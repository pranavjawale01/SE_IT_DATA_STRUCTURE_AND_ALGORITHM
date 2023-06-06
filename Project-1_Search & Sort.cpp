#include<iostream>
#include<string.h>
using namespace std;

struct student
{
    int rollno;
    string name;
    float sgpa;
};

void accept_data(struct student s[],int n)
{
    cout<<"\nEnter the data of student  > > >";
    for(int i=0;i<n;++i)
    {
        cout<<"\nEnter Name : ";
        cin>>s[i].name;
        cout<<"\nEnter Roll No. : ";
        cin>>s[i].rollno;
        cout<<"\nEnter SGPA : ";
        cin>>s[i].sgpa;
    }
}

void display_data(struct student s[],int n)
{
    cout<<"\nStudent Data is > > >";
    for(int i=0;i<n;i++)
    {
        cout<<"\nName : "<<s[i].name<<"\tRoll No. : "<<s[i].rollno<<'\t'<<"\tSGPA : "<<s[i].sgpa;
    }
}

//Bubble Sort
void roll_sort(struct student s[],int n)
{   
    struct student temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(s[j].rollno>s[j+1].rollno)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    display_data(s,n);
}

//Insertion Sort
void name_sort(struct student s[] , int n)
{
    struct student temp;
    for(int i=1; i < n; i++)
    {
        temp = s[i];
        string temp1 = s[i].name; 
        int j = i-1;
        while(j >= 0)
        {
            if(s[j].name > temp1)
            {
                s[j+1] = s[j];
                j--;
            }
            else
            {
                break;
            } 
        }
        s[j+1] = temp;
    }
}

//Qucik Sort
void topper_data(struct student s[],int first,int n)
{   
    int pivot = first ,too_big = first + 1,too_small = n-1;
    struct student temp;
    if (too_small > too_big)
    {
        while (too_small > too_big) 
        {
            while (s[too_big].sgpa<=s[pivot].sgpa)
                ++too_big;
            while (s[too_small].sgpa>s[pivot].sgpa)
                --too_small;
            if (too_big<too_small)
            {
                temp = s[too_big];
                s[too_big] = s[too_small];
                s[too_small] = temp;
            }
        }        
        if (too_small < too_big)
        {
            temp = s[too_small];
            s[too_small] = s[pivot];
            s[pivot] = temp;
        }
        topper_data(s,0,too_small);
        topper_data(s,too_small+1,n);
    }
}

//Linear Search
void search_data_sgpa(struct student s[],int n)
{
    cout<<"\nEnter SGPA to get Stdent DATA > > > ";
    float mysgpa;
    cin>>mysgpa;
    for(int i=0;i<n;i++)
    {
        if(mysgpa==s[i].sgpa)
        {
            cout<<"\nSearch Result is > > >";
            cout<<"\nSGPA : "<<s[i].sgpa<<"\tRoll No. : "<<s[i].rollno<<"\tName : "<<s[i].name<<'\n';
        }
    }
}

//Binary Search
void search_data_name(struct student s[] , int n)
{
    int low = 0 , high = n, mid;
    string x;
    cout<<"\nEnter the Name to get Student DATA > > > ";
    cin>>x;
    while(low <= high)
    {        
        mid = (low + high)/2;
        if(s[mid].name == x)
        {       
            cout<<"\nSearch Result is > > >";
            cout<<"\nName : "<<s[mid].name<<"\tRoll No. : "<<s[mid].rollno<<"\tSGPA : "<<s[mid].sgpa<<'\n';                     
            break;
        }
        else if(s[mid].name < x)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
}

int main()
{
    int n;
    cout<<"\nEnter the Number's Of Student Data You Want to Create > > >  ";
    cin>>n; 
    student s[n];
    accept_data(s,n);
    display_data(s,n);
    
    int ch;
    do
    {
        cout<<"\n1.Roll No. Sorting \n2.Arrange List of student Alphabetically \n3.Topper List \n4.Search Data by SGPA \n5.Search Data by Name \n6.Exit \nEnter the Choiise >>>  ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:
                roll_sort(s,n); 
                break;

            case 2:
                name_sort(s,n);
		        display_data(s,n);
                break;

            case 3:
                topper_data(s,0,n);
                cout<<"\nTopper List > > > ";
                for(int i=n-1;i>=0;--i)
                {
                    cout<<"\nSGPA : "<<s[i].sgpa<<"\tRoll No. : "<<s[i].rollno<<"\tName : "<<s[i].name<<'\n';
                }
                break;
                
            case 4:
                search_data_sgpa(s,n);
                break;

            case 5:
                name_sort(s,n);
                search_data_name(s,n);
                break;
        }
    }while(ch!=6);
    return 0;
}