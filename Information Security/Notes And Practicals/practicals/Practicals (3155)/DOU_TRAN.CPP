#include<conio.h>
#include<iostream.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

char k[20][20], c[50];
int a[20], q = 0, p1 = 0;

void encrypt ( int cl, int n )
 {
  q = 0;
  p1 = 0;
  for(int j= 0 ; j < cl; j++)
   {
    cout<<" ";
    for(int i = 0; i<n; i++)
      {
       c[p1]= k[i][a[q]];
       cout<<c[p1++];
      }
    q++;
   }
 }

void decrypt ( int cl, int n )
 {
  int i;
  q = 0;
  p1 = 0;
  for(int j= 0 ; j < cl; j++)
   {
    for( i = 0; i<n; i++)
       k[i][a[q]] = c[p1++];

    q++;
   }


  for(i=0; i<n; i++)
   for(j= 0; j<cl; j++)
    cout<<k[i][j];

 }

int factors(int n)        // return no. of factors
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
  char c1[50];
  int  j = 0,n=1;

  cout<<"\n\nEnter the string : ";
  cin.getline(c, 50);

  for(int i = 0;  i < strlen(c); i++)
   if(isalpha(c[i]))
     c1[j++] = c[i];                 // j = length of string without spaces

  i = factors(j);          // return no. of factors & array contain factors

  cout<<"\nLength of the string without spaces : "<<j;

  if(i==1)                    // if length is a prime no.
   { cout<<"Length is prime : "<<j;  c1[j++] = 'x';  i = factors(j);}

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

  cout<<"\n\nEnter numbers from 0 to "<<cl-1<<" in any order (NO REPITITION) : ";
  for(i=0; i<cl;i++)
   { cin>>a[i]; }

  cout<<"\nText after encyption : " ;
  cout<<"\nAfter first cycle : ";
  encrypt (cl, n);

  q = 0;
  for( i = 0; i < n; i++ )
   for ( j = 0 ; j < cl; j++ )
    k[i][j] = c[q++];

  cout<<"\nAfter second cycle : ";
  encrypt (cl, n);

  cout<<"\n\nText after decryption : ";
  cout<<"\nAfter reverting first time : ";
  decrypt (cl, n);

  q = 0;
  for( i = 0; i < n; i++ )
   for ( j = 0 ; j < cl; j++ )
    c[q++] = k[i][j];

  cout<<"\nAfter reverting second time : ";
  decrypt(cl, n);

  getch();
 }