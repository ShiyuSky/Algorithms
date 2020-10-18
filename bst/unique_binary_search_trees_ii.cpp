/**
 * Question
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>{};
        }
        return generateTreesRecur(1, n);
    }
    
    vector<TreeNode*> generateTreesRecur(int start, int end) {
        vector<TreeNode*> res{};
        
        if (start > end) {
            TreeNode* node = NULL;
            res.push_back(node);
            return res;
        }
        if (start == end) {
            TreeNode* node = new TreeNode(start);
            res.push_back(node);
            return res;
        }
        for (int i=start; i<=end; i++) {
            vector<TreeNode*> lNodes = generateTreesRecur(start, i-1);
            vector<TreeNode*> rNodes = generateTreesRecur(i+1, end);
            
            for(TreeNode* lNode : lNodes) {
                for(TreeNode* rNode : rNodes) {
                    TreeNode* node = new TreeNode(i, lNode, rNode);
                    res.push_back(node);
                }   
            } 
        }
        return res;
    }
};