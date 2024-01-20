//11. Write a menu driven program to implementing the various operations on a linear linked list

#include<iostream>
using namespace std;

class list{
    public:
    string data;
    list* next;
    list(string d){
        this -> data = d;
        this -> next = NULL;
    }
};

inline void insertatHead(list* &head , string data){
    list* temp = new list(data);
    temp -> next = head;
    head = temp;
}

inline void insertatTail(list* &tail , string data){
    list* temp = new list(data);
    tail -> next = temp ;
    tail = temp ;
}

inline void insertatPosition(list* &head ,list* &tail ,int  position ,string  data){
    if(position == 1){
        insertatHead(head , data);
        return ;
    }
    int count = 1;
    list* temp = head;
    while ( count <= position - 1){
        count++;
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        insertatTail(tail , data);
        return ;
    }
    list* temp2 = new list(data);
    temp2 -> next = temp -> next;
    temp -> next = temp2;
    
}

inline void  deleteatPosition(list* &head ,list*  &tail ,int position){
    if(position == 1){
        list* temp = head ;
        head = temp -> next;
        free(temp);
    }
    list* temp = head;
    list* previous = NULL;
    int count = 1;
    while(count <= position - 1){
        count++;
        previous = temp;
        temp = temp -> next;
    }
    previous -> next = temp -> next;
    free(temp);
    
}

inline void display(list* &head){
    list* temp = head ;
    while ( temp != NULL){
        cout<<temp -> data <<"|      |";
        temp = temp -> next;
    }
}

int main(){
    list* obj = new list("object");
   list* head = obj;
    list* tail = obj;
    while(1){
        cout<<"\nMENU\n1.Insert at Head\n2.Insert at Tail\n3.Insert at desired Position\n4.delete at desired position\n5.Display\n6.Exit\n";
   
        int choice;
        cout<<"Enter your choice : ";
        cin>>choice;
   
        switch(choice){
            case 1:
            {
                string data;
                cout<<"\nEnter data to insert : ";
                cin>>data;
                insertatHead(head , data);
                
            }
            case 2:
            {
                string data;
                cout<<"\nEnter data to insert : ";
                cin>>data;
                insertatTail(tail , data);
                break;
            }
            case 3:
            {
                int position;
                cout<<"\nEnter desired position : ";
                cin>>position;
                string data;
                cout<<"\nEnter data to insert : ";
                cin>>data;
                insertatPosition(head , tail , position , data);
                 break;
            }
            case 4:
            {
                int position;
                cout<<"\nEnter desired position : ";
                cin>>position;
                deleteatPosition(head , tail , position);
                 break;
            }
            case 5:
            {
                display(head);
                 break;
            }
            case 6:
            {
                cout<<"\nExited from program!! \n";
                exit(0);
            }
            default:
            {
                cout<<"\nInvalid choice!!";
            }
        }
    
    }
    
    return 0;
}
