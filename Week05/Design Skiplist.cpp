//TC : O(log(N)) for all kind of operation
//SC : O(N) + log(N) Where N is the size of given list & create new log(N) Node 
class Skiplist { 
public:
    class Node
    {
        public:
            int val;
            Node *next, *down;
            Node(int v, Node* n, Node* d){
                val = v;
                next = n; 
                down = d;
            }
        };
    
    Node* head;
    const static int DUMMYVALUE = -1;
    random_device rd;
    
    Skiplist() {
        head = new Node(DUMMYVALUE, NULL, NULL);
    }
    
    bool search(int target) {
        Node* curr = head;
        while(curr)
        {
            while(curr->next && curr->next->val < target)
            {
                curr = curr->next;
            }
            if(curr->next && curr->next->val == target)return true;
            curr = curr->down;
        }
        return false;
    }
    
    void add(int target) {
        stack<Node*> path;
        Node* curr = head;
        while(curr)
        {
            while(curr->next && curr->next->val < target)
            {
                curr = curr->next;
            } 
            path.push(curr);
            curr = curr->down;
        }
        bool goUp = true;
        Node* down = NULL;
        while(goUp && !path.empty())
        {
            curr = path.top();
            path.pop();
            curr->next = new Node(target, curr->next, down);
            down = curr->next;
            goUp = (rd() % 100) < 50;
        }
        if(goUp) head = new Node(DUMMYVALUE, NULL, head);
    }
    
    bool erase(int target) {
        Node* curr = head;
        bool found = false;
        while(curr)
        {
            while(curr->next && curr->next->val < target)
            {
                curr = curr->next;
            }
            if(curr->next && curr->next->val == target)
            {
                found = true;
                auto dumpNode = curr->next;
                curr->next = curr->next->next;
                delete(dumpNode);
            }
            curr = curr->down;
        }
        return found;
    }
};
