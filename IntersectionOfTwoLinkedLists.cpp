/****************************************************************

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

*****************************************************************/
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *h1 = firstHead, *h2 = secondHead;
    while (h1 && h2)
    {
        if (h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1)
        h2 = firstHead;
    else if (h2)
        h1 = secondHead;
    else
        return NULL;
    while (h1 && h2)
    {
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1)
        h2 = firstHead;
    else if (h2)
        h1 = secondHead;
    while (h1 && h2)
    {
        if (h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
    // Write your code here
}