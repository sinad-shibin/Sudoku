#include<iostream.h>

#include<conio.h>

#include<process.h>

#include<iomanip.h>

#include<dos.h>

#include<stdlib.h>

#include<string.h>

#include<stdio.h>

#include<fstream.h>

void Display_Grid(int arr[][9]);

void Display_Sudoku(int arr[][9],int perm[81]);

void Fill_Grid(int arr[][9]);

void Remove_Grid(int temp[][9],int n);

void Check_1(int arr[][9],int val,int i,int j,int &,int &,int &,int &,int &,int &,int &,int &,int &);

void Check_2(int arr[][9],int val,int i,int j,int& ,int& ,int &,int &,int &,int &,int &,int &,int &);

void main()
{

	clrscr();

	randomize();

	textcolor(WHITE);

	int val=0,m=0, a=1000,b=1000,no,n,p,q,r,s,again_val=0,x=26,y=3;

	int arr[9][9]={0},temp[9][9],temp2[9][9],permanent[81],Disp_val=0,check_val=0;

	char level,choice,ch;

	location:;

	for(int i=0;i<81;i++)

	{

		permanent[i]=1000;

	}

	m=0;  //for making the permanents and temporaries the next time the player chooses to play

	clrscr();

	cout<<"Very Easy-(v)"<<endl;

	textcolor(10);

	cputs("EASY-(e)");

	cout<<endl;

	textcolor(YELLOW);

	cputs("MEDIUM-(m)");

	cout<<endl;

	textcolor(12);

	cputs("HARD-(h)");

	cout<<endl;

	textcolor(RED);

	cputs("EVIL-(x)");

	cout<<endl<<endl;

	gotoxy(1,15);

	textcolor(12);

	cputs("Press ESC to exit now....");

	textcolor(15);

	gotoxy(1,17);

	cout<<"********************************* INSTRUCTIONS *********************************\n";

	cout<<"1. Use the w,a,s,d Keys to move the cursor.\n2. Press BACKSPACE to remove an entered Number."

	    <<"\n3. Press ENTER to submit.\n4. Press ESC to exit in between.";

	textcolor(15);

	gotoxy(1,6);

	cout<<"Which Level do you wish to play : ";

	level=getche();

	if(level==27)

		goto end;



	ch=getch();

	if(ch=='\b')

		goto location;

	else

		;



	if(level=='e' || level=='E')

		n=15;

	else if(level=='m'|| level=='M')

		n=40;

	else if(level=='h'|| level=='H')

		n=50;

	else if(level=='x'|| level=='X')

		n=55;

	else if(level=='v'|| level=='V')

		n=5;

	else if(level=='z' || level=='Z')

		n=81;

	else

	{

		cout<<"\n\nEnter something belonging to the choice ";

		getch();

		goto location;

	}





	//Filling the grid

	Fill_Grid(arr);



	for(i=0;i<9;i++)

	{

		for(int j=0;j<9;j++)

			temp[i][j]=arr[i][j];

	}

	Remove_Grid(temp,n);

	for(i=0;i<9;i++)

	{

		for(int j=0;j<9;j++)

			temp2[i][j]=temp[i][j];

	}

	Try_Again_Place:;

	m=0;

	check_val=0;

	a=b=10000000;

	for(i=0;i<9;i++)

	{

		for(int j=0;j<9;j++)

		{

			if(temp[i][j]!=0)

			{

				permanent[m]=(i*10)+j;

				m++;

			}

		}

	}

	Display_Sudoku(temp,permanent);

	gotoxy(27,4);

	x=27;y=4;

	while(1)

	{

		place:;

		textcolor(WHITE);

		ch=getch();

		if(ch=='w'|| ch=='W')

		{

			if(y==18 || y==11)

				y-=3;

			else

				y-=2;

		}

		else if(ch=='a'|| ch=='A')

		{

			if(x==38 || x==49)

				x-=5;

			else

				x-=3;

		}

		else if(ch=='s'|| ch=='S')

		{

			if(y==8 || y==15)

				y+=3;

			else

				y+=2;

		}

		else if(ch=='d'|| ch=='D')

		{

			if(x==33 || x==44)

				x+=5;

			else

				x+=3;

		}

		else if(ch==27)

		{

			break;

		}

		else

		{

			Disp_val=1;

			check_val=0;

			if(ch=='1')no=1;

			else if(ch=='2')no=2;

			else if(ch=='3')no=3;

			else if(ch=='4')no=4;

			else if(ch=='5')no=5;

			else if(ch=='6')no=6;

			else if(ch=='7')no=7;

			else if(ch=='8')no=8;

			else if(ch=='9')no=9;

			else if(ch=='\b')no=0;

			else if(ch==13)

			{

				check_val=1;

				goto here;

			}

			else

			{

				Disp_val=0;

				continue;

			}



			if(y>=18)

				a=(y-5)/2;

			else

				a=(y-4)/2;

			if(x<=44)

				b=((x-27)/3);

			else

				b=((x-27)/4)+1;



		}

		here:;

		if(x<27)

			x=27;

		if(x>55)

			x=55;

		if(y<4)

			y=4;

		if(y>22)

			y=22;

		gotoxy(x,y);



		for(int j=0;j<81;j++)

		{

			if((a*10)+b==permanent[j])

			{

				textcolor(12);

				gotoxy(x,y);

				Display_Sudoku(temp,permanent);

				gotoxy(x,y);

				a=b=100000;

				Disp_val=0;

				goto place;

			}

		}

		if(Disp_val==1)

		{

			temp[a][b]=no;

			Display_Sudoku(temp,permanent);

			Disp_val=0;

		}

		gotoxy(x,y);

		if(check_val==1)

		{

			for(j=0;j<9;j++)

			{

				for(int k=0;k<9;k++)

				{

					if(temp[j][k]==0)

						val++;

				}

			}



			if(val!=0)

			{

				val=0;

				check_val=0;

				gotoxy(28,1);

				textcolor(12);

				cputs("Please complete the sudoku...");

				gotoxy(x,y);

				textcolor(15);

				delay(500);

				Display_Sudoku(temp,permanent);

				textcolor(15);

				gotoxy(x,y);

			}

			else

			{

				for(int p=0;p<9;p++)

				{

					for(int q=0;q<9;q++)

					{

						if(temp[p][q]==arr[p][q])

							continue;

						else

							goto place1;

					}

				}

				place1:;

				again_val=0;

				if(p==9)

				{

					delay(500);

					clrscr();

					P:;

					textcolor(10);

					cout<<endl;

					cputs("             CONGRATULATIONS..! ");

					textcolor(WHITE);

					cputs("YOU COMPLETED THE SUDOKU CORRECTLY");

					if(again_val==0)

						delay(500);

					textcolor(WHITE);

					cout<<endl<<endl<<endl;

					cputs("Do you wish to play again?? <");

					textcolor(10);	cputs("y");

					textcolor(15);	cputs("/");

					textcolor(12);	cputs("n");

					textcolor(15);	cputs("> : ");

					cin>>choice;

					if(choice=='y')

						goto location;

					else if(choice=='n')

						break;

					else

					{

						delay(500);

						cout<<"\nPlease enter a valid choice!!";

						getch();

						again_val++;

						clrscr();

						goto P;

					}



				}

				else

				{

					delay(500);

					clrscr();

					textcolor(RED);

					cout<<endl;

					P1:;

					cputs("                   OOPS...!");

					textcolor(WHITE);

					cputs(" YOU COMPLETED THE SUDOKU INCORRECTLY");

					if(again_val==0)

						delay(500);

					cout<<endl<<endl;

					cputs("Do you wish to play again?? <");

					textcolor(10);	cputs("y");

					textcolor(15);	cputs("/");

					textcolor(12);	cputs("n");

					textcolor(15);	cputs("> : ");

					cin>>choice;

					if(choice=='y')

					{

						cout<<endl<<endl;

						textcolor(15);

						cputs("Do you wish to try again with the same table??<");

						textcolor(10); cputs("y");

						textcolor(15); cputs("/");

						textcolor(12); cputs("n");

						textcolor(15); cputs("> : ");

						cin>>choice;

						if(choice=='y'|| choice=='Y')

						{

							for(i=0;i<9;i++)

							{

								for(j=0;j<9;j++)

									temp[i][j]=temp2[i][j];

							}

							goto Try_Again_Place;

						}

						else if(choice=='n' || choice=='N')

							goto location;

						else

						{

							cout<<"Please enter a valid choice!!";

							getch();

							again_val++;

							clrscr();

							goto P1;

						}

					}

					else

						break;

				}

			}

		}

	}

	end:;

}



