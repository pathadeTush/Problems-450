#include<bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> mp;
bool comp(int a, int b){
    if(mp[a].first != mp[b].first)
        return mp[a].first > mp[b].first;
    return mp[a].second < mp[b].second;
}

void sortFreq(int arr[], int n){
    if(n == 0 || n == 1)
        return;
    mp.clear();

    for (int i = 0; i < n; i++){
        mp[arr[i]].first++;
        if(!mp[arr[i]].second)
            mp[arr[i]].second = i;
    }

    mp[arr[0]].second = 0;

    // for(auto it: mp){
    //     cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    // }

    sort(arr, arr + n, comp);
    return;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sortFreq(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}