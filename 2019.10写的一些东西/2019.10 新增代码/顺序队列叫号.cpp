/*此顺序队列采用队头指向第一个数据的前一个位置，队尾为真实队尾的存储方式
 并且舍弃一个存储空间来判断队列是否满队*/
#include<stdio.h>
#define MAXSIZE 6//队列最大存储空间为5，因为舍弃一个空间

typedef struct queue{
	int num[MAXSIZE];
	int front,rear;
}queue;

int number = 1;
void queuein(queue *q , int x)//入队
{
	if((q->rear +1) % MAXSIZE == q->front)//如果队尾后移模MAXSIZE为队头的话则为队满
		printf("\n诊室已满无法叫号！\n");
	else
	{
		q->rear = (q->rear +1) % MAXSIZE;//队尾后移一个赋值
		q->num[q->rear] = x;
		printf("\n取号成功！当前为%d号\n",x);
		number++;//号数加一
	}
}

void queueout(queue *q)//队头出队
{
	int x;
	if(q->front == q->rear )//如果头尾相同则说明无数据
	{
		printf("队列空！");
	}
	else
	{
		q->front = (q->front + 1)%MAXSIZE;//队头后移并取出此时的数据，队头指向队列第一个元素前一个位置
		x = q->num[q->front];	
		printf("\n取出%d号\n",x);
	}
}

int main()
{
	int choice;
	queue list;//初始化队列
	list.front = list.rear = 0;
	while(1)
	{
		printf("请选择操作：");
		printf("\n取号请按1");
		printf("\n叫号请按2");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				queuein(&list,number);//数字入队
				break;
			case 2:
				queueout(&list);
				break;
		}
	}
	return 0;
}