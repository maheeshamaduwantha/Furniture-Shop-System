#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include<iostream>
#include <iomanip>
#include<string>
#include <cmath>
#include<stdlib.h>
#include<conio.h>
#include <sstream>
#include <Windows.h>
#include <stdio.h>

using namespace std;
void Login(string UserType);
void Display_Main_Menu();
void PrintBill();
void AboutUs();
void SystemHeader();
void Help();
void WelCome();
void WelcomeAnimation();
void printLine(int n);
void textCenter(string InText, int Linel);
void printSpaces(int n);
void LoginOptions();
void exitFunc();
int opt = 0;
int optionValidate();
bool LoginSts = false;
void footerOption();
void ListStationeries();
void SearchStationeries();
void fetchStDetails(int arrR);
void leftnbox(string InText, int Linel);
int Linel = 100;
void SearchbyID();
void Searchbyiname();
void Searchbypubli();
string UsrTyp = "User";
void addItems();
void modifyItems();
void delItems();
void EmpSal();
int idValidate(string iID);
int main();
float ceilf(float x);

struct ProductRec
{
	string itID;
	string iname;
	string pname;
	string catgry;
	string avlblstck;
	string prse;
};

bool printBill = false;
int ItemQty = 0;
int discount = 0;
void AddToBasket();
string ValidItem();
int Validqty();
void ListBasketItem(int qty);
void DisplyBasket();
double getNumber(string a);
ProductRec ItemBasket[1];


const int arraCount = 9;
ProductRec itArray[arraCount];

void fillarray();

void WelcomeAnimation()
{


    system("COLOR 0e");
    system("cls");
    printf("\e[?25l");

 //Loading animation
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;

    cout << "\n\n\n\t\t\t\tLoading...";
    cout << "\n\n\n\t\t\t\t";

    for(int i = 0; i < 25; i++)
        cout << (char)bar1;

    cout <<"\r";
    cout <<"\t\t\t\t";
    for(int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(150);
    }

    cout<<"\n\t\t\t\t" << (char)1 <<"!";
    system("Pause");
}
void WelCome()
{
    WelcomeAnimation();
	system("cls");
	printLine(100);
	textCenter("SUPRIME FURNITURE ", Linel);
	textCenter("KURUNEGALA ", Linel);
	printLine(100);
	cout << endl;
	textCenter("Total Furniture Solutions for Hotels, Apartments, Residences and Commercial Office Spaces", Linel);
	textCenter("Please select a login option to continue the service  ", Linel);
	cout << endl;
	LoginOptions();
	cout << endl;

}

void LoginOptions()
{

	cout << "1. Admin" << endl;
	cout << "2. Customer" << endl;
	cout << "3. Exit" << endl << endl;
	int opt = optionValidate();

	if (opt == 1)
	{
		UsrTyp = "Admin";
		system("cls");
		Login(UsrTyp);
	}
	else if (opt == 2)
	{
		system("cls");
		Login(UsrTyp);
	}
	else if (opt == 3)
	{
		system("cls");
		exitFunc();
	}
	else
	{
		system("cls");
		WelCome();
	}

}

int optionValidate()
{
	cout << "Please select and option to continue: ";
	int opt;
	cin >> opt;
	while (std::cin.fail())
	{
		std::cout << "Please enter a valid Number: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> opt;
	}

	return opt;

}

//User Login and Validation

void Login(string UserType)
{
START:
	system("cls");
	SystemHeader();
	string username;
	string password;

	cout << "User Name: ";
	cin >> username;
	char ch;
	cout << "Password: ";
	ch = _getch();
	while (ch != 13) {
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}

	//User Login and validation

	if (username == "customer" && password == "customer123" && UserType == "User")
	{
		LoginSts = true;
		Display_Main_Menu();

	}
	else if (username == "admin" && password == "admin123" && UserType == "Admin")
	{
		LoginSts = true;
		Display_Main_Menu();

	}
	else
	{
		cout << endl << endl;
		printLine(100);
		cout << "\nWrong User Name or Password or Login type selected!" << endl;
		cout << "Do you want to return to the Login? y/n: ";
		char Yes;
		cin >> Yes;
		if (Yes == 'y')
		{
			goto START;
		}
		else
		{
			WelCome();
		}
		system("pause");

	}
}

