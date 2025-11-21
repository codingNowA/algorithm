#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=510,M=10010;
const int INF=0x3f3f3f3f;
int dist[N],last[N];

class Edge
{
public:
    int x;
    int y;
    int z;
}edges[M];

void bellman_ford(int n,int m,int k)
{
    dist[1]=0;//点从1号开始

    for(int i=0;i<k;i++)
    {
        memcpy(last,dist,sizeof dist);
        for(int j=0;j<m;j++)
        {
            int x=edges[j].x,y=edges[j].y,z=edges[j].z;
            if(dist[y]>last[x]+z) dist[y]=last[x]+z;
        }
    }
}

int main()
{
    memset(dist,0x3f,sizeof dist);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<m;i++)//边从0号开始
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edges[i].x=x,edges[i].y=y,edges[i].z=z;
    }

    bellman_ford(n,m,k);

    if(dist[n]>INF/2) printf("impossible\n");
    else printf("%d\n",dist[n]);
    return 0;
}