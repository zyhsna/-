#include<stdio.h>
#define LEN 100

typedef struct str{
	char data[LEN];
	int length;
}str;

int Length(str *p)//�󳤶�
{
	int i;
	for(i = 0;i<100;i++)
	{
		if(p->data[i] == '\0')//���ַ�����Ϊ��βʱ��break
			break;
	}
	return i;
}

void Assign(str *p)//����ֵ
{
	scanf("%s",&p->data);
	printf("%s",p->data);
	p->length = Length(p);
}

/*��next�������õ��ǸĽ��͵�next����������̥��ԭʼ��next������ԭ������������Ӵ������һ���ַ��ֳ���һ�飬��Ƚϴ��ַ�x����nextָ����ַ�m����������ַ���һ����
��x��next����m��next��������ȣ���x��next��Ϊԭ����next�������Ļ��ͻ�����ظ��ַ��ε��ظ�����*/
void getnext(str *p,int next[])
{
	int i = 1;//ָ���Ӵ��ĵ�һ���ַ�
	next[1] = 0;//0λ�ò��ã��������next[1]=0����˵��Ҫ���Ӵ��ŵ���ǰʧ�����һ��λ��������ƥ��
	int j = 0;
	while(i < p->length)//��iС���Ӵ�������
	{
		if(j==0 || p->data[i-1] == p->data[j-1])
		{
			i++;j++;
			if(p->data[i-1] != p->data[j-1])//�Ӵ��е�i��λ�����j��λ�ò�ͬʱ
				next[i] = j;//����һ��
			else
				next[i] = next[j];
		}
		else j = next[j];
	}
}
int compare(str *p,str *q,int next[])
{
	int i=0,j=1;//jҲ��ָ��next�������ã�����next��0λ������
	while(i < p->length && j<=q->length )//��iС���������Ȳ���jС�ڵ����Ӵ�����
	{
		if(j==0 || p->data[i] == q->data[j-1])
		{//j=0ʱ�����ʱ��Ҫ���Ӵ���һ���ַ��ӵ�ǰʧ���λ��Ų����һ��
		 //�� p->data[i] == q->data[j-1]ʱ����ƥ����һ��λ���Ƿ����
			i++;j++;
		}
		else
			j = next[j];//i��j-1λ���ַ����ȣ�����next����������һ��ƥ��
	}
	if(j>q->length )//ƥ�����
		return i- q->length +1;
	else
		return 0;
}

int main()
{
	int x;
	int next[LEN];//��ʼ��next
	str String,target;//��ʼ��
	String.length = target.length = 0;
	printf("������������");
	Assign(&String);//������ֵ
	printf("�������Ӵ�");
	Assign(&target);//�Ӵ���ֵ
	getnext(&target,next);//����next����
	x = compare(&String,&target,next);//�Ƚ�
	if(x)
		printf("�ڵ�%d��λ��",x);
	else
		printf("��ƥ��");
	return 0;
}

