#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	vector<string> v;
	while(cin >> s)
	{
		v.push_back(s);
	}

	sort(v.begin(), v.end(), greater<string>());
	for(auto x : v)
	{
		cout << x << endl;
	}
	return 0;
}