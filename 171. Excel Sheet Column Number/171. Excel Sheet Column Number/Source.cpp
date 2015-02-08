#include <string>
#include <math.h>
using namespace std;

class Solution {
private:
	int pow(int base, int e) {
		int res = 1;
		for (int i=0; i<e; i++) {
			res *= base;
		}
		return res;
	}
public:
    int titleToNumber(string s) {
		int len = s.size() - 1, res = 0;
		for (int i=0; i<=len; i++) {
			int bit = s[i] - 'A' + 1;
			res += pow(26, (len - i)) * bit;
		}
		return res;
    }
};