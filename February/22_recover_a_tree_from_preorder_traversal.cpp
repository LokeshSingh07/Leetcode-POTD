// 1028. Recover a Tree From Preorder Traversal

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
    int n;
    TreeNode* solve(string &s, int &i, int depth){
        if(i>=n) return NULL;

        int j = i;
        while(j<n && s[j]=='-'){
            j++;
        } 

        int dash = j-i;
        if(depth != dash) return NULL;

        i=j;
        int num=0;
        while(i<n && isdigit(s[i])){
            num = num*10 + (s[i]-'0');
            i++;
        }

        TreeNode* node = new TreeNode(num);

        node->left = solve(s, i, depth+1);
        node->right = solve(s, i, depth+1);

        return node;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int i=0;
        int depth=0;

        return solve(traversal, i, depth);
    }
};