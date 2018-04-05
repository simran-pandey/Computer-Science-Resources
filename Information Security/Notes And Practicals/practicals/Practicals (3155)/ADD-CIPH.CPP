//additive cipher

# include <iostream.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

void main()
{
 clrscr();
 int i,k;
 char d[100], c[100], a[100];
 cout << "\nEnter the string : ";
 cin.getline(a,100);
 cout << "\nEnter the key : ";
 cin >> k;

 cout<<"\nAfter encryption : ";
 for(i=0; i < strlen(a) ;i++)
  {
   if(isalpha(a[i]))
    {
     if(isupper(a[i]))
       c[i] = ((( a[i] - 65)+k)%26)+65;
     else
       c[i] = (((a[i] - 97)+k)%26)+97;
    }

   else
    c[i] = a[i];
   cout<<c[i];
  }

 cout<<"\nAfter decryption : ";

 for(i=0; i < strlen(a) ;i++)
  {
   if(isalpha(c[i]))
    {
     if(isupper(c[i]))
       d[i] = ((((c[i] - 65)-k)+26)%26)+65;
     else
       d[i] = ((((c[i] - 97)-k)+26)%26)+97;
    }

   else
     d[i] = c[i];

   cout<<d[i];
  }

 getch();
}
