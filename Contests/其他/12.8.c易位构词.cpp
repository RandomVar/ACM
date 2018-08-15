#include<bits/stdc++.h>
using namespace std;
int a[30];
struct node{
 int num;char x;char y;
};
int cmp1(node a,node b){
 return a.x<b.x;
}
int cmp2(node a,node b){
 return a.num<b.num;
}
int main(){
  string s;
  while(getline(cin,s)){
    vector<node>v;
    int len=s.size();
    //cout<<len<<endl;
  memset(a,0,sizeof(a));
  for(int i=0;i<len;i++){
    a[s[i]-'a']++;
  }
  int flag=0;int max=0;
  for(int i=0;i<26;i++){
    if(a[i]>max) max=a[i];
    if(a[i]>len/2) {
        flag=1;break;
    }
  }
  if(flag==1) cout<<"impossible"<<endl;
  else {

      for(int i=0;i<len;i++)
        v.push_back((node){i,s[i],'a'});
      sort(v.begin(),v.end(),cmp1);
    for(int i=len-1;i>=0;i--){
        v[(i+max)%len].y=v[i].x;
        }
     sort(v.begin(),v.end(),cmp2);
    for(int i=0;i<len;i++){
        cout<<v[i].y;
    }}
        /*//cout<<i<<" ";
                //if(i==len-1) cout<<1<<endl;
        for(int j=0;j<26;j++){
            if(((s[i]-'a')!=j)&&a[j]>0)
            {
                //cout<<j<<" ";
                cout<<char('a'+j);
               //cout<<endl;
                a[j]--;break;}
        }
    }
   // for(int j=0;j<26;j++) cout<<a[j]<<endl;*/
    cout<<endl;
  }
}

/*sdfefsdfdse*/
