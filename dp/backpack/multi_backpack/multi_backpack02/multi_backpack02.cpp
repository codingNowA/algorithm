/********first try******* */
/***********MLE********* */
/*

#include<iostream>
using namespace std;
const int N=1010*11,V=2010;//log2000约为11

int v[N],w[N],cnt;
int f[N][V];

void binary_piles(int vi,int wi,int si)
{
    int k=1;
    while(k<=si)
    {
        cnt++;
        v[cnt]=k*vi;
        w[cnt]=k*wi;
        si-=k;
        k*=2;
    }

    if(si>0)
    {
        v[++cnt]=si*vi;
        w[cnt]=si*wi;
    }
}

void dp(int num,int vol)
{
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<=vol;j++)
        {
            if(v[i]>j) f[i][j]=f[i-1][j];
            else f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
        }
    }
}

int main()
{
    int num,vol;
    scanf("%d%d",&num,&vol);
    for(int i=1;i<=num;i++)
    {
        int v_i,w_i,s_i;
        scanf("%d%d%d",&v_i,&w_i,&s_i);
        binary_piles(v_i,w_i,s_i);
    }

    num=cnt;

    dp(num,vol);

    printf("%d",f[num][vol]);
    return 0;
}

*/


/*******second try  AC***** */
/*******滚动数组* */
#include<iostream>
using namespace std;
const int N=1010*11,V=2010;//log2000约为11

int v[N],w[N],cnt;
int f[V];

void binary_piles(int vi,int wi,int si)
{
    int k=1;
    while(k<=si)
    {
        cnt++;
        v[cnt]=k*vi;
        w[cnt]=k*wi;
        si-=k;
        k*=2;
    }

    if(si>0)
    {
        v[++cnt]=si*vi;
        w[cnt]=si*wi;
    }
}

void dp(int num,int vol)
{
    for(int i=1;i<=num;i++)
    {
        for(int j=vol;j>=v[i];j--)
        {
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
        int v_i,w_i,s_i;
        scanf("%d%d%d",&v_i,&w_i,&s_i);
        binary_piles(v_i,w_i,s_i);
    }

    num=cnt;

    dp(num,vol);

    printf("%d",f[vol]);
    return 0;
}