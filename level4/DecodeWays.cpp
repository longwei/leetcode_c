//this version LTE.....
bool inline consumeOne(string s, int cur) {
    //cur at least ptr to a int
    if (s[cur] == '0') return false;
    return true;
}

bool inline consumeTwo(string s, int cur) {
    if (cur >= s.size() - 1) return false;
//    string twodigits = s.substr(cur, 2);
//    int sum = atoi(twodigits.c_str());
//    if (sum >= 10 && sum <= 26) {
//        return true;
//    }
    if(s[cur] == '1') return true;
    if(s[cur] == '2' && s[cur+1] < '7') return true;
    return false;
}


int inline numDecodingsRec(string s, int cur) {
    if (cur == s.size()) return 1;
    bool one = consumeOne(s, cur);
    bool two = consumeTwo(s, cur);
    if (!one && !two) return 0;
    if (one && !two) return numDecodingsRec(s, cur + 1);
    if (!one && two) return numDecodingsRec(s, cur + 2);
    if (one && two) return numDecodingsRec(s, cur + 1) + numDecodingsRec(s, cur + 2);
}

int numDecodings(string s) {
    if (s.empty()) return 0;
    return numDecodingsRec(s, 0);
}


int numDecodings(string s) {
    if(!s.size()||s[0]=='0')return 0;
    int cur_2 = 1,cur_1 = 1,cur = 0;

    for(int i = 2;i<=s.size();i++){
        if(s[i-1]!='0')cur+=cur_1;
        if(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<'7'))cur+=cur_2;
        cur_2 = cur_1;
        cur_1 =  cur;
        cur = 0;
    }
    return cur_1;
}