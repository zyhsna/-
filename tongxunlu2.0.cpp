#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(info)

struct info
{
	char name[10];
    char phone[20];
	char email[20];
	char type;
	struct info *next;
};

void insert();
/*void add();*/
void read();
void save();
void search();
void summary();
void browse();
void del();
void change();

struct info *head = NULL;



int main()

{	
	read();
	int q = 1;//q为标志，代表是否继续进行菜单操作
	while (q)
	{
		int choice;
		printf("———欢迎使用通讯录系统 ————    produced by zyh\n\n");  /*菜单界面*/
		printf("———增加新的联系人，请按1———\n\n");
		printf("———浏览所有联系人，请按2———\n\n");
		printf("———排序所有联系人，请按3———\n\n");
		printf("———查询一个联系人，请按4———\n\n");
		printf("———显示某类联系人，请按5———\n\n");
		printf("———删除一个联系人，请按6———\n\n");
		printf("———修改一个联系人，请按7———\n\n");
		printf("———  存盘联系人  ，请按8———\n\n");
		printf("———  读取联系人  ，请按9———\n\n");
		printf("———    退出系统  ，请按0———\n");
		printf("请输入你的选择");
		scanf("%d",&choice);
		switch(choice)
			{case 1:insert()/*add()*/;break;
			 case 2:browse();break;
			 case 3:break;
			 case 4:search();break;
			 case 5:summary();break;
			 case 6:del();break;
			 case 7:change();break;
			 case 8:save();break;
			 case 9:read();break;
			}
			
		if (choice == 0)
			break ;
		printf("需要继续使用本系统吗？继续请按1，停止请按0");
		scanf("%d",&q);

	}
	return 0;
}


void browse()
{
	struct info *p1;
	if(head == NULL)
	{
		printf("\n\n当前无联系人信息！！\n");
	}
	else
	{
		printf("姓名   手机  电子邮箱  类别");
		p1 = head;
		while(p1->next != NULL)
		{
			printf("\n%s %s %s %c\n",p1->name ,p1->phone ,p1->email ,p1->type );
			p1 = p1->next ;
		}
		printf("\n%s %s %s %c\n",p1->name ,p1->phone ,p1->email ,p1->type );
	}
}


void insert()
{
	struct info *p1,*p2,*p3;
	p3 = (struct info *)malloc(LEN);
	p2=p1 =head;
	printf("\n请输入联系人的名字\n");
	scanf("%s",&p3->name );
	printf("\n请输入联系人的手机号\n");
	scanf("%s",&p3->phone );
	printf("\n请输入联系人的电子邮箱\n");
	scanf("%s",&p3->email );
	printf("\n请输入联系人的类别\n");
	scanf("%c",&p3->type );
	p3->next =NULL;
	if(head==NULL)
		{
			head =p3;
			p3->next =NULL;
		}
	else
	{
		while(strcmp(p3->name ,p1->name )>0 && p1->next !=NULL)
		{
			p2 = p1;
			p1 = p1->next ;
		}
		if (strcmp(p3->name ,p1->name)<0)
		{
			if(head == p1)
			{
				head = p3;
				p3->next =p1;
			}
			else
			{
				p2->next = p3;
				p3->next = p1;
		    }
		}
		else
		{
			p1->next =p3;
			p3->next = NULL;
		}
	}
}


void save()
{
	FILE *fp;
	struct info *p1;
	int sign =0;
	if((fp = fopen("student.txt","w"))==NULL) //打开输出文件
	{
		printf("文件无法打开！\n");
		return;
	}
	p1 = head;
	while(p1->next !=NULL)
	{
		fprintf(fp,"%s %s %s %s\n",p1->name,&p1->phone,&p1->email,&p1->type);	
		p1=p1->next ;
		sign = 1;
	}
	fprintf(fp,"%s %s %s %c",p1->name,p1->phone,p1->email,p1->type);
	sign = 1;
	fclose(fp);
	if(sign ==0) // 判断是否存盘成功
		printf("数据存盘失败！！\n");
	else
		printf("数据存盘成功！");
}



void read()
{
	FILE *fp;
	struct info *p1,*p2;
	p2=p1=(struct info *)malloc(LEN);
	int n = 0;
	if((fp=fopen("student.txt","r"))==NULL)
	{
		printf("无法打开文件！！\n");
		exit(0);
	}
	
	while(1)
	{
		
		fscanf(fp,"%s%s%s%s",&p1->name,&p1->phone,&p1->email,&p1->type);
		if(n==0) head = p1;
		

		else p2->next = p1;
		p2 = p1;
		p1 = (struct info *)malloc(LEN);
		n++;
		if(feof(fp))
			break;
		
		}
	p2->next =NULL;
	fclose(fp);
	printf("读入%d条数据！\n",n);
}


