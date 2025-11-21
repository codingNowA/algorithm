#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;
const int N=1e5+10,M=3e5+10;

int n,m;
int a[M],s[M];//存前缀and前缀和
vector<PII> all,query;//all存原始散列点数据
vector<int> d_sub;//d_sub存散列点位置

bool cmp(int a,int b)
{
    return a<b;
}

int bsearch(int l,int r,int x)
{
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(x<=d_sub[mid]) r=mid;
        else l=mid+1;
    }
    return l+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x,c;
        scanf("%d%d",&x,&c);
        all.push_back({x,c});
        d_sub.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        query.push_back({l,r});
        d_sub.push_back(l);
        d_sub.push_back(r);
    }

    unique(d_sub.begin(),d_sub.end());
    sort(d_sub.begin(),d_sub.end(),cmp);

    for(int i=0;i<all.size();i++)
    {
        int x=all[i].first;
        a[bsearch(0,d_sub.size()-1,x)]+=all[i].second;
    }

    for(int i=1;i<=d_sub.size();i++) s[i]=s[i-1]+a[i];

    for(int i=0;i<query.size();i++)
    {
        int l=bsearch(0,d_sub.size(),query[i].first),r=bsearch(0,d_sub.size(),query[i].second);
        printf("%d\n",s[r]-s[l-1]);
    }

    return 0;
}