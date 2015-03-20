#include <iostream>
#include <vector>
#include <map>
using namespace std;

// three sum is very similar to 2 sum, the tricky part here is not duplicate


class Solution {
 public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > ans;
    int n = num.size();
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++) {
      if (i > 0 && num[i] == num[i - 1]) continue;
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        if (num[i] + num[j] + num[k] > 0)
          k--;
        else if (num[i] + num[j] + num[k] < 0)
          j++;
        else {
          ans.push_back({num[i], num[j], num[k]});
          while (j < k && num[k] == num[k - 1]) k--;
          while (j < k && num[j] == num[j + 1]) j++;
          k--;
          j++;
        }
      }
    }
    return ans;
  }
};

void printMatrix(vector<vector<int> > &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    printf("{");
    for (int j = 0; j < matrix[i].size(); j++) {
      printf("%3d ", matrix[i][j]);
    }
    printf("}\n");
  }
}

int main() {
  vector<int> numbbers = {0, 0, 0, 0};
  vector<vector<int> > result = threeSum(numbbers);
  printMatrix(result);
  return 0;
}
