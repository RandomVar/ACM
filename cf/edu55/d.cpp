#include<bits/stdc++.h>
#define fir first
#define sec second
#define mkr make_pair
using namespace std;
const int maxn=600;
int a[maxn];
vector<int>v,v1;
typedef pair<int,int> P;
queue<P>q;
int main()
{
    int n;
    while(cin>>n)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
         cin>>a[i],sum+=a[i];
        if(sum<2*(n-1))
      {
          cout<<"NO"<<endl;
          continue;
      }
      else
      {
          cout<<"YES"<<" ";
          int cnt=0;
          for(int i=1;i<=n;i++)
             if(a[i]==1) cnt++,v1.push_back(i);
             else v.push_back(i);
           cout<<n-max(cnt-2,0)-1<<endl;
           cout<<n-1<<endl;
           for(int i=0;i<v.size()-1;i++)
           {
              cout<<v[i]<<" "<<v[i+1]<<endl; 
             a[v[i]]--;a[v[i+1]]--;
            //  cout<<"?"<<endl;
           }
           if(v1.size()&&v.size())
           {
              cout<<v1[0]<<" "<<v[0]<<endl;
              a[v[0]]--;
            //   cout<<"?"<<a[v[0]]<<endl;
           }
            if(v1.size()>1&&v.size())
              {
              cout<<v[v.size()-1]<<" "<<v1[1]<<endl;
              a[v[v.size()-1]]--;
            //   cout<<a[v[v.size()-1]]<<endl;
              }
           for(int i=0;i<v.size();i++)
           if(a[v[i]])  
           {
               q.push(mkr(v[i],a[v[i]]));
            //    cout<<"!"<<a[i]<<endl;
           }
           for(int i=2;i<v1.size();i++)
          {
              P d=q.front();
              q.pop();
            //   cout<<d.fir<<" "<<d.sec<<endl;
              d.sec--;
              if(d.sec) q.push(d);
              cout<<v1[i]<<" "<<d.fir<<endl;
          }
      }
    }
}