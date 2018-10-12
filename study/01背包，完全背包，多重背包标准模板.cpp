/*
	01背包，完全背包，多重背包模板
	作者：桐小目
	时间：2016/01/28
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100005;
int dp[maxn];
int volume;
void ZeroOneBag(int value,int weight){                         //01背包
	for(int i=volume;i>=weight;i--)
		dp[i]=max(dp[i],dp[i-weight]+value);
}
void CompleteBag(int value,int weight){                        //完全背包
	for(int i=weight;i<=volume;i++)
		dp[i]=max(dp[i],dp[i-weight]+value);
}
void MultipleBag(int value,int weight,int number){             //多重背包（二进制优化）
	if(number*weight>=volume) {  //如果满足此条件可视为完全背包问题解决
		CompleteBag(value,weight);
		return;
	}
	int i=1;
	while(i<=number){            //二进制优化
		ZeroOneBag(i*value,i*weight);
		number-=i;
		i<<=1;
	}
	ZeroOneBag(number*value,number*weight);
}
int main(){                                                  //以下皆为测试，经测试没有出现错误
	int k=0;
	while(true){
	cout<<"--------------------------"<<endl;
	cout<<"输入0，01背包"<<endl<<"输入1，完全背包"<<endl<<"输入2，多重背包"<<endl<<"输入3，结束"<<endl;
	cout<<"--------------------------"<<endl;
	cin>>k;
	if(k==3) break;
	int n,value[maxn],weight[maxn],number[maxn];
	memset(dp,0,sizeof(dp));
	switch(k){
	case 0:
		cout<<"输入物品个数和背包容量"<<endl;
		cin>>n>>volume;
		cout<<"输入物品价值"<<endl;
		for(int i=1;i<=n;i++) 
			cin>>value[i];
		cout<<"输入物品重量"<<endl;
		for(int i=1;i<=n;i++) 
			cin>>weight[i];

		for(int i=1;i<=n;i++)
			ZeroOneBag(value[i],weight[i]);
		cout<<"结果为： "<<dp[volume]<<endl;
	break;
	case 1:
		cout<<"输入物品个数和背包容量"<<endl;
		cin>>n>>volume;
		cout<<"输入物品价值"<<endl;
		for(int i=1;i<=n;i++) 
			cin>>value[i];
		cout<<"输入物品重量"<<endl;
		for(int i=1;i<=n;i++) 
			cin>>weight[i];

		for(int i=1;i<=n;i++)
			CompleteBag(value[i],weight[i]);
		cout<<"结果为： "<<dp[volume]<<endl;
	break;
	case 2:
		cout<<"输入物品种类数和背包容量"<<endl;
		cin>>n>>volume;
		cout<<"输入物品价值"<<endl;
		for(int i=1;i<=n;i++) 
			cin>>value[i];
		cout<<"输入物品重量"<<endl;
		for(int i=1;i<=n;i++) 
			cin>>weight[i];
		cout<<"输入物品个数"<<endl;
		for(int i=1;i<=n;i++) 
			cin>>number[i];

		for(int i=1;i<=n;i++)
			MultipleBag(value[i],weight[i],number[i]);
		cout<<"结果为： "<<dp[volume]<<endl;
	break;
		}
	}
}