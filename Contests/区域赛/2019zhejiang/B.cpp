#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn], cnt[maxn];
int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n, ma = 0;
    ll x, y, ans = 0;
    scanf("%d%lld%lld", &n, &x, &y);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      ma = max(ma, a[i]);
      x -= 1LL * (i + 1) * a[i];
      y -= 1LL * (i + 1) * a[i] * a[i];
    }
    memset(cnt, 0, sizeof(cnt));
    if (x == 0 && y == 0)
    {
      for (int i = 0; i < n; i++)
      {
        ans += cnt[a[i]];
        cnt[a[i]] += 1;
      }
    }
    else if (x != 0 && y != 0 && y % x == 0)
    {
      ll add = y / x;
      for (int i = 0; i < n; i++)
        cnt[a[i]] += 1;
      for (int i = 0; i < n; i++)
      {
        if (a[i] <= add && add != 2 * a[i] && cnt[add - a[i]])
        {
          int b = add - a[i];
          if (x % abs(a[i] - b) == 0)
          {
            ll d = x / (a[i] - b);
            if (d > 0 && i + d < n && a[i + d] == b)
            {
              ans++;
            }
          }
        }
      }
    }
    printf ("%lld\n", ans);
  }
}