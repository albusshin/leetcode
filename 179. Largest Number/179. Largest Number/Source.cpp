class Solution {
public:
    string largestNumber(vector<int> &num) {
		sort(num.begin(), num.end(), [&](int num1, int num2){
			stringstream tmpss;
			string str1, str2;
			tmpss << num1 << num2;
			tmpss >> str1;
			tmpss.clear();
			tmpss << num2 << num1;
			tmpss >> str2;
			return str1 < str2;
		});

		stringstream ss;
		for (auto rite = num.rbegin(); rite != num.rend(); ++rite) {
			ss << (*rite);
		}
		string ret;
		ss >> ret;
		bool all0 = true;
		for (auto c : ret)
			if (c != '0')
				all0 = false;
		if (all0) return "0";
		return ret;
    }
};