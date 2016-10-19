#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &array, int indexA, int indexB) {
  int temp = array[indexA];
  array[indexA] = array[indexB];
  array[indexB] = temp;
}

void printArray(vector<int> array) {
  for(vector<int>::iterator it = array.begin(); it != array.end() - 1; it++) {
    cout << *it << ",";
  }
  cout << *(array.end() - 1) << endl;
}

vector<int> sampleArray() {
  int a[] = { 2, 7, 1, 15, 6, 4, 16, 13, 5, 3, 12, 9, 11, 8, 0, 10, 14 };

  vector<int> array;
  for(int i = 0; i < 17; i++) {
    array.push_back(a[i]);
  }
  return array;
}

void insertionSort(vector<int> &array) {
  int size = array.size();
  for(int i = 1; i < size; i++) {
    int holeValue = array[i];
    int holeIndex = i;
    for(int j = i - 1; j >= 0; j--) {
      if(holeValue < array[j]) {
        swap(array, holeIndex, j);
        holeIndex--;
      }
    }
  }
}

int main() {
  vector<int> array = sampleArray();
  insertionSort(array);
  printArray(array);
  return 0;
}
