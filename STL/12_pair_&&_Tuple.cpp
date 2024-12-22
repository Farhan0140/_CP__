#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));


//!Global_Declaration------------------------------------------------------
pair<string, int> pr1;
pair<string, string> pr2;
pair<int, int> pr3;


tuple<string, int, int, double, char, bool> t;
//       0     1    2     3      4      5  -----> like Index


int main() {
    //______Initialization_______________________________________________________________________________
    // 1
    pr1 = make_pair("Nadim", 5101001);

    // 2
    pr2 = {"Farhan", "Nadim"};

    // 3
    pr2.first = 100;
    pr2.second = 999;

    // 4
    pair<double, int> pr4(3.14159, 100);

    // 5
    pair<string, int> copy_pr(pr1);



    //______Element access_______________________________________________________________________________
    // 1
    cout << "Using first & Second: " << pr1.first << " " << pr1.second << endl;
    pr1.first = "Farhan";
    pr1.second = 99;

    // 2
    auto [Name, id] = pr1;
    cout << "Using auto: " << Name << " " << id << endl;



    //______Array of Pairs_______________________________________________________________________________
    // 1
    pair<string, int> arr[100];
    arr[0].first = "Farhan"; arr[0].second = 1;
    cout << "From array: " << arr[0].first << " " << arr[0].second << endl;

    // 2 From User
    ll n = 10; // cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i=0; i<n; i++) {
        cout << i << " th pair: " << arr[i].first << " " << arr[i].second << endl;
    }

    for(auto [x, y] : arr) {
        cout << x << " " << y << endl;
    }



    //______Tuple________________________________________________________________________________________

    //______Initialization________________________
    // 1
    //    name    id  phone   CGPA
    tuple<string, int, int, double> student = make_tuple("Farhan", 1, 1403, 3.59);

    // 2
    tuple<string, int, int, double> student1 = {"Hablu", 2, 111, 3.99};

    //______Element access______________________
    // 1
    cout << "\nTuple\n" << get<0>(student) << " " << get<1>(student) << " " << get<2>(student) << " " << get<3>(student) << endl;
    //                   index 0                         1                         2                         3                   

    // 2
    auto [name, Id, phone, cg] = student1;
    cout << name << " " << Id << " " << phone << " " << cg << endl;

    // From User
    tuple<string, int, int, double> student;
    cin >> get<0>(student) >> get<1>(student) >> get<2>(student) >> get<3>(student);
    cout << get<0>(student) << " " << get<1>(student) << " " << get<2>(student) << " " << get<3>(student) << endl;
    
    // Nested Pair_____________________________________

    pair<string, pair<int, string>> new_student = {"Hablu", {100, "014"}};
    pair<string, pair<int, string>> new_student1 = make_pair("Hablu", make_pair(100, "014"));

    string NAME = new_student1.first;
    int ID = new_student1.second.first;
    string Phone = new_student1.second.second;

    cout << NAME << " " << ID << " " << Phone << endl;
    return 0;
}