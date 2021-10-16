/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return helper(root, p, q);
  }

 private:
  bool findNode(TreeNode* root, TreeNode* node_to_find) {
    if (!root) return false;
    if (root == node_to_find) return true;

    return findNode(root->left, node_to_find) ||
           findNode(root->right, node_to_find);
  }

  TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    // allow the node to be a descendant of itself
    if (root == p || root == q) return root;

    bool p_at_left = findNode(root->left, p);
    bool q_at_left = findNode(root->left, q);

    // indicate existence of common ancestor
    if (p_at_left != q_at_left) return root;

    if (p_at_left)
      return helper(root->left, p, q);
    else
      return helper(root->right, p, q);
  }
};