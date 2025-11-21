#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;

int h[N],ne[2*N],e[2*N];
int idx=1,n,ANS;
bool st[N];

void add_edge(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dfs(int u)
{
    int sum=1,ans=0;
    st[u]=true;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int res=0;
        int p=e[i];
        if(!st[p]) res=dfs(p);
        sum+=res;
        ans=max(ans,res);
    }

    ans=max(ans,n-sum);
    ANS=min(ANS,ans);
    return sum;
}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);
    }

    ANS=n;
    dfs(1);

    printf("%d",ANS);
    return 0;
}
