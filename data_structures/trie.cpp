/* An implementation of Trie */

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

typedef struct Trie Trie;

struct Trie {
    bool isEnd;
    Trie* children[ALPHABET_SIZE];

    Trie();
    void insert(string key);
    bool search(string key);
};

Trie::Trie() {
    isEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = NULL;
    }
}

void Trie::insert(string key) {
    Trie* cur_node = this;

    for (int i = 0; i < key.length(); i++) {
        int alphabet_i = key[i] - 'a';
        if (!cur_node->children[alphabet_i]) {
            cur_node->children[alphabet_i] = new Trie();
        }
        cur_node = cur_node->children[alphabet_i];
    }
    cur_node->isEnd = true;
}

bool Trie::search(string key) {
    Trie* cur_node = this;

    for (int i = 0; i < key.length(); i++) {
        int alphabet_i = key[i] - 'a';
        if (!cur_node->children[alphabet_i]) {
            return false;
        }
        cur_node = cur_node->children[alphabet_i];
    }
    return cur_node != NULL && cur_node->isEnd;
}

int main() {
    string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys) / sizeof(keys[0]);

    Trie *root = new Trie();

    // Construct trie
    for (int i = 0; i < n; i++)
        root->insert(keys[i]);

    // Search for different keys
    root->search("the") ? cout << "Yes\n" : cout << "No\n";
    root->search("these") ? cout << "Yes\n" : cout << "No\n";
    std::cin.ignore();
    return 0;
}
