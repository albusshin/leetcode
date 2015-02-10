#include <string.h>
#include <ctype.h>

class Solution {
private:
	char *p;
	int pow10(int digit) {
		int res = 1;
		for (int i=0; i<digit; i++) res *= 10;
		return res;
	}
public:
    int atoi(const char *str) {
		p = (char*) str;
		while (isspace(*p)) p++;
		bool negative = false;
		if (*p == '+') {
			if(*(p+1) == '-') return 0;
			p++;
		};
		if (*p == '-') {
			if ((*p+1) == '+') return 0;
			p++;
			negative = true;
		}
		int digits = strlen(p) - 1;
		int res = 0;
		while (*p != NULL) {
			res += (*p - '0') * pow10(digits--);
			p++;
		}
		if (negative) res = -res;
		if (res < 0 && !negative) return -2147483648;
		else if (res > 0 && negative) return 2147483647;
		else return res;
    }
};