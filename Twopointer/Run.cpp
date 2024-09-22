#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, s; cin >> n >> s;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	int l = 0, r = n - 1;
	while(l < r)
	{
		int sum = a[l].first  + a[r].first;
		if(sum == s)
		{
			cout << a[l].second + 1 << " " << a[r].second + 1 << endl;
			return 0;
		}
		else if(sum > s) 
			r--;
		else 
			l++;
	}
	

	cout << "IMPOSSIBLE" << endl;
	return 0;
}