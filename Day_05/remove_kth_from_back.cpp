Node *removeKthNode(Node *head, int K)
{
    Node *start = new Node();
    start->next = head;
    Node *slow = start, *fast = start;

    for (int i = 1; i <= K; ++i)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *todelete = slow->next;
    slow->next = slow->next->next;
    delete todelete;

    return start->next;
}