#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int x)
{
    node* newnode = new node;
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Thêm node vào cây
void AddNode(node *&t, int x)
{
    if(t == NULL)
    {
        node* add = newNode(x);
        t = add;
    }
    else if(x < t->data)
    {
        AddNode(t->left, x);
    }
    else if(x > t->data)
    {
        AddNode(t->right, x);
    }
}


double AverageByLevel(TREE, int);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++) {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}

int height(TREE t)
{
    if(t == NULL) return -1;
    return max(height(t->left), height(t->right)) + 1;
}

int hn(node* t, int data, int dem = 0)
{
    if(t->key == data)
        return dem;
    else if(t->key < data)
        return dem + hn(t->right, data, dem) + 1;
    else 
        return dem +  hn(t->left, data, dem) + 1;
}

void LNR(node* t, vector<int> &v)
{
    if(t != NULL)
    {
        LNR(t->left, v);
        v.push_back(t->key);
        LNR(t->right, v);
    }
}

double AverageByLevel(node* t, int lv)
{
    int x = height(t);
    if(lv > x)
        return t->data;
    
    double sum = 0;
    int cnt = 0;
    
    vector<int> v;
    LNR(t, v);
    int n = v.size();
    
    for(int i = 0; i < n; i++)
    {
        if(hn(t, v[i]) == lv)
        {
            cnt++;
            sum += v[i];
        }
    }
    
    return sum / cnt;
}
