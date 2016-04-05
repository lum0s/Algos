#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct node{
	int data;
	node * left;
	node * right;
};

int search(node * root, int target){
	if(root==NULL){
		return 0;
	}

	if(root->data==target)
		return 1;

	if(root->data < target){
		return search(root->right, target);
	}
	else 
		return search(root->left, target);
}

node * newNode(int data){
	node * ptr = new node;
	ptr-> data = data;
	ptr->left = NULL;
	ptr->right= NULL;
	return ptr;

}

node * insert(node * root, int data){
	if (root==NULL){
		return newNode(data);
	}

	if (data<=root->data)
		root->left = insert(root->left, data);

	else
		root->right = insert(root->right, data);
	return root;
}


int maxDepth(){

}

int minDepth(){

}

int minElement(){

}

int maxElement(){

}

int LCA(){

}

int del_tree(){

}

node * create_tree(){
	int a,n,val;
	cin>>n;
	cin>>val;
	node * root=newNode(val);
	for (int i=0; i<n-1; i++){
		cin>>a;	
		insert(root,a);
	}
	return root;
}

/*int traverse(node * root, node *parent){
	if(root->left==NULL){
		cout<<root->data;
		if(root->right==NULL)

		cout<<parent->data;

		return 0;
	}
	else
		traverse()

}*/


node * traverse(node * root){
    if(root!=NULL){ 
    //for inorder use this   	
        traverse(root->left);
        cout<<root->data;
        traverse(root->right);         

    /*
    for a pre order traversal, cout the root first and then make the recursive call for both nodes.
    for a post order traversal, cout the roor and the end.
    */    
    }
}


int main(){
	node * root;
	root=create_tree();
	traverse(root);
	return 0;
}













