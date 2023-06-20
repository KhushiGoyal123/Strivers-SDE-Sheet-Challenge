LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // TC => O(N)
    if (head == NULL)
        return head;

    LinkedListNode<int> *dummy = NULL;

    while (head != NULL)
    {
        LinkedListNode<int> *nex = head->next;
        head->next = dummy;
        dummy = head;
        head = nex;
    }
    return dummy;
}