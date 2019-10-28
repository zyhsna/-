#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LEN1 sizeof(Two)
#define LEN2 sizeof(Ten)

typedef struct Two{
	int b;
	Two *next;
}Two;

typedef struct Ten{
	int d;
	Ten *next;
}Ten;

Two *Btop;
Ten *Dtop;

void push2(Ten *p,int d)//ʮ������ջ(ͷ�巨)
{
	Ten *q;
	q = (Ten *)malloc(sizeof(LEN2));
	q->d = d;
	q->next =Dtop;
	Dtop  = q;
}


void push1(Two *p,int b)//��������ջ
{
	Two *q;
	q = (Two *)malloc(sizeof(LEN1));
	q->b = b;
	q->next = Btop;
	Btop = q;
}

int pop1(Two *p)
{
	int x;
	x = Btop->b ;
	Btop = Btop->next ;
	return x;
}

int pop2(Ten *p)
{
	int x;
	x =Dtop->d;
	Dtop = Dtop->next;
	return x;
}

void TentoTwo()
{
	int i = 0;
	Dtop = NULL;
	Btop =NULL;
	int source,result;
	int temp[10];
	printf("������һ��ʮ��������");
	scanf("%d",&source);
	while(source)
	{
		temp[i] = source%2;
		source = source /2;
		printf("��ջ:%d\n",temp[i]);
		push1(Btop,temp[i]);//�������ջ
		i++;
	}
	result = 0;
	while(Btop)
	{
		result = pop1(Btop) + result *10;
	}
	printf("ת����Ķ�����Ϊ%d",result);
}


void TwotoTen()//������תʮ����
{
	Dtop = NULL;
	Btop = NULL;
	int i = 0;
	int source,result;
	int temp[10];
	printf("������һ����������");
	scanf("%d",&source);
	while(source)
	{
		temp[i] = source%10;
		source /= 10;
		printf("��ջ˳��");
		printf("%d",temp[i]);
		push2(Dtop,temp[i]);
		i++;
	}
	result = 0;
	while(Dtop)
	{
		i--;//֮ǰ��ջʱi�����һ��
		result = pop2(Dtop)*pow(float(2),i) +result;	
	}
	printf("ת�������ʮ����Ϊ%d",result);
}
int main()
{
	int choice;
	printf("������תʮ���ư�1\n");
	printf("ʮ����ת�����ư�2\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:TwotoTen();break;
		case 2:TentoTwo();break;
	}
	return 0;
}