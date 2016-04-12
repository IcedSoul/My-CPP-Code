#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn=50000;

int main()
{
	int T,Q,count,i,j,j1,m,n,t1;
	int d[maxn],dd[maxn],ddd[maxn],s[maxn];
	char r[maxn];
	cin >> T;
	while(T--)
	{
		count=0;
		t1=j1=0;
		cin >> Q;
		n=0;
		m=0;
			for(int i=0;i<Q;i++)
			{
				cin >> d[i];
				cin >> s[i];
				cin >> r[i];
			}
           for(i=0;i<Q;i++)
           {
           	if(s[i]==0&&r[i]=='i')
           	{
           		dd[j1++]=d[i];
           	    m++;
           	    
           	}
           	if(s[i]==1&&r[i]=='c')	
           	{
                ddd[t1++]=d[i];
           	    n++;
           	}
           }
             for(i=0;i<m;i++)
             {
             	for(j=0;j<n;j++)
             		if(dd[i]<ddd[j])
             			count++;
             }
		cout << count << endl;

	}
	return 0;
}