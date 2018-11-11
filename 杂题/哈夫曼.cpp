#include<bits/stdc++.h>
#define mkr make_pair
using namespace std;
typedef pair<int,int> P;
int a[60];
int l[60<<2];
int r[60<<2];
string s[60<<2];
void dfs(int k)
{
    
 if(l[k])
 {
     s[l[k]]=s[k]+'0';   
    dfs(l[k]);
 }
  if(r[k])
  {
      s[r[k]]=s[k]+'1';
    dfs(r[k]);
 }
}
int main()
{
    int t;
    cin>>t;int cas=0;
    while(t--)
    {
        int n;
        priority_queue<P,vector<P>,greater<P> >que;
        cin>>n;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=0;i<(60<<2);i++)
          s[i]="\0";
        for(int i=1;i<=n;i++)
        {
         cin>>a[i],que.push(mkr(a[i],-i));
        }
        int k=n;
        while(!que.empty())
        {
          P p1=que.top();
          que.pop();
          if(que.empty()) break;
          P p2=que.top();
          que.pop();
          que.push(mkr(p1.first+p2.first,-(++k)));
          l[k]=-p2.second;r[k]=-p1.second;//左子树权值大，序号小
         
        }
        cout<<"Case "<<++cas<<endl;
        dfs(k);
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
            cout<<s[i]<<endl;
        }
        cout<<endl;
    }
}