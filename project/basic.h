#include <iostream>
#include <string>
//#include <stdlib>
#include <fstream>
using namespace std;
class plane
{
	public:
	class node
	{
		public:
		int flight_no;
	    int price;
	    char from[50];
	    char to[50];
	    char start_time[40];
		char end_time[40];
		int economic,priceeco;
		int business,pricebus;
		char company[50];
		int height;
		
		node *left;
		node *right;
		
		void getdetails()
		{
		cout<<"\n\tECONOMIC PRICE: ";
		cin>>priceeco;
		cout<<"\n\tBUSINESS PRICE: ";
		cin>>pricebus;
		cout<<"\n\tFROM: ";
		cin>>from;
		cout<<"\n\tTO: ";
		cin>>to;
		cout<<"\n\tDEPARTURE TIME: ";
		cin>>start_time;
		cout<<"\n\tARRIVAL TIME: ";
		cin>>end_time;
		cout<<"\n\tNO OF SEATS IN ECONOMIC CLASS: ";
		cin>>economic;
		cout<<"\n\tNO OF SEATS IN BUSINESS CLASS: ";
		cin>>business;
		cout<<"\n\tCOMPANY: ";
		cin>>company;
		}
		void display()
		{
			cout<<"\n\tFLIGHT NUMBER: "<<flight_no;
			cout<<"\n\tECONOMIC PRICE: "<<priceeco;
			cout<<"\n\tBUSINESS PRICE: "<<pricebus;
			cout<<"\n\tFROM: "<<from;
			cout<<"\n\tTO: "<<to;
			cout<<"\n\tDEPARTURE TIME: "<<start_time;
			cout<<"\n\tARRIVAL TIME: "<<end_time;
			cout<<"\n\tNUMBER OF SEATS IN ECONOMIC CLASS: "<<economic;	
			cout<<"\n\tNUMBER OF SEATS IN BUSINESS CLASS: "<<business;
			cout<<"\n\t________________________________________________________";	
		}
		
		void displays()
		{
			cout<<"\n\tFLIGHT NUMBER: "<<flight_no;
			cout<<"\n\tECONOMIC PRICE: "<<priceeco;
			cout<<"\n\tBUSINESS PRICE: "<<pricebus;
			cout<<"\n\tFROM: "<<from;
			cout<<"\n\tTO: "<<to;
			cout<<"\n\tDEPARTURE TIME: "<<start_time;
			cout<<"\n\tARRIVAL TIME: "<<end_time;		
		}		
    };
	node *root;
	
	plane()
    {
      root = NULL;
    }
    
	int height (node *&t)
	{
		if(t==NULL)
		{
			return -1;
		}
		return t->height;
	}
	
