/*
Name: Hrushikesh Ambadas Lokhande
batch: D3
Roll No.: 208
Title: Design and implement a program to read, display, insert, update and delete operations 
	   on data objects for customer information supply chain management system using array.
*/

#include<iostream>
#include<string>
 
using namespace std;

class Textile
{
	public:
		string name;
		int mobile;
		string type;
		int quantity;
		string colour;
		int size;
		
	public:
		void get_info();
		void display();
		void update(Textile customer[],int size,int u);
		void insert(Textile customer[],int size,int max_size,int pos);
		void Delete(Textile customer[],int size,int e);
		
		
}; 

void Textile::get_info()
{
  cout<<"Enter costumer name:";
  cin>>name;
  cout<<"Enter costumer mobile number:";
  cin>>mobile;
  cout<<">>Enter costumer order inforamtion:";
  
  cout<<"\nEnter Garment type:";
  cin>>type;
  cout<<"Enter colour:";
  cin>>colour;
  cout<<"Enter size:";
  cin>>size;
  cout<<"Enter Garment quantity:";
  cin>>quantity;
}

void Textile::display()
{
  cout<<"\nCoustumer information:"<<endl;
  cout<<"costumer name:"<<name<<endl;
  cout<<"costumer mobile number:"<<mobile<<endl;
  cout<<">>costumer order inforamtion:"<<endl;
  cout<<"Garment type:"<<type<<endl;
  cout<<"colour:"<<colour<<endl;
  cout<<"size:"<<size<<endl;
  cout<<"Garment quantity:"<<quantity<<endl;
 
}

void Textile::update(Textile customer[] , int size, int u)
{
	if(u<1 || u>size)
	{
		cout<<"You entered invalid customer number"<<endl;	
	}
	else
	{
	 cout<<"\ncustomer number:"<<	u<<endl;
	 cout<<"\ncurrent costumer name:"<<customer[u-1].name<<endl;
	 cout<<"New costumer name:";
	 cin>>customer[u-1].name;
	 
	 cout<<"\ncurrent costumer mobile number::"<<customer[u-1].mobile<<endl;
	 cout<<"New costumer mobile number: ";
	 cin>>customer[u-1].mobile;
	cout<<"\n>>Enter costumer order inforamtion:"<<endl;
	 
	 cout<<"\ncurrent Garment type::"<<customer[u-1].type<<endl;
	 cout<<"New Garment type: ";
	 cin>>customer[u-1].type;
	 
	 cout<<"\ncurrent  colour::"<<customer[u-1].colour<<endl;
	 cout<<"New  colour: ";
	 cin>>customer[u-1].colour;
	 
	 cout<<"\ncurrent size:"<<customer[u-1].size<<endl;
	 cout<<"New  size: ";
	 cin>>customer[u-1].size;
	 
	 cout<<"\ncurrent Garment quantity:"<<customer[u-1].quantity<<endl;
	 cout<<"New Garment quantity: ";
	 cin>>customer[u-1].quantity;
	 
	 cout<<"\nUpdatated Data:"<<endl;
	 cout<<"\ncustomer number :"<<u;
	 customer[u-1].display();
	 
	}
	
}

void Textile::Delete(Textile customer[] , int size, int e)
{ 
 if(e<1 || e>size)
  {
	cout<<"You entered invalid customer number"<<endl;	
  }
	
 else
 {
   for(int i=e-1; i<size ;i++)	
   {
 	 customer[i].name=customer[i+1].name;
 	 customer[i].mobile=customer[i+1].mobile;
 	 customer[i].type=customer[i+1].type;
 	 customer[i].colour=customer[i+1].colour;
 	 customer[i].size=customer[i+1].size;
 	 customer[i].quantity=customer[i+1].quantity;
   }
   
     customer[size-1].name="None";
 	 customer[size-1].mobile=0;
 	 customer[size-1].type="None";
 	 customer[size-1].colour="None";
 	 customer[size-1].size=0;
 	 customer[size-1].quantity=0;
   
   cout<<"Data is deleted of customer number "<<e<<endl;	
 }
}


