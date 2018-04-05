#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

class Enigma
{
 private:
  int R3[26],R2[26],R1[26],RB[26];
  int ctr3,ctr2;//counter for no. of rotations done for R3,2.after 26rot of R3 rotate R2,after 26rot of R2 rotate R1.
  char getMappingRB(char ch);
  char getMappingR3(char ch);
  char getInvMappingR3(char ch);
  char getMappingR2(char ch);
  char getInvMappingR2(char ch);
  char getMappingR1(char ch);
  char getInvMappingR1(char ch);
  void rotate();
  void rotateRotorBy1(int *R);
  void setInitialRotorSettings(char ch3,char ch2,char ch1);
 public:
  Enigma()
  {
   ctr3=0;ctr2=0;
   //AY BR CU DH EQ FS GL IP JX KN MO TZ VW   ->Reflector B
   RB[0]=24;RB[24]=0; RB[1]=17;RB[17]=1; RB[2]=20;RB[20]=2;  RB[3]=7;RB[7]=3;
   RB[4]=16;RB[16]=4; RB[5]=18;RB[18]=5; RB[6]=11;RB[11]=6; RB[8]=15;RB[15]=8;
   RB[9]=23;RB[23]=9; RB[10]=13;RB[13]=10; RB[12]=14;RB[14]=12; RB[19]=25;RB[25]=19;
   RB[21]=22;RB[22]=21;
/*
   //R3-> B,D,F,H,J,L,C,P,R,T,X,V,Z,N,Y,E,I,W,G,A,K,M,U,S,Q,O
   //     1,3,5,7,9,11,2,15,17,19,23,21,25,13,24,4,8,22,6,0,10,12,20,18,16
   R3[0]=1; R3[1]=3; R3[2]=5; R3[3]=7; R3[4]=9; R3[5]=11; R3[6]=2;
   R3[7]=; R3[8]; R3[9]=; R3[10]=; R3[11]=; R3[12]=;  R3[13]=;
   R3[14]=; R3[15]=; R3[16]=; R3[17]=; R3[18]=; R3[19]=; R3[20]=;
   R3[21]=; R3[22]=; R3[23]=; R3[24]=; R3[25]=;
*/
   char R3Spec[]="bdfhjlcprtxvznyeiwgakmusqo";
   char R2Spec[]="ajdksiruxblhwtmcqgznpyfvoe";
   char R1Spec[]="ekmflgdqvzntowyhxuspaibrcj";
   for(int i=0;i<26;i++)
   {
    R3[i]=R3Spec[i]-97;
   }
   for(i=0;i<26;i++)
   {
    R2[i]=R2Spec[i]-97;
   }
   for(i=0;i<26;i++)
   {
    R1[i]=R1Spec[i]-97;
   }
   cout<<"\nEnter Initial Rotor Settings(R1,R2,R3): ";
   char ch1,ch2,ch3;
   cin>>ch1>>ch2>>ch3;
   setInitialRotorSettings(ch3,ch2,ch1);
/*
 cout<<"\nRotors mapping after settings:";
 cout<<"\nR3:";
 for(i=0;i<26;i++)
  cout<<(char)(R3[i]+97);
 cout<<"\nR2:";
 for(i=0;i<26;i++)
  cout<<(char)(R2[i]+97);
 cout<<"\nR1:";
 for(i=0;i<26;i++)
  cout<<(char)(R1[i]+97);
*/
  }
  void encrypt(char *msg);
  void decrypt(char* cipher);
};


