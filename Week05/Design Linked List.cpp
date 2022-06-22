//TC : O(n) for all functions where n is the max length of linked list
//SC : O(1)
class Node{
public:
    int value;
    Node* next;
    Node(int val, Node* nxt){
        value = val;
        next = nxt;
    }
};
class MyLinkedList {
public:
    Node* head = new Node(0, NULL);
    int size = 0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index >= size) return -1;
        Node* curr = head->next;
        for(int i = 0; i < index; i++){
            curr = curr -> next;
        }
        return curr -> value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        Node* NewNode = new Node(val, NULL);
        Node* curr = head;
        for(int i = 0; i < index; i++){
            curr = curr -> next;
        }
        NewNode -> next = curr -> next;
        curr -> next = NewNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size)return;
        Node* curr = head;
        for(int i = 0; i < index; i++){
            curr = curr -> next;
        }
        Node* dumpNode = curr -> next;
        curr -> next = curr-> next -> next;
        delete(dumpNode);
        size--;
    }
};