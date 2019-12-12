#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXNODE 20
#define INFINITY 256256

/*typedef struct AdjMatrix {
	int [MAXNODE][MAXNODE];//邻接矩阵
	int info;
}AdjMatrix[MAXNODE][MAXNODE];*/

typedef struct Graph{
	int node[MAXNODE];//顶点信息
	int arcs[MAXNODE][MAXNODE];//顶点之间的连线
	int nodenum = 1;//总顶点数 
	int edgenum = 0;//总边数
} Graph;//图的结构体

int visited[MAXNODE];//标志数组，dfs用来看是否被访问过

typedef struct queue {
	int data[MAXNODE];
	int front;
	int rear;//队头队尾
}queue;

void Creat(Graph &g)//图的创建
{
	int i, j;
	int w;//权重
	int x;
	printf("\n输入顶点代号（以-1结束）");
	scanf_s("%d",&x);
	while(x != -1)
	{
		g.node[g.nodenum] = x;
		printf("现在有%d个顶点",g.nodenum++);
		printf("\n输入顶点代号（以-1结束）");
		scanf_s("%d", &x);
	}
	g.nodenum--;//上一个while多加了一个节点
	for (i = 1; i <=g.nodenum; i++)
		for (j = 1; j <= g.nodenum; j++)
		{
			if (i == j)
				g.arcs[i][j] = g.arcs[j][i] = INFINITY;//如果是自身那么就为∞
			else
				g.arcs[j][i]=g.arcs[i][j] = INFINITY;
		}
	//邻接矩阵初始化，无穷代表i行j列无连接且无权值
	printf("输入边(vi,vj)上的下标i，下标j和权w:(以空格隔开，0 0 0结束)\n");
	scanf_s("%d %d %d", &i, &j, &w); /* 输入边(vi,vj)上的权w */
	while(i&&j)
	{
		if (i >g.nodenum || j >g.nodenum||i==j)
			printf("\ninvalid nodes!");//如果顶点编号大于总数或者是同一个顶点无效
		else
		{
			g.edgenum++;
			//1代表第i个与第j个节点有连线
			g.arcs[j][i] = g.arcs[i][j] = w;//因为是无向图，所以要两个都赋值
		}
		printf("\n输入边(vi,vj)上的下标i，下标j和权w:(以空格隔开，0 0 0结束)\n");
		scanf_s("%d %d %d", &i, &j, &w); /* 输入边(vi,vj)上的权w */
	}
	for (i = 1;i<=g.nodenum;i++)
	{
		for (j = 1; j <= g.nodenum; j++)
		{
			printf("\t%d",g.arcs[i][j]);
		}
		printf("\n");
	}
}

void DFS(Graph g, int i)
{
	int j;
	visited[i] = 1;//该节点已访问
	printf("\t%d", g.node[i]);//打印顶点代号
	for (j = 1; j <=g.nodenum; j++)//
		if (!visited[j] && g.arcs[i][j] != INFINITY)//如果这个节点与其他节点有连线且相连的节点未被调用
			DFS(g, j);//递归调用
}
/*深度遍历*/
/*迷宫点灯*/
/*从一个顶点进入，选取一个与之相连的顶点，挪到这个顶点并点亮这个顶点，重复这个操作，知道与一个顶点相连的顶点都被点亮，原路返回，看是否都点亮*/
/*如果都点亮，那么原路返回一个，如果没有，选取一个没有点亮的节点，重复上面点亮操作，直到退回起点，代表全部点亮*/
void DFSTraverse(Graph g)
{
	int v;
	for (v = 1; v <= g.nodenum;v++)
	{
		visited[v] = 0;//一开始全部未访问过
	}
	printf("\nthe result of dfs is behind:\n");
	for (v = 1; v <=g.nodenum; v++)//对未访问过的节点dfs
		if (!visited[v])
			DFS(g, v);
}


void queuein(queue* q, int x)//入队
{
	if ((q->rear + 1) % MAXNODE == q->front)//如果队尾后移模MAXSIZE为队头的话则为队满
		printf("已满");
	else
	{
		q->rear = (q->rear + 1) % MAXNODE;//队尾后移一个赋值
		q->data[q->rear] = x;
	}
}

