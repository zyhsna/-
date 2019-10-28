#include<stdio.h>
#include<stdlib.h>
#define LEN1 sizeof(info)
#define LEN2 sizeof(point)

typedef struct info{
	int num;
	info *next;
};//����

typedef struct point{
	info *front;
	info *rear;
} ;//ͷβָ��

int number = 1;//����
int sum = 0;//��ǰ�ڶ����е���Ŀ

void LineIn(point *q,int x)//����
{
	if(sum == 5)
		printf("\n��ǰ���������޷�ȡ�ţ�\n");
	else
	{
		printf("ȡ�ųɹ�����ǰ����%d",number);
		info *p;
		p = (info *)malloc(sizeof(LEN1));
		p->num = x;//�½ڵ�����
		p->next = NULL;
		q->rear ->next = p;//���½ڵ����ӵ�rear����
		q->rear = p;//rear����
		sum++;//����������++
		number++;//������һ
	}
}
int LineEmpty(point *q)//�ж϶ӿ�
{
	if(q->front  == q->rear )//��
		return 0;
	else//����
		return 1;
}

void Traverse(point *q)//��������
{
	if(!LineEmpty(q))//����Ϊ��
		printf("�����Ŷӣ�\n");
	else
	{
		info *p;
		p = q->front ->next ;//pָ���һ�������ݵĽڵ�
		do//��p������rearʱ
		{
			printf("\n%d�����Ŷ�",p->num );
			if(sum!=1)
				p =p->next ;
		}while(q->rear != p);
		//printf("\n%d�����Ŷ�",p->num );
	}
}
void LineOut(point *q)//����
{
	info *p;
	p = (info *)malloc(sizeof(LEN1));
	if(sum!=0)
	{
		p = q->front ->next ;//��һ�������ݵĽڵ�
		q->front->next = p->next; //���ӣ�front����
		if(p == q->rear )//ֻ��һ���ڵ�
			q->rear = q->front; //��rear����ָ��front
		sum--;//��������Ŀ--
		printf("\n��ǰȡ���ĺ�����%d��", p->num) ;
	}
	else
		printf("\n��ǰ�޺���ɽ�!");
}

void LineDestory(point *q)//��ն���
{
	q->rear = q->front ;
}

int main()
{
	int choice;
	int t = 1;
	int sign;
	info *q1;point *q2;
	q1 = (info *)malloc(sizeof(LEN1));//��������ͷ�ڵ�
	q2 = (point *)malloc(sizeof(LEN2));//����ͷβ�ڵ�
	q1->next =NULL;
	q2->front = q2->rear = q1;//��ͷβָ������ͷ���
	while(t)
	{
		printf("��ѡ�������");
		printf("\nȡ���밴1");
		printf("\n�к��밴2");
		printf("\n�鿴�ȴ������밴3");
		printf("\n�鿴�Ƿ��������Ŷ��밴4");
		printf("\n������к����밴5");
		printf("\n���������ѡ��");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				LineIn(q2,number);//�������
				break;
			case 2:
				LineOut(q2);
				break;
			case 3:
				Traverse(q2);
				break;
			case 4:
				sign = LineEmpty(q2);
				if (sign) printf("\n�����Ŷ�");
				else printf("\n�����Ŷ�");
				break;
			case 5:
				LineDestory(q2);
				printf("\n����գ�");
				break;
			default:printf("\n�������"); 
		}
		printf("\n�������ʹ��ϵͳ�𣿣������밴1��ֹͣ�밴0");
		scanf("%d",&t);
		system("cls");
	}
	return 0;
}