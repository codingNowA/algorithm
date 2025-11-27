//first try:WA
/*

#include<iostream>
using namespace std;

int get_pow(int p)//计算10的p次方
{
    int res=1;
    while(p)
    {
        res*=10;
        p--;
    }

    return res;
}

int count_i(int n,int x)
{   
    int res=0;
    //逐位处理
    int num=n;
    int r=0;//余数
    int p=0;//记录当前处理到几位
    while(num)
    {
        p++;
        r+=num%10;
        int high_digitals=num/10;
        num/=10;

        //高位:0~high_digitals个数字
        //低位部分：x000~x999,一共10^{p-1}位,这里搞错了，没考虑周全
        //一共(high_digitals+1)*10^{p-1}个x
        res+=(high_digitals+1)*get_pow(p-1);
    }

    return res;
}

int main()
{
    while(1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(!(a|b)) break;
        else if(a>b) swap(a,b);//注意a>b的特殊情况
        
        for(int i=0;i<=9;i++)
        {
            int res=count_i(b,i)-count_i(a-1,i);
            printf("%d ",res);
        }

        printf("\n");
    }

    return 0;
}

*/

//second try:WA
//没有正确处理前导0的情况
/*

#include<iostream>
using namespace std;

int get_pow(int p)//计算10的p次方
{
    int res=1;
    while(p)
    {
        res*=10;
        p--;
    }

    return res;
}

int count_i(int n,int x)
{   
    if(n<=0) return 0;
    int res=0;
    //逐位处理
    int num=n;
    int p=0;//记录当前处理到几位
    int low_digtals=0;
    int high_digitals=0;
    int cur_digital=0;
    while(num)
    {
        p++;
        cur_digital=num%10;
        low_digtals=n%(get_pow(p-1));
        high_digitals=num/10;
        num/=10;

        //高位:0~high_digitals个数字
        //当高位为0~high_digitals-1时
        //res+=(high_digitals-1+1)get_pow(p-1);

        //当高位为high_digitals
        //低位部分：
        //if cur_digtal>x :x000~x999,一共10^{p-1}位
        //所以:res+=10^{p-1}
        //if cur_digtal==x:x000~xC_{1}C_{2}C_{3},low_digitals+1
        //所以:res+=low_digitals+1
        //if cur_digtal<x:0
        
        res+=high_digitals*get_pow(p-1);
        if(cur_digital>x)res+=get_pow(p-1);
        else if(cur_digital==x) res+=low_digtals+1;
    }

    return res;
}

int main()
{
    while(1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(!(a|b)) break;
        else if(a>b) swap(a,b);//注意a>b的特殊情况
        
        for(int i=0;i<=9;i++)
        {
            int res=count_i(b,i)-count_i(a-1,i);
            printf("%d ",res);
        }

        printf("\n");
    }

    return 0;
}

*/

//third try
#include<iostream>
using namespace std;

int get_pow(int p)//计算10的p次方
{
    int res=1;
    while(p)
    {
        res*=10;
        p--;
    }

    return res;
}

int count_i(int n,int x)
{   
    if(n<=0) return 0;
    int res=0;
    //逐位处理
    int num=n;
    int p=0;//记录当前处理到几位
    int low_digtals=0;
    int high_digitals=0;
    int cur_digital=0;
    while(num)
    {
        p++;
        cur_digital=num%10;
        low_digtals=n%(get_pow(p-1));
        high_digitals=num/10;
        num/=10;

        if(x==0)
        {   
            //高位:1~high_digitals个数字
            //当高位为1~high_digitals-1时
            //res+=(high_digitals-1)get_pow(p-1);

            //当高位为high_digitals
            //低位部分：
            //if cur_digtal>x :x000~x999,一共10^{p-1}位
            //所以:res+=10^{p-1}
            //if cur_digtal==x:x000~xC_{1}C_{2}C_{3},low_digitals+1
            //所以:res+=low_digitals+1
            //if cur_digtal<x:0
            if(high_digitals!=0)
            {
                res+=(high_digitals-1)*get_pow(p-1);
                if(cur_digital>x)res+=get_pow(p-1);
                else if(cur_digital==x) res+=low_digtals+1;
            }

        }
        else if(x!=0)
        {   
            //高位:0~high_digitals个数字
            //当高位为0~high_digitals-1时
            //res+=(high_digitals-1+1)get_pow(p-1);

            //当高位为high_digitals
            //低位部分：
            //if cur_digtal>x :x000~x999,一共10^{p-1}位
            //所以:res+=10^{p-1}
            //if cur_digtal==x:x000~xC_{1}C_{2}C_{3},low_digitals+1
            //所以:res+=low_digitals+1
            //if cur_digtal<x:0
            
            res+=high_digitals*get_pow(p-1);
            if(cur_digital>x)res+=get_pow(p-1);
            else if(cur_digital==x) res+=low_digtals+1;
        }
    }

    return res;
}

int main()
{
    while(1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(!(a|b)) break;
        else if(a>b) swap(a,b);//注意a>b的特殊情况
        
        for(int i=0;i<=9;i++)
        {
            int res=count_i(b,i)-count_i(a-1,i);
            printf("%d ",res);
        }

        printf("\n");
    }

    return 0;
}
