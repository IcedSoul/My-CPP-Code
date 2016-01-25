#include<iostream>
#include<algorithm>
#define maxn 1005
#define maxn2 1000005
using namespace std;
struct S
{
    int deadLine=0;
    int scores=0;
};
int cmp(S a,S b){
    if(a.deadLine!=b.deadLine) return a.deadLine<b.deadLine;
    else return a.scores>b.scores;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        S homework[maxn];
        int mark[maxn];
        for (int i = 0; i < 1005; ++i)
        {
        	mark[i]=-1;
        }
        for(int i=0;i<n;i++){
            cin>>homework[i].deadLine;
        }
        for(int i=0;i<n;i++)
            cin>>homework[i].scores;
        sort(homework,homework+n,cmp);
        for(int i=0;i<n;i++){
            if(mark[homework[i].deadLine]==-1)
                mark[homework[i].deadLine]=homework[i].scores;
            else{
                int min=maxn2,k=-2;
                for(int j=homework[i].deadLine;j>0;j--){
                    if(mark[j]<min){
                        min=mark[j];
                        k=j;
                    }
                }
                if(min==-1){
                    mark[k]=homework[i].scores;}
                else{
                    if(min<homework[i].scores){
                        ans+=mark[k];
                        mark[k]=homework[i].scores;
                    }
                    else
                        ans+=homework[i].scores;
                }
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}