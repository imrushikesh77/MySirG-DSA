/*
* First in Last out
* Space complexity: O(n);
* Time complexity for push(), pop(), size(), isEmpty(), idFull(), deleteStack() is O(1)
* In case of dynamic array for pushing elt time complexity can be O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Stack{
    vector <int> stack;
    int top;
    public:
    Stack(){
        top = -1;
    }
    ~Stack(){
        top = -1;
    }
    int size(){
        return top+1;
    }
    void push(int data){
        // if(isFull()){
        //     cout<<"Stack Overflow"<<endl;
        // }
        // else {
            top++;
            stack.push_back(data);
        // }
    }
    int pop(){
        if(isEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else{
            int x= stack[top];
             stack.pop_back();
             top--;
            return x;
        }
    }
    int getTop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return stack[top];
    }
    int isEmpty(){
        if(top == -1) return 1;
        else return 0;
    }
    int isFull(){
        if(top == 99) return 1;
        else return 0;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
        }
        else{
            for(int i=top;i>=0; i--){
                cout<<stack[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Stack s;
    int choice;
    while(1){
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Get Top\n";
        cout<<"4. Get Size\n";
        cout<<"5. isEmpty\n";
        cout<<"6. isFull\n";
        cout<<"7. Display\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int val;
            cout<<"Enter value: ";
            cin>>val;
            s.push(val);
            break;
        
        case 2:
            cout<<"Deleted element is: "<<s.pop()<<endl;
            break;
        
        case 3:
            cout<<"Top of stack is: "<<s.getTop()<<endl;
            break;
        
        case 4:
            cout<<"Size of stack is: "<<s.size()<<endl;
            break;
        
        case 5:
            if(s.isEmpty()) cout<<"Stack is empty\n";
            else cout<<"Stack is not empty\n";
            break;

        case 6:
            if(s.isFull()) cout<<"Stack is full\n";
            else cout<<"Stack is not full\n";
            break;

        case 7:
            s.display();
            break;

        default:
            exit(0);
            break;
        }   
    }
    
    return 0;
}