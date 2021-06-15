#include <iostream>
#include <string.h>
//#include <stdlib>
#include <unistd.h>
#include <fstream>
#include "basic.h"
using namespace std;
int main()
{
	booking ba[10];
	passenger p2[10];
	char card[20];
	char cvv[3];
	char expiry[6];
	int confirmation=0;
	int flag=0;
	passenger p1,p5; 
	int ticket_no;
	booking b1,b2,b3,b5;
	char date[10];
	char name[40];
	int pos;
	int food;
	fstream fp;
	int flight_no;
	int flight_num;
	int option;
	fstream file,file1,file2,file3,file4,file5,file8,file9,file7,file10,fp1;
	plane a;
	int entry_choice=0;
	int passenger_choice=0;
	int choice1=0;
	int choice2=0;
	int choice3=0;
	char password[20];
	while(entry_choice!=-1)
	{
		system("CLS");
		cout<<"\t\t------------------------------------------------------------";
		cout<<"\n\t\t\t\tFLIGHT BOOKING SYSTEM";
		cout<<"\n\t\t------------------------------------------------------------";
		cout<<"\n\tWHO ARE YOU?\n\t1.ADMIN \n\t2.PASSENGER \n\t3.EXIT  :  \t";
		cin>>entry_choice;
		switch(entry_choice)
		{
			case 1:
					system("CLS");
					cout<<"\n\tENTER THE PASSWORD TO VERIFY CREDENTIALS: ";
					cin>>password;
					if(strcmp(password,"pass")==0)
					{
						choice1=0;
						while(choice1!=-1)
						{
							cout<<"\n\tENTER THE OPERATION YOU WOULD LIKE TO PERFORM\n\t1.ADD FLIGHTS\n\t2.DISPLAY FLIGHTS\n\t3.UPDATE FLIGHTS\n\t4.SEARCH FLIGHTS\n\t5.PASSENGER LIST OF PARTICULAR FLIGHTS\n\t6.DELETE FLIGHTS\n\t7.CANCELLED PASSENGERS LIST\n\t8.EXIT: \t";
							cin>>choice1;
							switch(choice1)
							{
								case 1:
										
										cout<<"\n\tENTER FLIGHT NUMBER: ";
										cin>>flight_num;
										a.insert(flight_num,a.root);
										system("CLS");
										break;
								case 2:	
										a.Inorder(a.root);
										getchar();
										getchar();
										system("CLS");
										break;
								case 3:
										cout<<"\tENTER THE FLIGHT NUMBER TO BE UPDATED: ";
										cin>>flight_num;
										a.update(flight_num);
										getchar();
										getchar();
										system("CLS");
										break;
								case 4: 
										
										cout<<"ENTER THE FLIGHT NUMBER TO BE SEARCHED: ";
										cin>>flight_num;
										a.printfound(flight_num);
										getchar();
										getchar();
										system("CLS");
										break;
								case 5:
								       	fp.open("bookings.txt",ios::in| ios::binary);
								       	file1.open("passengers.txt",ios::in|ios::binary);
								       	cout<<"\n\tENTER THE FLIGHT NUMBER: ";
								       	cin>>flight_no;
								       	cout<<"\n\tENTER DATE: ";
								       	cin>>date;
								       	flag=0;
								       	while(!fp.eof())
								       	{
											fp.read((char *)&b1, sizeof(b1));
											if(fp)
											{
										       	if(b1.flight_no==flight_no && strcmp(b1.date,date)==0&& b1.pass_cancel==0)
												{
										       		while(!file1.eof())
										       		{
										       			
										       			file1.read((char *)&p1, sizeof(p1));
										       			if(file1)
														{
											       			if(strcmp(p1.dispemail(),b1.passenger_email)==0 &&strcmp(p1.disp(),b1.passenger_name)==0 )
											       			{
											       				
											       				p1.printdetails();
																   break;	
															}
														}
											       				
													}
										       		flag=1;
										       	
												}
											}
									   	}
									   	file1.close();
									   	if(flag==0)
									   	{
									   		cout<<"\n\tTHERE ARE NO BOOKINGS YET!";
									   	}
									   	fp.close();
									   	getchar();
										getchar();
									   	system("CLS");
									   	break;
								case 6: 
										int flight_num;
										cout<<"ENTER THE FLIGHT NUMBER TO BE DELETED: ";
										cin>>flight_num;
										a.printfound(flight_num);
										a.deletevalue(a.root,flight_num);
										system("CLS");
										break;
								case 7:
										fp.open("bookings.txt",ios::in| ios::binary);
								       	file1.open("passengers.txt",ios::in|ios::binary);
								       	cout<<"\n\tENTER THE FLIGHT NUMBER: ";
								       	cin>>flight_no;
								       	cout<<"\n\tENTER DATE: ";
								       	cin>>date;
								       	flag=0;
								       	while(!fp.eof())
								       	{
								       		
											fp.read((char *)&b1, sizeof(b1));
											if(fp)
											{
										       	if(b1.flight_no==flight_no && strcmp(b1.date,date)==0 && b1.pass_cancel==1)
												{
													
										       		while(!file1.eof())
										       		{
										       			
										       			file1.read((char *)&p1, sizeof(p1));
										       			if(file1)
														{
											       			if(strcmp(p1.disp(),b1.passenger_name)==0)
											       			{
											       				
											       				p1.printdetails();
																   break;	
															}
														}
											       				
													}
										       		flag=1;
										       	
												}
											}
									   	}
									   	file1.close();
									   	if(flag==0)
									   	{
									   		cout<<"\n\t NO BOOKINGS HAS BEEN CANCELLED YET!";
									   	}
									   	fp.close();
									   	getchar();
										getchar();
									   	system("CLS");
									   	break;
								case 8:
										choice1=-1;
										break;
				   
							}
					    }  
					}
					else
					{
						cout<<"\n\tINVALID CREDENTIALS!";
					}
					break;
			case 2:
					choice2=0;
					while(choice2!=-1)
					{
						passenger p;
						
						int flag=0;
							       
						system("CLS");
						cout<<"\n\tCHOOSE FROM THE MENU BELOW:\n\t1.LOGIN \n\t2.SIGNUP\n\t3.BACK :\t";
						cin>>choice2;
						switch(choice2)
						{
							case 1:
									char email[50];
							       	char password[50];
							       	cout<<"\n\t\t------------------------------------------------------------";
									cout<<"\n\t\t\t\tENTER THE LOGIN DETAILS";
									cout<<"\n\t\t------------------------------------------------------------";
							       	cout<<"\n\tEMAIL: ";
							       	cin>>email;
							       	cout<<"\n\tPASSWORD: ";
							       	cin>>password;
							       	file2.open("passenger.txt",ios::in| ios::binary);
							       	flag=0;
							       	while(!file2.eof())
							       	{
								       	file2.read((char *)&p, sizeof(p));
//								       	cout<<"\t"<<p.disp();
								       	if(p.credentials(email,password)==1)
								       	{
								       		flag=1;
								       		break;
										}
								   	}
								   	file2.close();
								   	if(flag==1)
								   	{
									   	char from[20];
									   	int fromid;
									   	int toid;
									   	char to[20];
									   	int flight_no;
									   	char classes[20];
									   	
									   	passenger_choice=0;
									   	while(passenger_choice!=-1)
									   	{
									   		system("CLS");
										   	cout<<"\n\t\t------------------------------------------------------------";
											cout<<"\n\t\t\t\tWELCOME TO AIRLINE BOOKING SYSTEM";
											cout<<"\n\t\t------------------------------------------------------------";
										   	cout<<"\n\t\t\t\tWHAT WOULD U LIKE TO PERFORM?\n\t1.NEW BOOKING\n\t2.CHECK FLIGHT DETAILS\n\t3.CANCEL FLIGHTS\n\t4.BOOKING HISTORY\n\t5.LOGOUT :";
										   	cin>>passenger_choice;
										   	
										   	switch(passenger_choice)
										   	{
										   		case 1:
										   		        char date[10];
														system("CLS");
												   		cout<<"\n\tDUE TO THE ONGOING PANDEMIC, ONLY LIMITED FLIGHTS TO LIMITED CITIES ARE AVAILABLE.\n\tCHOOSE YOUR CONVENIENT LOCATION FROM THE AVAILABLE CITIES: ";
												   	   	cout<<"\n\tFROM:\n\t 1.Chennai\n\t2.Kolkata\n\t3.Bangalore\n\t4.Mumbai\n\t5.Delhi\n\t6.Hyderabad :\t";
												   	  	cin>>fromid;
												   	   	if(fromid==1)
												   	   	{
												   	   		strcpy(from,"Chennai");
													   	}
													   	else if(fromid==2)
													   	{
													   		strcpy(from,"Kolkata");
													   	}
													    else if(fromid==3)
													   	{
													   		strcpy(from,"Bangalore");
													   	}
													    else if(fromid==4)
													   	{
													   		strcpy(from,"Mumbai");
													   	}
													    else if(fromid==5)
													   	{
													   		strcpy(from,"Delhi");
													   	}
													    else if(fromid==6)
													   	{
													   		strcpy(from,"Hyderbad");
													   	}
													   	else
													   	{
													   		cout<<"\n\tINVALID ENTRY!";
													   	}
													   	cout<<"\n\tTo: ";
													   	cout<<"\n\t 1.Chennai\n\t2.Kolkata\n\t3.Bangalore\n\t4.Mumbai\n\t5.Delhi\n\t6.Hyderabad : \t ";
													   	cin>>toid;
													   	if(fromid!=toid)
													   	{
														   	if(toid==1)
													   	   	{
													   	   		strcpy(to,"Chennai");
														   	}
														   	else if(toid==2)
														   	{
														   		strcpy(to,"Kolkata");
														   	}
														    else if(toid==3)
														   	{
														   		strcpy(to,"Bangalore");
														   	}
														    else if(toid==4)
														   	{
														   		strcpy(to,"Mumbai");
														   	}
														    else if(toid==5)
														   	{
														   		strcpy(to,"Delhi");
														   	}
														    else if(toid==6)
														   	{
														   		strcpy(to,"Hyderbad");
														   	}
														   	else
														   	{
															   	cout<<"\n\tInvalid entry!";
															   	break;
														   	}
														   	cout<<"\nFLIGHTS AVAILABLE: ";
														   	a.findlocation(from,to,a.root);
														   	cout<<"\n\n\t 1.PROCEED \t2.EXIT: ";
														   	cin>>option;
														   	if(option==1)
															{
																cout<<"\n\tENTER THE FLIGHT NUMBER FROM THE ABOVE OPTIONS: ";
															   	cin>>flight_no;
															   	cout<<"\n\tENTER THE BOOKING DATE IN (DD/MM/YYYY) FORMAT: ";
															   	cin>>date;
															   	cout<<"\n\tENTER THE NO OF TICKETS YOU ARE GONNA BOOK: ";
															   	cin>>ticket_no;
															   	file8.open("passengers.txt",ios::app| ios::binary);
															   	file3.open("bookings.txt", ios::app|ios::binary);
															   	food=0;
															   	for(int i=0;i<ticket_no;i++)
																{
																	confirmation=0;
															   	
																	p2[i].getdetails(email);
																	
																   	ba[i].flight_no=flight_no;
																   	strcpy(ba[i].date,date);
																   	strcpy(ba[i].passenger_email,email);
																   	strcpy(ba[i].p_class,p2[i].pp_class());
	//															   	cout<<p2[i].disp();
																   	strcpy(ba[i].passenger_name,p2[i].disp());
																    ba[i].pass_cancel=0;
	//															   	cout<<ba[i].date;
																	//cout<<a.businessclass(flight_no);
																	//cout<<a.economicclass(flight_no);
																	if(strcmpi(p2[i].pp_class(),"Business")==0)
																	{
																		
																		ba[i].foodamount=0;
																   		food+=ba[i].fooddetails();
																   		food+=a.businessclass(flight_no);
																	}
																   	else if(strcmpi(p2[i].pp_class(),"Economic")==0)
																   	{
																   		ba[i].foodamount=0;
																   		food+=ba[i].fooddetails();
																   		food+=a.economicclass(flight_no);
																	}
																		
																}
																	
																cout<<"\n\tTOTAL: "<<food;
																food=0;
																cout<<"\n\tCHOOSE ONE AMONG THE FOLLOWING.\t1.CONFIRM\t2.CANCEL :\t";
															   	cin>>confirmation;
															   	if(confirmation==1)
															   	{
															   		
															   		system("CLS");
															   		cout<<"\n\tCHOOSE YOUR MODE OF PAYMENT:\t1.CREDIT CARD\t2.DEBIT CARD: \t";
															   		cin>>confirmation;
															   		cout<<"\n\tCARD NUMBER: ";
															   		cin>>card;
															   		cout<<"\n\tEXPIRY DATE (MM/YY): ";
															   		cin>>expiry;
															   		cout<<"\n\tCVV: ";
															   		cin>>cvv;
															   		cout<<"\n\t1.CONFIRM\t2.CANCEL :\t";
															   		cin>>confirmation;
															   		if(confirmation==1)
															   		{
															   			cout<<"\n\tPlease wait till the transaction is over...";
															   			sleep(4);
															   			for(int i=0;i<ticket_no;i++)
															   			{
															   				file8.write((char *)&p2[i], sizeof(p2[i]));
															   				file3.write((char *)&ba[i],sizeof(ba[i]));
																			   if(strcmpi(p2[i].pp_class(),"Business")==0)
																		   		{
																	   			a.decbus(flight_no);
																	
																		  		 }
																				else
																				{
																					a.decec(flight_no);
																				}	
																		}
															   			
															   	        cout<<"\n\n\tYOUR BOOKING IS CONFIRMED! WEAR A MASK AND MAINTAIN SOCIAL DISTANCING HAVE A SAFE JOURNEY!";
																	}
																	else
																	{
																		cout<<"\n\tYOUR BOOKING HAS BEEN CANCELLED!!!";
																	}
																}
															  	else
																	{
																		cout<<"\n\tYOUR BOOKING HAS BEEN CANCELLED";
																	}
															 	 file8.close();
															 	 file3.close();
															 	 break;
															  }
															  else
															  {
															  	break;
															  }
														   	   
													   }
													   else
													   {
													   		cout<<"\n\tYOUR DESTINATION AND BOARDING LOCATION ARE SAME. PLEASE CHANGE THE VALUE!";
													   		break;
													   }
											
												
										
									
													   break;
												case 2:int flight;
												       cout<<"\n\tENTER THE FLIGHT NUMBER: ";
													   cin>>flight;
													   a.printfounds(flight);
													   break;
												case 3: 					
												       file4.open("bookings.txt",ios::in| ios::binary| ios::out);
												       cout<<"\n\tENTER THE FLIGHT NO: ";
												       cin>>flight_no;
												       cout<<"\n\tENTER DATE: ";
												       cin>>date;
												       cout<<"\n\tENTER THE NAME OF THE PASSENGER:";
												       cin>>name;
												       flag=0;
												       while(!file4.eof())
												       
												       {
												       		pos=file4.tellg();
													       	file4.read((char *)&b2, sizeof(b2));
															if(file4)
															{
														       	if(b2.flight_no==flight_no && strcmp(b2.date,date)==0 &&strcmp(b2.passenger_name,name)==0)
														       	{
														       	    file4.seekp(pos);
														       	    
														       		   b2.flight_no=flight_no;
																	   b2.pass_cancel=1;
																	   strcpy(b1.passenger_name,name);
																	   strcpy(b1.date,date);
														       		   file4.write((char *)&b2, sizeof(b2));
														       		   flag=1;
																	   cout<<"YOUR BOOKING HAS BEEN CANCELLED!!!";
																	   if(strcmp(b1.p_class,"Business")==0)
																	   {
																	   		a.incbus(flight_no);
																	   }
																	   else
																	   {
																	   		a.incec(flight_no);	
																	   }
																}
															}
													   }
													   if(flag==0)
													   {
													   	cout<<"\n\tTHERE IS NO CORRESPONDING BOOKINGS YET!!!";
													   }
													   file4.close();
													   break;	
														
												case 4:
													  file9.open("bookings.txt",ios::in| ios::binary);
												       	flag=0;
													    
													       		while(!file9.eof())
													       		{
													       			file9.read((char *)&b3, sizeof(b3));
													       			if(file9)
																	{
														
																	
														       			if(strcmp(email,b3.passenger_email)==0 && b3.pass_cancel==0)
														       			{
														       				b3.printinfo();
														       				a.printfounds(b3.flight_no);
											
																		}
																	}
													       				
																}
													       		flag=1;
													   	file9.close();
													   	if(flag==0)
													   	{
													   		cout<<"\n\tTHERE ARE NO BOOKINGS YET!";
													   	}
													   	
														   break; 	
														
												
												
												
												case 5:
														passenger_choice=-1;
														break;
														  	
											}
										   	getchar();
										   	getchar();
									   	
									   }
								   }
								   
								   else
								   {
								   	cout<<"\n\tINVALID! TRY AGAIN!";
								   	getchar();
								   	getchar();
								   }
								   break;
							case 2: p.getdetail();
									file.open("passenger.txt",ios::app| ios::binary);
									file.write((char *)&p, sizeof(p));
									file.close();
									break;
									
							case 3:
								   choice2=-1;
								   break;
									
						}
					}
					break;
			case 3: entry_choice=-1;
					break;
		}
		
	}
}
