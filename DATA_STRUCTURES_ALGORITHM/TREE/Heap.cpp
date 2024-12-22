#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

/* 01 */ void Insert_in_Max_Heap(vector<int> &v, int New_Value); // TC - O(n log n)
/* 02 */ void Insert_in_Min_Heap(vector<int> &v, int New_Value); // TC - O(n log n)
/* 03 */ void Delete_in_Max_Heap(vector<int> &v); // TC - O(log n)

//_______________________________________________________________________________________________


int main(){
    vector<int> v = {50, 40, 45, 30, 35, 42, 32, 25, 20, 10};
    int n; cin >> n;

    Insert_in_Max_Heap(v, n);
    // Insert_in_Min_Heap(v, n);

    for(auto it : v) {
        cout << it << " ";
    } cout << endl;

    Delete_in_Max_Heap(v);

    for(auto it : v) {
        cout << it << " ";
    } cout << endl;

    Delete_in_Max_Heap(v);

    for(auto it : v) {
        cout << it << " ";
    } cout << endl;
    
    return 0;
}


//_______________________________________________________________________________________________

/* 01 */ void Insert_in_Max_Heap(vector<int> &v, int New_Value) {
    v.push_back(New_Value);

    int current_index = v.size()-1;
    
    while(current_index != 0) {
        int parent_index = (current_index - 1) / 2;

        if(v[parent_index] < v[current_index]) {
            swap(v[parent_index], v[current_index]);
        } else {
            break;
        }
        current_index = parent_index;
    }
}

//_______________________________________________________________________________________________

/* 02 */ void Insert_in_Min_Heap(vector<int> &v, int New_Value) { // TC - O(n log n)
    v.push_back(New_Value);

    int current_index = v.size()-1;
    
    while(current_index != 0) {
        int parent_index = (current_index - 1) / 2;

        if(v[parent_index] > v[current_index]) {
            swap(v[parent_index], v[current_index]);
        } else {
            break;
        }
        current_index = parent_index;
    }
}

//_______________________________________________________________________________________________

/* 03 */ void Delete_in_Max_Heap(vector<int> &v) {
    v[0] = v[v.size()-1]; v.pop_back();

    int current_index = 0;

    while(true) {
        int left_index = (current_index * 2) + 1;
        int right_index = (current_index * 2) + 2;
        int last_index = v.size() - 1;
        if(left_index <= last_index && right_index <= last_index) {
            if(v[left_index] >= v[right_index] && v[left_index] > v[current_index]){
                swap(v[left_index], v[current_index]);
                current_index = left_index;
            } else if(v[right_index] >= v[left_index] && v[right_index] > v[current_index]) {
                swap(v[right_index], v[current_index]);
                current_index = right_index;
            } else {
                break;
            }
        } else if(left_index <= last_index) {
            if(v[left_index] > v[current_index]){
                swap(v[current_index], v[left_index]);
                current_index = left_index;
            } else {
                break;
            }
        } else if(right_index <= last_index) {
            if(v[right_index] > v[current_index]){
                swap(v[current_index], v[right_index]);
                current_index = right_index;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

//_______________________________________________________________________________________________