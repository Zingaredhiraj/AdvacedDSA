#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
// NODE STRUCTURE
////////////////////////////////////////////////////////////

struct node
{
    int data;
    node *left, *right;
    int lbit, rbit;   // 1 = child, 0 = thread
};

////////////////////////////////////////////////////////////
// FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////

node* createHead();
node* insert(node* head, int key);

void inorderRecursive(node* root);
void preorderRecursive(node* root);
void postorderRecursive(node* root);

void inorderNonRecursive(node* head);
void preorderNonRecursive(node* head);

node* inorderSuccessor(node* ptr);

////////////////////////////////////////////////////////////
// MAIN FUNCTION (AUTO INSERT + DISPLAY)
////////////////////////////////////////////////////////////

int main()
{
    node* head = createHead();

    // Insert sample values
    head = insert(head, 50);
    head = insert(head, 30);
    head = insert(head, 70);
    head = insert(head, 20);
    head = insert(head, 40);
    head = insert(head, 60);
    head = insert(head, 80);

    cout << "\nInorder Recursive : ";
    inorderRecursive(head->left);

    cout << "\nPreorder Recursive : ";
    preorderRecursive(head->left);

    cout << "\nPostorder Recursive : ";
    postorderRecursive(head->left);

    cout << "\nInorder Non Recursive : ";
    inorderNonRecursive(head);

    cout << "\nPreorder Non Recursive : ";
    preorderNonRecursive(head);

    return 0;
}

////////////////////////////////////////////////////////////
// CREATE HEAD NODE
////////////////////////////////////////////////////////////

node* createHead()
{
    node* head = new node;

    head->data = 999;   // dummy value
    head->lbit = 0;
    head->rbit = 1;

    head->left = head;
    head->right = head;

    return head;
}

////////////////////////////////////////////////////////////
// INSERT FUNCTION
////////////////////////////////////////////////////////////

node* insert(node* head, int key)
{
    node *ptr = head->left;
    node *par = head;

    while (ptr != head)
    {
        if (key == ptr->data)
        {
            cout << "Duplicate key!";
            return head;
        }

        par = ptr;

        if (key < ptr->data)
        {
            if (ptr->lbit == 1)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rbit == 1)
                ptr = ptr->right;
            else
                break;
        }
    }

    node* tmp = new node;
    tmp->data = key;
    tmp->lbit = 0;
    tmp->rbit = 0;

    // First node insertion
    if (par == head)
    {
        tmp->left = head;
        tmp->right = head;

        head->left = tmp;
        head->lbit = 1;
    }
    // Insert as left child
    else if (key < par->data)
    {
        tmp->left = par->left;   // predecessor
        tmp->right = par;        // successor

        par->lbit = 1;
        par->left = tmp;
    }
    // Insert as right child
    else
    {
        tmp->right = par->right;
        tmp->left = par;

        par->rbit = 1;
        par->right = tmp;
    }

    return head;
}

////////////////////////////////////////////////////////////
// RECURSIVE TRAVERSALS
////////////////////////////////////////////////////////////

void inorderRecursive(node* root)
{
    if (root == NULL) return;

    if (root->lbit == 1)
        inorderRecursive(root->left);

    cout << root->data << " ";

    if (root->rbit == 1)
        inorderRecursive(root->right);
}

void preorderRecursive(node* root)
{
    if (root == NULL) return;

    cout << root->data << " ";

    if (root->lbit == 1)
        preorderRecursive(root->left);

    if (root->rbit == 1)
        preorderRecursive(root->right);
}

void postorderRecursive(node* root)
{
    if (root == NULL) return;

    if (root->lbit == 1)
        postorderRecursive(root->left);

    if (root->rbit == 1)
        postorderRecursive(root->right);

    cout << root->data << " ";
}

////////////////////////////////////////////////////////////
// THREADED TREE TRAVERSAL
////////////////////////////////////////////////////////////

node* inorderSuccessor(node* ptr)
{
    if (ptr->rbit == 0)
        return ptr->right;

    ptr = ptr->right;

    while (ptr->lbit == 1)
        ptr = ptr->left;

    return ptr;
}

void inorderNonRecursive(node* head)
{
    node* ptr = head;

    while (1)
    {
        ptr = inorderSuccessor(ptr);

        if (ptr == head)
            break;

        cout << ptr->data << " ";
    }
}

void preorderNonRecursive(node* head)
{
    node* ptr = head->left;

    while (ptr != head)
    {
        cout << ptr->data << " ";

        if (ptr->lbit == 1)
            ptr = ptr->left;
        else
        {
            while (ptr->rbit == 0)
                ptr = ptr->right;

            ptr = ptr->right;
        }
    }
}
