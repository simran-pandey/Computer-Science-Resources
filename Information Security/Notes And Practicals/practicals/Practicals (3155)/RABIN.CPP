#include<iostream.h>
#include<dos.h>
#include<string.h>
#include<math.h>
#include<conio.h>

class Rbn
{
	private:
		int i,j,len,key,n,p,q,a1,a2,b1,b2,C,P;
	public:
		void rabin_key_generation();
		void rabin_encryption();


		int multiplicative_inverse(int r1,int r2,int n);
		int chinese_remainder_theorem(int a,int b,int p,int q);
		void rabin_decryption();



};
void Rbn::rabin_key_generation()
{
	cout<<"Enter any two PRIME no. of form 4*k+3 (k any integer) : ";
	cin>>p>>q;
	n=p*q;
	cout<<"Private keys : "<<p<<" and "<<q<<endl;
	cout<<"Public key : "<<n<<endl;

}

void Rbn::rabin_encryption()
{
	 cout<<"\nEnter any integer to be encrypted : ";
	 cin>>P;
	C=(P*P)%n;
	 cout<<"\n\n Using p^2 mod n encrypted integer : "<<C<< endl;
	 getch();

}
void Rbn::rabin_decryption()
{
	int P1,P2,P3,P4;
	int temp1,temp2,temp3;
	 cout<<"\nValue of C  p  q : "<<C<<" "<<p<<" "<<q<<" "<< endl<<endl;
	temp1=C % p;
	temp2=(p+1)/4;
	temp3=pow(temp1,temp2);
	cout<<"Value of temp1 temp2 temp3 : "<<temp1<<" "<<temp2<<" "<<temp3<<endl<< endl;
	a1=+(temp3 % p);
	a2=-(temp3 % p);
	a2=a2+p;

	temp1=C%q;
	temp2=(q+1)/4;
	temp3=pow(temp1,temp2);
	cout<<"Value of temp1 temp2 temp3 : "<<temp1<<"   "<<temp2<<"   "<<temp3<<endl<< endl;
	b1=+(temp3 % q);
	b2=-(temp3 % q);
	b2=b2+q;
	cout<<"Value of a1 a1 b1 b2 : "<<a1<<"  "<<a2<<"  "<<b1<<"  "<<b2<< endl<<endl;

	getch();
	cout<<"Calculating possible values through Chinese theorem : " <<endl;
	cout<<"\nUsing extended Euclidean algo for finding \nthe multiplicative inverse used in Chinese theorem "<<endl;

	P1=chinese_remainder_theorem(a1,b1,p,q) % n;
	P2=chinese_remainder_theorem(a1,b2,p,q) % n;
	P3=chinese_remainder_theorem(a2,b1,p,q) % n;
	P4=chinese_remainder_theorem(a2,b2,p,q) % n;

	cout<<" Four possible decrypted nos are : "<<P1<<"   "<<P2<<"   "<<P3<<"   "<<P4;
	cout<<"\n\n NOTE :  On the basis of what value could be sent through encryption,\n one value from above four values is chosen ...!!!! ";

	getch();
}
int Rbn::multiplicative_inverse(int r1,int r2,int n)
{

	int r,q,t1,t2,t;
	t1=0;
	t2=1;

	while(r2>0)
    {
      q=r1/r2;

     r=r1-q*r2;
     r1=r2;
     r2=r;

     t=t1-q*t2;
     t1=t2;
     t2=t;
   }
	if(t1<0){t1=t1+n;}
    t1=t1 % n;
	return t1;
}
int Rbn::chinese_remainder_theorem(int a,int b,int p,int q)
{
	int M,M1,M2,y1,y2,X;
	M=p*q;
	M1=M/p;
	M2=M/q;
	cout<<"Value of M M1 M2 : "<<M<<" "<<M1<<" "<<M2<< endl<<endl;

	y1=multiplicative_inverse(p,M1,p);
	y2=multiplicative_inverse(q,M2,q);
	cout<<"Value of y1 y2 : "<<y1<<" "<<y2<< endl<<endl;
	X=a*M1*y1+b*M2*y2;
	return X;

}

void main()
{
	clrscr();
	Rbn b;
	b.rabin_key_generation();
	b.rabin_encryption();
	b.rabin_decryption();
	getch();

}