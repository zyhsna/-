#include<stdio.h>
#include<stdlib.h>
#define LENGTH sizeof(struct info)

struct info{
	int num;
	struct info *next;
};

struct info *head = NULL;

void insert();
int length();
void delrepeatition();
void delrange();
void traverse();

int main()
{
	int q = 1;
	int choice;
	while(q)
	{	
		printf("表长请按1\n");
		printf("插入请按2\n");
		printf("删除重复请按3\n");
		printf("删除一定范围请按4\n");
		printf("遍历请按5\n");
		printf("\n退出按7\n");
		printf("请输入你的选择");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					length();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 2:
					insert();
					traverse();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
		
				case 3:
					delrepeatition();
					traverse();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 4:
					delrange();
					traverse();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
				case 5:
					traverse();
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

int length()
{
	struct info *p;
	p = head;
	int LEN =0;
	//if(head == NULL)
		//printf("当前列表为空列表！链表节点个数为0\n");
		
	//else
		while(p)
		{
			LEN++;
			p = p->next ;
		}
		printf("当前链表节点个数为%d\n",LEN);
	return LEN;
}

void insert()
{
	struct info *p1,*p2,*p3;
	p2 =p3= head;
	p1 = (struct info *)malloc(sizeof(LENGTH));//申请空间
	printf("请输入数字：");
	scanf("%d",&p1->num);
	p1->next = NULL;
	if(head == NULL)
	{
		head = p1;//如果没节点，则直接将p1放置为第一个
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
			if(head == p2 )//p1数据小于等于第一个数字
			{
				p1->next =p2;
				head = p1;
				printf("%",head->num);
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

void delrange()
{
	struct info *pre,*cur;
	int sign =1;
	int left,right;
	if(head == NULL)
		printf("链表为空链表！");
	else
	{
		printf("请输入想要删除的范围：");  //确定范围 
		printf("\n左边范围为：");
		scanf("%d",&left);
		printf("\n右边范围为：");
		scanf("%d",&right);
		pre=head;
		cur = head->next;
		while(pre!=NULL && sign ==1)//循环判断某个数是否处于这个范围
		{
			if(head->num >=left && head->num <=right)//如果头指针是
			{
				head=head->next ;
				pre = head;
				if(cur!=NULL)//如果只有一个节点
				cur=cur->next ;
			}
			else //头指针不是
			{
				if(cur->num >=left && cur->num <=right )//cur所指向的数据处于这个范围
				{
					pre->next =cur->next ;//将pre连接到cur的下一个指针
					if(cur->next !=NULL)//如果cur不为最后一个节点，则将cur后移
						cur=cur->next ;
					else//代表cur为最后一个指针，sign赋值为0，程序结束
						sign =0;
				}
			
				else//cur不属于这个范围
				{
					pre=cur;//将pre后移
					if(cur->next !=NULL)//判断cur是否为最后一个节点
						cur=cur->next ;//不是则cur后移
					else
						sign =0;//是则结束运行
				}
			}
		}
	}
}


void traverse()
{
	struct info *p3;
	p3 = head;
	if(head == NULL)
		printf("该链表为空链表\n");
    else
	{
		while(p3)
		{			
			printf("│%-6d│\n",p3->num);
			p3 = p3->next ;
		}
	}
}
void delrepeatition()
{
	int temp;//temp存放要判断是否重复的数字
	struct info *p1,*cur,*pre;
	p1=head;
	if(head == NULL)//没数据当然不要判断了
	{
		printf("\n当前链表为空！\n");
	}
	else
	{
		while(p1!= NULL)//第一层循环
		{
			temp = p1->num ;//存放数字
			pre = p1 ;//
			cur=p1->next ;//将cur连接到p1的下一个节点
			while(cur!=NULL)//当cur不为NULL，一直往后移动
			{
				if(cur-> num == temp)//判断是否一样
					pre->next =cur->next  ;//如果一样则将这个节点前一个节点连接到后面
				else  pre=cur;//不一样则pre后移，以便下一个一样时删除节点
					cur =cur->next ; //cur后移
			}
			p1=p1->next ;//p1后移,代表要判断是否重复的数字改变
		}
	}
}
