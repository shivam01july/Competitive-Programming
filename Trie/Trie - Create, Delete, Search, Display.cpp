/*************************************************************/
/*          Trie - Create, Delete, Search, Display           */
/*************************************************************/

#include <iostream>

using namespace std;

#define ALPHABET_SIZE 26


struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool endofWord;
    
    TrieNode()
    {
        endofWord = false;
        for(int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
    
    bool containKey(char ch)
    {
        if(children[ch - 'a'] != NULL)
            return true;
        return false;    
    }
    
    void setEnd()
    {
        endofWord = true;
    }
    
    void resetEnd()
    {
        endofWord = false;
    }
    
    bool isEnd()
    {
        return endofWord;
    }
    
    void put(char ch, TrieNode* node)
    {
        children[ch - 'a'] = node;
    }
    
    TrieNode* get(char ch)
    {
        return children[ch - 'a'];
    }
    
    bool isEmpty(TrieNode* node)
    {
        for(int i = 0; i < ALPHABET_SIZE; i++)
        {
            if(children[i])
                return false;
        }
        return true;
    }
};


class Trie
{
  private:
    TrieNode* root = NULL;
    
    
  public:
    Trie()
    {
        root = new TrieNode;
    }
    
    
    void printAllWord(TrieNode* root, char* str, int pos)
    {
        if(root->isEnd())
        {
            str[pos] = '\0';
            cout << str << " ";
        }
        
        for(int i = 0; i < ALPHABET_SIZE; i++)
        {
            if(root->children[i])
            {
                str[pos] = i + 'a';
                printAllWord(root->children[i], str, pos+1);
            }
        }
    }
    
    
    void _display()
    {
        char str[25];
        printAllWord(root, str, 0);
    }
    
    
    void _insert(string word)
    {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containKey(word[i]))
            {
                node->put(word[i], new TrieNode);
            }
            
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }
    
    
    TrieNode* removeWord(TrieNode* root, string key, int depth)
    {
        // If tree is empty
        if(!root)
            return NULL;
            
        // If last character of key is being processed
        if(depth == key.length())
        {
            // This node is no more end of word after removal of given key
            if(root->isEnd())
                root->resetEnd();
                
            // If given is not prefix of any other word
            if(root->isEmpty(root))
            {
                delete root;
                root = NULL;
            }
            
            return root;
        }
        
        
        // If not last character, recur for the child obtained using ASCII value
        int index = key[depth] - 'a';
        root->children[index] = removeWord(root->children[index], key, depth+1);
        
        // If root does not have any child (its only child got deleted), and it is not end of another word.
        if (root->isEmpty(root) && !root->isEnd()) 
        {
            delete root;
            root = NULL;
        }
 
        return root;
    }
    
    
    void _delete(string word)
    {
        removeWord(root, word, 0);
    }
    
    
    bool _search(string word)
    {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containKey(word[i]))
            {   
                return false;
            }
            
            node = node->get(word[i]);
        }
        
        if(node->isEnd())
            return true;
        else
            return false;    
    }
    
    
    bool _startsWith(string prefix)
    {
        TrieNode* node = root;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(!node->containKey(prefix[i]))
            {   
                return false;
            }
            
            node = node->get(prefix[i]);
        }
        
        return true;
    }
};



int main()
{
    Trie trie;
    
    trie._insert("apple");
    trie._insert("apps");
    trie._insert("apnl");
    trie._insert("bac");
    trie._insert("bat");
    
    cout << "Trie: ";
    trie._display();
    cout << endl;

    
    trie._delete("bat");
    cout << "Trie: ";
    trie._display();
    cout << endl;
  
    string str;  
        
    str = "apps";
    if(trie._search(str))
        cout << str << " is found in Trie" << endl;
    else
        cout << str << " is not found in Trie" << endl;
    
    str = "appl";    
    if(trie._search(str))
        cout << str << " is found in Trie" << endl;
    else
        cout << str << " is not found in Trie" << endl;
    
    str = "bac";    
    if(trie._search(str))
        cout << str << " is found in Trie" << endl;
    else
        cout << str << " is not found in Trie" << endl;    
    
    str = "bae";    
    if(trie._search(str))
        cout << str << " is found in Trie" << endl;
    else
        cout << str << " is not found in Trie" << endl;    
        
    
        
    str = "appl"; 
    if(trie._startsWith(str))
        cout << str << " prefix is found in Trie " << endl;
    else
        cout << str << " prefix is not found in Trie" << endl;    
    
    str = "bae";     
    if(trie._startsWith(str))
        cout << str << " prefix is found in Trie " << endl;
    else
        cout << str << " prefix is not found in Trie" << endl;      
    

    return 0;
}
