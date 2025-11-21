#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=1.5e5+10;
const int INF=0x3f3f3f3f;
typedef pair<int,int> PII;

int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];

void add_edge(int a,int b,int z)
{
    e[idx]=b;
    w[idx]=z;
    ne[idx]=h[a];
    h[a]=idx++;
}

void dijkstra(int n)
{
    dist[1]=0;//0号不使用
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});//(x,y) x为dist,y为dist_point

    while(heap.size())
    {
        PII p=heap.top();
        heap.pop();
        int distance=p.first,v=p.second;
        if(st[v]) continue;
        st[v]=true;

        for(int i=h[v];i!=-1;i=ne[i])
        {
            int j=e[i];
            int edg=w[i];
            if(dist[j]>distance+edg) 
            {
                dist[j]=distance+edg;
                heap.push({distance+edg,j});
            }
        }
    }


}

int main()
{
    memset(h,-1,sizeof h);
    memset(dist,INF,sizeof dist);
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
    }

    dijkstra(n);

    if(dist[n]>=INF) printf("-1");
    else printf("%d",dist[n]);
    return 0;
}