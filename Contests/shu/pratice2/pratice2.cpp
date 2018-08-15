#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int po[50],pr[50],w[50];
int line[50][50];
int used[50],match[50];
int num_left;
int num_right;
bool find(int x){
  for(int i=1;i<=num_right;i++){
    if(line[x][i]&&!used[i]){
        used[i]=1;
        if(match[i]==0||find(match[i])){
            match[i]=x;
            return true;
        }
    }
  }
  return false;
}
int hungarian()
{
    int ans = 0;
    memset(match,0,sizeof(match));
    for (int i=1;i<=num_left;i++) {
       memset(used,0,sizeof(used));
       if(find(i)) ans++;
    }
    return ans;
}
int main(){
  int t;cin>>t;
  while(t--){
    memset(line,0,sizeof(line));
    cin>>num_left;
    for(int i=1;i<=num_left;i++){
        cin>>po[i];
    }
    for(int i=1;i<=num_left;i++){
        cin>>pr[i];
    }
    cin>>num_right;
    for(int i=1;i<=num_right;i++){
        cin>>w[i];
    }
    for(int i=1;i<=num_left;i++){
       for(int j=1;j<=num_right;j++){
         if(po[i]-pr[i]<=w[j]&&po[i]+pr[i]>=w[j]){
            line[i][j]=1;
         }
       }
    }

    cout<<hungarian()<<endl;
  }
  return 0;
}
