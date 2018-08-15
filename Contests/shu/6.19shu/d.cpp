#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1010];
ll cnt[30];
ll w[30][100000];
int main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
 // cin>>t;
  while(t--){
        memset(cnt,0,sizeof(cnt));
  memset(w,0,sizeof(w));
    int n,q;
    scanf("%d%d",&n,&q);
   // cin>>n>>q;
    string s;
    cin>>s;
    //scanf("%s",s);
    //cin>>s;
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
        w[s[i]-'a'][cnt[s[i]-'a']]=i+1;
    }
    /*for(int i=0;i<26;i++){
        for(int j=0;j<=cnt[i];j++)
        cout<<w[i][j]<<" ";
  cout<<endl;
    }*/
    for(int i=1;i<=q;i++){
        ll l;ll r;
        char c;
        scanf("%lld%lld%*c%c",&l,&r,&c);
        //cin>>l>>r>>c;
        int xl=(l-1)%n+1;
        int  xr=(r-1)%n+1;
        ll shu=(r-1)/n-(l-1)/n-1;
        int p2=upper_bound(w[c-'a'],w[c-'a']+cnt[c-'a']+1,xr)-w[c-'a'];//>=r
        int p1=lower_bound(w[c-'a'],w[c-'a']+cnt[c-'a']+1,xl)-w[c-'a'];
        ll ans=cnt[c-'a']-p1+1+p2-1;
        //if(w[c-'a'][p2]==xr) ans++;
        //if(w[c-'a'][p1]==xl) ans++;
        printf("%lld\n",ans+cnt[c-'a']*shu);
        //cout<<ans+cnt[c-'a']*shu<<e//ndl;
        //cout<<p1<<" "<<p2<<endl;
        //cout<<p2-p1<<endl;
    }
  }

return 0;
}
