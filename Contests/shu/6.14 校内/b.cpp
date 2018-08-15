#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=12;
const int maxk=1e5+100;
const int maxmod=5;
int casenum,n,k;
int data1[maxn];
int modres[maxmod];
void init()
{
    memset(data1,0,sizeof(data1));
    for(int i=0;i<maxmod;i++) modres[i]=-1;
}
int main()
{
    cin>>casenum;
    while(casenum--)
    {
        init();
        cin>>n>>k;
        int temp;
        for(int i=1;i<=n;i++) cin>>data1[i];
        sort(data1+1,data1+1+n);
        for(int i=n;i>=1;i--){
            temp=data1[i]%3;
            if(modres[temp]==-1) {
                modres[temp]=data1[i];
            }
        }
        int maxnum=-1;
        bool itcan=true;
        for(int i=0;i<3;i++){
            if(modres[i]>maxnum) maxnum=modres[i];
        }
        temp=maxnum%3;
            if(temp==0) {
                if(maxnum==0){
                    if(k==1) cout<<"0"<<endl;
                    else itcan=false;
                }
                else {
                    for(int i=1;i<=k;i++) cout<<maxnum;
                    cout<<endl;
                }
            }
            else if(temp==1)
            {
                int cnt=k*maxnum;
                if(cnt%3==0){
                    for(int i=1;i<=k;i++) cout<<maxnum;
                    cout<<endl;
                }
                else if(cnt%3==1){
                    if(modres[0]!=-1){
                        for(int i=1;i<=k-1;i++) cout<<maxnum;
                        cout<<modres[0]<<endl;
                    }
                    else if(modres[2]!=-1){
                        if(k<2) {
                            itcan=false;
                            break;
                        }
                        for(int i=1;i<=k-2;i++) cout<<maxnum;
                        cout<<modres[2]<<modres[2]<<endl;
                    }else itcan=false;
                }
                else if(cnt%3==2){
                    if(modres[2]!=-1){
                        for(int i=1;i<=k-1;i++) cout<<maxnum;
                        cout<<modres[2]<<endl;
                    }
                    else if(modres[0]!=-1){
                        if(k<2) {
                            itcan=false;
                            break;
                        }
                        for(int i=1;i<=k-2;i++) cout<<maxnum;
                        cout<<modres[0]<<modres[0]<<endl;
                    }else itcan=false;
                }
            }
            else if(temp==2)
            {
                int cnt=k*maxnum;
                if(cnt%3==0){
                    for(int i=1;i<=k;i++) cout<<maxnum;
                    cout<<endl;
                }
                else if(cnt%3==1){
                    if(modres[1]!=-1){
                        for(int i=1;i<=k-1;i++) cout<<maxnum;
                        cout<<modres[1]<<endl;
                    }
                    else if(modres[0]!=-1){
                        if(k<2) {
                            itcan=false;
                            break;
                        }
                        for(int i=1;i<=k-2;i++) cout<<maxnum;
                        cout<<modres[0]<<modres[0]<<endl;
                    }else itcan=false;
                }
                else if(cnt%3==2){
                    if(modres[0]!=-1){
                        for(int i=1;i<=k-1;i++) cout<<maxnum;
                        cout<<modres[0]<<endl;
                    }
                    else if(modres[1]!=-1){
                        if(k<2) {
                            itcan=false;
                            break;
                        }
                        for(int i=1;i<=k-2;i++) cout<<maxnum;
                        cout<<modres[1]<<modres[1]<<endl;
                    }else itcan=false;
                }
            }
            if(!itcan) cout<<"-1"<<endl;
    }
}
