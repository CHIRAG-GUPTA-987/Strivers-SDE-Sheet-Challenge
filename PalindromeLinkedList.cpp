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

bool isPalindrome(LinkedListNode<int> *head)
{
    int n = 0;
    LinkedListNode<int> *root = head, *last = NULL;
    while (root)
    {
        n++;
        root = root->next;
    }
    if (n <= 1)
        return true;
    int k = n / 2;
    while (k--)
    {
        LinkedListNode<int> *store = head->next;
        head->next = last;
        last = head;
        head = store;
    }
    if (n % 2)
        head = head->next;
    while (last && head)
    {
        if (last->data != head->data)
            return false;
        last = last->next;
        head = head->next;
    }
    return true;
    // Write your code here.
}