//Program for 3-D Transformation

#include<iostream.h>
#include<dos.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>

int gd=DETECT,gm;
double x1,x2,y1,y2;

void show_message()
	{
	char *mess[]={"-","=","["," ","3","D","-","T","r","a","n","s",
		      "f","o","r","m","a","t","i","o","n"," ","]","=","-"};
	int xx=28,xxx=52,i,j;
	_setcursortype(_NOCURSOR);
	for(i=0,j=24;i<15,j>=12;i++,j--)
		{
		gotoxy(xx,1);
		cout<<mess[i];
		xx++;
		gotoxy(xxx,1);
		cout<<mess[j];
		xxx--;
		delay(50);
		}
	_setcursortype(_NORMALCURSOR);
	}


void draw_cube(double edge[20][3])
      	{
        initgraph(&gd,&gm,"..\bgi");
	int i;
	clearviewport();
	for(i=0;i<19;i++)
	      	{
	       	x1=edge[i][0]+edge[i][2]*(cos(2.3562));
	       	y1=edge[i][1]-edge[i][2]*(sin(2.3562));
	       	x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
	       	y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));
		line(x1+320,240-y1,x2+320,240-y2);
	     	}
	line(320,240,320,25);
	line(320,240,550,240);
	line(320,240,150,410);
	getch();
     	closegraph();
     	}

void scale(double edge[20][3])
     	{
	double a,b,c;
	int i;
	cout<<"Enter The Scaling Factors ";
	cin>>a>>b>>c;
		initgraph(&gd,&gm,"..\bgi");
	clearviewport();
	for(i=0;i<20;i++)
		{
		edge[i][0]=edge[i][0]*a;
		edge[i][1]=edge[i][1]*b;
		edge[i][2]=edge[i][2]*c;
		}
	draw_cube(edge);
		closegraph();
		}

void translate(double edge[20][3])
	{
		int a,b,c;
		int i;
	cout<<"Enter The Translation Factors";
	cin>>a>>b>>c;
		initgraph(&gd,&gm,"..\bgi");
	clearviewport();
		for(i=0;i<20;i++)
			{
		edge[i][0]+=a;
		edge[i][0]+=b;
		edge[i][0]+=c;
			}
	draw_cube(edge);
		closegraph();
	}

void rotate(double edge[20][3])
	{
		int ch;
		int i;
		double temp,theta,temp1;
		clrscr();
	cout<<"-=[ Rotation About ]=-";
	cout<<"1:==> X-Axis ";
	cout<<"2:==> Y-Axis";
		cout<<"3:==> Z-Axis ";
		cout<<"Enter Your Choice ";
	cin>>ch;
	switch(ch)
		{
			case 1:
			cout<<" Enter The Angle ";
			cin>>theta;
			theta=(theta*3.14)/180;
			for(i=0;i<20;i++)
				{
					edge[i][0]=edge[i][0];
					temp=edge[i][1];
					temp1=edge[i][2];
					edge[i][1]=temp*cos(theta)-temp1*sin(theta);
					edge[i][2]=temp*sin(theta)+temp1*cos(theta);
				}
			draw_cube(edge);
			break;

			case 2:
			cout<<" Enter The Angle ";
			cin>>theta;
			theta=(theta*3.14)/180;
			for(i=0;i<20;i++)
				{
					edge[i][1]=edge[i][1];
					temp=edge[i][0];
					temp1=edge[i][2];
					edge[i][0]=temp*cos(theta)+temp1*sin(theta);
					edge[i][2]=-temp*sin(theta)+temp1*cos(theta);
				}
			draw_cube(edge);
			break;

			case 3:  cout<<" Enter The Angle ";
			cin>>theta;
			theta=(theta*3.14)/180;
			for(i=0;i<20;i++)
				{
					edge[i][2]=edge[i][2];
					temp=edge[i][0];
					temp1=edge[i][1];
					edge[i][0]=temp*cos(theta)-temp1*sin(theta);
					edge[i][1]=temp*sin(theta)+temp1*cos(theta);
				}
			draw_cube(edge);
			break;
		}
	}

