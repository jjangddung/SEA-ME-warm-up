#include <bits/stdc++.h>
#include "book.h"
using namespace std;




int main(){

    //vector<User> total_user ;

    //add("홍길동", "010-1234-5678", "길동이");
    //add("김영희", "010-8765-4321", "영희");

    string order; 
    

    while(1){
        menu();
        cin >> order ;
        if (order == "EXIT"){
            "Program EXIT\n";
            break ;
        }
        else if (order == "ADD"){
            string n;
            string p;
            string nick;
            cout << "input name,phone_number,nickname\n";
            cin >> n >> p >> nick ;
            add(n,p,nick);
        }

        else if (order == "SEARCH"){
            search();
        }

        else if (order == "REMOVE"){
            string re_n;
            cout << "what name do you want to remove?\n";
            cin >> re_n;
            removing(re_n);

        }

        else if (order == "BOOKMARK"){
            bookmark();
        }

        else {
            cout << "input again \n";
        }
    }
    








    return 0;
}