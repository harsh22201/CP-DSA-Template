// prefix tree
#include <string>
using namespace std;

#define ALPHABET_SIZE 26
class Trie
{
private:
    bool isword;
    Trie *child[ALPHABET_SIZE];

public:
    Trie()
    {
        this->isword = false;
        for (auto &i : child)
            i = NULL;
    }

    void insert(string word) // O(|word|)
    {
        Trie *curtrie = this;
        for (auto chr : word)
        {
            int pos = chr - 'a';
            if (curtrie->child[pos] == NULL)
                curtrie->child[pos] = new Trie();
            curtrie = curtrie->child[pos];
        }
        curtrie->isword = true;
    }

    bool search(string word, bool prefix = false) // O(|word|) //search for a full word or prefix
    {
        Trie *curtrie = this;
        for (auto chr : word)
        {
            int pos = chr - 'a';
            if (curtrie->child[pos] == NULL)
                return false;
            curtrie = curtrie->child[pos];
        }
        return prefix || curtrie->isword;
    }

    bool empty()
    {
        for (auto i : child)
            if (i != NULL)
                return false;
        return true;
    }
};
