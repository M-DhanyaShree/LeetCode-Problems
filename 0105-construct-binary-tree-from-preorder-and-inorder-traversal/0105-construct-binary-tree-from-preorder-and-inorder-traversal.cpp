/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* build(vector<int>& pre,int& pi,int l,int r,unordered_map<int,int>& mp) {
        if(l>r) return NULL;
        int val=pre[pi++];
        TreeNode* root=new TreeNode(val);
        int idx=mp[val];
        root->left=build(pre,pi,l,idx-1,mp);
        root->right=build(pre,pi,idx+1,r,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n=inorder.size(),pi=0;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        return build(preorder,pi,0,n-1,mp);
    }
};