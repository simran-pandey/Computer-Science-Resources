#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

void main()
{
 clrscr();
 int key1, key2, n;
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

 cout<<"\n\nEnter key K1 (multiplicative) :";

 cout<<"\n\nEnter the key that you want to choose from the given list : ";
 cout<<"\n\n\t1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25.";
 cout<<"\nEnter the key : ";
 cin>>key1;
 while(!(key1%2) || key1 == 13)
  {
   cout<<"\nYou've entered wrong key, enter it again :";
   cin>>key1;
  }

 cout<<"\nEnter key K2 (additive) : ";
 cin>>key2;

 cout<<"\nEncrypted data : ";

 for(int l = 0; l < n ; l++)
  {
   if(isupper(a[l]))
    {
     c[l] =  ( ( (a[l] - 64 ) * key1) + key2 ) % 26;
     if(c[l]==0)
      c[l] = 90;
     else
      c[l] += 64;
    }

   if(islower(a[l]))
    {
     c[l] =  ( ( (a[l] - 96 ) * key1) + key2 ) % 26;
     if(c[l]==0)
      c[l] = 122;
     else
      c[l] += 96;
    }

   cout<<c[l];
  }

 cout<<"\nDecrypted text : ";
  switch(key1)
    {
     case 3 : key1 = 9;
	      break;
     case 5 : key1 = 21;
	      break;
     case 7 : key1 = 15;
	      break;
     case 9 : key1 = 3;
	      break;
     case 11 : key1 =19;
	       break;
     case 15 : key1 = 7;
	       break;
     case 17 : key1 = 23;
	       break;
     case 19 : key1 = 11;
	       break;
     case 21 : key1 = 5;
	       break;
     case 23 : key1 = 17;
	       break;
    }

 for ( l = 0 ; l < n ; l++)
   a[l] = c[l];

 for(l = 0; l < n ; l++)
  {
   if(isupper(a[l]))
    {
     c[l] =  ( key1 * ( (a[l] - 64 ) - key2 ) ) % 26;
     if (c[l] == 0)
      c[l] = 90;
     else
     c[l] += 64;
    }

   if(islower(a[l]))
    {
     c[l] =  ( key1 * ( (a[l] - 96 ) - key2 )) % 26;
     if(c[l]==0)
      c[l] = 122;
    else
     c[l] += 96;
    }

   cout<<c[l];
  }
  getch();
 }