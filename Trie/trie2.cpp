#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    Node *children[26];
    int countPrefix = 0;
    int countEndWith = 0;

    bool containsKey(char ch)
    {
        return children[ch - 'a'];
    }

    Node *get(char ch)
    {
        return children[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        children[ch - 'a'] = node;
    }

    void increaseEnd()
    {
        countEndWith++;
    }

    void increasePrefix()
    {
        countPrefix++;
    }

    void deleteEnd()
    {
        countEndWith--;
    }

    void reducePrefix()
    {
        countPrefix--;
    }

    int getEnd()
    {
        return countEndWith;
    }
    int getPrefix()
    {
        return countPrefix;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (auto it : word)
        {
            if (!node->containsKey(it))
            {
                node->put(it, new Node());
            }

            node = node->get(it);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (auto it : word)
        {
            if (node->containsKey(it))
            {
                node = node->get(it);
            }
            else
            {
                return 0;
            }
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (auto it : word)
        {
            if (node->containsKey(it))
            {
                node = node->get(it);
            }
            else
            {
                return 0;
            }
        }

        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (auto it : word)
        {
            if (node->containsKey(it))
            {
                node = node->get(it);
                node->reducePrefix();
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
}

int
main()
{
}