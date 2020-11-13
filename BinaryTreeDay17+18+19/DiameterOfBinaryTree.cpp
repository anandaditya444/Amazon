If we knew the maximum length arrows L, R for each child, then the best path touches L + R + 1 nodes.


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
    int ans = 1;
    int height(TreeNode* root)
        {
            if (root == NULL)
                return 0;
            int ls = height(root->left);
            int rs = height(root->right);

            ans = max(ans, ls + rs + 1);

            return max(ls, rs) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root) {
            if (root == NULL)
                return 0;
            height(root);

            return ans - 1;

        }
    };






// int height(Node* node)
// {
//     if(node == NULL)
//         return 0;
//     int ls = height(node->left);
//     int rs = height(node->right);

//     return max(ls,rs)+1;
// }

// int diameter(Node* node)
// {
//    if(node == NULL)
//     return 0;
//    int left = height(node->left);
//    int right = height(node->right);
//    int op1 = left+right+1;
//    int op2 = diameter(node->left);
//    int op3 = diameter(node->right);

//    return max(op1,max(op2,op3));
// }
