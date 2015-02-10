#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int i = 0, j = 0;
		int* ar = new int[m+n];
		for (int k = 0; k < m + n; k++){
			if (i >= m) ar[k] = B[j++];
			else if (j >= m) ar[k] = A[i++];
			else ar[k] = A[i] < B[j] ? A[i++] : B[j++];
			cout << ar[k] << endl;
		}
		if (!((m+n) % 2)) return (ar[(m+n)/2 - 1] + ar[(m+n)/2])/2.0;
		else return ar[(m+n)/2];
    }
};

void main()
{
	int arr[] = {1, 2, 3, 4}, brr[] = {2, 3, 5, 7, 8, 9};
	Solution s;
	double d = s.findMedianSortedArrays(arr, 4, brr, 6);
	cout << d;
}