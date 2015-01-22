//Given an array and a value, remove all instances of that value in place and return the new length.

//The order of elements can be changed. It doesn't matter what you leave beyond the new length.


void permuteRec(vector<int>& num, int step, vector<bool>& visited,
                vector<int>& sol_on_build, vector<vector<int> >& coll){
    if(step == num.size()){
        coll.push_back(sol_on_build);
        return;
    }
    for(int i = 0; i < num.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            sol_on_build.push_back(num[i]);
            permuteRec(num, step+1, visited, sol_on_build, coll);
            sol_on_build.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > coll;
    if(num.size() == 0) return coll;
    vector<int> sol_on_build;
    vector<bool> visited(num.size(), false);
    permuteRec(num,0,visited, sol_on_build, coll);
    return coll;
}