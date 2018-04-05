			/*mid point ellipse drawing*/
#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
double a,b;
float m,n;
void pixels(int x,int y)
{
	putpixel(x+m,y+n,BLUE);
	putpixel(x+m,-y+n,BLUE);
	putpixel(-x+m,-y+n,BLUE);
	putpixel(-x+m,y+n,BLUE);
}


int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

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
   m=getmaxx();
   n=getmaxy();
   m=m/2;
   n=n/2;
   /*circle drawing */
   int x,y,r;
   double d,de,dse;

   //user input

   cout<<"\nenter coordinates of the point";
   cout<<"\n a:";
   cin>>a;
   cout<<"\n b:";
   cin>>b;
   cout<<endl;
   setcolor(WHITE);

   a=a/2;
   b=b/2;
   x=0;
   y=b;
   d=b*b-(a*a*b)+(0.25*a*a);
   //dse=(2*x)-(2*y)+5;
   //de=(2*x)+3;
//  ellipse(x,y,a,b);

   //drawing the circle


   pixels(x,y);

   while(((a*a)*(y-0.5))>((b*b)*(x+1)))
   {
	if(d<0)	    //select e
	d+=(b*b)*2*x+3;
	else        //select se
	{
		d+=(b*b)*(2*x+3)+(a*a*((-2*y)+2));
		y--;
	}
	x++;
	pixels(x,y);
   }
   d=(b*b)*(pow((x+0.5),2))+(a*a)*(pow((y-1),2))-(a*a*b*b);
   while(y>0)
   {
       if(d<0)
	 {
	    d+=(b*b)*(2*x+2)+(a*a)*(-2*y+3);
	    x++;
	 }
       else
	  d+=(a*a)*(-2*y+3);
       y--;
       pixels(x,y);
   }
   /* clean up */
   getch();
   closegraph();
   return 0;
}





