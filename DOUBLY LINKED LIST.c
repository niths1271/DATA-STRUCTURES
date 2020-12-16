#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
struct node
{
	int info;
	struct node *rlink;
	struct node *llink;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if (x==NULL)
	{
		printf("Memory full\n");
		exit(0);
	}
	return x;
}
NODE insertfront(NODE head,int item)
{
	NODE temp,cur;
	temp=getnode();
	temp->rlink=NULL;
	temp->llink=NULL;
	temp->info=item;
	cur=head->rlink;
	head->rlink=temp;
	temp->llink=head;
	temp->rlink=cur;
	cur->llink=temp;
	return head;
}
NODE insertrear(NODE head,int item)
{
	NODE temp,cur;
	temp=getnode();
	temp->rlink=NULL;
	temp->llink=NULL;
	temp->info=item;
	cur=head->llink;
	head->llink=temp;
	temp->rlink=head;
	cur->rlink=temp;
	temp->llink=cur;
	return head;
}
NODE deletefront(NODE head)
{
	NODE cur,next;
	if(head->rlink==head)
	{
		printf("DOUBLY LINKED LIST IS EMPTY\n");
		return head;
	}
	cur=head->rlink;
	next=cur->rlink;
	head->rlink=next;
	next->llink=head;
	printf("THE ITEM DELETED FROM FRONT=%d\n",cur->info);
	free(cur);
	return head;
}
NODE deleterear(NODE head)
{
	NODE cur,prev;
	if(head->rlink==head)
	{
		printf("DOUBLY LINKED LIST IS EMPTY\n");
		return head;
	}
cur=head->llink;
prev=cur->llink;
head->llink=prev;
prev->rlink=head;
printf("THE ITEM DELETED FROM FRONT=%d\n",cur->info);
	free(cur);
	return head;
}
void display(NODE head)
{
	NODE temp;
	if (head->rlink==head)
	{
		printf("List is empty\n");
	}
	printf("The contents of the list are:\n");
	temp=head->rlink;
	while (temp!=head)
	{
		printf("%d\n",temp->info);
		temp=temp->rlink;
	}
}
NODE insertleftpos(int item,NODE head)
{
	NODE temp,cur,prev;
	if (head->rlink==head)
	{
		printf("List is empty\n");
		return head;
	}
	cur=head->rlink;
	while (cur!=head)
	{
		if(cur->info==item)
		{
			break;
		}
		cur=cur->rlink;
	}
	if (cur==head)
	{
		printf("INVALID ITEM\n");
		return head;
	}
	prev=cur->llink;
	temp=getnode();
	temp->llink=NULL;
	temp->rlink=NULL;
	printf("Enter the item to be inserted at the left of the given item:\n");
	scanf("%d",&temp->info);
	prev->rlink=temp;
	temp->llink=prev;
	temp->rlink=cur;
	cur->llink=temp;
	return head;
}
NODE deletepos(int item,NODE head)
{
	NODE prev,cur,next;
	int count=0;
	if (head->rlink==head)
	{
		printf("List is empty\n");
		return head;
	}
	cur=head->rlink;
	while (cur!=head)
	{
		if (item!=cur->info)
		{
			cur=cur->rlink;
		}
		else
		{
			    count++;
				prev=cur->llink;
				next=cur->rlink;
				prev->rlink=next;
				next->llink=prev;
				free(cur);
				cur=next;
			}
		}
	if (count==0)
	{
		printf("No such item found in the list\n");
	}
	else
	{
		printf("Removed all the duplicate elements of the given item successfully\n");
	}
	return head;
}
int main()
{
NODE head;
int item, choice,key;
head=getnode();
head->llink=head;
head->rlink=head;
for(;;)
{
	printf("\n1:insertfront\n2:insertrear\n3:deletefront\n4:deleterear\n5:display\n6:insertleftpos\n7:deletepos\n8:exit\n");
	printf("enter the choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter the item at front end:\n");
				scanf("%d",&item);
				head=insertfront(head,item);
				break;
		case 2: printf("Enter the item at rear end:\n");
				scanf("%d",&item);
				head=insertrear(head,item);
				break;
		case 3:head=deletefront(head);
			   break;
		case 4:head=deleterear(head);
			   break;
		case 5:display(head);
			   break;
	    case 6:printf("Enter the key element:\n");
			   scanf("%d",&key);
			   head=insertleftpos(key,head);
			   break;
		case 7:printf("Enter the key element whose duplicates should be removed:\n");
			   scanf("%d",&key);
			   head=deletepos(key,head);
			   break;
	    case 8:exit(0);
		default:printf("INVALID CHOICE\n");
		}
	}
}
	
