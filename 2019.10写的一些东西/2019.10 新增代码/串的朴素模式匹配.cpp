#include<stdio.h>
#define LEN 100

typedef struct str{
	char data[LEN];
	int length;
};

int Length(str *s)//求串长度
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


void Assign(str *s)//串赋值
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
	str String;//初始化
	str target;
	String.length = 0;
	printf("请输入主串");
	Assign(&String);
	printf("请输入子串");
	Assign(&target);
	x = Compare(&String,&target);
	if(x)
		printf("在第%d个位置",x);
	else
		printf("不匹配！！");
	return 0;
}

