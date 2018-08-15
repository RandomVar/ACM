#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll l[4];
ll r[4];
ll andSet[4];
ll ans;

void dfs(int currendIndex, bool isOdd, ll preMul) {
    for(int i = currendIndex; i < 4; i++) {
        ll temp = (preMul * andSet[i]) % mod;
        if(isOdd) {
            ans -= temp;
        }
        else {
            ans += temp;
        }
        dfs(i + 1, !isOdd, temp);
    }
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        ans = 1;
        for(int i = 0; i < 4; i++) {
            cin>>l[i]>>r[i];
            ans = ans * (r[i] - l[i] + 1) % mod;
        }
        for(int i = 0; i < 4; i++) {
            andSet[i] = min(r[i], r[(i + 1)%4]) - max(l[i], l[(i+ 1)%4]) + 1;
            if(andSet[i] < 0) {
                andSet[i] = 0;
            }
        }
        dfs(0, true, 1);
        cout<<ans<<endl;
    }
}