void SystemHeader()
{
	int Linel = 100;
	printLine(100);
	textCenter("SUPRIME FURNITURE ", Linel);
	textCenter("\"Total Furniture Solutions for Hotels, Apartments, Residences and Commercial Office Spaces\"", Linel);
	printLine(100);
	cout << endl;
}

void printLine(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "-";
	}
	cout << endl;

}

// Exit Code
void exitFunc()
{
	system("cls");
	SystemHeader();
	char exitOpt;
	cout << "Do you want to exit? y/n: ";
	cin >> exitOpt;
	if (exitOpt == 'y')
	{
		exit(0);
	}
	else
	{
		system("cls");
		if (LoginSts == true)
		{
			Display_Main_Menu();
		}
		else
		{
			main();
		}

	}
}

void footerOption()
{
	printLine(100);
	cout << endl;
	cout << "1. Return to Main Menu" << endl;
	cout << "2. Exit" << endl;
	int opt = optionValidate();

	if (opt == 1)
	{
		Display_Main_Menu();
	}

	else if (opt == 2)
	{
		exitFunc();
	}

	else
	{
		cout << "Wrong input option !" << endl;
		cout << endl;
		cout << "Do you want to return to the Main Menu? y/n: ";
		char Yes;
		cin >> Yes;
		if (Yes == 'y')
		{
			Display_Main_Menu();
		}
		else
		{
			Display_Main_Menu();
		}
	}


	cout << endl;
}
    //Customer menu
void Display_Main_Menu()
{

	system("cls");
	SystemHeader();

    cout << "1. List of Furniture Items" << endl;
	cout << "2. Search Furniture Items" << endl;
	cout << "3. Print Bill" << endl;
	cout << "4. About Us" << endl;
	cout << "5. Help" << endl;
	cout << "6. Exit" << endl;

	// Admin menu

	if (UsrTyp == "Admin")
	{

		cout << endl;
		cout << "Administrative Access Rights:\n\n";
		cout << "7.  Add Furniture Items" << endl;
		cout << "8.  Modify Items Informations" << endl;
		cout << "9.  Delete Furniture Items" << endl;
		cout << "10. Employee Salary Calculator" << endl;
		cout << endl;
	}


START:
	int option = optionValidate();

	if (option == 1)
	{
		ListStationeries();
	}
	else if (option == 2)
	{
		SearchStationeries();
	}

	else if (option == 3)
	{
		PrintBill();
	}

	else if (option == 4)
	{
		AboutUs();

	}
	else if (option == 5)
	{
		Help();
	}
	else if (option == 6)
	{
		exitFunc();
	}
	else if (option == 7 && UsrTyp == "Admin")
	{
		addItems();
	}
	else if (option == 8 && UsrTyp == "Admin")
	{
		modifyItems();
	}
    else if (option == 9 && UsrTyp == "Admin")
	{
		delItems();
	}
	else if (option == 10 && UsrTyp == "Admin")
	{
		EmpSal();
	}
	else

		cout << "Wrong input option !" << endl;
		cout << endl;
		cout << "Do you want to return to the Main Menu? y/n: ";
		char Yes;
		cin >> Yes;
		if (Yes == 'y')
		{
			Display_Main_Menu();
		}
		else
		{
			goto START;
		}
	}



void printSpaces(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << " ";
	}
}

void textCenter(string InText, int Linel)
{
	int a = InText.length();
	int d = (Linel - 2);
	int c = d / 2;
	int b = (d - a) / 2;

	if (b <= c)
	{
		cout << "*";
		printSpaces(b);
		cout << InText;
		printSpaces(b);
		cout << "*" << endl;
	}

}

void leftnbox(string InText, int Linel)
{
	int a = InText.length();
	int d = (Linel - 2);
	int b = (d - a);
	if (b <= d)
	{
		cout << "";
		cout << InText;
		printSpaces(b);
		cout << "" << endl;
	}


}

