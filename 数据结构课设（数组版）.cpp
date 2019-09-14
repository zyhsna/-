#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 300

struct  info 
{
	int num;
	char name[10];
	int bw;      //basic wage 基本工资
	int sub;	 //subsidy 津贴
	int we;		 //water & electricity 水电费
	int wage;	 //实发工资
}worker[10];

void read();
void browse();
void save();
void search();
void add();
void del();
void sort();
void summary();
void summary1();
void sort1();

int j = 0;//全局变量，说明有多少条信息


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
					add();
					sort();
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

void browse()
{
	int a;
	for(a=0 ; a<j ; a++)//对系统中的信息进行输出
	{	printf("工号\t姓名\t基本工资\t补贴\t水电费\t实发工资");
		printf("\n %d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d",worker[a].num,worker[a].name ,worker[a].bw ,worker[a].sub,worker[a].we ,worker[a].wage );
		printf("\n\n\n");
	}
	if(j==0)//判断系统中是否有信息
		printf("当前系统无信息\n\n\n");
}

void read()
{
	FILE *fp;
	int sign = 1;
	if((fp = fopen("worker.txt","r"))==NULL);
	{
		printf("无法打开文件！！\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%d%d%d%d",&worker[j].num,&worker[j].name,&worker[j].bw,&worker[j].sub,&worker[j].we,&worker[j].wage);
		sign = 0;
		j++;
	}
	fclose(fp);
	if(sign == 1)
		printf("数据读取失败！\n");
	else
		printf("数据读取成功！\n");
	printf("已录入%d条信息\n",j);
}


void save()
{
	FILE *fp;//定义一个文件指针
	int i;
	int sign = 1;//判断是否完成数据存盘
	if((fp = fopen("worker.txt","w"))==NULL) //打开输出文件
	{
		printf("文件无法打开！\n");
		return;
	}
	for(i=0;i<j;i++)
		{
			fprintf(fp,"%d %s %d %d %d %d\n",worker[i].num,worker[i].name,worker[i].bw,worker[i].sub,worker[i].we,worker[i].wage);		
		}
	fclose(fp);//关闭文件
	if(sign ==0) // 判断是否存盘成功
		printf("数据存盘失败！！\n");
	else
		printf("数据存盘成功！");
}

void search()
{
	int a;
	int temp;//用来存放要查找的工号
	printf("输入查找的工号\n");
	scanf("%d",&temp);
	for(a = 0;a <=j ; a++)//遍历
		{
			if(temp == worker[a].num)//看是否相符合
				{
					printf("已找到信息！\n");
					printf("工号\t姓名\t基本工资\t补贴\t水电费\t实发工资");
					printf("\n %d  %s\t  %d\t   %d\t   %d\t   %d",worker[a].num,worker[a].name ,worker[a].bw ,worker[a].sub,worker[a].we ,worker[a].wage );
					printf("\n\n\n\n\n");
					break;
				}
			if(a==j)
				printf("\n未找到该信息！！\n");
		}
}


void del()
{
	int a;
	int b;
	int sign = 1;
	char temp[100];
	printf("当前系统中有以下信息\n");
	browse();
	if(worker[j-1].num != 0 && j>=1)
	{
		printf("请输入你要删除的人名");
		scanf("%s",&temp);
		for(a=0;a<j;a++)
			{	
				if (strcmp(temp,worker[a].name)==0)//查询是否有该名字
					{
						for(b=a;b<j;b++)
							{
								worker[b]=worker[b+1];//将要删除的数据后面一条复制到要删除的位置
							}
						j -= 1;//全局变量减一，代表所拥有的数据减一条
						printf("\n\n");
						printf("删除完成！！\n\n");
						sign = 0;
						break;
					}
				else
					continue;
			}
	if(sign == 1)
		printf("未找到该人！！\n");
	}
}

void add()
{
	printf("请输入工号\n");
	scanf("%d",&worker[j].num);
	printf("请输入姓名\n");
	scanf("%s",&worker[j].name);
	printf("请输入基本工资\n");
	scanf("%d",&worker[j].bw);
	printf("请输入补贴\n");
	scanf("%d",&worker[j].sub);
	printf("请输入水电费\n");
	scanf("%d",&worker[j].we);
	worker[j].wage = worker[j].bw +worker[j].sub -worker[j].we ;
	j++;
}


void sort()
{
	info temp;
	int i;
	int k;
	for(i=0;i<j-1;i++)
		{
			for(k=0;k<j-i-1;k++)    //冒泡排序法
				{
					if(worker[k].num>worker[k+1].num )   //判断一趟排序中，前后两个名字
						{
							temp =worker[k];
							worker[k]= worker[k+1];
							worker[k+1]= temp;
						}
				}
		}
}

void summary()
{
	int a =0;
	int b = 0;
	int c = 0;
	int i;
	for(i=0;i<j;i++)
	{
		a += worker[i].bw ;
		b += worker[i].sub ;
		c += worker[i].we;
	}
	printf("总基本工资%d\n",a);
	printf("总补贴%d\n",b);
	printf("总水电费%d\n",c);
}

void summary1()
{
	int a;
	for(a=0 ; a<j ; a++)//对系统中的信息进行输出
	{	printf("工号    姓名\t实发工资");
		printf("\n %d\t%s\t%d",worker[a].num,worker[a].name ,worker[a].wage );
		printf("\n\n\n");
	}
}

void sort1()
{
	info temp;
	int i;
	int k;
	for(i=0;i<j-1;i++)
		{
			for(k=0;k<j-i-1;k++)    //冒泡排序法
				{
					if(worker[k].wage>worker[k+1].wage )   //判断一趟排序中，前后两个名字
						{
							temp =worker[k];
							worker[k]= worker[k+1];
							worker[k+1]= temp;
						}
				}
		}
	for(i=0;i<j;i++)
	{
		printf("实发工资第%d名",j - i);
		printf("工号\t姓名\t基本工资\t补贴\t水电费\t实发工资");
		printf("\n %d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d",worker[i].num,worker[i].name ,worker[i].bw ,worker[i].sub,worker[i].we ,worker[i].wage );
		printf("\n\n\n");
	}
}

