#include <iostream>
using namespace std;
#define M 7

struct HashTable
{
	int sz;
	int sl;
	int head[M];
};

void initHashTable(HashTable &h)
{
	for(int i = 0; i < M; i++)
	{
		h.head[i] = -1;
	}
	h.sl = 0;
	h.sz = M;
}

int Hash(int key, int i)
{
	return ((key % M) + i) % M;
}

void Insert(HashTable &h, int key)
{
	if(h.sl == h.sz)
	{
		return;
	}

	h.sl++;
	int i = 0;
	int index = Hash(key, i);
	
	while(h.head[index] != -1)
	{
		++i;
		index = Hash(key, i);
	}

	h.head[index] = key;
}

void Delete(HashTable &h, int key)
{
	if(h.sl == 0)
	{
		cout << "Bang bam rong, khong the xoa\n";
		return;
	}

	int i = 0;
	int index = Hash(key, i);
	while(h.head[index] != key)
	{
		++i;
		if(i == h.sz || h.head[index] == -1)
		{
			cout << "Khong ton tai phan tu\n";
			return;
		}
		index = Hash(key, i);
	}
	h.head[index] = -1;
}

bool Search(HashTable h, int key)
{
	int i = 0;
	int index = Hash(key, i);

	while(h.head[index] != key)
	{
		++i;
		if(i == h.sz || h.head[index] == -1)
		{
			return false;
		} 
		index = Hash(key, i);
	}
	return true;
}

void Printf(HashTable h)
{
	for(int i = 0; i < h.sz; i++)
	{
		cout << "==================BUCKET " << i << "======================\n";
		cout << h.head[i] << endl;
	}
}

int main()
{

	HashTable h;
	initHashTable(h);

	Insert(h, 1);
	Insert(h, 8);
	Insert(h, 2);
	Insert(h, 4);
	Insert(h, 11);
	Insert(h, 15);
	Insert(h, 6);
	Insert(h, 10);
	Insert(h, 20);
	Insert(h, 30);

	Printf(h);

	// while(true)
	// {
	// 	int fd; cout <<  "Nhap phan tu muon tim kiem: "; cin >> fd;
	// 	if(Search(h, fd)) 
	// 		cout << "Tim thay phan tu " << fd << endl;
	// 	else cout << "Khong tim thay phan tu " << fd << endl;
	// }

	while(true)
	{
		int del; cout << "Nhap phan tu muon xoa: "; cin 
	}
	return 0;
}