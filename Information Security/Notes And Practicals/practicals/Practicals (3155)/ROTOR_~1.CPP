#include<constrea.h>
#include<string.h>

int i,j,l,k,d;
int a[26]={2,1,5,4,0,3,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,25,24,23};
char inc[50];
char dc[50];


void encrypt(char input[],int l);
void decrypt(char inc[],int l);

int main(){

	clrscr();

	char input[50];

	cout<<"Enter the string : ";
	cin>>input;
	l=strlen(input);

	cout<<"\nEncrypted text is :";
	encrypt(input,l);
	cout<<"\nDecrypted text is :";
	decrypt(inc,l);
	cout<<endl;
	cout<<endl;

	getch();
}


void encrypt(char input[],int l){
		for(i=0;i<l;i++){
		if(i!=0){
			int s=a[0];
			for(k=0;k<25;k++){
				a[k]=a[k+1]-1;
				if(a[k]<0)
					a[k] += 26;
		}
			a[25]=s-1;
			if(a[25]<0)
					a[25] += 26;
		}
		d=int(input[i])-97;
		char c;
	c = char(a[d]+97);
		inc[l-1-i]=c;
		cout<<c;
		}
}


void decrypt(char inc[],int l){

	for(i=0;i<l;i++){


		if(i!=0){
			int s=a[25];
			for(k=25;k>0;k--){
				a[k]=a[k-1]+1;
				if(a[k]>25)
		    a[k]=a[k]%26;
			}
	    a[0]=s+1;
			if(a[k]>25)
		    a[k]=a[k]%26;

		}

		d=int(inc[i])-97;
		for(k=0;k<25;k++){
	    if(a[k]==d)
		break;
		}
	dc[l-1-i]=char(k+97);
       }
	for(int t=0;t<l;t++)
		cout<<dc[t];
}
