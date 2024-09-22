#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int i, int n)
{
	int l = i * 2 + 1;
	int r = i *2 + 2;
	int lagest = i;

	if(l < n && a[lagest] < a[l])
		lagest = l;
	if(r < n && a[lagest] < a[r])
		lagest = r;

	if(lagest != i)
	{
		swap(a[lagest], a[i]);
		heapify(a, lagest, n);
	}
}

void HeapSort(int a[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(a, i, n);

	for(int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify(a, 0 ,i);
	}
}
int main()
{
	int n = 100;
	int a[1000];

	srand(time(nullptr));
	for(int i = 0; i < n; i++)
		a[i] = rand() % 1000;

	HeapSort(a, n);

	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}