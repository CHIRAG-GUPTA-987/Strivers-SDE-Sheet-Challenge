/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (!head)
        return head;
    LinkedListNode<int> *root = head;
    while (root)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(root->data);
        newNode->next = root->next;
        root->next = newNode;
        root = newNode->next;
    }
    root = head;
    while (root)
    {
        if (root->random)
            root->next->random = root->random->next;
        else
            root->next->random = NULL;
        root = root->next->next;
    }
    LinkedListNode<int> *head2 = head->next;
    root = head;
    while (root)
    {
        LinkedListNode<int> *store = root->next;
        root = root->next = store->next;
        if (root)
            store->next = root->next;
    }
    return head2;
    // Write your code here.
}
