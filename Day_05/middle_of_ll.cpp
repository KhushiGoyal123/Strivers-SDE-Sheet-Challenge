Node *findMiddle(Node *head)
{
    // TC => O(n + n/2), SC => O(1)
    // brute => count the number of nodes by traversing and
    // for odd and even = n/2+1
    // and start traversing from head and till n/2+1 node is achieved then return

    // optimized solution => tortorise method (fast, slow)
    // TC => O(n/2), SC => O(1)
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
