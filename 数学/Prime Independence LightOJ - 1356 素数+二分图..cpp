#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXM=500010;
const int MAXN=40010;
int prime[MAXM+1];
int a[MAXN];
int vis[100];
int line[50][50];
int used[50];//标记这条边有没有用过
int match[50];//标记右侧的点是否被匹配，以及匹配的是左侧哪个点
int nl;
int nr;
int n;
void getPrime() {
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXM;i++) {
            if(!prime[i])
                prime[++prime[0]]=i;
    for(int j=1;j<=prime[0]&&prime[j]<=MAXM/i;j++)  {
          prime[prime[j]*i]=1;
    if(i%prime[j]==0) break;
      } } }

long long f[100];
int getFactors(long long x){
    ll tmp=x;int cnt=0;
    for(int i=1;prime[i]<=tmp;i++){
        if(tmp%prime[i]==0){f[cnt++]=prime[i];
        while(tmp%prime[i]==0)
          tmp/=prime[i];}
    }
    return cnt;
}

bool find(int x){
  for(int i=0;i<n;i++){
    if(line[x][i]&&!used[i]){
        used[i]=1;
        if(match[i]==-1||find(match[i])){
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
    memset(match,-1,sizeof(match));
    for (int i=0;i<n;i++) {
       memset(used,0,sizeof(used));
       if(find(i)) ans++;
    }
    return ans;
}

void build(){
   for(int i=0;i<n;i++){
        if(!vis[i]) {vis[i]=1;nl++;}
        int cnt=getFactors(a[i]);
            // cout<<cnt<<endl;
             for(int j=i+1;j<n;j++){
               //if(!vis[j]){
              //      cout<<a[j]<<endl;
                    for(int k=0;k<cnt;k++){
                            //cout<<a[i]<<"=="<<f[k]<<"*"<<a[j]<<endl;
                        if(a[i]==f[k]*a[j]){
                               // cout<<a[i]<<"*"<<endl;
                            if(vis[i]==1) {vis[j]=2;nr++;line[i][j]=1;break;}
                           else {vis[j]=1;nl++;line[j][i]=1;break;}
        }}
    }
  // }
  // cout<<nl<<nr<<endl;
}
}

int cmp(int a,int b){
return a>b;
}

int main(){
 int t;
 scanf("%d",&t);
 int k=0;
 getPrime();
 while(k<t){
    k++;
    scanf("%d",&n);
   memset(line,0,sizeof(line));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    nr=0;nl=0;
    build();
    cout<<hungarian()/2<<endl;
    cout<<"Case "<<k<<": "<<n-hungarian()/2+n-nr-nl<<endl;
 }
}




