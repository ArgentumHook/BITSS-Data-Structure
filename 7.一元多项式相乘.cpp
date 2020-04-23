/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void input( NODE * head )
{   int flag, sign, sum, x;
	char c;

    NODE * p = head;

	while ( (c=getchar()) !='\n' )
	{
		if ( c == '<' )
	    {    sum = 0;
	         sign = 1;
	         flag = 1;
        }
		else if ( c =='-' )
             sign = -1;
		else if( c >='0'&& c <='9' )
		{    sum = sum*10 + c - '0';
        }
		else if ( c == ',' )
        {    if ( flag == 1 )
             {    x = sign * sum;
                  sum = 0;
                  flag = 2;
		  sign = 1;
             }
        }
		else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
             p->next->coef = x;
             p->next->exp  = sign * sum;
             p = p->next;
             p->next = NULL;
             flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   NODE * head1, * head2, * head3;

    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );

    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );

    head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );

	output( head3 );
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void multiplication(NODE *head1, NODE *head2, NODE *head3)
{
	NODE *p1,*p2,*p3,*p4;
	int cnt=0;
	p1=head1;
	while(p1->next)
	{
		p1=p1->next;
		if(!p1->coef&&cnt==1)
			continue;
		p2=head2;
		p3=head3;
		while(p2->next)
		{
			p2=p2->next;
			int Coef=p1->coef*p2->coef;
			int Exp=p1->exp+p2->exp;
			if(!Coef&&cnt==1)
				continue;
			while(p3)
			{
				p4=p3;
				p3=p3->next;
				if(!p3||p3->exp>Exp)
				{
					NODE *p5=new NODE;
					if(!Coef&&!cnt)
					{
						p5->exp=0;
						cnt=1;
					}
					else
						p5->exp=Exp;
					p5->coef=Coef;
					p5->next=p3;
					p4->next=p5;
					p3=p4;
					break;
				}
				if(p3->exp<Exp)
					continue;
				else if(p3->exp==Exp)
				{
					p3->coef+=Coef;
					if(!p3->coef&&Exp)
					{
						p4->next=p3->next;
						delete p3;
					}
					p3=p4;
					break;
				}
			}
		}
	}
}
