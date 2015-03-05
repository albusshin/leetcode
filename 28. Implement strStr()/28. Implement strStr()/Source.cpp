#include <vector>
#include <cstring>

using namespace std;

class Solution {
	vector<int> F;
public:
	void build_failure_function(const char* needle) {
		int m = strlen(needle);
		//F[0] = F[1] = 0, always true
		F.resize(m + 1);
		F[0] = F[1] = 0;
		for (int i = 2; i <= m; i++) {
			for (int j = F[i - 1]; ; j=F[j]) {
				if (needle[j] == needle[i - 1]) {F[i] = j + 1; break;}
				else if (j == 0) {F[i] = 0; break;}
			}
		}
	}

    int strStr(char *haystack, char *needle) { //KMP algo
		int n = strlen(haystack),
			m = strlen(needle);
		if (m == 0) return 0; //if needle is empty, always return 0, according to oj
		build_failure_function(needle);
		int i = 0,
			j = 0;
		for (; j != n; ) {
			if (haystack[j] == needle[i]) {
				i++;
				j++;
				if (i == m) return j - i;
			}
			else if (i == 0) j++;
			else i = F[i];
		}
		return -1;
    }
};