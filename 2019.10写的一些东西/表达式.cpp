#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct CH{//定义数字栈堆
	char fh[100];//符号
	int top;
}linkstack;

typedef struct NUM{//定义运算符栈堆
	double sz[100];//数字，为了存放小数
	int top;
}link;

int i=0;//定位表达式中第几个位置
double Evaluate();
char precede(char a,char b);
double numb();
void push1(linkstack *p,char c);
void push2(link *p,double num);
char gettop1(linkstack *optr);
char gettop2(linkstack *opnd);
char pop1(linkstack *optr);
double pop2(link *opnd);
double operate(double a, char theta,double b);

char Equation[100];//存放表达式

char prec[8][8]={">><<<>>",">><<<>>",">>>><>>",
		 ">>>><>>","<<<<<=@",">>>>@>>",
		 "<<<<<@=",">>>>>>>"};//定义运算符优先级
char sign[]="+-*/()#";//定义运算符

int main()
{
	double x;
	printf("请输入表达式（以#结束）");
	scanf("%s",Equation);
	x = Evaluate();
	printf("\n原式值为%f\n",x);
	return 0;
}

char precede(char a,char b)//判断两个运算符的优先级
{
	int i=0,j= 0;
	while(sign[i]!=a)//找到a位置
		i++;
	while(sign[j]!=b)//找到b位置
		j++;
	return(prec[i][j]);//返回a与b的优先级比较
}

double numb()//一个算量计算
{
	double num;
	int a =0 ;//确定小数部分的位置
	if(Equation[i]>='0' && Equation[i]<='9')//如果第一个是数字
	{
		num = Equation[i] - '0';
		i++;
		while(Equation[i]>='0' && Equation[i]<='9' )//数字为多位数字
		{
				num = num*10 + (Equation[i] - '0');
				i++;
		}
		if(Equation[i] == '.')//数字为带小数点的数字
			{
				i++;
				while(Equation[i]>='0' && Equation[i]<='9')
				{
					a--;//控制位数
					num = num+(Equation[i] - '0')*pow(10.0,a);
					i++;
				}
			}
		
		return(num);
	}
	else return 0;//代表不为数字
}

void push1(linkstack *p,char c)//运算符入栈
{
	p->fh[p->top++] = c;//入栈后top数加一
}

void push2(link *p,double num)
{
	p->sz [p->top++] = num;//入栈后top数加一
}

char gettop1(linkstack *optr)//取运算符栈顶元素
{
	return(optr->fh [optr->top -1]);
}

double gettop2(link *opnd)//取数字栈顶元素
{
    return(opnd->sz[opnd->top-1]);
}

char pop1(linkstack *optr)//弹出运算符栈顶元素
{
    return(optr->fh[--optr->top]);//top减一，将栈顶元素返回
}

double pop2(link *opnd)//弹出数字栈顶元素
 {
     return(opnd->sz[--opnd->top]);//top减一，将栈顶元素返回
}

double operate(double a, char theta,double b)//计算a与b运算值
{
	double num;
	switch(theta)
	{
		case '+': num=a+b;break;
		case '-': num=a-b;break;
		case '*': num=a*b;break;
		case '/': num=a/b;break;
		default:printf("错误！");
    }
    return num;//返回计算结果
}

double Evaluate()
{
	double num;char theta;double a,b;
	linkstack s;link t;//初始化
	s.top = 0;//将top置位0，代表里面无数字
	t.top = 0;
	push1(&s,'#');//将#送入算符栈
	while(Equation[i] != '#' || gettop1(&s) != '#')//当表达式最后一个以及算符栈top不同时为#
	{
		num = numb();//得到第一个数字
		if(num)//如果是一个数字
			push2(&t,num);
		else//那么就是算符
			switch(precede(gettop1(&s),Equation[i]))//比较这个算符和算符栈top的优先级
			{
				case'<':push1(&s,Equation[i++]);break;//当前算符优先级高，送入算符栈
				case'=':pop1(&s);//优先级相同，栈顶元素弹出栈顶算符
					i++;//将表达式下一个送入循环
					break;
				case'>': //优先级低，计算前后两个算量值
					{
						theta=pop1(&s); 
						b=pop2(&t);
						a=pop2(&t);
						push2(&t,operate(a,theta,b));
						break;
					}
			}
	}
	return(gettop2(&t));
}

