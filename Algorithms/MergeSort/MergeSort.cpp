#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> left, vector<int> right, vector<int>& destination) {
  destination.clear();
  int i,j;
  i = j = 0;
  while(i < left.size() && j < right.size()) {
    if(left[i] <= right[j]) {
      destination.push_back(left[i]);
      i++;
    } else {
      destination.push_back(right[j]);
      j++;
    }
  }
  while(i < left.size()) {
    destination.push_back(left[i]);
    i++;
  }
  while(j < right.size()) {
    destination.push_back(right[j]);
    j++;
  }
}

void mergeSort(vector<int>& array) {
  if(array.size() < 2) return;

  int mid = array.size() / 2;
  vector<int> left, right;
  for(int i = 0; i < mid; i++) {
    left.push_back(array.at(i));
  }
  for(int i = mid; i < array.size(); i++) {
    right.push_back(array.at(i));
  }
  mergeSort(left);
  mergeSort(right);
  merge(left, right, array);
}

void printArray(vector<int> array) {
  for(vector<int>::iterator it = array.begin(); it != array.end() - 1; it++) {
    cout << *it << ",";
  }
  cout << *(array.end() - 1) << endl;
}

int main() {
  int a[] = { 2, 1, 6, 4, 5, 3 };

  vector<int> array;
  for(int i = 0; i < 6; i++) {
    array.push_back(a[i]);
  }
  mergeSort(array);
  printArray(array);
  return 0;
}
