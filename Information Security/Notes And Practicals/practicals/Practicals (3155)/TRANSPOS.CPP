#include<conio.h>
#include<iostream.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int factors(int a[], int n)        // return no. of factors
 {
  int j = 0, i = 2;

    while(i<=n)
     if(n%i==0) {a[j++] = i; n/=i;}  // j has no. of factors
     else i++;

  return j ;
 }

void main()
 {
  clrscr();
  char c[50], c1[50], k[7][7];
  int a[20], j = 0,n=1;
  cout<<"\nEnter the string : ";
  cin.getline(c, 50);

  for(int i = 0;  i < strlen(c); i++)
   if(isalpha(c[i]))
     c1[j++] = c[i];                 // j = length of string without spaces

  i = factors(a, j);          // return no. of factors & array contain factors

  cout<<"\nLength of the string without spaces : "<<j;

  if(i==1)                    // if length is a prime no.
   { cout<<"Length is prime : "<<j;  c1[j++] = 'x';  i = factors(a,j);}

  int q=0;
  for( j = 0 ; j<(i-1); j++)
   n*=a[j];                   // rows = n (factors except last)

  int b, cl = a[j];			      // columns = last factor

  cout<<"\nMatrix with "<<n<<" rows and "<<a[j]<<" cols : ";

  for(i= 0 ; i < n; i++)
   {cout<<"\n\t\t\t";
    for(j = 0; j<cl; j++)
     {
      k[i][j] = c1[q++];
      cout<<k[i][j]<<" ";
     }
   }

  cout<<"\n\nEnter numbers from 0 to "<<cl-1<<" in any order (no repetition) : ";
  for(i=0; i<cl;i++)
   { cin>>a[i]; }

  cout<<"\nText after encyption : " ;
  char k1[7][7];

  q = 0;
  for(j= 0 ; j < cl; j++)
   {
    cout<<" ";
    for(i = 0; i<n; i++)
      {
       k1[i][j] = k[i][a[q]];
       cout<<k1[i][j];
      }
    q++;
   }

  cout<<"\n\nText after decryption : ";
  q = 0;
  for(j= 0 ; j < cl; j++)
   {
    for(i = 0; i<n; i++)
       k[i][a[q]] = k1[i][j];

    q++;
   }


  for(i=0; i<n; i++)
   for(j= 0; j<cl; j++)
    cout<<k[i][j];

  getch();
 }