#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+10;
const int INF=0x3f3f3f3f;

int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];

void add_edge(int x,int y,int z)
{
    e[idx]=y;
    w[idx]=z;
    ne[idx]=h[x];
    h[x]=idx++;
}

void spfa()
{
    dist[1]=0;
    queue<int> q;
    q.push(1);
    st[1]=true;

    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int z=w[i];
            int y=e[i];

            if(dist[y]>dist[t]+z)
            {
                dist[y]=dist[t]+z;
                if(!st[y])
                {
                    q.push(y);
                    st[y]=true;
                }
            }
        }
    }
}

int main()
{
    memset(h,-1,sizeof h);
    memset(dist,0x3f,sizeof dist);
    int n,m,k;
    scanf("%d%d",&n,&m); 

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
    }

    spfa();

    if(dist[n]>INF/2) printf("impossible\n");
    else printf("%d\n",dist[n]);    
    return 0;
}