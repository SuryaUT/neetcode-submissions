class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}

};

class LRUCache {

private:
    int cap;
    int size;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    
    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        right->prev = node;
        node->next = right;
        node->prev = prev;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        size = 0;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            cache[key]->val = value;
            return;
        }

        if(size >= cap){
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
            size--;
        }

        Node* newNode = new Node(key,value);
        insert(newNode);
        cache[key] = newNode;
        size++;
    }
};
