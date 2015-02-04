// https://oj.leetcode.com/problems/two-sum/
// Thought: sorting, binary-searching: O(n*logn)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ret;
		vector<int> sortedNumbers = numbers;
		sort(sortedNumbers.begin(), sortedNumbers.end());
		int i, j;
		vector<int>::iterator ite, jte;

		for (ite=numbers.begin(), i=1; ite!=numbers.end(); ite++, i++)
		{
			int key = target-*ite;
			if(binary_search(sortedNumbers.begin(), sortedNumbers.end(), target-*ite))
			{
	  			for (jte=ite, j=i; jte!=numbers.end(); jte++, j++)
    			{
					if (*jte == key && j!=i)
					{
						ret.push_back(i);
						ret.push_back(j);
						return ret;
					}
    			}
			}
		}
		return ret;
    }
};

void main()
{
}