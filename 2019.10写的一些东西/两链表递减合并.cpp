#include<stdio.h>
#include<stdlib.h>

#define LEN sizeof(Elem)

typedef struct Elem{
	int num;
	Elem *next;
};
int length =0;

Elem *Ahead = NULL;
Elem *Bhead = NULL;
Elem *Chead = NULL;

void Ainsert();
void Binsert();
void ATraverse();
void BTraverse();
void CTraverse();
void Merge();
int main()
{
	int q = 1;
	int choice;
	while(q)
	{	
		printf("遍历A链表请按1\n");
		printf("遍历B链表请按2\n");
		printf("A链表插入请按3\n");
		printf("B链表插入请按4\n");
		printf("合并链表请按5\n");
		printf("\n退出按7\n");
		printf("请输入你的选择");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					ATraverse();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 2:
					BTraverse();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
		
				case 3:
					Ainsert();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 4:
					Binsert();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
				case 5:
					Merge();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 7: q = 0;break;
			
				default:
				printf("输入有误！！\n");
				printf("还需要继续使用本系统吗？继续请按1，终止请按0");
				scanf("%d",&q);
			}
		system("cls");//清屏
	}
	return 0;
}


void ATraverse()
{
	Elem *p1;
	p1 = Ahead;
	if(p1 == NULL)
		printf("该链表为空链表\n");
    else
	{
		while(p1)
		{			
			printf("│%-6d│\n",p1->num);
			p1 = p1->next ;
		}
	}
}

void BTraverse()
{
	Elem *p1;
	p1 = Bhead;
	if(p1 == NULL)
		printf("该链表为空链表\n");
    else
	{
		while(p1)
		{			
			printf("│%-6d│\n",p1->num);
			p1 = p1->next ;
		}
	}
}


void Ainsert()
{
	Elem *p1,*p2,*p3;
	p2 =p3= Ahead;
	p1 = (Elem *)malloc(sizeof(LEN));//申请空间
	printf("请输入数字：");
	scanf("%d",&p1->num);
	p1->next = NULL;
	if(Ahead == NULL)
	{
		Ahead = p1;//如果没节点，则直接将p1放置为第一个
	}
	else
	{
		while(p1->num > p2->num && p2->next!=NULL)//当p1大于p2且p2不为最后一个节点
		{
			p3 = p2;//后移
			p2 = p2->next;
		}
		if((p1->num) <= (p2->num))
		{
			if(Ahead == p2 )//p1数据小于等于第一个数字
			{
				p1->next =p2;
				Ahead = p1;
			}
			else//p1大小处于表中数据中间时
			{
				p1->next = p2;
				p3->next =p1;
			}
		}
		else//最大
		{
			p2->next =p1;
		}
	}
}


void Binsert()
{
	Elem *p1,*p2,*p3;
	p2 =p3= Bhead;
	p1 = (Elem *)malloc(sizeof(LEN));//申请空间
	printf("请输入数字：");
	scanf("%d",&p1->num);
	p1->next = NULL;
	if(Bhead == NULL)
	{
		Bhead = p1;//如果没节点，则直接将p1放置为第一个
	}
	else
	{
		while(p1->num > p2->num && p2->next!=NULL)//当p1大于p2且p2不为最后一个节点
		{
			p3 = p2;//后移
			p2 = p2->next;
		}
		if((p1->num) <= (p2->num))
		{
			if(Bhead == p2 )//p1数据小于等于第一个数字
			{
				p1->next =p2;
				Bhead = p1;
				printf("%",Ahead->num);
			}
			else//p1大小处于表中数据中间时
			{
				p1->next = p2;
				p3->next =p1;
			}
		}
		else//最大
		{
			p2->next =p1;
		}
	}
}


/*void Merge()
{
	Elem *Apre,*Acur,*Bpre,*Bcur,*Cpre,*Ccur;
	if(Ahead ==NULL && Bhead ==NULL)
		printf("无可操作链表");
	else
	{
		Apre = Ahead;
		Bpre = Bhead;
		Acur = Ahead->next ;
		Bcur = Bhead->next ;
		Cpre = Chead;
		while(Apre&&Bpre)
		{
			if(Apre>=Bpre)//Apre数字比Bpre数字大
			{
				if(Chead == NULL)//c链表为空链表
					Cpre = Apre;
				else//c链表中有数据
					Apre->next = Cpre;
				Apre =Acur;
				if(Acur->next !=NULL)
					Acur = Acur->next ;
				
			}
			else//Bpre数字比Apre数字大
			{
				if(Chead == NULL)//c链表为空链表
					Cpre = Bpre;
				else//c链表中有数据
					Bpre->next = Cpre;
				Bpre =Bcur;
				if(Bcur->next !=NULL)
					Bcur = Bcur->next ;
				
			}
		}
		if(Apre)//a链表中还有数据
		{}
		if(Bpre)//b链表中还有数据
		{}
	}
	}
*/


void Merge()
{
	Elem *A,*B,*p1,*p2;
	p1=p2 = (Elem *)malloc(sizeof(LEN));
	A=Ahead;
	B=Bhead;
	int i=0;
	int j;
	int max,tem;
	int temp[200];
	while(A)
	{
		temp[length] = A->num ;
		A = A->next ;
		length++;
	}
	while(B)
	{
		temp[length] = B->num ;
		B=B->next ;
		length++;
	}
	printf("ab链表一共有%d个元素\n",length);
	for(i=0;i<length;i++)
	{
		printf("│%-6d│\n",temp[i]);
	}
	for(i=0;i<length;i++)
	{
		max=temp[i];
		for(j=i+1;j<length;j++)
		{
			if(temp[j]>max)
			{
				max = temp[j];
				tem=temp[i];
				temp[i]=temp[j];
				temp[j]=tem;
			}
		}
	}
	printf("排序过后\n");
	/*for(i=0;i<length;i++)
	{
		printf("│%-6d│\n",temp[i]);
	}*/
	i = 0;
	while(length)
	{
		p1->num =temp[i];
		p1->next =NULL;
		if(Chead == NULL)
			Chead = p1;
		else
			p2->next =p1;
		p2=p1;
		p1 = (Elem *)malloc(sizeof(LEN));
		i++;length--;
	}
	CTraverse();
}

void CTraverse()
{
	Elem *p1;
	p1 = Chead;
	if(p1 == NULL)
		printf("该链表为空链表\n");
    else
	{
		while(p1)
		{			
			printf("│%-6d│\n",p1->num);
			p1 = p1->next ;
		}
	}
}