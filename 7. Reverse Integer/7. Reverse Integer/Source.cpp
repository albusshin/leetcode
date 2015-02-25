#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int d) {
		long long x = d;
		bool negative = x < 0;
		long long xcopy;
		if (negative) xcopy = -x;
		else xcopy = x;
		long long bits;
		for (bits = 0; xcopy != 0; bits++) xcopy /= 10;
		if (negative) xcopy = -x;
		else xcopy = x;
		long long res = 0;
		for (int i=bits-1; i>=0; i--) {
			long long bit = xcopy % 10;
			for (int j=0; j<i; j++) {
				bit *= 10;
			}
			res += bit;
			if (res > INT_MAX) return 0;
			xcopy /= 10;
		}
		if (negative) res = -res;
		return res;
    }
};