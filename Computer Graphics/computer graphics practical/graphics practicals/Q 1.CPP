#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<math.h>
class node
{
 public:
	int row,col,data;
	node *next;
	node()
	{
		row=0;
		col=0;
		data=0;
		next=0;
	}
	node(int d, int m, int n, node *next_1)
	{
		data=d;
		row=m;
		col=n;
		next=next_1;
	}
};
class sparsematrix
{
 public:

	node *head, *tail;
	sparsematrix()
	{
		head=0;
		tail=0;
	}
	void addtotail(int a,int row_1,int col_1)
	{
		node *ptr;
		ptr=new node(a,row_1,col_1,0);
		if(tail==0)
		{
			head=tail=ptr;

		}
		else
		{
			tail->next=ptr;
			tail=ptr;

		}
	}
	void display();

};
	void sparsematrix::display()
	{
		node *temp;
		for(temp=head;temp->next!=0;temp=temp->next)
		{
			cout<<"Row:"<<temp->row<<endl;
			cout<<"Column:"<<temp->col<<endl;
			cout<<"Data:"<<temp->data<<endl;
		}
		cout<<"Row:"<<temp->row<<endl;
		cout<<"Column:"<<temp->col<<endl;
		cout<<"Data:"<<temp->data<<endl;
	}
void main()
{
	clrscr();
	int i,j,ch,nr,nc,count=0;
	sparsematrix s,s1,s2,s3;
	int arr[6][6];
	char ans='y';
	do
	{
		clrscr();
		cout<<"\nEnter the number of rows of the 2-D array: ";
		cin>>nr;
		cout<<"\nEnter the number of columns of the 2-D array: ";
		cin>>nc;
		cout<<"\nWhich kind of matrix of matrix do you want to enter?\n1.Regular Matrix\n2.Diagonal Matrix\n3.Lower Triangular Matrix\n4.Tridiagonal Matrix\n5.To exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		 case 1:cout<<"\nEnter the elements of the 2-D array"<<endl;
			for(i=0;i<nr;i++)
			{
				for(j=0;j<nc;j++)
				{
					cin>>arr[i][j];
				}
			}
			for(i=0;i<nr;i++)
			{
				cout<<endl;
				for(j=0;j<nc;j++)
				{
					cout<<arr[i][j]<<"   ";
					if(arr[i][j]!=0)
					count++;
				}
			}

			if(count>((nr*nr)/3))
			{
				cout<<"\n\nThe matrix is dense";
				delay(2000);
				exit(0);
			}

			else
			cout<<"\n\nThe matrix is sparse. It needs to be converted into a linked list to save storage space\n";
			for(i=0;i<nr;i++)
			{
				for(j=0;j<nc;j++)
				{
					if(arr[i][j]!=0)
					{
						s.addtotail(arr[i][j],i,j);
					}
				}
			}
			cout<<"\nThe matrix is"<<endl;
			s.display();
			count=0;
			break;
		 case 2:cout<<"\nEnter the elements of the 2-D array\n";
			for(i=0;i<nr;i++)
			{
				for(j=0;j<nc;j++)
				{
					if(i==j)
					{
						cin>>arr[i][j];
						if(arr[i][j]!=0)
						count++;
					}
					else
					arr[i][j]=0;
				}
			}
			for(i=0;i<nr;i++)
			{
				cout<<endl;
				for(j=0;j<nc;j++)
				{
					cout<<arr[i][j]<<"   ";
				}
			}
			if(count>((nr*nr)/3))
			{
				cout<<"\n\nThe matrix is dense";
				delay(2000);
				exit(0);
			}
			else
			cout<<"\n\nThe matrix is sparse. It needs to be converted into a linked list to save storage space\n";
			for(i=0;i<nr;i++)
			{
				for(j=0;j<nc;j++)
				{
					if(arr[i][j]!=0)
					{
						s1.addtotail(arr[i][j],i,j);
					}
				}
			}
			cout<<"\nThe matrix is"<<endl;
			s1.display();
			count=0;
			break;
		 case 3:cout<<"\nEnter the elements of the 2-D array\n";
			for(i=0;i<nr;i++)
			 {
				for(j=0;j<nc;j++)
				{
					if(i>=j)
					{
						cin>>arr[i][j];
						if(arr[i][j]!=0)
						count++;
					}
					else
					arr[i][j]=0;
				}
			 }
			for(i=0;i<nr;i++)
			{
				cout<<endl;
				for(j=0;j<nc;j++)
				{
					cout<<arr[i][j]<<"   ";
				}
			}

			if(count>((nr*nr)/3))
			{
				cout<<"\n\nThe matrix is dense";
				delay(2000);
				exit(0);
			}

			else
			cout<<"\n\nThe matrix is sparse. It needs to be converted into a linked list to save storage space\n";
			for(i=0;i<nr;i++)
			{
				for(j=0;j<nc;j++)
				{
					if(arr[i][j]!=0)
					{
						s2.addtotail(arr[i][j],i,j);
					}
				}
			}
			cout<<"\nThe matrix is"<<endl;
			s2.display();
			count=0;
			break;
		 case 4: cout<<"Enter the elements of the 2-D array\n";
			 for(i=0;i<nr;i++)
			 {
				for(j=0;j<nc;j++)
				{
					if(i==j||abs(i-j)==1)
					{
						cin>>arr[i][j];
						if(arr[i][j]!=0)
						count++;
					}
					else
					arr[i][j]=0;
				}
			 }
			for(i=0;i<nr;i++)
			{
				cout<<endl;
				for(j=0;j<nc;j++)
				{
					cout<<arr[i][j]<<"   ";

				}
			}

			if(count>((nr*nr)/3))
			{
				cout<<"\n\nThe matrix is dense";
				delay(2000);
				exit(0);
			}
			else
			cout<<"\n\nThe matrix is sparse. It needs to be converted into a linked list to save storage space\n";
			for(i=0;i<nr;i++)
			{
				for(j=0;j<nc;j++)
				{
					if(arr[i][j]!=0)
					{
						s3.addtotail(arr[i][j],i,j);
					}
				}
			}
			cout<<"\nThe matrix is"<<endl;
			s3.display();
			count=0;
			break;
		 case 5: exit(0);
		 }
		 cout<<"Do you want to continue(y/n)?"<<endl;
		 cin>>ans;
	}while(ans=='y');

	getch();
}