void Textile::insert(Textile customer[],int size,int max_size, int pos)
{
	if(pos>size || pos<=0 || size>=max_size) 
	{
		cout<<"insert operation does not possible....."<<endl;
	}
	else
	{
		for(int i=pos;i<=size;i++)
		{
		   customer[i].name=customer[i-1].name;
 	       customer[i].mobile=customer[i-1].mobile;
 	       customer[i].type=customer[i-1].type;
 	       customer[i].colour=customer[i-1].colour;
 	       customer[i].size=customer[i-1].size;
 	       customer[i].quantity=customer[i-1].quantity;	
		}	
		
		cout<<"Enter the data to insert at customer number "<<pos<<endl;
        cout<<"\ncustomer number :"<<pos<<endl;
        customer[pos-1].get_info();	
        
		cout<<"Data inserted successfuly...."<<endl;
	}
	
}


int main()
{ 
 int m,n,choice;
 cout<<"\nEnter maximum number of customer to store their Data:";
 cin>>m;
 Textile customer[m];
 cout<<"\nEnter number of customer to store their data now:";
  cin>>n;
  
  for (int i=0;i<n;i++)
  { cout<<"\ncustomer number :"<<i+1<<endl;
    customer[i].get_info();	
  }
  
  do
 {
   cout<<"\nList of operations:" ;
   cout<<"\n 1.Press 1 to display\n 2..Press 2 to update\n 3..Press 3 to Delete\n 4..Press 4 to Insert\n 5..Press 0 to Exit"<<endl;
   cout<<"Enter your choice;"<<endl;
   cin>>choice;

   switch(choice)	
   {
   	case 1:
   	  cout<<"\nDISPLAY OPERATION:";
   	  for (int i=0;i<n;i++)
   	  {
       cout<<"\ncustomer number:"<<i+1;
       customer[i].display();	
      }
	break;
	
	case 2:
	int u;
	cout<<"\nUPDATE OPERATION:";
	cout<<"\nEnter customer number to update Data :";
	cin>>u;	
	customer[u-1].update(customer,n,u);
	
	break;
	
	case 3:
	int e;
	cout<<"\nDELETE OPERATION:";
	cout<<"\nEnter customer number to Delete Data:";	
	cin>>e;
	customer[e-1].Delete(customer,n,e);
	n=n-1;
	break;
	
	case 4:
	int pos;
	cout<<"\nINSERT OPERATION:";
	cout<<"\nEnter customer number at which you want to Insert Data:";	
	cin>>pos;
	customer[pos-1].insert(customer,n,m,pos);
	n=n+1;
	break;
	
	case 0:
	cout<<"\nYour work is completed..."<<endl;
	break;
	
	default:
	cout<<"\nYou entered invalid choice....."<<endl;
	break;
   }
 
 }while(choice!=0);
	
	
	return 0;
	
}

