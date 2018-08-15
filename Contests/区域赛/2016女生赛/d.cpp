#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double cala(int h,int m,int sec){
    int sum1=12*60*60;
    int sum2=60*60;
  double ah=(sec+m*60+h*60*60)*1.0/sum1;
  while(ah>=360) ah-=360;
//  ah=ah%360;
  double am=(sec+m*60)*360*1.0/sum2;
//  am=am%360;
  while(am>=360) am-=360;
  double ans=am-ah;
  while(ans>=360) ans-=360;
  while(ans<0) ans+=360;

  return ans;
}

int main(){
   string s;
   while(getline(cin,s)){
        double a;
        cin>>a;
      for(int i=0;i<s.size();i++)
        if(s[i]==':') s[i]=' ';
      stringstream ss(s);
      int h,m,sec;
      ss>>h;ss>>m;ss>>sec;
      double x=cala(h,m,sec);
      cout<<x<<endl;
      if(x==a) {cout<<h<<":"<<m<<":"<<sec<<endl;}
      else{
      double vm=1.0/60*360;
      double vh=1.0/3600*360;
      double c=vm-vh;
      cout<<c<<endl;
      if(x<)
      double t1=(a+x)/(1.0*c);
      if(t1<0) t1=-t1;
      cout<<t1<<endl;
      int hh=h+t1/60/60;
      int mm=m+t1/60;
      int secc=sec+(int)t1%60;
       cout<<hh<<":"<<mm<<":"<<secc<<endl;
      }
   }
return 0;
}
