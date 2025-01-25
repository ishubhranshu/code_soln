class LFUCache {
public:
    // key: add
    unordered_map<int, list<pair<int, pair<int, int>>>::iterator> keyadd;
    // freq: (key, (val, freq))
    map<int, list<pair<int, pair<int, int>>>> freqmap;
    int cap;
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    void makeFrequentlyUsed(int key)
    {
        auto nodeit=(keyadd[key]);
        int value=nodeit->second.first;
        int freq=nodeit->second.second;

        freqmap[freq].erase(nodeit);
        if(freqmap[freq].empty())
            freqmap.erase(freq);

        freq++;
        freqmap[freq].push_front({key, {value, freq}});
        keyadd[key]=freqmap[freq].begin();
    }

    int get(int key) {
        if(keyadd.find(key)==keyadd.end())
            return -1;
        
        // get value
        int val=keyadd[key]->second.first;
        // get complete node
        makeFrequentlyUsed(key);
        // return value
        return val;
    }
    
    void put(int key, int value) {
        
        if(keyadd.find(key) != keyadd.end())
        {
            keyadd[key]->second.first=value;
            makeFrequentlyUsed(key);
        }
        else
        {
            if(cap==0)
            {
                auto it=freqmap.begin();
                int keytodel=it->second.back().first;
                it->second.pop_back();
                if(it->second.empty())
                    freqmap.erase(it->first);
                
                
                keyadd.erase(keytodel);
                
            }
            else
                cap--;
            
            
            freqmap[1].push_front({key, {value, 1}});
            keyadd[key]=freqmap[1].begin();
            
        } 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */