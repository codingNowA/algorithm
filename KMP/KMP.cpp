#include<iostream>
using namespace std;
const int N=1e5+10,M=1e6+10;

char P[N],S[M];
int ne[N];

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%s",P+1);//从1开始存，这里不要写错了
    scanf("%d",&m);
    scanf("%s",S+1);

    //求next数组
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&P[j+1]!=P[i]) j=ne[j];
        //若j==0或j+1匹配成功

        // if(P[j+1]==P[i]) j++,ne[i]=j;
        // else if(!j) ne[i]=j;
        if(P[j+1]==P[i]) j++;
        ne[i]=j;
    }

    for(int i=1,j=0;i<=m;i++)
    {
        while(j&&P[j+1]!=S[i]) j=ne[j];
        if(P[j+1]==S[i]) j++;
        if(j==n)
        {
            int ans=(i-n+1)-1;
            printf("%d ",ans);
        }
    }
    return 0;
}