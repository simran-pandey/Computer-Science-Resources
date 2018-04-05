#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

void main()
{
 clrscr();
 int key, n;
 char a[100], c[100];
 cout<<"\nEnter the length of the text you want to encrypt :";
 cin>>n;
 cout<<"\nEnter the text you want to encrypt :";
 for (int i = 0; i < n; i++)
  {
   cin>>a[i];
   int l = isalpha(a[i]) || (a[i]==32);
   if (!l)
    return;

  }

 cout<<"\n\nEnter the key that you want to choose from the given list : ";
 cout<<"\n\n\t1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25.";
 cout<<"\nEnter the key : ";
 cin>>key;
 while(!(key%2) || key == 13)
  {
   cout<<"\nYou've entered wrong key, enter it again :";
   cin>>key;
  }

 cout<<"\nEncrypted text :";

   for ( int l = 0; l < n; l++ )
    {
     if(isupper(a[l]))
       {
	c[l] = ( ( a[l] - 64 ) * key ) % 26;
	c[l] += 64;
       }

     else
      if(islower(a[l]))
       {
	c[l] = ( (a[l] - 96) * key ) % 26;
	c[l] += 96;
       }

      else
       c[l] = a[l];
      cout<<c[l];
    }

   cout<<"\n\nDecrypted text : ";
   switch(key)
    {
     case 3 : key = 9;
	      break;
     case 5 : key = 21;
	      break;
     case 7 : key = 15;
	      break;
     case 9 : key = 3;
	      break;
     case 11 : key =19;
	       break;
     case 15 : key = 7;
	       break;
     case 17 : key = 23;
	       break;
     case 19 : key = 11;
	       break;
     case 21 : key = 5;
	       break;
     case 23 : key = 17;
	       break;
    }

   for ( l = 0; l < n; l++ )
    a[l] = c[l];

   for ( l = 0; l < n; l++ )
    {
     if(isupper(a[l]))
       {
	c[l] = ( ( a[l] - 64 ) * key ) % 26;
	c[l] += 64;
       }

     else
      if(islower(a[l]))
       {
	c[l] = ( (a[l] - 96) * key ) % 26;
	c[l] += 96;
       }

      else
       c[l] = a[l];
      cout<<c[l];
    }


   getch();
 }
