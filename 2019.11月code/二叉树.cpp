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

typedef struct node{//�ǵݹ�������
	Btree* t;
	int tag;//tagΪ0��1�������Ƿ������������
}stack;

typedef struct queue {//��α���
	Btree* Tree[MAXSIZE];
	int rear, front;//��ͷ��β
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
void caculatedepth1(Btree* T, int depth);//�ǵݹ������
void caculateleaf1(Btree* T);//�ǵݹ���Ҷ��
int counter = 0;//����ڵ����
int counter1 = 0;//����Ҷ�ӽڵ���
int level = 0;//�������

int main(void)
{
	Btree *T;
	T = (Btree*)malloc(sizeof(LEN));
	T = NULL;
	int q = 1, choice;
	while (q)
	{
		printf("\n������ѡ��");
		printf("\n�ǵݹ鴴���������밴1");
		printf("\n�ݹ�ǰ������밴2");
		printf("\n�ݹ���������밴3");
		printf("\n�ݹ��������밴4");
		printf("\n�鿴��ǰ�ڵ�����밴5");
		printf("\n�ݹ齨���������밴6");
		printf("\n�ǵݹ�ǰ������밴7");
		printf("\n�ǵݹ���������밴8");
		printf("\n�ǵݹ��������밴9");
		printf("\n��α����밴10");
		printf("\n�ݹ����Ҷ�����밴11");
		printf("\n�ݹ��������밴12");
		printf("\n�ǵݹ齻�����������밴13");
		printf("\n�ǵݹ���Ҷ�ӽڵ㰴14");
		printf("\n�ǵݹ�����Ȱ�15");
		printf("\n�ݹ齻������������16");
		printf("\n�˳��밴0");
		scanf_s("%d",&choice);
		switch (choice)
		{
		case 1:T=creat(T); break;
		case 2:preOrderTraverse(T); break;
		case 3:inOrderTraverse(T); break;
		case 4:rearOrderTraverse(T); break;
		case 5:printf("\n��ǰ����%d���ڵ�\n", counter); break;
		case 6:T = recursivecreation(); break;
		case 7:preorder(T); break;
		case 8:inorder(T); break;
		case 9:postorder(T); break;
		case 10:levelorder(T);break;
		case 11:counter1 = 0; caculateleaf(T); printf("\n������%d��Ҷ��", counter1); break;
		case 12:caculatedepth(T, 1); printf("\n���Ϊ%d",level); break;
		case 13:exchange(T); break;
		case 14:counter1 = 0; caculateleaf1(T); printf("\n������%d��Ҷ��", counter1); break;
		case 15:caculatedepth1(T, 0); printf("\n���Ϊ%d", level); break;
		case 16:exchange1(T); break;
		case 0:	exit(0);
		default:printf("�������");
		}
		printf("\n��Ҫ����ʹ����");
		scanf_s("%d",&q);
		system("cls");
	}
	return 0;
}

//�ǵݹ鴴��������
Btree *creat(Btree *T)
{
	int count=0;
	int n;
	Btree* tree[MAXSIZE];//�����
	for (n = 0;  n < MAXSIZE;  n++)
	{
		tree[n] = NULL;
	}
	Btree* q;
	q = (Btree*)malloc(sizeof(Btree));
	int i, j;
	char x;
	printf("\n��������ź����ݣ��Կո����������0��������\n");
	scanf_s("%d %c",&i,&x);
	while (i != 0 && i < MAXSIZE)//
	{
		q = (Btree*)malloc(sizeof(Btree));
		q->data = x;
		q->lchild = NULL;
		q->rchild = NULL;
		tree[i] = q;//�ڼ�����ž�������²���
		if (i == 1)
			T = q;
		else
		{
			j = i / 2;//��ͼ�ҳ���˫�׽ڵ�
			if (i % 2 == 0)
				tree[j]->lchild = q;//���iΪ2��������������
			else
				tree[j]->rchild = q;//����Ϊ������
		}
		printf("\n��������ź����ݣ��Կո����������0��������\n");
		scanf_s("%d %c", &i, &x);//������
		
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


void preOrderTraverse(Btree *T)//�ݹ�ǰ�����
{
	if (T)
	{
		printf("%c", T->data);
		preOrderTraverse(T->lchild );
		preOrderTraverse(T->rchild);
	}
}

void inOrderTraverse(Btree* T)//�ݹ��������
{
	if (T)
	{
		inOrderTraverse(T->lchild);
		printf("%c", T->data);
		inOrderTraverse(T->rchild);
	}
}

void rearOrderTraverse(Btree* T)//�ݹ�������
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
	printf("\n���������� ��#����");
	scanf("%c",&temp);//��дʱ��������  ������ַ���temp������scanf�������������ֵʱ������������ַ����鲢����scanf_s���������ֺ����������ֵtemp�����
	if (temp=='#')
	{
		T = NULL;
	}
	else
	{
		T = (Btree*)malloc(sizeof(Btree));
		T->data = temp;
		printf("������");
		T->lchild = recursivecreation();
		printf("������");
		T->rchild = recursivecreation();
	}
	return T;
}
*/
Btree* recursivecreation(void)
{
	char temp[10];
	Btree* T;
	printf("\n���������� ��#����");
	scanf("%s", &temp[0]);//��дʱ��������  ������ַ���temp������scanf�������������ֵʱ������������ַ����鲢����scanf_s���������ֺ����������ֵtemp�����
	if (strcmp(temp,"#")==0)
	{
		T = NULL;
	}
	else
	{
		counter++;
		T = (Btree*)malloc(sizeof(Btree));
		T->data = temp[0];
		printf("%c��������",T->data );
		T->lchild = recursivecreation();
		printf("%c��������",T->data );
		T->rchild = recursivecreation();
	}
	return T;
}

void preorder(Btree *T)//�ǵݹ�ǰ�����
{
	Btree *tree[MAXSIZE];
	int	top = 0;//ջ��ָ��
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

void inorder(Btree* T)//����ǵݹ����
{
	Btree* tree[MAXSIZE];
	int	top = 0;//ջ��ָ��
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

void postorder(Btree *T)//����ǵݹ����
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
		printf("\n��������");
	else
		q->Tree[++q->rear] = T;
}

void queueout(queue* q,Btree* &T)//����Ҫ����T���ԼӸ�ȡ��ַ����
{
	if (q->front == q->rear)
		printf("\n��������Ԫ��");
	else
	{
		T = q->Tree[++q->front];
	}
}

void levelorder(Btree *T)//��α���
{
	queue  q;
	q.rear = q.front = 0;
	if (T != NULL)
		queuein(&q, T);//������ڵ㲻ΪNULL����ô���
	while (q.rear != q.front)//������в���
	{
		queueout(&q,T);//����һ���ڵ�
		printf("%c", T->data);//��ӡ
		if (T->lchild != NULL)//������ڵ������������ӣ���Ϊ����LILO���Բ��ص������ǻ���ǰ��ӡ
			queuein(&q,T->lchild );
		if (T->rchild != NULL)
			queuein(&q,T->rchild );
	}
}

void caculateleaf(Btree* T)//�ݹ���Ҳֻ����ʵ���ǵݹ�ǰ�������һ�ġ���������
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
			counter1++;
		caculateleaf(T->lchild);
		caculateleaf(T->rchild);
	}
}


void caculateleaf1(Btree* T)//�ǵݹ���Ҷ��
{
	Btree* tree[MAXSIZE];
	int	top = 0;//ջ��ָ��
	while (T != NULL || top != 0)
	{
		while (T != NULL)
		{
			tree[++top] = T;
			if (T->lchild == NULL && T->rchild == NULL)//�ж�
				counter1++;
			T = T->lchild;
		}
		if (top != 0)
			T = tree[top--]->rchild;
		
	}
}

void caculatedepth(Btree* T, int depth)//�ݹ������
{
	if (T)
	{
		if (depth > level)
			level = depth;//�����ǰ��ȴ���֮ǰ��ס����ȣ���ô�滻��
		caculatedepth(T->lchild, depth+1);//�ݹ����
		caculatedepth(T->rchild ,depth+1);
	}
}

void caculatedepth1(Btree* T, int depth)//�ǵݹ������
{
	queue  q;
	q.rear = q.front = 0;
	if (T != NULL)
		queuein(&q, T);//������ڵ㲻ΪNULL����ô���
	while (q.rear != q.front)//������в���
	{
		level++;
		int len = q.rear - q.front ;
		while (len--)
		{
			queueout(&q, T);//����һ���ڵ�
			if (T->lchild != NULL)//������ڵ������������ӣ���Ϊ����LILO���Բ��ص������ǻ���ǰ��ӡ
				queuein(&q, T->lchild);
			if (T->rchild != NULL)
				queuein(&q, T->rchild);
		}
	}
}

void exchange(Btree* T)//��������α�����һ�ģ���������ݸ�Ϊ�����ڵ����ʵ�ִ��ϵ��µ�������������
{
	Btree* temp;//����м����
	queue  q;
	q.rear = q.front = 0;
	if (T != NULL)
		queuein(&q, T);//������ڵ㲻ΪNULL����ô���
	while (q.rear != q.front)//������в���
	{
		queueout(&q, T);//����һ���ڵ�
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;//�����ڵ�
		if (T->lchild != NULL)//������ڵ�������������
			queuein(&q, T->lchild);
		if (T->rchild != NULL)
			queuein(&q, T->rchild);
	}
}

void exchange1(Btree* T)
{
	Btree* temp;//����м����
	if (T != NULL)
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;//�����ڵ�
		exchange1(T->lchild);
		exchange1(T->rchild);
	}
}