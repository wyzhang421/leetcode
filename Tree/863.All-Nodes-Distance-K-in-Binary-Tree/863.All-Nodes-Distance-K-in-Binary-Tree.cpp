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
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return res;
    }
    
    // return is the depth from curNode to target if they are in the same branch
    // if they are not in the same branch, return -1
    int dfs(TreeNode* curNode, TreeNode* target, int k) {
        if (!curNode) {return -1;}
        
        // if the curNode == target, find the subTree which the curNode is the root;
        if (curNode->val == target->val) {
            fetch(curNode, k);
            return 0;
        }
        
        // find the distance in the left branch, it will help us to find the eligible nodes in the right branch.
        int leftDepth = dfs(curNode->left, target, k);
        if (leftDepth != -1) {
            if (k - 1 == leftDepth) {
                res.push_back(curNode->val);
            } else {
                fetch(curNode->right, k - leftDepth - 2);
                return leftDepth + 1;
            }
        }
        
        // find the distance in the right branch, it will help us to find the eligible nodes in the left branch.
        int rightDepth = dfs(curNode->right, target, k);
        if (rightDepth != -1) {
            if (k - 1 == rightDepth) {
                res.push_back(curNode->val);
            } else {
                fetch(curNode->left, k - rightDepth - 2);
                return rightDepth + 1;
            }
        }
        return -1;
    }
    
    // This function is to get all eligible children from the curNode with a distance
    void fetch(TreeNode* curNode, int distance) {
        if (!curNode || distance < 0) {return;}
        if (distance == 0) {
            res.push_back(curNode->val);
            return;
        }
        fetch(curNode->left, distance - 1);
        fetch(curNode->right, distance - 1);
    }
};