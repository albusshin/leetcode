class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int i = 0,  j = -1;
		for (; i < n; i++) {
			while (++j < n && A[j] == elem);
			if (j >= n) break;
			A[i] = A[j];
		}
		return i;
    }
};