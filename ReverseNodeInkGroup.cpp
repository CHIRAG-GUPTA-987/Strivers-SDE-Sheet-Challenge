/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    Node *store1 = head, *curr = head, *last = NULL;
    while (b[0]-- && curr)
    {
        Node *store2 = curr->next;
        curr->next = last;
        last = curr;
        curr = store2;
    }
    if (last)
        head = last;
    for (int i = 1; i < n && curr; i++)
    {
        Node *store3 = curr;
        last = NULL;
        while (b[i]-- && curr)
        {
            Node *store2 = curr->next;
            curr->next = last;
            last = curr;
            curr = store2;
        }
        if (last)
        {
            store1->next = last;
            store1 = store3;
        }
    }
    if (curr && curr != head)
        store1->next = curr;
    return head;
    // Write your code here.
}