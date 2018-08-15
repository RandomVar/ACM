#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int>st;
int main(){
	char s[1005];
	while(cin.getline(s,1005)){
		while(!st.empty())
		   st.pop();
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='(') st.push(i);
			else if(s[i]==')') st.pop();
			else if(s[i]=='B') {
				int t=st.size();
				cout<<t<<endl;break;
			}
		}
	}
}
