#include <bits/stdc++.h> 

class Node {
public:
    Node* link[26];
    int countPrefix = 0;
    int endsWith = 0;

    bool containsKey(char ch) {
        return (link[ch - 'a'] != NULL);
    }

    void put(char ch) {
        link[ch - 'a'] = new Node();
    }

    Node* get(char ch) {
        return link[ch - 'a'];
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node;
    }

    void insert(string &word){
         int n = word.size();
         Node* node = root;
         for(int i = 0; i < n; i++) {
             char ch = word[i];
             if(!node -> containsKey(ch)) {
                 node -> put(ch);
             }
             node = node -> get(ch);
             node -> countPrefix++;
         }
         node -> endsWith++;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            char ch = word[i];
            if(!node -> containsKey(ch)) {
                return 0;
            }
            node = node -> get(ch);
        }
        return node -> endsWith;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            char ch = word[i];
            if(!node -> containsKey(ch)) {
                return 0;
            }
            node = node -> get(ch);
        }
        return node -> countPrefix;
    }

    void erase(string &word){
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            char ch = word[i];
            node = node -> get(ch);
            node -> countPrefix--;
        }
        node -> endsWith--;
    }
};
