#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	unordered_map<char, bool> ump;
	vector<vector<char>> board;
public:
	Solution() {
		resetUmp();
	}

	void resetUmp() {
		for (int i = 1; i <= 9; i++) {
			ump[i + '0'] = false;
		}
	}

	bool isValidRow(int index) {
		resetUmp();
		vector<char>& row = board[index];
		for (char c : row) {
			if (c == '.') continue;
			else if (ump[c]) return false;
			else ump[c] = true;
		}
		return true;
	}

	bool isValidColumn(int index) {
		resetUmp();
		for (int i = 0; i < 9; i++) {
			char c = board[i][index];
			if (c == '.') continue;
			else if (ump[c]) return false;
			else ump[c] = true;
		}
		return true;
	}

	bool isValidSquare(int i, int j) {
		resetUmp();
		for (int m = i; m< i + 3; m++) {
			for (int k = j; k < j + 3; k++) {
				char c = board[m][k];
				if (c == '.') continue;
				else if (ump[c]) return false;
				else ump[c] = true; 
			}
		}
		return true;
	}

    bool isValidSudoku(vector<vector<char>> &board) {
		this->board = board;
		for (int i = 0; i < 9; i++) {
			if (!isValidColumn(i)) return false;
			if (!isValidRow(i)) return false;
		}
		for (int i = 0; i <= 6; i += 3) {
			for (int j = 0; j <= 6; j += 3) {
				if (!isValidSquare(i, j)) return false;
			}
		}
		return true;
    }
};