#include<stdio.h>
#include<math.h>

typedef struct Two{
	int b[100];
	int top;
}; 

typedef struct Ten{
	int d[10];
	int top;
};


void push1(Ten *p,int d)//十进制入栈
{
	p->d [p->top ++] = d;
}

void push2(Two *p,int b)//二进制入栈
{
	p->b[p->top ++] = b;
}
 int pop1(Ten *p1)
{
	int num;
	num = p1->d[--p1->top ] ;
	return(num);
}

int pop2(Two *p1)
{
	int num;
	num = p1->b[--p1->top ] ;
	return(num);
}

void TwoToTen()
{
	Ten dec;
	dec.top= 0;
	int source;
	int temp;
	printf("请输入一个二进制数：");
	scanf("%d",&source);
	while(source)
	{
		temp = source%10;
		source /=10;
		printf("入栈顺序：");
		printf("%d",temp);
		push1(&dec,temp);
	}
	temp = 0;
	while(dec.top)
	{
		temp = pop1(&dec)*pow((float)2,dec.top) + temp;
	}
	printf("\n转换过后的十进制数为%d",temp);
}

void TentoTwo()
{
	Two bin;
	bin.top =0;
	int source;
	int temp;
	printf("请输入一个十进制数：");
	scanf("%d",&source);
	while(source)
	{
		temp = source%2;
		source /=2;
		printf("入栈顺序：");
		printf("%d",temp);
		push2(&bin,temp);
	}
	temp = 0;
	while(bin.top)
	{
		temp = pop2(&bin) + temp*10;
	}
	printf("\n转换过后的二进制数为%d",temp);
}

int main()
{
	int choice;
	printf("十到二按1，二到十按2");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:TentoTwo();break;
	
		case 2 :TwoToTen();break;
		default :printf("输入有误！");
	}
	return 0;
}


