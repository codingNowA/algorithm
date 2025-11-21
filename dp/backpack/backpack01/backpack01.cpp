/********朴素dp*******/
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
            if(j<v[i]) f[i][j]=f[i-1][j];
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
        int v_i,w_i;
        scanf("%d%d",&v_i,&w_i);
        v[i]=v_i,w[i]=w_i;
    }

    dp(num,vol);

    printf("%d\n",f[num][vol]);
    return 0;
}

*/

/********滚动数组*******/
#include<iostream>
using namespace std;
const int N=1010,V=1010;

int v[N],w[N];
int f[V];

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
        int v_i,w_i;
        scanf("%d%d",&v_i,&w_i);
        v[i]=v_i,w[i]=w_i;
    }

    dp(num,vol);

    printf("%d\n",f[vol]);
    return 0;
}