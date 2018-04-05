#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main()
{
 clrscr();
 char b[100], c[100];
 int n,j,i;


 cout<<"\nEnter the string : ";
 cin.getline(c,100);
 n = strlen(c);

 char a[26][2] = { {'A','Q'}, {'B','W'}, {'C','E'}, {'D','R'}, {'E','T'}, {'F','P'},
	   {'G','O'}, {'H','I'}, {'I','U'},
	   {'J','Y'}, {'K','A'}, {'L','S'}, {'M','D'}, {'N','F'}, {'O','G'},
	   {'P','L'}, {'Q','K'}, {'R','J'}, {'S','H'}, {'T','Z'}, {'U','X'},
	   {'V','C'}, {'W','V'}, {'X','M'}, {'Y','N'}, {'Z','B'} };

 cout<<"\n\nThe string after encryption is : ";
 for(i =0 ; i<n; i++)
  {
   if(islower(c[i]))
    {
     c[i]=toupper(c[i]);
     for(j=0; j<26; j++)
      {
       if(c[i]==a[j][0])
	b[i] = tolower(a[j][1]);
      }
    }

   else if(isupper(c[i]))
    {
     for(j=0; j<26; j++)
      {
       if(c[i]==a[j][0])
	b[i] = a[j][1];
      }
    }

   else
     b[i] = c[i];
   cout<<b[i];
  }


 cout<<"\n\nAfter decryption : ";
 for ( i = 0; i<n; i++)
  {
   if(islower(b[i]))
    {
     b[i]=toupper(b[i]);
     for(j=0; j<26; j++)
      {
       if(b[i]==a[j][1])
	c[i] = tolower(a[j][0]);
      }
    }

   else if(isupper(b[i]))
    {
     for(j=0; j<26; j++)
      {
       if(b[i]==a[j][1])
	c[i] = a[j][0];
      }
    }

   else
     c[i] = b[i];
  cout<<c[i];
  }


 getch();
}