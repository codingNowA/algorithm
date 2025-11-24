/*first try:WA*/
/*

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=15;

int cnt=0,f[N][N];
vector<char*> S; 

bool dp(char* a,char* b,int n,int m,int max_num)
{
    memset(f,0,sizeof f);//清0
    for(int i=0;i<=n;i++) f[i][0]=i;
    for(int j=0;j<=m;j++) f[0][j]=j;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {   
            if(f[i][j]>max_num) return false;
            //错在这里，逻辑上这样剪枝不总是正确

            f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
            else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
        }
    }

    return true;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    char str[N];
    for(int i=0;i<n;i++)
    {
        scanf("%s",str+1);//从1开始
        S.push_back(str);
        getchar();
    }
    
    for(int i=0;i<m;i++)
    {
        int max_num;
        scanf("%s",str+1);
        scanf("%d",&max_num);
        getchar();
        for(int k=0;k<n;k++)
        {
            bool res=dp(S[k],str,strlen(S[k]),strlen(str),max_num);
            if(res) cnt++;
        }

        printf("%d\n",cnt);
        cnt=0;
    }

    return 0;
}


*/


/********second try:AC***** */
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=15;

int cnt=0,f[N][N];
vector<char*> S; 

int dp(char* a,char* b,int n,int m)
{
    memset(f,0,sizeof f);//清0
    for(int i=0;i<=n;i++) f[i][0]=i;
    for(int j=0;j<=m;j++) f[0][j]=j;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {   
            f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
            else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
            
        }
    }

    return f[n][m];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
    {
        char* str=new char[N];
        scanf("%s",str+1);//从1开始
        S.push_back(str);
        getchar();
    }
    
    for(int i=0;i<m;i++)
    {
        int max_num;
        char* str=new char[N];
        scanf("%s",str+1);
        scanf("%d",&max_num);
        getchar();
        for(int k=0;k<n;k++)
        {
            int res=dp(S[k],str,strlen(S[k]+1),strlen(str+1));
            if(res<=max_num) cnt++;
        }

        printf("%d\n",cnt);
        cnt=0;
    }

    return 0;
}