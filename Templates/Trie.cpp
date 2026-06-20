#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:

    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isEnd=false;
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* curr=root;
        for(char c:word){
            int idx=c-'a';

            if(curr->children[idx]==nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->isEnd=true;
    }

    bool search(string word){
        TrieNode* curr=root;
        for(char c:word){
            int idx=c-'a';

            if(curr->children[idx]==nullptr){
                return false;
            }
            curr=curr->children[idx];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix){
        TrieNode* curr=root;
        for(char c:prefix){
            int idx=c-'a';

            if(curr->children[idx]==nullptr){
                return false;
            }
            curr=curr->children[idx];
        }
        return true;
    }

    ~Trie() {
        clear(root);
    }

private:
    void clear(TrieNode* node){
        if(node==nullptr) return;
        for(int i=0;i<26;i++){
            clear(node->children[i]);
        }
        delete node;
    }

};

