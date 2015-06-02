class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        vector<string> vs;
        stringstream ss;
        string tmpstr;
        for (char c : path) {
            if (c == '/') {
                vs.push_back(tmpstr);
				tmpstr = "";
            }
            else tmpstr += c;
        }
        vs.push_back(tmpstr);
        stack<string> stks;
        for (string str : vs) {
            if (str == ".") continue;
            if (str == "") continue;
            if (str == "..") {
                if (stks.empty()) continue;
                else stks.pop();
            }
            else {
                stks.push(str);
            }
        }
        stack<string> revstks;
        while (!stks.empty()) {
            revstks.push(stks.top());
            stks.pop();
        }
        while (!revstks.empty()) {
            ret += "/" + revstks.top();
            revstks.pop();
        }
        if (ret.empty()) return "/";
        return ret;
    }
};
