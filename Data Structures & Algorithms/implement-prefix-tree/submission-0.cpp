class PrefixTree {
    struct Node{
        Node* letters[26];
        bool last;

        Node(){
            last = false;
            for(int i=0; i<26; i++){
                letters[i] = nullptr;
            }
        }
    };

    Node* trie;

public:
    PrefixTree() {
        trie = new Node();
    }
    
    void insert(string word) {
        if(word == "") return;

        Node* curr = trie;

        for(char c : word){
            if(curr->letters[c-'a'] == nullptr){
                // Node* newNode = new Node();
                curr->letters[c-'a'] = new Node();
            }
            curr = curr->letters[c-'a'];
        }

        curr->last = true;
    }
    
    bool search(string word) {
        Node* curr = trie;

        for(char c : word){
            if(curr->letters[c-'a'] == nullptr) return false;

            curr = curr->letters[c-'a'];
        }

        return curr->last;
    }
    
    bool startsWith(string prefix) {
        Node* curr = trie;

        for(char c : prefix){
            if(curr->letters[c-'a'] == nullptr) return false;

            curr = curr->letters[c-'a'];
        }

        return true;
    }
};
