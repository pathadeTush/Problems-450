class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        vector<vector<int>> v;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 3; i++)
        {
            for (int j = i + 1; j < arr.size() - 2; j++)
            {
                int l = j + 1;
                int r = arr.size() - 1;
                while (l < r)
                {
                    vector<int> v1;
                    if (arr[i] + arr[j] + arr[l] + arr[r] == k)
                    {
                        v1.push_back(arr[i]);
                        v1.push_back(arr[j]);
                        v1.push_back(arr[l]);
                        v1.push_back(arr[r]);

                        v.push_back(v1);
                        l++;
                        r--;
                    }
                    else if (arr[i] + arr[j] + arr[l] + arr[r] < k)
                        l++;
                    else
                        r--;
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }

    // this approach is not working

    // arr[] : int input array of integers
    // k : the quadruple sum required
    // vector<vector<int>> fourSum(vector<int> &arr, int k) {
    //     vector<vector<int>> ans;

    //     int n = arr.size();
    //     sort(arr.begin(), arr.end());

    //     for(int i = 0; i < n-3; i++){
    //         vector <int> temp;
    //         temp.push_back(arr[i]);
    //         for(int j = i+1; j < n-2; j++){
    //             temp.push_back(arr[j]);

    //             int sum = k - (arr[i] + arr[j]);
    //             // now we have to find two number(a1, a2) from j+1 to n such that a1+a2 equal to sum

    //             // instead of finding tow numbers, lets find out a number which is equal to sum - a1;
    //             map <int, int> mp; // (value, presence)

    //             //cout << "New " << endl;
    //             for(int m = j+1; m < n; m++){
    //                 mp[abs(sum-arr[m])]++;
    //               //  cout << arr[m] << " ";
    //             }
    //             //cout << endl;
    //             for(int m = j+1; m < n; m++){
    //               //  cout << mp[arr[m]] << " ";
    //                 if(mp[arr[m]]){
    //                     if((sum - arr[m]) < arr[m]){
    //                         temp.push_back(sum - arr[m]);
    //                         temp.push_back(arr[m]);
    //                     }
    //                     else{
    //                         temp.push_back(arr[m]);
    //                         temp.push_back(sum - arr[m]);
    //                     }

    //                     //cout << "Inside if "<< sum-arr[m] << " " << arr[m] << " "<< endl;

    //                     ans.push_back(temp);
    //                     temp.pop_back();
    //                     temp.pop_back();

    //                     mp[arr[m]] = 0;
    //                     mp[abs(sum-arr[m])] = 0;
    //                 }
    //             }

    //             // cout << endl;
    //             temp.pop_back();
    //         }
    //     }

    //     return ans;
    // }
};