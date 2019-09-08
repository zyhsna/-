#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student *p1,*p2,*head;
#define null 0;

struct student 
{
	int num;
	int score;
	struct student *next;
}stu[10];

void add();
void print();
int del(int a);


int j = 0;


int main()
{
	int a= 1;
	add();
	del(a);
	print();
	return 0;

}

void add()
{
	int n = 0;
	head =NULL;
	p1 = p2 = (struct student *)malloc(LEN);
	printf("请输入学生的学号以及姓名：");
	scanf("%d,%d",&p1->num ,&p1->score );
	while(p1->num != 0 && j<10)
	{
		if(n == 0)
		{
			n ++;
			head = p1;
			j++;
		}
		else
		{p2->next = p1;}
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		printf("请输入学生的学号以及分数");
		scanf("%d,%d",&p1->num ,&p1->score );
		j++;
	}
	p2 ->next = NULL;
}


void print()
{
	struct student *p3;
	p3 = head;
	if(head == NULL)
		printf("该链表为空链表\n");
	while(p3->num != NULL)
	{
		if(j == 9)
			printf("储存数已达到最大！\n");
		printf("学号%d 成绩%d\n",p3->num ,p3->score);
		p3 = p3->next ;
	}
}

int del(int a)
{
	struct student *p3,*p4;
	p3 =head ;
	if(head == NULL)
		printf("该链表为空链表，无法删除！");
	if(head->num == a)
		{head = head->next ;
		 j --;
		}
	else
	{
		while(p3 ->num != a && p3->next != NULL)
		{
			p4 = p3;
			p3 = p3->next ;
		}
		if(p3 ->num == a)
		{
			p4->next = p3->next ;
			j --;
		}
		else
			printf("未找到！");
	}
	return 0;
}

/*int insert()
{
	struct student *stud;
	struct student*p0,*p3,*p4;
	p3 = head;
	p0 = stud;
	if(head == NULL)
	{
		head = p0;
		p0 ->next = NULL;
	}
	else
	{
		while((p0->num > p3->num ) && (p3->next!=NULL ))
		{
			p4 = p1;
			p1 = p1->next ;
		}
		if((p0->num <=p1->num ))
		{
			if(head == p1)
				head = p0;

		}
	}
}*/