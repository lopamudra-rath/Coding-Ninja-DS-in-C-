// Nodes without sibling
// Send Feedback
// Given a binary tree, print all nodes that don’t have a sibling.
// Edit : Print the elements in different lines. And order of elements doesn't matter.
// Input format :
// Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.
// Output format :
// Print nodes separated by new line.
// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output :
// 9   

void nodesWithoutSiblings(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    
    if(root->right == NULL && root->left != NULL){
        cout<<root->left->data;
    }
    if(root->right != NULL && root->left == NULL){
        cout<<root->left->data;
    }
    
    nodesWithoutSiblings(root->right);
     nodesWithoutSiblings(root->left);
    
}
