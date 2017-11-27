#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <time.h>
const c=10;
void inputa(int a[ ]);
void outputa(int a[ ]);
void dosort(int a[ ]);
void swap(int &x, int &y);
void search(int a[ ]);
int dosearch(int a[ ], int b);
int main()
{
	int a[c];
	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);
	inputa(a);
	outputa(a);
	cout<<endl;
	dosort(a);
	outputa(a);
	search(a);
	return 0;
}
void inputa(int a[ ])
{
	int i;
	for(i=0; i<c;i++)
	{
		a[i]=rand()%101;
	}
}
void outputa(int a[ ])
{
	int pig;
	for(pig=0; pig<c;pig++)
	{
		cout<<a[pig]<<endl;
	}
}
void dosort(int a[ ])
{
	int j, pig;
	for(pig=0;pig<c;pig++)
	{
		for(j=0;j<c;j++)
		{
			if (a[j]>a[pig])
			{
				swap(a[j],a[pig]);
			}
		}
	}
}
void swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void search(int a[ ])
{
	int b;
	cout<<"Enter Number to Search for: ";
	cin>>b;
	dosearch(a,b);
	cout<<"The number was found in line number "<<dosearch(a,b)<<endl;
}
int dosearch(int a[ ], int b)
{
	int high=c;
	int mid=c/2;
	int low=-1;
	int d=0;
	int line=0;
	do
	{
		if(b>a[mid])
		{
			low=mid+1;
			mid=(high+low)/2;
		}
		else if (b<a[mid])
		{
			high=mid+1;
			mid=(high+low)/2;
		}
		else if(a[mid]==b)
		{
			return mid+1;
		}
	}while(low<high);
	return -1;
}