void addItems()
{
	system("cls");
	SystemHeader();

	for (int i = 0; i < arraCount; i++)
	{
		if (itArray[i].itID == "")
		{
			char iID[10];
			char itname[100];
			char pubname[100];
			char itcatgry[100];          // Admin Add Items Part
			char itstock[100];
			char itprse[100];

			cout << "Please Enter the Item ID: ";
			cin.ignore();
		ID:
			cin.getline(iID, 10);
			int idEx = idValidate(iID);
			if (idEx == 1)
			{
				cout << endl;
				printLine(100);
				textCenter("The ID Already Exist !", Linel);
				printLine(100);
				cout << endl;
				cout << "Please Enter an ID Again: ";
				idEx = 0;
				goto ID;
			}
			else
			{
				itArray[i].itID = iID;
			}
			cout << "\nPlease Enter the Item Name: ";
			cin.getline(itname, 100);
			itArray[i].iname = itname;
			cout << "\nPlease Enter the Item Makers Name: ";
			cin.getline(pubname, 100);
			itArray[i].pname = pubname;
			cout << "\nPlease Enter the Category: ";
			cin.getline(itcatgry, 100);
			itArray[i].catgry = itcatgry;
			cout << "\nPlease Enter the Available Stock: ";
			cin.getline(itstock, 100);
			itArray[i].avlblstck = itstock;
			cout << "\nPlease Enter the Item Price: ";
			cin.getline(itprse, 100);
			itArray[i].prse = itprse;
			cout << "\nData Added Successfully !\n";
			break;
		}
	}
	footerOption();
}

int idValidate(string iID)
{
	for (int i = 0; i < arraCount; i++)
	{
		if (itArray[i].itID == iID)
		{
			return(1);
		}
	}
}

void modifyItems()
{
	system("cls");
	SystemHeader();

	char iID[10];
	char itname[100];
	char pubname[100];
	char itcatgry[100];
	char itstock[100];
	char itprse[100];

	cout << "Please Enter the Item ID to Modify: ";
ID:
	cin.ignore();
	cin.getline(iID, 10);							// Admin Items Modify
	for (int i = 0; i < arraCount; i++)
	{
		if (itArray[i].itID == iID)
		{
			cout << "\nPlease Enter the Item Name: ";
			cin.getline(itname, 100);
			itArray[i].iname = itname;
			cout << "\nPlease Enter the Item Makers Name: ";
			cin.getline(pubname, 100);
			itArray[i].pname = pubname;
			cout << "\nPlease Enter the Category: ";
			cin.getline(itcatgry, 100);
			itArray[i].catgry = itcatgry;
			cout << "\nPlease Enter the Available Stock: ";
			cin.getline(itstock, 100);
			itArray[i].avlblstck = itstock;
			cout << "\nPlease Enter the Item Price: ";
			cin.getline(itprse, 100);
			itArray[i].prse = itprse;

			cout << "\nData Modified Successfully !\n";

			break;
		}

		else
		{
			cout << "Could not find the ID in the Database !\n";
			cout << "Please enter a valid ID to proceed: ";

			goto ID;
		}
	}
	footerOption();
}

void fillarray()
{
	itArray[0].itID = "001";
	itArray[0].iname = "Armstrong";
	itArray[0].pname = "Living Room Furniture";
	itArray[0].catgry = "SOFA";
	itArray[0].avlblstck = "7";
	itArray[0].prse = "78,000.00 LKR";

	itArray[1].itID = "002";
	itArray[1].iname = "Belfast";
	itArray[1].pname = "Living Room Furniture";
	itArray[1].catgry = "SOFA";
	itArray[1].avlblstck = "15";
	itArray[1].prse = "98,000.00 LKR";

	itArray[2].itID = "003";
	itArray[2].iname = "Adam GT";
	itArray[2].pname = "Dining Tables";
	itArray[2].catgry = "TABLE";
	itArray[2].avlblstck = "14";
	itArray[2].prse = "52,000.00 LKR";

	itArray[3].itID = "004";
	itArray[3].iname = "Adam TT";
	itArray[3].pname = "Dining Tables";
	itArray[3].catgry = "TABLE";
	itArray[3].avlblstck = "22";
	itArray[3].prse = "43,000.00 LKR";

	itArray[4].itID = "005";
	itArray[4].iname = "PK 07";
	itArray[4].pname = "PANTRY CUPBOARD & KITCHEN COLLECTION";
	itArray[4].catgry = "PANTRY & KITCHEN";
	itArray[4].avlblstck = "10";
	itArray[4].prse = "125,000.00 LKR";

	itArray[5].itID = "006";
	itArray[5].iname = "PK 08";
	itArray[5].pname = "PANTRY CUPBOARD & KITCHEN COLLECTION";
	itArray[5].catgry = "PANTRY & KITCHEN";
	itArray[5].avlblstck = "14";
	itArray[5].prse = "245,000.00 LKR";

}
void delItems()
{

}

