/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    Node<int> *head = NULL;
    if (first->data <= second->data)
    {
        head = first;
        first = first->next;
    }
    else
    {
        head = second;
        second = second->next;
    }
    Node<int> *p = head;
    while (first && second)
    {
        if (first->data <= second->data)
        {
            p->next = first;
            first = first->next;
        }
        else
        {
            p->next = second;
            second = second->next;
        }
        p = p->next;
    }
    if (first)
        p->next = first;
    else
        p->next = second;
    return head;
    // Write your code here.
}
