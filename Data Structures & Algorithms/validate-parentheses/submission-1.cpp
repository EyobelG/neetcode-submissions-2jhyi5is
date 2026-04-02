#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        // Create an unordered_map
        unordered_map<char, char> umap;

        // Insert key-value pairs into the unordered_map
        umap[']'] = '[';
        umap[')'] = '(';
        umap['}'] = '{';

        for (char c: s) {
            if (umap.count(c)) {
                if (!st.empty() && st.top() == umap[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
            
    }
};
