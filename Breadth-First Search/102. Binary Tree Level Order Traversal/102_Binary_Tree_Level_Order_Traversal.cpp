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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) return {};
    vector<vector<int>> result;
    vector<int> curr_level;

    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    // act as delimiter
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      if (node) {
        curr_level.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      } else {
        // signify ending of level
        result.push_back(curr_level);
        curr_level.clear();
        if (!q.empty()) q.push(nullptr);
      }
    }
    return result;
  }
};