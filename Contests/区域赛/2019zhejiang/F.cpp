#include <bits/stdc++.h>
using namespace std;
char s[120], ans[120];
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%s", s);
    ans[0] = s[0];
    int l = strlen(s), j = 1;
    for(int i=1;i<=l;i++)
    {
      if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y')
        ans[j++] = s[i];
    }
    printf("%s\n", ans);
  }
}