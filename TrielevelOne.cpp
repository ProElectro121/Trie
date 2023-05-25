A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

class Node {
public:
    Node* link[26];
    bool flag = false;

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

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            if(!node -> containsKey(word[i])) {
                node -> put(word[i]);
            }
            node = node -> get(word[i]);
        }
        node -> flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        int n = word.size();

        for(int i = 0; i < n; i++) {
            if(!node -> containsKey(word[i])) {
                return false;
            }
            node = node -> get(word[i]);
        }
        return node -> flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int n = prefix.size();

        for(int i = 0; i < n; i++) {
            if(!node -> containsKey(prefix[i])) {
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */






