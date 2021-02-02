#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

typedef stack<string> Stack;

void Input(string &str, int &num);                             // 파일로 부터 입력을 받음
void nextpermutation(string str, Stack &stk, int num);         // 다음 순열을 구해서 스택에 저장
void prevpermutation(string str, Stack &stk, int num, int &a); // 이전 순열을 구해서 스택에 저장
void Output(Stack stk, int num, int a);                        // 스택으로 부터 출력

int main(){
    Stack stk;
    string str;
    int num, location;
    Input(str, num);                                 // 입력
    prevpermutation(str, stk, num, location);        // 이전 순열
    nextpermutation(str, stk, num);                  // 다음 순열
    while(!stk.empty()){
        cout<<stk.top() << endl;
        stk.pop();
    }
    Output(stk, num, location);                      // 조건에 따라 출력
}

void Input(string &str, int &num){
    ifstream input("1.inp");
    cin >> str >> num;
    input.close();
}

void nextpermutation(string str, Stack &stk, int num){
    int counter=0;
    string copy_str(str);
    while(1){
        string temp;
        bool finish=false;
        temp.push_back(copy_str.back());
        copy_str.pop_back();
        do{
            if(temp.back()<=copy_str.back()){
                temp.push_back(copy_str.back());
                copy_str.pop_back();
            }
            else{
                for(int i=0;i<temp.size();i++){
                    if(temp[i]>copy_str.back()){
                        char c=temp[i];
                        temp[i]=copy_str.back();
                        copy_str.pop_back();
                        copy_str.push_back(c);
                        finish=true;
                        break;
                    }
                }
            }
            if(finish==true) break;
        }while(!copy_str.empty());
        counter++;
        for(int i=0;i<temp.size();i++) copy_str.push_back(temp[i]);
        stk.push(copy_str);
        if(finish==false||counter==num) break;
    }

}

void prevpermutation(string str, Stack &stk, int num, int &a){
    int counter=0;
    string copy_str(str);
    Stack tempstk;
    while(1){
        string temp;
        bool finish=false;
        temp.push_back(copy_str.back());
        copy_str.pop_back();
        do{
            if(temp.back()>=copy_str.back()){
                temp.push_back(copy_str.back());
                copy_str.pop_back();
            }
            else{
                for(int i=0;i<temp.size();i++){
                    if(temp[i]<copy_str.back()){
                        char c=temp[i];
                        temp[i]=copy_str.back();
                        copy_str.pop_back();
                        copy_str.push_back(c);
                        finish=true;
                        break;
                    }
                }
            }
            if(finish==true) break;
        }while(!copy_str.empty());
        counter++;
        for(int i=0;i<temp.size();i++) copy_str.push_back(temp[i]);
        tempstk.push(copy_str);
        if(finish==false||counter==num) break;
    }
    while(!tempstk.empty()){
        stk.push(tempstk.top());
        tempstk.pop();
    }
    stk.push(str);          // 원래 문자열 넣기
    a = stk.size();         // 원래 문자열 위치
}

void Output(Stack stk, int num, int a){
    bool b=false, c=false;
    if(num+a>stk.size()) b = true;
    if(a-num<0) c = true;
    string prev, next;
    next = stk.top();
    while(!stk.empty()){
        prev = stk.top();
        stk.pop();
    }
    ofstream output("1.out");
    if(c==true) output << "none" << endl;
    else output << prev <<endl;
    if(b==true) output << "none" << endl;
    else output << next << endl;
    output.close();
}
