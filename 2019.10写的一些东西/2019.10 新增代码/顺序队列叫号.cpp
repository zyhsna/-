/*��˳����в��ö�ͷָ���һ�����ݵ�ǰһ��λ�ã���βΪ��ʵ��β�Ĵ洢��ʽ
 ��������һ���洢�ռ����ж϶����Ƿ�����*/
#include<stdio.h>
#define MAXSIZE 6//�������洢�ռ�Ϊ5����Ϊ����һ���ռ�

typedef struct queue{
	int num[MAXSIZE];
	int front,rear;
}queue;

int number = 1;
void queuein(queue *q , int x)//���
{
	if((q->rear +1) % MAXSIZE == q->front)//�����β����ģMAXSIZEΪ��ͷ�Ļ���Ϊ����
		printf("\n���������޷��кţ�\n");
	else
	{
		q->rear = (q->rear +1) % MAXSIZE;//��β����һ����ֵ
		q->num[q->rear] = x;
		printf("\nȡ�ųɹ�����ǰΪ%d��\n",x);
		number++;//������һ
	}
}

void queueout(queue *q)//��ͷ����
{
	int x;
	if(q->front == q->rear )//���ͷβ��ͬ��˵��������
	{
		printf("���пգ�");
	}
	else
	{
		q->front = (q->front + 1)%MAXSIZE;//��ͷ���Ʋ�ȡ����ʱ�����ݣ���ͷָ����е�һ��Ԫ��ǰһ��λ��
		x = q->num[q->front];	
		printf("\nȡ��%d��\n",x);
	}
}

int main()
{
	int choice;
	queue list;//��ʼ������
	list.front = list.rear = 0;
	while(1)
	{
		printf("��ѡ�������");
		printf("\nȡ���밴1");
		printf("\n�к��밴2");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				queuein(&list,number);//�������
				break;
			case 2:
				queueout(&list);
				break;
		}
	}
	return 0;
}