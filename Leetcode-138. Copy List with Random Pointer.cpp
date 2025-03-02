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
            if(head==NULL){
                return NULL;
            }
            unordered_map<Node*, Node*>mp;
            Node* newHead = new Node(head->val);
            Node* oldTmp=head->next;
            Node* newTmp = newHead;
            mp[head]=newHead;
    
            while(oldTmp!=NULL){
                Node* copyNode=new Node(oldTmp->val);
                mp[oldTmp]=copyNode;
                newTmp->next=copyNode;
                oldTmp=oldTmp->next;
                newTmp=newTmp->next;
    
            }
    
            oldTmp=head;
            newTmp=newHead;
            while(oldTmp!=NULL){
                newTmp->random=mp[oldTmp->random];
                oldTmp=oldTmp->next;
                newTmp=newTmp->next;
    
            }
            return newHead;
        }
    };