void Fill_Grid(int arr[][9])

{

	randomize();

	int a,b,c,d,e,f,g,h,z,  problem_val=0,no,val=0,n=0;

	place2:;

	for(int i=0;i<9;i++)

	{

		for(int j=0;j<9;j++)

			arr[i][j]=0;

	}



	for(i=0;i<9;i++)

	{

		for(int j=0;j<9;j++)

		{



			if(i==0)

			{

				arr[i][j]=random(10);

				if(arr[i][j]==0)

					j--;

			}

			else

				j=8;

			if((j==8 && i==0) || (i!=0))

			{

				problem_val=0;

				for(int n=0;n<9;n++)

				{

					a=b=c=d=e=f=g=h=z=0;

					Check_1(arr,val,i,n,a,b,c,d,e,f,g,h,z);

					Check_2(arr,val,i,n,a,b,c,d,e,f,g,h,z);



					if(a==0)

						arr[i][n]=1;

					if(b==0)

						arr[i][n]=2;

					if(c==0)

						arr[i][n]=3;

					if(d==0)

						arr[i][n]=4;

					if(e==0)

						arr[i][n]=5;

					if(f==0)

						arr[i][n]=6;

					if(g==0)

						arr[i][n]=7;

					if(h==0)

						arr[i][n]=8;

					if(z==0)

						arr[i][n]=9;





					if(arr[i][n]==0)

					{

						problem_val++;

						n=0;

						if(problem_val>100)

							goto place2;

					}

					else

						;

				}

			}

		}

	}



}