void search()
{
	struct info *p1;
	int i;
	char a[10];
	int sign = 0;
	if(head == NULL)
		printf("\n该链表为空链表！\n");
	else
	{	
		printf("请输入要寻找的人名");
		scanf("%s",&a);
		p1 = head;
		if(strcmp(p1->name,a)==0)
		{
			printf("姓名   手机  电子邮箱  类别");
			printf("\n%s %s %s %c\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
			sign = 1;
		}
		else	
		{
			while(p1->next !=NULL)
			{
				if(strcmp(a,p1->name)==0 )	
				{
					printf("姓名   手机  电子邮箱  类别");
					printf("\n%s %s %s %c\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
					sign = 1;
					break;
				}
				else
					p1 = p1->next ;
			}	
		if(strcmp(a,p1->name)==0 && sign !=1)
			{
				printf("姓名   手机  电子邮箱  类别");
				printf("\n%s %s %s %c\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
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
	char temp[10];
	browse();
	int sign = 0;
	printf("请输入要删除的姓名");
	scanf("%s",&temp);
	struct info *p3,*p4;
	p3 =head ;
	if(p3 == NULL)
		printf("该链表为空链表，无法删除！");
	if(strcmp(head->name,temp)==0)
		{head = head->next ;
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
			sign = 1;
		}
		else
			printf("未找到！");
	}
	if(sign == 1)
		printf("\n已删除！！\n");
}


void change()
{
	struct info *p1;
	int sign = 1;
	p1 = head;
	char temp[10];
	browse();
	if(head == NULL)
		printf("\n无法修改！\n");
	else
	{
		printf("请输入要修改的姓名");
		scanf("%s",&temp);
		if(strcmp(head->name ,temp)==0)
		{
			printf("\n请输入联系人的名字\n");
			scanf("%s",&head->name );
			printf("\n请输入联系人的手机号\n");
			scanf("%s",&head->phone );
			printf("\n请输入联系人的电子邮箱\n");
			scanf("%s",&head->email );
			printf("\n请输入联系人的类别\n");
			scanf("%s",&head->type );
			sign = 0;
		}
		while(strcmp(p1->name,temp)!=0 && p1->next !=NULL)
		{
			p1 = p1->next ;
		}
		if(strcmp(p1->name ,temp)==0)
		{
			printf("\n请输入联系人的名字\n");
			scanf("%s",&p1->name );
			printf("\n请输入联系人的手机号\n");
			scanf("%s",&p1->phone );
			printf("\n请输入联系人的电子邮箱\n");
			scanf("%s",&p1->email );
			printf("\n请输入联系人的类别\n");
			scanf("%s",&p1->type );
			sign = 0;
		}
	}
	if(sign == 0)
		printf("\n修改成功！！\n");
	else
		printf("\n查无此人！！\n");
}

void summary()
{
	int target;
	struct info *p1;
	if(head == NULL)
		printf("无联系人信息！！");
	else
	{
		printf("请选择要查找的联系人类别：（1是A类，2是B类，3是C类）");
		scanf("%d",&target);
		if(target==1)
		{
			p1 = head;
			while( p1->next !=NULL)
			{
				if(p1->type == 'a' || p1->type == 'A')
				{printf("姓名   手机  电子邮箱  类别");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );}
				p1 = p1->next ;
			}
			if(p1->type == 'a' || p1->type == 'A')
			{
				printf("姓名   手机  电子邮箱  类别");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
			}
		}
		
		if(target==2)
		{
			p1 = head;
			while(p1->next !=NULL)
			{
				if(p1->type == 'b' || p1->type == 'B')
				{printf("姓名   手机  电子邮箱  类别");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );}
				p1 = p1->next ;
			}
			if(p1->type == 'b' || p1->type == 'B')
			{
				printf("姓名   手机  电子邮箱  类别");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
			}
		}
		
		if(target==3)
		{
			p1 = head;
			while(p1->next !=NULL)
			{
				if(p1->type == 'c' || p1->type == 'C')
				{printf("姓名   手机  电子邮箱  类别");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );}
				p1 = p1->next ;
			}
			if(p1->type == 'c' || p1->type == 'C')
			{
				printf("姓名   手机  电子邮箱  类别");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
			}
		}
	}
}

/*void add()
{
	struct info *p1,*p2;
	int n = 0;
	p1 = p2 = (struct info *)malloc(LEN);
	printf("请输入姓名");
	scanf("%s",&p1->name);
	while(strcmp(p1->name ,"zxc")!=0)
	{
		printf("请输入手机号：");
		scanf("%s",&p1->phone );
		printf("请输入电子邮箱：");
		scanf("%s",&p1->email );
		printf("请输入类别：");
		scanf("%s",&p1->type );
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
		printf("请输入姓名");
		scanf("%s",&p1->name);
		j++;
	}
	p2 ->next = NULL;
}*/