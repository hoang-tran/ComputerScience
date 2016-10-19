#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &array, int indexA, int indexB) {
  int temp = array[indexA];
  array[indexA] = array[indexB];
  array[indexB] = temp;
}

void selectionSort(vector<int> &array) {
  int size = array.size();
  for(int i = 0; i < size - 1; i++) {
    int min = array[i];
    int minIndex = i;
    for(int j = i + 1; j < size; j++) {
      if(array[j] < min) {
        min = array[j];
        minIndex = j;
      }
    }
    swap(array, i, minIndex);
  }
}

void printArray(vector<int> array) {
  for(vector<int>::iterator it = array.begin(); it != array.end() - 1; it++) {
    cout << *it << ",";
  }
  cout << *(array.end() - 1) << endl;
}

vector<int> sampleArray() {
  int a[] = { 2, 1, 6, 4, 5, 3 };

  vector<int> array;
  for(int i = 0; i < 6; i++) {
    array.push_back(a[i]);
  }
  return array;
}

int main() {
  vector<int> array = sampleArray();
  selectionSort(array);
  printArray(array);
  return 0;
}
