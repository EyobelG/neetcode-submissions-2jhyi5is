class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // initialize result and empty current string
        vector<string> result;
        string current ;
        // call backtrack with open=0, close=0
        backtrack(n, 0, 0, current, result);
        return result;
     
 
   
    }
        
private:
    void backtrack(int n, int open, int close, string& current,
                   vector<string>& result) 
    {
        // BASE CASE: current string is length 2*n → push to result
        if (current.size() == 2*n) {
            result.push_back(current);
            return;
        }
        // open is the number of opening brackets '('
        // close is the number of closing brackets ')'
        if (open < n) {
            current.push_back('(');
            backtrack(n, open + 1, close, current, result);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, result);
            current.pop_back();
        }
        // RECURSIVE CASE:
        // if open < n  → add '(' and recurse
        // if close < open → add ')' and recurse
        // (undo after each — pop last char)
            


    }
};




