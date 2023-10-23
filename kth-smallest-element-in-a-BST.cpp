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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return kthSmallestHelper(root, k, count).second;
    }
    
private:
    // Helper function to perform in-order traversal and find kth smallest element
    pair<int, int> kthSmallestHelper(TreeNode* node, int k, int count) {
        if (node == nullptr) return {count, -1};  // -1 is a placeholder
        
        // Traverse the left subtree
        auto leftResult = kthSmallestHelper(node->left, k, count);
        count = leftResult.first;
        if (count == k) {
            return leftResult;
        }
        
        // Process the current node
        count++;
        if (count == k) {
            return {count, node->val};
        }
        
        // Traverse the right subtree
        auto rightResult = kthSmallestHelper(node->right, k, count);
        return rightResult;
    }
};
