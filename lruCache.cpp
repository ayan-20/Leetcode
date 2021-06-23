//Source : https://leetcode.com/problems/lru-cache/
//Author : Ayan Agrawal
//Date   : 23-06-2021


//Maintain a doubly linked list and a map
//doubly linked list has two nodes head and tail
//key value are add from head and deleted from tail
//doubly linked list deletes and adds in O(1). So this is used.

class LRUCache {
public: 
    class doublyLinkedListNode{
        public:
            int key; 
            int val;
            doublyLinkedListNode* next;
            doublyLinkedListNode* prev;
        doublyLinkedListNode(int key1, int val1){
            key = key1;
            val = val1;
        }
    };
    
    doublyLinkedListNode* head = new doublyLinkedListNode(-1,-1);
    doublyLinkedListNode* tail = new doublyLinkedListNode(-1,-1);
    
    int given_capacity;
    unordered_map<int, doublyLinkedListNode*> ump;
    
    LRUCache(int capacity) {
        given_capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(doublyLinkedListNode* new_node){
        
        doublyLinkedListNode* temp = head->next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }
    
    void deleteNode(doublyLinkedListNode* delete_node){
        doublyLinkedListNode* delete_prev = delete_node->prev;
        doublyLinkedListNode* delete_next = delete_node->next;
        delete_prev->next = delete_next;
        delete_next->prev = delete_prev;
    }
    int get(int key1) {
        if(ump.find(key1)!=ump.end())
        {
            doublyLinkedListNode* result_node = ump[key1];
            int ans = result_node->val;
            ump.erase(key1);
            deleteNode(result_node);
            addNode(result_node);
            ump[key1] = head->next;
            return ans;
        }
        else return -1;
    }
    
    void put(int key1, int value) {
        if(ump.find(key1)!=ump.end())
        {
            doublyLinkedListNode* existing_node = ump[key1];
            ump.erase(key1);
            deleteNode(existing_node);
        }
        if(ump.size()==given_capacity)
        {
            ump.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        doublyLinkedListNode* node_to_add = new doublyLinkedListNode(key1,value);
        addNode(node_to_add);
        ump[key1] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */