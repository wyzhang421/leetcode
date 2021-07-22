### 863.All-Nodes-Distance-K-in-Binary-Tree

题目链接： [link](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

思路：

解法1: 想象两个节点 A 和 B 之间的路径，他们之间可以想象在一个节点 O 的左右两侧，那么左分支是 OA， 右分支是 OB，我们递归的处理每个节点 node，把 node 当作是 O， 假设 A 就是 target，那么如何从 OB 中寻找 B，假设 target 到 node->left 之间的距离是 t， 那么我们只需要从 node->right 出发走 k-t-2 就可以找到所有符合条件的 B。同理，如果 target 位于当前 node 的右分支，一样的处理。

如果 O 就是距离 target 距离为 k 的点，那么就直接放进结果的数组中。

如果 O 就是 target 呢，就直接找以 O 为 root 的所有子节点中距离为 k 的点。

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
```

</details>