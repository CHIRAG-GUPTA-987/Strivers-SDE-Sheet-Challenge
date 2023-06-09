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

bool detectCycle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        if (fast && fast == slow)
            return true;
    }
    return false;
    //	Write your code here
}