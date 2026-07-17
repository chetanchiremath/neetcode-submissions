class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node() {
        key = val = -1;
        next = prev = nullptr;
    }
 
    Node(int k, int v) {
        key = k;
        val = v;
        next = prev = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* front = head->next;
        node->next = front;
        front->prev = node;
        node->prev = head;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            deleteNode(node);
            node->val = value;
            insertAfterHead(node);
            return;
        }

        if(mpp.size() == cap) {
            Node* lastNode = tail->prev;
            mpp.erase(lastNode->key);
            deleteNode(lastNode);
        }
        Node* newNode = new Node(key, value);
        mpp[key] = newNode;
        insertAfterHead(newNode);
    }
};
