#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=1e5+10;

int h[N],kc[N],ck[N];
int cnt,idx;//cnt表示数组现在用到哪里了，idx为代表元素的key（即第几个插入）

void heap_swap(int a,int b)//传入的参数为真实数组下标
{
    swap(h[a],h[b]);
    swap(kc[ck[a]],kc[ck[b]]);
    swap(ck[a],ck[b]);
}

void up(int n)
{
    while(n>>1&&h[n]<h[n/2])
    {
        heap_swap(n,n/2);
        n=n/2;
    }
}
void down(int n)
{
    int t=n;
    while(1)
    {
        int l=2*n,r=2*n+1;
        if(l<=cnt&&h[t]>h[l]) t=l;
        if(r<=cnt&&h[t]>h[r]) t=r;
        if(t==n) break;
        else if(t!=n) heap_swap(n,t),n=t;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[3];
        scanf("%s",op);

        if(op[0]=='I')
        {
            int x;
            scanf("%d",&x);
            h[++cnt]=x;
            idx++;
            ck[cnt]=idx;
            kc[idx]=cnt;
            up(cnt);
        }

        else if(op[0]=='P')
        {
            printf("%d\n",h[1]);
        }

        else if(!strcmp(op,"DM")) 
        {
            heap_swap(1,cnt);
            cnt--;
            down(1);
        }

        else if(!strcmp(op,"D"))
        {
            int k;
            scanf("%d",&k);
            int t=kc[k];
            heap_swap(cnt,t);
            cnt--;
            up(t);
            down(t);
        }

        else if(op[0]=='C')
        {
            int k,x;
            scanf("%d%d",&k,&x);
            int t=kc[k];
            h[t]=x;
            up(t);
            down(t);
        }
    }


    return 0;
}