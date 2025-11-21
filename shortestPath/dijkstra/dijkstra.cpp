#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
const int inf=0x3f3f3f3f;

int dist[N],g[N][N];
bool st[N];

void dijkstra(int n)
{
    dist[1]=0;//0号位置不用
    st[1]=true;
    int cnt=n;
    if(n==1) return;

    while(cnt--)
    {
        int t=inf;
        int min_point=0;
        for(int i=2;i<=n;i++)
        {
            if(dist[i]<dist[min_point]&&!st[i]) min_point=i;
        }
        
        st[min_point]=true;

        for(int i=2;i<=n;i++)
        {
            if(dist[i]>dist[min_point]+g[min_point][i]) 
                dist[i]=dist[min_point]+g[min_point][i];
        }
    }
}   


int main()
{
    memset(g,inf,sizeof(g));
    memset(dist,inf,sizeof(dist));
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y,z;  
        scanf("%d%d%d",&x,&y,&z);
        if(x==y) g[x][y]=0;
        g[x][y]=min(g[x][y],z);
    }
    
    for(int i=1;i<=n;i++) dist[i]=g[1][i];

    dijkstra(n);

    if(dist[n]>=inf) printf("-1");
    else printf("%d",dist[n]);
    return 0;
}

/*
#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
const int inf=0x3f3f3f3f;

int dist[N],g[N][N];

void dijkstra(int n)
{
    dist[1]=0;//0号位置不用
    int cnt=n;
    if(n==1) return;

    while(cnt--)
    {
        int t=inf;
        int min_point=0;
        for(int i=2;i<=n;i++)
        {
            if(g[1][i]<g[1][min_point]) min_point=i;
        }

        dist[min_point]=g[1][min_point];

        for(int i=2;i<=n;i++)
        {
            if(dist[i]>g[1][min_point]+g[min_point][i]) 
                dist[i]=g[1][min_point]+g[min_point][i];
        }
    }
}   


int main()
{
    memset(g,inf,sizeof(g));
    memset(dist,inf,sizeof(dist));
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y,z;  
        scanf("%d%d%d",&x,&y,&z);
        if(x==y) g[x][y]=0;
        g[x][y]=min(g[x][y],z);
    }

    dijkstra(n);

    printf("%d",dist[n]);
    return 0;
}
 

*/