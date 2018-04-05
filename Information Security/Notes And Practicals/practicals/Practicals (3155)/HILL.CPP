// Hill cipher

#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

int gcd ( int a, int b )
 {
  if ( b == 0 )
   return a;

  else
   if ( b == 1 )
    return 1;

   else
    if ( a <= b )
     return gcd ( a, b%a );

    else
     return gcd ( b, a%b );

 }

void main()
{
 clrscr();
 char b[100][2],s[100][2], c[100];
 int o[2][2];
 int i, j, k, det, si = 0, flag = 0;

 cout<<"Enter the string : ";
 cin.getline(c,100);

 for(i=0, j = 0, k = 0; k < strlen(c);)
  {
   if ( isalpha(c[k]) )
    {
     b[i][j++ % 2] = c[k++];
     if(j%2 == 0)
      i++;
     si++;                  // length of the string without special char
    }

   else                       // for spaces or other symbols
    k++;  		      // we will remind positions of the special char

  }

 if ( si % 2 )             // if length of strin without other char is odd
  {                          // add bogus character
   cout<<"\n\n Odd length string. A bogus character added.\n";
   b[i][j] = 'z';
   si++; flag = 1;
  }
 //key matrix is defined below

 o[0][0] = 3;  o[0][1] = 5 ;
 o[1][0] = 3;  o[1][1] = 6;

 det = (o[0][0] * o[1][1] - o[1][0] * o[0][1]) % 26 ;

 cout<<"\nAfter encryption : ";
 for(i = 0, j = 0 ; i < si/2 ; i++ )
  {
   b[i][0] -= 97;
   b[i][1] -= 97;

     s[i][0] = ((b[i][0] * o[0][0] + b[i][1] * o[1][0]) % 26 )+97;
     s[i][1] = ((b[i][0] * o[0][1] + b[i][1] * o[1][1]) % 26 )+97;

   cout<<s[i][0];
   if( flag && i == si/2 - 1 );              // for not showing bogus char
   else
    cout<<s[i][1];
  }

 //inverse of the key matrix
 o[0][0] = 6;  o[0][1] = -5+26;  // if negative then add n value
 o[1][0] = -3+26; o[1][1] = 3;

 if ( gcd(det,26) != 1 )         // determinant should not be coprime
  {
   cout<<"\n\n\tKey matrix is incorrect... Aborting";
   getch();
   exit(0);
  }

 switch(det)
    {
     case 3 : det = 9;
	      break;
     case 5 : det = 21;
	      break;
     case 7 : det = 15;
	      break;
     case 9 : det = 3;
	      break;
     case 11 : det =19;
	       break;
     case 15 : det = 7;
	       break;
     case 17 : det = 23;
	       break;
     case 19 : det = 11;
	       break;
     case 21 : det = 5;
	       break;
     case 23 : det = 17;
	       break;
    }

 cout<<"\n\nAfter decryption : ";

 o[0][0] = (o[0][0] * det) % 26;
 o[0][1] = (o[0][1] * det) % 26;
 o[1][0] = (o[1][0] * det) % 26;
 o[1][1] = (o[1][1] * det) % 26;

 for(i = 0 ; i < si/2 ; i++ )
  {
     s[i][0] -= 97;
     s[i][1] -= 97;
     b[i][0] = ((s[i][0] * o[0][0] + s[i][1] * o[1][0]) % 26 )+97;
     b[i][1] = ((s[i][0] * o[0][1] + s[i][1] * o[1][1]) % 26 )+97;

   cout<<b[i][0];
   if( flag && i == si/2 - 1 );
   else
    cout<<b[i][1];

  }

 getch();
}
