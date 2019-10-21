#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(info)

struct  info 
{
	int num;
	char name[10];
	int bw;      //basic wage 基本工资
	int sub;	 //subsidy 津贴
	int we;		 //water & electricity 水电费
	int wage;	 //实发工资
	struct info *prior;
	struct info *next;
};

struct info *head = NULL;



void read();
void traverse();
void save();
void search();
void del();
void summary();
void summary1();
void sort1();
void insert();

int main()
{
	read();
	int q = 1;
	int choice;
	while(q)
	{	
		printf("———欢迎使用工人信息管理系统 ————    produced by zyh\n\n");  /*菜单界面*/
		printf("查询工人信息请按1\n");
		printf("插入工人信息请按2\n");
		printf("删除工人信息请按3\n");
		printf("查询工人实发工资请按4\n");
		printf("求工资项总额请按5\n");
		printf("排序工人请按6\n");
		printf("退出该系统请按7\n");
		printf("请输入你的选择");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					search();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 2:
					insert();
					traverse();
					//save();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
		
				case 3:
					del();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 4:
					summary1();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 5:
					summary();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 6:
					sort1();
					printf("还需要继续使用本系统吗？继续请按1，终止请按0");
					scanf("%d",&q);
					break;
			
				case 7: q = 0;break;
			
				default:
				printf("输入有误！！\n");
				printf("还需要继续使用本系统吗？继续请按1，终止请按0");
				scanf("%d",&q);
			}
		system("cls");
	}
	return 0;
}


