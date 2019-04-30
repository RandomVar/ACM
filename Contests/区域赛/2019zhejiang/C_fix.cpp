#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int a[maxn], cnt[maxn], vis[maxn];
struct node
{
  int x, y;
  node(int xx, int yy) { x = xx, y = yy; }
  bool operator<(const node &t) const { return y < t.y; }
};
int main()
{
  int T, n;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(int) * (n + 5));
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int flag = 1;
    for (int i = 1; i <= n && flag; i++)
      if (cnt[i] * 2 > n)
        flag = 0;
    if (!flag)
    {
      puts("Impossible");
      continue;
    }
    memset(vis, 0, sizeof(int) * (n + 5));
    vector<int> I;
    priority_queue<node> N;
    for (int i = 1; i <= n; i++)
    {
      if (cnt[i])
      {
        I.push_back(i);
        N.push(node(i, 2 * cnt[i]));
        vis[i] = cnt[i];
      }
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      int flag = 1;
      vis[a[i]]--;
      while(true)
      {
        node T = N.top();
        if (T.y <= n - i - 1) break;
        if (T.y != vis[T.x] + cnt[T.x])
        {
          N.pop();
          N.push(node(T.x, vis[T.x] + cnt[T.x]));
        }
        else if (T.x != a[i])
        {
          a[i] = T.x;
          cnt[T.x]--;
          N.pop();
          N.push(node(T.x, vis[T.x] + cnt[T.x]));
          flag = 0;
          break;
        }
      }
      if (!flag) continue;
      flag = 1;
      for (int k = j; k < I.size() && flag; k++)
      {
        if (I[k] != a[i] && cnt[I[k]])
          a[i] = I[k], cnt[I[k]]--, flag = 0;
      }
      if (cnt[I[j]] == 0)  j++;
    }
    for (int i = 0; i < n; i++)
      if(!i)
        printf("%d", a[i]);
      else
        printf(" %d", a[i]);
    puts("");
  }
}