#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x=0, TreeNode *left=nullptr, TreeNode *right=nullptr) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        if(root==NULL) return true;
        if(root->val >= maxVal || root->val<=minVal) return false;
        return isValidBST(root->left,minVal,root->val) && isValidBST(root->right,root->val,maxVal);
    }
};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    Solution sol;
    bool result = sol.isValidBST(root);
    
    cout << (result ? "true" : "false") << endl;
    
    return 0;
}