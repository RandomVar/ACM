#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-6;
typedef pair<int,int>line;
line lines[5010];
int cnt[5010];
int n,m,xa,ya,xb,yb;
bool check(int x,int y,line l){
  if(x<min(l.first,l.second)) return 0;
  double xline=(double)(l.first-l.second)/(ya-yb)*(y-ya)+l.first;
  //cout<<xline<<endl;
  if(xline<=x) return 1;
  else return 0;
}
int main(){
   while(cin>>n){
    if(n==0) break;
   else cin>>m>>xa>>ya>>xb>>yb;
    memset(cnt,0,sizeof(cnt));
      lines[0]=line(xa,xa);
      for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        lines[i]=line(a,b);
      }
      lines[n+1]=line(xb,xb);
      for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int left=0;int right=n+1;
        while(left<=right){
            int mid=(left+right)/2;
            if(check(x,y,lines[mid])){
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        cnt[left-1]++;
       // cout<<left<<endl;
      }
      for(int i=0;i<=n;i++){
        cout<<i<<": "<<cnt[i]<<endl;
      }
      cout<<endl;
   }
}
/*
5 6 0 10 60 0
3 1
4 3
6 8
10 10
15 30
1 5
2 1
2 8
5 5
40 10
7 9
4 10 0 10 100 0
20 20
40 40
60 60
80 80
 5 10
15 10
25 10
35 10
45 10
55 10
65 10
75 10
85 10
95 10
0
*/
