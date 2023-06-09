/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *removeKthNode(Node *head, int K)
{
    int n = 0;
    Node *root = head;
    while (root)
    {
        n++;
        root = root->next;
    }
    Node *p = NULL;
    int c = n - K;
    root = head;
    while (c--)
    {
        p = root;
        root = root->next;
    }
    if (p == NULL)
        head = head->next;
    else
        p->next = root->next;
    delete root;
    return head;
    // Write your code here.
}