//*********************************************************

void Check_1(int arr[9][9],int val,int i,int j,int &a,int &b,int &c,int &d,int &e,int &f,int &g,int &h,int &z)

{



	for(int k=0;k<9;k++)

	{

		if(arr[i][k]==1 || arr[k][j]==1)

		{

			a++;

		}

		if(arr[i][k]==2 || arr[k][j]==2)

		{

			b++;

		}

		if(arr[i][k]==3 || arr[k][j]==3)

		{

			c++;

		}

		if(arr[i][k]==4 || arr[k][j]==4)

		{

			d++;

		}

		if(arr[i][k]==5 || arr[k][j]==5)

		{

			e++;

		}

		if(arr[i][k]==6 || arr[k][j]==6)

		{

			f++;

		}

		if(arr[i][k]==7 || arr[k][j]==7)

		{

			g++;

		}

		if(arr[i][k]==8 || arr[k][j]==8)

		{

			h++;

		}

		if(arr[i][k]==9 || arr[k][j]==9)

		{

			z++;

		}



	}



}

//******************************************************************

void Check_2(int arr[][9],int val,int i,int j,int &a,int &b,int &c,int &d,int &e,int &f,int &g,int &h,int &z)

{



	int l,p,q,r,s,sq_no;

	if(i<=2 && j<=2)

	{

		sq_no=1;

		p=0;

		r=2;

		q=0;

		s=2;

	}

	if(i<=2 && j>2 && j<6)

	{

		sq_no=2;

		p=0;

		r=2;

		q=3;

		s=5;

	}

	if(i<=2 && j>5)

	{

		sq_no=3;

		p=0;

		r=2;

		q=6;

		s=8;

	}

	if(i<=5 && i>=3 && j<=2)

	{

		sq_no=4;

		p=3;

		r=5;

		q=0;

		s=2;

	}

	if(i<=5 && i>=3 && j>2 && j<=5)

	{

		sq_no=5;

		p=3;

		r=5;

		q=3;

		s=5;

	}

	if(i<=5 && i>=3 && j>5)

	{

		sq_no=6;

		p=3;

		r=5;

		q=6;

		s=8;

	}

	if(i>=6 && j<=2)

	{

		sq_no=7;

		p=6;

		r=8;

		q=0;

		s=2;

	}

	if(i>=6 && j>2 && j<=5)

	{

		sq_no=8;

		p=6;

		r=8;

		q=3;

		s=5;

	}

	if(i>=6 && j>5)

	{

		sq_no=9;

		p=6;

		r=8;

		q=6;

		s=8;

	}

	while(p<=r)

	{

		l=q;

		while(l<=s)

		{

			if(arr[p][l]==1)

				a++;

			if(arr[p][l]==2)

				b++;

			if(arr[p][l]==3)

				c++;

			if(arr[p][l]==4)

				d++;

			if(arr[p][l]==5)

				e++;

			if(arr[p][l]==6)

				f++;

			if(arr[p][l]==7)

				g++;

			if(arr[p][l]==8)

				h++;

			if(arr[p][l]==9)

				z++;



			l++;

		}

		p++;



	}



}

