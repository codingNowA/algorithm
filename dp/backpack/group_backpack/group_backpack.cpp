/*******朴素dp *********/
/*

#include<iostream>
using namespace std;
const int  N=110,V=110;

int v[N][V],w[N][V],s[N];
int f[N][V];

void dp(int g_num,int vol)
{
    for(int i=1;i<=g_num;i++)
    {
        for(int j=0;j<=vol;j++)
        {
            for(int k=0;k<=s[i];k++)
            {
                if(v[i][k]<=j) f[i][j]=max(f[i][j],f[i-1][j-v[i][k]]+w[i][k]);
            }
        }
    }
}

int main()
{
    int g_num,vol;
    scanf("%d%d",&g_num,&vol);

    for(int i=1;i<=g_num;i++)
    {
        int s_i;
        scanf("%d",&s_i);
        s[i]=s_i;
        
        for(int j=1;j<=s_i;j++)
        {
            int v_ij,w_ij;
            scanf("%d%d",&v_ij,&w_ij);
            v[i][j]=v_ij,w[i][j]=w_ij; 
        }
    }

    dp(g_num,vol);

    printf("%d\n",f[g_num][vol]);
    return 0;
}

*/

/*********状态压缩******** */
#include<iostream>
using namespace std;
const int  N=110,V=110;

int v[N][V],w[N][V],s[N];
int f[V];

void dp(int g_num,int vol)
{
    for(int i=1;i<=g_num;i++)
    {
        for(int j=vol;j>=0;j--)
        {
            for(int k=0;k<=s[i];k++)
            {
                if(v[i][k]<=j) f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
            }
        }
    }
}

int main()
{
    int g_num,vol;
    scanf("%d%d",&g_num,&vol);

    for(int i=1;i<=g_num;i++)
    {
        int s_i;
        scanf("%d",&s_i);
        s[i]=s_i;
        
        for(int j=1;j<=s_i;j++)
        {
            int v_ij,w_ij;
            scanf("%d%d",&v_ij,&w_ij);
            v[i][j]=v_ij,w[i][j]=w_ij; 
        }
    }

    dp(g_num,vol);

    printf("%d\n",f[vol]);
    return 0;
}