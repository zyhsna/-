#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(info)

struct  info 
{
	int num;
	char name[10];
	int bw;      //basic wage 基本工资
	int sub;	 //subsidy 津贴
	int we;		 //water & electricity 水电费
	int wage;	 //实发工资
	struct info *next;
};

struct info *head = NULL;

void read();
void print();
void save();
void search();
/*void add();*/
void del();
/*void sort();*/
void summary();
void summary1();
void sort1();
void insert();
int j =0;

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
					/*add();
					sort()*/;
					insert();
					print();
					save();
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
	}
	return 0;
}

/*void add()
{
	struct info *p1,*p2;
	int n = 0;
	head =NULL;
	p1 = p2 = (struct info *)malloc(LEN);
	printf("请输入工人的工号");
	scanf("%d,%s",&p1->num);
	while(p1->num != 0)
	{
		printf("请输入工人的姓名：");
		scanf("%s",&p1->name );
		printf("请输入工人的基本工资：");
		scanf("%d",&p1->bw );
		printf("请输入工人的补贴：");
		scanf("%d",&p1->sub );
		printf("请输入工人的水电费：");
		scanf("%d",&p1->we );
		p1->wage = (p1->bw) + (p1->sub) - (p1->we);
		if(n == 0)
		{
			n ++;
			head = p1;
			j++;
		}
		else
		{p2->next = p1;}
		p2 = p1;
		p1 = (struct info *)malloc(LEN);
		printf("请输入工人的工号");
		scanf("%d",&p1->num);
		j++;
	}
	p2 ->next = NULL;
}*/

void print()
{
	struct info *p3;
	p3 = head;
	if(head == NULL)
		printf("该链表为空链表\n");
    printf("│工 号│姓 名│基 本 工 资│补    贴│水 电  费│  实发工资│\n");
	while(p3->next != NULL)
	{	
		
		printf("│%d	  │%s	│%d	  │%d    │ %d    │    %d      │\n",p3->num ,p3->name ,p3->bw ,p3->sub ,p3->we,p3->wage );
		p3 = p3->next ;
	}
	printf("│%d	  │%s	│%d	  │%d    │ %d    │    %d      │\n",p3->num ,p3->name ,p3->bw ,p3->sub ,p3->we,p3->wage );
	
}

void del()
{
	char temp[10];
	print();
	int sign = 0;
	printf("请输入要删除工人的姓名");
	scanf("%s",&temp);
	struct info *p3,*p4;
	p3 =head ;
	if(p3 == NULL)
		printf("该链表为空链表，无法删除！");
	if(strcmp(head->name,temp)==0)
		{head = head->next ;
		 j --;
		 sign = 1;
		}
	else
	{
		while(strcmp(p3 ->name,temp)!=0  && p3->next != NULL)
		{
			p4 = p3;
			p3 = p3->next ;
		}
		if(strcmp(p3 ->name,temp)==0)
		{
			p4->next = p3->next ;
			j --;
			sign = 1;
		}
		else
			printf("未找到！");
	}
	if(sign == 1)
		printf("\n已删除！！\n");
}

void search()
{
	struct info *p1;
	int a,i;
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
			printf("工号	姓名	基本工资	补贴	水电费	实发工资\n");
			printf("%d	%s	%d	%d	%d	%d\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage);
			sign = 1;
		}
		else	
		{
			while(p1->next !=NULL)
			{
				if(a==p1->num )	
				{
					printf("工号	姓名	基本工资	补贴	水电费	实发工资\n");
					printf("%d	%s	%d	%d	%d	%d\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage);
					sign = 1;
					break;
				}
				else
					p1 = p1->next ;
			}	
		if(a==p1->num && sign !=1)
			{
				printf("工号	姓名	基本工资	补贴	水电费	实发工资\n");
				printf("%d	%s	%d	%d	%d	%d",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage);
				sign = 1;
			}
		}
	}
	if(sign == 1)
		printf("\n已找到该人！！\n");
	else
		printf("未找到此人！！\n");
}


/*void sort()
{
	struct info *p,*q;
	int num = 0,j = 0;
	int i;
	q = head;
	while(q!=0)
	{
		q=q->next ;
		num++;
	}
	for(i=0;i<num-1;i++)
	{
		p=q=head;
		j=num-i-1;
		while(p->next !=NULL & j!= 0)
		{
			j--;
			if(p->num >(p->next->num ))
			{
				if(p==head) head = p->next ;
				else q->next =p->next;
				q->next =p->next ;
				q= q->next ;
				p->next = q->next ;
				q->next =p;
				p=q;
			}
			q=p;
			p = p->next ;
		}
	}
}*/

void summary()
{
	int a =0;
	int b = 0;
	int c = 0;
	int i;
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
	struct info *p,*q;
	int num = 0,j = 0;
	int i;
	q = head;
	while(q!=0)
	{
		q=q->next ;
		num++;
	}
	for(i=0;i<num-1;i++)
	{
		p=q=head;
		j=num-i-1;
		while(p->next !=NULL & j!= 0)
		{
			j--;
			if(p->wage >(p->next->wage ))
			{
				if(p==head) head = p->next ;
				else q->next =p->next;
				q->next =p->next ;
				q= q->next ;
				p->next = q->next ;
				q->next =p;
				p=q;
			}
			q=p;
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
	
		else p2 ->next = p1;
		p2 = p1;
		p1 = (struct info *)malloc(LEN);
		fscanf(fp,"%d%s%d%d%d%d",&p1->num,&p1->name,&p1->bw,&p1->sub,&p1->we,&p1->wage);
		n++;
	}
	p2->next =NULL;
	fclose(fp);
	j+=n;
	printf("读入%d条数据！\n",n);
}


void save()
{
	FILE *fp;
	struct info *p1;
	int sign =0;
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
		sign = 1;
	}
	fprintf(fp,"%d %s %d %d %d %d\n",p1->num,p1->name,p1->bw,p1->sub,p1->we,p1->wage);
	fclose(fp);
	if(sign ==0) // 判断是否存盘成功
		printf("数据存盘失败！！\n");
	else
		printf("数据存盘成功！");
}

void insert()
{
	struct info *p1,*p2,*p3;
	p2=p1 =head;
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
	p3->next =NULL;
	printf("%d %s %d %d %d %d\n",p1->num,p1->name,p1->bw,p1->sub,p1->we,p1->wage);
	printf("%d %s %d %d %d %d\n",p3->num,p3->name,p3->bw,p3->sub,p3->we,p3->wage);
	if(head == NULL)
	{
		head = p3;
		p3->next =NULL;
	}
	else
	{
		while((p3->num) > (p1->num)  && p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next ;
		}
		if((p3->num) <= (p1->num))
		{
			if(head == p1)
				head = p3;
			else
				p2->next =p3;
			p3->next =p1;
		}
		else
		{
			p1->next =p3;	
			p3->next = NULL;
		}
	}
	j += 1;
}


