#include <iostream>
using namespace std;

class BST
{
private:
    struct node
    {
        int m_value;
        struct node *pLeft, *pRight;
    };
    node* m_root;
public:
    BST() {m_root = NULL;}
    BST(int data)
    {
        m_root->m_value = data;
        m_root->pLeft = m_root->pRight = NULL;
    }
    node* getRootNode() { return m_root;}
    int getRootValue() { return m_root->m_value;}

    void traversal(node* t)
    {
        if(t == NULL)
            return;
        traversal(t->pLeft);
        cout<<t->m_value<<" ";
        traversal(t->pRight);
    }

    void insert(const int& value, node* t)
    {
        if(t == NULL)
            return;
        if(value >= t->m_value)
            insert (value, t->pRight);
        else
            insert (value, t->pLeft);

        node* newnode = new node;
        newnode->m_value = value;
        newnode->pLeft = newnode->pRight = NULL;

    }


};

int main()
{
    return 0;
}