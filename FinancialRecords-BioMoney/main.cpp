#include <iostream>
#include <iomanip> //library for setprecision
#include <conio.h> // library for getch, gotoxy
#include <windows.h> //library for handle function

using namespace std;

// =color function=//
void setcolor(unsigned short color)
{
	//This function is used to display color
	//how to check color list : open cmd >> color Z >> enter
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
	//[GetStdHandle] function to get handle to screen
}

// =gotxy function= //
void gotoxy(int x, int y)
{ 
	//This function is used in graphing by moving the cursor to points x and y
	COORD titik = {x,y};
	//[COORD] is a coordinate data type
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), titik);
	//[SetConsoleCursorPosition] functions to move the cursor from the x=0 and y=0 positions to the desired x and y positions
}

// =title function= // 
void title()
{
	system ("cls");
	//setcolor serves to change the display color of cmd, the number in brackets is the type of text and background color
	setcolor (880);
	cout << "=============================================================================" << endl;
    cout << "=                          FINANCIAL RECORD PROGRAM                         =" << endl;
	cout << "=============================================================================" << endl;
	cout << endl;
	setcolor (7);
}

// =fungsi main= //
int main ()
{
	
    //PROFILE
    first:
    	//[system("cls")] berfunsgi untuk membersihkan layar pada program
    	title();
    	setcolor (7);
    	string name;
    	cout << " Enter your name : ";
		getline (cin,name);
		//[getline] functions to take input in one line
		cout << endl;

	//PERIOD
	string period;
	string time;
	
	selectperiod :
		title();
		//[title()] means calling the title function
		cout << "---------------------------  SELECT TIME PERIODE  ---------------------------" << endl;		
		cout << endl;
		cout << " Select the time period for which you want to record the finances :" << endl;
		cout << endl;
    	cout << " 1. Daily" << endl;
    	cout << " 2. Weekly" << endl;
    	cout << " 3. Monthly" << endl;
    	cout << endl;
    	cout << " Your choice : ";
    	cin >> period;
    	cout << endl;

    	//(conditional statement to specify the contents in the time container)
		if (period == "1")
    	{
    		time = "day";
    		goto selectincome;
    		//[goto] functions to move and run the intended coding
		}
		if (period == "2")
		{
			time = "week";
			goto selectincome;
		}
		if (period == "3")
		{
			time = "month";
			goto selectincome;
		}
		else
		{
			setcolor (12);
			cout << " The option you want doesn't exist." << endl;
			cout << endl;
			setcolor (7);
			getch();															
			cout << endl;
			goto selectperiod;
		}

    //INCOME
    int income;
    
    selectincome:
		cout << "---------------------------------  INCOME  ----------------------------------" << endl;
    	cout << endl;
    	cout << " Your income this " << time << " : Rp.";
		cin >> income;
		cout << endl;

	//SHOWING EXPENSE CATEGORIES
	expense :
	title();
	int expense; 
	int total = 6;
	string change;
	string kat[100]={"Foods","CLothing","Electricity","Health","Hobby","etc"};
	//[string kat[100]] is the container/where the category name is stored
	
	cout << "---------------------------------  EXPENSE  ---------------------------------" << endl;
	cout << endl;
	cout << " List of expense categories : " << endl;
	cout << endl;
	
	//(Loop to display category list)
	for (int i=0;i<total;i++)
	{
		cout << i+1 << ". " << kat[i] << endl;
	}		
	
	cout << endl;
	cout << " Do you want to change the category above ( Yes(Y) / No(N) ) ? ";
	cin >> change;
	cout << endl;

	//CHANGE KATEGORI
	edit :
		if (change=="y"||change=="Y"||change=="yes"||change=="Yes")
		//[if (change=="y"||change=="Y")] change is a container that contains the answer to
		//[||] is [or], so the purpose of if above is [y or Y], the goal is to make it easier for users if they forget to fill in large [Y]

		{	
			system ("cls");
			title();
			cout << "-----------------------------  CHANGE KATEGORI  -----------------------------" << endl;
			cout << endl;
			setcolor (12);
			cout << "Input multiple categories not less than 2 and greater than 8." << endl << endl;
			setcolor (7);
			cout << " How many categories of expenses do you want : ";
			cin >> total;
			cout << endl;
			
			
			if (total>8)
			{
				setcolor (12);
				cout << " The categories you want are too many." << endl;
				cout << " Use category name 'etc' for less important categories." << endl << endl; 
				setcolor (7);
				getch ();
				goto edit;
			}
			else if (total<2)
			{
				setcolor (12);
				cout << " The category you want is too few, try more than 1." << endl << endl;
				setcolor (7);
				getch ();
				goto edit;
			}
			else
		
			cout << " Enter the category name: " << endl;
			cout << endl;
			//(loop to input the name of the category that you wanted to edit)
			for (int i=0;i<total;i++)
			{
				cout << "Category " << i+1 << " : ";
				cin >> kat[i];
			}
		}
		else if (change=="N"||change=="n"||change=="no"||change=="No")
		{
			goto input;
		}
		else
		{
			setcolor (12);
			cout << " Your input is wrong, please enter as instructed";
			setcolor (7);
			getch();
			getch ();
			goto expense;
		}
	
	Baru:
	system ("cls");
	title();	
	cout << endl;
	cout << "-------------------------------  NEW EXPENSE  -------------------------------" << endl;
	cout << endl;
	cout << " List of New expense categories : " << endl;
	cout << endl;
	//(loop to show new category)
	for (int i=0;i<total;i++)
	{
		cout << i+1 << ". " << kat[i] << endl;
	}
	
		cout << endl;	
		cout << " Are you sure about the list of expense categories above," << endl;
		cout << " Do you want to change the category again ( Yes(Y) / No(N) ) ? ";
		cin >> change;
		cout << endl;
		
	if (change=="y"||change=="Y"||change=="Yes"||change=="yes")
	{
		goto edit;
	}
	else if (change=="n"||change=="N"||change=="No"||change=="no")
	{
		goto input;
	}
	else
	{
		cout << " Your input is wrong, please enter as instructed";
		goto Baru;
	}
	
	//INPUT expense
	input :
		system ("cls");
		cout << "----------------------------  INPUT EXPENSE  --------------------------------" << endl;
		cout << endl;
		cout << " Enter the expense per category below : " << endl;
		cout << endl;
		float input [100];
		
		for (int i=0;i<total;i++)
		{
			cout << i+1 << ". " << kat[i] << " : Rp." ;
			//The second iteration is to input the cost per category name that was displayed earlier
			for(int k=i;k<=i;k++)
			{
				cin >> input [i];
			}	
		}
		system("cls");	
			
	cout << endl;
		
	//HASIL AKHIR	
	title();
	cout << "-------------------------  YOUR FINANCIAL RECORD  ---------------------------" << endl;		
	cout << endl;
		
	//TOTAL,MIN,MAX
	int add,min,max;
	add=0;
	min = input [0];
	max = input [0];
	string katmax;
	
	//loop to find the highest and lowest total expense and expense	
	for (int j=0;j<total;j++)
	{
		//first add to find Total
		add = add + input[j];
		
		//both branches to determine the highest and lowest expense
		if (input [j]<min)
		{
			min=input[j];
		}
		else if (input[j]>max)
		{
			max=input[j];
			katmax=kat[j];
		}
	}
	cout << " "<< "Hii " << name << endl;	
	cout << endl;
	cout << " Your total income for this " << time << " : "; setcolor(2); cout << "Rp." << income << endl; setcolor(7);
	cout << " Your total expenses for this " << time << " : "; setcolor(4); cout << "Rp." << add << endl; setcolor(7); 
	cout << " Your biggest expense is " << max << "  in the category "<< katmax << endl;   
	
	//branching to determine whether we are wasteful or not by comparing income and expenses with the total(add)
	if (income >= add)
	{
		cout << " Your remaining money for this " << time << " is "; setcolor(1); cout << "Rp." << income-add << endl; setcolor(7);
		cout << endl;
		setcolor(2);
		cout << " You are good enough in managing your finances" << endl;
		cout << " Keep it up for even more savings " << name << endl;
		setcolor(7);
	}
	else if (income < add)
	{
		setcolor(2);
		cout << " expense anda melebihi income anda" << endl;
		cout << endl;
		cout << " Anda sangat Boros" << endl;
		cout << " Trying to be frugal in managing your finances "<< endl;
		setcolor(7);
	}
	
	
	//PONDASI GRAFIK
	cout << endl;
	cout << "---------------------------  PERCENTAGE GRAPH  -----------------------------" << endl;
	cout << endl;
	
	// loop to make numbers 0.5,10,15,..,100 from bottom to top on the graph
	// the number is the x-axis (percentage value) which is the point for measuring the percentage height of the category later
	for(float m=0;m<=20;m++)
	{
		int n;
		n = m*5;
		gotoxy(1,38-m);cout<<n;  	 
	}
	
	// the loop is almost the same as the one above except that it is not a number that is printed but [|] as a line to make it easier to understand the graph					
	for(int o=0;o<=20;o++) 
	{
		gotoxy(4,38-o);cout<<"|";
	}
	
	// this loop consists of two functions to print [-]
	for(int p=0;p<=70;p++) 
	{
		for(int q=0;q<=20;q++)
		{
			gotoxy(6+p,18+q);cout<<"-"; 
		}
	}
	
	// this loop is the same as above the function is to print [ ]
	// the goal is to anticipate if there is a downward [-] line so it doesn't damage the graph
	for (int p=0;p<=80;p++)
	{
		for (int q=0;q<=5;q++)
		{
			gotoxy(6+p,39+q);cout<<" ";
		}
	}
	
	//PERCENTAGE GRAPH CATEGORY
	
	int i=0;
	// the do while loop is created as the y-axis or the point where the category bar graph stands
	//which will be executed with the gotoxy function in the for loop
	
	do
	{	
		// the for loop will print a bar graph in the form of a [|#|] symbol from bottom to top according to how big the percentage of the category is
		// note formula : percentage is obtained from = (input[i]/add*100)
		// number of bars that are symbols [|#|] = percentage/5
		//example for example input [i] = 10, add=100
		// then percentage = (10/100*100) = 10
		// then number of bars = 10/5 = 2
		// then the symbol [|#|] will be printed 2 times
		for(float x=0;x<=((input[i]/add*100)/5);x++)
		{
			setcolor (i+8);
			int p=(i*9)+9;
			int q=(i*9)+9;
			gotoxy(p,38-x);cout<<"|#|";
			gotoxy(q,39);
			setcolor (7);
			cout << "Kat-" << i+1;
		}
		i++;
	}
	while (i<total);
	setcolor (7);
	
	cout << endl;
	cout << endl;
	cout << " Description : " << endl;

	
	for (int i=0;i<total;i++)
	{	
		cout << " - " ;
		setcolor (i+1);
		cout << "|#|";
		setcolor (7);
		cout << " : " << setprecision(2) << input[i]/add*100 << "%" << " dari " << kat[i]<<endl;
		//[setprecision(2)] function to display only 2 numbers after comma
	}
	
	//AKHIR PROGRAM
	
	programakhir:
		cout << endl;
		cout << " Do you want to end this program (Yes(Y) / No(N)) ?";
		cin >> change;
		
	if(change=="y"||change=="Y"||change=="Yes"||change=="yes")
	{
		goto first;
	}
	else if (change=="n"||change=="N"||change=="No"||change=="no")
	{
		goto end;
	}
	else 
	{	
		setcolor (12);
		cout << " Your choice doesn't exist" << endl;
		setcolor (7);
		getch();
		goto programakhir;
		system ("cls");
	}
	end:
		getch ();
		/*[getch()] functions to stop programming so that it doesn't immediately exit/move*/
		return 0;
}

