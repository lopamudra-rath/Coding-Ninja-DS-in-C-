// ZigZag tree
// Send Feedback
// Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
// Input format :

// Elements in level order form (separated by space)

// (If any node does not have left or right child, take -1 in its place)

// Output Format :

// Elements are printed level wise, each level in new line (separated by space).

// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output :
// 5
// 10 6
// 2 3
// 9

/*#include <stack>

void zigzag(BinaryNodeTree<int>* root){
    stack<BinaryNodeTree<int>> s1;
    stack<BinaryNodeTree<int>> s2;
    
    s1.push(root);
    s2.push(root);
    
    while(!s1.isEmpty() && !s2.isEmpty()){
        BinaryNodeTree<int> temp = s2.pop();
        
        while(!s1.isEmpty()){
            if(s1.peek()->left != NULL){
                s2.push(s1.peek()->left);
            }
            if(s1.peek()->right != NULL){
                s2.push(s1.peek()->right);
            }
            cout<<s1.pop()<<" "; 
        }
        cout<<endl;
        while(!s2.isEmpty()){
            if(s2.peek()->right != NULL){
                s1.push(s2.peek()->right);
            }
            if(s2.peek()->left != NULL){
                s1.push(s2.peek()->left);
            }
            cout<<s2.pop()<<" "; 
        }
        cout<<endl;
        s2.push(root);
    }
}*/
int count(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1+ count(root->left)+ count(root->right);
}

void zigZag(BinaryTreeNode<int>* root, int n){
    BinaryTreeNode<int> * queue[2 * n];
    int top = -1;
    int front = 1;
    queue[++top] = NULL;
    queue[++top] = root;
    queue[++top] = NULL;
 
    // struct Node* t=root;
    int prevFront = 0, count = 1;
    while (1) {
 
        BinaryTreeNode<int> * curr = queue[front];
 
        // A level separator found
        if (curr == NULL) {
 
            // If this is the only item in dequeue
            if (front == top)
                break;
 
            // Else print contents of previous level
            // according to count
            else {
                if (count % 2 == 0) {
                    for (int i = front - 1; i > prevFront; i--)
                        printf("%d ", queue[i]->data);
                }
                else {
                    
                    for (int i = prevFront + 1; i < front; i++)
                        printf("%d ", queue[i]->data);
                }
                cout<<endl;
 
                prevFront = front;
                count++;
                front++;
 
                // Insert a new level separator
                queue[++top] = NULL;
 
                continue;
            }
        }
 
        if (curr->left != NULL)
            queue[++top] = curr->left;
        if (curr->right != NULL)
            queue[++top] = curr->right;
        front++;
    }
 
    if (count % 2 == 0) {
       for (int i = top - 1; i > prevFront; i--)
            printf("%d ", queue[i]->data);
    }
    else {
        
         for (int i = prevFront + 1; i < top; i++)
            printf("%d ", queue[i]->data);
    }
}
void zigZagOrder(BinaryTreeNode<int> *root) {
    int n = count(root);
    zigZag(root, n);
}
