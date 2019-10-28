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

void push2(Ten *p,int d)//十进制入栈(头插法)
{
	Ten *q;
	q = (Ten *)malloc(sizeof(LEN2));
	q->d = d;
	q->next =Dtop;
	Dtop  = q;
}


void push1(Two *p,int b)//二进制入栈
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
	printf("请输入一个十进制数：");
	scanf("%d",&source);
	while(source)
	{
		temp[i] = source%2;
		source = source /2;
		printf("入栈:%d\n",temp[i]);
		push1(Btop,temp[i]);//入二进制栈
		i++;
	}
	result = 0;
	while(Btop)
	{
		result = pop1(Btop) + result *10;
	}
	printf("转换后的二进制为%d",result);
}


void TwotoTen()//二进制转十进制
{
	Dtop = NULL;
	Btop = NULL;
	int i = 0;
	int source,result;
	int temp[10];
	printf("请输入一个二进制数");
	scanf("%d",&source);
	while(source)
	{
		temp[i] = source%10;
		source /= 10;
		printf("入栈顺序：");
		printf("%d",temp[i]);
		push2(Dtop,temp[i]);
		i++;
	}
	result = 0;
	while(Dtop)
	{
		i--;//之前入栈时i多加了一次
		result = pop2(Dtop)*pow(float(2),i) +result;	
	}
	printf("转换过后的十进制为%d",result);
}
int main()
{
	int choice;
	printf("二进制转十进制按1\n");
	printf("十进制转二进制按2\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:TwotoTen();break;
		case 2:TentoTwo();break;
	}
	return 0;
}