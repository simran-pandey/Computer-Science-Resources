#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main()
{
 clrscr();
 char b[100], c[100], o[100];
 int n,j,i,m,k;
 m = 1000;

 cout<<"\nEnter the string : ";
 cin.getline(c,100);
 n = strlen(c);

 while(m>n)
  {
   cout<<"\n\nEnter the key : ";
   cin.getline(b,100);
   m = strlen(b);
  }

 cout<<"\n\nEncrypted text : ";

 for( i = 0, j= 0; i < n ; i++ )
  {
   if (islower(c[i]))
     {
      o[i] = ( (c[i] + tolower(b[j%m]) - 2*96 ) % 26 ) + 96;
      if ( o[i] == 96)
       o[i] = 122;
     }
   else
     if (isupper(c[i]))
       {
	o[i] = ( (c[i] + toupper(b[j%m]) - 2*64 ) % 26 ) + 64;
	if ( o[i] == 64 )
	 o[i] = 90;
	}
   else
     {
      o[i] = c[i];
      j--;
     }
   cout<<o[i];
   j++;

  }

  cout<<"\n\nDecrypted text : ";
  for ( i = 0, j = 0; i < n ; i++)
   {
    if (islower(o[i]))
     {
      if ( (k = o[i] - tolower(b[j%m]) ) < 0)

       c[i] = (( k + 26 ) % 26 ) + 96;
      else
       c[i] = ( k % 26 ) +96;
      if ( c[i] == 96)
       c[i] = 122;
     }

    else
     if (isupper(o[i]))
       {
	if ( o[i] >= toupper(b[j%m]) )
	 c[i] = ( (o[i] - toupper(b[j%m]) ) % 26 ) + 64;
	else
	 c[i] = ( (-o[i] + toupper(b[j%m]) ) % 26 ) + 64;
	if ( c[i] == 64 )
	 c[i] = 90;
	}
     else
      {
       c[i] = o[i];
       j--;
      }

    cout<<c[i];
    j++;
  }

 getch();
}