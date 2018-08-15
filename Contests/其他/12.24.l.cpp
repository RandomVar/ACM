#include<bits/stdc++.h>
#define LL long long
using namespace std;
int p[20];int pos;
void getprim(int x){
    memset(p,0,sizeof(p));
    pos=0;
  for(int i=2;i*i<x;i++){
    if(x%i==0){
        p[pos++]=i;
        while(x%i==0) x/=i;
    }
  }
  if(x>1) p[pos++]=x;
}
LL Get_num(int num)
{
    LL ans=0;
    for(int i=1;i<(1<<pos);i++){
        LL temp=1;int flag=0;
        for(int j=0;j<pos;j++){
            if(i&(1<<j)){
                flag++;
                temp*=p[j];
            }
        }
        if(flag&1)ans+=(num/temp)*(num/temp);
        else ans-=num/temp;
    }
     return ans;
}
int main(){
   int n;
   while(cin>>n){
        getprim(n);
   LL ans=0;
    /*for(int i=1;i<n;i++)
      if(huzhi(i)) ans+=(LL)i*i;*/
      for(int i=0;i<pos;i++){
        ans+=p[i]
      }
      cout<<ans<<endl;
   }
}
