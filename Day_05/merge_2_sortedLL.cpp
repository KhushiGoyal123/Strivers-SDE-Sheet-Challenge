Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // optimal => TC -> O(N1 + N2), SC => O(1) =>
    // in-place merging by breaking bonds
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (first->data > second->data)
        swap(first, second);
    Node<int> *res = first;

    while (first != NULL && second != NULL)
    {
        Node<int> *temp = NULL;
        while (first != NULL && first->data <= second->data)
        {
            temp = first;
            first = first->next;
        }
        temp->next = second;
        swap(first, second);
    }
    return res;
}