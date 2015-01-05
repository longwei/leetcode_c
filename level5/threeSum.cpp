#include <iostream>
#include <vector>
#include <map>
using namespace std;

//three sum is very similar to 2 sum, the tricky part here is not duplicate


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > result;

        //sort the array
        sort(num.begin() , num.end());
        int n = num.size();

        for(int i =0; i < n - 2; i++){
            //skip duplicate ??_
            if( i > 0 && num[i-1] == num[i]) continue;
            int a = num[i];
            int low = i + 1;
            int high = n - 1;
            while(low < high) {
                int b = num[low];
                int c = num[high];
                int sum = a + b + c;
                cout << a << " " << b << " "<< c<<endl;
                cout << sum <<endl;
                if(sum == 0){
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    result.push_back(v);
                    //skip duplicate
                    while (low < n && num[low] == num[low+1]) {
                        cout << "2" <<endl;
                        low++;
                    }
                    while (high > 0 && num[high] == num[high - 1]){
                        cout << "3"<<endl;
                        high--;
                    }
                    low++;
                    high--;
                } else if (sum > 0){
                    while (high > 0 && num[high] == num[high - 1]){
                        high--;
                    }
                    high--;
                } else {
                    //sum < 0
                    while (low < n && num[low] == num[low+1]) {
                        low++;
                    }
                    low++;
                }
            }
        }
        return result;

    }
    void printMatrix(vector<vector<int> > &matrix)
    {
        for(int i=0; i<matrix.size(); i++){
            printf("{");
            for(int j=0; j< matrix[i].size(); j++) {
                printf("%3d ", matrix[i][j]) ;
            }
            printf("}\n");
        }
        cout << endl;
    }

};

int main()
{
    Solution s;
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > result = s.threeSum(num);
    s.printMatrix(result);
    return 0;
}