void EmpSal()
{
    system("cls");
	SystemHeader();

    string Name, Department;
	cout<<"Enter the Name :";
	cin>>Name;

	cout<<"Enter Department :";
	cin>>Department;

	int Basic_Salary;
	cout<<"Enter Basic Salary :";
	cin>>Basic_Salary;

	int OT_hrs;
	cout<<"Enter OT hrs :";
	cin>>OT_hrs;

    int OT_hour_amount;
	cout<<"Enter OT amount for hour :";
	cin>>OT_hour_amount;

	int Leave_Days;
	cout<<"Enter Leave Days :";
	cin>>Leave_Days;

	double OT_amount;
	double Net_salary_1;
	double Day_pay;
	double Day_pay_x_Leave_days;
	double Net_salary_2;
	double EPF_Emp;
	double EPF_Com,ETF,Central_Bank,Net_salary_3,Bonus,Welfare,Increasment,Income_tax,Gross_salary;

	cout<<"Name : "<<Name<<endl;

	cout<<"Dept : "<<Department<<endl;

	cout<<"Basic salary : "<<Basic_Salary<<endl;

	cout<<"OT Rate :"<<OT_hour_amount<<endl;

	cout<<"OT Hrs : "<<OT_hrs<<endl;

	cout<<"OT Amount :"<<OT_amount<<endl;

	Net_salary_1 = Basic_Salary + OT_amount;
	cout<<"Net Salary 1: "<<Net_salary_1<<endl;

	Day_pay = Basic_Salary/25;
	cout<<"Day pay :"<<Day_pay<<endl;

	cout<<"Leave days :"<<Leave_Days<<endl;

	Day_pay_x_Leave_days = Day_pay * Leave_Days;
	cout<<"Day pay * Leave days :"<<Day_pay_x_Leave_days<<endl;

	Net_salary_2 = Net_salary_1 - Day_pay_x_Leave_days;
	cout<<"Net salary 2 :"<<Net_salary_2<<endl;

	EPF_Emp = Basic_Salary * 0.08;
	cout<<"EPF(Emp) BS 8% :"<<EPF_Emp<<endl;

	EPF_Com = Basic_Salary * 0.12;
	cout<<"EPF(Com) BS 12% :"<<EPF_Com<<endl;

	ETF = Basic_Salary * 0.03;
	cout<<"ETF BS 3% :"<<ETF<<endl;

	Central_Bank = EPF_Emp + EPF_Com + ETF;
	cout<<"Central Bank :"<<Central_Bank<<endl;

	Net_salary_3 = Net_salary_2 - EPF_Emp;
	cout<<"Net Salary 3 :"<<Net_salary_3<<endl;

	Bonus = Basic_Salary * 2;
	cout<<"Bonus :"<<Bonus<<endl;

	Welfare = 100;
	cout<<"Welfare :"<<Welfare<<endl;

	Increasment = Basic_Salary * 0.1;
	cout<<"Increasment :"<<Increasment<<endl;

	if(Net_salary_3 >= 500000) {Income_tax = Net_salary_3 * 0.08;
	cout<<"Income tax :"<<Income_tax<<endl;
	}
	else if(Net_salary_3 >= 200000) {Income_tax = Net_salary_3 * 0.06;
	cout<<"Income tax :"<<Income_tax<<endl;
}

	else if(Net_salary_3 >= 160000) {Income_tax = Net_salary_3 * 0.03;
	cout<<"Income tax :"<<Income_tax<<endl;
}

	else{cout<<"No Income tax"<<endl;
	}

	Gross_salary = Net_salary_3 + Bonus + Increasment - Welfare - Income_tax;
	cout<<"Gross salary :"<<Gross_salary<<endl;
}

void ListStationeries()
{
	system("cls");;
	SystemHeader();


	for (int i = 0; i < arraCount; i++)
	{
		fetchStDetails(i);

	}							// List Items View

	footerOption();
}

void fetchStDetails(int arrR)
{
	if (itArray[arrR].itID == "")
	{
		return;
	}

	printLine(100);

	leftnbox("Items ID\t\t:\t" + string(itArray[arrR].itID), Linel);
	leftnbox("Items Name\t\t:\t" + string(itArray[arrR].iname), Linel);
	leftnbox("Item Makers Name\t\t:\t" + string(itArray[arrR].pname), Linel);
	leftnbox("Category\t\t:\t" + string(itArray[arrR].catgry), Linel);
	leftnbox("Available Stock\t\t:\t" + string(itArray[arrR].avlblstck), Linel);
	leftnbox("Price\t\t\t:\t" + string(itArray[arrR].prse), Linel);
}

