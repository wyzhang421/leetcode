### 094.Binary-Tree-Inorder-Traversal

题目链接： [link](https://leetcode.com/problems/binary-tree-inorder-traversal/)

思路：

解法1: 递归

**Solution 1**

<details>
<summary>solution</summary>

```C++
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
// time complexity: O(n)
// space complexity: O(n) stack space
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderHelper(root, ans);
        return ans;
    }
    void inorderHelper(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }
        inorderHelper(root->left, ans);
        ans.push_back(root->val);
        inorderHelper(root->right, ans);
    }
};
```

</details>