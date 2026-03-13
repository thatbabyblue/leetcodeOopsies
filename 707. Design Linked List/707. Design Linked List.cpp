/*
 * Problem: 707. Design Linked List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/design-linked-list/submissions/1946603875/
 * Language: cpp
 * Date: 2026-03-13
 */

class MyLinkedList {
private:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int x) : val(x), next(nullptr) {}
    };
    int size;
    LinkedNode* dummy;
public:
    MyLinkedList() {
        size = 0;
        dummy = new LinkedNode(0);
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        LinkedNode* cur = dummy->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = dummy->next;
        dummy->next = node;
        size++;    
    }
    
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = dummy;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = dummy;
        while (index--) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        LinkedNode* cur = dummy;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
