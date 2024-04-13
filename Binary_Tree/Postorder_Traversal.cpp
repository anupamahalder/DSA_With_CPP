/*
Create a binary tree and traverse the binary tree using postorder traversal.

*/
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
    	int val;
        TreeNode *left;
        TreeNode *right;
      	// constructor to initialize the member variables
        TreeNode(int val){
        	this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
TreeNode* input_tree(){
	// if input value is -1 means there is null value we can assume
	int val;
    cout<<"Enter the element:";
    cin>>val;
    TreeNode *root;
    if(val == -1) root=NULL;
    else root = new TreeNode(val);
    // take a queue for taking input in level order
    queue<TreeNode*>q;
    if(root) q.push(root);
    while(!q.empty()){
    	// take out node from the queue
        TreeNode *p = q.front();
        q.pop();
        // take the input for children nodes
        int l, r;
        cin>>l>>r;
        // take two node for left and right
        TreeNode *nleft, *nright;
        if(l == -1) nleft = NULL;
        else nleft = new TreeNode(l);
        
        if(r == -1) nright = NULL;
        else nright = new TreeNode(r);
        
        // make connection of children node to its parent
        p->left = nleft;
        p->right = nright;
        
        // now push the chidren node to queue
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

void postOrder(TreeNode *root, vector<int>&ans){
    // base case 
    if(root == NULL) return;
    // go to left 
    postOrder(root->left, ans);
    // go to right 
    postOrder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    postOrder(root, ans);
    return ans;
}
int main(){
	TreeNode *root = input_tree();
    vector<int>ans;
    ans = postorderTraversal(root);
    // print the post order of the binary tree 
    cout<<"After postorder traversal:\n";
    for(int num: ans){
    	cout<<num<<" ";
    }
    cout<<'\n';
	return 0;
}
