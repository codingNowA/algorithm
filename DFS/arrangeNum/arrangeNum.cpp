#include<iostream>
using namespace std;

int n;
int num[7],path[7];
bool st[7];

void dfs(int u)
{
    if(u>=n)
    {
        for(int i=0;i<n;i++) printf("%d ",path[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!st[i])
        {
            path[u]=num[i];
            st[i]=true;
            dfs(u+1);
            st[i]=false;
        }
        
    }

}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) num[i]=i+1;
    dfs(0);
    return 0;
}