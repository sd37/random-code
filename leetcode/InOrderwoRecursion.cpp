/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
void inorder_helper(TreeNode *root,vector<int>& inorder_traversal)
{
    stack<struct TreeNode> st;
    
    while(!(root == NULL && st.empty()))
    {
        if(root)
        {
            while(root->left != NULL)
            {
                st.push(*root);
                root = root->left;
            }
            st.push(*root); //this is needed to push the last node for which the while condition failed.
        }
        
        struct TreeNode temp = st.top(); //copy the value
        st.pop();
        inorder_traversal.push_back(temp.val);
        
        root = temp.right;
    }
}

public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder_traversal;
        inorder_helper(root,inorder_traversal);
        return inorder_traversal;
    }
};
