#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int i,n,a,b;
	int beg,t,ck;
	int x[1000];
	while(scanf("%d%d%d",&a,&b,&n)!=EOF){
		getchar();
		ck=0;
		x[1]=1;x[2]=1;
		if(a==0&&b==0&&n==0) break;
		for(i=3;i<=51;i++) {
		x[i]=(a*x[i-1]+b*x[i-2])%7;
		for(int j=2;j<i;j++)  
            {  if(x[j]==x[i] && x[j-1]==x[i-1])  
                {   t = i-j;  
                    beg = j-1;  
                    ck = 1;  
                    break;  
                }  
            }  
            if(ck)  break; } 
	   if(n<beg)  
            cout<<x[n]<<endl;  
        else  
            cout<<x[beg+(n-beg)%t]<<endl;  
    }    
return 0;
}
