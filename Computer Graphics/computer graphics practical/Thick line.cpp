#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
#include<dos.h>
#include<process.h>

int a,b,x,y;
float d;

void swap(int &x0,int &y0,int &x1,int &y1)
{
	int t=x0;
	x0=x1;
	x1=t;
	t=y0;
	y0=y1;
	y1=t;
}
/*following functions are used to implement different cases*/

void case1(int x0,int y0,int x1,int y1)
{
	   if(x0>x1)         //swap only if condition is true
	   {
	    swap(x0,y0,x1,y1);
	   }
	   d=2*a+b;
	   x=x0;
	   while(x<=x1)
	   {
		putpixel(x,y0,BLUE);
		putpixel(x,y0+1,BLUE);
		putpixel(x,y0-1,BLUE);
		putpixel(x,y0+2,BLUE);
		putpixel(x,y0-2,BLUE);

		if(d<=0)
		  d=d+2*a;
		else
		{
		 d=d+2*(a+b);
		 y0=y0+1;
		}
		x=x+1;

	   }

}

void case2(int x0,int y0,int x1,int y1)
{

	   if(y0>y1)
	   {
	    swap(x0,y0,x1,y1);
	   }
	   d=(a/2)+b;
	   y=y0;

	   while(y<=y1) //error
	   {
		putpixel(x0,y,BLUE);
		putpixel(x0+1,y,BLUE);
		putpixel(x0-1,y,BLUE);
		putpixel(x0+2,y,BLUE);
		putpixel(x0-2,y,BLUE);

		if(d<0)
		 { d=d+a+b;
		   x0=x0+1;}
		else
		{
		  d=d+b;
		}
		y=y+1;

	   }

}

void case3(int x0,int y0,int x1,int y1)
{
	   if(x0>x1)
	   {
	    swap(x0,y0,x1,y1);
	   }
	   d=a-(b/2);

	   x=x0;

	   while(x<=x1)
	   {
		putpixel(x,y0,BLUE);
		putpixel(x,y0+1,BLUE);
		putpixel(x,y0-1,BLUE);
		putpixel(x,y0+2,BLUE);
		putpixel(x,y0-2,BLUE);

		if(d<0)
		 {
		   d=d+a;

		 }
		else
		{
		 d=d+(a-b);
		 y0=y0-1;
		}
		x=x+1;

	   }

}

void case4(int x0,int y0,int x1,int y1)
{
	   if(x0>x1)
	   {
	    swap(x0,y0,x1,y1);
	   }
	   d=a-2*b;
	   y=y0;

	   while(y>=y1)        //y change hoga not x
	   {
		putpixel(x0,y,BLUE);
		putpixel(x0+1,y,BLUE);
		putpixel(x0-1,y,BLUE);
		putpixel(x0+2,y,BLUE);
		putpixel(x0-2,y,BLUE);

		if(d>=0){
		  d=d+2*(a-b);
		  x0+=1;}
		else
		{
		 d=d-2*b;
		 //x0=x0+1;
		}
		y=y-1;

	   }

}



int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
//   int xmax, ymax;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }


   //declarations

	int x0,y0,x1,y1;

	int dx,dy;    //should be int
	float m;

	//input

	cout<<"enter point p1"<<endl;
	cout<<"x1=";
	cin>>x0;
	cout<<"y1=";
	cin>>y0;

	cout<<"enter point p2"<<endl;
	cout<<"x2=";
	cin>>x1;
	cout<<"y2=";
	cin>>y1;

	//calculating slope
	dy=y1-y0;
	dx=x1-x0;
	m=(float)dy/dx;
	a=dy;
	b=-dx;

	setcolor(GREEN);
	line(x0,y0,x1,y1);
	getch();
	//checking the slope of the line

	if(m<=1&&m>=0)
	{

		case1(x0,y0,x1,y1);
	}
	else if(m>1)
	{
		case2(x0,y0,x1,y1);
	}
	else if(m<0&&m>=-1)
	{
		case3(x0,y0,x1,y1);
	}
	else if(m<-1)
	{
		case4(x0,y0,x1,y1);
	}
	else
	{
		cout<<"invalid input";
		delay(1000);
		exit(0);
	}


   /* clean up */
   getch();
   closegraph();
   return 0;
}
