//
// Created by Belal on 08-Jul-25.
//


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
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr) return nullptr;
        TreeNode* curr = root;



        invertTree(curr->left);
        invertTree(curr->right);
        swapChildren(curr);



        return root;
    }

    void swapChildren(TreeNode* node) {
        if (!node) return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};