/*
output-


Enter maximum number of customer to store their Data:10

Enter number of customer to store their data now:3

customer number :1
Enter costumer name:xyz
Enter costumer mobile number:45789645
>>Enter costumer order inforamtion:
Enter Garment type:cotton
Enter colour:blue
Enter size:16
Enter Garment quantity:5

customer number :2
Enter costumer name:abc
Enter costumer mobile number:54879632
>>Enter costumer order inforamtion:
Enter Garment type:cotton
Enter colour:orange
Enter size:35
Enter Garment quantity:3

customer number :3
Enter costumer name:pqr
Enter costumer mobile number:75689425
>>Enter costumer order inforamtion:
Enter Garment type:cotton
Enter colour:red
Enter size:75
Enter Garment quantity:6

List of operations:
 1.Press 1 to display
 2..Press 2 to update
 3..Press 3 to Delete
 4..Press 4 to Insert
 5..Press 0 to Exit
Enter your choice;
1

DISPLAY OPERATION:
customer number:1
Coustumer information:
costumer name:xyz
costumer mobile number:45789645
>>costumer order inforamtion:
Garment type:cotton
colour:blue
size:16
Garment quantity:5

customer number:2
Coustumer information:
costumer name:abc
costumer mobile number:54879632
>>costumer order inforamtion:
Garment type:cotton
colour:orange
size:35
Garment quantity:3

customer number:3
Coustumer information:
costumer name:pqr
costumer mobile number:75689425
>>costumer order inforamtion:
Garment type:cotton
colour:red
size:75
Garment quantity:6

List of operations:
 1.Press 1 to display
 2..Press 2 to update
 3..Press 3 to Delete
 4..Press 4 to Insert
 5..Press 0 to Exit
Enter your choice;
2

UPDATE OPERATION:
Enter customer number to update Data :3

customer number:3

current costumer name:pqr
New costumer name:lmn

current costumer mobile number::75689425
New costumer mobile number: 75846

>>Enter costumer order inforamtion:

current Garment type::cotton
New Garment type: cotton

current  colour::red
New  colour: pink

current size:75
New  size: 46

current Garment quantity:6
New Garment quantity: 10

Updatated Data:

customer number :3
Coustumer information:
costumer name:lmn
costumer mobile number:75846
>>costumer order inforamtion:
Garment type:cotton
colour:pink
size:46
Garment quantity:10

List of operations:
 1.Press 1 to display
 2..Press 2 to update
 3..Press 3 to Delete
 4..Press 4 to Insert
 5..Press 0 to Exit
Enter your choice;
3

DELETE OPERATION:
Enter customer number to Delete Data:3
Data is deleted of customer number 3

List of operations:
 1.Press 1 to display
 2..Press 2 to update
 3..Press 3 to Delete
 4..Press 4 to Insert
 5..Press 0 to Exit
Enter your choice;
1

DISPLAY OPERATION:
customer number:1
Coustumer information:
costumer name:xyz
costumer mobile number:45789645
>>costumer order inforamtion:
Garment type:cotton
colour:blue
size:16
Garment quantity:5

customer number:2
Coustumer information:
costumer name:abc
costumer mobile number:54879632
>>costumer order inforamtion:
Garment type:cotton
colour:orange
size:35
Garment quantity:3

List of operations:
 1.Press 1 to display
 2..Press 2 to update
 3..Press 3 to Delete
 4..Press 4 to Insert
 5..Press 0 to Exit
Enter your choice;
4

INSERT OPERATION:
Enter customer number at which you want to Insert Data:2
Enter the data to insert at customer number 2

customer number :2
Enter costumer name:seh
Enter costumer mobile number:4786
>>Enter costumer order inforamtion:
Enter Garment type:cotton
Enter colour:green
Enter size:32
Enter Garment quantity:39
Data inserted successfuly....

List of operations:
 1.Press 1 to display
 2..Press 2 to update
 3..Press 3 to Delete
 4..Press 4 to Insert
 5..Press 0 to Exit
Enter your choice;
1

DISPLAY OPERATION:
customer number:1
Coustumer information:
costumer name:xyz
costumer mobile number:45789645
>>costumer order inforamtion:
Garment type:cotton
colour:blue
size:16
Garment quantity:5

customer number:2
Coustumer information:
costumer name:seh
costumer mobile number:4786
>>costumer order inforamtion:
Garment type:cotton
colour:green
size:32
Garment quantity:39

customer number:3
Coustumer information:
costumer name:abc
costumer mobile number:54879632
>>costumer order inforamtion:
Garment type:cotton
colour:orange
size:35
Garment quantity:3

List of operations:
 1.Press 1 to display
 2..Press 2 to update
 3..Press 3 to Delete
 4..Press 4 to Insert
 5..Press 0 to Exit
Enter your choice;
0

Your work is completed...

You entered invalid choice.....

--------------------------------
Process exited after 322.3 seconds with return value 0
Press any key to continue . . .








*/

















































