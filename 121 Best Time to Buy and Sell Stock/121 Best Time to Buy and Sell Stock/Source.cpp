class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        stack<int> maxes;
        for (auto rite = prices.rbegin(); rite != prices.rend(); ++rite) {
            if (maxes.empty()) maxes.push(*rite);
            else {
                int prevMax = maxes.top();
                maxes.push(max(prevMax, *rite));
            }
        }
        maxes.pop();
        stack<int> mins;
        for (auto ite = prices.begin(); ite != prices.end(); ++ite) {
            if (mins.empty()) mins.push(*ite);
            else {
                int prevMin = mins.top();
                mins.push(min(prevMin, *ite));
            }
        }
        mins.pop();
        stack<int> tmp;
        while (!mins.empty()) {
            tmp.push(mins.top());
            mins.pop();
        }
        mins = tmp;
        int maxInterval = 0;
        while (!maxes.empty()) {
            maxInterval = max(maxInterval, maxes.top() - mins.top());
            maxes.pop();
            mins.pop();
        }
        return maxInterval;
    }
};