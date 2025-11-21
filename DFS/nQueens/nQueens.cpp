#include<iostream>
using namespace std;
const int N=11;

int ans[N][N];
int col[N],dig[2*N],cdig[2*N];
int n;

void dfs(int u)//u代表当前dfs到的层数
{
    if(u>n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%c",(ans[i][j]==1)?'Q':'.');
            }
            printf("\n");
        }

        printf("\n");
        return;
    }

    for(int j=1;j<=n;j++)
    {
        if(!col[j]&&!dig[j-u+n]&&!cdig[j+u])
        {
            ans[u][j]=1;
            col[j]=true,dig[j-u+n]=true,cdig[j+u]=true;
            dfs(u+1);
            ans[u][j]=0;
            col[j]=false,dig[j-u+n]=false,cdig[j+u]=false;
        }

    }
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}