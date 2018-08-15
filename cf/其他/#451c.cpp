#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
struct node{
  string name;int num;
  string s[400];
  bool operator<(const node &b)const{
   return name<b.name;
  }
}p[30];
vector<string>vec;
bool cmp(string a,string b){
return a.size()>b.size();
}
int cunzai(string s1,int x){
   for(int i=1;i<=x;i++){
     if(s1==p[i].name) return i;
   }
return -1;
}
void init(){
 for(int i=0;i<30;i++){
    p[i].name="";
    p[i].num=0;
 }
}
int main(){
  int n;
  while(cin>>n){
        init();
        int x=0;
    for(int i=0;i<n;i++){
        string name;
        int num;
        cin>>name>>num;
        //cout<<name<<num;
       int f=cunzai(name,x);
       if(f==-1){
        p[++x].name=name;
        f=x;
         }
       for(int j=p[f].num;j<num+p[f].num;j++){
         cin>>p[f].s[j];
       }
       p[f].num+=num;
    }

    for(int i=1;i<=x;i++){
       sort(p[i].s,p[i].s+p[i].num,cmp);
       vec.clear();
       vec.push_back(p[i].s[0]);
       for(int j=1;j<p[i].num;j++){
           // cout<<p[i].s[j]<<endl;s
            int flag=1;
             int len2=p[i].s[j].size();
          for(int k=0;k<vec.size();k++){
              string t=vec[k];
              int len1=t.size();

              if(t.substr(len1-len2)==p[i].s[j]) {
                flag=0;break;
              }

          }
          if(flag) vec.push_back(p[i].s[j]);
       }
       p[i].num=vec.size();
       for(int j=0;j<vec.size();j++)
          p[i].s[j]=vec[j];
    }
     cout<<x<<endl;
     for(int i=1;i<=x;i++){
        cout<<p[i].name<<" "<<p[i].num;
        for(int j=0;j<p[i].num;j++)
            cout<<" "<<p[i].s[j];
        cout<<endl;
     }

  }


}
