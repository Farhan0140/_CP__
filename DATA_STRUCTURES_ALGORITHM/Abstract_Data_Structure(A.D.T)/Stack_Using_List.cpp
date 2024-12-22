//!--> Last in First out ---> LIFO

#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Stack{
    private:
        list<int> li;
    
    public:
        void Push(int val) {
            li.push_back(val);
        }

        void Pop() {
            li.pop_back();
        }

        int Top() {
            return li.back();
        }

        int Size() {
            return li.size();
        }

        bool Empty() {
            if(li.size() == 0) { return true; }
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