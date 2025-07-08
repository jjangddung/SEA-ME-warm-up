//명령어를 입력받고, 받은 명령어가 exit 아니면 계속 명령어를 입력받도록
// 해야함.
//ADD , SEARCH, REMOVE , BOOKMARK , EXIT



#include <bits/stdc++.h>

//user 정보를 vector<string> 형태로 저장하고, 입력받는 식으로 해야할 것 같다.

//전체 유저를 vector<User> total_user로 사용해보자!


using namespace std;


class User{
    public :
    string name ;
    string phone_number ;
    string nickname ;

    User(string n, string p, string nick) 
        : name(n) , phone_number(p), nickname(nick) {}

    void print_info() const {
        cout << "name: " << name << "\n"
             << " phone: " << phone_number << "\n"
             << " nickname: " << nickname << "\n";
    }

}; 
vector<User> total_user;

class Bookmark_members : public User{


    public:

    int index ;
    Bookmark_members(int i, const User & u) 
        : User(u), index(i) {} 

        void bookmark_info() const {
            cout << "index: " << index << "\n"; 
            cout << "name: " << name << "\n"
                 << " phone: " << phone_number << "\n"
                 << " nickname: " << nickname << "\n";
        }

};



vector<Bookmark_members> bookmark_user;

void add(string name, string phone_number, string nickname ){
    User user(name,phone_number,nickname);
    total_user.push_back(user);

    return ;
}

void search(){
    string ans;
    int index ; 
    for (int i= 0 ; i < total_user.size(); i ++){
        cout << i+1 << ". \n";
        total_user[i].print_info();
    }

    cout << "Will you want to bookmark? (yes/no) \n";
    cin >> ans ;
    if (ans == "yes"){
        cout << "Input index: ";
        cin >> index ;
        Bookmark_members bookmark_mem(index, total_user[index-1]);
        bookmark_user.push_back(bookmark_mem);

    }
    return ;
}

void bookmark(){
    for (auto mem : bookmark_user){
        mem.bookmark_info();
    }


}

void menu(){
    cout << "----------------menu----------------\n";
    cout << "ADD\nSEARCH\nREMOVE\nBOOKMARK\nEXIT\n\n";
}

void removing(string na){
    int re_in ;
    for (int i = 0 ; i < total_user.size() ; i ++){
        if (total_user[i].name == na){
            re_in  = i ;
            total_user.erase(total_user.begin()+i);
            break ;
        }
    }
    //sort( total_user.begin(), total_user.end());

    for (int i = 0 ; i < bookmark_user.size() ; i ++){
        if (bookmark_user[i].name == na){
            bookmark_user.erase(bookmark_user.begin()+i);
            break ;
        }
    }

    for (int i = 0 ; i < bookmark_user.size() ; i ++){
        if (bookmark_user[i].index > i){
            bookmark_user[i].index-=1;
        }
    }

    //sort(bookmark_user.begin(),bookmark_user.end());

    
}

