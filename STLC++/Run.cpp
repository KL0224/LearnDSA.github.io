#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	unordered_map<int, int> m;
	m.insert({1, 100});
	m.insert({2, 100});
	m.insert({2, 400});

	for(auto x : m)
	{
		cout << x.first << " " << x.second << endl;
	}
	
	return 0;
}