class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int flag=1;
        if(root==NULL) return {};
        q.push(root);
        while(!q.empty()) {
            int s=q.size();
            vector<int> t2(s);
            for(int i=0;i<s;i++) {
                TreeNode* temp=q.front();
                q.pop();
                int idx=flag==1?i:s-1-i;
                t2[idx]=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            ans.push_back(t2);
            flag=(flag==1)?0:1;
        }
        return ans;
    }
};