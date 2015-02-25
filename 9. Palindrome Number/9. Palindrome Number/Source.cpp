class Solution {
public:
    bool isPalindrome(int x) {
        int xcopy = x;
        if (x < 0) return false;
        else if (x == 0) return true;
        int bits = 0;
        for (bits = 0; xcopy != 0; bits++) {
			xcopy /= 10;
		}
		int left = 0, right = 0;
		left = x;
		for (int i=0; i<bits/2; i++) {
			left /= 10;
		}
		if (bits % 2) {
			left /= 10;
		}
		for (int i=1; i<=bits/2; i++) {
			int bit = x % 10;
			for (int j=0; j<(bits/2)-i; j++) {
				bit *= 10;
			}
			right += bit;
			x /= 10;
		}
		if (left == right) return true;
		else return false;
    }
};