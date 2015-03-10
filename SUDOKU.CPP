#include<stdio.h>
#include<conio.h>
#include<stdlib.h>;
int place(int,int,int);
int a[9][9],ovr[9]; //ovr0--8
int chkovr();
void clrovr();
int rowfull(int);
void main()
{       int k,ovrf=0;
	clrscr();
	for(int i=0;i<9;i++)
	{	for(int j=0;j<9;j++)
		{   // labl:
		     clrovr();
		     ovrf=0;
		     while(1)
		     {
			  do
			  { k=random(100)%9+1;        //k 1--9
			  }while(ovr[k-1]==1);
			  ovr[k-1]=1;
			  if(place(k,i,j))
			  {	a[i][j]=k;
				ovrf++;
				if(ovrf==9)
				{	if(j>0)
						j--;
					else
					{       i--;
						j=8;
					}
					a[i][j]=0;
			       //	goto labl;
				}
			  }
		     }
		}
	}
	for(int p=0;p<9;p++)
	{	for(int q=0;q<9;q++)
		       printf("%d ",a[p][q]);
		printf("\n");
	}
	getch();
}
int place(int k,int r,int c)
{       int f=0;
	for(int i=0;i<c;i++)
	{	if(a[r][i]==k)
		{	f=1;
			break;
		}
	}
	for(i=0;i<r;i++)
	{	if(a[i][c]==k)
		{
			f=1;
			break;
		}
	}
	if(f==0)
		return 1;
	return 0;
}
int chkovr()
{       int ovrf=0;
	for(int i=0;i<9;i++)
	{	if(ovr[i]==1)
		    ovrf++;
	}
	if(ovrf==9)
	    return 1;
	return 0;
}
void clrovr()
{       for(int i=0;i<9;i++)
		ovr[i]=0;
}
int rowfull(int i)
{       int rf=0;
	for(int j=0;j<9;j++)
		if(a[i][j]>0)
		     rf++;
	if(rf==9)
		return 0;
	return 1;
}