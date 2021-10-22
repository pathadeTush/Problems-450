

// Header Files
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 
 */

typedef struct node
{
    int val;
    int ind;
} node;

vector<int> freqSort(vector<int> listEle)
{
    vector<int> answer = listEle;
    // Write your code here

    int n = listEle.size();

    vector<int> freq(10000, 0);

    vector<node> arr(n);

    for (int i = 0; i < n; i++)
    {
        freq[listEle[i]] += 1;
        arr[i].val = listEle[i];
        arr[i].ind = i;
    }

    for (int i = 0; i < n; i++)
    {
        int j = i;

        while (j > 0)
        {
            int x = answer[j];
            int y = answer[j - 1];
            if (freq[x] > freq[y])
            {
                //int temp = x;
                answer[j] = y;
                answer[j - 1] = x;
            }
            else if (freq[x] == freq[y])
            {
                if (arr[j].ind < arr[j - 1].ind)
                {
                    answer[j] = y;
                    answer[j - 1] = x;
                }
            }

            j--;
        }
    }

    return answer;
}

int main()
{

    //input for listEle
    int listEle_size;
    cin >> listEle_size;
    vector<int> listEle;
    for (int idx = 0; idx < listEle_size; idx++)
    {
        int temp;
        cin >> temp;
        listEle.push_back(temp);
    }

    //output
    vector<int> result = freqSort(listEle);
    for (int idx = 0; idx < result.size() - 1; idx++)
    {
        cout << result[idx] << " ";
    }
    cout << result[result.size() - 1];

    return 0;
}

// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// typedef struct node{
//     int val;

//     int ind;
// } node;

// int main()
// {
//     int size;
//     cin >> size;
//     int arr[size];

//     for (int i = 0; i < size; i++)
//         cin >> arr[i];

//     vector<int> freq(100000, 0);

//     vector<node> a;

//     for (int i = 0; i < size; i++){

//         freq[arr[i]]++;
//         a[i].val = arr[i];
//         a[i].ind = i;
//     }

//         for (int i = 0; i < size; i++)
//         {
//             int j = i;
//             while (j > 0 &&  freq[a[j].val] > freq[a[j-1].val])
//             {
//                 // swapping
//                 int temp = arr[j];
//                 arr[j] = arr[j - 1];
//                 arr[j - 1] = temp;
//                 j--;
//             }

//         }

//         for (int i = 0; i < size; i++)
//             cout << arr[i] << " ";

//         return 0;
// }

// // Running time depends on not only the size of the array but also the contents of the array.
// // Best-case:		 O(n)
// // Array is already sorted in ascending order.
// // Inner loop will not be executed.
// // The number of moves: 2*(n-1) 		 O(n)
// // The number of key comparisons: (n-1) 	 O(n)

// // Worst-case: 	 O(n^2)
// // Array is in reverse order:
// // Inner loop is executed i-1 times, for i = 2,3, …, n
// // The number of moves: 2*(n-1)+(1+2+...+n-1)= 2*(n-1)+ n*(n-1)/2 	 O(n^2)
// // The number of key comparisons: (1+2+...+n-1)= n*(n-1)/2 		 O(n^2)

// // Average-case: 	 O(n^2)
// // We have to look at all possible initial data organizations.
// // So, Insertion Sort is O(n^2)