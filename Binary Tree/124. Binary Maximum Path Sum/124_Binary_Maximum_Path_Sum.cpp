/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val;
    int max_sum{INT_MIN};
    helper(root, max_sum);
    return max_sum;
  }

 private:
  int helper(TreeNode* root, int& max_sum) {
    // no root
    if (root == NULL) return 0;
    // get ans from left anf right child
    int left = helper(root->left, max_sum);
    int right = helper(root->right, max_sum);
    int max_node_val = max(root->val, max(left, right) + root->val);
    // compared with using chain
    int chained_node_val = max(max_node_val, left + right + root->val);
    max_sum = max(max_sum, chained_node_val);
    return max_node_val;
  }
};