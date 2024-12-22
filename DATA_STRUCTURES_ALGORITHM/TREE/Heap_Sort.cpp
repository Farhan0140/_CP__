#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Heap {
    public:
      vector<int> v;
      Heap() {

      }

      void Up_heapify(int index) {          
          while(index > 0 && v[index] > v[(index-1) / 2]) {
              swap(v[index], v[(index-1) / 2]);
              index = (index-1) / 2;
          }
      }

      void Down_heapify(int index) {
          while(true) {
              int LargestIndex = index;
              int l = (index*2) + 1;
              int r = (index*2) + 2;

              if(l < v.size() && v[LargestIndex] < v[l]) { LargestIndex = l; }
              if(r < v.size() && v[LargestIndex] < v[r]) { LargestIndex = r; }
              
              if(index == LargestIndex) { break; }

              swap(v[LargestIndex], v[index]);
              index = LargestIndex;
          }
      }

      void Push(int val) {
          v.push_back(val);
          Up_heapify(v.size() - 1);
      }

      void Pop(int index) {
          swap(v[index], v[v.size()-1]); v.pop_back();
          Down_heapify(index);
      }

      void ArrayToHeap(vector<int> &arr) {
          v = arr;

          int NonLeafNode = (v.size() / 2) - 1;
          for(int i=NonLeafNode; i >= 0; i--) {
              Down_heapify(i);
          }
      }

      int Top() { return v[0]; }
      bool Empty() { if(v.size() == 0) { return true; } else { return false; } }

      void Print() {
          for(auto it : v) { cout << it << " "; }
          cout << endl;
      }
};

//_______________________________________________________________________________________________


int main(){
    Heap heap;
    // heap.Push(12);
    // heap.Push(124);
    // heap.Push(122);
    // heap.Push(212);
    // heap.Push(112);
    // heap.Push(6);
    // heap.Push(11);

    // cout << heap.Top() << endl;
    // heap.Print();
    // heap.Pop(0);
    // heap.Pop(1);

    vector<int> v = {5,3,6,1,2,8,9,11,34,12};
    heap.ArrayToHeap(v);

    while(!heap.Empty()) {
        cout << heap.Top() << " ";
        heap.Pop(0);
    }
    return 0;
}


//_______________________________________________________________________________________________