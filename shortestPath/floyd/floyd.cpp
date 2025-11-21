#include<iostream>
#include<algorithm>
using namespace std;
const int N=210,INF=1e9;

int d[N][N];

void floyd(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            d[i][j]=INF;
            if(i==j) d[i][j]=0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[x][y]=min(d[x][y],z);
    }

    floyd(n);

    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(d[x][y]>INF/2) printf("impossible\n");
        else printf("%d\n",d[x][y]);
    }
    return 0;
}