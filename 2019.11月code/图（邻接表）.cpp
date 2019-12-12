#include<stdio.h>
#include<stdlib.h>
#define MAX 256

typedef struct edgenode {//边界点的结构地
	int adjvex;//顶点编号
	int weight;//权值大小
	edgenode* next;
}edgenode;

typedef struct VertrxNode {//顶点结构体
	int data;//顶点编号
	int indegree = 0;//这个顶点的入度
	edgenode* firstedge;//头指针
}VerxNode;

/*用一个一维数组来存放与相对于节点代号相连各个节点*/
typedef struct Graph {
	VertrxNode adjlist[MAX];//存放头结点
	int nodenum = 1;//0下标弃置不用
	int edgenum = 0;//图中顶点数和边数
}Graph;


typedef struct stack {
	int datastack[30];
	int top = 0;
}stack;//栈的结构体

void creat(Graph *g)
{
	int i, j, k;
	edgenode* e;
	printf("\n请输入顶点(以-1结束)");
	scanf_s("%d",&i);
	while (i != -1)
	{
		g->adjlist[g->nodenum].data = i;//顶点信息，也就是编号
		g->adjlist[g->nodenum].firstedge= NULL;//一开始没有顶点与其相连
		printf("\n当前已有%d个节点",g->nodenum++);
		printf("\n请输入顶点(以-1结束)");
		scanf_s("%d", &i);
	}
	g->nodenum--;//之前的循环中多加了一次
	printf("\n请输入边（vi,vj）的顶点序号及权值");//开始连接顶点
	printf("\n以0 0 0结束");
	scanf_s("%d %d %d",&i,&j,&k);
	while (i && j )
	{
		if (i == j || i >g->nodenum || j>g->nodenum)
			printf("\ninvalid node!");
		else
		{
			e = (edgenode*)malloc(sizeof(edgenode));//分配节点
			e->adjvex = j;//vj顶点编号
			e->weight = k;
			e->next = g->adjlist[i].firstedge;//头插法
			g->adjlist[i].firstedge = e;
			g->adjlist[j].indegree++;//由i到j，j的入度加一
			printf("%d", g->adjlist[j].indegree);
			/*无向图如果是有向图将下面赋值删了皆可*/
			/*e = (edgenode*)malloc(sizeof(edgenode));//分配节点
			e->adjvex = i;//vj顶点编号
			e->weight = k;
			e->next = g->adjlist[j].firstedge;//头插法
			g->adjlist[j].firstedge = e;*/


			g->edgenum++;//边数加一
			printf("\n请输入边（vi,vj）的顶点序号及权值");
			printf("\n以0 0 0结束");
			scanf_s("%d %d %d", &i, &j, &k);
		}
	}
	//for (i = 1; i <= g->nodenum; i++)   测试用，查看所有节点入度
	//	printf("%d",g->adjlist[i].indegree);
	//i = 1;
	//for (e = g->adjlist[i].firstedge; e; e = e->next)//这个顶点出发到相邻节点的入度减一
	//{
	//	k = e->adjvex;
	//	printf("%d",k);//得到相连节点编号
	//}   测试用
}

void push(stack &S, int i)
{
	if (S.top == 49)
		printf("栈满");
	else
		S.datastack[S.top++] = i;//入栈
}

int pop(stack &S)
{
	if (S.top == 0)
		printf("栈空，无法出战");
	else
		return S.datastack[--S.top];
}


void TopologicalSort(Graph *g)
{
	edgenode* e;
	int i, k, gettop;
	int counter = 0;//用来统计输出几个顶点
	stack S;//用来存放入度为0的顶点
	S.top = 0;
	for (i = 1; i <= g->nodenum; i++)
	{
		if (g->adjlist[i].indegree == 0)
			push(S, i);
	}
	//printf("\n%d",S.top);
	//printf("sdfsdfsd%d",S.datastack[S.top-1]);/*
	while (S.top != 0)
	{
		printf("\n栈内情况");
		for (i = 0; i < S.top; i++)	
			printf("%d", S.datastack[i]);
		gettop = pop(S);//出栈一个
		printf("打印节点%d -> ",g->adjlist[gettop].data);//打印
		counter++;//输出顶点数加1
		for (e = g->adjlist[gettop].firstedge; e; e = e->next)//这个顶点出发到相邻节点的入度减一
		{
			k = e->adjvex;//得到相连节点编号
			if ((--g->adjlist[k].indegree == 0))//如果减去之后的入度为1
				push(S, k);//入栈
		}
	}
	printf("null");
	if (counter == g->nodenum)
		printf("\n拓扑排序成功");
	else
		printf("\n拓扑排序未成功");
}

int main(void)
{
	Graph G;
	creat(&G);
	TopologicalSort(&G);
	return 0;
}