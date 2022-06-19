#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    struct Trie *children[26];
    bool isWordEnd;
};

struct Trie *getNode()
{
    Trie *node = new Trie();

    node->isWordEnd = false;
    for (int i = 0; i < 26; i++)
    {
        node->children[i] = null;
    }

    return node;
}

void insert(Trie *root, string key)
{
    Trie *pCrawl = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        {
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isWordEnd = true;
}

bool search(Trie *root, string key)
{
    Trie *pCrawl = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        {
            return false;
        }

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isWordEnd);
}

bool isEmpty(Trie *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i])
        {
            return false;
        }
    }
    return true;
}

Trie *remove(Trie *root, string key, int depth)
{
    if (!root)
    {
        return NULL;
    }

    if (depth == key.size())
    {
        if (root->isWordEnd)
        {
            root->isWordEnd = false;
        }

        if (isEmpty(root))
        {
            delete root;
            root = NULL;
        }
        return root;
    }

    int index = key[depth] - '0';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isWordEnd == false)
    {
        delete root;
        root = NULL;
    }

    return root;
}

int main()
{
}