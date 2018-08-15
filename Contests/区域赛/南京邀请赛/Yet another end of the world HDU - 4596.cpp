#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
  int x,y,z;
  bool operator<(const node &b)const{
    return y<b.y;
  }
}s[1010];
ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    ll d=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
  }
bool judge(ll ans,ll a,ll b){
 if(a%ans==0||b%ans==0) return 1;
 else if(b/ans-a/ans>0) return 1;
 return 0;
}
int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<n;i++)
        cin>>s[i].x>>s[i].y>>s[i].z;
    sort(s,s+n);
    int flag=0;
    for(int i=1;i<n;i++){
        if(s[i-1].z>=s[i].y){ flag=1;break;}
    }
    if(flag==0){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
                ll a1,a2;
            ll ans=ex_gcd(s[i].x,s[j].x,a1,a2);/*设t=c/d,则通解为 x=t*x0+b/d*k; y=t*y0-a/d*k*/
            if(judge(ans,s[j].y-s[i].z,s[j].z-s[i].y)) {flag=1;break;}
        }
        if(flag) break;
    }}
   if(flag) cout<<"Cannot Take off"<<endl;
   else cout<<"Can Take off"<<endl;
  }
  return 0;
}
