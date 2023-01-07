#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;
//_____________________________________________________________________ SEMUA DECLARATON
int menudetails; //use to insert admin or user
int password; //adminpassword
int list,wrongpass; //adminpassword utk pilih


HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

int adminoption;  // ADMINMENU function
int numberbrands;  //addbrands function
int yesadd; //addbrands function
int removed; //removebrand function

int manytype[100][5]; //(guna utk tahu berapa type) UNTUK COUT TYPE!!!!!!!
int type; // user input type

int counter=0,kira=0,choose,choosetype; //editbrands function
char anything;
int userchoice,prebrands,userbrand,useramount,usertype,userdecide; //untuk user
double totuserprice, accumulatetot;
int kaunter=0;
int passyangnakdicompare; //ini utk password suka hati kita

int oldpasssuka; //untuk tukar password
int newpasssuka=0;  //untuk tukar password

	
	
	
//______________________________________________________________________



struct details
{
	char brands[100];
	char nametype[100]; //untuk declare type punya name
	double price;
	int total;
	int amount;

};

struct order
{
	char brands[100];
	double price;
	int amount;
};

order preobarang[100];
details gempak[100][5];

//_______________________________________________________________________ SEMUA FUNTIONS PROTOTYPE
void mainscreen(); //clearsreen

void adminpassword();
void adminmenu();
void addbrands(details [][5]);  // DALAM ADMIN MENU
void editbrands(details [][5]); //DALAM ADMIN MENU
void changepassword();
void summaryofstock(details [][5]);
void summarymainpage();
void termsandcondition();

//colour change----------------------------------------------------------
void green();
//-----------------------------------------------------------------------


void usermenu(details [][5]);
void preorder(order [],ofstream&);
void buyproducts(details [][5],ofstream&);
void browseallproducts(details [][5]);
//_______________________________________________________________________




int main()
{
	ifstream passcode("PASSWORD.txt");
    if(newpasssuka  == 0)
	{
	passcode >> passyangnakdicompare;
	}
	else
	{
		passyangnakdicompare = newpasssuka ;
	}


   
   bool conditionmomo = false;
   while(conditionmomo == false)
   {
      mainscreen();
	  cout<<"\t _______________________________________________________________";
	  cout<<"\n\t _______________________________________________________________"<<endl<<endl;
	  cout<<"\t[1.]ADMIN"<<endl;
      cout<<"\t[2.]USER"<<endl;
	  cout<<"\t[3.]EXIT"<<endl;
      cout<<"\n\tINPUT : ";
      cin>>menudetails;

	   
	   if (menudetails==1) //INI UNTUK ADMIN!!!
       {
		 adminpassword();
	
       }
       else if (menudetails==2)  //INI UNTUK USER!!
	   {
		   usermenu(gempak);
	   } 
	   else if ( menudetails ==3)
	   {
		   green();
		   return 0;
	   }
	   else 
	   {
		   conditionmomo = false;
	   }
   } 
	return 0;
}
	

void mainscreen()
{
    system("cls"); 
	SetConsoleTextAttribute(color, 14);
  cout<<"\n\t _______________________________________________________________";
  cout<<"\n\t |                |                                            |";
  cout<<"\n\t |   __________   |                  WELCOME  TO               |";
  cout<<"\n\t |  |          |  |                                            |";
  cout<<"\n\t |  |  ________|  |                    GEMPAK                  |";
  cout<<"\n\t |  |  |    ___   |                  SHOE STORE                |";
  cout<<"\n\t |  |  |   |_ _|  |                                            |";
  cout<<"\n\t |  |  |    | |   |                                            |";
  cout<<"\n\t |  |  |____| |   |                                            |";
  cout<<"\n\t |  |         |   |                                            |";
  cout<<"\n\t |  |_________|   |____________________________________________|";
  cout<<"\n\t |  -----------   |  CREDITS: THE THREE BROTHERS (SAM)         |";
  cout<<"\n\t |________________|____________________________________________|";
  cout<<endl<<endl<<endl;
  SetConsoleTextAttribute(color, 11);
  
}

