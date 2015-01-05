#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Implement atoi to convert a string to an integer.

//Hint: Carefully consider all possible input cases.
//If you want a challenge, please do not see below and ask yourself what are the possible input cases.

class Solution {
public:
    int atoi(const char *str) {
        //discard all while space
        //optional +/-
        //number looking out for overflow
        if(str == NULL || *str == '\0') {
            return 0;
        }
        int length = strlen(str);
        int ret = 0;
        for(;isspace(*str); str++);
        bool neg = false;
        if(*str == '-' || *str == '+'){
            neg = (*str == '-');
            str++;
        }
        for(; isdigit(*str); str++){
            int digit = (*str - '0');
            if(neg){
                if (-ret < (INT_MIN + digit) / 10){
                    return INT_MIN;
                }
            } else {
                if(ret > (INT_MAX - digit) /10 ) {
                    return INT_MAX;
                }
            }
            ret = 10 * ret + digit;
        }
        return neg? -ret : ret;
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


