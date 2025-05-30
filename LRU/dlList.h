struct Node
{
    int val, key;
    Node *prev;
    Node *next;

    Node(int _val, int _key)
    {
        val = _val;
        key = _key;
        prev = nullptr;
        next = nullptr;
    }

    Node(int _val, int _key, Node *_next, Node *_prev)
    {
        val = _val;
        key = _key;
        next = _next;
        prev = _prev;
    }
};

class DLList
{
private:
    int _size;
    Node *head;
    Node *tail;

public:
    DLList()
    {
        _size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    Node *addEleInFront(int _val, int _key)
    {
        Node *temp = new Node(_val, _key, head->next, head);
        head->next->prev = temp;
        head->next = temp;
        _size++;

        return temp;
    }

    void moveToFront(Node *_node)
    {
        _node->prev->next = _node->next;
        _node->next->prev = _node->prev;

        _node->next = head->next;
        _node->prev = head;
        head->next->prev = _node;
        head->next = _node;
    }

    int removeLastEleFromList()
    {
        Node *temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        _size--;
        int key = temp->key;
        delete temp;
        return key;
    }

    int size() { return _size; }
};