void adminpassword()
{
	bool status = false;
	while(status == false)
	{


	    mainscreen();
		cout<<"\t[1]Login"<<endl;
	    cout<<"\t[2]Back"<<endl;
	    cout<<"\t-->";
	    cin>>list;
		mainscreen();	

		if (list == 1 )
		{
		   bool stats = false;
		   while ( stats == false)
		   {
		   mainscreen();
		   cout<<"\n\tINSET PASSWORD :";
		   cout<<"\n\tPRESS [0] TO MAIN PAGE :";
		   cout<<"\n\t-->";
		   cin>>password;
		   

		         if (password == passyangnakdicompare)
				 {
					 adminmenu();
				 }
				 else if(password == 0)
				 {
					 break;
				 }
				 else 
				 {
					 stats = false;
				 }

		   }

		}
		else if ( list == 2)
		{
			break;
		}

		else 
		{
			status = false;
		}
	}
}


void adminmenu()
{
	bool condition = false;
	while ( condition == false)
	{
	mainscreen();
	cout<<"\t[1.]ADD BRANDS"<<endl;
	cout<<"\t[2.]CHANGE PASSWORD"<<endl;
	cout<<"\t[3.]EDIT BRANDS"<<endl;
	cout<<"\t[4.]SUMMARY OF STOCK"<<endl;
	cout<<"\t[5.]TERMS AND CONDITIONS OF THIS STORE"<<endl;
	cout<<"\t[6.]MAIN MENU";
	cout<<"\n\t-->";
	cin>>adminoption;

		if (adminoption == 1)
		{
			addbrands(gempak);
		}
		else if (adminoption == 2)
		{
			changepassword();
		}
		else if (adminoption == 3)
		{
			editbrands(gempak);
		}
		else if (adminoption == 4)
		{
			summaryofstock(gempak);
		}
		else if (adminoption == 5)
		{
			termsandcondition();
		}
		else if (adminoption == 6)
		{
			break;
		}
		else 
		{
			condition = false;
		}
	}
}


void addbrands(details list[100][5])
{	
	mainscreen();
	bool lol=false;
	cout<<"\tPLEASE INSERT HOW MANY BRANDS TO ADD :";
	cin>>numberbrands;
	
	 
		for (int x = 0; x<numberbrands;x++)
		{
		 
		cout<<"\n\tENTER NAME OF BRANDS "<<kira+1<<":";
		cin>>ws;
		cin.getline(list[kira][0].brands,100); 
		cout<<"\n\tINSERT HOW MANY TYPES:";
		cin>>manytype[kira][type];
		
			for(int y=0; y<manytype[kira][type];y++)
			{
				cout<<"\n\tENTER TYPE "<<y+1<<" NAME :";
				cin>>ws;
				cin.getline(list[kira][y].nametype,100); 
				cout<<"\n\tENTER AMOUNT :";
				cin>>list[kira][y].amount;
				cout<<"\n\tENTER PRICE :";
				cin>>list[kira][y].price;
			}
		kira++;
		}


		while (lol == false)
	{
		mainscreen();
		cout<<"\tAdd more [1]Yes [2]No  :";
		cout<<"\n\t-->";
		cin>>yesadd;
		
		if (yesadd== 1)
		{
			addbrands(gempak);
		}
		else if (yesadd == 2)
		{
			break;
		}
		else 
		{
			lol = false;
		}
	}
	
}


