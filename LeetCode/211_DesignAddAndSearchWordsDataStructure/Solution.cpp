class Trie {
    public:
        bool isTerminal;
        unordered_map<char, Trie*> children;
        Trie() {
            isTerminal = false;
        }
};

class WordDictionary {
private:
    Trie* root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string& word) {
        Trie* cur = root;
        for(char c : word){
            if(cur->children.find(c-'a') == cur->children.end()){
                cur->children[c-'a'] = new Trie();
            }
            cur = cur->children[c-'a'];
        }
        cur->isTerminal = true;
    }

    bool isExist(string& word, int index, Trie*& cur){
        if(word.length() == index){
            return cur -> isTerminal;
        }
        char c = word[index];

        if(c=='.'){
            for(int i=0;i<26;i++){
                if(cur->children[i]!=nullptr&&isExist(word, index+1, cur->children[i])){
                    return true;
                }
            }
            return false;
        }
        else{
            if(cur->children[c-'a']==nullptr){
                return false;
            }
            return isExist(word, index+1, cur->children[c-'a']);
        }
    }
    
    bool search(string& word) {
        return isExist(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 