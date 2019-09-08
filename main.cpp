#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 300



struct information
{
	char name[100];//����
	char tel[20];//�绰����
	char email[30];//��������
	char kind;//�������
};


void add();
void browse();
void sort();
void search();
void summary();
void del();
void change();
void save();
void read();
int j = 3;//jΪȫ�ֱ���������ͨѶ¼����������Ϣ������

struct information info[num] = {{"zyh","19825300946","758088924@qq.com",'b'},
							    {"asd","11111111111","1111111111111111",'B'},
								{"bad","22222222222","2222222222222222",'C'},
									};/*Ԥ�ȴ�������*/

int main()
{
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
			{case 1:add();break;
			 case 2:browse();break;
			 case 3:sort();break;
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





/*�����ϵ��*/

void add()
{
	int a=1;//һ����־����a==1ʱ��������ӳ���a==0ʱֹͣ����
	int b;
	char mz[10];
	char needs_go_on = 'y';//һ����־�������ϵ�������ظ���������¼����ϵ�˲���
	int check = 1;//����һ����ڶ�������������Ƿ�һ��
	while(a==1)
		{	
			printf("����������");
			scanf("%s",&mz);
			for(b=0;b<j;b++)
				{
					if(strcmp(mz,info[b].name ) == 0)
						{
							printf("\n����ϵ���Ѵ��ڣ�\n\n");
							needs_go_on = 'n';
							break;
						}
				}
			if(needs_go_on == 'y')
				{	
					printf("����ϵ�˿�����ӣ����ٴ�����������\n");
					while(check)//����һ����ڶ�������������Ƿ�һ��
						{
							scanf("%s",&info[j].name );
							if(strcmp(mz,info[j].name ) != 0)
								{
									printf("�����������벻һ����\n");
									printf("���������룡");
								}
							else
								check = 0;
						}

					printf("\n�������ֻ�����");         //������Ϣ
					scanf("%s",&info[j].tel );getchar();
					printf("\n�������������");
					scanf("%s",&info[j].email );getchar();
					printf("\n�������������AΪ�칫�� BΪ������ CΪ�����ࣩ");
					scanf("%s",&info[j].kind );getchar();
					j += 1;
				}
			printf("��Ҫ����¼���𣿼�����1��ֹͣ��0\n\n");
			scanf("%d",&a);
			if(a==1)
				{check = 1;
				 needs_go_on = 'y';}
		}
}



/*������ϵ��*/

void browse()
{
	int a;
	for(a=0 ; a<j ; a++)//��ͨѶ¼�е���Ϣ�������
	{	printf("����\t��������\t�绰\t���");
		printf("\n %s %s %s %c",info[a].name,info[a].email ,info[a].tel ,info[a].kind);
		printf("\n\n\n");
	}
	
	if(j==0)//�ж�ͨѶ¼���Ƿ�����Ϣ
		printf("��ǰ����ϵ����Ϣ\n\n\n");
}


/*������ϵ��*/
void sort()
{
	int i;
	int k;
	information temp;//����һ��temp����ʱ����Ҫ���н�������Ϣ
	for(i=0;i<j-1;i++)
		{
			for(k=0;k<j-i-1;k++)    //ð������
				{
					if(strcmp(info[k].name ,info[k+1].name )<0)   //�ж�һ�������У�ǰ����������
						{
							temp =info[k];
							info[k]= info[k+1];
							info[k+1]= temp;
						}
				}
		}
	printf("����ɹ�!\n");

	browse();//�����һ�飬���Ƿ�ɹ�
}

/*��ѯ��ϵ��*/

void search()
{
	int a;
	char temp[100];//�������Ҫ���ҵ�����
	printf("������ҵ�����\n");
	scanf("%s",temp);
	for(a = 0;a <=j ; a++)//����ͨѶ¼
		{
			if(strcmp(temp,info[a].name) == 0)//���Ƿ�����mz�д�ŵ����������
				{
					printf("���ҵ�����ϵ�ˣ�\n");
					printf("����\t  �绰\t  ��������\t  ���\n\n");
					printf("%s   %s  %s   %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
					printf("\n\n\n\n\n");
					break;
				}
			if(a==j)
				printf("\nδ�ҵ���ϵ�ˣ���\n");
		}
}


/*ͳ����ϵ��*/
void summary()
{

    int target;//�����Ҫͳ�Ƶ����
	int a;
	int sign = 0;
	printf("�����¼��ࡣAΪ�칫�� BΪ������ CΪ������");
	printf("\nA���밴1,B���밴2��C���밴3");
	scanf("%d",&target);

	if(target == 1)
	{
		for(a=0;a<j;a++)
			{
				if( info[a].kind == 'A'||info[a].kind == 'a')//ֻҪ��a��𣬲��۴�Сд�����
					{
						printf("����\t�绰\t��������\t���\n\n");
						printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
						
						printf("\n\n\n\n");
						sign = 1;
					}
			}
			
	}

	if(target == 2)
	{
		for(a=0;a<j;a++)
			{
				if( info[a].kind == 'B'||info[a].kind == 'b')//ֻҪ��b��𣬲��۴�Сд�����
					{
						printf("����\t�绰\t��������\t���\n\n");
						printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
					
						printf("\n\n\n\n");
						sign = 1;						
					}
			}
			
	}

	if(target == 3)
	{
		for(a=0;a<j;a++)
			{
				if( info[a].kind == 'C'||info[a].kind == 'c')//ֻҪ��c��𣬲��۴�Сд�����
					{
						printf("����\t�绰\t��������\t���\n\n");
						printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
						printf("\n\n\n\n");
						sign = 1;
					}
			}
	}

	if(sign == 0)
		printf("\n��ǰ�������ϵ����Ϣ����\n");

	if(sign == 1)
		printf("\n\n����������ȫ����ʾ������������\n\n");
}

/*ɾ����ϵ��*/

void del()
{
	int a;
	int b;
	int sign = 1;
	char temp[100];
	printf("��ǰͨѶ¼����������Ϣ\n");
	browse();
	printf("��������Ҫɾ��������");
	scanf("%s",&temp);
	for(a=0;a<j;a++)
		{	
			if (strcmp(temp,info[a].name)==0)//��ѯ�Ƿ��и�����
				{
					for(b=a;b<num;b++)
						{
							info[b]=info[b+1];//��Ҫɾ�������ݺ���һ�����Ƶ�Ҫɾ����λ��
							
						}
					j -= 1;//ȫ�ֱ�����һ��������ӵ�е����ݼ�һ��
					printf("\n\n");
					browse();//���Ƿ�ɾ�����
					printf("ɾ����ɣ���\n\n");
					sign = 0;
					break;
					
				}
			else
				continue;
		}
	if(sign == 1)
		printf("δ�ҵ�����ϵ�ˣ���\n");

}

/*�޸���ϵ��*/
void change()
{
	int a;
	int sign=1;//һ����־�����Ƿ��޸ĳɹ����ɹ�Ϊ0.ʧ�ܻ�δ�ҵ�Ϊ1
	int target ;
	int q = 1;
	char temp[100];//���Ҫ�޸ĵ�����
	printf("�����ǵ�ǰͨѶ¼�а�������Ϣ\n\n");
	browse();
	printf("������Ҫ�޸��˵�����");
	scanf("%s",&temp);
	getchar();
	for (a=0;a<j;a++)
		{
			if(strcmp(temp,info[a].name )==0)
				{
					sign=0;//���ҵ�
					printf("���ҵ���ϵ�ˣ�\n");
					printf("ԭ��Ϣ���£�\n");
					printf("����\t�绰\t��������\t���\n\n");
					
					while(q)
						{
							printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
							printf("��������Ҫ�޸ĵ���\n");
							printf("�޸������밴1  �޸ĵ绰�밴2  �޸ĵ��������밴3  �޸�����밴4\n");
							scanf("%d",&target);
						
							if(target == 1)
							{printf("\n�������޸Ĺ��������");
							scanf("%s",&info[a].name);getchar();}					

							if(target == 2)
							{printf("�������޸Ĺ���ĵ绰");
							scanf("%s",&info[a].tel);getchar();}

							if(target == 3)
							{printf("�������޸Ĺ���ĵ�������");
							scanf("%s",&info[a].email);getchar();}
						
							if(target == 4)
							{printf("�������޸Ĺ�������");
							scanf("%c",&info[a].kind);getchar();}
							printf("�޸ĳɹ�������\n\n");	
							printf("�㻹������޸ĸ���ϵ����Ϣ�𣿼����밴1,��ֹ�밴0");
							scanf("%d",&q);
						}
			}
					break;
				}
		
			if(sign)
				printf("ͨѶ¼���޴��ˣ���\n\n");
}


//��ϵ����Ϣ����
void save()
{
	FILE *fp;//����һ���ļ�ָ��
	int i;
	int sign = 0;//�ж��Ƿ�������ݴ���
	if((fp = fopen("stu.dat","wb"))==NULL) //������ļ�
	{
		printf("�ļ��޷��򿪣�\n");
		return;
	}
	for(i=0;i<j;i++)
		{
			if(fwrite(&info[i],sizeof(struct information),1,fp)!=1)
				{printf("����д��ʧ�ܣ�\n");
			sign = 1;}
		}
	fclose(fp);//�ر��ļ�
	if(sign == 1) // �ж��Ƿ���̳ɹ�
		printf("���ݴ���ʧ�ܣ���\n");
	else
		printf("���ݴ��̳ɹ���");

	
}


//��ϵ����Ϣ��ȡ
void read()
{
	FILE *fp;
	int i,k;
	int c = 0;
	int sign = 1;
	int check = 1;
	int m = 0;
	struct information temp[300];
	if((fp = fopen("stu.dat","rb"))==NULL)
	{
		printf("�޷����ļ�\n");
		exit(0);
	}
	for(i = 0;i<300;i++)
	{
		fread(&temp[i],sizeof(struct information),1,fp);
		sign = 0;
	}
	for(i=0;i<300;i++)
	{
		if(strlen(temp[i].name) != 0)
			c++;
	}
	for(i=0;i<c;i++)//�ж��Ƿ�������ϵ�����ظ���
	{
		for(k=0;k<300;k++)
		{
			if(strcmp(temp[i].name ,info[k].name )!=0)
				check = 1;
			else
				{
					check = 0;
					break;
				}
		}
		if(check == 1)//���û���ظ��ģ����������
			{
				info[j] = temp[i];
				j += 1;
				m++;
			}

	}
	fclose(fp);
	if(sign == 1)
		printf("���ݶ�ȡʧ�ܣ�\n");
	else
		printf("���ݶ�ȡ�ɹ���\n");
	printf("��¼��%d����Ϣ\n",m);
}