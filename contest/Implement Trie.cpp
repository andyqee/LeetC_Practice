//
//  Implement Trie.cpp
//  contest
//
//  Created by andy on 8/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <set>

//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        unordered_map<char, TrieNode> map;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string s) {
        insert(root, s, 0);
    }
    
    // Returns if the word is in the trie.
//    bool search(string key) {
//        
//    }
//    
//    // Returns if there is any word in the trie
//    // that starts with the given prefix.
//    bool startsWith(string prefix) {
//        
//    }
    
private:
    TrieNode* root;
    
    void insert(TrieNode* node, string s, int d) {
        if (node == NULL) {
            node = new TrieNode();
        }
        if (d == s.length()) {
            // we can set value here
            
            return;
        }
        char c = s[d];
        
    }
    
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
