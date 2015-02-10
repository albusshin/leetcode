#include <string.h>
#include <ctype.h>

class Solution {
private:
	char *p;
	char digits[10];
	long long pow10(int digit) {
		long long res = 1;
		for (int i=0; i<digit; i++) res *= 10;
		return res;
	}
	int isDigit(char c) {
		for (int i=0; i<10; i++) {
			if (c == digits[i]) return true;
		}
		return false;
	}
public:
	Solution() {
		for (int i=0; i<10; i++) {
			digits[i] = i + '0';
		}
	}
    int atoi(const char *str) {
		p = (char*) str;
		while (isspace(*p)) p++;
		bool negative = false;
		if (*p == '+') {
			if(*(p+1) == '-') return 0;
			p++;
		}
		if (*p == '-') {
			if (*(p+1) == '+') return 0;
			p++;
			negative = true;
		}
		char *num = new char[strlen(str)];
		int i = 0;
		char *pTmp = p;
		while (*pTmp != NULL && isDigit(*pTmp)) {
			num[i++] = *pTmp;
			pTmp++;
		}
		num[i] = 0;
		int digits = strlen(num) - 1;
		if (digits > 9) {
			if (!negative) return 2147483647;
			else return -2147483648;
		}
		long long res = 0, tmpRes;
		while (*p != NULL && isDigit(*p)) {
			res += (*p - '0') * pow10(digits--);
			tmpRes = negative ? -res : res;
			if (tmpRes > 2147483647) return 2147483647;
			else if (tmpRes < -2147483648) return -2147483648;
			p++;
		}
		if (negative) res = -res;
		return (int)res;
    }
};