
//Given two binary strings, return their sum (also a binary string).

//For example,
//a = "11"
//b = "1"
//Return "100".

string addBinary(string a, string b) {
    string result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while(i>=0 || j>=0){
        int ia = (i>=0? a[i] - '0': 0);
        int ib = (j>=0? b[j] - '0': 0);
        int sum =  ia + ib + carry;
        carry = sum / 2;
        result.insert(result.begin(), sum % 2 + '0');
        --i;
        --j;
    }
    if(carry){
        result.insert(result.begin(), carry + '0');
    }
    return result;
}
