#include <set>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		set<int> s;
		for (int i=0; i<n; i++)
		{
			int e = A[i];
			if (s.find(e) == s.end())
				s.insert(e);
			else
				s.erase(e);
		}
		return *(s.begin());
    }
};