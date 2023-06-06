#include<iostream>
using namespace std;
class Queue
{
	private:
		int rear,front,item;
	public:
		void enqueue(int q[],int n);
		void dequeue(int q[],int n);
		void display(int q[],int n);
		Queue()
		{
			front=-1;
			rear=-1;
		}
};

void Queue::enqueue(int q[],int n)
{
	if(rear==n-1)
	{
		cout<<"Queue overflow ! "<<endl;
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		cout<<"\nEnter element > > > ";
		cin>>item;
		rear++;
		q[rear]=item;
	}
}

void Queue::dequeue(int q[],int n)
{
	int A;
	if(front==-1)
	{
		cout<<"\nQueue is Empty";
	}
	else
	{
		A=q[front];
		cout<<"\nDeleted element is > > "<<A;
		front++;
	}
}

void Queue::display(int q[],int n)
{
	for(int i=front;i<=rear;i++)
	{
		cout<<q[i]<<"\t";
	}
}

int main()
{
	int n,s,ch;
	char ans;
	Queue x;
	cout<<"\nEnter the size of element > > > ";
	cin>>s;
	int q[s];
	do
	{
		cout<<"\n1.INSERT Element\t"<<"2.DELETE Element\t"<<"3.DISPALY Element\t"<<"4.Exit";
		cout<<"\nEnter Your Choice > > > ";
		cin>>ch;
		switch(ch)
		{
			case 1:x.enqueue(q,s);
				break;
			case 2:x.dequeue(q,s);
				break;
			case 3:x.display(q,s);
				break;
		}
	}while(ch!=4);
	return 0;
}