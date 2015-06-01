class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mini = getMinimums(prices);
        vector<int> maxi = getMaximums(prices);
        int sum = 0;
        for (int i : maxi) {
            sum += i;
        }
        for (int i : mini) {
            sum -= i;
        }
        return sum;
    }
    vector<int> getMaximums(vector<int>& prices) {
        vector<int> ret;
        for (int i = 1; i < prices.size(); i++) {
            if (i == prices.size() - 1 && prices[i - 1] <= prices[i]) ret.push_back(prices[i]);
            else if (prices[i - 1] <= prices[i] && prices[i] > prices[i + 1]) ret.push_back(prices[i]);
        }
        return ret;
    }
    vector<int> getMinimums(vector<int>& prices) {
        vector<int> ret;
        for (int i = 0; i + 1 < prices.size(); i++) {
            if (i == 0 && prices[i + 1] >= prices[i]) ret.push_back(prices[i]);
            else if (prices[i - 1] > prices[i] && prices[i] <= prices[i + 1]) ret.push_back(prices[i]);
        }
        return ret;
    }
};