#include<bits/stdc++.h>
using namespace std;
int a[100100];
stack<int>st;
set<int>s;
int main(){
    int n;
    while(cin>>n){
        s.clear();
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--)
               st.push(a[j]);

        while(st.size()>1){
            int x1=st.top();
            st.pop();
            s.insert(x1);
            int x2=st.top();
            s.insert(x2);
            st.pop();
            cout<<x1<<x2<<endl;
            if(st.empty()||(x1|x2)!=st.top())
                st.push((x1|x2));
        }
        while(!st.empty()){
            int x1=st.top();
            s.insert(x1);
            st.pop();
        }}
        cout<<s.size()<<endl;
    }


}
