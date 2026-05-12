using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*"
            || t == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if (t == "+") s.push(a + b);
                if (t == "-") s.push(a - b);
                if (t == "*") s.push(a * b);
                if (t == "/") s.push(a / b);
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