void SearchStationeries()
{

	system("cls");
	SystemHeader();

	cout << "Search Stationeries by: \n";
	cout << "1. Item ID" << endl;
	cout << "2. Item Name" << endl;
	cout << "3. Item Maker" << endl;

START:
	int option = optionValidate();

	if (option == 1)
	{
		SearchbyID();				// Search Items by ID, Name, Maker
	}
	else if (option == 2)
	{
		Searchbyiname();
	}
	else if (option == 3)
	{
		Searchbypubli();

	}

	else
	{
		cout << "Wrong input option !" << endl;
		cout << endl;
		cout << "Do you want to return to the Main Menu? y/n: ";
		char Yes;
		cin >> Yes;
		if (Yes == 'y')
		{
			Display_Main_Menu();
		}
		else
		{
			goto START;
		}
	}

	footerOption();
}

void SearchbyID()
{
	system("cls");
	SystemHeader();
	string iID;
	cout << "Enter Items ID: ";
START:
	cin >> iID;
	bool found = false;

	for (int i = 0; i < arraCount; i++)
	{
		if (iID == itArray[i].itID) {

			found = true;
			fetchStDetails(i);
			cout << endl;
			break;
		}
	}
	if (found == false)
	{
		cout << "Invalid id, Please enter a valid id again(Eg: \"001\"): " << endl;
		goto START;
	}

	footerOption();
}

void Searchbyiname()
{
	system("cls");
	SystemHeader();
	string itname;
	cout << "Enter Items Name: ";
START:
	cin >> itname;
	bool found = false;

	for (int i = 0; i < arraCount; i++)
	{
		if (itname == itArray[i].iname) {

			found = true;
			fetchStDetails(i);
			cout << endl;
		}
	}
	if (found == false)
	{
		cout << "Could not find the name in database, Insert first letter capital(Eg: \"Sofa\"): " << endl;
		goto START;
	}

	footerOption();
}

void Searchbypubli()
{
	system("cls");
	SystemHeader();
	string pubname;
	cout << "Enter Item Makers Name: ";
START:
	cin >> pubname;
	bool found = false;

	for (int i = 0; i < arraCount; i++)
	{
		if (pubname == itArray[i].pname) {

			found = true;
			fetchStDetails(i);
			cout << endl;
		}
	}
	if (found == false)
	{
		cout << "Could not find the name in the database, Insert first letter capital(Eg: \"Sofa\"): " << endl;
		goto START;
	}

	footerOption();

}

void PrintBill()
{
	system("cls");
	SystemHeader();

	//footerOption();
	AddToBasket();


}

// About Us Code

void AboutUs()
{
	system("cls");
	SystemHeader();

	cout << "- Suprime Furniture is a best furniture seller in Sri Lanka.\n- Today we are comprised of more than 6 branches including furniture stores.\n- Suprime Furniture is also a direct importer and distributor of furnitures the worldwide.\n- Suprime Furniture are now available online at our website suprimefurniture.lk\n- Registered under Forest Ordinance (Chapter 451) as amended by act no.13 of 1996.\n" << endl;


	footerOption();



}
// Help Code
void Help()
{
	system("cls");
	SystemHeader();
	cout << "This billing system is maintained by Suprime Furniture Engineers.\nIf you have face the any issues please call us.\nYou can reach out for question or concern about your billing system or you have a general enquiry.\n\n" << endl;
	cout << "Phone: \t+94 112 500 833\nFax: \t+94 112 301 633\nEmail: \tinfo@suprimefurniture.com \n";



	footerOption();

}

int main()
{
	fillarray();
	WelCome();

	cout << endl;
	cout << endl;
	cout << endl;
	system("pause");
}


