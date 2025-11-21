/*******朴素dp*** */
/*

#include<iostream>
using namespace std;
const int N=510;
const int INF=0x3f3f3f3f;

int g[N][N],f[N][N];

void dp(int n)
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            //f[1][1]有点特殊
            if(j==1) f[i][j]=f[i-1][j]+g[i][j];
            else if(j==i) f[i][j]=f[i-1][j-1]+g[i][j];
            else f[i][j]=max(f[i-1][j-1],f[i-1][j])+g[i][j];
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int r;
            scanf("%d",&r);
            g[i][j]=r;
        }
    }

    dp(n);

    int res=-INF;
    for(int j=1;j<=n;j++)
    {
        res=max(res,f[n][j]);
    }

    printf("%d",res);
    return 0;
}

*/


/*********滚动数组***********/
#include<iostream>
using namespace std;
const int N=510;
const int INF=0x3f3f3f3f;

int g[N][N],f[N];

void dp(int n)
{

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            //f[1][1]有点特殊
            if(j==1) f[j]=f[j]+g[i][j];
            else if(j==i) f[j]=f[j-1]+g[i][j];
            else f[j]=max(f[j-1],f[j])+g[i][j];
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int r;
            scanf("%d",&r);
            g[i][j]=r;
        }
    }

    dp(n);

    int res=-INF;
    for(int j=1;j<=n;j++)
    {
        res=max(res,f[j]);
    }

    printf("%d",res);
    return 0;
}