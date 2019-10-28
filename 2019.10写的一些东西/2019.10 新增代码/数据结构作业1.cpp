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
		printf("���밴1\n");
		printf("�����밴2\n");
		printf("ɾ���ظ��밴3\n");
		printf("ɾ��һ����Χ�밴4\n");
		printf("�����밴5\n");
		printf("\n�˳���7\n");
		printf("���������ѡ��");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					length();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 2:
					insert();
					traverse();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
		
				case 3:
					delrepeatition();
					traverse();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 4:
					delrange();
					traverse();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
				case 5:
					traverse();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 7: q = 0;break;
			
				default:
				printf("�������󣡣�\n");
				printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
				scanf("%d",&q);
			}
		system("cls");//����
	}
	return 0;
}

int length()
{
	struct info *p;
	p = head;
	int LEN =0;
	//if(head == NULL)
		//printf("��ǰ�б�Ϊ���б�����ڵ����Ϊ0\n");
		
	//else
		while(p)
		{
			LEN++;
			p = p->next ;
		}
		printf("��ǰ����ڵ����Ϊ%d\n",LEN);
	return LEN;
}

void insert()
{
	struct info *p1,*p2,*p3;
	p2 =p3= head;
	p1 = (struct info *)malloc(sizeof(LENGTH));//����ռ�
	printf("���������֣�");
	scanf("%d",&p1->num);
	p1->next = NULL;
	if(head == NULL)
	{
		head = p1;//���û�ڵ㣬��ֱ�ӽ�p1����Ϊ��һ��
	}
	else
	{
		while(p1->num > p2->num && p2->next!=NULL)//��p1����p2��p2��Ϊ���һ���ڵ�
		{
			p3 = p2;//����
			p2 = p2->next;
		}
		if((p1->num) <= (p2->num))
		{
			if(head == p2 )//p1����С�ڵ��ڵ�һ������
			{
				p1->next =p2;
				head = p1;
				printf("%",head->num);
			}
			else//p1��С���ڱ��������м�ʱ
			{
				p1->next = p2;
				p3->next =p1;
			}
		}
		else//���
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
		printf("����Ϊ������");
	else
	{
		printf("��������Ҫɾ���ķ�Χ��");  //ȷ����Χ 
		printf("\n��߷�ΧΪ��");
		scanf("%d",&left);
		printf("\n�ұ߷�ΧΪ��");
		scanf("%d",&right);
		pre=head;
		cur = head->next;
		while(pre!=NULL && sign ==1)//ѭ���ж�ĳ�����Ƿ��������Χ
		{
			if(head->num >=left && head->num <=right)//���ͷָ����
			{
				head=head->next ;
				pre = head;
				if(cur!=NULL)//���ֻ��һ���ڵ�
				cur=cur->next ;
			}
			else //ͷָ�벻��
			{
				if(cur->num >=left && cur->num <=right )//cur��ָ������ݴ��������Χ
				{
					pre->next =cur->next ;//��pre���ӵ�cur����һ��ָ��
					if(cur->next !=NULL)//���cur��Ϊ���һ���ڵ㣬��cur����
						cur=cur->next ;
					else//����curΪ���һ��ָ�룬sign��ֵΪ0���������
						sign =0;
				}
			
				else//cur�����������Χ
				{
					pre=cur;//��pre����
					if(cur->next !=NULL)//�ж�cur�Ƿ�Ϊ���һ���ڵ�
						cur=cur->next ;//������cur����
					else
						sign =0;//�����������
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
		printf("������Ϊ������\n");
    else
	{
		while(p3)
		{			
			printf("��%-6d��\n",p3->num);
			p3 = p3->next ;
		}
	}
}
void delrepeatition()
{
	int temp;//temp���Ҫ�ж��Ƿ��ظ�������
	struct info *p1,*cur,*pre;
	p1=head;
	if(head == NULL)//û���ݵ�Ȼ��Ҫ�ж���
	{
		printf("\n��ǰ����Ϊ�գ�\n");
	}
	else
	{
		while(p1!= NULL)//��һ��ѭ��
		{
			temp = p1->num ;//�������
			pre = p1 ;//
			cur=p1->next ;//��cur���ӵ�p1����һ���ڵ�
			while(cur!=NULL)//��cur��ΪNULL��һֱ�����ƶ�
			{
				if(cur-> num == temp)//�ж��Ƿ�һ��
					pre->next =cur->next  ;//���һ��������ڵ�ǰһ���ڵ����ӵ�����
				else  pre=cur;//��һ����pre���ƣ��Ա���һ��һ��ʱɾ���ڵ�
					cur =cur->next ; //cur����
			}
			p1=p1->next ;//p1����,����Ҫ�ж��Ƿ��ظ������ָı�
		}
	}
}
