#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
struct node{
   int num;
   int s;
    int nex;
    int pre;
};
node cnt[maxn];
int main(){
   string s;
   while(cin>>s){
        int k=1;
        int len=s.size();
        for(int i=0;i<s.size();i++){
          cnt[i].num=1;
          cnt[i].s=s[i]-'a';
          cnt[i].nex=i+1;
          cnt[i].pre=i-1;
        }
        int ans=0;
        int pre=0;

        while(cnt[pre].nex!=len){
            int i=pre;int flag=0;
            int j=cnt[i].nex;
        for(int x=pre;x<len;x=cnt[x].nex){
            cout<<x<<" ";

        }
        cout<<endl;
        while(cnt[i].nex!=len){
            while(j!=len&&cnt[i].s==cnt[j].s){
                   cnt[i].num+=cnt[j].num;
                   cnt[i].nex=cnt[j].nex;
                   int t=cnt[j].nex;
                   cnt[t].pre=i;
                   //i=cnt[i].nex;
                   j=cnt[j].nex;
            }

            //cnt[i].nex=j;
            int x=i;int k=cnt[i].pre;
            while(j!=len&&(cnt[i].s!=cnt[j].s||(k!=-1&&cnt[i].s!=cnt[k].s))){
                 cnt[i].num--;
                 flag=1;

                 if(cnt[i].num==0) {
                  if(cnt[i].pre>0)  cnt[cnt[i].pre].nex=cnt[i].nex;
                    cnt[cnt[i].nex].pre=cnt[i].pre;
                    if(i==pre) pre=cnt[i].nex;
                 }
                k=i;
                i=cnt[i].nex;
                j=cnt[i].nex;
            }


        }
         if(cnt[i].nex==len&&cnt[i].s!=cnt[k].s){
                 cnt[i].num--;
                 if(cnt[i].num==0) {
                  if(cnt[i].pre>0)  cnt[cnt[i].pre].nex=cnt[i].nex;

                  //  if(i==pre) pre=cnt[i].nex;
                 }
             }
        if(flag) ans++;

        }
      /*  while(cnt[pre].nex!=len){
            int i=pre;ans++;
           while(cnt[i].nex!=len){
                int j=cnt[i].nex;
               while(j<len&&cnt[i].s==cnt[j].s){
                   cnt[i].num+=cnt[j].num;
                   cnt[i].nex=cnt[j].nex;
                   int t=cnt[j].nex;
                   cnt[t].pre=i;
                   i=j;
               }
               while(j<len&&cnt[i].s!=cnt[j].s){
                 cnt[i].num--;
                 cnt[j].num--;
                 if(cnt[j].num==0) {
                        cnt[i].nex=cnt[j].nex;

                 }
                 if(cnt[i].num<=0){
                    if(i==pre) {pre=j;cnt[j].pre=-1;}
                    else {

                            cnt[cnt[i].nex].pre=cnt[i].pre;
                            cnt[cnt[i].pre].nex=cnt[i].nex;
                    }

                 }
                  i=cnt[i].nex;j=cnt[j].nex;
               }
           }
            }*/
            cout<<ans<<endl;
   }

        }

