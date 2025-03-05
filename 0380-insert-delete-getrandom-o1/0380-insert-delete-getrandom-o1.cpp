class RandomizedSet {
public:
    vector<int> elements;
    unordered_map<int, int> indMap;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indMap.count(val))   
            return false;

        elements.push_back(val);
        indMap[val]=elements.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(!indMap.count(val))   
            return false;

        int delInd=indMap[val];
        int lastEle=elements.back();
        int lastInd=elements.size()-1;
        swap(elements[delInd], elements[lastInd]);

        indMap[lastEle]=delInd;

        return true;
    }
    
    int getRandom() {
        int n=elements.size();
        if(n==1)
            return elements[0];

        return elements[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */