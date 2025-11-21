#include<iostream>
using namespace std;
const int N=1e3+10;

int n,m,q;
int M[N][N],b[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
    return;
}


int main()
{
    scanf("%d%d%d",&n,&m,&q);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {
                scanf("%d",&M[i][j]);
                insert(i,j,i,j,M[i][j]);
            }

    while(q--)
    {
        int x1,x2,y1,y2,c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        insert(x1,y1,x2,y2,c);
    }


    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {
                b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            }

     
    for(int i=1;i<=n;i++)
    {   
        if(i!=1) printf("\n");
        for(int j=1;j<=m;j++)
            printf("%d ",b[i][j]);
    }

    return 0;
}