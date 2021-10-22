class Solution
{
public:
    // o(n^2)
    //     int maxProfit(vector<int>& prices) {
    //         int n = prices.size();
    //         vector <int> profites;

    //         for(int i = 0; i < n-1; i++){
    //             int temp = prices[i];
    //             int maxProfit = 0;
    //             for(int j = i+1; j < n; j++){
    //                 maxProfit = max(maxProfit, (prices[j] - prices[i]));
    //             }
    //             profites.push_back(maxProfit);
    //         }

    //         int maxProfit = 0;
    //         for(auto i: profites)
    //             maxProfit = max(maxProfit, i);

    //         return maxProfit;
    //     }

    // time complexity: O(n)
    // space complexity: O(n)
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> Diff;

        for (int i = 0; i < n - 1; i++)
            Diff.push_back(prices[i + 1] - prices[i]);

        // maxProfit is largest sum of contiguous array of differences

        int sum = 0, maxProfit = 0;

        for (auto i : Diff)
        {
            sum += i;
            if (sum < 0)
                sum = 0;
            maxProfit = max(maxProfit, sum);
        }

        return maxProfit;
    }


    // Time complexity: O(n)
    // Space complexity: O(1)

    int maxProfit(vector<int> &prices){
        int minSellPrice = INT_MAX;
        int maxProfit = INT_MIN;

        for (int i = 0; i < prices.size(); i++){
            minSellPrice = min(minSellPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minSellPrice);
        }

        return maxProfit;
    }
};
 