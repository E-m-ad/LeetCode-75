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
    bool isLeaf(TreeNode *node){
        return (!(node->left) && !(node->right));
    }
    void traversal(TreeNode* node , vector<int>&leaves) {
        if(!node)
            return;
        if(isLeaf(node))
            leaves.push_back(node->val);
        traversal(node->left , leaves);
        traversal(node->right , leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         if(!root1 || !root2)
            return true;
        
        vector<int> tree1;
        vector<int> tree2;
        traversal(root1 , tree1);
        traversal(root2 , tree2);

        if(tree1.size() != tree2.size())
            return false ;
        
        for(int i = 0 ; i < tree1.size() ; i++)
            if(tree1[i] != tree2[i])
                return false;

        return true;
        
        
        
    }
};