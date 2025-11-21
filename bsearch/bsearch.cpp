#include<iostream>
using namespace std;
const int N=1e5+10;

int n,q;
int a[N];

int bsearch_1(int l,int r,int x)
{
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(x<=a[mid]) r=mid;
        else l=mid+1;
    }
    return l;
}

int bsearch_2(int l,int r,int x)
{
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(x>=a[mid]) l=mid;
        else r=mid-1;
    }
    return l;
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(q--)
    {
        int k;
        scanf("%d",&k);
        
        int l=bsearch_1(0,n-1,k);
        int r=bsearch_2(0,n-1,k);

        if(a[l]==k) printf("%d %d\n",l,r);
        else printf("-1 -1\n");
    }

    return 0;
}