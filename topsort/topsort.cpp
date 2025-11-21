#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+10;

int h[N],ne[N],e[N],in[N],q[N];
int idx;

void add_edge(int x,int y)
{
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}

int main()
{
    memset(h,-1,sizeof h);
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        in[y]++;
    }

    int tt=-1,hh=0;
    
    //初始化队列，存入度为0的点
    for(int i =1;i<=n;i++) if(in[i]==0) q[++tt]=i;

    while(tt>=hh)
    {
        int t=q[hh];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            in[j]--;
            if(in[j]==0) q[++tt]=j;
        }

        hh++;

    }

    bool flag=true;
    for(int i=1;i<=n;i++) if(in[i]!=0) flag=false;
    
    if(flag==false) printf("-1\n");
    else
    {
        //这里没想到,q之前的元素其实没有被删除
        for(int i=0;i<n;i++) printf("%d ",q[i]);
    }
    return 0;
}