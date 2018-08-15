#include<iostream>
#include<cstdio> 
using namespace std;
long long gcd(long long a,long long b){
         if(a < b){   
                   long long temp;
                   temp = a;
                   a = b;
                   b = temp;
         }
         while(a % b){   
             long long r = a % b;   
                   a = b;
                   b = r;
                   r = a % b;
         }
         return b;
}
 long long quickmod(long long a,long long b,long long m)  
{  
    long long ans = 1;  
    while(b)  
    {  
        if(b&1)
        {  
            ans = (ans*a)%m;
            b--;
        }  
        b/=2;  
        a = a*a%m;  
    }  
    return ans;  
}   
int main(){
	long long a,b;
	long long c;
	while(scanf("%lld%lld",&a,&b)==2){
		c=1;
		for(int i=1;i<=b;i++) {c=b*c;if(c>a) break;}
		if(c>a) c=quickmod(b,b,a);
		if(c==0) cout<<a<<endl;
		else cout<<gcd(c,a)<<endl;
	}
	return 0;
	}
