class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string temp = "";

        for (string str : strs) {
            int len = str.length();
            temp += to_string(len);
            temp += "#";
            temp += str;
        }
        return temp;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<string> result;
        int i = 0;

        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));

            string str = s.substr(j + 1, len);
            result.push_back(str);
            i = j + 1 + len;
        }
        return result;
    }
};
