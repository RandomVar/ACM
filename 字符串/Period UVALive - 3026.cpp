#include<bits/stdc++.h>
using namespace std;
string s;
int f[1000010];
void getfailture(){
  int j=0;int k=-1;
  f[0]=-1;
  while(j<s.size())
  if(k==-1||s[k]==s[j])
    f[++j]=++k;
   else k=f[k];
}
/*int kmp(string pat,int p){
 getfailture(pat);
 int i=p,j=0;
 while(i<s.size()&&j<pat.size()&&pat.size()-j<=s.size()-i){
    if(j==-1||pat[j]==ob[i]) {i++;j++;}
    else j=f[j];
 }
 if(j<pat.size()) return -1;
 else return i-j;
}*/

int main(){
  int n;int k=0;
  while(scanf("%d",&n)==1){
    if(n==0) break;
    k++;
    getchar();
    getline(cin,s);
    printf("Test case #%d\n",k);
    //string pat;
    getfailture();
    /*for(int i=0;i<s.size();i++)
        cout<<f[i]<<" ";*/
    for(int i=2;i<=s.size();i++){
        if(f[i]&& i%(i-f[i])==0)
            printf("%d %d\n", i, i / (i- f[i]));
    }
    printf("\n");
  }
  return 0;
}
