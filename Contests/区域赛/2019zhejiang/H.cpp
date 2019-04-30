#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn], vis[maxn];
int n;
int judge_1(int i)
{
  if (i < 0 || i >= n)
    return 0;
  int ans = 0;
  if (i - 1 >= 0 && a[i] > a[i - 1] && i + 2 < n && a[i] > a[i + 2])
    ans = 1;
  return vis[i] - ans;
}
int judge_2(int i)
{
  if (i < 0 || i >= n)
    return 0;
  int ans = 0;
  if (i - 2 >= 0 && a[i] > a[i - 2] && i + 1 < n && a[i] > a[i + 1])
    ans = 1;
  return vis[i] - ans;
}
int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    vis[0] = vis[n - 1] = 0;
    int cnt = 0, ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
      if (a[i] > a[i - 1] && a[i] > a[i + 1])
        vis[i] = 1, cnt++;
      else
        vis[i] = 0;
    }

    for (int i = 0, ma; i < n; i++)
    {
      ma = judge_1(i - 1) + judge_2(i + 1);
      ans = max(ans, ma + vis[i]);
    }
    printf("%d\n", cnt - ans);
  }
}