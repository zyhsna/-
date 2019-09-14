#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(info)

struct  info 
{
	int num;
	char name[10];
	int bw;      //basic wage ��������
	int sub;	 //subsidy ����
	int we;		 //water & electricity ˮ���
	int wage;	 //ʵ������
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
					/*add();
					sort()*/;
					insert();
					print();
					save();
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
	}
	return 0;
}

/*void add()
{
	struct info *p1,*p2;
	int n = 0;
	head =NULL;
	p1 = p2 = (struct info *)malloc(LEN);
	printf("�����빤�˵Ĺ���");
	scanf("%d,%s",&p1->num);
	while(p1->num != 0)
	{
		printf("�����빤�˵�������");
		scanf("%s",&p1->name );
		printf("�����빤�˵Ļ������ʣ�");
		scanf("%d",&p1->bw );
		printf("�����빤�˵Ĳ�����");
		scanf("%d",&p1->sub );
		printf("�����빤�˵�ˮ��ѣ�");
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
		printf("�����빤�˵Ĺ���");
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
		printf("������Ϊ������\n");
    printf("���� �ũ��� ������ �� �� �ʩ���    ����ˮ ��  �ѩ�  ʵ�����ʩ�\n");
	while(p3->next != NULL)
	{	
		
		printf("��%d	  ��%s	��%d	  ��%d    �� %d    ��    %d      ��\n",p3->num ,p3->name ,p3->bw ,p3->sub ,p3->we,p3->wage );
		p3 = p3->next ;
	}
	printf("��%d	  ��%s	��%d	  ��%d    �� %d    ��    %d      ��\n",p3->num ,p3->name ,p3->bw ,p3->sub ,p3->we,p3->wage );
	
}

void del()
{
	char temp[10];
	print();
	int sign = 0;
	printf("������Ҫɾ�����˵�����");
	scanf("%s",&temp);
	struct info *p3,*p4;
	p3 =head ;
	if(p3 == NULL)
		printf("������Ϊ�������޷�ɾ����");
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
			printf("δ�ҵ���");
	}
	if(sign == 1)
		printf("\n��ɾ������\n");
}

void search()
{
	struct info *p1;
	int a,i;
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
			printf("����	����	��������	����	ˮ���	ʵ������\n");
			printf("%d	%s	%d	%d	%d	%d\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage);
			sign = 1;
		}
		else	
		{
			while(p1->next !=NULL)
			{
				if(a==p1->num )	
				{
					printf("����	����	��������	����	ˮ���	ʵ������\n");
					printf("%d	%s	%d	%d	%d	%d\n",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage);
					sign = 1;
					break;
				}
				else
					p1 = p1->next ;
			}	
		if(a==p1->num && sign !=1)
			{
				printf("����	����	��������	����	ˮ���	ʵ������\n");
				printf("%d	%s	%d	%d	%d	%d",p1->num ,p1->name ,p1->bw ,p1->sub ,p1->we,p1->wage);
				sign = 1;
			}
		}
	}
	if(sign == 1)
		printf("\n���ҵ����ˣ���\n");
	else
		printf("δ�ҵ����ˣ���\n");
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
		printf("����    ����\tʵ������");
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
		printf("�޷����ļ�����\n");
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
	printf("����%d�����ݣ�\n",n);
}


void save()
{
	FILE *fp;
	struct info *p1;
	int sign =0;
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
		sign = 1;
	}
	fprintf(fp,"%d %s %d %d %d %d\n",p1->num,p1->name,p1->bw,p1->sub,p1->we,p1->wage);
	fclose(fp);
	if(sign ==0) // �ж��Ƿ���̳ɹ�
		printf("���ݴ���ʧ�ܣ���\n");
	else
		printf("���ݴ��̳ɹ���");
}

void insert()
{
	struct info *p1,*p2,*p3;
	p2=p1 =head;
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


