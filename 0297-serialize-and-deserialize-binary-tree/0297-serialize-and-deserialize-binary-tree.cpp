/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void ser(TreeNode* root,string& ans) {
        if(root==NULL) {
            ans+="#,";
            return;
        }
        ans+=to_string(root->val)+",";
        ser(root->left,ans);
        ser(root->right,ans);
    }
    TreeNode* des(stringstream& ss) {
        string cur;
        getline(ss,cur,',');
        if(cur=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(cur));
        root->left=des(ss);
        root->right=des(ss);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        ser(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       stringstream ss(data);
        return des(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));