void queueout(queue* q, int *u)//队头出队
{
	int x;
	if (q->front == q->rear)//如果头尾相同则说明无数据
	{
		printf("队列空！");
	}
	else
	{
		q->front = (q->front + 1) % MAXNODE;//队头后移并取出此时的数据，队头指向队列第一个元素前一个位置
		x = q->data[q->front];
		*u = x;
	}
}

/*广度优先搜索*/
/*类似于树的层次遍历，先访问一个顶点，然后将与之相连的顶点入队，然后递归调用*/
void BFSTraverse(Graph g)
{
	int u;
	int v;
	for (v = 0; v <= g.nodenum; v++)
		visited[v] = 0;//清零初始化
	queue Q;
	Q.front = Q.rear = 0;
	for  (v= 1;v<=g.nodenum;v++)
	{
		if (!visited[v])
		{
			visited[v] = 1;
			printf("\t%d",g.node [v]);
			queuein(&Q, v);
			while (Q.front != Q.rear)
			{
				queueout(&Q,&v);
				for(int j =1;j<=g.nodenum;j++)
					if (!visited[j] && g.arcs[v][j] != INFINITY)
					{
						visited[j] = 1;
						printf("\t%d",g.node[j]);
						queuein(&Q,j);
					}
			}
		}
	}
}
/*最小生成树prim算法的思想*/
/*
每次扫描与该顶点A相连的顶点X\之间的权值，如果比保存的lowcost[x]中值小，那么用该权值代替lowcost值并且修改到达x最快的顶点为A
lowcost数组中保存的是已完成的生成树顶点集合到与集合相连的顶点x的最小值
adjvex数组中保存的是到对应顶点的权值最小的相连节点代号
*/
void MiniSpanTree_prim(Graph G)
{
	int min, i, j, k;
	int adjvex[MAXNODE];//保存相关顶点下标,也就是最小权值的相连的顶点
	int lowcost[MAXNODE];//保存相关顶点间边的权值
	lowcost[1] = 0;//第一个顶点加入生成树
		//lowcost[i]=0 代表第i个顶点加入生成树
	adjvex[1] = 1;//初始化第一个顶点为1
	for(i=2;i<=G.nodenum ;i++)
	{
		lowcost[i] = G.arcs[1][i];//存放权值，看是否相连以及之后权值大小的判断
		adjvex[i] = 1;//初始化时下标都指向第一个顶点
	}
	
	for (i = 2; i <= G.nodenum; i++)
	{
		printf("\n当前adjvex");
		for (int q = 1; q <= G.nodenum; q++)
			printf("\t%d", adjvex[q]);
		printf("\n当前lowcost");
		for (int q = 1; q <= G.nodenum; q++)
			printf("\t%d", lowcost[q]);
		min = INFINITY;//每一次寻找的初始化为∞
		j = 2; k = 1;
		while (j <= G.nodenum)
		{
			if (lowcost[j] != INFINITY&&lowcost[j]<min && lowcost[j] != 0)//如果这两点相连且权值小于min
			{
				min = lowcost[j];
				k = j;
			}
			j++;//判断下一个
		}
		printf("\n当前权值最小为第%d个顶点与顶点%d",adjvex[k],k);
		lowcost[k] = 0;//代表当前顶点已加入生成树
		for(j = 2;j<=G.nodenum ;j++)
		{
			if (G.arcs[k][j] < lowcost[j]&&lowcost[j]!=0)//如果不是相连或者已经加入生成树并且比lowcost小
			{
				lowcost[j] = G.arcs[k][j];//那么修改到达这个顶点的最小值
				adjvex[j] = k;//修改到达这个顶点最快的点
			}
		}
	}
}
int main(void)
{
	Graph g;//初始化邻接矩阵
	int q = 1;
	int choice;
	while (q)
	{
		system("cls");
		printf("输入节点请按1");
		printf("\ndfs,put 2");
		printf("\nbfs,put 3");
		printf("\nminispantree_prim,put 4");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:Creat(g); break;
		case 2:DFSTraverse(g); break;
		case 3:BFSTraverse(g); break;
		case 4: MiniSpanTree_prim(g); break;
		}
		printf("\ncontinue to use?");
		scanf_s("%d", &q);
	}
	return 0;
}
