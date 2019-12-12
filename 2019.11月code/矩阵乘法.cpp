#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 256

typedef struct Triple {
	int i, j;//i行j列
	int e;//非零元素的值
}Triple;//三元组结构体


typedef struct TSMatrix {
	Triple data[MAXSIZE + 1];//非零元素三元组表 data[0]不用 也就是存放压缩后的稀疏矩阵
	int position[MAXSIZE + 1];//每行第一个非零元的位置表
	int row, col, sum;  //矩阵的行数与列数以及非零元素个数
}TSMatrix;//矩阵

int i1 = 1;
int i2 = 1;
int i3 = 1;
void initmatrixA(TSMatrix* M);
void initmatrixB(TSMatrix* M);
void multi(TSMatrix& M, TSMatrix& T, TSMatrix& Q);
void Browse(TSMatrix T);
void calculateposition(TSMatrix& M);

int main(void)
{
	int q = 1, choice;
	TSMatrix M, T,Q;//初始化两个矩阵
	M.row = 0; M.col = 0;
	M.sum = 0;//初始化
	T.row = 0; T.col = 0;
	T.sum = 0;//初始化
	Q.row = 0; Q.col = 0;
	Q.sum = 0;//初始化
	while (q)
	{
		printf("\n输入A矩阵(在左边的)按1");
		printf("\n输入B矩阵(在右边的)按2");
		printf("\n乘法按3");
		printf("\n退出按0");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:initmatrixA(&M); calculateposition(M); break;
		case 2:initmatrixB(&T); calculateposition(T); break;
		case 3:multi(M, T, Q);;  break;
		case 0:exit(0);
		default:
			break;
		}
		printf("\n\n还要继续使用吗？按1继续0停止\n");
		scanf_s("%d", &q);
		system("cls");
	}
	return 0;
}


void initmatrixA(TSMatrix* M)//A矩阵输入
{
	int t = 1;
	printf("请输入矩阵\n");
	scanf_s("%d%d%d", &M->data[i1].i, &M->data[i1].j, &M->data[i1].e);
	i1++;
	printf("行  列   元素值\n");
	for (t = 1; t < i1; t++)//输出当前原矩阵的值
	{
		printf("%d    %d    %d \n", M->data[t].i, M->data[t].j, M->data[t].e);
	}
	//自动算出当前矩阵的行数与列数
	t = t - 1;//定位到当前新输入的数据中
	if (M->data[t].i >= M->row)
		M->row = M->data[t].i;
	if (M->data[t].j >= M->col)
		M->col = M->data[t].j;
	M->sum++;//非零元素加1
	printf("当前为%d行%d列矩阵,总非零元素个数为%d", M->row, M->col, M->sum);
}

void initmatrixB(TSMatrix* M)//B矩阵输入
{
	int t = 1;
	printf("请输入矩阵\n");
	scanf_s("%d%d%d", &M->data[i2].i, &M->data[i2].j, &M->data[i2].e);
	i2++;
	printf("行  列   元素值\n");
	for (t = 1; t < i2; t++)//输出当前原矩阵的值
	{
		printf("%d    %d    %d \n", M->data[t].i, M->data[t].j, M->data[t].e);
	}
	//自动算出当前矩阵的行数与列数
	t = t - 1;//定位到当前新输入的数据中
	if (M->data[t].i >= M->row)
		M->row = M->data[t].i;
	if (M->data[t].j >= M->col)
		M->col = M->data[t].j;
	M->sum++;//非零元素加1
	printf("当前为%d行%d列矩阵,总非零元素个数为%d", M->row, M->col, M->sum);
}

void multi(TSMatrix& M, TSMatrix& T, TSMatrix& Q)
{
	int arow,ccol,sum[20],ta,tb,p,brow;//sum存放运算结果
	if (M.col != T.row)//行列不等，无法进行矩阵乘法
	{
		printf("\n相乘的两个矩阵不满足列数与行数相等\n");
	}
	else if(M.sum * T.sum !=0)//说明里面有数据
	{
		Q.row = M.row; Q.col = T.col; Q.sum = 0;//将Q的数据初始化，q为M行T列
		for (arow = 1; arow <= M.row; arow++)//处理M的每一行
		{
			for (ccol = 1; ccol <= Q.col; ccol++)
				sum[ccol] = 0;//当前列元素清0
			Q.position[arow] = Q.sum + 1;//得到Q的各行非零元素位置表，肯定是前面一次循环后sum下一个位置
			if (arow < M.row)//判断是否是最后一行
				ta = M.position[arow + 1];//不是则ta为M的此行最后一个非零元位置
			else ta = M.sum + 1;//是的话就是最大值加1
			for (p = M.position[arow]; p < ta; p++)//对应当前行的每一个非零元素
			{
				brow = M.data[p].j;//找到对应元所在T中的行号，因为是M的j列与T的j行元素相乘
				if (brow < T.row)//判断是否是最后一行
					tb = T.position[brow + 1];//不是的话就将这一行的下一行起始位置传给tb
				else tb = T.sum + 1;//是的话就代表tb只有一行
				for (int q = T.position[brow]; q < tb; q++)
				{
					ccol = T.data[q].j;//乘积元素在Q中的列号
					sum[ccol] += M.data[p].e * T.data[q].e;//相乘 
				}
			}//求Q中第crow行（也就是第Arow行）的非零元
			for (ccol = 1; ccol <= Q.col; ccol++)//压缩非零元
			{
				if (sum[ccol])//如果不是0，那么压缩该行非零元素到C中
				{
					if (++Q.sum > MAXSIZE)//如果超过上限，不操作
						exit(1);
					else
					{
						Q.data[Q.sum].i = arow;//M的行数
						Q.data[Q.sum].j = ccol;//T的列数
						Q.data[Q.sum].e = sum[ccol];
					}
				}
			}
		}
		Browse(Q);
	}
}

void Browse(TSMatrix T)//显示
{
	printf("\n算出的结果如下\n");
	printf("行  列   元素值\n");
	for (int t = 1; t <=T.sum; t++)//输出当前原矩阵的值
	{
		printf("\n%d    %d    %d \n", T.data[t].i, T.data[t].j, T.data[t].e);
	}
}

void calculateposition(TSMatrix& M)//算出每一行非零元素的起始位置  position其实就是每一行非零元素的列的存储，可以通过这个在计算乘积时快速找到对应的元素行数
{
	int number[MAXSIZE+1];//定义数组最大
	int j;
	for (j = 1; j <= M.row; j++)
	{
		number[j] = 0;//清0初始化
	}
	for (int t = 1; t <= M.sum; t++)
	{
		number[M.data[t].i]++;//每一行非零元素个数
	}
	M.position[1] = 1;//初始位置当然是0啦
	for (j = 2; j <= M.row; j++)
		M.position[j] = M.position[j - 1] + number[j - 1];//计算每一行非零元素的位置占据
	//也就是说这一行的起始位置等于上一行的起始位置加上上一行非零元素个数
	//for (j = 1; j <=M.row; j++)
	//{
//		printf("\n%d",M.position[j]);
//	}
}