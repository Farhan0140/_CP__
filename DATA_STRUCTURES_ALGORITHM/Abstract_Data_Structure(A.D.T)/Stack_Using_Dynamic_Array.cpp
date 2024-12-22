//!--> Last in First out ---> LIFO

#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Stack{
    private:
        vector<int> v;
    
    public:
        void Push(int val) {
            v.push_back(val);
        }

        void Pop() {
            v.pop_back();
        }

        int Top() {
            return v.back();
        }

        int Size() {
            return v.size();
        }

        bool Empty() {
            if(v.size() == 0) { return true; }
            else { return false; }
        }
};

//_______________________________________________________________________________________________


int main(){
    
    Stack st;
    st.Push(120);
    st.Push(10);
    st.Push(20);
    st.Push(40);
    st.Push(60);
    st.Push(920);
    
    while(!st.Empty()){
        cout << st.Top() << endl;
        st.Pop();
    }
    return 0;
}


//_______________________________________________________________________________________________