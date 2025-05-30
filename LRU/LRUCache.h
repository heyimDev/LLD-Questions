#include "dlList.h"
#include <unordered_map>

using namespace std;

class LRUCache
{
private:
    DLList *dl;
    int size;
    unordered_map<int, Node *> keyNodeHashMap;

public:
    LRUCache(int _size)
    {
        size = _size;
        dl = new DLList();
    }

    void put(int _key, int _value)
    {
        if (keyNodeHashMap.find(_key) != keyNodeHashMap.end())
        {
            keyNodeHashMap[_key]->val = _value;
            dl->moveToFront(keyNodeHashMap[_key]);
        }
        else
        {
            if (size == dl->size())
            {
                keyNodeHashMap.erase(dl->removeLastEleFromList());
            }
            keyNodeHashMap[_key] = dl->addEleInFront(_value, _key);
        }
    }

    int get(int _key)
    {
        if (keyNodeHashMap.find(_key) == keyNodeHashMap.end())
        {
            return -1;
        }
        else
        {
            dl->moveToFront(keyNodeHashMap[_key]);
            return keyNodeHashMap[_key]->val;
        }
    }
};
