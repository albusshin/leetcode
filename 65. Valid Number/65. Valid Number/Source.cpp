#include <ctype.h>

using namespace std;

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
	bool is1To9(char c) {
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
		if (*p == '-' || *p == '+') p++;

		if (is1To9(*p)) {
			while (isDigit(*p)) p++; 
			if (*p == '.') {
				p++;
				if (!(*p == 'e' || isDigit(*p) || *p == NULL || isspace(*p))) return false;
			}
		}
		else if (*p == '0') {
			p++;
			if (*p == 'x' || *p == 'X') {
				p++;
				if (!(*p == 'e' || isDigit(*p))) return false;
			}
			while (isDigit(*p)) p++;
			if (*p == '.') {
				p++;
				if (!(*p == 'e' || isDigit(*p) || *p == NULL || isspace(*p))) return false;
			}
		}
		else if (*p == '.') {
			p++;
			if (!(isDigit(*p))) return false;
		}
		else return false;

		if (isDigit(*p)) {
			while (isDigit(*p)) p++;
		}
		if (*p == 'e' || *p == 'E') {
			p++;
	    	if (*p == '+' || *p == '-') p++;
	    	if (isDigit(*p)) {
	    		while (isDigit(*p)) p++;
	    	}
			else return false;
		}
		advanceWhiteSpace();
		if (*p == NULL) return true;
		else return false;
    }
};