#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int poly[100],xmin,xmax,ymin,ymax,n;

	   /*left clipping*/

void left_clip(int xmin,int ymin,int xmax,int ymax)
{
  int temp[100],i,j=0,count=0,x1,y1,x2,y2;
  for(i=0;i<2*n;i+=2)
   {
	 x1 = poly[i];
	 y1 = poly[i+1];
	 x2 = poly[i+2];
	 y2 = poly[i+3];
	 if(x1<xmin && x2<xmin)
	   {
	  //both points outside. Do not store any vertices
	   }
	 else if(x1>=xmin && x2>=xmin)
	   {
	 //both points inside. Store second vertex
	 temp[j] = x2;
	 temp[j+1] = y2;
	 j+=2;
	 count++;
	   }
	 else if(x1<xmin && x2>=xmin)
	  {
	 //outside to inside. Store intersection and second vertex
	 int x=xmin;
	 int y= y1 + (xmin-x1)*(float)(y2-y1)/(x2-x1);
	 temp[j]=x;
	 temp[j+1]=y;
	 temp[j+2]=x2;
	 temp[j+3]=y2;
	 j+=4;
	 count+=2;
	   }
	 else
	   {
	  //inside to outside. Store intersection only
	  int x=xmin;
	  int y= y1 + (xmin-x1)*(float)(y2-y1)/(x2-x1);
	  temp[j] = x;
	  temp[j+1] = y;

	  j+=2;
	  count++;
	}
   }
  n=count;
  //store 1st vertex as last
  temp[j]=temp[0];
  temp[j+1]=temp[1];

  for(i=0;i<2*(n+1);i++)
	{
	 poly[i]=temp[i];
       }
}

		   /*right clipping*/

void right_clip(int xmin,int ymin,int xmax,int ymax)
{
  int temp[100],i,j=0,count=0,x1,y1,x2,y2;
  for(i=0;i<2*n;i+=2)
   {
	 x1 = poly[i];
	 y1 = poly[i+1];
	 x2 = poly[i+2];
	 y2 = poly[i+3];

	if(x1>xmax && x2>xmax)
	  {
	 //both points outside. Do not store any vertices
	  }
	  if(x1<=xmax && x2<=xmax)
	  {
	 //both points inside. Store second vertex
	 temp[j] = x2;
	 temp[j+1] = y2;
	 j+=2;
	 count+=1;
	   }
	 else if(x1>xmax && x2<=xmax)
	   {
	 //outside to inside. Store intersection n second vertex
	 int x=xmax;
	 int y= y1 + (xmax-x1)*(float)(y2-y1)/(x2-x1);
	 temp[j]=x;
	 temp[j+1]=y;
	 temp[j+2]=x2;
	 temp[j+3]=y2;
	 j+=4;
	 count+=2;
	}
	  else
	{
	  //inside to outside. Store intersection only
	  int x=xmax;
	  int y= y1 + (xmax-x1)*(float)(y2-y1)/(x2-x1);
	  temp[j] = x;
	  temp[j+1] = y;
	  j+=2;
	  count+=1;
	}
   }
  n=count;
  //store 1st vertex as last
  temp[j]=temp[0];
  temp[j+1]=temp[1];

  for(i=0;i<2*(n+1);i++)
 {
   poly[i]=temp[i];
 }

}


		 /*bottom clipping*/

void bottom_clip(int xmin,int ymin,int xmax,int ymax)
{
  int temp[100],i,j=0,count=0,x1,y1,x2,y2;
  for(i=0;i<2*n;i+=2)
   {
	  x1 = poly[i];
	  y1 = poly[i+1];
	  x2 = poly[i+2];
	  y2 = poly[i+3];
	  if(y1<ymin && y2<ymin)
	   {
	 //both points outside. Do not store any vertices
	   }
	  else if(y1>=ymin && y2>=ymin)
	   {
	 //both points inside. Store second vertex
	 temp[j] = x2;
	 temp[j+1] = y2;
	 j+=2;
	 count++;
	   }
	  else if(y1<ymin && y2>=ymin)
	   {
	 //outside to inside. Store intersection n second vertex
	 int x= x1 +(float)((ymin-y1)*(x2-x1))/(y2-y1);
	 int y= ymin;
	 temp[j]=x;
	 temp[j+1]=y;
	 temp[j+2]=x2;
	 temp[j+3]=y2;
	 j+=4;
	 count+=2;
	   }
	  else
	   {
	 //inside to outside. Store intersection only
	 int x= x1 +(float)((ymin-y1)*(x2-x1))/(y2-y1);
	 int y= ymin;
	 temp[j] = x;
	 temp[j+1] = y;
	 j+=2;
	 count++;
	   }
	}
  n=count;
  //store 1st vertex as last
  temp[j]=temp[0];
  temp[j+1]=temp[1];

  for(i=0;i<2*(n+1);i++)
  {poly[i]=temp[i];
  }
}

	   /*top clipping*/

void top_clip(int xmin,int ymin,int xmax,int ymax)
{
  int temp[100],i,j=0,count=0,x1,y1,x2,y2;
  for(i=0;i<2*n;i+=2)
   {
	   x1 = poly[i];
	   y1 = poly[i+1];
	   x2 = poly[i+2];
	   y2 = poly[i+3];
	   if(y1>ymax && y2>ymax)
	{
	  //both points outside. Do not store any vertices
	}
	   else if(y1<=ymax && y2<=ymax)
	{
	  //both points inside. Store second vertex
	  temp[j] = x2;
	  temp[j+1] = y2;
	  j+=2;
	  count++;
	}
	   else if(y1>ymax && y2<=ymax)
	{
	  //outside to inside. Store intersection n second vertex
	  int x= x1 + (ymax-y1)*(float)(x2-x1)/(y2-y1);
	  int y= ymax;
	  temp[j]=x;
	  temp[j+1]=y;
	  temp[j+2]=x2;
	  temp[j+3]=y2;
	  j+=4;
	  count+=2;
	}
	   else
	{
	  //inside to outside. Store intersection only
	  int x= x1 + (ymax-y1)*(float)(x2-x1)/(y2-y1);
	  int y= ymax;
	  temp[j] = x;
	  temp[j+1] = y;
	  j+=2;
	  count++;
	}
	 }
  n=count;
  //store 1st vertex as last
  temp[j]=temp[0];
  temp[j+1]=temp[1];

  for(i=0;i<2*(n+1);i++)
  {
	poly[i]=temp[i];
  }
}
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
   int i;
   setcolor(RED);
   xmin=200;
   ymin=200;
   xmax=300;
   ymax=300;
   //cout<<"Enter bottom left and top right co-ordinates of window: ";
  // cin>>xmin>>ymin>>xmax>>ymax;
  rectangle(200,200,300,300);
   cout<<"Enter the no. of vertices: ";
   cin>>n;
   for(i=0;i<2*n;i+=2)
   {
     cout<<"Enter co-ordinates of vertex "<<(i/2+1)<<": ";
     cin>>poly[i]>>poly[i+1];
   }
    //store 1st vertex as last
    setcolor(YELLOW);
   poly[2*n]=poly[0];
   poly[2*n+1]=poly[1];
   drawpoly(n+1,poly);

   left_clip(xmin,ymin,xmax,ymax);
   right_clip(xmin,ymin,xmax,ymax);
   bottom_clip(xmin,ymin,xmax,ymax);
   top_clip(xmin,ymin,xmax,ymax);

   cout<<"after clipping"<<endl;
   setcolor(BLUE);
   drawpoly(n+1,poly);
      /* clean up */
   getch();
   closegraph();
   return 0;
}

