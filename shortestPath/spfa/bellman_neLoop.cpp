#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2010,M=10010;
int dist[N];//没有使用备份数组也可以检测负环

class Edge
{
public:
    int x,y,z;
}edges[M];

bool bellman(int n,int m)
{
    dist[1]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x,y,z;
            x=edges[j].x,y=edges[j].y, z=edges[j].z;

            if(dist[y]>dist[x]+z)
            {   
                if(i==n) return true;
                dist[y]=dist[x]+z;   
            }
        }
    }

    return false;
}

int main()
{
    memset(dist,0x3f,sizeof dist);
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edges[i]={x,y,z};
    }

    if(bellman(n,m)) printf("Yes");
    else printf("No");
    return 0;
}