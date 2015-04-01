#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> ret;
		ret.push_back(1);
		if (rowIndex == 0) return ret;
		ret.push_back(1);
		if (rowIndex == 1) return ret;
		for (int j = 1; j < rowIndex; j++) {
			ret.push_back(1);
			int tmp = ret[0], ttmp;
			for (int i = 1; i <= j; i++) {
				ttmp = ret[i];
				ret[i] = tmp + ret[i];
				tmp = ttmp;
			}
		}
		return ret;
    }
};

int main() {
	Solution s;
	vector<int> vi = s.getRow(8);
	for (auto i : vi) cout << i << " ";
}