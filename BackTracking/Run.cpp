#include <bits/stdc++.h>
using namespace std;

int N, X[100], cot[100], d1[100], d2[100];
int a[100][100];
int cnt = 0;

void Inkq()
{
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= N; i++)
	{
		a[i][X[i]] = 1;
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void Try(int i)
{
	for(int j = 1; j <= N; j++)
	{
		if(cot[j] == 1 && d1[i - j + N] == 1 && d2[i + j - 1] == 1)
		{ 
			X[i] = j;
			cot[j] = d1[i - j + N] = d2[i + j - 1] = 0;
			if(i == N) 
				{
					cnt++;
					//Inkq();
				}
			else Try(i + 1);
			cot[j] = d1[i - j + N] = d2[i + j - 1] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= 99; i++)
		cot[i] = d1[i] = d2[i] = 1;
	Try(1);
	cout << cnt << endl;

	return 0;
}