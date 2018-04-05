#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
int in[6];

	//program for 2-dimensional transformation  of triangles
void translate(int in[])
{       int out[6];
	int tx,ty,i,j,k=0;
	cout<<"enter the distance on x axis";
	cin>>tx;
	cout<<"enter the distance on y axis";
	cin>>ty;
	int t[9]={1,0,tx,0,1,ty,0,0,1};
	int c=0;
	for(i=0;i<6;)
	{      int a[3];
		a[0]=in[i];
		a[1]=in[i+1];
		a[2]=1;
		c=0;
		for(j=0;j<2;j++)
		{       out[i]=0;
			for(k=0;k<3;k++)
			{
				out[i]+=t[c++]*a[k];
			}
		      //	cout<<out[i]<<" ";
			i++;
		}
	}

	for(i=0;i<6;i++)
	{
		in[i]=out[i];
		cout<<out[i]<<" "<<in[i];
	}


}

void rotate(int in[])
{       int out[6];
	double x;
	int a;
	cout<<"enter the angle by which you want to rotate the triangle"<<endl;
	cin>>a;
	x=a*(0.0174);
	cout<<cos(x)<<" "<<sin(x)<<endl;
     //	delay(5000);
	float t[9]={cos(x),-sin(x),0,sin(x),cos(x),0,0,0,1};
	int c=0;
	for(int i=0;i<6;)
	{

		int a[3];
		a[0]=in[i];
		a[1]=in[i+1];
		a[2]=1;
		c=0;
		for(int j=0;j<2;j++)
		{       out[i]=0;
			for(int k=0;k<3;k++)
			{

				out[i]+=t[c++]*a[k];
				cout<<out[i]<<"+"<<t[c-1]<<"X"<<a[k]<<endl;
			}
			cout<<"out["<<i<<"]="<<out[i]<<" ";
			i++;
		}

	}
		getch();
	for(i=0;i<6;i++)
	{
		in[i]=out[i];
		//cout<<out[i]<<" "<<in[i];
	}




}
void scale(int in[])
{
	int out[6];
	int sx,sy;
	cout<<"enter the distance on x axis";
	cin>>sx;
	cout<<"enter the distance on y axis";
	cin>>sy;
	int t[9]={sx,0,0,0,sy,0,0,0,1};
	int c=0;
	for(int i=0;i<6;)
	{

		int a[3];
		a[0]=in[i];
		a[1]=in[i+1];
		a[2]=1;
		c=0;
		for(int j=0;j<2;j++)
		{       out[i]=0;
			for(int k=0;k<3;k++)
			{
				out[i]+=t[c++]*a[k];
			}
		  //	cout<<"out["<<i<<"]="<<out[i]<<" ";
			i++;
		}
	}

	for(i=0;i<6;i++)
	{
		in[i]=out[i];
		//cout<<out[i]<<" "<<in[i];
	}


}
void reflex(int in[])
{
	int out[6],i,x,y;
	char ch;
	cout<<"enter the axis(x or y)along which you want to reflect the triangle"<<endl;
	cin>>ch;


	if(ch=='x')
	{
		x=1;
		y=-1;
	}
	else if(ch=='y')
	 {  x=-1;
	    y=1;
	 }
	int t[9]={x,0,0,0,y,0,0,0,1};
	int c=0;
	for(i=0;i<6;)
	{

		int a[3];
		a[0]=in[i];
		a[1]=in[i+1];
		a[2]=1;
		c=0;
		for(int j=0;j<2;j++)
		{       out[i]=0;
			for(int k=0;k<3;k++)
			{
				out[i]+=t[c++]*a[k];
			}
		  //	cout<<"out["<<i<<"]="<<out[i]<<" ";
			i++;
		}
	}

	for(i=0;i<6;i++)
	{
		in[i]=out[i];
		//cout<<out[i]<<" "<<in[i];
	}





}

int main(void)
{
 clrscr();
 //int in[6];
 int i,j;
 int copy[6];
 //taking input
 for(i=0;i<6;i++)
 {


	      if(i%2==0){
	      cout<<"x:";
	      cin>>in[i];}

	      else{
	      cout<<"y:";
	      cin>>in[i];}
	      copy[i]=in[i];

 }
 int c;
 cout<<"press 1 to translate \n";
 cout<<"press 2 to rotate \n";
 cout<<"press 3 to scale \n";
 cout<<"press 4 to reflect\n";
 cin>>c;
 switch(c)
 {
	case 1: translate(in);
		break;
	case 2: rotate(in);
		break;
	case 3: {cout<<"entering scaling function\n";
		scale(in);
		break;    }
	case 4: reflex(in);
		break;
 }
 cout<<"back from scaling f()"<<endl;
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

setcolor(BLUE);
if(c==1||c==3)
{
copy[6]=copy[0];
copy[7]=copy[1];
//before transformation
for(i=0;i<6;i+=2)
{
 line(copy[i],copy[i+1],copy[i+2],copy[i+3]);

}
getch();
//after transformation
setcolor(RED);
in[6]=in[0];
in[7]=in[1];
//cout<<in[0]<<" "<<in[1]<<" "<<in[2]<<" "<<in[3]<<" "<<in[4]<<" "<<in[5]<<in[6]<<" "<<in[7]<<endl;
//getch();
for(i=0;i<6;i+=2)
{
 //cout<<in[i]<<" "<<in[i+1]<<endl;
 line(in[i],in[i+1],in[i+2],in[i+3]);


}
}
else
{
	int m=getmaxx();
	int n=getmaxy();
	cout<<m<<" "<<n<<endl;
	m=m/2;
	n=n/2;
	cout<<m<<" "<<n<<endl;
	setcolor(WHITE);
	line(m,0,m,getmaxy());
	line(0,n,getmaxx(),n);
	setcolor(BLUE);
	copy[6]=copy[0];
	copy[7]=copy[1];
	//before transformation
	for(i=0;i<6;i+=2)
	{//   cout<<copy[i]+m<<" "<<copy[i+1]+n<<endl;
		 line(copy[i]+m,copy[i+1]+2*n,copy[i+2]+m,copy[i+3]+2*n);

	}

	setcolor(GREEN);
	getch();
	in[6]=in[0];
	in[7]=in[1];

	//after transformation
	for(i=0;i<6;i+=2)
	{
	  //cout<<in[i]<<" "<<in[i+1]<<endl;
	  line(in[i]+m,in[i+1]+2*n,in[i+2]+m,in[i+3]+2*n);
	}

}
 /* clean up */
getch();
closegraph();


return 0;
}
