/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node* ptr=head;
        // 1 Insert
        while(ptr)
        {
            Node* newNode=new Node(ptr->val);
            newNode->next=ptr->next;
            ptr->next=newNode;
            ptr=newNode->next;
        }

        ptr=head;
        // 2 Random

        while(ptr)
        {
            ptr->next->random=ptr->random==nullptr ? nullptr : ptr->random->next;
            ptr=ptr->next->next;
        }

        ptr=head;
        Node* newHead=ptr->next;
        
        // 3 Next
        while(ptr)
        {
            Node* origNext=ptr->next->next;
            ptr->next->next=origNext==nullptr ? nullptr: origNext->next;
            ptr->next=origNext;
            ptr=ptr->next;
        }

        return newHead;
    }
};