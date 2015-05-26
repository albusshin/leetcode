class WordDictionary {
	map<int, set<string>> wmap;
public:

    // Adds a word into the data structure.
    void addWord(string word) {
		int n = word.size();
		if (wmap.find(n) == wmap.end()) {
			set<string> s;
			s.insert(word);
			wmap[n] = s;
		}
		else {
			wmap[n].insert(word);
		}
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		int n = word.size();
		set<string>& theSet = wmap[n];
		for (string s : theSet) {
			bool match = true;
			for (int i = 0; i < n; i++) {
				if (word[i] == '.') continue;
				if (word[i] != s[i]) {
					match = false;
					break;
				}
			}
			if (match) return true;
		}
		return false;
    }
};