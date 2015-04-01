#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int pivotPoint = findPivotPoint(A, n);
		cout << pivotPoint << endl;
		int i = binarySearch(A, pivotPoint, target);
		if (i != -1) return i;
		i = binarySearch(A + pivotPoint, n - pivotPoint, target);
		if (i != -1) return pivotPoint + i;
		return -1;
    }
    int findPivotPoint(int A[], int n) {
        if (n == 0) return -1;
        int left = 0, right = n - 1;
        int i = (left + right) / 2;
        while (right - left > 1) {
            if (A[i] < A[left]) right = i;
            else left = i;
            i = (left + right) / 2;
        }
		return i + 1;
    }
	int binarySearch(int A[], int n, int target) {
		if (n == 0) return -1;
		int left = 0, right = n - 1;
		int i = (left + right) / 2;
		while (A[i] != target) {
			if (right <= left) return -1;
			if (A[i] < target) left = i + 1;
			else right = i - 1;
			i = (left + right) / 2;
		}
		return i;
	}
};

int main() {
	int arr[] = {1, 2, 3, 5};
	Solution s;
	cout << s.search(arr, 4, 3 );
}