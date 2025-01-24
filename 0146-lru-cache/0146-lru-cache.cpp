class DListNode{
    public:
    int key;
    int val;
    DListNode* next;
    DListNode* prev;
    

    DListNode(int x, int y)
    {
        key=x;
        val=y;
        next=NULL;
        prev=NULL;
    }
    DListNode()
    {
        val=0;
        key=0;
        next=NULL;
        prev=NULL;
    }
    
};
class LRUCache {
    DListNode* head;
    DListNode* tail;
    int maxcap;
    int currcap;
    unordered_map<int, DListNode*> ump;

public:
    LRUCache(int capacity) {
        head=new DListNode(-1,-1);
        tail=new DListNode(-1,-1);
        
        head->next=tail;
        tail->prev=head;
        maxcap=capacity;
        currcap=0;
    }
    
    int get(int key) {
        if(ump.find(key)==ump.end())
            return -1;
            
        DListNode* node=ump[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // exists
        if(ump.find(key)!=ump.end())
        {
            DListNode* node=remove(ump[key]);
            node->val=value;
            insert(node);
        }
        else
        {
            if(currcap==maxcap)
            {
                remove();
                currcap--;
            }
            
            DListNode* node=new DListNode(key, value);    
            insert(node);
            ump[key]=node;
            currcap++;
        }
    }
    DListNode* remove(DListNode* node)
    {
        node->next->prev=node->prev;
        node->prev->next=node->next;
        return node;
    }
    void remove()
    {
        DListNode* node=tail->prev;
        node->next->prev=node->prev;
        node->prev->next=node->next;
        ump.erase(node->key);
    }
    void insert(DListNode* node)
    {
        node->next=head->next;
        node->prev=head;
        head->next=node;
        node->next->prev=node;
    }
    

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */