#include<iostream>
using namespace std;

class Tree
{
	private:
		int data;
   	        Tree*root;
   	        Tree*parent;
   	        Tree*left;
    	    	Tree*right;
    	    	Tree*current;
    	public:
		Tree()
		{
			root=NULL;
		}
		Tree*Create(int);
		void Insert(Tree* , int);
		void Search(Tree* , int);
		void Remove(Tree* , int);
		void InorderTraversal(Tree*);
		void PostorderTraversal(Tree*);
		void PreorderTraversal(Tree*);
		void Display(Tree*);
};

Tree*Tree :: Create(int a)
{
        Tree*newnode=new Tree();
        newnode->data=a;
        newnode->left=NULL;
        newnode->right=NULL;    
        return newnode;
}

void Tree :: Insert(Tree*current , int key)
{
        while(current != NULL)
        {
                if(current->data < key)
                {
                        parent = current;
                        current = current->right;
                }
                else if(current->data > key)
                {
                        parent = current;
                        current = current->left;
                }
        }
        if(parent->data > key)
        {
                parent->left=newnode;
        }
        else if(parent->data < key)
        {
                parent->right=newnode;
        }
}

void Tree :: Search(Tree*current , int key)
{
        while(current != NULL)
        {
                if(current->data == key)
                {
                        current=current->parent;
                }
                else
                {
                        if(current->data > key)
                        {
                                current=current->left;
                        }
                        else if(current->data < key)
                        {
                                current=current->right;
                        }
                }
        }
        if(current == NULL)
        {
                cout<<"Element Not Found";
        }
}

void Tree :: Remove(Tree*current , int key)
{
	int temp;
	//Case 1:
    	if(current->left == NULL && current->right == NULL)
	{
		if(parent->left == current)
		{
			parent->left=NULL;
		}
		else
		{
			parent->right=NULL;
		}
		delete(current);
	}
	
	//Case 2:
	if(current->left != NULL && current->right == NULL)
	{
		if(current = parent -> right)
		{
			parent->right=current->left;
		}
		else
		{
			parent->left=current->left;
		}
		delete(current);
	}
	else if(current->left == NULL && current->right != NULL)
	{
		if(current = parent->right)
		{
			parent->right=current->left;
		}
		else
		{
			parent->left=current->left;
		}
		delete(current);
	}
	
	//Case 3:
	if(current ->left !=NULL && current->right!=NULL)
	{
		parent=current;
		temp=current->left;
		while(temp -> right != NULL)
		{
			parent=temp;
			temp=temp->right;
		}
		current->data=temp->data;
		if(parent = current)
		{
			parent->left=temp->left;
		}
		else
		{
			parent->right=temp->left;
		}
		delete(current);
	}
}

void Tree::InorderTraversal(Tree* current)
{
	if (current != NULL)
	{
		InorderTraversal(current->left);
		cout << current->data << " ";
		InorderTraversal(current->right);
	}
}

void Tree::PostorderTraversal(Tree* current)
{
	if (current != NULL)
	{
		PostorderTraversal(current->left);
		PostorderTraversal(current->right);
		cout << current->data << " ";
	}
}

void Tree::PreorderTraversal(Tree* current)
{
	if (current != NULL)
	{
		cout << current->data << " ";
		PreorderTraversal(current->left);
		PreorderTraversal(current->right);
	}
}

void Tree::Display(Tree* current)
{
	cout << "\nInorder Traversal: ";
	InorderTraversal(current);

	cout << "\nPostorder Traversal: ";
	PostorderTraversal(current);

	cout << "\nPreorder Traversal: ";
	PreorderTraversal(current);

	cout << endl;
}

int main()
{
	int key, a, ch;
	Tree* current;
	Tree T;
	cout << "\nCreate Binary Search Tree ";
	T.Create(a);
	do
	{
		cout << "\n1.Insert \n2.Search \n3.Delete \n4.Inorder Traversal \n5.Postorder Traversal \n6.Preorder Traversal \n7.Display \n8.Exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			T.Insert(current, key);
			break;
		case 2:
			T.Search(current, key);
			break;
		case 3:
			T.Remove(current, key);
			break;
		case 4:
			T.InorderTraversal(current);
			break;
		case 5:
			T.PostorderTraversal(current);
			break;
		case 6:
			T.PreorderTraversal(current);
			break;
		case 7:
			T.Display(current);
			break;
		}
	} while (ch != 8);
	return 0;
}
