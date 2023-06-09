/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> *node)
{
    LinkedListNode<int> *p = NULL;
    while (node && node->next)
    {
        node->data = node->next->data;
        p = node;
        node = node->next;
    }
    p->next = NULL;
    delete node;
    // Write your code here.
}