#include<stdio.h>
#include<stdlib.h>
#include<string>
#define LEN  sizeof(Btree)
#define MAXSIZE 64

typedef struct Btree{
	char data;
	Btree* lchild;
	Btree* rchild;
}Btree;

typedef struct node{//非递归后序遍历
	Btree* t;
	int tag;//tag为0或1，代表是否输出过左子树
}stack;

typedef struct queue {//层次遍历
	Btree* Tree[MAXSIZE];
	int rear, front;//队头队尾
}queue;

Btree* creat(Btree *T);
void preOrderTraverse(Btree *T);
void rearOrderTraverse(Btree* T);
void inOrderTraverse(Btree* T);
Btree* recursivecreation(void);
void preorder(Btree* T);
void inorder(Btree* T);
void postorder(Btree* T);
void queuein(queue* q, Btree* T);
void queueout(queue* q, Btree*& T);
void levelorder(Btree* T);
void caculateleaf(Btree *T);
void caculatedepth(Btree* T, int depth);
void exchange1(Btree* T);
void exchange(Btree* T);
void caculatedepth1(Btree* T, int depth);//非递归算深度
void caculateleaf1(Btree* T);//非递归算叶子
int counter = 0;//计算节点个数
int counter1 = 0;//计算叶子节点数
int level = 0;//计算深度

int main(void)
{
	Btree *T;
	T = (Btree*)malloc(sizeof(LEN));
	T = NULL;
	int q = 1, choice;
	while (q)
	{
		printf("\n请输入选择");
		printf("\n非递归创立二叉树请按1");
		printf("\n递归前序遍历请按2");
		printf("\n递归中序遍历请按3");
		printf("\n递归后序遍历请按4");
		printf("\n查看当前节点个数请按5");
		printf("\n递归建立二叉树请按6");
		printf("\n非递归前序遍历请按7");
		printf("\n非递归中序遍历请按8");
		printf("\n非递归后序遍历请按9");
		printf("\n层次遍历请按10");
		printf("\n递归计算叶子数请按11");
		printf("\n递归计算深度请按12");
		printf("\n非递归交换左右子树请按13");
		printf("\n非递归算叶子节点按14");
		printf("\n非递归算深度按15");
		printf("\n递归交换左右子树按16");
		printf("\n退出请按0");
		scanf_s("%d",&choice);
		switch (choice)
		{
		case 1:T=creat(T); break;
		case 2:preOrderTraverse(T); break;
		case 3:inOrderTraverse(T); break;
		case 4:rearOrderTraverse(T); break;
		case 5:printf("\n当前共有%d个节点\n", counter); break;
		case 6:T = recursivecreation(); break;
		case 7:preorder(T); break;
		case 8:inorder(T); break;
		case 9:postorder(T); break;
		case 10:levelorder(T);break;
		case 11:counter1 = 0; caculateleaf(T); printf("\n该树有%d个叶子", counter1); break;
		case 12:caculatedepth(T, 1); printf("\n深度为%d",level); break;
		case 13:exchange(T); break;
		case 14:counter1 = 0; caculateleaf1(T); printf("\n该树有%d个叶子", counter1); break;
		case 15:caculatedepth1(T, 0); printf("\n深度为%d", level); break;
		case 16:exchange1(T); break;
		case 0:	exit(0);
		default:printf("输入错误");
		}
		printf("\n还要继续使用吗？");
		scanf_s("%d",&q);
		system("cls");
	}
	return 0;
}

//非递归创立二叉树
Btree *creat(Btree *T)
{
	int count=0;
	int n;
	Btree* tree[MAXSIZE];//存放树
	for (n = 0;  n < MAXSIZE;  n++)
	{
		tree[n] = NULL;
	}
	Btree* q;
	q = (Btree*)malloc(sizeof(Btree));
	int i, j;
	char x;
	printf("\n请输入序号和数据，以空格隔开，输入0结束输入\n");
	scanf_s("%d %c",&i,&x);
	while (i != 0 && i < MAXSIZE)//
	{
		q = (Btree*)malloc(sizeof(Btree));
		q->data = x;
		q->lchild = NULL;
		q->rchild = NULL;
		tree[i] = q;//第几个序号就是这个新插入
		if (i == 1)
			T = q;
		else
		{
			j = i / 2;//试图找出其双亲节点
			if (i % 2 == 0)
				tree[j]->lchild = q;//如果i为2倍数则是左子树
			else
				tree[j]->rchild = q;//否则为右子树
		}
		printf("\n请输入序号和数据，以空格隔开，输入0结束输入\n");
		scanf_s("%d %c", &i, &x);//再输入
		
	}
	for (n = 0; n < MAXSIZE; n++)
	{
		if (tree[n] != NULL)
			count++;
	}
	printf("%d",count);
	counter = count;
	return T;
}


void preOrderTraverse(Btree *T)//递归前序遍历
{
	if (T)
	{
		printf("%c", T->data);
		preOrderTraverse(T->lchild );
		preOrderTraverse(T->rchild);
	}
}

void inOrderTraverse(Btree* T)//递归中序遍历
{
	if (T)
	{
		inOrderTraverse(T->lchild);
		printf("%c", T->data);
		inOrderTraverse(T->rchild);
	}
}

