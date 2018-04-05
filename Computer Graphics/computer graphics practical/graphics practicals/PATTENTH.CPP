# include <iostream.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>
int arr[10];
char IncFlag;
void Bresenham(int x1,int x2,int y1,int y2);
void DrawLine(int X,int Y,int End,int NE,int E,int d,int XInc,int YInc);
void main()
{
	int gDriver=DETECT, gMode;
	int x1,x2,y1,y2;

	void Bresenham(int,int,int,int);
	initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
	cout<<endl<<"x1   : ";
	cin>>x1;
	cout<<endl<<"y1   : ";
	cin>>y1;
	cout<<endl<<"x2   : ";
	cin>>x2;
	cout<<endl<<"y2   : ";
	cin>>y2;
	for(int i=0;i<10;i++)
	cin>>arr[i];
	//line(320,0,320,480);
	//line(0,240,640,240);
	Bresenham(x1,x2,y1,y2);
	Bresenham(x1,x2, (y1+1), (y2+1));
	Bresenham(x1,x2, (y1-1), (y2-1));
	line(x1+50,y1,x2+50,y2);
	cleardevice();
	Bresenham(x1,x2,y1,y2);
	getch();
}

void Bresenham(int x1,int x2,int y1,int y2)
{
	int S,O,End;
	int d;
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	float Slope;
	int NE,E,XInc,YInc;
	if (dx == 0)  //Slope Infinite
	{
	}
	else
	{
	Slope = (float)(y1 - y2) / (x1 - x2);   //to find slop
	if (Slope>-1 && Slope<1) //slope between
	{
		IncFlag = 'X';
		NE = 2 * (dy - dx);
		E = 2 * dy;
		d = 2 * dy - dx;
		if (x1>x2)
		{
		S = x2;
		O = y2;
		End = x1;
		}
		else
		{
		S = x1;
		O = y1;
		End = x2;
		}
//            DrawLine(x,y,End,NE,E,d,XInc,YInc);
	}
	else
	{
		IncFlag = 'Y';
		NE = 2 * (dx - dy);
		E = 2 * dx;
		d = 2 * dx - dy;
		if (y1 > y2)
		{
		O = x2;
		S = y2;
		End = y1;
		}
		else
		{
		O = x1;
		S = y1;
		End = y2;
		}
	}
	if (IncFlag == 'X'&&arr[S%10]==0)
		putpixel(S,O,YELLOW);
	else if(arr[O%10]==0)
		putpixel(O,S,YELLOW);
	while (S <= End)
	{
		S++;
		if (d<0)
		d = d + E;
		else
		{
		d = d + NE;
		if (Slope>0)
			O++;
		else
			O--;
		}
		if (IncFlag == 'X'&&arr[S%10]==0)
		putpixel(S,O,YELLOW);
		else if(arr[O%10]==0)
		putpixel(O,S,YELLOW);
	}
	}
}