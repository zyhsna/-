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
	int q = 1;//qΪ��־�������Ƿ�������в˵�����
	while (q)
	{
		int choice;
		printf("��������ӭʹ��ͨѶ¼ϵͳ ��������    produced by zyh\n\n");  /*�˵�����*/
		printf("�����������µ���ϵ�ˣ��밴1������\n\n");
		printf("���������������ϵ�ˣ��밴2������\n\n");
		printf("����������������ϵ�ˣ��밴3������\n\n");
		printf("��������ѯһ����ϵ�ˣ��밴4������\n\n");
		printf("��������ʾĳ����ϵ�ˣ��밴5������\n\n");
		printf("������ɾ��һ����ϵ�ˣ��밴6������\n\n");
		printf("�������޸�һ����ϵ�ˣ��밴7������\n\n");
		printf("������  ������ϵ��  ���밴8������\n\n");
		printf("������  ��ȡ��ϵ��  ���밴9������\n\n");
		printf("������    �˳�ϵͳ  ���밴0������\n");
		printf("���������ѡ��");
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
		printf("��Ҫ����ʹ�ñ�ϵͳ�𣿼����밴1��ֹͣ�밴0");
		scanf("%d",&q);

	}
	return 0;
}


void browse()
{
	struct info *p1;
	if(head == NULL)
	{
		printf("\n\n��ǰ����ϵ����Ϣ����\n");
	}
	else
	{
		printf("����   �ֻ�  ��������  ���");
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
	printf("\n��������ϵ�˵�����\n");
	scanf("%s",&p3->name );
	printf("\n��������ϵ�˵��ֻ���\n");
	scanf("%s",&p3->phone );
	printf("\n��������ϵ�˵ĵ�������\n");
	scanf("%s",&p3->email );
	printf("\n��������ϵ�˵����\n");
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
	if((fp = fopen("student.txt","w"))==NULL) //������ļ�
	{
		printf("�ļ��޷��򿪣�\n");
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
	if(sign ==0) // �ж��Ƿ���̳ɹ�
		printf("���ݴ���ʧ�ܣ���\n");
	else
		printf("���ݴ��̳ɹ���");
}



void read()
{
	FILE *fp;
	struct info *p1,*p2;
	p2=p1=(struct info *)malloc(LEN);
	int n = 0;
	if((fp=fopen("student.txt","r"))==NULL)
	{
		printf("�޷����ļ�����\n");
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
	printf("����%d�����ݣ�\n",n);
}


void search()
{
	struct info *p1;
	int i;
	char a[10];
	int sign = 0;
	if(head == NULL)
		printf("\n������Ϊ������\n");
	else
	{	
		printf("������ҪѰ�ҵ�����");
		scanf("%s",&a);
		p1 = head;
		if(strcmp(p1->name,a)==0)
		{
			printf("����   �ֻ�  ��������  ���");
			printf("\n%s %s %s %c\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
			sign = 1;
		}
		else	
		{
			while(p1->next !=NULL)
			{
				if(strcmp(a,p1->name)==0 )	
				{
					printf("����   �ֻ�  ��������  ���");
					printf("\n%s %s %s %c\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
					sign = 1;
					break;
				}
				else
					p1 = p1->next ;
			}	
		if(strcmp(a,p1->name)==0 && sign !=1)
			{
				printf("����   �ֻ�  ��������  ���");
				printf("\n%s %s %s %c\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
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
	char temp[10];
	browse();
	int sign = 0;
	printf("������Ҫɾ��������");
	scanf("%s",&temp);
	struct info *p3,*p4;
	p3 =head ;
	if(p3 == NULL)
		printf("������Ϊ�������޷�ɾ����");
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
			printf("δ�ҵ���");
	}
	if(sign == 1)
		printf("\n��ɾ������\n");
}


void change()
{
	struct info *p1;
	int sign = 1;
	p1 = head;
	char temp[10];
	browse();
	if(head == NULL)
		printf("\n�޷��޸ģ�\n");
	else
	{
		printf("������Ҫ�޸ĵ�����");
		scanf("%s",&temp);
		if(strcmp(head->name ,temp)==0)
		{
			printf("\n��������ϵ�˵�����\n");
			scanf("%s",&head->name );
			printf("\n��������ϵ�˵��ֻ���\n");
			scanf("%s",&head->phone );
			printf("\n��������ϵ�˵ĵ�������\n");
			scanf("%s",&head->email );
			printf("\n��������ϵ�˵����\n");
			scanf("%s",&head->type );
			sign = 0;
		}
		while(strcmp(p1->name,temp)!=0 && p1->next !=NULL)
		{
			p1 = p1->next ;
		}
		if(strcmp(p1->name ,temp)==0)
		{
			printf("\n��������ϵ�˵�����\n");
			scanf("%s",&p1->name );
			printf("\n��������ϵ�˵��ֻ���\n");
			scanf("%s",&p1->phone );
			printf("\n��������ϵ�˵ĵ�������\n");
			scanf("%s",&p1->email );
			printf("\n��������ϵ�˵����\n");
			scanf("%s",&p1->type );
			sign = 0;
		}
	}
	if(sign == 0)
		printf("\n�޸ĳɹ�����\n");
	else
		printf("\n���޴��ˣ���\n");
}

void summary()
{
	int target;
	struct info *p1;
	if(head == NULL)
		printf("����ϵ����Ϣ����");
	else
	{
		printf("��ѡ��Ҫ���ҵ���ϵ����𣺣�1��A�࣬2��B�࣬3��C�ࣩ");
		scanf("%d",&target);
		if(target==1)
		{
			p1 = head;
			while( p1->next !=NULL)
			{
				if(p1->type == 'a' || p1->type == 'A')
				{printf("����   �ֻ�  ��������  ���");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );}
				p1 = p1->next ;
			}
			if(p1->type == 'a' || p1->type == 'A')
			{
				printf("����   �ֻ�  ��������  ���");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
			}
		}
		
		if(target==2)
		{
			p1 = head;
			while(p1->next !=NULL)
			{
				if(p1->type == 'b' || p1->type == 'B')
				{printf("����   �ֻ�  ��������  ���");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );}
				p1 = p1->next ;
			}
			if(p1->type == 'b' || p1->type == 'B')
			{
				printf("����   �ֻ�  ��������  ���");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );
			}
		}
		
		if(target==3)
		{
			p1 = head;
			while(p1->next !=NULL)
			{
				if(p1->type == 'c' || p1->type == 'C')
				{printf("����   �ֻ�  ��������  ���");
				printf("\n%s %s %s %s\n",&p1->name ,&p1->phone ,&p1->email ,&p1->type );}
				p1 = p1->next ;
			}
			if(p1->type == 'c' || p1->type == 'C')
			{
				printf("����   �ֻ�  ��������  ���");
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
	printf("����������");
	scanf("%s",&p1->name);
	while(strcmp(p1->name ,"zxc")!=0)
	{
		printf("�������ֻ��ţ�");
		scanf("%s",&p1->phone );
		printf("������������䣺");
		scanf("%s",&p1->email );
		printf("���������");
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
		printf("����������");
		scanf("%s",&p1->name);
		j++;
	}
	p2 ->next = NULL;
}*/