void rearOrderTraverse(Btree* T)//递归后序遍历
{
	if (T)
	{
		rearOrderTraverse(T->lchild);
		rearOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
}

/*
Btree *recursivecreation(void)
{
	char temp;
	Btree* T;
	printf("\n请输入数据 以#结束");
	scanf("%c",&temp);//编写时遇到问题  如果用字符型temp并且用scanf则会在左子树赋值时出错。如果不用字符数组并且用scanf_s函数则会出现好像根本不赋值temp的情况
	if (temp=='#')
	{
		T = NULL;
	}
	else
	{
		T = (Btree*)malloc(sizeof(Btree));
		T->data = temp;
		printf("左子树");
		T->lchild = recursivecreation();
		printf("右子树");
		T->rchild = recursivecreation();
	}
	return T;
}
*/
Btree* recursivecreation(void)
{
	char temp[10];
	Btree* T;
	printf("\n请输入数据 以#结束");
	scanf("%s", &temp[0]);//编写时遇到问题  如果用字符型temp并且用scanf则会在左子树赋值时出错。如果不用字符数组并且用scanf_s函数则会出现好像根本不赋值temp的情况
	if (strcmp(temp,"#")==0)
	{
		T = NULL;
	}
	else
	{
		counter++;
		T = (Btree*)malloc(sizeof(Btree));
		T->data = temp[0];
		printf("%c的左子树",T->data );
		T->lchild = recursivecreation();
		printf("%c的右子树",T->data );
		T->rchild = recursivecreation();
	}
	return T;
}

void preorder(Btree *T)//非递归前序遍历
{
	Btree *tree[MAXSIZE];
	int	top = 0;//栈顶指针
	while (T != NULL || top != 0)
	{
		while (T != NULL)
		{
			printf("%c", T->data);
			tree[++top] = T;
			T = T->lchild;
		}
		if (top != 0)
			T = tree[top--]->rchild;
	}
}

void inorder(Btree* T)//中序非递归遍历
{
	Btree* tree[MAXSIZE];
	int	top = 0;//栈顶指针
	while (T != NULL || top != 0)
	{
		while (T != NULL)
		{
			tree[++top] = T;
			T = T->lchild;
		}
		if (top != 0)
		{
			T = tree[top--];
			printf("%c", T->data);
			T = T->rchild;
		}
	}
}

void postorder(Btree *T)//后序非递归遍历
{
	stack s[MAXSIZE];
	int top = 0;
	while (T != NULL || top != 0)
	{
		while (T != NULL)
		{
			s[++top].t = T;
			s[top].tag = 0;
			T = T->lchild;
		}
		while (top != 0 && s[top].tag == 1)
			printf("%c",T->data );
		if (top)
		{
			s[top].tag = 1;
			T = s[top].t->rchild;
		}
	}
}

void queuein(queue* q, Btree* T)
{
	if (q->rear == MAXSIZE)
		printf("\n队列满！");
	else
		q->Tree[++q->rear] = T;
}

void queueout(queue* q,Btree* &T)//这里要返回T所以加个取地址符号
{
	if (q->front == q->rear)
		printf("\n队列中无元素");
	else
	{
		T = q->Tree[++q->front];
	}
}

void levelorder(Btree *T)//层次遍历
{
	queue  q;
	q.rear = q.front = 0;
	if (T != NULL)
		queuein(&q, T);//如果根节点不为NULL，那么入队
	while (q.rear != q.front)//如果队列不空
	{
		queueout(&q,T);//出队一个节点
		printf("%c", T->data);//打印
		if (T->lchild != NULL)//将这个节点的左右子树入队，因为队列LILO所以不必担心他们会提前打印
			queuein(&q,T->lchild );
		if (T->rchild != NULL)
			queuein(&q,T->rchild );
	}
}

void caculateleaf(Btree* T)//递归算也只，其实就是递归前序遍历改一改·····
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
			counter1++;
		caculateleaf(T->lchild);
		caculateleaf(T->rchild);
	}
}


void caculateleaf1(Btree* T)//非递归算叶子
{
	Btree* tree[MAXSIZE];
	int	top = 0;//栈顶指针
	while (T != NULL || top != 0)
	{
		while (T != NULL)
		{
			tree[++top] = T;
			if (T->lchild == NULL && T->rchild == NULL)//判断
				counter1++;
			T = T->lchild;
		}
		if (top != 0)
			T = tree[top--]->rchild;
		
	}
}

void caculatedepth(Btree* T, int depth)//递归算深度
{
	if (T)
	{
		if (depth > level)
			level = depth;//如果当前深度大于之前记住的深度，那么替换掉
		caculatedepth(T->lchild, depth+1);//递归计算
		caculatedepth(T->rchild ,depth+1);
	}
}

void caculatedepth1(Btree* T, int depth)//非递归算深度
{
	queue  q;
	q.rear = q.front = 0;
	if (T != NULL)
		queuein(&q, T);//如果根节点不为NULL，那么入队
	while (q.rear != q.front)//如果队列不空
	{
		level++;
		int len = q.rear - q.front ;
		while (len--)
		{
			queueout(&q, T);//出队一个节点
			if (T->lchild != NULL)//将这个节点的左右子树入队，因为队列LILO所以不必担心他们会提前打印
				queuein(&q, T->lchild);
			if (T->rchild != NULL)
				queuein(&q, T->rchild);
		}
	}
}

void exchange(Btree* T)//二叉树层次遍历改一改，将输出数据改为交换节点就能实现从上到下的左右子树交换
{
	Btree* temp;//存放中间变量
	queue  q;
	q.rear = q.front = 0;
	if (T != NULL)
		queuein(&q, T);//如果根节点不为NULL，那么入队
	while (q.rear != q.front)//如果队列不空
	{
		queueout(&q, T);//出队一个节点
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;//交换节点
		if (T->lchild != NULL)//将这个节点的左右子树入队
			queuein(&q, T->lchild);
		if (T->rchild != NULL)
			queuein(&q, T->rchild);
	}
}

void exchange1(Btree* T)
{
	Btree* temp;//存放中间变量
	if (T != NULL)
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;//交换节点
		exchange1(T->lchild);
		exchange1(T->rchild);
	}
}