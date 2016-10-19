#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* next;

  ~Node() {
  }

  Node() {
    next = NULL;
  }

  Node(int _data) {
    data = _data;
    next = NULL;
  }
};

class LinkedList {
public:
  Node* head;

  LinkedList() { head = NULL; }
  ~LinkedList() {
    Node* node = this->head;
    while(node != NULL) {
      Node* currentNode = node;
      node = node->next;
      delete currentNode;
    }
  }
  
  static LinkedList* sampleList() {
    LinkedList* list = new LinkedList();
    int a[] = { 0, 1, 2, 3, 4, 5, 6 , 7, 8 };
    Node* lastNode = NULL;
    for(int i = 0; i < 9; i++) {
      Node* node = new Node(a[i]);
      if(lastNode == NULL) {
        list->head = node;
      } else {
        lastNode->next = node;
      }
      lastNode = node;
    }
    return list;
  }

  void print() {
    Node* node = this->head;
    while(node != NULL) {
      cout << node->data << " ";
      node = node->next;
    }
  }

  void insertHead(int value) {
    Node* node = new Node(value);
    node->next = this->head;
    this->head = node;
  }

  void insertTail(int value) {
    Node* node = new Node(value);
    if(this->head == NULL) {
      this->head = node;
    } else {
      Node* lastNode = this->head;
      while(lastNode->next != NULL) {
        lastNode = lastNode->next;
      }
      lastNode->next = node;
    }
  }

  void insertAtIndex(int value, int index) {
    if(index < 0) return;

    if(index == 0) {
      insertHead(value);
      return;
    }

    Node* newNode = new Node(value);
    int count = 0;
    if(this->head == NULL) {
      this->head = newNode;
    } else {
      Node* node = this->head;
      while(node->next != NULL && count < index - 1) {
        node = node->next;
        count++;
      }
      newNode->next = node->next;
      node->next = newNode;
    }  
  }


  bool isEmpty() {
    return this->head == NULL;
  }

  void reverse() {
    if(this->isEmpty()) return;

    Node* prev = NULL;
    Node* cur = this->head;
    Node* next = NULL;
    while(cur != NULL) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    this->head = prev;
  }

  void removeHead() {
    if(isEmpty()) return;
    Node* head = this->head;
    this->head = head->next;
    head->next = NULL;
    delete head;
  }

  void removeAtIndex(int index) {
    if(index < 0) return;
    if(index == 0) {
      removeHead();
      return;
    }
    int count = 0;
    Node* node = this->head;
    Node* prevNode = NULL;
    while(node != NULL && count < index) {
      prevNode = node;
      node = node->next;
      count++; 
    }
    if(node == NULL) return;
    prevNode->next = node->next;
    node->next = NULL;
    delete node;
  }
};

int main() {
  LinkedList* list = LinkedList::sampleList();
  list->reverse();
  list->print();
  delete list;
  return 0;
}
