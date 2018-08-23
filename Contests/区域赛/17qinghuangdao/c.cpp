#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
string s;
pair<int,int> c[20];
int id(char c)
{
    if(c=='g') return 0;
    if(c=='o') return 1;
    if(c=='a') return 2;
}
void solve()
{
    
    int k=0;
    c[++k].fir=id(s[0]);
    c[k].sec=1;
    int ans=0;
    for(int i=1;i<9;i++)
    {
        if(id(s[i])==c[k].fir)
        {
            c[k].sec++;
        }
        else {
            c[++k].fir=id(s[i]);
            c[k].sec=1;
        }
        if(c[k].sec==3)
        {
            ans++;k--;
        }
    }
    if(ans==3)
    {
        cout<<3<<endl;return;
    }
    if(ans==2)
     {
         cout<<3<<endl;return;
     }
     if(ans==1)
     {
         cout<<2<<endl;return;
     }
    int cnt=0;
    int pre=-1;
    // for(int i=1;i<=k;i++)
    //  cout<<c[i].fir<<" "<<c[i].sec<<endl;
    for(int x=0;x<3;x++)
    {
        for(int i=1;i<=k;i++)
        {

            if(c[i].fir==x) continue;
           if(pre==-1||c[i].fir==pre)
              cnt+=c[i].sec,pre=c[i].fir;
           else
           {
               pre=c[i].fir;
               cnt=c[i].sec;
           }
        //    cout<<x<<": "<<i<<" "<<pre<<" "<<cnt<<endl;
           if(cnt==3)
           {
               cout<<2<<endl;return;
           }
        }
    }
    cout<<1<<endl;return;

      
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
       solve();
    }
}