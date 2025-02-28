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
        unordered_map<Node*, Node*> ump;
        Node* origPtr=head;

        while(origPtr)
        {
            Node* newNode=new Node(origPtr->val);
            ump[origPtr]=newNode;
            origPtr=origPtr->next;
        }

        origPtr=head;
        Node* copyPtr=ump[origPtr];

        while(origPtr)
        {
            copyPtr->next=ump[origPtr->next];
            copyPtr->random=ump[origPtr->random];
            origPtr=origPtr->next;
            copyPtr=copyPtr->next;
        }
        return ump[head];
    }
};