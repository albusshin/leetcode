class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        bool found = false;
        vector<int> vi;
        if (n == 1 && A[0] == target) {
            vi.push_back(0);
            vi.push_back(0);
            return vi;
        }
        vi.push_back(-1);
        vi.push_back(-1);
        int left = bins(A, n, target - 0.5);
        int right = bins(A, n, target + 0.5);
        if (left != right) {
            vi.clear();
            right--;
            vi.push_back(left);
            vi.push_back(right);
        }
        return vi;
    }
    int bins(int A[], int n, double target) {
        int left = 0, right = n - 1;
        int i = (left + right) / 2;
        while (right >= left) {
            if (A[i] > target) right = i - 1;
            else left = i + 1;
            i = (left + right) / 2;
        }
        return left;
    }
};