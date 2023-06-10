/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    int n = 0;
    Node *root = head, *p = NULL, *tail = NULL;
    while (root)
    {
        n++;
        tail = root;
        root = root->next;
    }
    k = k % n;
    k = n - k;
    if (n == k)
        return head;
    root = head;
    while (k--)
    {
        p = head;
        head = head->next;
    }
    if (p)
    {
        p->next = NULL;
        tail->next = root;
    }
    return head;
    // Write your code here.
}