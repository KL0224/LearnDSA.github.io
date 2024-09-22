#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* newNode(int x)
{
	node* newnode = new node();
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void push(node *&que, int x)
{
	node *newnode = newNode(x);
	if(que == NULL)
	{
		que = newnode;
		return;
	}

	node* temp = que;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}

void pop(node *&que)
{
	if(que == NULL) return;
	node* temp = que;
	que = que->next;
	delete temp;
}

int size(node *que)
{
	int dem = 0;
	while(que != NULL)
	{
		dem++;
		que = que->next;
	}
	return dem;
}

bool empty(node* que)
{
	return que == NULL;
}

int front(node *que)
{
	return que->data;
}

void Printf(node* que)
{
	while(que != NULL)
	{
		cout << que->data << " ";
		que = que->next;
	}
	cout << endl;
}

int main()
{
	node* que = NULL;
	while(true)
	{
		cout << "========================\n";
		cout << "1. push\n";
		cout << "2. pop\n";
		cout << "3. front\n";
		cout << "4. size\n";
		cout << "5. empty\n";
		cout << "6. Duyet\n";
		cout << "0. Thoat\n";
		cout << "========================\n";
		int chon; cin >> chon;
		if(chon == 1)
		{
			int x; cout << "Nhap gia tri: "; cin >> x;
			push(que, x);
		}
		else if(chon == 2)
		{
			pop(que);
		}
		else if(chon == 3)
		{
			if(que == NULL) cout << "EMPTY\n";
			else cout << front(que) << endl;
		}
		else if(chon == 4)
			cout << size(que) << endl;
		else if(chon == 5)
		{
			if(empty(que)) cout << "EMPTY\n";
			else cout << "NOT EMPTY\n";
		}
		else if(chon == 6)
			Printf(que);
		else 
			break;
	}
	return 0;
}