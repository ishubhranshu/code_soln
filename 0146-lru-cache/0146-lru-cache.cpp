class LRUCache {
public:
    list<int> cache;
    unordered_map<int, pair<list<int>:: iterator, int>> addMap;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makeMostRecent(int key)
    {
        auto node=*(addMap[key].first);
        int val=addMap[key].second;
        cache.erase(addMap[key].first);

        cache.push_front(key);

        addMap[key]={cache.begin(), val};
    }
    int get(int key) {
        if(!addMap.count(key))
            return -1;

        int val=addMap[key].second;
        makeMostRecent(key);

        return val;
    }
    
    void put(int key, int value) {
        if(addMap.count(key))
        {
            addMap[key].second=value;
            makeMostRecent(key);
            return;
        }

        if(n==cache.size())
        {
            int keyToDel=cache.back();
            cache.pop_back();
            addMap.erase(keyToDel);
        }

        cache.push_front(key);

        addMap[key]={cache.begin(), value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */