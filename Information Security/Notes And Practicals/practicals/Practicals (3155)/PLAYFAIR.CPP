
			     /* PLAYFAIR CIPHER */

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void main()
{
 clrscr();
 char temp[100], c[100], key[100];
 char q[2], k[5][5];
 int b = 0,m = 0,i = 0, j=0,n = 0;

 cout<<"\nEnter the text to encrypt : " ;
 cin.getline(c, 100);

 cout<<"\nEnter the key text : ";
 cin.getline(key, 100);

 cout<<"\n\nKey text without spaces : ";

 //remove spaces from the key text
 while ( i < strlen(key) )
  {
   if(isalpha(key[i]))
    {
     if(key[i] == 'j')            // playfair cipher can have either i or j
      key[i] = 'i';

     key[j] = key[i];
     cout<<key[j++];
     n++;                // length of key text without spaces
    }
   i++;
  }


 //check for repitition of alphabets in key text
 cout<<"\n\nKey text without repetition and spaces : ";
 i = 0;
 while( i < n )
  {
   for( j = i+1; j<n; j++ )
    if(key[i] == key[j])
      key[j] = 0;            //simply assign 0 to multiple occurence


   if ( isalpha (key[i]) )
    {
     temp[b] = key[i];
     cout<<temp[b++];      // b has length of key text without repititions
    }
   i++;

  }


 // temp contains the key text without any repitition and spaces
 cout<<"\n\nThe key matrix is given by : \n\t\t";

 n = 0;
 i = j = 0;

 while(n < b)                  // assign key text to key matrix
  {

       k[i][j%5]=temp[n];
       cout<<k[i][j++%5]<<" ";
       if(j%5==0) {i++; cout<<"\n\t\t";}

   n++;
  }

 m = b;
 int p = 97;

 while(25-b)                   // key matrix have 25 alphabets
  {
   n = 0;

   while(n < m)
    {
     if ( temp[n++] == p || p == 106)  // 106 char value is j
      {
       p++;
       n=0;
      }
    }

   k[i%5][j%5] = p++;

   cout<<k[i%5][j++%5]<<" ";
   if(j%5==0) {i++; cout<<"\n\t\t";}

   b++;
  }


 cout<<"\n\nPlain text after pairing : ";

 b = i = 0;
 int flag = 0;

 while( c[i] )
 { if(isalpha(c[i]))
    {
     if(c[i]=='j') c[i]='i';
     temp[b] = c[i];
     cout<<temp[b++];

     if(c[i] == c[i+1])
      {
       temp[b] = 'x';
       cout<<temp[b++];
      }
    }
   i++;
 }

 if(b%2)                       // add bogus character if odd length
  {
   temp[b] = 'x';
   cout<<temp[b++];
   flag = 1;
  }


 cout<<"\nAfter encryption : ";
 int x= 0, y=0;
 i = j = n = m = 0;

 while (i<b)
 {
  while(temp[i] != k[x][y])
   { y++; if((y%5)==0) {y=0; x++;}}


  i++;

  while(temp[i] != k[j][n])
   { n++; if ((n%5)==0) {n=0;j++;}}


  i++;
  if ( x == j )           // in same row
   {
    c[m++]=k[x][(y+1)%5];
    c[m++]= k[j][(n+1)%5];
   }

  else if (  y == n )     // in same column
       { c[m++]=k[(x+1)%5][y];
	 c[m++]=k[(j+1)%5][n];
       }

       else              // forms a rectangle
	{
	 c[m++]=k[x][n];
	 c[m++]=k[j][y];
	}

  j =0;x=0;y =0;n = 0;
  cout<<c[m-2]<<c[m-1];

 }

 i = 0;m = 0;
 cout<<"\nAfter decryption : ";

 while (i<b)
 {
  while(c[i] != k[x][y])
   { y++; if((y%5)==0) {y=0; x++;}}


  i++;

  while(c[i] != k[j][n])
   { n++; if ((n%5)==0) {n=0;j++;}}


  i++;
  if ( x == j )           // in same row
   {
    if((y-=1)<0) y+=5;
    if((n-=1)<0) n+=5;
    temp[m++]=k[x][y];
    temp[m++]= k[j][n];
   }

  else if (  y == n )     // in same column
       {
	if((x-=1)<0) x+=5;
	if((j-=1)<0) j+=5;
	temp[m++]=k[x][y];
	temp[m++]=k[j][n];
       }

       else              // forms a rectangle
	{
	 temp[m++]=k[x][n];
	 temp[m++]=k[j][y];
	}

  j =0;x=0;y =0;n = 0;
  cout<<temp[m-2]<<temp[m-1];

 }


 getch();
}