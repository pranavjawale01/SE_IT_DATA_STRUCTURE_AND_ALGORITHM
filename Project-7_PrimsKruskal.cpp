#include<iostream>
#include<cstdlib>
using namespace std;
class graphP
{

	int **mat;
	public:
		int source,dest,weight,v,e;
		int print;
		graphP()
		{
			cout<<"Enter how many elements your graph has : ";
			cin>>v;
			print=0;
			mat=new int*[v];
			for (int i=0;i<v;i++)
				mat[i]=new int[v];
		}		
		void create_matrix();
		int min_key(int [],bool []);
		void prims();
		void display(int [],int );
		//void krushkals(int);
};
void graphP ::create_matrix()
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			mat[i][j]=0;
	}
	char ans='Y';
	int x,y,w;
	while(ans=='y' || ans=='Y')
	{
		e++;
		cout<<"Enter the node from which the edge starts : ";
		cin>>x;
		cout<<"Enter the node where the edge ends : ";
		cin>>y;
		cout<<"Enter the weight of the edge : ";
		cin>>w;
		mat[x][y]=w;
		mat[y][x]=w;
		cout<<"\n Does the graph any more nodes ?(y/n) : ";
		cin>>ans;
	}		
}	
int graphP ::min_key(int key[],bool visit[])
{
	int x;
	int min=9999;
	int min_index=0;
	for(x=0;x<v;x++)
	{
		if(visit[x]==false && key[x]<min)
		{
			min=key[x];
			min_index=x;
		}
	}
	return min_index;
}
void graphP::display(int parent[],int minvertex)
{
	int i;
	if(print==0)
	{
		cout<<"\nMinimum Spanning Tree is as follows : \n\n";
		cout<<"Edge\t\tWeight\n";
		print++;
	}	
	if(mat[minvertex][parent[minvertex]]!=0)
		cout<<parent[minvertex]<<" -> "<<minvertex<<"\t\t"<<mat[minvertex][parent[minvertex]]<<"\n";
}					
void graphP::prims()
{
	bool visited[v];
	int key[v],parent[v],j,a;
	for(int i=0;i<v;i++)
	{
		key[i]=9999;
		visited[i]=false;
		parent[i]=i;
	}
	cout<<"\n\n Source Vertex for Minimum Spanning Tree : ";
	cin>>source;	
	key[source]=0;
	for(int i=0;i<v;i++)
	{
		int minvertex=min_key(key,visited);
		visited[minvertex]=true;
		for(int j=0;j<v;j++)
		{
			if((mat[minvertex][j])!=0 && visited[j]==false && mat[minvertex][j]<key[j])
			{
				parent[j]=minvertex;
				key[j]=mat[minvertex][j];
			}
		}
		display(parent,minvertex);
	}
	
}				

class graphK
{
	int source, weight, desti;
	
	public:
		void accept();
		void display();
		void sort(graphK *[], int);
		int findparent(int, int*);
		graphK *kruskal(graphK *[], int);
};


void graphK :: accept()
{
	cout<<"Enter source value :";
	cin>>source;
	cout<<"Enter destination value :";
	cin>>desti;
	cout<<"Enter weight of the edge :";
	cin>>weight;
	cout<<"\n";
}
void graphK :: display()
{
	cout<<source<<"\t"<<desti<<"\t\t"<<weight<<"\n";
}

void graphK :: sort(graphK *edge[], int n)
{
	int i, j;
	graphK *temp = NULL;
	for(i = n-1; i>0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(edge[j]->weight > edge[j+1]->weight)
			{
				temp = edge[j];
				edge[j] = edge[j+1];
				edge[j+1] = temp;
			}
		}
	}
}

int graphK :: findparent(int v, int *parent)
{
	if(parent[v] = v);
	 	return v;
	return findparent(parent[v], parent);
}

graphK *graphK :: kruskal(graphK *edge[], int v)
{
	int i, count = 0, p = 0;
	int *parent = new int[v];
	for(i = 0; i < v; i++)
	{
		parent[i] = i;
	}
	cout<<"\nMinimum Spanning Tree is as follows :"<<endl;
	cout<<"\nSource\tDestination\tWeight\n";
	while(count != (v-1))
	{
		int source = findparent(edge[p]->source, parent);
		int desti = findparent(edge[p]->desti, parent);
		if(source != desti)
		{
			cout<<"\n"<<edge[p]->source<<"\t"<<edge[p]->desti<<"\t"<<edge[p]->weight;
			parent[source] = desti;
			count++;
		}
		p++;
	}
}

int main()
{
	graphP g;
	graphK f;
	int v, i, e, data;
	string flag;
	int ch;
	graphK *edge[50];
	graphK *temp;
	do
	{
		cout<<"\n1.Prim's Algorith \n2.Kruskal's Algorithm \n3.Exit \n>>> ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.create_matrix();
				g.prims();
				break;
			case 2:				
				do
				{
					cout<<"\n1.Graph creation\n2.Display sorted graph\n3.Display Minimum Spanning Tree\n4.Exit\n\nEnter the option from above :"<<"\n";
					cin>>data;
		
					switch(data)
					{
						case 1:
							cout<<"Enter total no. of vertices :";
							cin>>v;
							cout<<"Entr total no. of edges :";
							cin>>e;
							cout<<"\n";
							for(i = 0; i < e; i++)
							{
								edge[i] = new graphK;
								edge[i]->accept();
							}
							break;
						case 2: 
							temp->sort(edge, e);
							cout<<endl;
							cout<<"Graph aftr sorting edges :"<<endl;
							cout<<"\nSource\tDestination\tWeight\n";
							for(i = 0; i < e; i++)
							{
								edge[i]->display();
							}
							break;
						case 3:
							edge[i]->kruskal(edge,v);
							break;	
						case 4:
							cout<<endl;
							break;	
						default:
							cout<<"Invalid Input !!!";
					}cout<<"\nDo you want to continue ?(y/n)";
					cin>>flag;
				}while(ch!==3);
				break;
		}
	}while(ch!=3);
	
	return 0;
}