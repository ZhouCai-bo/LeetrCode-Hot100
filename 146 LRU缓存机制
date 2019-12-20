class LRUCache {

private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int , list<pair<int,int>>::iterator> m;

public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        auto key_value = *m[key];
        l.erase(m[key]);
        l.push_front(key_value);
        m[key] = l.begin();
        return key_value.second;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end())
        {
            if(cap == l.size())
            {
                m.erase(l.back().first);
                l.pop_back();
            }
        }
        else
        {
            l.erase(m[key]);
        }
        l.push_front(make_pair(key,value));
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
