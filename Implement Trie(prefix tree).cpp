Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.


**************************
class Trie {
public:
    // time=0(n),n=len of word
    /** Initialize your data structure here. */
    /*
    this part to initialize a struct
    struct TrieNode{               // this node we made
        bool isend;
        TrieNode* children[26];
          
    };
    TrieNode* root;
  
    Trie() {                  // this trie was given originally
       root=new TrieNode();      
    }
    */
  
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* pcrawl=root;
        for(char c:word)
        {
            if(pcrawl->children[c-'a']==NULL)
                pcrawl->children[c-'a']=new TrieNode();
            
            pcrawl=pcrawl->children[c-'a'];
        }
        pcrawl->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* pcrawl=root;
        for(char c:word)
        {
            if(pcrawl->children[c-'a']==NULL)
                return false;
            
            pcrawl=pcrawl->children[c-'a'];
        }
        if(pcrawl->isend==true)
            return true;
        
        return false;
            
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
          TrieNode* pcrawl=root;
        for(char c:prefix)
        {
            if(pcrawl->children[c-'a']==NULL)
                return false;
            
            pcrawl=pcrawl->children[c-'a'];
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
