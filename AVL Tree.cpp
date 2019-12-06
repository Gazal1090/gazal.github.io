
#include <iostream>
#include <cmath>
using namespace std;

struct node{

	int key;
	int height;
	node *left;
	node *right;
};

node* get_node(int value){
	node * node = new struct node();
	node->key=value;
	node->height=1;
	node->left=NULL;
	node->right=NULL;

	return node;
};

	int height(node *N)  
	{  
    	if (N == NULL)  
        	return 0;  
    	return N->height;  
	};


	int balancing_f(node *node)
	{
		if(node==NULL)
			return 0;
		int h = height(node->right) - height(node->left);
		return h;
	};


	node* left_rotate(node* root)
	{
		node* x = root->right;
		node* y = x->left;

		x->left = root;
		root->right = y;

		root->height = 1 + max(height(root->left) , height(root->right));
		x->height = 1 + max(height(x->left) , height(x->right));
		return x;

	};

	node* right_rotate(node* root)
	{
		node* x = root->left;
		node* y = x->right;

		x->right = root;
		root->left = y;

		root->height = 1 + max(height(root->left) , height(root->right));
		x->height = 1 + max(height(x->left) , height(x->right));

		return x;

	};

	node* balancing(node* root, int balance,int key)
	{
		if(balance >1 && key>root->right->key)
			return left_rotate(root);		// right - right rotation

		else if(balance <-1 && key<root->left->key)
			return right_rotate(root);		// left-left rotation

		else if(balance >1 && key<root->right->key)
		{
			root->right = right_rotate(root->right);
			return left_rotate(root);		// left-right rotation
		}

		else if(balance <-1 && key>root->left->key)
		{

			root->left = left_rotate(root->left);
			return right_rotate(root);	    // right-left rotation
		}

		else
			return root;
	};

	node* insert(node* root,int key)
	{
		if(root==NULL)
		{
			struct node* newnode=get_node(key);
			root=newnode;
			return root; 
		}

		if(key < root->key)
			root->left = insert(root->left,key);

		else if(key > root->key)
			root->right = insert(root->right,key);

		else
			return root;

		root->height = 1 + max(height(root->left) , height(root->right));
		int balance = balancing_f(root);
		return balancing (root,balance,key);
	}

	node* min_element(node* node)
	{	
		struct node* min=node;
		while(node!=NULL)
		{
			min=node;
			node=node->left;
		}

		return min;
	};

	node* delete_(node *root,int key)
	{
		if(root==NULL)
			return root;

		if(key < root->key)
			root->left = delete_(root->left,key);

		else if(key > root->key)
			root->right = delete_(root->right,key);

		else
		{

			if(root->left==NULL && root->right==NULL)
				root=NULL;
			
			else if(root->left==NULL)
			{
				root = root->right;
				root->right = NULL;
			}

			else if(root->right==NULL)
			{
				root = root->left;
				root->left = NULL;
			}

			else
			{
				struct node *min=min_element(root);
				root->key=min->key;
				min=min->right;
				min->right = NULL;
			}

			if(root==NULL)
				return root;

			root->height = 1 + max(height(root->left) , height(root->right));
			int balance = balancing_f(root);
			return balancing (root,balance,key);

		}
	}

	void InOrder(node *root)  
	{  
    	if(root != NULL)  
    	{    
        	InOrder(root->left);  
        	cout << root->key << " ";
        	InOrder(root->right);  
    	}  
	}; 
   
	int main()  
	{  
    	node *root = NULL;   
    	root = insert(root, 10);  
    	root = insert(root, 20);  
    	root = insert(root, 30);  
    	root = insert(root, 40);
    	root = insert(root, 50);  
    	root = insert(root, 25);  
      	
    
    	cout << "Inorder traversal of the "
            "constructed AVL tree is \n";  
   		InOrder(root);   
      	
    	return 0;  
	}  
