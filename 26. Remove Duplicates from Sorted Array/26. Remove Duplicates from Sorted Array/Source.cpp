class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if (n <= 1) return n;
		else if (n == 2 && A[0] == A[1]) return 1;
		int now = A[0];
		int j = 1;
		int i;
		for (i = 1; i < n; i++) {
			while (j < n && A[j] <= now) j++;
			if (j != n) {
				A[i] = A[j];
				now = A[i];
			}
			else break;
		}
		return i;
    }
};