

#define NUM_LETTERS 26

struct TrieNode { 
  vector<TrieNode*> next;
  bool isEndOfWord;
  int val;
  
  TrieNode() : next(vector<int>(NUM_LETTERS, nullptr)), isEndOfWord(false), val(-1) {}
};


class Trie {

    TrieNode* root;
    
    public:
    Trie() : root(nullptr) {}
    
    bool insert(string word) {
      if(!root)
        root = new TrieNode();
      TrieNode* it = root;

      for(int i=0; i < word.size(); ++i) {
        if(it->next[word[i] - 'a'] == nullptr) {
          it->next[word[i] - 'a'] = new TrieNode();
        }
        it = it->next[word[i] - 'a']
      }
      
      if(!it->isEndOfWord {
        it->isEndOfWord = true;
        return true;
      }
      return false;
    }
    
    bool search(string word) {
      if(!root) return false;
      TrieNode *it = root;
      
      for(const char& c : word) {
        if(!it->next[c - 'a'])
          return false;
        it = it->next[c - 'a'];
      }
      
      return it->isEndOfWord;
    }
    
    bool remove(string word) {
      if(!root) return false;
      TrieNode *it = root;
      stack<TrieNode*> path;
      for(const char& c : word) {
        if(!it->next[c - 'a'])
          return false;
        path.push(it);
        it = it->next[c - 'a'];
      }
      
      if(!it->isEndOfWord)
        return false;
      if(it.hasNext()) {
        curr_it->isEndOfWord = false;
        return true;
      }
      
      
      while(!path.empty()) {
        TrieNode *curr_it = path.top();
        path.pop();
        curr_it
        if(curr_it.hasNext()) {
          return true;
        }
      }
      
      // TODO complete this
      
    }
     
    ~Trie() {
      // TODO
    }

};