void AddToBasket()
{
	system("cls");
	SystemHeader();
	cout << "Please Enter the Item ID Go Ahead:" << endl;
	cout << endl;
	cout << "2. Main menu" << endl;
	cout << endl;
	string itembuy = ValidItem();
	if (itembuy == "2")                      // Add to Items for Bill
	{
		Display_Main_Menu();
	}
	else
	{
		ItemQty = Validqty();

		DisplyBasket();

	STARTAddRemove:
		cout << endl;
		cout << " 1.  Add More Quantity" << endl;
		cout << " 2.  Clear Quantity" << endl;
		cout << " 3.  Print Bill" << endl;
		cout << " 4.  Main menu" << endl;
		string opt = "";
		cin >> opt;

		if (opt == "1")
		{
			ItemQty = Validqty();
			DisplyBasket();
			goto STARTAddRemove;
		}
		else if (opt == "-1")
		{
			ItemQty = Validqty();
			DisplyBasket();

			goto STARTAddRemove;
		}
		else if (opt == "3")
		{
			ItemQty = 0;
			Display_Main_Menu();
		}
		else if (opt == "2")
		{
			cout << " 2. Add to Discount " << endl;
			cout << "-2. Without Discount" << endl;

			string option = "";
			cin >> option;

			if (option == "2")
			{
				discount = 5;
				DisplyBasket();
				goto STARTAddRemove;
			}
			else
			{
				discount = 0;
				DisplyBasket();
				cout << " 1. Return to Main Menu" << endl;

				string optionPrint = "";
				cin >> optionPrint;
				if (optionPrint == "1")
				{
					Display_Main_Menu();
				}
				DisplyBasket();
			}

			goto STARTAddRemove;
		}
		else
		{
			cout << "Invalid input..." << endl;
			goto STARTAddRemove;
		}
	}


}

void DisplyBasket()
{
	system("cls");
	SystemHeader();
	cout << "Your Bill Details...." << endl;
	ListBasketItem(ItemQty);
}

string  ValidItem()
{
	string opt = "2";
	bool valid = false;
	while (valid != true)
	{
		std::cout << "Please Enter the Value Item ID: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> opt;					// Print Bill – Enter the Item ID
		if (idValidate(opt) == 1)
		{
			for (int i = 0; i < arraCount; i++)
			{
				if (itArray[i].itID == opt)
				{
					ItemBasket[0].itID = itArray[i].itID;
					ItemBasket[0].iname = itArray[i].iname;
					ItemBasket[0].pname = itArray[i].pname;
					ItemBasket[0].catgry = itArray[i].catgry;
					ItemBasket[0].avlblstck = itArray[i].avlblstck;
					ItemBasket[0].prse = itArray[i].prse;
				}
			}
			valid = true;
		}
		else if (opt == "2")
		{
			valid = true;
		}
	}

	return opt;
}

int  Validqty()
{
	int qty = 0;
	int qtyAvl = std::atoi(ItemBasket[0].avlblstck.c_str());
	bool valid = false;
	while (valid != true)
	{
		std::cout << "Please Enter Quantity :";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> qty;

		if (qty > 0 && qtyAvl >= qty)  // Enter Quantity
		{
			valid = true;
		}
		else
		{
			cout << "Not a Valid Quantity:" << endl;
		}

	}
	return qty;
}


#define ROUNDF(f, c) (((float)((int)((f) * (c))) / (c)))
void ListBasketItem(int qty)
{
	printLine(100);

	int IndexCount = ItemBasket[0].prse.find("LKR");

	string ccc = ItemBasket[0].prse.substr(0, IndexCount);

	double price = getNumber(ccc.c_str());
	double TOTaMOUNT = 0.0f;    					// Discout Calculate
	if (discount > 0)
		TOTaMOUNT = ((price * qty) * (100 - discount)) / 100;
	else
		TOTaMOUNT = price * qty;

	std::ostringstream buffer;
	buffer << std::fixed;
	buffer << std::setprecision(2);
	buffer << TOTaMOUNT;						// Print Bill
	std::string strObj3 = buffer.str();


	leftnbox("Items ID\t\t:\t" + string(ItemBasket[0].itID), Linel);
	leftnbox("Items Name\t\t:\t" + string(ItemBasket[0].iname), Linel);
	leftnbox("Item Makers Name\t\t:\t" + string(ItemBasket[0].pname), Linel);
	leftnbox("Category\t\t:\t" + string(ItemBasket[0].catgry), Linel);

	if (discount > 0)
		leftnbox("Total Amount(%)\t\t:\t" + string(strObj3), Linel);

	else
		leftnbox("Total Amount\t\t:\t" + string(strObj3), Linel);


	if (printBill)
		cout << endl;
	cout << endl;


	cout << "Thank You Come Again..! - SUPRIME FURNITURE - +94 112 500 833" << endl;
}

double getNumber(string a)
{

	for (int i = 0; i <= a.size(); i++) {
		if (a[i] == ',') {
			a.erase(i, 1);
		}
	}


	return atof(a.c_str());
}



