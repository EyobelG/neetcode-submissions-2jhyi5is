class WordDictionary {
    struct Node {
        Node* children[26];
        bool isEndOfWord;
        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEndOfWord = false;
        }
    };
public:
    Node* root;
    WordDictionary() {
        root = new Node();
        
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            int index = c  - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
        
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }

    bool dfs(string& word, int j, Node* curr) {
        for (int i = j; i < word.length(); i++ ) {
            char c = word[i];
            if (c == '.') {
                for (int k = 0; k < 26; k++) {
                    if (curr->children[k] != nullptr) {
                        if ((dfs(word, i + 1, curr->children[k]))) {
                            return true;
                        }
                    }
                }
                return false;

            } else {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    return false;
                }
                curr = curr->children[index];
            }
        }
        return curr->isEndOfWord;
    }
    
};
