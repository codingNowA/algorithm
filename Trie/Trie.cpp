#include<iostream>
#include<string.h>
using namespace std;;

const int N=1e5+10;

int son[N][26],cnt[N],idx;
char str[N];

void insert(char* s)
{
    int p=0;
    for(int i=0;i<strlen(s);i++)
    {
        int j=s[i]-'a';
        if(!son[p][j]) son[p][j]=++idx;
        p=son[p][j];
    }
    
    cnt[p]++;
}

int query(char* s)
{
    int p=0;
    for(int i=0;i<strlen(s);i++)
    {
        int j=s[i]-'a';
        if(!son[p][j]) return 0;
        p=son[p][j];
    }

    return cnt[p];
}


int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        char op[2];
        scanf("%s",op);
        scanf("%s",str);

        if(op[0]=='I') insert(str);
        else printf("%d\n",query(str));
    }

    return 0;
}