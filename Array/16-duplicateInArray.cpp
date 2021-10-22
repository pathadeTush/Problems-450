// solve @gfg

vector<int> duplicates(int arr[], int n)
{
    vector<int> dict(n, 0); // dictionary vector
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        dict[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
        if (dict[i] > 1)
            ans.push_back(i);

    if (!ans.size())
        ans.push_back(-1);
    return ans;
}