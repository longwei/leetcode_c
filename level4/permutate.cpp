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


//another way to think this problem is 
//swap head with rest of the array
// then reduce the problem to [head+1, end]
//   solve the problem by change the status of array and accept it at end of tree.
//   instead of reduce the problem by append a bit to result and [head + 1, end]
// standart bt, change status back

void permuteBT(vector<int>& num, int start, int end, vector<vector<int> >& coll){
    int i;
    if(start==end){
        coll.push_back(num);
    } else {
        for(i = start; i <= end; i++){
            //swap start i
            int tmp;
            tmp = num[start];
            num[start] = num[i];
            num[i] = tmp;
            permuteBT(num, start+1, end, coll);
            //swap i start;
            tmp = num[start];
            num[start] = num[i];
            num[i] = tmp;
        }
    }
}

vector<vector<int> > permute2(vector<int> &num) {
    vector<vector<int> > coll;
    if (num.size() == 0) return coll;
    permuteBT(num, 0, num.size() - 1, coll);
}


//what if the input is n and k, to give all the permute from 1..n
//i[n...0)
// push
// permuteRec(i-1, k-1,...)
// pop

