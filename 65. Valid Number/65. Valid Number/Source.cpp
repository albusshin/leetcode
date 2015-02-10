#include <string.h>
#include <ctype.h>

class Solution {
private:
	char digits[10], *p;
public:
	Solution() {
		for (int i=0; i<10; i++) {
			digits[i] = i + '0';
		}
	}
	bool isDigit(char c) {
		for (int i=0; i<10; i++) {
			if (digits[i] == c) return true;
		}
		return false;
	}
	bool is0To9(char c) {
		for (int i=1; i<10; i++) {
			if (digits[i] == c) return true;
		}
		return false;
	}
	char* advanceWhiteSpace() {
		while (isspace(*p)) p++;
	}
    bool isNumber(const char *s) {
		p = (char*)s;
		advanceWhiteSpace();
		if (*p == '-') p++;
		if (is0To9(*p)) {
			while (is0To9(*p)) p++; 
		}
		else if (*p == '0') p++;
		else return false;
		if (*p == '.') p++;
		if (isDigit(*p)) {
			while (isDigit(*p)) p++;
		}
		if (*p == 'e' || *p == 'E') p++;
		if (*p == '+' || *p == '-') p++;
		if (isDigit(*p)) {
			while (isDigit(*p)) p++;
		}
		advanceWhiteSpace();
		if (*p == NULL) return true;
		else return false;
    }
};

void main() {
	Solution s;

}