#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 10001
int f[MAX];
int r[MAX];
int indegree[MAX];
int visit[MAX];
vector<int> hash[MAX],Qes[MAX];
int ancestor[MAX];

void init(int n)
{
   for(int i=1;i<=n;i++)
    {
        r[i]=1;
        f[i]=i;
        indegree[i]=0;
        visit[i]=0;
        ancestor[i]=0;
        hash[i].clear();
        Qes[i].clear();
    }
}


int find(int n)
{
   if(f[n]==n)
       return n;
   else
       f[n]=find(f[n]);
  return f[n];
 }//查找函数，并压缩路径


int Union(int x,int y)
{
   	int a=find(x);
    int b=find(y);
    if(a==b)
        return 0;
    else if(r[a]<=r[b])
    {
        f[a]=b;
        r[b]+=r[a];
     }
    else
    {
       f[b]=a;
       r[a]+=r[b];
    }
    return 1;
    
 }//合并函数，如果属于同一分支则返回0，成功合并返回1

void LCA(int u)
{
    ancestor[u]=u;
    int i,size = hash[u].size();
    for(i=0;i<size;i++)
    {
       LCA(hash[u][i]);
        Union(u,hash[u][i]);
        ancestor[find(u)]=u;
    }
    visit[u]=1;
    size = Qes[u].size();
    for(i=0;i<size;i++)
    {
       if(visit[Qes[u][i]]==1)
       {
           printf("%d\n",ancestor[find(Qes[u][i])]);
           return;
        }
     }
 }

int main()
{
    int testcase;
    int n;
    int i,j;
    scanf("%d",&testcase);
    for(i=1;i<=testcase;i++)
    {
        scanf("%d",&n);
        init(n);
        int s,t;
        for(j=1;j<=n-1;j++)
        {

            scanf("%d%d",&s,&t);
            hash[s].push_back(t);
            indegree[t]++;
         }
        scanf("%d%d",&s,&t);
        Qes[s].push_back(t);
        Qes[t].push_back(s);
        for(j=1;j<=n;j++)
        {
            if(indegree[j]==0)
           {
                LCA(j);
               break;
             }
        }
     }
    return 0;
}