    void printfound(int val)
   	{
    	node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			temp->display();
   			cout<<endl;
   		}
   		else
   			cout<<"\n\tINVALID FLIGHT NUMBER!";
   	}
   	
   	void printfounds(int val)
   	{
    	node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			temp->displays();
   			cout<<endl;
   		}
   		else
   			cout<<"\n\tINVALID FLIGHT NUMBER!";
   	}

	void findlocation(char fromgiven[20],char togiven[20], node *t)
	{
		if(t==NULL)
		{
			return;
		}
		if(strcmp(t->from,fromgiven)==0 && strcmp(t->to, togiven)==0)
		{
		  t->display();	
		}
		findlocation(fromgiven,togiven,t->left);
		findlocation(fromgiven,togiven,t->right);
	}

	node *find(int x,node *&t)
	{
	  	node *temp=t;
	  	if(temp==NULL)
	  	{
	   		return NULL;
	  	}
	  	if(temp->flight_no==x)
	  	{
	  		
	    	return temp;
	  	}
	  	else if(x>temp->flight_no)
	  	{
	     	find(x,temp->right);
	  	}
	  	else
	  	{
	    	find(x,temp->left);
	  	}
	}
	
	void insert( int x, node * & t )
	{		
	 	if( t == NULL )
	  	{
	    	t = new node();
	    	t->flight_no=x;
	    	t->getdetails();
	    	t->height=0;
	  	}
	  	else if( x < t->flight_no )
	  	{
	   	 	insert( x, t->left );
	    	if( height( t->left ) - height( t->right ) == 2 )
	    		if( x < t->left->flight_no )
	      			rotateWithLeftChild( t );
	    		else
	      			doubleWithLeftChild( t );
	  	}
	  	else if( t->flight_no < x )
	  	{ 
	    	insert( x, t->right );
	    	if( height( t->right ) - height( t->left ) == 2 )
	    		if( t->right->flight_no < x )
	      			rotateWithRightChild( t );
	    		else
	      			doubleWithRightChild( t );
	  	}
	  	else
	  		;
	  	t->height = max( height( t->left ),height( t->right ) ) + 1;
	}
	
	void rotateWithLeftChild( node * & k2 )
	{
	  	node *k1 = k2->left;
	  	k2->left = k1->right;
	  	k1->right = k2;
	  	k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
	  	k1->height = max( height( k1->left ), k2->height ) + 1;
	  	k2 = k1;
	}	

	void doubleWithLeftChild( node * & k3 )
	{
	  	rotateWithRightChild( k3->left );
	  	rotateWithLeftChild( k3 );
	}

	void doubleWithRightChild( node * & k1 )
	{
	  	rotateWithLeftChild( k1->right );
	  	rotateWithRightChild( k1 );
	}
	
	void rotateWithRightChild( node * & k1 )
	{
	 	node *k2 = k1->right;
	  	k1->right = k2->left;
	  	k2->left = k1;
	  	k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
	  	k2->height = max( height( k2->right ), k1->height ) + 1;
	  	k1 = k2;
	}
	
	node *deletevalue(node *&t,int val)
	{
	  	if (t == NULL)
	  		return root;
	  	if ( val<t->flight_no)
	  		deletevalue(t->left,val);
	  	else if(t->flight_no<val )
	  		deletevalue(t->right,val);
	  	else
	  	{
	   		if( t->left == NULL || t->right == NULL )
	   		{
	     		node *temp = t->left ?t->left :t->right;
	     		if (temp == NULL)
	     		{
	       			temp = t;
	       			t = NULL;
	     		}
	     		else
	     			*t = *temp;
	     		delete(temp);
	    	}
	    	else
	    	{
	      		node* temp = Min(t->right);
	      		t->flight_no=temp->flight_no;
	      		deletevalue(t->right,temp->flight_no);
	    	}
	   }
	   if(t!=NULL)
	   {
	      	t->height = 1 + max(height(t->left),
	      	height(t->right));
	      	int balance = getBalance(t);
	      	if (balance > 1 && getBalance(t->left) >= 0)
	      	{
	       		rotateWithLeftChild(t);
	       		return t;
	      	}
	      	if (balance > 1 && getBalance(t->left) < 0)
	      	{
	        	rotateWithRightChild(t->left);
	        	rotateWithLeftChild(t);
	        	return t;
		  	}
	      	if (balance < -1 && getBalance(t->right) <= 0)
	      	{
	       		rotateWithRightChild(t);
	       		return t;
	      	}
	      	if (balance < -1 && getBalance(t->right) > 0)
	      	{
	       		rotateWithLeftChild(t->right);
	       		rotateWithRightChild(t);
	       		return t;
	      	}
	   }
		return t;
	}
		
	int getBalance(node *&t)
	{
		if (t == NULL)
			return 0;
		return height(t->left) - height(t->right);
	}

	void Inorder( node *t ) const
	{
	  	if( t != NULL )
	  	{
	    	Inorder( t->left );
	    	t->display();
	    	Inorder( t->right );
	  	}		
	}

		
	node *Min( node *t ) const
	{
	  	node *temp=t;
	  	if( temp != NULL )
	  	{
	    	while( temp->left != NULL )
	      		temp = temp->left;
	  	}
	  	return temp;
	}
	
    void update(int val)
	{
	    int choice = 0;
	    node *temp=find(val,root);
	    while(choice != -1)
		{
		    int a;
		   	char f[20];
		    cout<<"\tWHICH YOU WANT TO UPDATE";
		    cout<<"\n\t1.ECONOMIC PRICE OR BUSINESS PRICE";
		    cout<<"\n\t2.FROM";
		    cout<<"\n\t3.TO";
		    cout<<"\n\t4.DEPARTURE TIME";
		    cout<<"\n\t5.ARRIVAL TIME";
		    cout<<"\n\t6.NO OF SEATS IN ECONOMIC CLASS";
		    cout<<"\n\t7.NO OF SEATS IN BUSINESS CLASS";
		    cout<<"\n\t8.EXIT :";
		    cin>>a;
		    if(a==1)
		    {
		    	char a[20];
		    	cout<<"FOR WHICH CLASS YOU WANT TO UPDATE: \t";
		    	cin>>a;
		    	if(strcmpi(a,"Business")==0)
		    	{
		    		int p;
		        	cout<<"\tENTER THE NEW PRICE: ";
		        	cin>>p;
		        	temp->pricebus=p;
				}
		        else if(strcmpi(a,"Economic")==0)
		        {
		        	int p;
		        	cout<<"\tENTER THE NEW PRICE: ";
		        	cin>>p;
		        	temp->priceeco=p;
				}
				else
				{
					cout<<"\n\tINVALID";
				}
		    }
			if(a==2)
			    {
			        
			        cout<<"\tENTER THE NEW FROM LOCATION: ";
			        cin>>f;
			        strcpy(temp->from,f);
			    }
			if(a==3)
			    {
			        char t[20];
			        cout<<"\tENTER THE NEW TO LOCATION: ";
			        cin>>t;
			        strcpy(temp->to,t);
			    }
			if(a==4)
			    {
			        char d[20];
			        cout<<"\tENTER THE NEW DEPARTURE TIME: ";
			        cin>>d;
			        strcpy(temp->start_time,d);
			    }
			if(a==5)
			    {
			        char a[20];
			        cout<<"\tENTER THE NEW FROM ARRIVAL TIME: ";
			        cin>>a;
			        strcpy(temp->end_time,a);
			    }
			if(a==6)
			    {
			        int e;
			        cout<<"\tENTER THE NEW ECONOMIC CLASS SEATS: ";
			        cin>>e;
			        temp->economic=e;
			    }
			if(a==7)
			    {
			        int b;
			        cout<<"\tENTER THE NEW BUSINESS CLASS SEATS: ";
			        cin>>b;
			        temp->business=b;
			    }
			if(a==8)
				{
				choice=-1;
				break;
				}
		}
	}
	int businessclass(int val){
		node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			return temp->pricebus;
   		}
   		else
   			return 0;;
	}
	int economicclass(int val){
		node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			return temp->priceeco;
   		}
   		else
   			return 0;;
	}
	void decbus(int val){
		node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			temp->business--;
   			cout<<endl;
   		}
   		else
   			cout<<"\n\tINVALID FLIGHT NUMBER!";
	}
	
	void incbus(int val){
		node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			temp->business++;
   			cout<<endl;
   		}
   		else
   			cout<<"\n\tINVALID FLIGHT NUMBER!";
	}
	void incec(int val){
		node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			temp->economic++;
   			cout<<endl;
   		}
   		else
   			cout<<"\n\tINVALID FLIGHT NUMBER!";
	}
	
	void decec(int val){
		node *temp=find(val,root);
   		if(temp!=NULL)
  	 	{
   			temp->economic--;
   			cout<<endl;
   		}
   		else
   			cout<<"\n\tINVALID FLIGHT NUMBER!";
	}
};

