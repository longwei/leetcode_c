// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

vector<vector<int> > getCombine(int n, int k, vector<int>& solution, vector<vector<int> > result) {
	if(k == 0){
		std::vector<int> v = solution;
		sort(v.begin(),v.end());
		result.push_back(v);
		return;
	}

	for(int i= n; i > 0; i--){
		solution.push_back(i);
		getCombine(i-1, k-1, solution,result);
		// getCombine(n-1, k-1, solution,result);
		//this is wrong
		solution.pop_back(i);
	}
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> solution;
    getCombination(n, k, solution, result);
    return result; 
}