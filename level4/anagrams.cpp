//Given an array of strings, return all groups of strings that are anagrams.

//Note: All inputs will be in lower-case.

vector<string> anagrams(vector<string> &strs) {
    vector<string> result;
    if(strs.size() < 2) return result;
    //-1 for already in result
    unordered_map<string, int> cache;

    for(int i=0; i < strs.size(); i++){
        string s = strs[i];
        sort(s.begin(), s.end());
        auto it = cache.find(s);
        if(it == cache.end()){
            cache[s] = i;
        } else {
            //hit
            result.push_back(strs[i]);
            if( it->second >=0){
                result.push_back(strs[it->second]);
                it->second = -1;
            }
        }
    }
    return result;

}