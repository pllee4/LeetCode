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
  int minCameraCover(TreeNode* root) {
    // inital root with NULL parent
    auto camera_state = GetCameraState(root, camera_num_);
    // check for the last node
    if (camera_state == CameraState::Uncovered) camera_num_++;
    return camera_num_;
  }

 private:
  enum class CameraState { Covered, Uncovered, Exist };
  int camera_num_;

  CameraState GetCameraState(TreeNode* root, int& camera_num) {
    // return Covered for null root since they do not exist
    if (!root) return CameraState::Covered;
    auto left = GetCameraState(root->left, camera_num);
    auto right = GetCameraState(root->right, camera_num);
    // add camera if it is not covered
    if (left == CameraState::Uncovered || right == CameraState::Uncovered) {
      camera_num++;
      return CameraState::Exist;
    }
    // if there is camera exists, considered as covered
    if (left == CameraState::Exist || right == CameraState::Exist)
      return CameraState::Covered;
    else
      return CameraState::Uncovered;
  }
};