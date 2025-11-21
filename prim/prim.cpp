/*****TLE,邻接表没有邻接矩阵快****/
/*
#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=510,M=1e5+10;

int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];

void add_edge(int u,int v,int z)
{
    e[idx]=v;
    w[idx]=z;
    ne[idx]=h[u];
    h[u]=idx++;
}

int prim(int n,int m)
{
    memset(dist,0x3f,sizeof dist);

    dist[1]=0;
    int res=0;
    
    for(int i=1;i<=n;i++)//n轮选点
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[j]<dist[t])) t=j;
        }

        if(dist[t]==INF) return INF;
        st[t]=true;
        res+=dist[t];

        for(int j=h[t];j!=-1;j=ne[j])
        {
            int v=e[j];
            int z=w[j];
            if(!st[v]&&dist[v]>z) dist[v]=z; 
        } 

    }


    return res;
}

int main()
{   
    memset(h,-1,sizeof h);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,z;
        scanf("%d%d%d",&u,&v,&z);
        if(u==v) continue;
        add_edge(u,v,z);
        add_edge(v,u,z);
    }

    int res=prim(n,m);

    if(res>INF/2) printf("impossible\n");
    else printf("%d",res);
    return 0;
}

*/


/********堆优化还是过不了，没有邻接矩阵快********/
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=510,M=1e5+10;
typedef pair<int,int> PII;

int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];

void add_edge(int u,int v,int z)
{
    e[idx]=v;
    w[idx]=z;
    ne[idx]=h[u];
    h[u]=idx++;
}

int prim(int n,int m)
{
    memset(dist,0x3f,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>> q;
    dist[1]=0;
    int res=0;
    int cnt=0;

    q.push({dist[1],1});
    
    while(q.size())//n轮选点
    {   
        if(cnt==n) break;

        PII t=q.top();
        q.pop();
        int distance=t.first,poi=t.second;

        if(st[poi]) continue;
        if(distance==INF) return INF;

        st[poi]=true;
        res+=distance;
        cnt++;

        for(int j=h[poi];j!=-1;j=ne[j])
        {
            int v=e[j];
            int z=w[j];
            if(!st[v]&&dist[v]>z) dist[v]=z;
            q.push({dist[v],v}); 
        } 

    }


    return res;
}

int main()
{   
    memset(h,-1,sizeof h);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,z;
        scanf("%d%d%d",&u,&v,&z);
        if(u==v) continue;
        add_edge(u,v,z);
        add_edge(v,u,z);
    }

    int res=prim(n,m);

    if(res>INF/2) printf("impossible\n");
    else printf("%d",res);
    return 0;
}