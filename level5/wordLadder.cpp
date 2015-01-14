int ladderLength(string start, string end, unordered_set<string> &dict) {
    //use a map to track distance and remove duplicate
    map<string, int> dist;
    dist[start] = 0;

    queue<string> q;
    q.push(start);

    while(!q.empty()){
        string word = q.front();
        q.pop();
        if(word == end){
            break;//got it
        }
        for(int i = 0; i < word.size(); i++){
            string tmp = word;
            for(int c = 'a'; c <= 'z'; c++){
                tmp[i] = c;
                if(dict.count(tmp) >0 && dist[tmp] == 0){
                    dist[tmp] = dist[word] + 1;
                    q.push(tmp);
                }
            }
        }
    }
    return dist[end] == 0 ? 0: dist[end];
}