void editbrands(details list[][5])
{
	if ( kira == 0 )
	{
		mainscreen();
		char anotom;
		cout<<"\tTHERE IS NO STOCK RIGHT NOW"<<endl;
		cout<<"\tENTER ANYTHING TO EXIT"<<endl;
		cout<<"\t-->";
		cin>>anotom;
	    

	}
	else
		{
	
	mainscreen();
	for(int x=0;x<kira;x++)
	{
		cout<<"\t"<<x+1<<"."<<list[x][0].brands<<" BRAND"<<endl;
		for(int y=0;y<manytype[x][type];y++)
		{
		cout<<"\t"<<"TYPE "<<y+1<<" :"<<list[x][y].nametype<<endl;
		cout<<"\t"<<"AMOUNT :"<<list[x][y].amount<<endl;
		cout<<"\t"<<"PRICE :"<<list[x][y].price<<endl;
		cout<<endl;
		}
	}
	cout<<"\n\tCHOOSE BRANDS TO EDIT :";
	cout<<"\n\t-->";
	cin>>choose;
	mainscreen();

	cout<<"\t"<<"A."<<list[choose-1][0].brands<<" BRAND"<<endl;
	for(int y=0; y<manytype[choose-1][type];y++)
		{
		cout<<"\t"<<"TYPE "<<y+1<<" :"<<list[choose-1][y].nametype<<endl;
		cout<<"\t"<<"AMOUNT :"<<list[choose-1][y].amount<<endl;
		cout<<"\t"<<"PRICE :"<<list[choose-1][y].price<<endl;
		cout<<endl;
		}
	
	cout << "\n\tCHOOSE TYPE" << endl;
	cout << "\t-->";
	cin >> choosetype;
	mainscreen();
	cout<<"\t"<<choose<<"."<<list[choose-1][0].brands<<" BRAND"<<endl;
	cout<<"\t"<<"TYPE "<<choosetype<<" :"<<list[choose-1][choosetype-1].nametype<<endl;
	cout<<"\t"<<"AMOUNT :"<<list[choose-1][choosetype-1].amount<<endl;
	cout<<"\t"<<"PRICE :"<<list[choose-1][choosetype-1].price<<endl;
	cout<<endl;
		
	cout << "\tRE-ENTER TYPE NAME :"<<endl;
	cout << "\t-->";
	cin >> ws;
	cin.getline(list[choose-1][choosetype-1].nametype,100);
	cout << "\n\tRE-ENTER AOMUNT :"<<endl;
	cout << "\t-->";
	cin  >> list[choose-1][choosetype-1].amount;
	cout << "\n\tRE-ENTER PRICE :"<<endl;
	cout << "\t-->";
	cin  >> list[choose-1][choosetype-1].price;
    

	
	
		}
}

