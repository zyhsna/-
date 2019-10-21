#include<stdio.h>
#include<stdlib.h>

#define LEN sizeof(Elem)

typedef struct Elem{
	int num;
	Elem *next;
};
int length =0;

Elem *Ahead = NULL;
Elem *Bhead = NULL;
Elem *Chead = NULL;

void Ainsert();
void Binsert();
void ATraverse();
void BTraverse();
void CTraverse();
void Merge();
int main()
{
	int q = 1;
	int choice;
	while(q)
	{	
		printf("����A�����밴1\n");
		printf("����B�����밴2\n");
		printf("A��������밴3\n");
		printf("B��������밴4\n");
		printf("�ϲ������밴5\n");
		printf("\n�˳���7\n");
		printf("���������ѡ��");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					ATraverse();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 2:
					BTraverse();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
		
				case 3:
					Ainsert();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 4:
					Binsert();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
				case 5:
					Merge();
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


void ATraverse()
{
	Elem *p1;
	p1 = Ahead;
	if(p1 == NULL)
		printf("������Ϊ������\n");
    else
	{
		while(p1)
		{			
			printf("��%-6d��\n",p1->num);
			p1 = p1->next ;
		}
	}
}

void BTraverse()
{
	Elem *p1;
	p1 = Bhead;
	if(p1 == NULL)
		printf("������Ϊ������\n");
    else
	{
		while(p1)
		{			
			printf("��%-6d��\n",p1->num);
			p1 = p1->next ;
		}
	}
}


void Ainsert()
{
	Elem *p1,*p2,*p3;
	p2 =p3= Ahead;
	p1 = (Elem *)malloc(sizeof(LEN));//����ռ�
	printf("���������֣�");
	scanf("%d",&p1->num);
	p1->next = NULL;
	if(Ahead == NULL)
	{
		Ahead = p1;//���û�ڵ㣬��ֱ�ӽ�p1����Ϊ��һ��
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
			if(Ahead == p2 )//p1����С�ڵ��ڵ�һ������
			{
				p1->next =p2;
				Ahead = p1;
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


void Binsert()
{
	Elem *p1,*p2,*p3;
	p2 =p3= Bhead;
	p1 = (Elem *)malloc(sizeof(LEN));//����ռ�
	printf("���������֣�");
	scanf("%d",&p1->num);
	p1->next = NULL;
	if(Bhead == NULL)
	{
		Bhead = p1;//���û�ڵ㣬��ֱ�ӽ�p1����Ϊ��һ��
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
			if(Bhead == p2 )//p1����С�ڵ��ڵ�һ������
			{
				p1->next =p2;
				Bhead = p1;
				printf("%",Ahead->num);
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


/*void Merge()
{
	Elem *Apre,*Acur,*Bpre,*Bcur,*Cpre,*Ccur;
	if(Ahead ==NULL && Bhead ==NULL)
		printf("�޿ɲ�������");
	else
	{
		Apre = Ahead;
		Bpre = Bhead;
		Acur = Ahead->next ;
		Bcur = Bhead->next ;
		Cpre = Chead;
		while(Apre&&Bpre)
		{
			if(Apre>=Bpre)//Apre���ֱ�Bpre���ִ�
			{
				if(Chead == NULL)//c����Ϊ������
					Cpre = Apre;
				else//c������������
					Apre->next = Cpre;
				Apre =Acur;
				if(Acur->next !=NULL)
					Acur = Acur->next ;
				
			}
			else//Bpre���ֱ�Apre���ִ�
			{
				if(Chead == NULL)//c����Ϊ������
					Cpre = Bpre;
				else//c������������
					Bpre->next = Cpre;
				Bpre =Bcur;
				if(Bcur->next !=NULL)
					Bcur = Bcur->next ;
				
			}
		}
		if(Apre)//a�����л�������
		{}
		if(Bpre)//b�����л�������
		{}
	}
	}
*/


void Merge()
{
	Elem *A,*B,*p1,*p2;
	p1=p2 = (Elem *)malloc(sizeof(LEN));
	A=Ahead;
	B=Bhead;
	int i=0;
	int j;
	int max,tem;
	int temp[200];
	while(A)
	{
		temp[length] = A->num ;
		A = A->next ;
		length++;
	}
	while(B)
	{
		temp[length] = B->num ;
		B=B->next ;
		length++;
	}
	printf("ab����һ����%d��Ԫ��\n",length);
	for(i=0;i<length;i++)
	{
		printf("��%-6d��\n",temp[i]);
	}
	for(i=0;i<length;i++)
	{
		max=temp[i];
		for(j=i+1;j<length;j++)
		{
			if(temp[j]>max)
			{
				max = temp[j];
				tem=temp[i];
				temp[i]=temp[j];
				temp[j]=tem;
			}
		}
	}
	printf("�������\n");
	/*for(i=0;i<length;i++)
	{
		printf("��%-6d��\n",temp[i]);
	}*/
	i = 0;
	while(length)
	{
		p1->num =temp[i];
		p1->next =NULL;
		if(Chead == NULL)
			Chead = p1;
		else
			p2->next =p1;
		p2=p1;
		p1 = (Elem *)malloc(sizeof(LEN));
		i++;length--;
	}
	CTraverse();
}

void CTraverse()
{
	Elem *p1;
	p1 = Chead;
	if(p1 == NULL)
		printf("������Ϊ������\n");
    else
	{
		while(p1)
		{			
			printf("��%-6d��\n",p1->num);
			p1 = p1->next ;
		}
	}
}