#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int TOP_K = 5;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEnd = false;
    int frequency = 0;
};

class Trie
{
private:
    TrieNode *root;

    struct Suggestion
    {
        string word;
        int frequency;
        bool operator<(const Suggestion &other) const
        {
            // Keep the least desirable suggestion at the top of the heap so it
            // can be removed when the heap grows beyond TOP_K.
            return frequency > other.frequency || (frequency == other.frequency && word < other.word);
        }
    };

    void dfs(TrieNode *node, string path, priority_queue<Suggestion> &pq)
    {
        if (!node)
            return;
        if (node->isEnd)
        {
            pq.push({path, node->frequency});
            if ((int)pq.size() > TOP_K)
                pq.pop(); // keep top K
        }
        for (auto &pair : node->children)
        {
            dfs(pair.second, path + pair.first, pq);
        }
    }

public:
    Trie() { root = new TrieNode(); }

    void insert(const string &word, int freq = 1)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->children.count(ch))
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEnd = true;
        node->frequency += freq;
    }

    vector<string> getSuggestions(const string &prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (!node->children.count(ch))
                return {};
            node = node->children[ch];
        }

        priority_queue<Suggestion> pq;
        dfs(node, prefix, pq);

        vector<string> result(pq.size());
        for (int i = pq.size() - 1; i >= 0; --i)
        {
            result[i] = pq.top().word;
            pq.pop();
        }
        return result;
    }
};

int main()
{
    Trie trie;

    // Load dictionary
    ifstream file("dictionary.txt");
    if (!file.is_open())
    {
        cerr << "Failed to open dictionary.txt\n";
        return 1;
    }

    string word;
    int freq;
    while (file >> word >> freq)
    {
        trie.insert(word, freq);
    }
    file.close();

    cout << "Auto-completion Engine (type prefix and press Enter, Ctrl+C to exit):\n\n";

    string input;
    while (true)
    {
        cout << ">> ";
        if (!getline(cin, input))
            break;
        if (input.empty())
            continue;

        vector<string> suggestions = trie.getSuggestions(input);
        if (suggestions.empty())
        {
            cout << "No suggestions found.\n";
        }
        else
        {
            for (const string &s : suggestions)
            {
                cout << " - " << s << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}
