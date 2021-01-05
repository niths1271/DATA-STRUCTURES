#include<stdio.h>
#include<conio.h>
#include<process.h>
int item;
int r=-1;
int f=0;
int n;
int q[10];
void insertrear()
{
	if(r==(n-1))
	{
		printf("QUEUE OVERFLOW\n");
		return;
	}
	printf("ENTER THE ITEM TO BE INSERTED\n");
	scanf("%d",&item);
	r=r+1;
	q[r]=item;
}
void deletefront()
{
	if(f>r)
	{
		printf("THE QUEUE IS EMPTY\n");
		f=0;
		r=-1;
	}
	else
	printf("THE ITEM DELETED IS =%d\n",q[f++]);
}
void display()
{
	int i;
	if(f>r)
	{
		printf("THE QUEUE IS EMPTY\n");
		return;
	}
	else
	{
    printf("THE CONTENTS OF THE QUEUE IS=  ");
    for(i=f;i<=r;i++)
    {
		printf("%d\t",q[i]);
	}
	printf("\n");
}
}
int main()
{
	int c,i;
	printf("ENTER THE SIZE OF QUEUE\n");
	scanf("%d",&n);
	while(i!=4)
	{
		printf("1-INSERT  2-DELETE  3-DISPLAY 4-EXIT\n");
		printf("ENTER THE CHOICE\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			        insertrear();
			        break;
			case 2:
			        deletefront();
			        break;
		    case 3:
			        display();
			        break;
			case 4:
			        exit(0);
		  default:
			        printf("INVALID CHOICE");
				}
			}
		}
		
			 
		
	
