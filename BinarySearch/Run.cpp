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

int FirstPos(vi a, int n, int x)
{
	int res = -1;
	int l = 0, r = n - 1;
	while(l <= r)
	{
		int m = (l + r) / 2;
		if(a[m] == x) 
		{
			res = m;
			r = m - 1;
		}
		else if(a[m] < x) l = m + 1;
		else r = m - 1;
	}
	return res;
}

int LastPost(vi a, int n, int x)
{
	int res = -1;
	int l = 0, r = n - 1;
	while(l <= r)
	{
		int m = (l + r) / 2;
		if(a[m] == x) 
		{
			res = m;
			l = m + 1;
		}
		else if(a[m] < x) l = m + 1;
		else r = m - 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x; cin >> n >> x;
	vi v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	cout << FirstPos(v, n, x) << " " << LastPost(v, n, x) << endl;
	return 0;
}