#include<stdio.h>
#define LEN 100

typedef struct str{
	char data[LEN];
	int length;
};

int Length(str *s)//�󴮳���
{
	int i;
	int j=0;
	for(i=0;i<100;i++)
	{
		if(s->data[i] == '\0')
			break;
		j++;
	}
	return j;
}


void Assign(str *s)//����ֵ
{
	int i;
	scanf("%s",&s->data);
	printf("%s",s->data );
	s->length = Length(s);
}

int Compare(str *p,str *q)
{
	int i,j;
	i = j =0;
	while(i<p->length && j<q->length )
	{
		if(p->data[i] == q->data[j])
		{
			i++;j++;
		}
		else
		{
			i = i-j+1;
			j=0;
		}
	}
	if(j == q->length )
		return i-q->length +1;
	else 
		return 0;
}

int main()
{
	int x;
	str String;//��ʼ��
	str target;
	String.length = 0;
	printf("����������");
	Assign(&String);
	printf("�������Ӵ�");
	Assign(&target);
	x = Compare(&String,&target);
	if(x)
		printf("�ڵ�%d��λ��",x);
	else
		printf("��ƥ�䣡��");
	return 0;
}