//***********************************************************

void Remove_Grid(int temp[][9],int n)

{

	for(int i=0;i<n;i++)

	{

		int a=random(9);

		int b=random(9);

		if(temp[a][b]==0)

			i--;

		else

			temp[a][b]=0;

	}

}

//*******************************************************

void Display_Sudoku(int sudoku[9][9],int perm[81])

{



	clrscr();

	textcolor(15);

	int tr_val=0,a,b,no;

	cout<<"\n\n\n";

	for(int i=0;i<9;i++)

	{

		if(i==0)

			cout<<"                          ";

		else

		{

			cout<<"\n\n                          ";

		}



		for(int j=0;j<9;j++)

		{

			tr_val=0;

			for(int k=0;k<81;k++)

			{

				if(((i*10)+j)==perm[k])

					tr_val++;

			}



			if(sudoku[i][j]==1)

			{

				if(tr_val==0)

					textcolor(15);

				else

					textcolor(10);

				cputs("1  ");

			}

			if(sudoku[i][j]==2)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("2  ");

			}

			if(sudoku[i][j]==3)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("3  ");

			}

			if(sudoku[i][j]==4)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("4  ");

			}

			if(sudoku[i][j]==5)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("5  ");

			}

			if(sudoku[i][j]==6)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("6  ");

			}

			if(sudoku[i][j]==7)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("7  ");

			}

			if(sudoku[i][j]==8)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("8  ");

			}

			if(sudoku[i][j]==9)

			{

				if(tr_val==0)

					textcolor(WHITE);

				else

					textcolor(10);

				cputs("9  ");

			}

			if(sudoku[i][j]==0)

			{

				textcolor(8);

				cputs("*  ");

			}



			if(j==8)

				continue;

			if((j+1)%3==0)

			{

				textcolor(WHITE);

				cputs("| ");

			}

		}

		if(i==8)

			continue;



		if((i+1)%3==0)

		{

			cout<<"\n                         ";

			for(int no=0;no<16;no++)

			{

				textcolor(WHITE);

				cputs("_ ");

			}

		}

	}

	textcolor(15);



}
