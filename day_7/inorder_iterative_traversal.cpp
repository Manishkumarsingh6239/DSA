#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // if(root==nullptr) ;
        // inorderTraversal(root->left);
        // ans.push_back(root->val);
        // inorderTraversal(root->right);
        // return ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node!=nullptr){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;

    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);
    cout<<"Inorder traversal of the tree is: ";
    for(int i: ans) cout<<i<<" ";
}