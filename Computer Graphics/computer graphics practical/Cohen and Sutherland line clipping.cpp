
#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef unsigned int outcode;
enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8 };

outcode comp_Outcode ( double x, double y, double xmin, double xmax, double ymin, double ymax)
 {
  outcode code = 0;

  if ( y > ymax )
   code |= TOP;

  else if ( y < ymin )
   code |= BOTTOM;

  if ( x > xmax )
   code |= RIGHT;

  else if ( x < xmin )
   code |= LEFT;

  return code;
 }

void cohen_lineclipping ( double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax )
 {
  outcode outcode0, outcode1, outcodeout ;
  int accept = 0, done = 0;

  outcode0 = comp_Outcode ( x0, y0, xmin, xmax, ymin, ymax);
  outcode1 = comp_Outcode ( x1, y1, xmin, xmax, ymin, ymax);

  do
   {
    if (!(outcode0 | outcode1))               // trivially accept
     {
      accept = 1;
      done = 1;
     }

    else if ( outcode0 & outcode1 )                // trivially reject
     {
      done = 1;
     }

    else
     {
      /* if some portion of the line lies in the clipping rectangle */

      double x, y;
      outcodeout = outcode0 ? outcode0 : outcode1 ;

      if ( outcodeout & TOP )
       {
	/* clip the line off from the TOP part */
	x = x0 + ( ymax - y0 ) * ( x1 - x0 ) / ( y1 - y0 ) ;
	y = ymax ;
       }

      else if ( outcodeout & BOTTOM )
       {
	/* clip the line off from the BOTTOM part */
	x = x0 + ( ymin - y0 ) * ( x1 - x0 ) / ( y1 - y0 ) ;
	y = ymin ;
       }

      else if ( outcodeout & LEFT )
       {
	/* clip the line off from the LEFT part */
	y = y0 + ( xmin - x0 ) * ( y1 - y0 ) / ( x1 - x0 );
	x = xmin;
       }

      else
       {
	/* clip the line off from the RIGHT part */
	y = y0 + ( xmax - x0 ) * ( y1 - y0 ) / ( x1 - x0 );
	x = xmax ;
       }


      /* now we move outside pt. to intersection point to clip */

      if ( outcodeout == outcode0 )
       {
	x0 = x;
	y0 = y;
	outcode0 = comp_Outcode ( x0, y0, xmin, xmax, ymin, ymax );
       }

      else
       {
	x1 = x;
	y1 = y;
	outcode1 = comp_Outcode ( x1, y1, xmin, xmax, ymin, ymax );
       }

     }

   }
    while ( done == 0 );

  if ( accept )
   line ( x0, y0, x1, y1 );

 }
  /* end of function cohen_lineclipping */

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   double x0, x1, y0, y1, xmin, ymin, xmax, ymax;

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

   cout<<"\n Enter the start and end pt. of the line : ";
   cout<<"\n Enter first coordinate : ";
   cin>> x0 >> y0 ;

   cout<<"\n Enter second coordinate : ";
   cin>> x1 >> y1 ;

   cout<<"\n\n Enter the coodinates of the clipping rectangle : ";
   cout<<"\n Enter (xmin, ymin) : " ;
   cin>> xmin >> ymin;

   cout<<"\n Enter (xmax, ymax) : " ;
   cin>> xmax >> ymax;

   /* drawing the clipping rectangle */
   line ( xmin, ymin, xmax, ymin );
   line ( xmin, ymin, xmin, ymax );
   line ( xmin, ymax, xmax, ymax );
   line ( xmax, ymin, xmax, ymax );

   /* clipping the line with the help of clipping rectangle */
   cohen_lineclipping ( x0, y0, x1, y1, xmin, xmax, ymin, ymax);

   /* drawing the line without clipping */
   setcolor ( 10 );
   line ( x0+50, y0, x1+50, y1);

   /* clean up */
   getch();
   closegraph();
   return 0;
}