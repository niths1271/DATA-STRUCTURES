#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
struct node{
	int inf;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("MEMORY IS FULL\n");
		exit(0);
	}
	else
	return x;
}
NODE insertfront(NODE first,int item)
{
	NODE temp;
	temp=getnode();
	temp->inf=item;
	temp->link=NULL;
	if(first==NULL)
	{
		return temp;
	}
	temp->link=first;
	first=temp;
	return first;
}
NODE insertrear(NODE first,int item)
{
	NODE temp,cur;
	temp=getnode();
	temp->inf=item;
	temp->link=NULL;
	if(first==NULL)
	{
		return temp;
	}
	cur=first;
	while(cur->link != NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	return first;
}

NODE insertpos(int item,int pos,NODE first)
{
NODE temp,cur,prev;
int count;
temp=getnode();
temp->inf=item;
temp->link=NULL;
if(first==NULL&&pos==1)
{
return temp;
}
if(first==NULL)
{
printf("invalid position\n");
return first;
}
if(pos==1)
{
temp->link=first;
first=temp;
return temp;
}
count=1;
prev=NULL;
cur=first;
while(cur!=NULL&&count!=pos)
{
prev=cur;
cur=cur->link;
count++;
}
if(count==pos)
{

prev->link=temp;
temp->link=cur;
return first;
}
printf("invalid position\n");
return first;
}



void display(NODE first)
{
	NODE temp;
	if(first==NULL){
		printf("THE LIST IS EMPTY\n");
	}
	printf("THE ELEMENTS ARE=");
	for(temp=first;temp!=NULL;temp=temp->link)
	{
		printf("%d\t",temp->inf);
	}
	printf("\n");
}

int main()
{
	int c,item,pos;
	NODE first=NULL;
	for(;;)
	{
		printf("1-INSERTFRONT \n 2-INSERTREAR \n 3-INSERT AT GIVEN POSITION \n 4-DISPLAY \n 5-EXIT\n");
		printf("ENTER THE CHOICE\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("ENTER THE ELEMENT TO BE INSERTED FRONT\n");
			scanf("%d",&item);
			first=insertfront(first,item);
			break;
			case 2:
			printf("ENTER THE ELEMENT TO BE INSERTED AT THE END\n");
			scanf("%d",&item);
			first=insertrear(first,item);
			break;
              case 3:
              printf("ENTER THE ELEMENT AND THE POS AT WHICH IT SHOULD BE INSERTED\n");
			scanf("%d",&item);
			scanf("%d",&pos);
			first=insertpos(item,pos,first);
			break;
            case 4:
            display(first);
            break;
            case 5:
            exit(0);
         default:
         printf("INVALID CHOICE\n");
	 }
 }
}



