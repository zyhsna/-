#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(info)

struct  info 
{
	int num;
	char name[10];
	int bw;      //basic wage ��������
	int sub;	 //subsidy ����
	int we;		 //water & electricity ˮ���
	int wage;	 //ʵ������
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
		printf("��������ӭʹ�ù�����Ϣ����ϵͳ ��������    produced by zyh\n\n");  /*�˵�����*/
		printf("��ѯ������Ϣ�밴1\n");
		printf("���빤����Ϣ�밴2\n");
		printf("ɾ��������Ϣ�밴3\n");
		printf("��ѯ����ʵ�������밴4\n");
		printf("�������ܶ��밴5\n");
		printf("�������밴6\n");
		printf("�˳���ϵͳ�밴7\n");
		printf("���������ѡ��");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					search();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 2:
					insert();
					traverse();
					//save();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
		
				case 3:
					del();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 4:
					summary1();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 5:
					summary();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 6:
					sort1();
					printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
					scanf("%d",&q);
					break;
			
				case 7: q = 0;break;
			
				default:
				printf("�������󣡣�\n");
				printf("����Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1����ֹ�밴0");
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
		printf("\n������Ϊ������\n");
	else
	{
		printf("�� ���� �� ���� �� �� �� �� �� | ���� ��ˮ��ѩ�ʵ�����ʩ�\n");
		while(p1->next!= NULL)
		{			
			printf("��%-6d��%-6s��%-13d|%-6d��%-6d��%-8d��\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
			p1 = p1->next ;
		}
		printf("��%-6d��%-6s��%-13d|%-6d��%-6d��%-8d��\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
	}
}

void insert()
{
	struct info *p1,*p2,*p3,*p4;
	p4=p2 = p1 = head ;
	int temp =0;
	int sign = 0;
	p3 = (struct info *)malloc(LEN);
	printf("�����빤�˵Ĺ��ţ�");
	scanf("%d",&p3->num );
	printf("�����빤�˵�������");
	scanf("%s",&p3->name );
	printf("�����빤�˵Ļ������ʣ�");	
	scanf("%d",&p3->bw );
	printf("�����빤�˵Ĳ�����");
	scanf("%d",&p3->sub );
	printf("�����빤�˵�ˮ��ѣ�");
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
				printf("\n�����Ѿ����ڣ�\n");
				sign = 1;
				break;
			}
			p4 = p4->next ;
			temp = p4->num;
		}
		if(temp == p3->num )
		{
			printf("\n�����Ѿ����ڣ�\n");
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
				if(head == p1)//���p3��������С
				{
					p3->next = p1;
					p1->prior = p3;
					head = p3;
				}
				else//����λ��
				{
					p3->next = p1;
					p3->prior = p1->prior ;
					p2->next = p3;
					p1->prior = p3;
				}
			}
			else//�������Ϊ���
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
		printf("�޷����ļ�����\n");
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
	printf("����%d�����ݣ�\n",n);
}

void save()
{
	FILE *fp;
	struct info *p1;
	if((fp = fopen("worker.txt","w"))==NULL) //������ļ�
	{
		printf("�ļ��޷��򿪣�\n");
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
	printf("���ݴ��̳ɹ���");
}

void search()
{
	struct info *p1;
	int a;
	int sign = 0;
	if(head == NULL)
		printf("\n������Ϊ������\n");
	else
	{	
		printf("������ҪѰ�ҵĹ���");
		scanf("%d",&a);
		p1 = head;
		if(p1->num == a)
		{
			printf("�� ���� �� ���� �� �� �� �� �� | ���� ��ˮ��ѩ�ʵ�����ʩ�\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
			printf("��%-6d��%-6s��%-13d|%-6d��%-6d��%-8d��\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
			sign = 1;
		}
		else	
		{
			while(p1->next !=NULL)
			{
				if(a==p1->num )	
				{
					printf("�� ���� �� ���� �� �� �� �� �� | ���� ��ˮ��ѩ�ʵ�����ʩ�\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
					printf("��%-6d��%-6s��%-13d|%-6d��%-6d��%-8d��\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
					sign = 1;
					break;
				}
				else
					p1 = p1->next ;
			}	
			if(a==p1->num && sign !=1)
			{
				printf("�� ���� �� ���� �� �� �� �� �� | ���� ��ˮ��ѩ�ʵ�����ʩ�\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
				printf("��%-6d��%-6s��%-13d|%-6d��%-6d��%-8d��\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage );
				sign = 1;
			}
		}
	}
	if(sign == 1)
		printf("\n���ҵ����ˣ���\n");
	else
		printf("δ�ҵ����ˣ���\n");
}

void del()
{
	struct info *p3,*p4;
	char temp[10];
	traverse();
	p3 = head;
	int sign = 0;
	if(p3 == NULL)
		printf("������Ϊ�������޷�ɾ����");
	else
	{
		printf("������Ҫɾ�����˵�����");
		scanf("%s",&temp);
		p3 =head ;
	
		if(strcmp(head->name,temp)==0)//��һ��Ϊɾ������
		{
			head = head->next ;
			free(p3);
			sign = 1;
		}
		else
		{
			while(strcmp(p3 ->name,temp)!=0  && p3->next != NULL)//�����Ƿ���һ����
			{
				p4 = p3;
				p3 = p3->next ;
			}
			if(strcmp(p3 ->name,temp)==0)//�ҵ�
			{
				p4->next = p3->next ;
				if(p3->next != NULL)
					p3->next->prior= p4;
				free(p3);
				sign = 1;
			}
			else
				printf("δ�ҵ���");
		}
		if(sign == 1)
			printf("\n��ɾ������\n");
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
		printf("�ܻ�������%d\n",a);
		printf("�ܲ���%d\n",b);
		printf("��ˮ���%d\n",c);
	}
	else
		printf("\n��ǰ����Ϊ������\n");
}

void summary1()
{
	int a=0;
	struct info *p1;
	p1=head;
	if(head!=NULL)
	{
		printf("����    ����\tʵ������");
		while(p1->next !=NULL)
		{
			printf("\n %d\t%s\t%d",p1->num ,p1->name,p1->wage );
			p1 = p1->next;
		}
		printf("\n %d\t%s\t%d",p1->num ,p1->name,p1->wage );
	}
	else
		printf("������Ϊ������\n");
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
		printf("\n�������޷�����\n");
	else
	{	
		while(q)
		{
			length++;
			q= q->next;
		}
		q= head;
		printf("%d",length);
		for(i=0;i<length-1;i++)//ð������
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
		/*while(q)//��һ��
		{
			MIN = q->wage ;
			p = q;
			while(p)//ÿһ����ȡ��С
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
			printf("����    ����\tʵ������\t����");
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
		printf("����    ����\tʵ������");
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
		printf("����Ϊ�գ�\n");
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