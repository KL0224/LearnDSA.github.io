#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* NewNode(int data)
{
	node* newnode = new node;
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void InsertNode(node* t, int data)
{
	if(t == NULL)
	{
		node* newnode = NewNode(data);
		t = newnode;
		return;
	}
	if(t->data > data)
		InsertNode(t->left, data);
	else 
		InsertNode(t->right, data);
}

void LNR(node* t)
{
	if(t != NULL)
	{
		LNR(t->left);
		cout << t->data << " ";
		LNR(t->right);
	}
}

void 

void CheckBST(node* t)
{

}

int main()
{

}