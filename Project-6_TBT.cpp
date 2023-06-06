#include<iostream>
using namespace std;
class tree
{
	int data ;
	tree *left, *right ,*head ;
	int lthread,rthread;
	public:
		tree* create(int);
		void insert(int);
		void inorder_tbt();
		void preorder_tbt();
		void check_head();
		tree* inorder_successor(tree *);
		tree()
		{
			head=NULL;
        }
};

tree* tree::create(int d)
{
	tree *newnode = new tree();
	newnode->left=head;
	newnode->right=head;
	newnode->lthread=1;
	newnode->rthread=1;
	newnode->data=d;
	return newnode;
}

void tree::insert(int key)
{
	if(head==NULL)
	{
		head=create(key);
		head->rthread=0;
	}
	else
	{
		tree *curr=head;
		tree *newnode;
		newnode=create(key);	
		if(head->lthread==1)
		{
			head->left=newnode;
			head->lthread=0;
		}
		else
		{
			curr=curr->left;
			while(1)
			{
				if(key>curr->data)
				{
					if(curr->rthread==1)
					{
						newnode->right=curr->right;
						curr->right=newnode;
						curr->rthread=0;
						newnode->left=curr;
						break;
					}
					else
						curr=curr->right;
				}
				else
				{
					if(curr->lthread==1)
					{
						newnode->left=curr->left;
						curr->left=newnode;
						curr->lthread=0;
						newnode->right=curr;
						break;
					}
					else
						curr=curr->left;
				}
			}
		}
	}
}		

void tree::inorder_tbt()
{
	tree *curr=head->left;
	while(curr->lthread!=1)
		curr=curr->left;
	cout<<curr->data<<"\t";
	while(curr->right!=head)
	{
		curr=inorder_successor(curr);
		cout<<curr->data<<"\t";
	}
}

tree* tree::inorder_successor(tree* curr)
{
	tree *temp=curr->right;
	if(curr->rthread!=1)
	{
		while(temp->lthread!=1)
		{
			temp=temp->left;
		}
	}
	return temp;
}			

void tree::preorder_tbt()
{
	if(head==NULL)
		cout<<"Tree has no node !!";
	tree* curr=head->left;	
	while(curr!=NULL)
	{
		cout<<curr->data<<"\t";
		if(curr->lthread==0)
			curr=curr->left;
		else if(curr->rthread==0)	
			curr=curr->right;
		else
		{
			while(curr!=NULL && curr->rthread==1)
				curr=curr->right;
			if(curr!=NULL)
				curr=curr->right;
		}				
	}
}	
						
int main()
{
	tree obj;
	int n,choice;
	int ele;
	cout<<"Enter the no.of elements you want to insert > > ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(i==0)
			obj.insert(1212);
		cout<<"Enter the element you want to insert > > ";
		cin>>ele;	
		obj.insert(ele);	
	}
	do
	{
		cout<<"\n1.Insert a new Element \n2.Apply In-order traversal \n3.Apply Pre-Order traversal \n4.Exit \nEnter your choice > > \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the element you want to insert > > ";
				cin>>ele;	
				obj.insert(ele);
				cout<<"Node inserted successfully !\n";
				break;
			case 2:
				cout<<"The In-Order Traversal is as follows > > \n";
				obj.inorder_tbt();
				break;				
			case 3:				
				cout<<"The Pre-Order Traversal is as follows > > \n";	
				obj.preorder_tbt();
				break;
		}		
    }while(choice!=4);	
	return 0;
}
/*    OUTPUT :
CASE 1:
Enter the no.of elements you want to insert:5
Enter the element you want to insert:6
Enter the element you want to insert:-2
Enter the element you want to insert:9
Enter the element you want to insert:1
Enter the element you want to insert:7
 1.Insert a new Element. 
 2.Apply In-order traversal. 
 3.Apply Pre-Order traversal 
 Enter your choice : 
2
The In-Order Traversal is as follows : 
-2	1	6	7	9	
Do you want to continue (y/n) ?y
 1.Insert a new Element. 
 2.Apply In-order traversal. 
 3.Apply Pre-Order traversal 
 Enter your choice : 
3
The Pre-Order Traversal is as follows : 
6	-2	1	9	7	
Do you want to continue (y/n) ?n

CASE 2:
Enter the no.of elements you want to insert:9
Enter the element you want to insert:4
Enter the element you want to insert:-232
Enter the element you want to insert:5
Enter the element you want to insert:9
Enter the element you want to insert:35
Enter the element you want to insert:986
Enter the element you want to insert:43
Enter the element you want to insert:-45
Enter the element you want to insert:1
 1.Insert a new Element. 
 2.Apply In-order traversal. 
 3.Apply Pre-Order traversal 
 Enter your choice : 
2
The In-Order Traversal is as follows : 
-232	-45	1	4	5	9	35	43	986	
Do you want to continue (y/n) ?Y
 1.Insert a new Element. 
 2.Apply In-order traversal. 
 3.Apply Pre-Order traversal A
 Enter your choice : 
1
Enter the element you want to insert:34
Node inserted successfully !

Do you want to continue (y/n) ?Y
 1.Insert a new Element. 
 2.Apply In-order traversal. 
 3.Apply Pre-Order traversal 
 Enter your choice : 
2
The In-Order Traversal is as follows : 
-232	-45	1	4	5	9	34	35	43	986	
Do you want to continue (y/n) ?Y
 1.Insert a new Element. 
 2.Apply In-order traversal. 
 3.Apply Pre-Order traversal 
 Enter your choice : 
3
The Pre-Order Traversal is as follows : 
4	-232	-45	1	5	9	35	34	986	43	
Do you want to continue (y/n) ?	n
*/