void summarymainpage()
{
	cout<<"\n\t_________________________________________________________________";
  cout<<"\n\t|                    SUMMARY OF STOCK                           |";
  cout<<"\n\t|_______________________________________________________________|";
  cout<<"\n\t >>>>>>>>>>>>>>>>>>>>>>>>            <<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

void summaryofstock(details list[][5])
{
	mainscreen();
	summarymainpage();
	
	if ( kira == 0 )
	{
		mainscreen();
		char anotom;
		cout<<"\tTHERE IS NO STOCK RIGHT NOW"<<endl;
		cout<<"\tENTER ANYTHING TO EXIT"<<endl;
		cout<<"\t-->";
		cin>>anotom;

	}
	else
	{
	
	//---------------------------------------------------------------------------------------------------
	cout<<"\n\tHIGHEST PRODUCT AMOUNT OF A BRANDS :"<<endl;
	int highestsummary = 0;
	int sumhigh = 0;
	int haa=0;

	for(int x=0;x<kira;x++)
	{
		sumhigh = 0;
		for(int y=0;y<5;y++)
		{
			sumhigh = sumhigh + list[x][y].amount;
		}
		if(sumhigh>highestsummary)
			{
				highestsummary = sumhigh;
				haa = x;
			}
	}

	cout<<"\t-->"<<list[haa][0].brands<<" WITH THE AMOUNT OF "<<highestsummary<<endl;
	//-----------------------------------------------------------------------------------------------------
	cout<<"\n\tLOWEST PRODUCT AMOUNT OF A BRANDS :"<<endl;
	double lowestsummary = 100000;
	int sumlowest = 0;
	int lowamount=0;

	for(int x=0;x<kira;x++)
	{
		sumlowest = 0;
		for(int y=0;y<5;y++)
		{
			sumlowest = sumlowest + list[x][y].amount;
		}
		if(sumlowest<lowestsummary)
			{
				lowestsummary = sumlowest;
				lowamount = x;
			}
	}

	cout<<"\t-->"<<list[lowamount][0].brands<<" WITH THE AMOUNT OF "<<lowestsummary<<endl;
	//------------------------------------------------------------------------------------------------------
	cout<<"\n\tSORTING ACCORDING TO LOWEST AMOUNT OF PRODUCT TO HIGHEST :"<<endl;

	

	for(int x=0;x<kira;x++)
	{
		for( int y=0;y<5;y++)
		{
			list[x][0].total = 0;
		}
	}
	int onano[100];
	for(int x=0;x<kira;x++)
	{
		for( int y=0;y<5;y++)
		{
			list[x][0].total = list[x][0].total + list[x][y].amount;
			onano[x] = x;
		}
	}
	
	double temp;
	double tempona;
	
	for ( int iteration = 1; iteration < kira; iteration++)
	{
		for (int index = 0; index<kira - iteration;index++)
			if ( list[index][0].total > list[index+1][0].total)
			{
				temp = list[index][0].total;
				list[index][0].total = list[index+1][0].total;
				list[index+1][0].total = temp;

				tempona = onano[index];
				onano[index] = onano[index+1];
				onano[index+1] = tempona;
			}
	}

	for(int x=0;x<kira;x++)
	{
		cout<<"\n\t["<<x+1<<".]"<<list[x][0].total<<" FROM "<<list[onano[x]][0].brands<<" BRANDS";
	}

	
	

	//--------------------------------------------------------------SEARCHING !
	
	cout<<endl;
	int amountofitemtosearch;
	cout<<"\tINSERT AMOUNT OF THAT IS MORE THAN SEARCH :"<<endl;
	cout<<"\t-->";
	cin>>amountofitemtosearch;

	int sumtertinggi = 0;

	for(int x=0;x<kira;x++)
	{
		sumtertinggi = 0;
		for(int y=0;y<5;y++)
		{
			sumtertinggi = sumtertinggi + list[x][y].amount;
			
		}
		if(sumtertinggi>amountofitemtosearch)
			{
				cout<<"\n\t["<<x+1<<".]"<<list[x][0].brands;
			}
	}

	//------------------------------------------------------------------------average !
	cout<<endl;
	cout<<"\n\tAVERAGE OF ALL BRANDS :"<<endl;

	double averagebrands;
	double sumsum = 0;
	double kiraaverage ;
	for(int x=0;x<kira;x++)
	{
		averagebrands = 0;
		sumsum = 0;
		kiraaverage = 0;
		for(int y=0;y<5;y++)
		{
			sumsum = sumsum + list[x][y].amount;
			if ( list[x][y].amount !=0)
			{
				kiraaverage++;
			}

		}
		averagebrands = sumsum / kiraaverage;
		cout<<"\tAVERAGE OF "<<list[x][0].brands<<" BRANDS : "<<averagebrands<<endl;
		
	}

	//---------------------------------------------------------------------------------------

	char mokaodsf;
	cout<<"\n\tENTER ANYTHING TO RETURN TO MAIN";
	cout<<"\n\t-->";
	cin>>ws;
	cin>>mokaodsf;
    

	
	}
}	

void termsandcondition()
{
  char backtomain;
  cout<<"\n\t_________________________________________________________________";
  cout<<"\n\t|                 TERMS AND CONDITION OF STORE                  |";
  cout<<"\n\t|_______________________________________________________________|";
  cout<<"\n\t >>>>>>>>>>>>>>>>>>>>>>>>            <<<<<<<<<<<<<<<<<<<<<<<<<<<<";
  cout<<endl<<endl;

  cout<<"\tTHIS STORE IS ONLY CAPABLE OF STORING BRANDS WHICH IS NOT MORE THAN 100"<<endl;
  cout<<"\tEACH BRANDS IS GIVEN 5 TYPE OF ITEMS FOR THEM TO PLACE IN THIS STORE"<<endl;
  cout<<"\tEACH BRANDS HAS ITS OWN LOCKER FOR THEM TO KEEP"<<endl;
  cout<<"\tWORKERS ARE NOT ALLOWED TO MIX EACH BRANDS ON ONE LOCKER"<<endl;
  cout<<"\tPENALTY WILL BE GIVEN FOR WORKERS THAT DAMAGE OR LOST EACH GOODS"<<endl;
  cout<<"\tANY CRIMINAL ACT WILL BE REPORTED TO THE POLICE"<<endl;

  cout<<"\tPRESS ANYTHING TO BACK TO MAIN PAGE"<<endl;
  cout<<"\t-->";
  cin>>backtomain;
  
}

void usermenu(details list [][5])
{
	ofstream printrecipt("RECEIPT.txt");
	ofstream printpreorder("PREORDER.txt");

	bool condition = false;
	while (condition == false)
	{
	     mainscreen();
		 cout<<"\t[1.]BROWSE ALL PRODUCTS"<<endl;
		 cout<<"\t[2.]BUY PRODUCTS"<<endl;
		 cout<<"\t[3.]PRE-ORDER PRODUCTS"<<endl;
		 cout<<"\t[4.]MAIN PAGE"<<endl;
		 cout<<"\t-->";
		 cin>>userchoice;


		if (userchoice == 1)
		{
			browseallproducts(gempak);
		}

		else if (userchoice == 2)
		{
			buyproducts(gempak,printrecipt);	
		}
		else if (userchoice == 3)
		{
			preorder(preobarang,printpreorder);
		}

		else if (userchoice == 4)
		{
			condition = true;
		}
		else 
		{
			condition = false;
		}
	}
}

void buyproducts(details list[][5],ofstream& printrecipt)
{
	mainscreen();
	
	//------------------------------------------------------------------------------------------------------
	if ( kira == 0 )
	{
		char anotom;
		cout<<"\tTHERE IS NO STOCK RIGHT NOW"<<endl;
		cout<<"\tENTER ANYTHING TO EXIT"<<endl;
		cout<<"\t-->";
		cin>>anotom;
	}
	else 
	{

	for(int x=0;x<kira;x++)
	{
		cout<<"\t"<<x+1<<"."<<list[x][0].brands<<" BRAND"<<endl;
		for(int y=0;y<manytype[x][type];y++)
		{
		cout<<"\t"<<"TYPE "<<y+1<<" :"<<list[x][y].nametype<<endl;
		cout<<"\t"<<"AMOUNT :"<<list[x][y].amount<<endl;
		cout<<"\t"<<"PRICE :"<<list[x][y].price<<endl;
		cout<<endl;
		}
	}
	    cout<<endl;
		cout<<"\tINSERT BRANDS NUMBER :"<<endl;
		cout<<"\t-->";
		cin>>userbrand;

		cout<<"\n\tINSERT TYPE :"<<endl;
		cout<<"\t-->";
		cin>>usertype;

		bool condition = false;
		while (condition == false)
		{
			cout<<"\n\tINSERT AMOUNT :";
			cout<<"\n\t-->";
			cin>>useramount;
			if (list[userbrand-1][usertype-1].amount<useramount)
				{
				cout<<"\n\tAmount inputted is more than stock";
				cout<<"\n\tPlease retry";
				condition=false;
				}
			else 
			{
				condition = true;
			}
		}
		
		

		list[userbrand-1][usertype-1].amount -= useramount;

		totuserprice = useramount * list[userbrand-1][usertype-1].price;  

		accumulatetot += totuserprice;

		//---------------------------------------------------------------------------------------------------------
	       //ini untuk cout resit dia: 
			mainscreen();
			cout<<"\n\t_________________________________________________________________";
			cout<<"\n\t|                      YOUR ORDER PRODUCTS                      |";
			cout<<"\n\t|_______________________________________________________________|";
			cout<<"\n\t >>>>>>>>>>>>>>>>>>>>>>>>            <<<<<<<<<<<<<<<<<<<<<<<<<<<<";
			cout<<endl<<endl;

			cout<<"\t["<<counter+1<<".]"<<list[userbrand-1][0].brands<<endl;
			cout<<"\t["<<counter+1<<".]"<<list[userbrand-1][usertype-1].nametype<<endl;
			cout<<"\tAMOUNT :"<<useramount<<endl;
			cout<<"\tTOTAL PRICE:"<<totuserprice<<endl;
       //-------------------------------------------------------------------------------------------------------RECEIPT SECTION !!!!!!

			if (kaunter== 0)
			{
			printrecipt<<"\n\t_________________________________________________________________";
			printrecipt<<"\n\t|                      YOUR ORDER PRODUCTS                      |";
			printrecipt<<"\n\t|_______________________________________________________________|";
			printrecipt<<"\n\t >>>>>>>>>>>>>>>>>>>>>>>>            <<<<<<<<<<<<<<<<<<<<<<<<<<<<";
			printrecipt<<endl<<endl;

			printrecipt<<"\t["<<counter+1<<".]"<<list[userbrand-1][0].brands<<endl;
			printrecipt<<"\t["<<counter+1<<".]"<<list[userbrand-1][usertype-1].nametype<<endl;
			printrecipt<<"\tAMOUNT :"<<useramount<<endl;
			printrecipt<<"\tTOTAL PRICE:"<<totuserprice<<endl;
			}
			else 
			{
			
			printrecipt<<endl;
			printrecipt<<"\t["<<counter+1<<".]"<<list[userbrand-1][0].brands<<endl;
			printrecipt<<"\t["<<counter+1<<".]"<<list[userbrand-1][usertype-1].nametype<<endl;
			printrecipt<<"\tAMOUNT :"<<useramount<<endl;
			printrecipt<<"\tTOTAL PRICE :"<<totuserprice<<endl;
			printrecipt<<"\tACCUMULATED TOTAL PRICE :" << accumulatetot << endl;
			
			}

			counter++;
			kaunter++;
		cout<<endl;
		char kolaz;
		cout<<"\tORDER WAS INSERT IN THE RESIT"<<endl;
		cout<<"\tTO ORDER MORE GO TO BUY PRODUCTS INI USER MENU"<<endl;
		cout<<"\tPRESS ANYTHING TO USER MENU"<<endl;
		cout<<"\t-->";
		cin>>kolaz;
				
    }
	
}

void preorder(order preobarang[],ofstream& printpreorder)
{
	   
	    mainscreen();
        cout<<"\tPLEASE INSERT HOW MANY BRANDS TO PRE-ORDER :"<<endl;
		cout<<"\t-->";
		cin>>prebrands;
	 
		for (int x = 0; x<prebrands;x++)
		{
		cout<<"\n\tENTER NAME OF BRANDS "<<x+1<<":";
		cout<<"\n\t-->";
		cin>>ws;
		cin.getline(preobarang[x].brands,100); 
		cout<<"\n\tENTER AMOUNT :"<<endl;		
		cout<<"\t-->";
		cin>>preobarang[x].amount;
		}
		
		mainscreen();
		int backtomain;
		cout<<"\n\t_________________________________________________________________";
		cout<<"\n\t|                    YOUR PRE-ORDER PRODUCTS                    |";
		cout<<"\n\t|_______________________________________________________________|";
		cout<<"\n\t >>>>>>>>>>>>>>>>>>>>>>>>            <<<<<<<<<<<<<<<<<<<<<<<<<<<<";
		cout<<endl<<endl;

		for (int x = 0; x<prebrands;x++)
		{
			cout<<"\t["<<x+1<<".]"<<preobarang[x].brands<<" BRANDS"<<endl;
			cout<<"\tAMOUNT = "<<preobarang[x].amount<<endl;
			
		}
		//-----------------------------------------------------------------------------------------OUTPUT KE RESIT!!!!
		mainscreen();
		printpreorder<<"\n\t_________________________________________________________________";
		printpreorder<<"\n\t|                    YOUR PRE-ORDER PRODUCTS                    |";
		printpreorder<<"\n\t|_______________________________________________________________|";
		printpreorder<<"\n\t >>>>>>>>>>>>>>>>>>>>>>>>            <<<<<<<<<<<<<<<<<<<<<<<<<<<<";
		printpreorder<<endl<<endl;

		for (int x = 0; x<prebrands;x++)
		{
			printpreorder<<"\t["<<x+1<<".]"<<preobarang[x].brands<<" BRANDS"<<endl;
			printpreorder<<"\tAMOUNT = "<<preobarang[x].amount<<endl;
			
		}
		
		//-----------------------------------------------------------------------------------------------------------
		cout<<endl;
		cout<<"\tPRE-ORDER WAS PRINTED PLEASE TAKE THE RESIT"<<endl;
		cout<<"\tPRESS ANYTHING TO USER MENU"<<endl;
		cout<<"\t-->";
		cin>>backtomain;
		
}


void changepassword()
{
	
	mainscreen();
	bool nothingl = false;
	while ( nothingl == false)
	{

		cout<<"\tPLEASE INSERT THE PREVIOUS PASSWORD [0] TO MAIN:"<<endl;
		cout<<"\t-->";
		cin>>oldpasssuka;
		
		if( oldpasssuka == passyangnakdicompare)
		{
			cout<<"\tENTER NEW PASSWORD :"<<endl;
			cout<<"\t-->";
			cin>>newpasssuka;
			passyangnakdicompare = newpasssuka  ;
			cout<<"\n\tPASSWORD CHANGED COMPLETE :"<<endl;	
			break;
		}
		else if (oldpasssuka == 0)
		{
		  break;
		}
		else
		{
		  nothingl = false;
		}
	}

}

void green()
{
	system("cls");
	system("color 7C");
	cout<<"\n\n\n\t\t\t\PLEASE WAIT WHILE VALIDATING\n\n";
	char a=176, b=219;
	cout<<"\t\t\t";
	for(int i=0;i<70;i++)
	cout<<a;
	cout<<"\r";
	cout<<"\t\t\t";
	for(int i=0;i<=70;i++)
	{
		cout<<b;
		for(int j=0;j<1e7;j++);
	}
	system("cls");
	system("color 0B");

	system("cls");
	system("color 7C");
	cout<<"\n\n\n\t\t\t\PLEASE WAIT WHILE EXITING\n\n";
	cout<<"\t\t\t";
	for(int i=0;i<70;i++)
	cout<<a;
	cout<<"\r";
	cout<<"\t\t\t";
	for(int i=0;i<=70;i++)
	{
		cout<<b;
		for(int j=0;j<1e7;j++);
	}
	system("cls");
	system("color 0B");

}

void browseallproducts(details list[][5])
{
					mainscreen();
					if ( kira == 0 )	
					{
					char anotom;
					cout<<"\tTHERE IS NO STOCK RIGHT NOW"<<endl;
					cout<<"\tENTER ANYTHING TO EXIT"<<endl;
					cout<<"\t-->";
					cin>>anotom;
					}
					else
						{
							for(int x=0;x<kira;x++)
							{
							cout<<"\t"<<x+1<<"."<<list[x][0].brands<<" BRAND"<<endl;
								for(int y=0;y<manytype[x][type];y++)
								{
								cout<<"\t"<<"TYPE "<<y+1<<" :"<<list[x][y].nametype<<endl;
								cout<<"\t"<<"AMOUNT :"<<list[x][y].amount<<endl;
								cout<<"\t"<<"PRICE :"<<list[x][y].price<<endl;
								cout<<endl;
								}
							}
								cout<<"\tENTER ANYTHING TO RETURN TO MAIN"<<endl;
								cout<<"\t-->";
								cin>>anything;
						}
}
