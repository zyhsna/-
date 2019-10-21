#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct CH{//��������ջ��
	char fh[100];//����
	int top;
}linkstack;

typedef struct NUM{//���������ջ��
	double sz[100];//���֣�Ϊ�˴��С��
	int top;
}link;

int i=0;//��λ���ʽ�еڼ���λ��
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

char Equation[100];//��ű��ʽ

char prec[8][8]={">><<<>>",">><<<>>",">>>><>>",
		 ">>>><>>","<<<<<=@",">>>>@>>",
		 "<<<<<@=",">>>>>>>"};//������������ȼ�
char sign[]="+-*/()#";//���������

int main()
{
	double x;
	printf("��������ʽ����#������");
	scanf("%s",Equation);
	x = Evaluate();
	printf("\nԭʽֵΪ%f\n",x);
	return 0;
}

char precede(char a,char b)//�ж���������������ȼ�
{
	int i=0,j= 0;
	while(sign[i]!=a)//�ҵ�aλ��
		i++;
	while(sign[j]!=b)//�ҵ�bλ��
		j++;
	return(prec[i][j]);//����a��b�����ȼ��Ƚ�
}

double numb()//һ����������
{
	double num;
	int a =0 ;//ȷ��С�����ֵ�λ��
	if(Equation[i]>='0' && Equation[i]<='9')//�����һ��������
	{
		num = Equation[i] - '0';
		i++;
		while(Equation[i]>='0' && Equation[i]<='9' )//����Ϊ��λ����
		{
				num = num*10 + (Equation[i] - '0');
				i++;
		}
		if(Equation[i] == '.')//����Ϊ��С���������
			{
				i++;
				while(Equation[i]>='0' && Equation[i]<='9')
				{
					a--;//����λ��
					num = num+(Equation[i] - '0')*pow(10.0,a);
					i++;
				}
			}
		
		return(num);
	}
	else return 0;//����Ϊ����
}

void push1(linkstack *p,char c)//�������ջ
{
	p->fh[p->top++] = c;//��ջ��top����һ
}

void push2(link *p,double num)
{
	p->sz [p->top++] = num;//��ջ��top����һ
}

char gettop1(linkstack *optr)//ȡ�����ջ��Ԫ��
{
	return(optr->fh [optr->top -1]);
}

double gettop2(link *opnd)//ȡ����ջ��Ԫ��
{
    return(opnd->sz[opnd->top-1]);
}

char pop1(linkstack *optr)//���������ջ��Ԫ��
{
    return(optr->fh[--optr->top]);//top��һ����ջ��Ԫ�ط���
}

double pop2(link *opnd)//��������ջ��Ԫ��
 {
     return(opnd->sz[--opnd->top]);//top��һ����ջ��Ԫ�ط���
}

double operate(double a, char theta,double b)//����a��b����ֵ
{
	double num;
	switch(theta)
	{
		case '+': num=a+b;break;
		case '-': num=a-b;break;
		case '*': num=a*b;break;
		case '/': num=a/b;break;
		default:printf("����");
    }
    return num;//���ؼ�����
}

double Evaluate()
{
	double num;char theta;double a,b;
	linkstack s;link t;//��ʼ��
	s.top = 0;//��top��λ0����������������
	t.top = 0;
	push1(&s,'#');//��#�������ջ
	while(Equation[i] != '#' || gettop1(&s) != '#')//�����ʽ���һ���Լ����ջtop��ͬʱΪ#
	{
		num = numb();//�õ���һ������
		if(num)//�����һ������
			push2(&t,num);
		else//��ô�������
			switch(precede(gettop1(&s),Equation[i]))//�Ƚ������������ջtop�����ȼ�
			{
				case'<':push1(&s,Equation[i++]);break;//��ǰ������ȼ��ߣ��������ջ
				case'=':pop1(&s);//���ȼ���ͬ��ջ��Ԫ�ص���ջ�����
					i++;//�����ʽ��һ������ѭ��
					break;
				case'>': //���ȼ��ͣ�����ǰ����������ֵ
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

