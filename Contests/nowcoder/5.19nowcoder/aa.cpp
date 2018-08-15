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
using namespace std;
const int INF=0x3f3f3f3f;
int cnt1[30];
int cnt2[30];
int aa[30];
int bb[30];
int main(){

  string a;
  string b;
  while(cin>>a>>b){
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
    for(int i=0;i<a.size();i++)
        cnt1[a[i]-'A']++;
    for(int i=0;i<b.size();i++)
        cnt2[b[i]-'A']++;
        int cnt=INF;
  for(int k=0;k<26;k++){
         int ans=0;
         for(int s=0;s<26;s++){
              aa[s]=cnt1[s];
              bb[s]=cnt2[s];
         }
    for(int e=0;e<26;e++){
        int i=(k+e)%26;
        int j=i;

        while(aa[i]){
          if(bb[j]==0)  {j=(j+1)%26;continue;}
          if(bb[j]<=aa[i]){
             aa[i]-=bb[j];
             ans+=(j-i+26)%26*bb[j];
             bb[j]=0;
             j=(j+1)%26;
        }
         else if(bb[j]>aa[i]){
              bb[j]-=aa[i];
              ans+=(j-i+26)%26*aa[i];
              aa[i]=0;
          }
      }
    //cout<<ans<<endl;
    }
    //cout<<ans<<endl;

     cnt=min(ans,cnt);
     }
    cout<<cnt<<endl;
  }
}
