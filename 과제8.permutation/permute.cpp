#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

typedef stack<string> Stack;

void Input(string &str, int &num);                             // ���Ϸ� ���� �Է��� ����
void nextpermutation(string str, Stack &stk, int num);         // ���� ������ ���ؼ� ���ÿ� ����
void prevpermutation(string str, Stack &stk, int num, int &a); // ���� ������ ���ؼ� ���ÿ� ����
void Output(Stack stk, int num, int a);                        // �������� ���� ���

int main(){
    Stack stk;
    string str;
    int num, location;
    Input(str, num);                                 // �Է�
    prevpermutation(str, stk, num, location);        // ���� ����
    nextpermutation(str, stk, num);                  // ���� ����
    while(!stk.empty()){
        cout<<stk.top() << endl;
        stk.pop();
    }
    Output(stk, num, location);                      // ���ǿ� ���� ���
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
    stk.push(str);          // ���� ���ڿ� �ֱ�
    a = stk.size();         // ���� ���ڿ� ��ġ
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