void traverse()
{
	struct info *p1;
	p1 = head ;
	if(head == NULL)
		printf("\n该链表为空链表！\n");
	else
	{
		printf("│ 工号 │ 姓名 │ 基 本 工 资 | 补贴 │水电费│实发工资│\n");
		while(p1->next!= NULL)
		{			
			printf("│%-6d│%-6s│%-13d|%-6d│%-6d│%-8d│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
			p1 = p1->next ;
		}
		printf("│%-6d│%-6s│%-13d|%-6d│%-6d│%-8d│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
	}
}

void insert()
{
	struct info *p1,*p2,*p3,*p4;
	p4=p2 = p1 = head ;
	int temp =0;
	int sign = 0;
	p3 = (struct info *)malloc(LEN);
	printf("请输入工人的工号：");
	scanf("%d",&p3->num );
	printf("请输入工人的姓名：");
	scanf("%s",&p3->name );
	printf("请输入工人的基本工资：");	
	scanf("%d",&p3->bw );
	printf("请输入工人的补贴：");
	scanf("%d",&p3->sub );
	printf("请输入工人的水电费：");
	scanf("%d",&p3->we );
	p3->wage = (p3->bw) + (p3->sub) - (p3->we);
	p3->prior = NULL;
	p3->next = NULL;
	if(head == NULL)
		head = p3;
	else
	{
		while(p4->next!=NULL)
		{
			if(p4->num  == p3->num )
			{
				printf("\n工号已经存在！\n");
				sign = 1;
				break;
			}
			p4 = p4->next ;
			temp = p4->num;
		}
		if(temp == p3->num )
		{
			printf("\n工号已经存在！\n");
			sign = 1;
		}
		if(sign == 0)
		{
			while((p3->num) > (p1->num ) && p1->next != NULL)
			{
				p2 = p1;
				p1 = p1->next;
			}
			if((p3->num) <= (p1->num ))
			{
				if(head == p1)//如果p3工号是最小
				{
					p3->next = p1;
					p1->prior = p3;
					head = p3;
				}
				else//其他位置
				{
					p3->next = p1;
					p3->prior = p1->prior ;
					p2->next = p3;
					p1->prior = p3;
				}
			}
			else//工号如果为最大
			{
				p1->next =p3;
				p3->prior = p1;
			}
		}
	}
}


void read()
{
	FILE *fp;
	struct info *p1,*p2;
	p2=p1=(struct info *)malloc(LEN);
	int n = 0;
	if((fp=fopen("worker.txt","r"))==NULL)
	{
		printf("无法打开文件！！\n");
		exit(0);
	}
	fscanf(fp,"%d%s%d%d%d%d",&p1->num,&p1->name,&p1->bw,&p1->sub,&p1->we,&p1->wage);
	while(!feof(fp))
	{
		if(n==0) head = p1;
	
		else 
		{
			p2 ->next = p1;
			p1->prior = p2;
		}
		p2 = p1;
		p1 = (struct info *)malloc(LEN);
		fscanf(fp,"%d%s%d%d%d%d",&p1->num,&p1->name,&p1->bw,&p1->sub,&p1->we,&p1->wage);
		n++;
	}
	p2->next =NULL;
	fclose(fp);
	printf("读入%d条数据！\n",n);
}

void save()
{
	FILE *fp;
	struct info *p1;
	if((fp = fopen("worker.txt","w"))==NULL) //打开输出文件
	{
		printf("文件无法打开！\n");
		return;
	}
	p1 = head;
	while(p1->next !=NULL)
	{
		fprintf(fp,"%d %s %d %d %d %d\n",p1->num,p1->name,p1->bw,p1->sub,p1->we,p1->wage);	
		p1=p1->next ;
	}
	fprintf(fp,"%d %s %d %d %d %d\n",p1->num,p1->name,p1->bw,p1->sub,p1->we,p1->wage);
	fclose(fp);
	printf("数据存盘成功！");
}

void search()
{
	struct info *p1;
	int a;
	int sign = 0;
	if(head == NULL)
		printf("\n该链表为空链表！\n");
	else
	{	
		printf("请输入要寻找的工号");
		scanf("%d",&a);
		p1 = head;
		if(p1->num == a)
		{
			printf("│ 工号 │ 姓名 │ 基 本 工 资 | 补贴 │水电费│实发工资│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
			printf("│%-6d│%-6s│%-13d|%-6d│%-6d│%-8d│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
			sign = 1;
		}
		else	
		{
			while(p1->next !=NULL)
			{
				if(a==p1->num )	
				{
					printf("│ 工号 │ 姓名 │ 基 本 工 资 | 补贴 │水电费│实发工资│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
					printf("│%-6d│%-6s│%-13d|%-6d│%-6d│%-8d│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
					sign = 1;
					break;
				}
				else
					p1 = p1->next ;
			}	
			if(a==p1->num && sign !=1)
			{
				printf("│ 工号 │ 姓名 │ 基 本 工 资 | 补贴 │水电费│实发工资│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
				printf("│%-6d│%-6s│%-13d|%-6d│%-6d│%-8d│\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
				sign = 1;
			}
		}
	}
	if(sign == 1)
		printf("\n已找到该人！！\n");
	else
		printf("未找到此人！！\n");
}

void del()
{
	struct info *p3,*p4;
	char temp[10];
	traverse();
	p3 = head;
	int sign = 0;
	if(p3 == NULL)
		printf("该链表为空链表，无法删除！");
	else
	{
		printf("请输入要删除工人的姓名");
		scanf("%s",&temp);
		p3 =head ;
	
		if(strcmp(head->name,temp)==0)//第一个为删除对象
		{
			head = head->next ;
			free(p3);
			sign = 1;
		}
		else
		{
			while(strcmp(p3 ->name,temp)!=0  && p3->next != NULL)//看看是否有一样的
			{
				p4 = p3;
				p3 = p3->next ;
			}
			if(strcmp(p3 ->name,temp)==0)//找到
			{
				p4->next = p3->next ;
				if(p3->next != NULL)
					p3->next->prior= p4;
				free(p3);
				sign = 1;
			}
			else
				printf("未找到！");
		}
		if(sign == 1)
			printf("\n已删除！！\n");
	}
}

void summary()
{
	int a =0;
	int b = 0;
	int c = 0;
	struct info *p1;
	p1 = head;
	if(head !=NULL)
	{
		while(p1->next !=NULL)
		{
			a += p1->bw ;
			p1 = p1->next ;
		}
		a += p1->bw ;
		
		p1 = head;
		while(p1->next !=NULL)
		{
			b += p1->sub  ;
			p1 = p1->next ;
		}
		b += p1->sub  ;
	
		p1 = head;
		while(p1->next !=NULL)
		{
			c += p1->we  ;
			p1 = p1->next ;
		}
		c += p1->we ;	
		printf("总基本工资%d\n",a);
		printf("总补贴%d\n",b);
		printf("总水电费%d\n",c);
	}
	else
		printf("\n当前链表为空链表！\n");
}

void summary1()
{
	int a=0;
	struct info *p1;
	p1=head;
	if(head!=NULL)
	{
		printf("工号    姓名\t实发工资");
		while(p1->next !=NULL)
		{
			printf("\n %d\t%s\t%d",p1->num ,p1->name,p1->wage );
			p1 = p1->next;
		}
		printf("\n %d\t%s\t%d",p1->num ,p1->name,p1->wage );
	}
	else
		printf("该链表为空链表！\n");
	printf("\n\n");
}

void sort1()
{
	struct info *p,*q,*p1;
	struct info *temp;
	int length=0;
	temp = (struct info*)malloc(sizeof(LEN));
	q = p= head;
	int MIN,i;
	if(head ==NULL)
		printf("\n空链表，无法排序！\n");
	else
	{	
		while(q)
		{
			length++;
			q= q->next;
		}
		q= head;
		printf("%d",length);
		for(i=0;i<length-1;i++)//冒泡排序法
		{
			p = q;
			while(p)
			{
				if(q->wage > p->wage )
				{
					temp->num  = p->num ;
					temp->sub = p->sub ;
					temp->bw =p->bw ;
					temp->wage =p->wage ;
					strcpy(temp->name ,p->name) ;
					temp->we =p->we;
					p->num  = q->num ;
					p->sub = q->sub ;
					p->bw =q->bw ;
					p->wage =q->wage ;
					strcpy(p->name ,q->name) ;
					p->we =q->we;
					q->num  = temp->num ;
					q->sub = temp->sub ;
					q->bw =temp->bw ;
					q->wage =temp->wage ;
					strcpy(q->name ,temp->name) ;
					q->we =temp->we;
				}
				p=p->next ;
			}
			q=q->next ;
		}
		/*while(q)//第一遍
		{
			MIN = q->wage ;
			p = q;
			while(p)//每一遍中取最小
			{
				if(q->wage > p->wage )
				{
					MIN = p->wage ;
					temp->num  = p->num ;
					temp->sub = p->sub ;
					temp->bw =p->bw ;
					temp->wage =p->wage ;
					strcpy(temp->name ,p->name) ;
					temp->we =p->we;
					p->num  = q->num ;
					p->sub = q->sub ;
					p->bw =q->bw ;
					p->wage =q->wage ;
					strcpy(p->name ,q->name) ;
					p->we =q->we;
					q->num  = temp->num ;
					q->sub = temp->sub ;
					q->bw =temp->bw ;
					q->wage =temp->wage ;
					strcpy(q->name ,temp->name) ;
					q->we =temp->we;
				}
				//if(p->next == NULL)  break;
				p=p->next ;
			}
			q=q->next ;
		}*/
		if(head)
		{	i = 1;
			p1 = head;
			printf("工号    姓名\t实发工资\t排名");
			while(p1)
			{
				printf("\n %d\t%s\t%d\t\t%d\n",p1->num ,p1->name,p1->wage,length );	
				p1 =p1->next ;
				length --;
			}
			//printf("\n %d\t%s\t%d\n",p1->num ,p1->name,p1->wage );	
		}
	}
}
/*
void sort1()
{
	struct info *p,*q;
	struct info *temp;
	temp = (struct info *)malloc(sizeof(LEN));
	int num = 0,j = 0;
	int i;
	q = head;
	while(q!=NULL)
	{
		q=q->next ;
		num++;
	}
	for(i=0;i<num-1;i++)
	{
		p=q=head;
		j=num-i-1;
		while(p->next !=NULL && j!= 0)
		{
			j--;
			if(p->wage >(p->next->wage ))
			{
				temp->num  = p->next->num ;
				temp->sub = p->next->sub ;
				temp->bw =p->next->bw ;
				temp->wage =p->next->wage ;
				strcpy(temp->name ,p->next->name) ;
				temp->we =p->next->we;
				p->num  = p->next->num ;
				p->sub = p->next->sub ;
				p->bw =p->next->bw ;
				p->wage =p->next->wage ;
				strcpy(p->name ,p->next->name) ;
				p->we =p->next->we;
				p->next->num  = temp->num ;
				p->next->sub = temp->sub ;
				p->next->bw =temp->bw ;
				p->next->wage =temp->wage ;
				strcpy(p->name ,temp->name) ;
				p->next->we =temp->we;
			}
			p = p->next ;
		}
	}
	if(head != NULL)
	{
		p = head;
		printf("工号    姓名\t实发工资");
			while(p->next !=0)
		{
			printf("\n %d\t%s\t%d\n",p->num ,p->name,p->wage );	
			p =p->next ;
		}
			printf("\n %d\t%s\t%d\n",p->num ,p->name,p->wage );
	}
}
*/

/*void sort1()
{
	struct info *p1;
	int length = 0;
	char *temp[10][10];
	int num;
	char *i[10];
	if(head == NULL)
		printf("链表为空！\n");
	else
	{
		p1=head;
		while(p1)
		{
			temp[length][0] = p1->name;
			num = p1->wage ;
			itoa(num ,i,10);
			temp[length][0] = i[0] ;
			p1=p1->next ;
			length++;
		}
		
		printf("%s",temp[0][1]);
	}
}*/