#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10,M=2e5+10;

int p[N];//并查集


class Edge
{
public:
    int x,y,z;

public:
    bool operator<(const Edge& other)const
    {
        return this->z < other.z;
    }
}edges[M];//无向边 

int find(int x)
{
    if(p[x]==x) return x;
    p[x]=find(p[x]);
    return p[x];
}


bool kruskal(int n,int m,int &res)
{
    sort(edges,edges+m);
    for(int i=1;i<=n;i++) p[i]=i;

    int cnt=0;//边的计数器
    for(int i=0;i<m;i++)
    {   
        Edge t=edges[i];
        int x=t.x,y=t.y,z=t.z;
        int a=find(x),b=find(y);
        if(a!=b)
        {
            res+=z;
            cnt++;
            p[a]=b;
        }           
    }

    return cnt==n-1;
}   

int main()
{   
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edges[i]={x,y,z};
    }
    
    int res=0;
    bool flag=kruskal(n,m,res);

    if(!flag) printf("impossible\n");
    else printf("%d",res);    
    return 0;
}