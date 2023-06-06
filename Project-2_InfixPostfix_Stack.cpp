#include<iostream>
using namespace std;

template <typename T> class Stack_Linklist
{
	private:
		T data;
		Stack_Linklist *next,*top;
	public:
		Stack_Linklist()
		{
			top=NULL;
		}
		void push(T);
		void pop();
		void infixtopostfix(char[],char[]);
		void reverse(char[],char[]);
		void infixtoprefix(char[],char[]);
        void postfixEvaluation(char[]);
		void prefixEvaluation(char[]);
};

template <typename T> void Stack_Linklist <T> :: push(T x)
{
	Stack_Linklist <T>*newnode;
	newnode = new Stack_Linklist();
	newnode->data=x;
	newnode->next=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}

template <typename T> void Stack_Linklist <T> :: pop()
{
	if(top==NULL)
	{
        cout<<"Empty Stack";
		return;
	}
    else
    {
	    top=top->next;
    }
}

template <typename T> int priority  (T x)
{
	if(x=='*' || x=='/')
	{	
		return 2;
	}
	else if(x=='+' || x=='-')
	{
		return 1;
	}
	else
	{
		return 0; 
	}
}

template <typename T > void Stack_Linklist <T> :: infixtopostfix(char infix[],char postfix[])
{
	int i=0,j=0;
	while(infix[i]!='\0')
	{
		if(!(isalnum(infix[i])))
		{
			if(top==NULL)
            {
				push(infix[i]);
            }
			else if(infix[i]=='(')
            {
				push(infix[i]);
            }
			else if(infix[i]==')')
			{
				while(top->data!='(')
				{
					postfix[j]=top->data;
					j++;
					pop();
				}
				pop();
			}
			else
			{
				while(priority(infix[i])<priority(top->data))
				{
					postfix[j]=top->data;
					j++;
					pop();
					if(top==NULL)
					break;
				}
				push(infix[i]);
			}
		}
		else
		{
			postfix[j]=infix[i];
			j++;
		}
		i++;
	}
	while(top!=NULL)
	{
		postfix[j]=top->data;
		j++;
		pop();
	}
	postfix[j]=='\0';
}

template <typename T> void Stack_Linklist <T> :: reverse(char infix[], char revinfix[])
{
	int i=0,j=0,length=0;
	while(infix[i]!='\0')
    {
		i++;
    }
	length=i;
	i--;
	for( j=0;j<length;j++)
	{
		if(infix[i]=='(')
		{
			revinfix[j]=')';
		}
		else if(infix[i]==')')
		{
			revinfix[j]='(';
		}
		else 
		{
			revinfix[j]=infix[i];
		}
		i--;
	}
	revinfix[j]='\0';
}

template <typename T> void Stack_Linklist <T> :: infixtoprefix(char infix[], char prefix[])
{
    char exp[100];
	reverse(infix,exp);
	infixtopostfix(exp,prefix);
	reverse(prefix,exp);
    cout<<"\nPrefix expression is > > > "<<exp<<'\n';
}

template <typename T> void Stack_Linkedlistm<T> :: postfixEvaluation(T postfix[])
{
	int i=0;
	float result;
	cout<<postfix;
	while(postfix[i]!='\0')
	{
		if(isdigit(postfix[i]))
		{
			push(postfix[i]);
		}
		else
		{	int x,y;
			x=(top->data)-48;
			pop();
			y=(top->data)-48;
			pop();
			if(postfix[i]=='+')
			{
				result=y+x;
			}
			if(postfix[i]=='-')
			{
				result=y-x;
			}
			if(postfix[i]=='*')
			{
				result=y*x;	
			}
			if(postfix[i]=='/')
			{
				result=y/x;	
			}
			cout<<result;	
			push(result+48);		
		}
		i++;
	}
	result=(top->data)-48;
	pop();
}

template <typename T> void Stack_Linkedlist <T> :: prefixEvaluation(T prefix[])
{
	int i=0;
	float result;
	float result1;
	infixtoprefix(infix,postfix,revinfix,prefix);
	while(prefix[i]!='\0')
	{
		i++;
	}
	i--;
	while(i>=0)
	{
		if(isalpha(prefix[i]))
		{
			cout<<"Enter the value for :"<<prefix[i]<<" ";
			cin>>eval[i];
			push(eval[i]);
		}
		else
		{
			float x=top->data;
			pop();
			float y=top->data;
			pop();
			if(prefix[i]=='+')
			{
				result=x+y;
			}
			if(prefix[i]=='-')
			{
				result=x-y;
			}
			if(prefix[i]=='*')
			{
				result=x*y;
			}
			if(prefix[i]=='/')
			{
				result=x/y;
			}
			push(result);
		}
		i--;
	}
	result1=top->data;
}

int main()
{
	Stack_Linklist<char> obj1;
	Stack_Linklist<int> obj2;
	float result;
	int ch;
	char infix[100],postfix[100],prefix[100],revinfix[100];
    cout<<"\nEnter Infix Expression > > > ";
	cin>>infix;
	do
	{
		cout<<"\n1.Postfix Expression \n2.Prefix Expression \n3.Postfix Evaluation \n4.Prefix Evaluation \n5.Exit";
		switch(ch)
		{
			case 1:
				obj1.infixtopostfix(infix,postfix);
				cout<<"\nPostfix Expression is > > > "<<postfix;
				break;
			case 2:
				obj1.infixtoprefix(infix, prefix);
				cout<<"\nPrefix Expression is > > > "<<prefix;
				break;
			case 3:
				obj2.postfixEvaluation(postfix);
				cout<<"\nPostfix Evaluation > > > "<<result;
				break;
			case 4:
				obj2.prefixEvaluation(prefix);
				cout<<"\nPrefix Evaluation > > > "<<result;
				break;
		}
	}while(ch!=5);	
	return 0;
}