// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T>
class TPQueue {
     private:
    struct Node {
        T value;
        Node* next;
    };
    Node* head;
     public:
    TPQueue() : head(nullptr) {}
    void push(const T& item);
    T pop();
};

template<typename T>
void TPQueue<T>::push(const T& item) {
    if (head == NULL) {
        Node* temp = new Node;
        temp->value = item;
        temp->next = NULL;
        head = temp;
    } else {
        Node* cur1 = head;
        Node* cur2 = new Node;
        int count = 0;
        while (cur1) {
            if (cur1->value.prior < item.prior) {
                break;
            } else {
                cur1 = cur1->next;
                count++;
            }
        }
        if (count == 0) {
            cur2->next = head;
            cur2->value = item;
            head = cur2;
        } else {
            cur1 = head;
            for (int i = 1; i < count; i++) {
                cur1 = cur1->next;
            }
            cur2->next = cur1->next;
            cur2->value = item;
            cur1->next = cur2;
        }
    }
}

template<typename T>
T TPQueue<T>::pop() {
    if (head == NULL) {
        throw std::string("Empty!");
    } else {
        T item = head->value;
        Node* cur = head->next;
        delete head;
        head = cur;
        return item;
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
