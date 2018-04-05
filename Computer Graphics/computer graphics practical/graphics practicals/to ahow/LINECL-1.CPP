#include<iostream.h>
#include<conio.h>
#include<graphics.h>

typedef unsigned int outcode;

enum
{
	TOP = 0X1,
	BOTTOM = 0X2,
	RIGHT = 0X4,
	LEFT = 0X8,
};

int calcode( float, float, float, float, float, float );

void lineclip( float x0, float y0, float x1, float y1, float xwmin, float ywmin, float xwmax, float ywmax )
{
	outcode code0, code1, codeout;
	int accept = 0, done = 0;

	code0 = calcode( x0, y0, xwmin, ywmin, xwmax, ywmax );
	code1 = calcode( x1, y1, xwmin, ywmin, xwmax, ywmax );

	do
	{
		if( ! ( code0 | code1 ) )
		{
			accept = 1;
			done = 1;
		}
		else if( code0 & code1 )
			done = 1;
		else
		{
			float x, y;
			codeout = code0 ? code0 : code1;
			if( codeout & TOP )
			{
			x = x0 + ( x1 - x0 ) * ( ywmax - y0 ) / ( y1- y0 );
				y = ywmax;
			}
			else if( codeout & BOTTOM )
			{
		       x = x0 + ( x1 - x0 ) * ( ywmin - y0 ) / ( y1 - y0 );
				y = ywmin;
			}
			else if( codeout & RIGHT )
		{
		y = y0 + ( y1 - y0 ) * ( xwmax - x0 ) / ( x1 - x0 );
				x = xwmax;
		}
			else
			{
		y = y0 + ( y1 - y0 ) * ( xwmin - x0 ) / ( x1 - x0 );
				x = xwmin;
			}

			if( codeout == code0 )
			{
				x0 = x;
				y0 = y;
				code0 = calcode( x0, y0, xwmin, ywmin, xwmax, ywmax );
			}
			else
			{
				x1 = x;
				y1 = y;
				code1 = calcode( x1, y1, xwmin, ywmin, xwmax, ywmax );
			}
		}
	} while( done == 0 );

	if( accept )
		line( x0, y0, x1, y1 );

	rectangle( xwmin, ywmin, xwmax, ywmax );
	getch( );
}

int calcode( float x, float y, float xwmin, float ywmin, float xwmax, float ywmax )
{
	int code = 0;

	if( y > ywmax )
		code |= TOP;
	else if( y < ywmin )
		code |= BOTTOM;
	else if( x > xwmax )
		code |= RIGHT;
	else if( x < xwmin )
		code |= LEFT;

	return( code );
}

void main( )
{
	clrscr( );
	cout << " \t THIS PROGRAM CLIPS THE LINE USING COHEN SUTHERLAND ALGORITHM ";

	float x1, y1, x2, y2;
	float xwmin, ywmin, xwmax, ywmax;
cout <<"\n\nEnter the x coordinate of first end point of the line: ";
	cin >> x1;
cout << " Enter the y coordinate of first end point of the line:";
	cin >> y1;
	cout << " \n\n Enter the x coordinate of second end point of the line: ";
	cin >> x2;
	cout << " Enter the x coordinate of second end point of the line: ";
	cin >> y2;

	cout << " \n\n Enter xwmin: ";
	cin >> xwmin;
	cout << " Enter ywmin: ";
	cin >> ywmin;
	cout << " Enter xwmax: ";
	cin >> xwmax;
	cout << " Enter ywmax: ";
	cin >> ywmax;

	int gdriver = DETECT, gmode;
	initgraph( &gdriver, &gmode, "..\\BGI" );

	cleardevice( );
	outtextxy( 100, 10, " PROGRAM TO SIMULATE COHEN SUTHERLAND ALGORITHM " );
	line( x1, y1, x2, y2 );
	rectangle( xwmin, ywmin, xwmax, ywmax );
	getch( );
	cleardevice( );

	outtextxy( 100, 10, " CLIPPED LINE " );
	rectangle( xwmin, ywmin, xwmax, ywmax );
	lineclip( x1, y1, x2, y2, xwmin, ywmin, xwmax, ywmax );

	getch( );
	closegraph( );
}

