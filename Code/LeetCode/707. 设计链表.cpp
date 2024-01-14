// my solution
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int val):val(val), next(nullptr) {}
    };

    MyLinkedList() {
        int val;
        virtualhead_ = new LinkedNode(0);  // 创建虚拟头节点
        size_ = 0;
    }
    
    int get(int index) {
        if((index < 0) || (index >= size_)) {
            return -1;
        }
        LinkedNode *target = virtualhead_;
        while(index > -1) {
            target = target->next;
            index--;
        }
        return target->val;
    }
    
    void addAtHead(int val) {
        LinkedNode *target =  new LinkedNode(val);
        target->next = virtualhead_->next;
        virtualhead_->next = target;
        size_++;
    }
    
    void addAtTail(int val) {
        LinkedNode *target =  new LinkedNode(val);
        LinkedNode *cur = virtualhead_;
        while(cur->next!=nullptr) {
            cur = cur->next;
        }
        cur->next = target;
        target->next = nullptr;
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        LinkedNode *target =  new LinkedNode(val);
        LinkedNode *cur = virtualhead_;
        if(index > size_)
            return;
        while(index > 0) {
            cur = cur->next;
            index--;
        }
        target->next = cur->next;
        cur->next = target;
        size_++;
    }
    
    void deleteAtIndex(int index) {
        if((index < 0) || (index >= size_)) {
            return;
        }
        LinkedNode *cur = virtualhead_;
        while(index > 0) {
            cur = cur->next;
            index--;
        }
        LinkedNode *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        size_--;
    }

    private:
        LinkedNode *virtualhead_;
        int size_;
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
