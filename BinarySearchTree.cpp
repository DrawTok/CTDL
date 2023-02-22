#include <iostream>

using namespace std;

struct Node
{
    int key_value;
    Node *left;
    Node *right;
};

class BST
{
private:
    Node *root;
    void destroy_tree(Node *leaf)
    {
        if (leaf != NULL)
        {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }

    void insert(int key, Node *leaf)
    {
        if (key < (leaf->key_value))
        {
            if (leaf->left != NULL)
            {
                insert(key, leaf->left);
            }
            else
            {
                leaf->left = new Node;
                leaf->left->key_value = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        }
        else if (key >= (leaf->key_value))
        {
            if (leaf->right != NULL)
            {
                insert(key, leaf->right);
            }
            else
            {
                leaf->right = new Node;
                leaf->right->key_value = key;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
        }
    }

    Node *search(int key, Node *leaf)
    {
        if (leaf != NULL)
        {
            if (key == (leaf->key_value))
            {
                return leaf;
            }

            if (key < leaf->key_value)
            {
                return search(key, leaf->left);
            }
            else
            {
                return search(key, leaf->right);
            }
        }
        else
            return NULL;
    }

    void printPreOrder(Node *r)
    {
        if (r == NULL)
            return;
        cout << r->key_value << " ";
        printPreOrder(r->left);
        printPreOrder(r->right);
    }

    void printPostOrder(Node *r)
    {
        if (r == NULL)
            return;
        printPostOrder(r->left);
        printPostOrder(r->right);
        cout << r->key_value << " ";
    }

    void printInOrder(Node *r)
    {
        if (r == NULL)
            return;
        printInOrder(r->left);
        cout << r->key_value << " ";
        printInOrder(r->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        destroy_tree();
    }

    void insert(int key)
    {
        if (root != NULL)
        {
            insert(key, root);
        }
        else
        {
            root = new Node;
            root->key_value = key;
            root->left = NULL;
            root->right = NULL;
        }
    }

    void *search(int key)
    {
        return search(key, root);
    }

    void destroy_tree()
    {
        destroy_tree(root);
    }

    void PreOrder()
    {
        printPreOrder(root);
    }

    void InOrder()
    {
        printInOrder(root);
    }

    void PostOrder()
    {
        printPostOrder(root);
    }
};

int main()

{
    BST t1;
    t1.insert(18);
    t1.insert(8);
    t1.insert(94);
    t1.insert(42);
    t1.insert(13);
    t1.insert(78);
    t1.insert(34);
    t1.insert(4);
    t1.insert(7);
    t1.insert(12);
    t1.insert(10);
    t1.insert(19);
    t1.insert(22);
    t1.insert(18);
    t1.insert(26);
    cout << "Post:";
    t1.PostOrder();
    cout << endl
         << "Pre:";
    t1.PreOrder();
    cout << endl
         << "In:";
    t1.InOrder();
    cout << endl;
    return 0;
}