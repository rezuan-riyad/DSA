#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(vector<int> &hT, int i){
  int size = hT.size();
  int largest = i;
  int leftChildIndex = 2*i + 1;
  int rightChildIndex = 2*i + 2;
  // condition for max heap tree
  if(leftChildIndex < size && hT[leftChildIndex] > hT[largest])
    largest = leftChildIndex;
  if(rightChildIndex < size && hT[rightChildIndex] > hT[largest])
    largest = rightChildIndex;

  if(largest != i){
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

void insert(vector<int> &hT, int newNum){
  int size = hT.size();
  if(size == 0){
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    for(int i = size/2 - 1; i >= 0; i--){
      heapify(hT, i);
    }
  }
}

void deleteNode(vector<int> &hT, int num){
  int size = hT.size();
  int i;
  for(i = 0; i < size; i++){
    if(num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);
  hT.pop_back();
  for(int j = size/2-1; j >= 0; j--){
    heapify(hT, j);
  }
}

void printArray(vector<int> &hT){
  for(int i = 0; i < hT.size(); i++){
    cout << hT[i] << " ";
  }
  cout << "\n";
}

int main(){
  vector<int> heapTree;
  insert(heapTree, 9);
  insert(heapTree, 4);
  insert(heapTree, 5);
  insert(heapTree, 1);
  insert(heapTree, 3);
  insert(heapTree, 2);
  insert(heapTree, 7);

  cout << "Max-Heap Array: ";
  printArray(heapTree);
  deleteNode(heapTree, 4);
  cout << "After deleting an element: ";
  printArray(heapTree);
  return 0;
}