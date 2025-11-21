#include<iostream>
using namespace std;
const int N=1010;

int f[N][N];
char A[N],B[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    scanf("%s",A+1);
    getchar();
    scanf("%s",B+1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i]==B[j]) f[i][j]=f[i-1][j-1]+1;
            else
                f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }

    printf("%d\n",f[n][m]);
    return 0;
}