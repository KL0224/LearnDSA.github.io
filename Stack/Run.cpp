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
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

void push(node *&top, int x)
{
	node* newnode = newNode(x);
	if(top == NULL)
	{
		top = newnode;
		return;
	}
	newnode->next = top;
	top = newnode;
}

void pop(node *&top)
{
	if(top != NULL)
	{
		node *temp = top;
		top = temp->next;
		delete temp;
	}
}

int top(node *&top)
{
	if(top != NULL)
	{
		return top->data;
	}
	return -1;
}

int size(node *head)
{
	int dem = 0;
	while(head != NULL)
	{
		dem++;
		head = head->next;
	}
	return dem;
}

int main()
{
	node* Stack = 0;
	while(true)
	{
		cout << "========================\n";
		cout << "1. push\n";
		cout << "2. pop\n";
		cout << "3. top\n";
		cout << "4. size\n";
		cout << "0. Thoat\n";
		cout << "========================\n";
		int chon; cin >> chon;
		if(chon == 1)
		{
			int x; cout << "Nhap gia tri: "; cin >> x;
			push(Stack, x);
		}
		else if(chon == 2)
		{
			pop(Stack);
		}
		else if(chon == 3)
		{
			if(Stack == NULL) cout << "EMPTY\n";
			cout << top(Stack) << endl;
		}
		else if(chon == 4)
			cout << size(Stack) << endl;
		else 
			break;
	}
	return 0;
}