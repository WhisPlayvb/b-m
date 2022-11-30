#include<iostream>
#include<string>

using namespace std;

class student
{
    public:
        string name;
        int rollNo;
        long int mob;
        string email;
    
    public:
        void getinfo();
        void display();
        void update(student mem[],int size,int u);
        void insert(student mem[],int size, int max_size,int pos);
        void Delete(student mem[],int size,int e);

};

void student::getinfo()
{
    cout<<"Enter Student name:";
    cin>>name;
    cout<<"Enter your RollNo";
    cin>>rollNo;
    cout<<"Enter your mobile NO:";
    cin>>mob;
    cout<<"Enter your Email;";
    cin>>email;
    
}

 
void student::display()
{
    cout<<"\n--------student information--------"<<endl;
    cout<<"Student name:"<<name<<endl;
    cout<<"Student RollNo:"<<rollNo<<endl;
    cout<<"Student mobile:"<<mob<<endl;
    cout<<"Student Email:"<<email<<endl;


}

void student::update(student mem[], int size,int u)
{
    if(u<1 || u>size)
    {
        cout<<"you entered invalid Student numbers"<<endl;
    }
    else{
        cout<<"\ncurrent student:"<<u<<endl;
        cout<<"\n current student name"<<mem[u-1].name<<endl;
        cout<<"\n new student name";
        cin>>mem[u-1].name;

        cout<<"\n current student rollno:"<<mem[u-1].rollNo<<endl;
        cout<<"\n new current rollno:";
        cin>>mem[u-1].rollNo;

        cout<<"\n current student mob"<<mem[u-1].mob<<endl;
        cout<<"\n new current student mobile no";
        cin>>mem[u-1].mob;

        cout<<"\n current student email"<<mem[u-1].email<<endl;
        cout<<"\n new current student email";
        cin>>mem[u-1].mob;

        mem[u-1].display();
    }
}

void student::insert(student mem[],int size,int max_size, int pos)
{
    if(pos>size || pos <=0 || size>=max_size)
    {
        cout<<"insert operation can not be done"<<endl;
    }
    else{
        for(int i=pos; i<=size; i++)
        {
            mem[i].name=mem[i-1].name;
            mem[i].rollNo=mem[i-1].rollNo;
            mem[i].mob=mem[i-1].mob;
            mem[i].email=mem[i-1].email;
        }

        cout<<"Enter the data to insert at stduent number"<<pos<<endl;
        mem[pos-1].getinfo();
        cout<<"data inserted"<<endl;
    }
}

void student::Delete(student mem[] , int size, int e)
{ 
 if(e<1 || e>size)
  {
	cout<<"You entered invalid customer number"<<endl;	
  }
	
 else
 {
   for(int i=e-1; i<size ;i++)	
   {
 	 mem[i].name=mem[i+1].name;
 	 mem[i].rollNo=mem[i+1].rollNo;
 	 mem[i].mob=mem[i+1].mob;
 	 mem[i].email=mem[i+1].email;
   }
   
     mem[size-1].name="None";
 	 mem[size-1].rollNo=0;
 	 mem[size-1].mob=0;
 	 mem[size-1].email="None";
   cout<<"Data is deleted of customer number "<<e<<endl;	
 }
}

int main()
{
    int m,n,choice;


    cout<<"how many customer data want to store";
    cin>>m;
    student mem[m];
    cout<<"current student info:";
    cin>>n;
    
    for (int i=0; i<n; i++)
    {
        cout<<"current student number"<<i+1<<endl;
        mem[i].getinfo(); 
    }

    do
    {
        cout<<"---------List of oprations---------";
        cout<<"\n 1.Press 1 to diplay \n 2.Press 2 to update \n  3.Press 3 to Insert \n 4.Press 4 to Delete \n 5.Press to 0 to Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"\n Display Operation:";
            for (int i=0; i<n; i++)
            { 
                cout<<"Student number: "<<i+1;
                mem[i].display();
            }

            case 2:
            int u;
            cout<<"\n Update Operation:";
            cout<<"\n Enter student number to Update Data:";
            cin>>u;
            mem[u-1].update(mem,n,u);


            break;

            case 3:
            int pos;
            cout<<"\n Insert Operation:";
            cout<<"\n Enter student number at which you want to insert data:";
            cin>>pos;
            mem[pos-1].insert(mem,n,m,pos);
            n=n+1;

            break;

            case 4:

            int e;
            cout<<"\n Delete Operation:";
            cout<<"\n Enter student number to delete data: ";
            mem[e-1].Delete(mem,n,e);
            n=n-1;

            break;

            case 0:
            cout<<"\n program complete"<<endl;
            break;

            default:
            cout<<"\n You entered Invalid Choice";
        }
    } while (choice!=0);
    


}
