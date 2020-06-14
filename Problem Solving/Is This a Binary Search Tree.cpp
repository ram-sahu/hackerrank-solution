/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

int isBST(Node* node, int min=0, int max=10000)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBST(node->left, min, node->data-1) && // Allow only distinct values  
        isBST(node->right, node->data+1, max); // Allow only distinct values  
}  
  

bool checkBST(Node* root) {
    return isBST(root);
}