char Enigma::getMappingRB(char ch)
{
 return (char)(RB[ch-97]+97);
}
char Enigma::getMappingR3(char ch)
{
 return (char)(R3[ch-97]+97);
}
char Enigma::getInvMappingR3(char ch)
{
 char ch1='\0';
 for(int i=0;i<26;i++)
 {
  if(R3[i]==(int)(ch-97))
  {
   ch1=(char)(i+97);
   break;
  }
 }
 return ch1;
}
char Enigma::getMappingR2(char ch)
{
 return (char)(R2[ch-97]+97);
}
char Enigma::getInvMappingR2(char ch)
{
 char ch1='\0';
 for(int i=0;i<26;i++)
 {
  if(R2[i]==(int)(ch-97))
  {
   ch1=(char)(i+97);
   break;
  }
 }
 return ch1;
}
char Enigma::getMappingR1(char ch)
{
 return (char)(R1[ch-97]+97);
}
char Enigma::getInvMappingR1(char ch)
{
 char ch1='\0';
 for(int i=0;i<26;i++)
 {
  if(R1[i]==(int)(ch-97))
  {
   ch1=(char)(i+97);
   break;
  }
 }
 if(ch1=='\0')
 {
  cout<<"\nError!";
  getch();
  exit(0);
 }
 return ch1;
}
void Enigma::rotate()
{
/* cout<<"\nRotors mapping before rotation:";
 cout<<"\nR3:";
 for(int i=0;i<26;i++)
  cout<<(char)(R3[i]+97);
 cout<<"\nR2:";
 for(i=0;i<26;i++)
  cout<<(char)(R2[i]+97);
 cout<<"\nR1:";
 for(i=0;i<26;i++)
  cout<<(char)(R1[i]+97);
  */
 rotateRotorBy1(R3);
 ctr3=(ctr3+1)%26;
 if(ctr3==0)//rotateR2, R3 completed 26 rotations
 {
  rotateRotorBy1(R2);
  ctr2=(ctr2+1)%26;
  if(ctr2==0)//rotate R1,  R2 completed its 26 rotations
  {
   rotateRotorBy1(R1);
  }
 }
 /*
 cout<<"\nRotors mapping after rotation:";
 cout<<"\nR3:";
 for(i=0;i<26;i++)
  cout<<(char)(R3[i]+97);
 cout<<"\nR2:";
 for(i=0;i<26;i++)
  cout<<(char)(R2[i]+97);
 cout<<"\nR1:";
 for(i=0;i<26;i++)
  cout<<(char)(R1[i]+97);
  */
}
void Enigma::rotateRotorBy1(int *R)
{
 int temp[26];
 for(int i=0;i<26;i++)
 {
  temp[i]=(i+((R[(i-1+26)%26]-((i-1+26)%26))+26)%26)%26; //moving wiring downwards Or say moving chars upward A->B,B->C
 }
 for(i=0;i<26;i++)
 {
  R[i]=temp[i];
 }
}

void Enigma::setInitialRotorSettings(char ch3,char ch2,char ch1)
{
 for(int i=0;i<(int)(ch3-97);i++)        //initial is A if requested setting is C then rotate wiring downwards 2 times
  rotateRotorBy1(R3);
 for(i=0;i<((int)ch2-97);i++)
  rotateRotorBy1(R2);
 for(i=0;i<(int)(ch1-97);i++)
  rotateRotorBy1(R1);
}

void Enigma::encrypt(char* msg)
{
 char ch;//temp
 for(int i=0;i<strlen(msg);i++)
 {
  ch=msg[i];
  ch=getMappingR3(ch);
  ch=getMappingR2(ch);
  ch=getMappingR1(ch);
  ch=getMappingRB(ch);
  ch=getInvMappingR1(ch);
  ch=getInvMappingR2(ch);
  ch=getInvMappingR3(ch);
  msg[i]=ch;
  rotate();//rotating after encrypting 1 letter
 }
}
void Enigma::decrypt(char* cipher)
{
  encrypt(cipher);
}


void main()
{
clrscr();
cout<<"\n(Dealing wit lowercase chars only)\n";
cout<<"\n****Enigma Machine Implementation****";
cout<<"\nEncryption Demo:\n";
Enigma Sender;
cout<<"\nEnter message: ";
char *msg;
gets(msg);
cout<<"\nEncrypted Text: ";
Sender.encrypt(msg);
puts(msg);

cout<<"\nDecryption Demo(use same initial rotor settings to decrypt above encrypted text):\n";
Enigma Reciever;
cout<<"\nEnter Cipher Text: ";
char* cipher;
gets(cipher);
cout<<"\nDecrypted Text: ";
Reciever.decrypt(cipher);
puts(cipher);

getch();
}