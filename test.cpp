ll spfa(int x)
{
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    d[x]=0;
    queue<int> que;
    que.push(x);
    vis[x]=1;
    cnt[x]=1;
    while(!que.empty())
    {
        int t=que.front();
        que.pop();
        vis[t]=0;
        for(int i=0;i<G[t].size();i++)
        {
            node e=G[t][i];
            if(d[e.to]>d[t]+e.cost)
            {
                d[e.to]=d[t]+e.cost;
                if(!vis[e.to])
                {
                    que.push(e.to);
                    vis[e.to]=1;
                    cnt[e.to]++;
                }
            }
        }
        if(cnt[t]>N+1)
            return -1;
    }
    return 0;
}