class passenger:public plane
{
	char name[20];
	char email[50];
	int age;
	char gender[10];
	char medical[100];
	char password[20];
	char p_class[30];
	public:
		void getdetail()
		{
			cout<<"\t\t------------------------------------------------------------";
			cout<<"\n\t\t\t\tSIGN UP";
			cout<<"\n\t\t------------------------------------------------------------";
			cout<<"\n\tFILL THE FOLLOWING FORM:\n\tNAME: ";
			fflush(stdin);
			gets(name);
			cout<<"\n\tEMAIL: ";
			cin>>email;
			cout<<"\n\tAGE: ";
			cin>>age;
			cout<<"\n\tGENDER: ";
			cin>>gender;
			cout<<"\n\tIF YOU HAVE ANY MEDICAL CONDITIONS LIKE (FEVER, HEART ATTACK ETC) PLEASE ENTER THE DETAILS OF IT: ";
			fflush(stdin);
			gets(medical);
			
			cout<<"\n\tPASSWORD: ";
			cin>>password;
		}
		
		void getdetails(char* ems)
		{
			cout<<"\n\tFILL THE DETAILS:\n\tNAME: ";
			cin>>name;
			strcpy(email,ems);
			cout<<"\n\tAGE: ";
			cin>>age;
			cout<<"\n\tGENDER: ";
			cin>>gender;
			cout<<"\n\tIF YOU HAVE ANY MEDICAL CONDITIONS LIKE (FEVER, HEART ATTACK ETC) PLEASE ENTER THE DETAILS OF IT: ";
			fflush(stdin);
			gets(medical);
			cout<<"\n\tUNDER WHICH CLASS YOU WANNA TRAVEL: ";
			fflush(stdin);
			gets(p_class);
		}
		
