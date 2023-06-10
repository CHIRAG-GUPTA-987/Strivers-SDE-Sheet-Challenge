/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *head = new Node((num1->data + num2->data) % 10), *p = NULL;
    int carry = (num1->data + num2->data) / 10;
    num1 = num1->next;
    num2 = num2->next;
    p = head;
    while (num1 && num2)
    {
        p->next = new Node((num1->data + num2->data + carry) % 10);
        carry = (num1->data + num2->data + carry) / 10;
        num1 = num1->next;
        num2 = num2->next;
        p = p->next;
    }
    while (num1)
    {
        p->next = new Node((num1->data + carry) % 10);
        carry = (num1->data + carry) / 10;
        num1 = num1->next;
        p = p->next;
    }
    while (num2)
    {
        p->next = new Node((num2->data + carry) % 10);
        carry = (num2->data + carry) / 10;
        num2 = num2->next;
        p = p->next;
    }
    if (carry)
        p->next = new Node(1);
    return head;
    // Write your code here.
}
