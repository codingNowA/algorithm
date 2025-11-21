#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N=1e5+10;

bool st[N];
int d[N],h[N],e[N],ne[N];
int idx;

void add_edge(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int main()
{
    memset(h,-1,sizeof h);
    memset(d,-1,sizeof d);
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a,b);
    }

    queue<int> q;
    q.push(1);
    d[1]=0;
    st[1]=true;
    while(!q.empty())
    {
        int p=q.front();
        for(int i=h[p];i!=-1;i=ne[i])
        {
            int des=e[i];
            if(!st[des])
            {
                st[des]=true;
                d[des]=d[p]+1;
                q.push(des);
            }
        }

        q.pop();
    }

    printf("%d",d[n]);
    return 0;
}