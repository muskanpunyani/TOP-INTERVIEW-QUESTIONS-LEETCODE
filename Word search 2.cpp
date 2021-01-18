Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:

Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

 

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 12
    board[i][j] is a lowercase English letter.
    1 <= words.length <= 3 * 104
    1 <= words[i].length <= 10
    words[i] consists of lowercase English letters.
    All the strings of words are unique.


**********************
//Assume there are n word and each word has a length m, board has row length x and column length y

    To build the tree you need to iterate all the characters of every word once O(n*m)
    To findWord you have to visit each element in the board (x*y elements) and treat it as a starting point. In the recursive calls you
    preform a DFS on all the neighbouring node and you don't visit the nodes that have already been seen so the worst case scenario
    is you visit all the elements for each start point.

so the asymptotic runtime is O(mn + (xy)^2)

Note that why you are traversing through the trie you are only iterating the next node which is a linear operation in each recursive call.
This is not the bottleneck so we don't have to consider it in our asymptotic runtime :)

# define alphabet 26
struct Trie{
    struct Trie *children[alphabet];
    bool isend;
    string value;
};
class Solution {
public:
struct Trie* getNode(void)    // creating node
{
    struct Trie *node=new Trie;
    node->isend=false;
    for(int i=0;i<alphabet;i++)
    {
        node->children[i]=NULL;
    }
    return node;
}
void insert(struct Trie* root,string key)
{
    
    struct Trie *pcrawl=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(pcrawl->children[index]==NULL)
        {
            pcrawl->children[index]=getNode();
        }
        pcrawl=pcrawl->children[index];
    }
    pcrawl->value=key;
    pcrawl->isend=true;
}
    
    void dfs(int i, int j, Trie* head, vector<vector<char>>& board, vector<string>* out) {
        if (i >= board.size() || i < 0 || j >= board[i].size() || j < 0) return;
        
        char c = board[i][j];
        if (c == '.') return; // visited
        
        Trie* next_trie = head->children[c - 'a'];  // find char in trie
        if (next_trie == nullptr) return;          // if char not found
        
        board[i][j] = '.'; // changes board  , marking visited
        
        if (next_trie->isend && next_trie->value!="") {
            out->push_back(next_trie->value);   // insert word
            next_trie->isend = false; // changes the trie (other option is to use hashset)
        }
                                     
        dfs(i+1, j, next_trie, board, out);   // dfs in all 4 dirn
        dfs(i, j+1, next_trie, board, out);
        dfs(i-1, j, next_trie, board, out);
        dfs(i, j-1, next_trie, board, out);
        
        board[i][j] = c; // reverting board  , i.e marking unvisited
                                     
        return;
    }   
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) return vector<string>(); 
    
        struct Trie *head = getNode();
        for(int i=0;i<words.size();i++)
        {
            insert(head,words[i]);   // insert the word list in trie
        }
        
        vector<string> out;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs (i, j, head, board, &out);   // search for every char
            }
        }
        return out;
    }
};
