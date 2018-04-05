#include <graphics.h>
#include<iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

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
   int a[10],i,n;
   cout<<"enter the pattern array"<<endl;

   for(i=0;i<10;i++)
   {
	cout<<i+1<<"=";
	cin>>a[i];
	cout<<endl;
   }

   cout<<"enter the length of the pattern"<<endl;
   cin>>n;
   int x=50;
   int y=50;
   //clrscr();
   for(i=0;i<n;i++)
   {
	if(a[i%10]==1)
	 {
		delay(100);
		putpixel(x+i,y,YELLOW);
		putpixel(x+i,y+5,RED);
		putpixel(x+i,y-5,BLUE);
	 }

   }

   /* clean up */
   getch();
   closegraph();
   return 0;
}

