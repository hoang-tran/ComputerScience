#include <iostream>
using namespace std;

class ArrayList {
private:
  int count;
  int capacity;
  int* array;
public:
  ArrayList() {
    count = 0;
    capacity = 20;
    array = new int[capacity];
  }

  bool isEmpty() {
    return count == 0;
  }

  int size() {
    return count;
  }

  bool isOutOfBound(int index) {
    return index < 0 || index >= count;
  }

  void grow() {
    capacity += 20;
    int* newArray = new int[capacity];
    for(int i = 0; i < count; i++) {
      newArray[i] = array[i];
    }
    int* oldArray = array;
    array = newArray;
    delete oldArray;
  }

  void add(int value) {
    array[count] = value;
    count++;
    if(count >= capacity) {
      grow();
    }
  }

  void insertAtIndex(int value, int index) {
    if(index < 0 || index > count) return;
    for(int i = count; i > index; i--) {
      array[i] = array[i - 1];
    }
    array[index] = value;
    count++;
    if(count >= capacity) {
      grow();
    }
  }

  void deleteAtIndex(int index) {
    if(isOutOfBound(index)) return;
    for(int i = index; i < count - 1; i++) {
      array[i] = array[i + 1];
    }
    count--;
  }

  int at(int index) {
    if(isOutOfBound(index)) return -1;
    return array[index];
  }

  void print() {
    for(int i = 0; i < count; i++) {
      cout << array[i] << " ";  
    }
  }
};

int main() {
  ArrayList* list = new ArrayList();
  for(int i = 0; i < 100; i++) {
    list->insertAtIndex(i, 0);
  }
  cout << "Size: " << list->size() << endl;
  list->print();
  return 0;
}
