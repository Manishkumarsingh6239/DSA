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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        if((root->left == nullptr) && (root->right == nullptr)) return root;
        TreeNode* temp = root->right;
        root->right=root->left;
        root->left=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Solution sol;
    cout<<"Before inverting tree's inorder traversal: ";
    sol.inorder(root);
    cout<<endl;
    root=sol.invertTree(root);
    cout<<"After inverting tree's inorder traversal: ";
    sol.inorder(root);
}