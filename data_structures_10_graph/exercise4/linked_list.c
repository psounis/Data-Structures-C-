/* linked_list.c: Kwdikas tis vivliothikis sindedemenis listas */
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* LL_init(): arxikopoiei tin lista */
void LL_init(LIST_PTR *head)
{
	*head=NULL;
}

/* LL_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i lista einai adeia */
int LL_empty(LIST_PTR head)
{
	return head == NULL;
}

/* LL_data(): epistrefei ta dedomena tou komvou
			  pou deixnei o deiktis p */
elem LL_data(LIST_PTR p)
{
	return p->data;
}

/* LL_insert_start(): Eisagei to stoixeio x
			stin arxi tis listas */
int LL_insert_start(LIST_PTR *head,elem x)
{
	LIST_PTR newnode;

	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;
	newnode->next=*head;
	*head=newnode;
	return TRUE;
}

/* LL_insert_after(): Eisagei to stoixeio x
			meta to stoixeio pou deixnei o p */
int LL_insert_after(LIST_PTR p,elem x)
{
	LIST_PTR newnode;

	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;

	newnode->next=p->next;
	p->next=newnode;
	return TRUE;
}

/* LL_delete_start(): Diagrafei ton komvo poy deixnei
	i kefali tis listas */
int LL_delete_start(LIST_PTR *head, elem *x)
{
	LIST_PTR current;

	if (*head==NULL)
		return FALSE;

	current=*head;
	*x=current->data;

	(*head)=(*head)->next;
	free(current);
	return TRUE;
}

/* LL_delete_after(): Diagrafei ton epomeno tou
				komvou poy deixnei o prev */
int LL_delete_after(LIST_PTR prev, elem *x)
{
	LIST_PTR current;

	if (prev->next==NULL)
		return FALSE;

	current=prev->next;
	*x=current->data;

	prev->next=current->next;
	free(current);
	return TRUE;
}

/* LL_print(): Typwnei ta periexomena mias
				syndedemenis listas	 */

void LL_print(LIST_PTR head)
{
	LIST_PTR current;

	current=head;
	while(current!=NULL)
	{
		printf("%d(%d) ",current->data.id, current->data.weight);
		current=current->next;
	}
}

/* LL_destroy(): Apodesmeyei to xwro poy exei
				desmeusei i lista	 */

void LL_destroy(LIST_PTR *head)
{
	LIST_PTR ptr;

	while (*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}


/* Deytereouses prakseis gia ti domi: grafos */
/* LL_insert: eisagei taksinomimena ena stoixeio sti lista */
int LL_insert(LIST_PTR *head, int id, int weight)
{
	LIST_PTR prev, cur;
	elem newdata;

	newdata.id = id;
	newdata.weight = weight;

	if (*head==NULL)
		return LL_insert_start(head, newdata);
	else if (newdata.id < (*head)->data.id)
		return LL_insert_start(head, newdata);
	else
	{
		cur = *head;
		while(1)
		{
			if (newdata.id == cur->data.id)
			{
				printf("H akmh yparxei hdh");
				return FALSE;
			}
			else if (newdata.id > cur->data.id)
			{
				prev=cur;
				cur=cur->next;
				if (cur==NULL)
					return LL_insert_after(prev, newdata);
			}
			else // x < cur.data
				return LL_insert_after(prev, newdata);
		}
	}
}
