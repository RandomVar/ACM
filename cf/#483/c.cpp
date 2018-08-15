#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
         if(a < b){
                   long long temp;
                   temp = a;
                   a = b;
                   b = temp;
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}
int main(){
  //  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n){
    for(int i=0;i<n;i++)
    {
        ll p,q,b;
    scanf("%lld%lld%lld",&p,&q,&b);
//        cin>>p>>q>>b;
        if(p%q==0){
                printf("Finite\n");
//            cout<<"Finite"<<endl;

        }
        else{
                int flag=0;
            ll t=gcd(q,p);
            q=q/t;
            p=p/t;
            while(1){
                ll d=gcd(q,b);
                if(d==1) {flag=1;break;}
                q/=d;
                if(q==1) break;
                b=d;
            }

            if(flag){
               printf("Infinite\n");
                //cout<<"Infinite"<<endl;
            }
            else
            printf("Finite\n");
                //cout<<"Finite"<<endl;
        }
    }

   }
return 0;
}
