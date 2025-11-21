/*************spfa**************/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=2010,M=10010;
const int INF=0x3f3f3f3f;

int h[N],e[M],ne[M],w[M],idx;
int dist[N],cnt[N];
bool st[N];

void add_edge(int x,int y,int z)
{
    e[idx]=y;
    w[idx]=z;
    ne[idx]=h[x];
    h[x]=idx++;
}

bool spfa(int n)
{
    dist[1]=0;
    queue<int> q;
    
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        st[i]=true;
        cnt[i]=0;
    }

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
                cnt[y]=cnt[t]+1;
                if(cnt[y]>=n) return true;

                if(!st[y])
                {
                    q.push(y);
                    st[y]=true;
                }
            }
        }
    }

    return false;
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

    bool res=spfa(n);

    if(res) printf("Yes\n");
    else printf("No\n");    
    return 0;
}


