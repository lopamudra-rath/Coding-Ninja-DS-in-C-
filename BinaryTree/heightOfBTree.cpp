// Height Of Binary Tree
// Send Feedback
// Given a binary tree, find and return the height of given tree.
// Input format :
// Nodes in the level order form (separated by space). If any node does not have left or right child, take -1 in its place
// Output format :
// Height
// Constraints :
// 1 <= N <= 10^5
// Sample Input :
// 10
//  9 
// 4 
// -1 
// -1 
//  5 
//  8 
// -1 
// 6 
// -1 
// -1 
// 3 
// -1 
// -1
// -1
// Sample Output :
// 5

int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int left = root->left;
    int right = root->right;
    
    if(right > left){
        return (right + 1);
    }
    else{
        return (left + 1);
    }
}
