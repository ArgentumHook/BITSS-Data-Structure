/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{   int         data;
    struct node * next;
} NODE;

NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );
void outputring( NODE * pring )
{	NODE * p;
	p = pring;
	if ( p == NULL )
		printf("NULL");
	else
		do	{	printf("%d", p->data);
			p = p->next;
		} while ( p != pring );
	printf("\n");
	return;
}

int main()
{   int n, m;
	NODE * head, * pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	change( n, m, head );
	pring = find( head, &n );
	printf("ring=%d\n", n);
	outputring( pring );

	return 0;
}

/* Here is waiting for you.
void change( int n, int m, NODE * head )
{ 
}

NODE * find( NODE * head, int * n )
{
}
*/

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
#include<string.h>
#define NEWSIZE 4
int t = 0;
int prior = 0;
typedef struct SeqList
{
    int *base;
    size_t capa;
    size_t len;
}SeqList;

void InitSeqList(SeqList *list,int SIZE)  
{
    list->capa = SIZE;
    list->base = (int *)malloc(sizeof(int)*list->capa);
    list->len = 0;
}

int NewSpace(SeqList *list)  
{
    int *newspace = (int*)malloc(sizeof(int)*(list->capa + NEWSIZE));
    if(newspace == NULL)
        return 0;
    memcpy(newspace, list->base, sizeof(int)*list->capa);
    free(list->base);
    list->base = newspace;
    list->capa += NEWSIZE;
    return 1;
}

int FindElem(SeqList *list, int a)
{
    int i,flag = 0;
    if(list->len == 0)
        return -1;
    else
    {
        for(i=0; i<list->len; i++)
        {
            if(list->base[i] == a)        
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return -1;
        else
            return i;
    }
}

int EndInsert(SeqList *list, int a)
{
    if(NULL == list->base)           
        return 0;
    if(list->len >= list->capa && !NewSpace(list))
        return 0;
    list->base[list->len++] = a;
    return 1;
}

void change(int n, int m, NODE *head)
{
    NODE *p,*newNode,*q;
    SeqList list;
    InitSeqList(&list,n);
    EndInsert(&list,n); 
    int yu, chu;
    p = head;
    while(1)
    {

        chu = n*10 / m;
        yu = n*10 % m;
        int pos = FindElem(&list,yu);

        if(pos == -1)
        {
            EndInsert(&list,yu);
            newNode = (NODE *)malloc(sizeof(NODE));
            newNode->data = chu;
            newNode->next = p->next;
            p->next = newNode;
            p = p->next;
            n = yu;
            prior++;
        }
        else  
        {

            t = pos;
            if(chu != 0)
            {
                newNode = (NODE *)malloc(sizeof(NODE));
                newNode->data = chu;
                newNode->next = p->next;
                p->next = newNode;
                p = p->next;
                prior++;
            }
            q = head->next;
            while(pos--)
                q = q->next;
            p->next = q;
            break;
        }
    }
}

NODE * find(NODE *head, int *n)
{
    NODE *p;
    p = head;
    *n = prior-t;
    for(int i = 0;i < t+1;i++)
        p = p->next;
    return p;
}
