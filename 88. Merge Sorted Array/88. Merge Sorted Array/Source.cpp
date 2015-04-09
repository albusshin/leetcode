class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pa = m - 1,
            pb = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (pa == -1) A[i] = B[pb--];
            else if (pb == -1) A[i] = A[pa--];
            else if (A[pa] > B[pb]) {
                A[i] = A[pa];
                pa--;
            }
            else {
                A[i] = B[pb];
                pb--;
            }
        }
    }
};