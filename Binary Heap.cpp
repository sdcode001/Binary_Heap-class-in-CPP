#include<bits/stdc++.h>
#include <vector>
using namespace std;
//here we work with array representation of binary tree not linked list representation
//we take an binary tree as array and make it into binary_heap
class Binary_Heap{
  int size=0; //size of heap initially 0
  vector<int> heap; //as the size of heap is not ststic here so we use vector insted of array

public:
  Binary_Heap(int array[],int n){
    //copying all element of array to heap vector then we make it heap using inplace method
    //here we create max heap.
    //here we fill heap[0]=0; because we start from index 1.
    size=n+1;
    heap.push_back(0);
    for(int i=0;i<n;i++){
      heap.push_back(array[i]);
    }
// assuming frist element(heap[1]) is already in the heap.
  for(int i=2;i<=n;i++){
    int temp=heap[i];
    int j=i;
    while(j>1 && heap[j]>heap[j/2]){
      heap[j]=heap[j/2];
      heap[j/2]=temp;
      j=j/2;}
    }
  }

  void display_Heap(){
    for (auto i = heap.begin()+1; i != heap.end(); ++i){
        cout << *i << " ";
    }
  }

  void insert_Heap(int a){
    heap.push_back(a);
    size++;
    int j=size-1;
    int temp=a;
    while(j>1 && heap[j]>heap[j/2]){
      heap[j]=heap[j/2];
      heap[j/2]=temp;
      j=j/2;
    }

  }

//in heap only deletion of root element(heap[0]) is possible because deletion of other element makes heap incomplete binary tree.
//here using delete function we can only delete root element and adjust the heap to maintain maxHeap property.
int delete_Heap(){
  int result=heap[1];
  heap[1]=heap[size-1];
  heap.pop_back();
  size--;
  int i=1;
  int j;
  if(heap[2*i]>=heap[2*i+1]){j=2*i;}
  else{j=2*i+1;}
  int temp=heap[1];
  while(j<size){

    heap[i]=heap[j];
    heap[j]=temp;
    i=j;
    if(heap[2*i]>=heap[2*i+1]){j=2*i;}
    else{j=2*i+1;}
  }
  return result;
}
//heap sort is nothing but storing the deleted element from heap one by one and storing is done in one before another fashion.
//in heap sort for max heap we get an decending array and for min heap we will get ascending array.
vector<int> heap_sort(){
  vector<int> result;
  while(size!=1){
    result.push_back(delete_Heap());
  }
  return result;
}



};
int main(){
 int list[7]={10,20,30,25,5,40,35};
 Binary_Heap bh(list,7);
 bh.insert_Heap(50);
 //bh.delete_Heap();
 //bh.display_Heap();
vector<int> sort_res=bh.heap_sort();
for (auto i = sort_res.begin(); i != sort_res.end(); ++i){
        cout << *i << " ";
}




  return 0;
}
