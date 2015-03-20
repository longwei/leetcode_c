#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

/**********************************************************************************
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid
* but "(]" and "([)]" are not.
*
*
**********************************************************************************/

class Solution {
 public:
  bool isValid(string s) {
    string stack;
    int n = s.size();
    int i = 0;
    while (i < n) {
      char c = s[i];
      if (c == '[' || c == '{' || c == '(') {
        stack.push_back(c);
      } else if (c == ']' || c == '}' || c == ')') {
        if (stack.size() <= 0) return false;
        char rch = stack.back();
        if ((rch == '[' && c == ']') || (rch == '{' && c == '}') ||
            (rch == '(' && c == ')')) {
          stack.pop_back();
        } else {
          // not a match
          return false;
        }
      } else {
        return false;
      }
      i++;
    }
    return stack.empty();
  }
};

int main() {
  Solution s;
  cout << s.isValid("{[()]}") << endl;
  cout << true << endl;
  return 0;
}