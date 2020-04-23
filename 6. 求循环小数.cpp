/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

void output( NODE *, int );
void change( int, int, NODE * );

void output( NODE * head, int kk )
{   int k=0;

	printf("0.");
	while ( head->next != NULL && k<kk )
	{   printf("%d", head->next->data );
		head = head->next;
		k ++;
	}
	printf("\n");
}

int main()
{   int n, m,k;
	NODE * head;

	scanf("%d%d%d", &n, &m, &k);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;
	change( n, m, head );
	output( head,k );
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
#define MAX 10000
void change(int n, int m, struct node *head)
{
	struct node *p, *p1, *p2, *p3, *p4;
	int chu, shang, yu, i, j;
	chu = n;
	p = (NODE *)malloc(sizeof(struct node));
	p2 = (NODE *)malloc(sizeof(struct node));
	shang = chu * 10 / m;
	yu = chu * 10 % m;
	p->data = shang;
	head->next = p;
	p1 = p;
	if (yu == 0)
	{
		p->next = NULL;
		return;
	}
	if (yu == chu)
	{
		p->next = p;
		return;
	}
	p2->data = chu;
	p3 = p4 = p2;
	p2->next = NULL;
	chu = yu;
	for (j = 1; j <= MAX; j++)
	{
		int count = 0;
		struct node *c;
		c = p3;
		while (c != NULL)
		{
			if (c->data == chu)
			{
				count++;
				break;
			}
			else
			{
				c = c->next;
				count++;
			}
		}
		if (c != NULL && c->data == chu)
		{
			struct node *zhuan;
			int count2;
			zhuan = head;
			for (count2 = 1; count2 <= count; count2++)
				zhuan = zhuan->next;
			p->next = zhuan;
			return;
		}
		p = (NODE *)malloc(sizeof(struct node));
		p2 = (NODE *)malloc(sizeof(struct node));
		shang = chu * 10 / m;
		yu = chu * 10 % m;
		p->data = shang;
		p1->next = p;
		p1 = p;
		if (yu == 0)
		{
			p1->next = NULL;
			break;
		}
		p2->data = chu;
		p4->next = p2;
		p4 = p2;
		p2->next = NULL;
		chu = yu;
	}
}
