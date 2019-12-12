#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 128//最大元素

int n = 1;//代表存放第几组数据

typedef struct Triple{
	int i, j;//i行j列
	int e;//非零元素的值
}Triple;//三元组结构体


typedef struct TSMatrix{
	Triple data[MAXSIZE + 1];//非零元素三元组表 data[0]不用 也就是存放压缩后的稀疏矩阵
	int row, col, sum;  //矩阵的行数与列数以及非零元素个数
}TSMatrix;//矩阵


void initmatrix(TSMatrix* M);
void Inversion(TSMatrix& M, TSMatrix& T);
void Browse(TSMatrix T);

int main(void)
{
	int q = 1,choice;
	TSMatrix M, T;//初始化两个矩阵
	M.row = 0; M.col = 0;
	M.sum = 0;//初始化
	while (q)
	{
		printf("\n输入矩阵按1");
		printf("\n倒置按2");
		scanf_s("%d",&choice);
		switch (choice)
		{
		case 1:initmatrix(&M); break;
		case 2:Inversion(M, T);	Browse(T); break;
		case 0:exit(0);
		default:
			break;
		}
		printf("\n\n还要继续使用吗？按1继续0停止\n");
		scanf_s("%d",&q);
		system("cls");
	}
	return 0;
}


void initmatrix(TSMatrix* M)//输入矩阵
{
	int t = 1;
	printf("请输入矩阵\n");
	scanf_s("%d%d%d", &M->data[n].i, &M->data[n].j, &M->data[n].e);
	n++;
	printf("行  列   元素值\n");
	for (t = 1; t < n; t++)//输出当前原矩阵的值
	{
		printf("%d    %d    %d \n", M->data[t].i, M->data[t].j, M->data[t].e);
	}
	//自动算出当前矩阵的行数与列数
	t = t - 1;//定位到当前新输入的数据中
	if(M->data[t].i >= M->row)
		M->row = M->data[t].i;
	if (M->data[t].j >= M->col)
		M->col = M->data[t].j;
	M->sum++;//非零元素加1
	printf("当前为%d行%d列矩阵,总非零元素个数为%d",M->row,M->col,M->sum);
}


void Inversion(TSMatrix &M , TSMatrix  &T)//转置
{
	int col, t, p, q;
	int num[20];//为相同列数
	int  position[20];//position为起始位置
	T.col = M.col; T.row = M.row; T.sum = M.sum;//赋值
	if (T.sum)//如果不为零矩阵
	{
		for (col = 1; col <= M.col; col++)
			num[col] = 0;//清0初始化
		for (t = 1; t <= M.sum; ++t)
			++num[M.data[t].j];//计算相同列数的一共有多少
		position[1] = 1;//转置过后的第一行当然要从1开始
		for (col = 2; col <= M.col; ++col)
			position[col] = position[col - 1] + num[col - 1];//计算转置过后每一行的起始位置 num为上一行所占的行数，position为上一行起始位置
		for (p = 1; p <= M.sum; ++p)
		{
			col = M.data[p].j;
			q = position[col];//得到位置
			T.data[q].i = M.data[p].j;//放入列与行对调，值不变
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e ;
			position[col]++;
		}
	}
}

void Browse(TSMatrix T)//遍历
{
	printf("\n倒置之后\n");
	printf("行  列   元素值\n");
	for (int t = 1; t < n; t++)//输出当前原矩阵的值
	{
		printf("\n%d    %d    %d \n", T.data[t].i, T.data [t].j,T.data[t].e);
	}
}