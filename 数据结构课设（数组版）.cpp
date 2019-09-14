#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 300

struct  info 
{
	int num;
	char name[10];
	int bw;      //basic wage ��������
	int sub;	 //subsidy ����
	int we;		 //water & electricity ˮ���
	int wage;	 //ʵ������
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

int j = 0;//ȫ�ֱ�����˵���ж�������Ϣ


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
					add();
					sort();
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

void browse()
{
	int a;
	for(a=0 ; a<j ; a++)//��ϵͳ�е���Ϣ�������
	{	printf("����\t����\t��������\t����\tˮ���\tʵ������");
		printf("\n %d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d",worker[a].num,worker[a].name ,worker[a].bw ,worker[a].sub,worker[a].we ,worker[a].wage );
		printf("\n\n\n");
	}
	if(j==0)//�ж�ϵͳ���Ƿ�����Ϣ
		printf("��ǰϵͳ����Ϣ\n\n\n");
}

void read()
{
	FILE *fp;
	int sign = 1;
	if((fp = fopen("worker.txt","r"))==NULL);
	{
		printf("�޷����ļ�����\n");
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
		printf("���ݶ�ȡʧ�ܣ�\n");
	else
		printf("���ݶ�ȡ�ɹ���\n");
	printf("��¼��%d����Ϣ\n",j);
}


void save()
{
	FILE *fp;//����һ���ļ�ָ��
	int i;
	int sign = 1;//�ж��Ƿ�������ݴ���
	if((fp = fopen("worker.txt","w"))==NULL) //������ļ�
	{
		printf("�ļ��޷��򿪣�\n");
		return;
	}
	for(i=0;i<j;i++)
		{
			fprintf(fp,"%d %s %d %d %d %d\n",worker[i].num,worker[i].name,worker[i].bw,worker[i].sub,worker[i].we,worker[i].wage);		
		}
	fclose(fp);//�ر��ļ�
	if(sign ==0) // �ж��Ƿ���̳ɹ�
		printf("���ݴ���ʧ�ܣ���\n");
	else
		printf("���ݴ��̳ɹ���");
}

void search()
{
	int a;
	int temp;//�������Ҫ���ҵĹ���
	printf("������ҵĹ���\n");
	scanf("%d",&temp);
	for(a = 0;a <=j ; a++)//����
		{
			if(temp == worker[a].num)//���Ƿ������
				{
					printf("���ҵ���Ϣ��\n");
					printf("����\t����\t��������\t����\tˮ���\tʵ������");
					printf("\n %d  %s\t  %d\t   %d\t   %d\t   %d",worker[a].num,worker[a].name ,worker[a].bw ,worker[a].sub,worker[a].we ,worker[a].wage );
					printf("\n\n\n\n\n");
					break;
				}
			if(a==j)
				printf("\nδ�ҵ�����Ϣ����\n");
		}
}


void del()
{
	int a;
	int b;
	int sign = 1;
	char temp[100];
	printf("��ǰϵͳ����������Ϣ\n");
	browse();
	if(worker[j-1].num != 0 && j>=1)
	{
		printf("��������Ҫɾ��������");
		scanf("%s",&temp);
		for(a=0;a<j;a++)
			{	
				if (strcmp(temp,worker[a].name)==0)//��ѯ�Ƿ��и�����
					{
						for(b=a;b<j;b++)
							{
								worker[b]=worker[b+1];//��Ҫɾ�������ݺ���һ�����Ƶ�Ҫɾ����λ��
							}
						j -= 1;//ȫ�ֱ�����һ��������ӵ�е����ݼ�һ��
						printf("\n\n");
						printf("ɾ����ɣ���\n\n");
						sign = 0;
						break;
					}
				else
					continue;
			}
	if(sign == 1)
		printf("δ�ҵ����ˣ���\n");
	}
}

void add()
{
	printf("�����빤��\n");
	scanf("%d",&worker[j].num);
	printf("����������\n");
	scanf("%s",&worker[j].name);
	printf("�������������\n");
	scanf("%d",&worker[j].bw);
	printf("�����벹��\n");
	scanf("%d",&worker[j].sub);
	printf("������ˮ���\n");
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
			for(k=0;k<j-i-1;k++)    //ð������
				{
					if(worker[k].num>worker[k+1].num )   //�ж�һ�������У�ǰ����������
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
	printf("�ܻ�������%d\n",a);
	printf("�ܲ���%d\n",b);
	printf("��ˮ���%d\n",c);
}

void summary1()
{
	int a;
	for(a=0 ; a<j ; a++)//��ϵͳ�е���Ϣ�������
	{	printf("����    ����\tʵ������");
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
			for(k=0;k<j-i-1;k++)    //ð������
				{
					if(worker[k].wage>worker[k+1].wage )   //�ж�һ�������У�ǰ����������
						{
							temp =worker[k];
							worker[k]= worker[k+1];
							worker[k+1]= temp;
						}
				}
		}
	for(i=0;i<j;i++)
	{
		printf("ʵ�����ʵ�%d��",j - i);
		printf("����\t����\t��������\t����\tˮ���\tʵ������");
		printf("\n %d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d",worker[i].num,worker[i].name ,worker[i].bw ,worker[i].sub,worker[i].we ,worker[i].wage );
		printf("\n\n\n");
	}
}

