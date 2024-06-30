#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
    public:
        Node* head;
        LinkedList(int data){
            head = new Node(data);
        }
        void traverse(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        int insertEnd(int value){
            Node* newNode = new Node(value);
            
            if(head == nullptr){
                head = newNode;
            }else{
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            return value;
        }
        int insertBegin(int value){
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return value;
        }
        int insertAtPos(int pos, int value){
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                return value;
            }
            if(head->data == pos){
                this->insertBegin(value);
                return value;
            }

            Node* temp = head;
            Node* prev = head;
            while(temp->data != pos && temp != nullptr){
                prev = temp;
                temp = temp->next;
            }
            if(temp == nullptr){
                cout << "Position not found" << endl;
                return -1;
            }

            prev->next = newNode;
            newNode->next = temp;

            return value;
        }
        int deleteNodeEnd(){
            if(head == nullptr){
                cout << "List is empty" << endl;
                return -1;
            }
            Node* temp = head;
            Node* prev = head;
            while(temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
            int key = temp->data;
            delete temp;
            return key;
        }
        int deleteNodeBegin(){
            if (head == nullptr){
                cout << "List is empty" << endl;
                return -1;
            }
            Node* temp = head;
            head = head->next;
            int key = temp->data;
            delete temp;
            return key;
        }
        int deleteAtPost(int pos){
            Node* temp = head;
            Node* prev = head;
            if(head == nullptr){
                cout << "List is empty" << endl;
            }
            if(head->data == pos){
                this->deleteNodeBegin();
                return pos;
            }
            while(temp != nullptr && temp->data != pos){
                prev = temp;
                temp = temp->next;
            }
            if(temp == nullptr){
                cout << "Position not found" << endl;
                return -1;
            }

            prev->next = temp->next;
            delete temp;
            return pos;
        }

};

int getData(){
    int data;
    cout << "Enter data : ";
    cin >> data;
    return data;
}
int getPos(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    return pos;
}

int main(){
    int option = -1, data, pos;
    LinkedList list(5);
    cout << "0. Exit" << endl;
    cout << "1. Traverse List" << endl;
    cout << "2. Insert Begin" << endl;
    cout << "3. Insert End" << endl;
    cout << "4. Insert Pos" << endl;
    cout << "5. Delete Begin" << endl;
    cout << "6. Delete End" << endl;
    cout << "7. Delete Pos" << endl;
    while(option != 0){
        cout << "Enter your choice : ";
        cin >> option;

        switch(option){
            case 0:
                break;
            case 1:
                list.traverse();
                break;
            case 2:
                data = getData();
                list.insertBegin(data);
                break;
            case 3:
                data = getData();
                list.insertEnd(data);
                break;
            case 4:
                data = getData();
                pos = getPos();
                list.insertAtPos(pos, data);
                break;
            case 5:
                list.deleteNodeBegin();
                break; 
            case 6:
                list.deleteNodeEnd();
                break; 
            case 7:
                pos = getPos();
                list.deleteAtPost(pos);
                break;

        }
    };
    // cout << list.insertNode(3) << endl;
    return 0;
}