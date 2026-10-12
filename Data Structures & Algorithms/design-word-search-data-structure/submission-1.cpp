class WordDictionary {
    struct Node{
        Node* children[26];
        bool lastletter;

        Node(){
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
            lastletter = false;
        }
    };

    Node* trie;

public:
    WordDictionary() {
        trie = new Node();
    }
    
    void addWord(string word) {
        Node* temp = trie;

        for(char c : word){
            if(temp->children[c-'a'] == nullptr){
                temp->children[c-'a'] = new Node();
            }
            temp = temp->children[c-'a'];
        }
        temp->lastletter = true;
    }

    bool searchWithWildCard(string word, Node* node){
        // cout<<word<<endl;
        if(node == nullptr) return false;
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(int j=0; j<26; j++){
                    if(searchWithWildCard(word.substr(i+1), node->children[j])) return true;
                }
                return false;
            }
            else{
                if(node->children[c-'a'] == nullptr) return false;
            }
            node = node->children[c-'a'];
        }

        return node->lastletter;
    }
    
    bool search(string word) {
        return searchWithWildCard(word, trie);
    }
};
