class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int sameCounter = 1;
        int i = 1;
        int prev = A[0];
        for (int j = 1; j < n; j++) {
            if (prev == A[j]){
                sameCounter++;
                if (sameCounter <= 2) {
                    A[i++] = A[j];
                }
            } else {
                sameCounter = 1;
                A[i++] = A[j];
                prev = A[j];
            }
        }
        return i;
    }
};