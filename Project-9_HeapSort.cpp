#include<iostream>
using namespace std;

class HeapSort
{
    private:
        int n;
        int*arr;
    public:
        HeapSort()
        {
            cout<<"Enter the Number of elements to insert in Tree > > > ";
			cin>>n;
			arr =new int[n];
        }
        void accept();
        void maxHeapify(int,int);
        void heapSort();       
        void display();
};

void HeapSort :: accept()
{
    int i=0;
    while(i<n)
    {
        cout<<"\nEnter Element "<<i<<" > ";
        cin>>arr[i];
        i++;
    }
}

void HeapSort :: maxHeapify(int i,int n)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        maxHeapify(largest,n);
    }
}

void HeapSort :: heapSort()
{
    for(int j=(n/2)-1 ; j>=0 ; j--)
    {
        maxHeapify(j , n-1 );
    }
    for(int j=n-1 ; j>0 ; j--)
    {
        swap(arr[0], arr [j]);
        maxHeapify(0,j-1);
    }
}

void HeapSort :: display()
{
    cout<<"Sorted Element (Heap Sort) > > > \n";
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }  
}

int main()
{
    HeapSort x;
    int ch;
    do
    {
        cout<<"\n1.Insert \n2.Heap Sort \n3.Display \n4.Exit";
        switch(ch)
        {
            case 1:
                x.accept();
                break;
            case 2:
                x.heapSort();
                break;
            case 3:
                x.display();
                break;
        }
    }while(ch!=4);   
    return 0;
}