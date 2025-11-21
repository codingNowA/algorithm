#include<iostream>
using namespace std;
const int N=110,V=110;

int v[N],w[N],s[N];
int f[N][V];

void dp(int num,int vol)
{
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<=vol;j++)
        {
            for(int k=0;k*v[i]<=j&&k<=s[i];k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }

            /*
          f[i][j]=max(f[i-1][j],f[i-1][j-v]+w,f[i-1][j-2v]+2w....f[i-1][j-sv]+sw);
specially f[i][j-v]=max(        f[i-1][j-v]  ,f[i-1][j-2v]+w.....f[i-1][j-sv]+(s-1)w,f[i-1][j-(s+1)v]+sw  );
         ? 
          f[i][j]=max(f[i-1][j],f[i-1][j-v]+w,f[i-1][j-2v]+2w....f[i-1][j-tv]+tw);
specially f[i][j-v]=max(        f[i-1][j-v]  ,f[i-1][j-2v]+w.....f[i-1][j-tv]+(t-1)w );


注意：这里的t被体积和s[i]同时限制,所以不能像完全背包问题那样直接简化状态

which t<s[i]&&tv<j  
------>
  f[i][j]=max(f[i-1][j],f[i][j-v]+w) is unreasonable
            */
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
        v[i]=v_i,w[i]=w_i,s[i]=s_i;
    }

    dp(num,vol);

    printf("%d",f[num][vol]);
    return 0;
}