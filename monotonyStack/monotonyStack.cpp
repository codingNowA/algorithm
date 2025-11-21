#include<iostream>
using namespace std;
const int N=1e5+10;

int tt=-1,n=0;
int stk[N];
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        
        while(tt>=0&&stk[tt]>=x) tt--;
        if(tt==-1) printf("-1 ");
        else printf("%d ",stk[tt]);
        stk[++tt]=x;

    }

    return 0;
}