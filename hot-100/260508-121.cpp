class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minP(n, INT_MAX);
        for(int i = 0; i < n; i++){
            minP[i] = i == 0 ? prices[0] : min(minP[i - 1], prices[i]);
        }
        vector<int> maxP(n, INT_MIN);
        for (int i = n - 1; i >= 0; i--)
        {
            maxP[i] = i == n - 1 ? prices[n - 1] : max(maxP[i + 1], prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(maxP[i] - minP[i], ans);
        }
        return ans;
        
        
    }
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            minP = min(minP, prices[i]);
            ans = max(ans, prices[i] - minP);
        }
        return ans;
    }
};