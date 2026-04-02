#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        
    // Declare a stack of characters.
    std::stack<char> paren_stack;

    // I'm using a for loop to iterate over s, but we
    // could easily convert this to a while loop that runs
    // as long as there are characters left in s.
    for (size_t i = 0; i < s.length(); i++) {
        char curr_char = s[i];
        if (is_opener(curr_char)) {
            paren_stack.push(curr_char);
        }
        else if (is_closer(curr_char)) {
            if (paren_stack.empty() || !matches(paren_stack.top(), curr_char)) {
                // If either of above conditions is true, no need to look at
                // rest of the string: we know s is not balanced.
                return false;
            }
            else {
                // Matched closer with opener on top of stack, so
                // pop top of stack since we're done with this subsession.
                paren_stack.pop();
            }
        }
        else {
            // If curr_char is anything else, then it doesn't affect whether
            // or not the parentheses are balanced.  Just continue.
            continue;
        }
    }

    if (not paren_stack.empty()) {
        // If we went over the whole s and the stack is not empty,
        // then there must be some openers that were not matched.
        return false;
    }
    else {
        return true;
    }
}

/* Input: character c.
 * Output: true if c is one of (, [, or {, false otherwise.
 */
bool is_opener(char c)
{
    return (c == '(') or (c == '[') or (c == '{');
}

/* Input: character c.
 * Output: true if c is one of ), ], or }, false otherwise.
 */
bool is_closer(char c)
{
    return (c == ')') or (c == ']') or (c == '}');
}

/* Input: char opener is one of (, [, or {,
 *        char closer is one of ), ], or }.
 * Output: true if opener matches closer, false otherwise.
 */
bool matches(char opener, char closer)
{
    return ((opener == '(') and (closer == ')'))
        or ((opener == '{') and (closer == '}'))
        or ((opener == '[') and (closer == ']'));
}

};
