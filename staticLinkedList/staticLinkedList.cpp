#include<iostream>
using namespace std;
const int N=1e5+10;

int m;
int val[N],ne[N];
int head,idx;
void init()
{
    head=-1;
    idx=0;
}

void add_to_head(int x)
{
    val[idx]=x;
    ne[idx]=head;
    head=idx++;
}

void del_k(int k)
{
    if(k==-1)
    {
        head=ne[head];
        return;
    }
    ne[k]=ne[ne[k]];
}

void insert_k(int k,int x)
{
    val[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
int main()
{
    init();
    scanf("%d",&m);
    getchar();
    while(m--)
    {
        char op;
        scanf("%c",&op);

        if(op=='H')
        {
            int x;
            scanf("%d",&x);
            getchar();
            add_to_head(x);
        }

        else if(op=='D')
        {
            int k;
            scanf("%d",&k);
            getchar();
            del_k(k-1);
        }

        else if(op=='I')
        {
            int k,x;
            scanf("%d%d",&k,&x);
            getchar();
            insert_k(k-1,x);
        }
    }

    for(int i=head;i!=-1;i=ne[i]) printf("%d ",val[i]);

    return 0;
}