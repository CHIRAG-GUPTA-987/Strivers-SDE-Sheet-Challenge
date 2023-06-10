/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *a, Node *b)
{
    Node *x = NULL, *y = NULL;
    if (a->data <= b->data)
    {
        y = x = a;
        a = a->child;
    }
    else
    {
        y = x = b;
        b = b->child;
    }
    while (a && b)
    {
        if (a->data <= b->data)
        {
            y->child = a;
            a = a->child;
        }
        else
        {
            y->child = b;
            b = b->child;
        }
        y = y->child;
    }
    if (a)
        y->child = a;
    else
        y->child = b;
    return x;
}
Node *flattenLinkedList(Node *head)
{
    if (head->next)
    {
        Node *slow = head, *fast = head, *p = NULL;
        while (fast)
        {
            p = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        p->next = NULL;
        head = flattenLinkedList(head);
        slow = flattenLinkedList(slow);
        return merge(head, slow);
    }
    return head;
    // Write your code here
}
