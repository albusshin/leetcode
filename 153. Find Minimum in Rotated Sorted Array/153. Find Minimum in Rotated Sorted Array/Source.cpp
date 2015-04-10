class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 2) return min(num[0], num[1]);
        if (num.empty()) return NAN;
        int smallest = num[0];
        int left = 0, right = num.size() - 1;
        int mid = right / 2;
        while (left <= right) {
            if (num[mid] >= smallest) left = mid + 1;
            else {
                smallest = num[mid];
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }
        return smallest;
    }
};