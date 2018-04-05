// stream cipher

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main()
{
 clrscr();
 int i,k[100],c[100];
 char a[100];
 cout << "\nEnter the string as bit stream : ";
 cin.getline(a,100);

  cout<<"\n\n\t\tKey : ";
 for(i=0; i < strlen(a) ;i++)
  {
   k[i] = rand()%2;
   cout<<k[i];
  }

 cout<<"\nAfter encryption : ";
 for(i=0; i < strlen(a) ;i++)
  {
   c[i] = (int(a[i]) + k[i]) % 2;
   cout<<c[i];
  }

  cout<<"\n\n\t\tKey : ";
 for(i=0; i < strlen(a) ;i++)
  cout<<k[i];

 cout<<"\nAfter decryption : ";

 for(i=0; i < strlen(a) ;i++)
  {
   c[i] = (c[i] + k[i]) % 2;
   cout<<c[i];
  }

 getch();
}