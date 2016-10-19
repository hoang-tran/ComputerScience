#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &array, int indexA, int indexB) {
  int temp = array[indexA];
  array[indexA] = array[indexB];
  array[indexB] = temp;
}

int partition(vector<int> &array, int start, int end) {
  int pivot = array.at(end);
  int pivotIndex = 0;
  for(int i = 0; i < end; i++) {
    if(array.at(i) <= pivot) {
      swap(array, i, pivotIndex);
      pivotIndex++;
    }
  }
  swap(array, pivotIndex, end);
  return pivotIndex;
}

void quickSort(vector<int> &array, int start, int end) {
  if(start >= end) return;

  int partitionIndex = partition(array, start, end);
  quickSort(array, start, partitionIndex - 1);
  quickSort(array, partitionIndex + 1, end);
}

void quickSort(vector<int> &array) {
  quickSort(array, 0, array.size() - 1);
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
  quickSort(array);
  printArray(array);
  return 0;
}
