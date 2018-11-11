#include<bits/stdc++.h>
using namespace std;
string str;
const int maxn=2e5+10000;
string s[maxn];
int id[maxn];
int num[210];
int check(int x)
{
    int len=s[x].size();
    if(len==0) return 0;
    if(s[x][0]>='a'&&s[x][0]<='z') return 0;
    if(s[x][0]=='0'&&len>1) return 0;
    if(s[x][len-1]>='a'&&s[x][len-1]<='z') return 0;
    return 1;
}
int main()
{
    // #ifndef ONLINE_JUDGE 
    // freopen("data.in","r",stdin); 
    // freopen("data.out","w",stdout); 
    // #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int k=0;
    int c=0;
    int cnt=0;
    memset(id,0,sizeof(id));
    memset(num,0,sizeof(num));
  while(getline(cin,str))
  {
      c++;
      stringstream ss(str);
      char bb=str[0];
      if(bb==' ') k++;
      if(ss>>s[++k])
      {
          if(k!=1)
          {
            //   cout<<s[k-1]<<" "<<s[k-1].size()<<endl;
              int x=s[k-1].size()-1;
            //   cout<<x<<endl;
              if(x>=0&&s[k-1][x]>='0'&&s[k-1][x]<='9'&&s[k][0]>='0'&&s[k][0]<='9')
                {
                    
                    s[k-1]+=s[k];
                     s[k]="";
                    // for(int i=0;i<y;i++)
                    //   s[k-1][++x]=s[k][i];
                    //   s[k-1][++x]='\0';
                      k--;
                }
                else id[k]=c;
          }
          else id[k]=c;
        // cout<<s[k]<<endl;
     while(ss>>s[++k])
      {
    //  cout<<s[k]<<endl;
           id[k]=c;
      }
      int len=str.size();
      if(str[len-1]==' ')
        k++;
      k--;
      }                           
     
  }
  int flag=0;
   for(int i=1;i<=k;i++)
      {
          if(check(i))
          {
            if(flag) 
                cout<<" ";
            cout<<s[i];
            num[id[i]]++;
            flag=1;
          }
      }
      cout<<endl;
    //   printf("%d\n",cnt);
      for(int i=1;i<=c;i++)
        cout<<num[i]<<endl;
        // printf("%d\n",num[i]);
}