#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a,b;
  // a[0][1]=1;

  // for(int i=0;i<3;i++)
  //  for(int j=0;j<3;j++)
  //    ans[i][j]=(f[0])
  int t;
  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    int len1=a.size();
    int len2=b.size();
    int a1=0;int a2=0;
    for(int i=len1-1;i>=0;i--)
    {
        a1=(a1*10+(a[i]-'0')%3)%3;
    }
    a1=(a1-1+3)%3;
    for(int i=len2-1;i>=0;i--)
     a2=(a2*10+(b[i]-'0')%3)%3;
     a2=(a2-1+3)%3;
    //  cout<<a1<<" "<<a2<<endl;
    // if((a1==a2&&(a1==0||a1==1)))
    if((a1==0&&(a2==0))||(a1==1&&a2==1)||(a1==2&&a2==0)||(a1==1&&a2==2))
      {
        cout<<1<<endl;
      // printf("1\n");
      }
      else cout<<0<<endl;
  //  else printf("0\n");
  }
}