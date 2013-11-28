#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<list>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


class Tree
{
        unsigned int V;
        void InOrder(struct TreeNode*,vector<struct TreeNode> &v_list);
        bool isSorted(vector<struct TreeNode>&);    
    public:
        Tree();
        bool isValidBSTSimple(struct TreeNode* root);
        bool isValidBST(struct TreeNode* root);
        struct TreeNode* addNode(int val,struct TreeNode* left , struct TreeNode* right);
};

Tree::Tree()
{
    this->V = 0;
}

struct TreeNode* Tree::addNode(int val,struct TreeNode* left , struct TreeNode* right)
{
    //returns the node just added
    struct TreeNode* new_node = new TreeNode;
    
    if(new_node == NULL)
    {
        perror("memory allocation failure\n");
    }
    new_node->val = val;
    new_node->left = left;
    new_node->right = right;
    this->V++;
    return new_node;
}

bool Tree::isSorted(vector<struct TreeNode>& v_list)
{
    for(unsigned int i = 1; i < v_list.size() ; i++)
    {
        if(v_list[i-1].val >= v_list[i].val)
            return false;
    }

    return true;
}

void Tree::InOrder(struct TreeNode* root,vector<struct TreeNode> &v_list)
{
    if(root)
    {
        InOrder(root->left,v_list);
        v_list.push_back(*root);
        InOrder(root->right,v_list);
    }

}

bool Tree::isValidBSTSimple(struct TreeNode* root)
{
    vector<struct TreeNode> inorder_traversal;
    this->InOrder(root,inorder_traversal);
    return isSorted(inorder_traversal);
}

bool Tree::isValidBST(struct TreeNode* root)
{
    static TreeNode *prev = NULL; 
    // leetcode declare it as a global variable as static variables retains it values between function calls .. so prev is not reset properly. 

    if(root)
    {
        if(!isValidBST(root->left))
           return false;
        
        if(prev != NULL && prev->val >= root->val )
            return false;
        prev = root;

        return isValidBST(root->right); 
    }

   return true;
}


int main()
{
    fflush(stdout);

    Tree tr;
    struct TreeNode* n1 = tr.addNode(6,NULL,NULL);
    struct TreeNode* n2 = tr.addNode(9,NULL,NULL);
    struct TreeNode* n3 = tr.addNode(13,NULL,NULL);
    struct TreeNode* n4 = tr.addNode(13,n1,NULL);
    struct TreeNode* n5 = tr.addNode(12,NULL,n3);
    struct TreeNode* n6 = tr.addNode(10,n4,n5);
    
    struct TreeNode* root = n4;
    if(tr.isValidBSTSimple(root))    
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    
    printf("\n");
    return 0;
}
