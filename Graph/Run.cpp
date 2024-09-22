#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef map<int, int> mii;
typedef set<int> si;
typedef long long ll;

struct Edge
{
    int x, y, z;
    Edge(int x, int y, int z) : x(x), y(y), z(z) {}
};

int n, m;
vector<pair<int, int>> adj[1001];

void Input()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z}); 
    }
}

void Dijsktra(int s)
{
    vector<ll> d(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while(!Q.empty())
    {
        pair<int, int> top = Q.top(); Q.pop();
        int dinh = top.second;
        if(visited[dinh]) continue;
        visited[dinh] = true;
        for(auto x : adj[dinh])
        {
            int u = x.first;
            int trongso = x.second;
            if(d[u] > d[dinh] + trongso)
            {
                d[u] = d[dinh] + trongso;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Prim(1);

    return 0;
}