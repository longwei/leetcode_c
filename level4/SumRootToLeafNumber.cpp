class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(root == nullptr) return 0;
        return sumRec(root, 0);
    }

    int sumRec(TreeNode* root, int last){
        int sum = last*10 + root->val;
        if(!root->left && !root->right){
            return sum;
        }
        int val = 0;
        if(root->left) val+=sumRec(root->left, sum);
        if(root->right) val+=sumRec(root->right, sum);
        return val;
    }
};