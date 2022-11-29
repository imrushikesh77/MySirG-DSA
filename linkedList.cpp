/*
*A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers as shown in the below image:

 *       |-------|-------|   |-------|-------|   |-------|-------|
 *Head-->|  Data |Address|-->|  Data |Address|-->|  Data |  NULL |
*        |_______|_______|   |_______|_______|   |_______|_______|

* The block of data and address is called node
*/
// *********************** //

#include <bits/stdc++.h>
using namespace std;

class node{
    public:

    int val;
    node* next;

    node(){
        val = 0;
        next = NULL;
    }
};

class LinkedList{
    node *head;

    public:

    LinkedList(){
        head = NULL;
    }

    //* Insert at end
    void insertAtEnd(int data){
            node *temp = new node();
            temp -> val = data;
            //* For the first node
            if(head == NULL){
                head = temp;
            }
            else{
               node *t = head;

               // * Move to null node
               while (t->next!=NULL){
                t = t -> next;
               }

               t -> next = temp;
                
            }
    }

    //* Insert at first;
    void insertAtFirst(int data){
        node *temp = new node();
        temp->val = data;
        if(head == NULL){
            head = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
    }

    //* Inserting at given node
    void insertInMiddle(int data, int pos){
        //* Pos is the node after which we want insert node
        node *temp = new node();
        temp ->val = data;
        if(pos==0){
            temp->next = head;
            head = temp;
        }
        else{
            node *t = head;
            while(pos>1){
                pos--;
                if(t->next != NULL){
                    t = t->next;
                }
                else{
                    cout<<"Position does not exist\n";
                    return;
                }  
            }
            temp -> next = t -> next;
            t ->next = temp;
        }
    }

    // * Delete node
    void deleteNode(int pos){
        node *temp = head;
        if(pos==1){
            head = head ->next;
            cout<<temp->val<<" deleted\n";
            delete temp;
        }
        else if(pos==2){
            temp = temp->next;
            head->next = temp ->next;
            cout<<temp->val<<" deleted\n";
            delete temp;
        }
        else{
            while(pos>2){
                pos--;
                if(temp->next->next!=NULL)
                    temp = temp ->next;
                else{
                    cout<<"Invalid position\n";
                    return;
                }
            }
            node *t = temp->next;
            temp ->next = t->next;
            cout<<t->val<<" deleted\n";
            delete t;
        }
    }

    //* Searching node
    void searchNode(int data){
        node *temp = head;
        bool flag = false;
        if(head == NULL){
            cout<<"Linked list null\n";
        }
        else{
            int count = 1;
            while(temp!=NULL){
                if(temp->val==data){
                    cout<<"Element found  at "<<count<<" node\n";
                    flag = true;
                    return;
                }
                count++;
                temp = temp ->next;
            }
            if(!flag){
                cout<<"Element not found!!\n";
            }
        }
    }

    //* Maximum element
    void maxElement(){
        node *p = head;
    int maxElt = INT32_MIN;
    while(p){
        if(maxElt<p->val)
            maxElt = p->val;
            p = p->next;
    } 
    cout<<"Maximum element is: "<<maxElt<<endl;
    }

//* No. of counts in ll
void countNodes(){
    node *p = head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    cout<<"No. of nodes in linked list are: "<< count<<endl;
}

//* Sum of nodes
void sumNodes(){
    node *p = head;
    int sum=0;
    while(p){
        sum+=p->val;
        p=p->next;
    }
    cout<<"Sum of all nodes is: "<<sum<<endl;
}

    //* Printing LL
    void printLL(){
        node *t = head;
        while(t != NULL){
            cout<<t->val<<" -> ";
            t = t->next;
        }
        cout<<" NULL\n";
    }

};

int main(){

    LinkedList ll;
    int choice;

    // ll.insertAtEnd(0);
    // ll.insertAtEnd(1);
    // ll.insertAtEnd(2);
    // ll.insertAtEnd(3);
    // ll.insertAtEnd(4);
    // ll.insertAtEnd(5);
    // ll.maxElement();
    // ll.countNodes();
    // ll.sumNodes();
    // ll.printLL();

    while(1){
        cout<<"***Menu***\n";
        cout<<"1. Insert at first\n";
        cout<<"2. Insert in middle\n";
        cout<<"3. Insert at end\n";
        cout<<"4. Delete node\n";
        cout<<"5. Search node\n";
        cout<<"6. Maximum element\n";
        cout<<"7. Count nodes\n";
        cout<<"8. Sum of nodes\n";
        cout<<"9. Print linked list\n";
        cout<<"10. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        int data,pos;
        switch(choice){
            case 1:
                cout<<"Enter data: ";
                cin>>data;
                ll.insertAtFirst(data);
                cout<<data<<" inserted\n";
                break;
            case 2:
                cout<<"Enter data and position: ";
                cin>>data>>pos;
                ll.insertInMiddle(data,pos);
                cout<<data<<" inserted at "<<pos<<" position\n";
                break;
            case 3:
                cout<<"Enter data: ";
                cin>>data;
                ll.insertAtEnd(data);
                cout<<data<<" inserted at the end\n";
                break;
            case 4:
                cout<<"Enter position\n";
                cin>>pos;
                ll.deleteNode(pos);
                break;
            case 5:
                int data;
                cout<<"Enter data: ";
                cin>>data;
                ll.searchNode(data);
                break;
            case 6:
                ll.maxElement();
                break;
            case 7:
                ll.countNodes();
                break;
            case 8:
                ll.sumNodes();
                break;
            case 9:
                ll.printLL();
                break;
            case 10:
                exit(0);
            default:
                cout<<"Invalid choice: ";
                break;
        }

    }
    
    return 0;
}