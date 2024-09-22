#include <bits/stdc++.h>
using ll = long long;
#define pb push_back
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int n, m;
int a[1000][1000];

void Nhap()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
}

void Loang(int i, int j)
{
	a[i][j] = 0;
	for(int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m)
		{
			if(a[i1][j1]) 
				{
					Loang(i1, j1);
				}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Nhap();
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			{
				if(a[i][j])
				{
					dem++;
					Loang(i, j);
				}
			}
	}

	cout << dem << endl;
	return 0;
}