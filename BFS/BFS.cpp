#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N=110;
typedef pair<int,int> PII;

int g[N][N],f[N][N];
queue<PII> q;

int main()
{
    memset(f,-1,sizeof f);
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);

    PII pos={1,1};
    q.push(pos);
    f[1][1]=0;

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    while(!q.empty())
    {
        pos=q.front();
        for(int i=0;i<4;i++)
        {
            int x=pos.first+dx[i];
            int y=pos.second+dy[i];

            if(x>=1&&x<=n&&y>=1&&y<=m&&g[x][y]==0&&f[x][y]==-1)
            {
                f[x][y]=f[pos.first][pos.second]+1;
                q.push({x,y});
            }
        }

        q.pop();
    }

    if(f[n][m]!=-1) printf("%d",f[n][m]);
    return 0;
}