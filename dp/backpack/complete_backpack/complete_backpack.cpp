/*************朴素dp********* */
/*

#include<iostream>
using namespace std;
const int N=1010,V=1010;

int v[N],w[N];
int f[N][V];

void dp(int num,int vol)
{
    
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<=vol;j++)
        {
            for(int k=0;k*v[i]<=j;k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);

            }
        }
    }
}

int main()
{
    int num,vol;
    scanf("%d%d",&num,&vol);

    for(int i=1;i<=num;i++)
    {
        int v_i,w_i;
        scanf("%d%d",&v_i,&w_i);
        v[i]=v_i,w[i]=w_i;
    }

    dp(num,vol);

    printf("%d",f[num][vol]);
    return 0;
}

*/

/***********滚动数组********* */
#include<iostream>
using namespace std;
const int N=1010,V=1010;

int v[N],w[N];
int f[V];

void dp(int num,int vol)
{
    
    for(int i=1;i<=num;i++)
    {
        for(int j=v[i];j<=vol;j++)
        {
            //second try 这里即使用了滚动数组，还是TLE了
            /*
            for(int k=0;k*v[i]<=j;k++)
            {
                f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
            }
            */

            //analyze
            /*
            f[i][j]=max(f[i][j],f[i-1][j-k*v[i]+k*w[i]])
            which EQ
            f[i][j]=max(f[i-1][j],f[i-1][j-v]+w,......f[i-1][j-kv]+kw)
            注意到
            f[i][j-v]=max(       ,f[i-1][j-v],........f[i-1][j-kv]+(k-1)w )  

            所以
            f[i][j]=max(f[i-1][j],f[i][j-v]+w)

            --->ac code
            if(j<v) f[i][j]=f[i-1][j];
            else  f[i][j]=max(f[i-1][j],f[i][j-v]+w)

            */
           f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
}

int main()
{
    int num,vol;
    scanf("%d%d",&num,&vol);

    for(int i=1;i<=num;i++)
    {
        int v_i,w_i;
        scanf("%d%d",&v_i,&w_i);
        v[i]=v_i,w[i]=w_i;
    }

    dp(num,vol);

    printf("%d",f[vol]);
    return 0;
}