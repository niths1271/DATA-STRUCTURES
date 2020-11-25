#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
struct node{
	int info;
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
	temp->info=item;
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
	temp->info=item;
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
temp->info=item;
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

NODE deletefront(NODE first)
{
	NODE cur;
	if(first==NULL)
	{
		printf("THE LINKED LIST IS EMPTY\n");
		return first;
	}
	cur=first;
	cur=cur->link;
	printf("THE DELETED ITEM FROM FRONT IS=%d\n",first->info);
	free(first);
	return cur;
}
NODE deleterear(NODE first)
{
	NODE prev,cur;
	if(first==NULL)
	{
		printf("THE LINKED LIST IS EMPTY\n");
		return first;
	}
	if(first->link==NULL)
	{
		printf("ITEM DELETED IS=%d\n",first->info);
		free(first);
		return NULL;
	}
	prev=NULL;
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("THE DELETED ITEM FROM REAR IS=%d\n",cur->info);
	free(cur);
	prev->link=NULL;
	return first;
}
NODE deletepos(NODE first,int pos)
{
	NODE prev,cur;
	NODE temp;
	int count;
	if(first==NULL)
	{
		printf("THE LINKED LIST IS EMPTY\n");
		return NULL;
	}
	if(pos==1)
	{
		temp=first;
		printf("THE DELETED ITEM FROM POS 1 IS=%d\n",temp->info);
		free(temp);
	    first=first->link;
	    return first;
	}
	count=1;
	prev=NULL;
	cur=first;
	while(cur!=NULL && count!=pos)
	{
		prev=cur;
		cur=cur->link;
		count++;
	}
	if(count==pos)
	{
		printf("THE DELETED ITEM AT POSITION %d=%d\n",pos,cur->info);
		prev->link=cur->link;
		free(cur);
		return first;
	}
		printf("INVALID CHOICE\n");
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
		printf("%d\t",temp->info);
	}
	printf("\n");
}


int main()
{
	int c,item,pos;
	NODE first=NULL;
	for(;;)
	{
		printf("1-INSERTFRONT \n 2-INSERTREAR \n 3-INSERT AT GIVEN POSITION \n 4-DELETEFRONT \n 5-DELETEREAR \n 6-DELETEPOS \n 7-DISPLAY \n 8-EXIT\n");
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
			first=deletefront(first);
			break;
			case 5:
			first=deleterear(first);
			break;
			case 6:
			printf("ENTER  THE POS AT WHICH ELEMENT SHOULD BE DELETED\n");
			scanf("%d",&pos);
			first=deletepos(first,pos);
			break;			
            case 7:
            display(first);
            break;
            case 8:
            exit(0);
         default:
         printf("INVALID CHOICE\n");
	 }
 }
}




	
	
	
	
	
	
	
	
	
	
	
	
