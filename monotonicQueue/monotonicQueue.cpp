/*
#include<iostream>
using namespace std;
const int N=1e6+10;

int a[N],q[N];//a存储输入数组，q为存储关键值的队列
int hh=0,tt=-1;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    //找最小值
    for(int i=0;i<n;i++)
    {
        if(i-hh+1<=k)
        {
            if(tt==-1) q[++tt]=a[i];
            else if(q[tt]>a[i]) q[tt]=a[i];
        }
        else
        {   
            if(q[tt]<=a[i]) q[++tt]=a[i];
            while(tt>=hh&&q[tt]>a[i])
            {
                q[tt]=a[i];
                if(tt>=hh) tt--;//注意特判tt
            }
            //出来之后a[i]在队尾
            if(i-hh+1>k) hh++;
            printf("%d ",q[hh]);
        }
    }

    hh=0,tt=-1;//清空队列
    printf("\n");

    //找最大值
    for(int i=0;i<n;i++)
    {
        if(i-hh+1<=k)
        {
            if(tt==-1) q[++tt]=a[i];
            else if(q[tt]<a[i]) q[tt]=a[i];
        }
        else
        {
            if(q[tt]>=a[i]) q[++tt]=a[i];
            while(tt>=hh&&q[tt]<a[i])
            {
                q[tt]=a[i];
                if(tt>=hh) tt--;
            }
            //出来之后a[i]在队尾
            if(i-hh+1>k) hh++;
            printf("%d ",q[hh]);
        }
    }
    
}

这里的单调队列应该存下标，我搞错了，真服了
*/


#include<iostream>
using namespace std;
const int N=1e6+10;

int a[N],q[N];//a存储输入数组，q为存储关键值的下标的队列
int hh=0,tt=-1;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    //找最小值
    for(int i=0;i<n;i++)
    {
        if(i-hh+1<=k)
        {
            if(tt==-1) q[++tt]=a[i];
            else if(q[tt]>a[i]) q[tt]=a[i];
        }
        else
        {   
            if(q[tt]<=a[i]) q[++tt]=a[i];
            while(tt>=hh&&q[tt]>a[i])
            {
                q[tt]=a[i];
                if(tt>=hh) tt--;//注意特判tt
            }
            //出来之后a[i]在队尾
            if(i-hh+1>k) hh++;
            printf("%d ",q[hh]);
        }
    }

    hh=0,tt=-1;//清空队列
    printf("\n");

    //找最大值
    for(int i=0;i<n;i++)
    {
        if(i-hh+1<=k)
        {
            if(tt==-1) q[++tt]=a[i];
            else if(q[tt]<a[i]) q[tt]=a[i];
        }
        else
        {
            if(q[tt]>=a[i]) q[++tt]=a[i];
            while(tt>=hh&&q[tt]<a[i])
            {
                q[tt]=a[i];
                if(tt>=hh) tt--;
            }
            //出来之后a[i]在队尾
            if(i-hh+1>k) hh++;
            printf("%d ",q[hh]);
        }
    }
    
}