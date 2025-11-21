/**********first try********/
/*
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10,M=2*N;

int color[N];//0没染，1，2两种颜色
int h[N],e[M],ne[M],idx;

void add_edge(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool Bipartite(int n,int m)
{
    //因为不知道连通情况，所以要尝试从任意一个顶点开始
    for(int i=1;i<=n;i++)
    {
        for(int j=h[i];j!=-1;j=ne[j])
        {
            int b=e[j];
            if(j==h[i]&&!color[i])
            {
                color[i]=1;
                //这就是错误的地方，当这个点连接边本来就有
                //颜色时，固定染色为1，会引发错误
                //应该对每个染了色的点，也作为源点去染色下其他点
            }

            if(!color[b]) color[b]=3-color[i];
            else if(color[b]==3-color[i]) continue;
            else
            {
                return false;//染色冲突，返回
            }
        }
    }

    return true;
}

int main()
{   
    memset(h,-1,sizeof h);
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }

    bool res=Bipartite(n,m);

    if(res) printf("Yes\n");
    else printf("No\n");
    return 0;
}
*/



/*******AC code*****/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+10,M=2*N;

int color[N];//0没染，1，2两种颜色
int h[N],e[M],ne[M],idx;

void add_edge(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool Bipartite(int n,int m)
{   
    queue<int> q;
    
    //因为不知道连通情况，所以要尝试从任意一个顶点开始
    for(int i=1;i<=n;i++)
    {
        if(color[i]) continue;  
        q.push(i);
        color[i]=1;

        while(q.size())
        {
            int u=q.front();
            q.pop();

            for(int j=h[u];j!=-1;j=ne[j])
            {
                int b=e[j];

                if(!color[b])
                {
                    color[b]=3-color[u];
                    q.push(b);
                }
                else if(color[b]==3-color[u]) continue;
                else
                {
                    return false;//染色冲突，返回
                }
            }
        }
    }

    return true;
}

int main()
{   
    memset(h,-1,sizeof h);
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }

    bool res=Bipartite(n,m);

    if(res) printf("Yes\n");
    else printf("No\n");
    return 0;
}