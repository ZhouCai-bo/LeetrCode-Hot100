class Trie {
public:
    int tr[100000][26]{0};
    bool tag[100000]{false};
    map<char,int> m;

    int cnt = 0;

    Trie() {
        char ch = 'a';
        for(int i=0 ; i<26 ; i++)
        {
            m.insert(pair<char,int>(ch,i));
            ch++;
        }
    }
    
    void insert(string word) {
        int curr=0;
        for(auto a: word)
        {
            if(tr[curr][m[a]] != 0)
            {
                curr = tr[curr][m[a]];
            }
            else
            {
                tr[curr][m[a]] = ++cnt;
                curr = cnt;
            }
        }
        tag[curr] = true;
    }
    
    bool search(string word) 
    {
        int curr=0;
        for(auto a: word)
        {
            if((curr = tr[curr][m[a]]) == 0)
                return false;
        }
        if(tag[curr])    
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
       int curr=0;
        for(auto a: prefix)
        {
            if((curr = tr[curr][m[a]]) == 0)
                return false;
        }
        return true;
    }
};
