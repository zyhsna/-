#include<stdio.h>
#include<stdlib.h>
#define LEN1 sizeof(info)
#define LEN2 sizeof(point)

typedef struct info{
	int num;
	info *next;
};//队列

typedef struct point{
	info *front;
	info *rear;
} ;//头尾指针

int number = 1;//号数
int sum = 0;//当前在队列中的数目

void LineIn(point *q,int x)//入列
{
	if(sum == 5)
		printf("\n当前诊室已满无法取号！\n");
	else
	{
		printf("取号成功！当前号数%d",number);
		info *p;
		p = (info *)malloc(sizeof(LEN1));
		p->num = x;//新节点数据
		p->next = NULL;
		q->rear ->next = p;//将新节点连接到rear后面
		q->rear = p;//rear后移
		sum++;//队列中数量++
		number++;//号数加一
	}
}
int LineEmpty(point *q)//判断队空
{
	if(q->front  == q->rear )//空
		return 0;
	else//不空
		return 1;
}

void Traverse(point *q)//遍历队列
{
	if(!LineEmpty(q))//队列为空
		printf("无人排队！\n");
	else
	{
		info *p;
		p = q->front ->next ;//p指向第一个有数据的节点
		do//当p不等于rear时
		{
			printf("\n%d号在排队",p->num );
			if(sum!=1)
				p =p->next ;
		}while(q->rear != p);
		//printf("\n%d号在排队",p->num );
	}
}
void LineOut(point *q)//出队
{
	info *p;
	p = (info *)malloc(sizeof(LEN1));
	if(sum!=0)
	{
		p = q->front ->next ;//第一个有数据的节点
		q->front->next = p->next; //出队，front后移
		if(p == q->rear )//只有一个节点
			q->rear = q->front; //将rear重新指向front
		sum--;//队列中数目--
		printf("\n当前取出的号码是%d号", p->num) ;
	}
	else
		printf("\n当前无号码可叫!");
}

void LineDestory(point *q)//清空队列
{
	q->rear = q->front ;
}

int main()
{
	int choice;
	int t = 1;
	int sign;
	info *q1;point *q2;
	q1 = (info *)malloc(sizeof(LEN1));//申请链队头节点
	q2 = (point *)malloc(sizeof(LEN2));//申请头尾节点
	q1->next =NULL;
	q2->front = q2->rear = q1;//将头尾指针连接头结点
	while(t)
	{
		printf("请选择操作：");
		printf("\n取号请按1");
		printf("\n叫号请按2");
		printf("\n查看等待号数请按3");
		printf("\n查看是否有人在排队请按4");
		printf("\n清空所有号码请按5");
		printf("\n请输入你的选择");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				LineIn(q2,number);//数字入队
				break;
			case 2:
				LineOut(q2);
				break;
			case 3:
				Traverse(q2);
				break;
			case 4:
				sign = LineEmpty(q2);
				if (sign) printf("\n有人排队");
				else printf("\n无人排队");
				break;
			case 5:
				LineDestory(q2);
				printf("\n已清空！");
				break;
			default:printf("\n输入错误！"); 
		}
		printf("\n还想继续使用系统吗？，继续请按1，停止请按0");
		scanf("%d",&t);
		system("cls");
	}
	return 0;
}