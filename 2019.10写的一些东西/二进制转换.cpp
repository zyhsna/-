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


void push1(Ten *p,int d)//ʮ������ջ
{
	p->d [p->top ++] = d;
}

void push2(Two *p,int b)//��������ջ
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
	printf("������һ������������");
	scanf("%d",&source);
	while(source)
	{
		temp = source%10;
		source /=10;
		printf("��ջ˳��");
		printf("%d",temp);
		push1(&dec,temp);
	}
	temp = 0;
	while(dec.top)
	{
		temp = pop1(&dec)*pow((float)2,dec.top) + temp;
	}
	printf("\nת�������ʮ������Ϊ%d",temp);
}

void TentoTwo()
{
	Two bin;
	bin.top =0;
	int source;
	int temp;
	printf("������һ��ʮ��������");
	scanf("%d",&source);
	while(source)
	{
		temp = source%2;
		source /=2;
		printf("��ջ˳��");
		printf("%d",temp);
		push2(&bin,temp);
	}
	temp = 0;
	while(bin.top)
	{
		temp = pop2(&bin) + temp*10;
	}
	printf("\nת������Ķ�������Ϊ%d",temp);
}

int main()
{
	int choice;
	printf("ʮ������1������ʮ��2");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:TentoTwo();break;
	
		case 2 :TwoToTen();break;
		default :printf("��������");
	}
	return 0;
}


