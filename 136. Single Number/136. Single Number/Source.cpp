#include <set>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		set<int> s;
		for (int i=0; i<n; i++)
		{
			if (s.find(i) == s.end())
				s.insert(i);
			else
				s.erase(i);
		}
		return *(s.begin());
    }
};