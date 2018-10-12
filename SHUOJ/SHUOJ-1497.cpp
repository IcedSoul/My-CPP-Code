#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	char a;
	 int s1=0,s2=0,s3=0,s4=0;
      while(scanf("%c",&a)!=EOF){
		if(a!='\n'){
              if((a>='A'&& a<='Z')||(a>='a'&& a<='z'))
                   s1++;
              else if(a>='0'&& a<='9')
                   s2++;
              else if(a==' ')
                   s3++;
              else
                   s4++;
            }
           else{
            cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
            s1=0;s2=0;s3=0;s4=0;
        }
        }
        return 0;
}