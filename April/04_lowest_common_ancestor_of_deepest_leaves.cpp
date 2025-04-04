// 1123. Lowest Common Ancestor of Deepest Leaves

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
public:
    unordered_map<int,int> mp;
    int maxL = INT_MIN;;
    void depth(TreeNode* root, int level){
        if(!root) return;

        maxL = max(maxL, level);
        mp[root->val] = level;
        depth(root->left, level+1);
        depth(root->right, level+1);
    }

    TreeNode* LCA(TreeNode* root){
        if(!root || mp[root->val] == maxL){
            return root;
        }

        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);

        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);
        return LCA(root);
    }
};