		char *dispemail()
		{
			return email;
		}
		
		int credentials(char emailgiven[50], char passwordgiven[50])
		{
			if(strcmp(email,emailgiven)==0 && strcmp(password,passwordgiven)==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		char *disp()
		{
			return name;
		}
		
		char *pp_class()
		{
			
			return p_class;
		}
		
		void printdetails()
		{
			cout<<"\n";
			cout<<"\n\tNAME: "<<name;
			cout<<"\n\tEMAIL: "<<email;
			cout<<"\n\tAGE: "<<age;
			cout<<"\n\tGENDER: "<<gender;
			cout<<"\n\tMEDICAL CONDITION: ";
			puts(medical);
			cout<<"\tCLASS :";
			puts(p_class);
			cout<<"___________________________________________________________________";
		}
};


class booking
{
	public:
	int flight_no;
	char passenger_name[50];
	char passenger_email[50];
	char date[10];
	int pass_cancel;
	int food[10];
	int foodamount;
	char p_class[20];
	
	int fooddetails(){
		foodamount=0;
			int option=0;
			int i=0;
			cout<<"\n\tFOOD AVAILABLE: ";
			cout<<"\n\t 1.Sandwich :- Rs.250";
			cout<<"\n\t 2.Coke :- Rs.100";
			cout<<"\n\t 3.Water bottle :- Rs.90";
			cout<<"\n\t 4.Pringles :- Rs.250";
			cout<<"\n\t 5.Exit";
			cout<<"\n\tEnter the number of food items you would like to buy: ";
			cin>>option;
			if(option>4)
			{
				cout<<"\n\tInvalid choice!";
			}
			else
			{
			while(i<option)
			{
				cout<<"\n\tENTER FOOD "<<i+1<<" : ";
				cin>>food[i];
				if(food[i]==1)
			    {
			        foodamount+=250;
			    }
				if(food[i]==2)
				    {
				     foodamount+=100;   
				       
				    }
				if(food[i]==3)
				    {
				      foodamount+=90;  
				    }
				if(food[i]==4)
				    {
				      foodamount+=250;   
				    }
	
				
			i++;
			}
		}
		return foodamount;
		}
		
		void printinfo(){
			
			cout<<"\n\n INFORMATION";
			cout<<"\n\tNAME: "<<passenger_name;
			cout<<"\n\tEMAIL: "<<passenger_email;
			cout<<"\n\tDATE :";
			puts(date);
			cout<<"\tCLASS :";
			puts(p_class);
		}
	
};
