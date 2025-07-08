#include <bits/stdc++.h>

using namespace std;

string up(string order ,string sentence);

//g++ -o [실행파일 이름] [실행파일.cpp]
// arg는 전달된 인자의 수를 의미
// argumetns vector는 가변적인 갯수의 문자열을 의미
//char* 문자열 시작의 첫 주소값을 의미
int main(int argc, char* argv[]){


    string order;
    string sentence = "";


    order = argv[1];

    for (int i = 2 ; i < argc ; i ++){
        sentence += argv[i];
        sentence += " ";
    }

    cout << sentence ;

    cout << up(order, sentence) << "\n";

    //cout << order << "\n";
    //cout << sentence << "\n";


    return  0;
}

string up(string order, string sentence){
    if (order == "up"){
        for (int i = 0 ; i < sentence.size() ; i ++){
            sentence[i] =  toupper(sentence[i]);
        }
    }

    else {
        for (int i = 0 ; i < sentence.size() ; i ++){
            sentence[i] =  tolower(sentence[i]);
        }

    }

    return sentence ;
}