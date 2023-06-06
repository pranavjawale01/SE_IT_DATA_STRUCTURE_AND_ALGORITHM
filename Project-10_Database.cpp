#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Student
{
    public:
        int age,rollNo;
        char name[20],division,grade[1],address[50];
        float percentage;
        void getData();
        void nameModify();
        void rollNoModify();
        int getRollNo();
};

void Student :: getData()
{
    cout<<"\nEnter Name >> ";
    cin>>name;
    cout<<"\nEnter Roll No. > > ";
    cin>>rollNo;
    cout<<"\nEnter Age >> ";
    cin>>age;
    cout<<"\nEnter Address > > ";
    cin>>address;
    cout<<"\nEnter Division > > ";
    cin>>division;
    cout<<"\nEnter Grade > > ";
    cin>>grade;
    cout<<"\nEnter Percentage > > ";
    cin>>percentage;
}

void Student ::rollNoModify()
{
    cout<<"\nEnter the Roll No. to Modify > > ";
	cin>>rollNo;
}
void Student ::nameModify()
{
    cout<<"\nEnter the Name to Modify > > ";
	cin>>name;
}


int main()
{
    Student s;
    int ch = 0,ch1,ch2,on,add3,start3,n3,y1,add4,start4,n4,locate,roll;
    char name1[20];
    fstream a, b , in;
    do
    {
        cout<<"\n1.Enter Data \n2.Display Data \n3.Enter Data in Append Mode \n4.Modify \n5.Delete \n6.Exit \n>>> ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                b.open("Database.txt",ios::out);
                s.getData();
                b.write((char*) & s , sizeof(s));                      	
                b.close();          
                break;

            case 2:
                b.open("Database.txt",ios :: in);
                b.read((char*) & s,(sizeof(s)));
                while(b)
                {
                    b.read((char*) & s,(sizeof(s)));
                    cout<<"\nStudent Data";
                    cout<<"\nName >> "<<s.name<<"\tAge >> "<<s.age<<"\ts.Roll No >> "<<s.rollNo<<"\tDivision >> "<<s.division<<"\tAddress >> "<<s.address<<"\tGrade >> "<<s.grade<<"\tPercentage >> "<<s.percentage<<"\n";
                    //cout<<s.address<<s.age<<s.division<<s.grade<<s.name<<s.percentage<<s.rollNo;//rough display func
                }
                b.close();
                break;
            
            case 3:
                x:s.getData();
                b.open("Database.txt", ios :: app);
                b.write((char*) & s , sizeof(s));
                cout<<"\nDo you want to enter more records?\n1.Yes\n2.No\n>>";
			    cin>>ch2;
			    if(ch2==1)
				    goto x;
			    else
				    b.close();
                break;

            case 4:
                do
                {
                    cout<<"\n1.Modify-Roll No. \n2.Modify-Name \n3.Exit \n>>>";
                    cin>>ch1;
                    switch(ch1)
                    {
                        case 1:
                            cout<<"\nEnter the Roll No. Number of Student to Modify Data > > ";
                            cin>>on;
                            b.open("Database.txt",ios::in|ios::out);
                            b.read((char*) & s,(sizeof(s)));
                            while(b)
                            {
                                if(on==s.rollNo)
                                {
                                    cout<<"\nNumber Found";
                                    add3=b.tellg();
                                    b.seekg(0,ios::beg);
                                    start3=b.tellg();
                                    n3=(add3-start3)/(sizeof(s));
                                    b.seekp((n3-1)*(sizeof(s)),ios::beg);
                                    s.rollNoModify();
                                    b.write((char*)& s,(sizeof(s)));
                                    b.close();
                                    break;
                                }
                                a.read((char*)& s,(sizeof(s)));
                            }
                            break;
                        case 2:
                            cout<<"\nEnter the Name of Student to Modify Data > > ";
                            cin>>name1;
                            b.open("Database.txt",ios::in|ios::out);
                            b.read((char*)& s,(sizeof(s)));
                            while(b)
                            {
                                y1=(strcmp(name1,s.name));
                                if(y1==0)
                                {
                                    cout<<"\nName found";
                                    add4=b.tellg();
                                    b.seekg(0,ios::beg);
                                    start4=b.tellg();
                                    n4=(add4-start4)/(sizeof(s));
                                    b.seekp((n4-1)*sizeof(s),ios::beg);
                                    s.nameModify();
                                    b.write((char*) & s,(sizeof(s)));
                                    b.close();break;
                                }
                                b.read((char*)& s,(sizeof(s)));
                            }
                            break;
                    }
                }while(ch1!=3);
                break;

            case 5:
                cout<<"Please Enter the Roll No. of Student Whose Info You Want to Delete > > ";
                cin>>roll;
                b.open("Database.txt",ios::in);
                a.open("temp.txt",ios::out);
                b.read((char *)& s,sizeof(s));
                while(!b.eof())
                {
                    if (s.getRollNo()!=roll)
                        a.write((char *)& s,sizeof(s));
                        b.read((char *)& s,sizeof(s));
                }
                cout<<"\nThe Record with the Roll No. "<<roll<<" has been Deleted ";
                b.close();
                a.close();
                remove("Database.txt");
                rename("temp.txt","Database.txt");
                break;
        }
    }while(ch!=6);
    
    return 0;
}