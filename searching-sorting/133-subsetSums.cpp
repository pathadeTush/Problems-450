#include <bits/stdc++.h>
using namespace std;

void getSubset(int arr[], vector<int> &v, int start, int end){
    int n = end-start+1;

    for (int i = 0; i < (1 << n); i++){
        int subsetSum = 0;
        int j = start;
        int x = i;
        while (x)
        {
            if(x & 1)
                subsetSum += arr[j];
            j++;
            x = x >> 1;
        }
        v.push_back(subsetSum);
    }
}

int subsetSum(int arr[], int N, int A, int B){
    vector<int> v1, v2;

    getSubset(arr, v1, 0, N/2);
    getSubset(arr, v2, N/2+1, N-1);

    sort(v2.begin(), v2.end());
    int count = 0;
    for (int i = 0; i < v1.size(); i++){
        // binary search
        int low = lower_bound(v2.begin(), v2.end(), A - v1[i]) - v2.begin(); // index of smallest element which is greater or equal to A - v1[i]
        int high = upper_bound(v2.begin(), v2.end(), B - v1[i]) - v2.begin(); // index of largest element which is smaller or equal to B - v1[i]
        count += high - low;
    }

    return count;
}

int main(){
    int N, A, B;
    cin >> N>> A >> B;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << subsetSum(arr, N, A, B) << endl;

    return 0;
}