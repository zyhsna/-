#include<stdio.h>
#define LEN 100

typedef struct str{
	char data[LEN];
	int length;
}str;

int Length(str *p)//求长度
{
	int i;
	for(i = 0;i<100;i++)
	{
		if(p->data[i] == '\0')//当字符数组为结尾时，break
			break;
	}
	return i;
}

void Assign(str *p)//串赋值
{
	scanf("%s",&p->data);
	printf("%s",p->data);
	p->length = Length(p);
}

/*本next函数采用的是改进型的next函数，其脱胎于原始的next函数。原理在于如果在子串中如果一个字符又出现一遍，则比较此字符x与其next指向的字符m，如果两个字符是一样的
则x的next等于m的next，如果不等，则x的next任为原来的next。这样的话就会减少重复字符段的重复排序*/
void getnext(str *p,int next[])
{
	int i = 1;//指向子串的第一个字符
	next[1] = 0;//0位置不用，如果碰到next[1]=0，则说明要把子串放到当前失配的下一个位置来进行匹配
	int j = 0;
	while(i < p->length)//当i小于子串长度是
	{
		if(j==0 || p->data[i-1] == p->data[j-1])
		{
			i++;j++;
			if(p->data[i-1] != p->data[j-1])//子串中第i个位置与第j个位置不同时
				next[i] = j;//则下一次
			else
				next[i] = next[j];
		}
		else j = next[j];
	}
}
int compare(str *p,str *q,int next[])
{
	int i=0,j=1;//j也有指向next数组作用，并且next第0位无数字
	while(i < p->length && j<=q->length )//当i小于主串长度并且j小于等于子串长度
	{
		if(j==0 || p->data[i] == q->data[j-1])
		{//j=0时代表此时需要将子串第一个字符从当前失配的位置挪到下一个
		 //当 p->data[i] == q->data[j-1]时继续匹配下一个位置是否相等
			i++;j++;
		}
		else
			j = next[j];//i和j-1位置字符不等，则按照next函数进行下一次匹配
	}
	if(j>q->length )//匹配结束
		return i- q->length +1;
	else
		return 0;
}

int main()
{
	int x;
	int next[LEN];//初始化next
	str String,target;//初始化
	String.length = target.length = 0;
	printf("请输入主串：");
	Assign(&String);//主串赋值
	printf("请输入子串");
	Assign(&target);//子串赋值
	getnext(&target,next);//计算next函数
	x = compare(&String,&target,next);//比较
	if(x)
		printf("在第%d个位置",x);
	else
		printf("无匹配");
	return 0;
}

