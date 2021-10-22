/*

Set  = [a,b,c]
power_set_size = pow(2, 3) = 8
Run for binary counter = 000 to 111

Value of Counter            Subset
    000                    -> Empty set
    001                    -> a
    010                    -> b
    011                    -> ab
    100                    -> c
    101                    -> ac
    110                    -> bc
    111                    -> abc

*/

vector<string> AllPossibleStrings(string s)
{
    int n = s.length();
    vector<string> ans;

    // do not count empty string here
    for (int i = 1; i < (1 << n); i++)
    {

        string temp = "";
        for (int pos = 0; pos < n; pos++)
            if (i & (1 << pos))
                temp += s[pos];

        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());

    return ans;
}