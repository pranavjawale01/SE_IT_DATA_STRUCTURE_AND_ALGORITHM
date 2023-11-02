#include<iostream>
using namespace std;

class Stack;

class Tree
{
	private:
    		char data;
   	    	Tree*Left;
	    	Tree*Right;
    	public:
       		Tree*create(char);
		Tree*CreateTree(char[]);
        	void inorderRecursive(Tree*);
        	void preorderRecursive(Tree*);
        	void postorderRecursive(Tree*);
        	void inorderIterative(Tree*);   
        	void postorderIterative(Tree*);  
        	void preorderIterative(Tree*);
};

class Stack
{
    private:
        Tree*root;
        Stack*next;
        Stack*top;
    public:
        int flag;
        void push(Tree*,int);
        Tree*pop();
        int empty();
        int FlagReturn();
        Stack()
        {
            flag=0;
            top=NULL;
        }
};

Tree*Tree :: create(char a)
{
    Tree*newnode=new Tree();
    newnode->data=a;
    newnode->Left=NULL;
    newnode->Right=NULL;    
	
    return newnode;
}

Tree*Tree::CreateTree(char postfix[])
{
    Stack s;
	Tree *result;
	int i = 0;
	while(postfix[i] != '\0')
	{
		if(isalnum(postfix[i]))
		{
			s.push(create(postfix[i]),0);
		}
		else
		{
			Tree *x,*y,*current;
			current = create(postfix[i]);
			x = s.pop();
			y = s.pop();
			current->Right = x;
			current->Left = y;
			s.push(current,0);
		}
		i++;
	}
	result = s.pop();
	return result;
}
int Stack::FlagReturn()	
{	
    return top->flag;
}

int Stack::empty()
{
	if(top == NULL)
		return 0;
	else
		return 1 ;	
}

void Stack::push(Tree *node,int flag)
{
	Stack *newnode;
	newnode = new Stack();
	newnode->root = node;
	newnode->flag = flag;
	newnode->next = top;
	top = newnode;
}

Tree* Stack::pop()
{
	Stack *ptr;
	ptr = top;
	top = top->next;
	ptr->next = NULL;
	return ptr->root;
}

void Tree :: inorderRecursive(Tree*curr)
{
    if(curr!=NULL)
    {
        inorderRecursive(curr->Left);
        cout<<curr->data;
        inorderRecursive(curr->Right);
    }
}

void Tree :: preorderRecursive(Tree*curr)
{
    if(curr!=NULL)
    {
        cout<<curr->data;
        preorderRecursive(curr->Left);
        preorderRecursive(curr->Right);
    }
}

void Tree :: postorderRecursive(Tree*curr)
{
    if(curr!=NULL)
    {
        postorderRecursive(curr->Left);
        postorderRecursive(curr->Right);
        cout<<curr->data;
    }
}

void Tree :: inorderIterative(Tree*curr)
{
    Stack s;
	while(1)
	{
		while(curr!=NULL)
		{
			s.push(curr,0);
			curr = curr->Left;
		}
		if(s.empty() == 0)
        {
			break;
        }
		curr = s.pop();
		cout<<curr->data;
		curr = curr->Right;
	}
}

void Tree :: preorderIterative(Tree*curr)
{
    Stack s;
	while(1)
	{
		while(curr!= NULL)
		{
			cout<<curr->data;
			if(curr->Right!= NULL)
            {
				s.push(curr->Right,0);
            }
			curr=curr->Left;
		}
		if(s.empty()== 0)
        {
			break;	
        }
		curr=s.pop();	
	}
}

void Tree :: postorderIterative(Tree*curr)
{
    int flag;
	Stack s;
	do
    	{
		while(curr!= NULL)
		{
			s.push(curr , s.flag );
			curr = curr->Left;
		}
		flag = s.FlagReturn();
		curr = s.pop();
		if(flag==1)
		{
			cout<<curr->data;
			curr = NULL;
		}
		else
		{
			s.push(curr,1);
			if(curr->Right)
            		{
				curr = curr->Right;
           		}
			else
            		{
				curr = NULL;
           		}
		}
	}while(s.empty()!=0);
}


int main()
{
    Tree t;
	Tree*root;
	char str[10];
	int len = 0, ch, ch1, ch2 ,ch3;
	cout<<"Enter the Postfix Expression > > > ";
	cin>>str;
	while(str[len] != '\0')
		len++;
	char *postfix=new char(len);
	postfix = str;
	root = t.createpostfix(postfix);
	do
	{
		cout<<"\n1.Inorder R \n2.Inorder NR \n3.Preorder R \n4.Preorder NR \n5.Postorder R \n6.Postorder NR \n7.Exit ";
    	cin>>ch;
		switch(ch)
		{
           		case 1:
                		t.inorder(root);
                		cout<<"\n";
				break;
            		case 2:
		        	t.nrinorder(root);
                		cout<<"\n";
				break;
            		case 3:
                		t.preorder(root);
                		cout<<"\n";
			    	break;
            		case 4:
                		t.nrpreorder(root);
                		cout<<"\n";
	            		break;
            		case 5:
                		t.postorder(root);
                		cout<<"\n";
				break;
            		case 6:
	        		t.nrpostorder(root);
                		cout<<"\n";	
			    	break;
		}						
	}while(ch!=7);
 	return 0;
}
