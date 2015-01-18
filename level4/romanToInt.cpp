#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <unordered_set>
using namespace std;


int romanCharToInt(char ch){
    int d = 0;
    switch(ch){
        case 'I':
            d = 1;
            break;
        case 'V':
            d = 5;
            break;
        case 'X':
            d = 10;
            break;
        case 'L':
            d = 50;
            break;
        case 'C':
            d = 100;
            break;
        case 'D':
            d = 500;
            break;
        case 'M':
            d = 1000;
            break;
    }
    return d;
}

int romanToInt(string s) {
    if(s.size() <= 0) return 0;
    int result = romanCharToInt(s[0]);
    for(int i=1; i < s.size(); i++){
        int prev = romanCharToInt(s[i-1]);
        int cur  = romanCharToInt(s[i]);

        if(prev < cur) {
            result = result - 2* prev;
        } else {
            result += cur;
        }
    }
    return result;
}

string intToRoman(int num) {
    string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
    int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
    string result;

    for(int i=0; num!=0; i++){
        while(num >= value[i]){
            num -= value[i];
            result+=symbol[i];
        }
    }

    return result;
}


int main()
{
     cout << "" << endl;

    return 0;
}


