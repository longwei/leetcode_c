string removeNoise(const string& s){
    string d;
    for(int i=0; i<s.size();i++){
        if(isalnum(s[i])) d.push_back(tolower(s[i]));
    }
    return d;
}

bool isPalindrome(string s) {
    s = removeNoise(s);
    for(int i=0; i<s.size()/2; i++){
        if (s[i]!= s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    cout << true << endl;
    cout << isPalindrome(s) << endl;
    return 0;
}