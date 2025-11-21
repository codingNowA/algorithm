#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10,molnum=1e5;

int h[N],e[N],ne[N];
int idx;

void insert(int x)
{
    int k=(x%molnum+molnum)%molnum;
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}

bool query(int x)
{
    int k=(x%molnum+molnum)%molnum;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x) return true;
    }

    return false;
}
int main()
{
    memset(h,-1,sizeof(h));
    int n;
    scanf("%d",&n);

    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        if(!strcmp(op,"I")) insert(x);
        else printf("%s",(query(x)?"Yes\n":"No\n"));
    }
    return 0;
}