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

int n, final, a[1001], cnt;

void KhoiTao()
{
	cnt = 1;
	a[1] = n;
}
void Sinh()
{
	int i = cnt;
	while(i >= 1 && a[i] == 1) i--;
	if(i == 0) final =0;
	else 
	{
		a[i]--;
		int bu = cnt - i + 1;
		cnt = i;
		int chia = bu / a[i];
		int du = bu % a[i];
		if(chia)
			rer(j, 1, chia)
			{
				cnt++;
				a[cnt] = a[i];
			}
		if(du)
		{
			cnt++;
			a[cnt] = du;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		final = 1;
		cin >> n;
		KhoiTao();
		while(final)
		{
			cout << "(";
			rer(i, 1, cnt - 1)
				cout << a[i] << " ";
			cout << a[cnt] << ")";
			cout << " ";
			Sinh();
		}
		cout << endl;
	}
	return 0;
}