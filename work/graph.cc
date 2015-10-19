#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXSIZE 20
#define INFINITY 65535


typedef struct MGraph{
    char vexs[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int numVex,numEdg;
};

typedef struct EdgNode{
    int Adjedg;
    int weight;
    struct EdgNode *next;
};

typedef struct VexNode{
    int vex;
    EdgNode *firstedg;
};

typedef struct AdjGraph{
    VexNode vexnode[MAXSIZE];
    int numVex,numEdg;
};

/*创建图，点数，边数*/
void creat_graph(MGraph *g, int vex, int edg)
{
    g->numVex = vex;
    g->numEdg = edg;
    int i = 0,vi,j = 0,vj,w;

    for(i = 0; i < g->numVex; i++)
    {
        g->vexs[i] = 'A'+i;
        cout << g->vexs[i] << " ";
    }
    cout << endl;

    for(i = 0; i < g->numVex; i++)
        for(j = 0; j < g->numVex; j++)
            g->arc[i][j] = INFINITY;

    /*
    for(i = 0; i < g->numEdg; i++)
    {
        cout << "请分别输入边的上下标序号，权值" << endl;
        cin >> vi >> vj >> w;
        g->arc[vi][vj] = w;
        g->arc[vj][vi] = w;//若为无向图
    }
    */
    g->arc[0][1] = 10; g->arc[0][5] = 11; 
    g->arc[1][0] = 10; g->arc[5][0] = 11; 
    g->arc[1][2] = 18; g->arc[1][6] = 16; g->arc[1][8] = 12;
    g->arc[2][1] = 18; g->arc[6][1] = 16; g->arc[8][1] = 12;
    g->arc[2][3] = 22; g->arc[2][8] = 8;
    g->arc[3][2] = 22; g->arc[8][2] = 8;
    g->arc[3][4] = 20; g->arc[3][6] = 24; g->arc[3][7] = 16; g->arc[3][8] = 21;
    g->arc[4][3] = 20; g->arc[6][3] = 24; g->arc[7][3] = 16; g->arc[8][3] = 21;
    g->arc[4][5] = 26; g->arc[4][7] = 7;
    g->arc[5][4] = 26; g->arc[7][4] = 7;
    g->arc[5][6] = 17; 
    g->arc[6][5] = 17; 
    g->arc[6][7] = 19; 
    g->arc[7][6] = 19; 
}

void creat_Adjgraph(AdjGraph *g, int vexs, int edges)
{
    g->numVex = vexs;
    g->numEdg = edges;

    int i,vi,vj,w;
    for(i = 0; i < g->numVex; i++)
    {
        g->vexnode[i].vex = i;
        g->vexnode[i].firstedg = NULL;
    }

    for(i = 0; i < g->numEdg; i++)
    {
        cout << "请分别输入边的上下标序号，权值" << endl;
        cin >> vi >> vj >> w;
        /*尾插法
        EdgNode *E =g->vexnode[i].firstedg;
        while(L)
        {
            L = L->next;
        }
        EdgNode *newnode = (EdgNode*)malloc(sizeof(EdgNode));
        newnode->Adjedg = vj;
        newnode->next = L->next;
        L->next = newnode;*/

        /*头插法*/
        EdgNode *newnode = (EdgNode*)malloc(sizeof(EdgNode));
        newnode->Adjedg = vj;
        newnode->weight = w;
        newnode->next = g->vexnode[vi].firstedg;
        g->vexnode[vi].firstedg = newnode;

        /*EdgNode *newnode = (EdgNode*)malloc(sizeof(EdgNode));
        newnode->Adjedg = vi;
        newnode->next = g->vexnode[vj].firstedg;
        g->vexnode[vj].firstedg = newnode;*///无向图
    }
}

void print_graph(MGraph g)
{
    for(int i = 0; i < g.numVex; i++)
    {
        for(int j = 0; j < g.numVex; j++)
            cout << g.arc[i][j] << " " ;
        cout << endl;
    }
}

int visited[MAXSIZE];//标志访问顶点

void DFS(MGraph g,int vex)
{
    visited[vex] = 1;

    cout << g.vexs[vex] << " " ;
    int i = 0;
    for(; i < g.numVex; i++)
    {
        if(g.arc[vex][i] != INFINITY && !visited[i])
            DFS(g,i);
    }
}

void DFS_Graph(MGraph g)
{
    int i;
    cout << "The DFS sequence is: ";
    for(i = 0; i < MAXSIZE; i++)
        visited[i] = 0;

    for(i = 0; i < g.numVex; i++)
    {
        if(!visited[i])
            DFS(g,i);
    }
    cout << endl;
}

class Queue{
    int front;
    int rear;
    int data[2*MAXSIZE];

    public:
      void Init_queue();
      void push_queue(int);
      int pop_queue();
      int Queue_empty();
};

void Queue::Init_queue()
{
    this->front = 0;
    this->rear = 0;
}

void Queue::push_queue(int num)
{
    if((this->rear + 1)%(2*MAXSIZE) == this->front)
    {
        cout << "队列满" << endl;
        return;
    }
    this->data[rear] = num;
    rear = (rear+1)%(2*MAXSIZE);
}

int Queue::pop_queue()
{
    if(rear == front)
    {
        cout << "队列空" << endl;
        return -1;
    }

    int num = data[front];
    front = (front+1)%(2*MAXSIZE);

    return num;
}

int Queue::Queue_empty()
{
    if(rear == front)
    {
        cout << "队列空" << endl;
        return -1;
    }
    else
        return 1;
}

int visited_BFS[MAXSIZE];
void BFS_Graph(MGraph g)
{
    int i;
    for(i = 0; i < g.numVex; i++)
        visited_BFS[i] = 0;

    cout << "The BFS sequence is:" ;

    Queue Q;
    Q.Init_queue();

    for(i = 0; i < g.numVex; i++)
    {
        if(!visited_BFS[i])
        {
            cout << g.vexs[i] << " ";
            visited_BFS[i] = 1;
            Q.push_queue(i);

            int j,c;
            while(Q.Queue_empty() != -1)
            {
                c = Q.pop_queue();
                if(c != -1)
                    for(j = 0; j < g.numVex; j++)
                    {
                        if(!visited_BFS[j] && g.arc[c][j] != INFINITY)
                        {
                            Q.push_queue(j);
                            visited_BFS[j] = 1;
                            cout << g.vexs[j] <<" ";
                        }
                    }
            }
        }
    }
    cout << endl;
}

void Minispantree_prim(MGraph g)
{
    int min;
    int adjvex[MAXSIZE];
    int lowcost[MAXSIZE];

    cout << "The Minispantree_prim is:";
    /*初始化*/
    lowcost[0] = 0;//从顶点0出发，权值为0,将0结点加入最小生成树
    adjvex[0] = 0;

    int i,j,k;
    for(i = 1; i < g.numVex; i++)
    {
        lowcost[i] = g.arc[0][i];
        adjvex[i] = 0;
    }

    for(i = 1; i < g.numVex; i++)
    {
        min = INFINITY;
        k = 0;j = 1;
        while(j < g.numVex)
        {
            if(lowcost[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        //cout << "(" << adjvex[k] << "," << k << ")" ;
        cout << "(" << g.vexs[adjvex[k]] << "," << g.vexs[k] << ")" ;
        lowcost[k] = 0;//加入顶点k

        for(j = 1; j < g.numVex; j++)
        {
            if(lowcost[j] && g.arc[k][j] < lowcost[j])
            {
                lowcost[j] = g.arc[k][j];//修改权值小的边所对应的结点
                adjvex[j] = k;
            }
        }
    }
    cout << endl;

}

/*边集信息数组*/
struct Edge{
    int begin;
    int end;
    int weight;
};

int find(int *p, int n)
{
    while(p[n] > 0)
        n = p[n];
    return n;
}

void print(vector<Edge> e)
{
    auto i = e.begin();
    cout << "边组信息数组：" << endl;
    while(i != e.end())
    {
        cout << "(" <<  (*i).begin << "," << (*i).end << ") " << (*i).weight << endl;
        i++;
    }
}

void transfer(MGraph g,vector<Edge> *e)
{
    int i,j;
    for(i = 0; i < g.numVex; i++)
        for(j = i; j < g.numVex; j++)
        {
            if(g.arc[i][j] != INFINITY)
            {
                Edge *edge = (Edge *)malloc(sizeof(Edge));
                edge->begin = i;
                edge->end = j;
                edge->weight = g.arc[i][j];
                e->push_back(*edge);
            }
        }

    stable_sort(e->begin(),e->end(),[](Edge e1,Edge e2){return e1.weight < e2.weight;});
    print(*e);
}

void Minispantree_kruskal(MGraph g)
{
    vector<Edge> edges;
    int parrent[MAXSIZE];

    /*初始化*/
    transfer(g,&edges);//将邻接矩阵转化成边集信息数组
    int i;
    for(i = 0; i < g.numVex; i++)
        parrent[i] = 0;

    int n,m;
    cout << "The Minispantree_prim is:";
    for(i = 0; i < g.numEdg; i++)
    {
        n = find(parrent,edges[i].begin);
        m = find(parrent,edges[i].end);

        if(n != m)
        {
            parrent[n] = m;
            //cout << "(" << edges[i].begin << "," << edges[i].end << "):" << edges[i].weight << " ";
            cout << "(" << g.vexs[edges[i].begin] << "," << g.vexs[edges[i].end] << "):" << edges[i].weight << " ";
        }
    }
    cout << endl;
}

void print(MGraph g, int *shortest, int *path)
{
    cout << "The Shortestpath_Dijkstral from V0 ,there related prepath is:";
    int i;
    for(i = 0; i < g.numVex; i++)
        cout << g.vexs[path[i]] << " ";
    cout << "Nil" << endl;

    cout << "The Shortestpath_Dijkstral weight is:";
    for(i = 0; i < g.numVex; i++)
        cout << shortest[i] << ", ";
    cout << "Nil" << endl;
}

void Shortestpath_Dijkstral(MGraph g,int v0)
{
    int Path[MAXSIZE];//存储从V0开始最短路径下标
    int Shortest[MAXSIZE];//存储对应顶点最短路径权值
    int finally[MAXSIZE];//存储对应顶点是否已找到最短路径

    /*初始化*/
    int i;
    for(i = 0; i < g.numVex; i++)
    {
        finally[i] = 0;
        Shortest[i] = g.arc[v0][i];
        Path[i] = 0;
    }
    Shortest[v0] = 0;
    finally[v0] = 1;

    int min,j,k;
    for(i = 1; i < g.numVex; i++)
    {
        min = INFINITY;
        for(j = 0; j < g.numVex; j++)//寻找离V0最近的顶点
        {
            if(!finally[j] && min > Shortest[j])
            {
                min = Shortest[j];
                k = j;
            }
        }

        finally[k] = 1;
        for(j = 0; j < g.numVex; j++)//更改当前最短路径值
        {
            if(!finally[j] && (g.arc[k][j] + min < Shortest[j]))
            {
                Shortest[j] = g.arc[k][j] + min;
                Path[j] = k;
            }
        }
    }
    print(g,Shortest,Path);
}

//void print(MGraph g, int **shortest, int **path)
void print(MGraph g, int shortest[][MAXSIZE], int path[][MAXSIZE])
{
    int i,j;
    cout << "\nThe matrix of weight:" << endl;
    for(i = 0; i < g.numVex; i++)
    {
        for(j = 0; j < g.numVex; j++)
            cout << shortest[i][j] << " ";
        cout << endl;
    }

    cout << "\nThe matrix of Path:" << endl;
    for(i = 0; i < g.numVex; i++)
    {
        for(j = 0; j < g.numVex; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
}

void Shortestpath_Floyd(MGraph g)
{
    int i,j,k;
    int Path[MAXSIZE][MAXSIZE];
    int Shortest[MAXSIZE][MAXSIZE];
//    int **Path;
//    int **Shortest;

    /*初始化*/
    for(i = 0; i < g.numVex; i++)
    {
        for(j = 0; j < g.numVex; j++)
        {
            Path[i][j] = j;
            Shortest[i][j] = g.arc[i][j];
        }
        Shortest[i][i] = 0;
    }

    for(k = 0; k < g.numVex; k++)
    {
        for(i = 0; i < g.numVex; i++)
        {
            for(j = 0; j < g.numVex; j++)
            {
                if(Shortest[i][k] + Shortest[k][j] < Shortest[i][j])
                {
                    Shortest[i][j] = Shortest[i][k] + Shortest[k][j];
                    Path[i][j] = Path[i][k];
                }
            }
        }
    }
    print(g,Shortest,Path);

}

int main()
{
    MGraph G;
    AdjGraph G1;

    /*建图*/
    creat_graph(&G,9,15);
    //print_graph(G);

    /*DFS遍历图*/
    DFS_Graph(G);

    /*利用邻接表建图*/
   // creat_Adjgraph(&G1,9,15);

    /*BFS遍历图*/
    BFS_Graph(G);

    /*最小生成树——prim算法*/
    Minispantree_prim(G);

    /*最小生成树——kruskal算法*/
    Minispantree_kruskal(G);

    /*最短路径——Dijkstral*/
    Shortestpath_Dijkstral(G,0);

    /*最短路径——Floyd*/
    Shortestpath_Floyd(G);

    return 0;
}

