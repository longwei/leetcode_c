#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Implement atoi to convert a string to an integer.

//Hint: Carefully consider all possible input cases.
//If you want a challenge, please do not see below and ask yourself what are the possible input cases.

class Solution {
public:
    int atoi(string str) {
        int n = 0;
        int sign = 0;
        int i = 0;

        while (isspace(str[i])) i++;
        sign = (str[i] == '-' ? -1 : 1);
        if (str[i] == '-' || str[i] == '+') i++;

        for (; isdigit(str[i]); i++) {
            int x = str[i] - '0';
            if (n > (INT_MAX - x) / 10) {
                return sign < 0 ? INT_MIN : INT_MAX;
            }
            n = n * 10 + x;
        }
        return n * sign;
    }
};



int main()
{
    Solution s;
    cout << s.atoi("123") << endl;
    cout << s.atoi("+123") << endl;
    cout << s.atoi("-123") << endl;
    cout << s.atoi("    +123") << endl;

    return 0;
}


