			/*Mid point circle drawing*/

#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
int x1,y1;
void pixels(int x,int y)
{
	putpixel(x+x1,y+y1,BLUE);
	putpixel(y+x1,x+y1,BLUE);
	putpixel(y+x1,-x+y1,BLUE);
	putpixel(x+x1,-y+y1,BLUE);
	putpixel(-x+x1,-y+y1,BLUE);
	putpixel(-y+x1,-x+y1,BLUE);
	putpixel(-y+x1,x+y1,BLUE);
	putpixel(-x+x1,y+y1,BLUE);
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

   /*circle drawing */
   int x,y,r;
   int d,de,dse;

   //user input
   cout<<"enter the radius";
   cin>>r;
   cout<<"\nenter coordinates of the point";
   cout<<"\n x:";
   cin>>x1;
   cout<<"\n y:";
   cin>>y1;
   cout<<endl;
   setcolor(WHITE);
   circle(x1,y1,r+50);
   x=0;
   y=r;
   d=1-r;
   //dse=(2*x)-(2*y)+5;
   //de=(2*x)+3;


   //drawing the circle


   pixels(x,y);

   while(y>x)
   {
	if(d<0)	    //select e
	d+=(2*x)+3;
	else        //select se
	{
		d+=(2*x)-(2*y)+5;
		y--;
	}
	x++;
	pixels(x,y);
   }
   /* clean up */
   getch();
   closegraph();
   return 0;
}