void reflect(double edge[20][3])
	{
		int ch;
		int i;
		clrscr();
	cout<<"-=[ Reflection About ]=-";
	cout<<"1:==> X-Axis";
	cout<<"2:==> Y-Axis ";
		cout<<"3:==> Z-Axis ";
		cout<<" Enter Your Choice ";
		cin>>ch;
	switch(ch)
		{
			case 1:
			for(i=0;i<20;i++)
				{
					edge[i][0]=edge[i][0];
					edge[i][1]=-edge[i][1];
					edge[i][2]=-edge[i][2];
				}
			draw_cube(edge);
			break;

			case 2:
				for(i=0;i<20;i++)
				{
					edge[i][1]=edge[i][1];
					edge[i][0]=-edge[i][0];
					edge[i][2]=-edge[i][2];
				}
			draw_cube(edge);
			break;

			case 3:
				for(i=0;i<20;i++)
				{
					edge[i][2]=edge[i][2];
					edge[i][0]=-edge[i][0];
					edge[i][1]=-edge[i][1];
				}
			draw_cube(edge);
			break;
		}
	}

void perspect(double edge[20][3])
	{
		int ch;
		int i;
		double p,q,r;
		clrscr();
	cout<<"-=[ Perspective Projection About ]=-";
	cout<<"		1:==> X-Axis ";
	cout<<"2:==> Y-Axis ";
		cout<<"3:==> Z-Axis";
		cout<<" Enter Your Choice :=";
	cin>>ch;
	switch(ch)
		{
			case 1:
			cout<<" Enter P :=";
			cin>>p;
			for(i=0;i<20;i++)
				{
					edge[i][0]=edge[i][0]/(p*edge[i][0]+1);
					edge[i][1]=edge[i][1]/(p*edge[i][0]+1);
					edge[i][2]=edge[i][2]/(p*edge[i][0]+1);
				}
			draw_cube(edge);
			       break;

	     	case 2:
			cout<<" Enter Q :=";
			cin>>q;
			for(i=0;i<20;i++)
				{
					edge[i][1]=edge[i][1]/(edge[i][1]*q+1);
					edge[i][0]=edge[i][0]/(edge[i][1]*q+1);
					edge[i][2]=edge[i][2]/(edge[i][1]*q+1);
				}
			draw_cube(edge);
			break;

			case 3:
			cout<<" Enter R :=";
			cin>>r;
			for(i=0;i<20;i++)
				{
					edge[i][2]=edge[i][2]/(edge[i][2]*r+1);
					edge[i][0]=edge[i][0]/(edge[i][2]*r+1);
					edge[i][1]=edge[i][1]/(edge[i][2]*r+1);
				}
			draw_cube(edge);
			break;
		}
		closegraph();
	}


void main()
	{
	int choice;
		double edge[20][3]=
				{
			100,0,0,
			100,100,0,
			0,100,0,
			0,100,100,
			0,0,100,
			0,0,0,
			100,0,0,
			100,0,100,
			100,75,100,
			75,100,100,
			100,100,75,
			100,100,0,
			100,100,75,
			100,75,100,
			75,100,100,
			0,100,100,
			0,100,0,
			0,0,0,
			0,0,100,
			100,0,100
				};
		while(1)
			{
		clrscr();
			show_message();
		cout<<"1:==> Draw Cube "<<endl;
		cout<<"2:==> Scaling "<<endl;
		cout<<"3:==> Rotation "<<endl;
		cout<<"4:==> Reflection "<<endl;
		cout<<"5:==> Translation "<<endl;
		cout<<"6:==> Perspective Projection "<<endl;
		cout<<"7:==> Exit "<<endl;
		cout<<" Enter Your Choice :=";
			cin>>choice;
		switch(choice)
			 {
			 case 1:
				draw_cube(edge);
				break;

			 case 2:
				scale(edge);
				break;

			 case 3:
				rotate(edge);
				break;

			 case 4:
				reflect(edge);
				break;

			 case 5:
				translate(edge);
				break;

			 case 6:
					perspect(edge);
				break;

			 case 7:
				exit(0);

					 default:
						cout<<" Press A Valid Key...!!! ";
							getch();
							break;
			 }
			closegraph();
			}
	}

