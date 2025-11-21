#include<iostream>
using namespace std;
const int N=1010;

int a[N],f[N];
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            if(a[i]>a[j]) f[i]=max(f[i],f[j]+1);            
        }

    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,f[i]+1);//初始化全为0，但是最短都是1

    printf("%d",res);
    return 0;
}