// Time Complexity: O(n1 + n2 + n3)
// Space Complexity: O(n1 + n2)
//   vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
//     {
//         vector <int> commonEle;
//         unordered_map <int, int> mp1; // arr[i], presence
//         unordered_map <int, int> mp2; // arr[i], presence

//         for(int i = 0; i < n1; i++)
//             mp1[A[i]]++;
//         for(int i = 0; i < n2; i++)
//             mp2[B[i]]++;

//         int prev = -1;
//         for(int i = 0; i < n3; i++){
//             if(mp1[C[i]] && mp2[C[i]] && prev != C[i])
//                 commonEle.push_back(C[i]);
//             prev = C[i];
//         }

//         return commonEle;
//     }

// Time Complexity: O(n1 + n2 + n3)
// Space Complexity: O(1) // O(n) for commonEle vector | n = no. common elements
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> commonEle;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            commonEle.push_back(A[i]);
            i++;
            j++;
            k++;
            // prev = C[k];
            //  continue;
        }

        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else
            k++;

        while (i < n1 && A[i] == A[i - 1])
            i++;
        while (j < n2 && B[j] == B[j - 1])
            j++;
        while (k < n3 && C[k] == C[k - 1])
            k++;
        // int temp = max(max(A[i], B[j]), C[k]);
        // while(i < n1 && A[i] < temp) i++;
        // if(i >= n1)
        //     break;
        // while(j < n2 && B[j] < temp) j++;
        // if(j >= n2)
        //     break;
        // while(k < n3 && C[k] < temp) k++;
        // if(k >= n3)
        //     break;
    }

    return commonEle;
}