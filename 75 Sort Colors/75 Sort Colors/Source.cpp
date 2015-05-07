class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            nums[i] = 2;
            if (num == 1) {
                if (p1 >= p0) nums[p1++] = 1;
                else {
                    p1 = p0;
                    nums[p1++] = 1;
                }
            }
            else if (num == 0) {
                nums[p0++] = 0;
                if (p1 >= p0) nums[p1++] = 1;
            }
        }
    }
};