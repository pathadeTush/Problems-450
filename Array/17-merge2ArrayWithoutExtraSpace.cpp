
// time complexity:   O(n*m)
// space complexity:  O(1)
// 	void merge(int arr1[], int arr2[], int n, int m) {
// 	    for(int i = 0; i < n; i++){
// 	        if(arr1[i] > arr2[0]){
// 	            swap(arr1[i], arr2[0]);
// 	            int j = 0;
// 	            while(j < m-1 && arr2[j] > arr2[j+1]){
// 	                swap(arr2[j], arr2[j+1]);
// 	                j++;
// 	            }
// 	        }
// 	    }
// 	   // for(int i = 0; i < n; i++)
// 	   //     cout << arr1[i] << " ";
// 	   // for(int j = 0; j < m; j++)
// 	   //     cout << arr2[j] << " ";

// 	   //cout << endl;

// 	   return;
// 	}

// gap method
// time complexity:   O((n+m)*log(n+m))
// space complexity:  O(1)
void merge(int arr1[], int arr2[], int n, int m)
{
    int gap = (n + m) / 2 + (n + m) % 2;

    while (1)
    {
        int i = 0;
        for (int j = gap; j < n + m; j++, i++)
        {

            if (j < n && arr1[i] > arr1[j])
                swap(arr1[i], arr1[j]);

            else if (i < n && j >= n && arr1[i] > arr2[j - n])
                swap(arr1[i], arr2[j - n]);

            else if (i >= n && j >= n && arr2[i - n] > arr2[j - n])
                swap(arr2[i - n], arr2[j - n]);
        }

        if (gap == 1)
            break;

        gap = gap / 2 + gap % 2;
    }

    return;
}

// put all n small elements in arr1 and rest are in arr2
// 	void merge(int arr1[], int arr2[], int n, int m){
// 	    int i = 0, j = 0, k = n-1;

// 	    while(i <= k && j < m){
// 	        if(arr1[i] < arr2[j])
// 	            i++;

// 	        else
// 	            swap(arr1[k--], arr2[j++]);
// 	    }

// 	    sort(arr1, arr1+n);
// 	    sort(arr2, arr2+m);

// 	    return;
// 	}