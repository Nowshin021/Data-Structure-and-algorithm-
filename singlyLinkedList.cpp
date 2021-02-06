#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int* key;
        Node* next;
        Node(){next = NULL;}
        Node(int value){
            key = new int (value);
            next = NULL;
        }
        ~Node(){}
};




void menu();
void pushFront(int key);
void pushBack(int key);
int* topFront();
void popBack();
void popFront();
int* topBack();
void print();
bool findKey(int key);
bool isEmpty();
void eraseKey(int key);
void addBefore(Node* node , int key);
void findIfExists(int value);
void processNode(bool found , int value);
Node* findFor(int key);
void addAfter(Node* node , int data);
void deleteDuplicates();
int countNodes();
Node* findMiddle(int c);
void deleteMiddle(Node* n);
void printN_th(int c , int n);
void reverseList();
void rotateKth(int n);
Node* head = NULL;
Node* tail = NULL;

int main(){
    int choice;
    int key;
    int* p;
    int a;
    int b;
    int res;
    bool answer;
    Node *node;
    int value;
    int afterValue;
    int count;


    while(true){
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter key: ";
            cin >> key;
            pushFront(key);
            cout << "operation completed" << endl;
            break;
        case 2:

            popFront();
            cout<<"Operation complete"<<endl;
            break;
        case 3:
            p = topFront();
            cout << "top front: " << *p << endl;
            cout << "operation completed" << endl;
            break;
        case 4:
            cout<<"Enter key" <<endl;
            cin>>key;
            pushBack(key);
            cout << "operation completed" << endl;
            break;
        case 5:
            popBack();
            cout << "operation completed" << endl;
            break;
        case 6:
           p = topBack();
            cout<< *p <<endl;
            cout << "operation completed" << endl;

            break;
        case 7:
            cout<<"Enter a key to find"<<endl;
            cin>>a;
            res = findKey(a);
            cout<<"Result : " << res <<endl;
            cout << "operation completed" << endl;
            break;
        case 8:
            cout<<"Enter a key to erase"<<endl;
            cin>>b;
            eraseKey(b);
            cout << "operation completed" << endl;
            break;

        case 9:
            answer = isEmpty();
            cout<<"answer : " << answer <<endl;
            cout << "operation completed" << endl;
            break;
        case 10:
            cout<<"Enter the key before which you want to enter data: "<<endl;
            cin>>value;
            cout<<"Enter the data you want to add"<<endl;
            cin>>key;
            addBefore(findFor(value),key);

            cout << "operation completed" << endl;
            break;
        case 11:
            cout<<"Enter the key After which you want to enter data: "<<endl;
            cin>>afterValue;
            cout<<"Enter the data you want to add"<<endl;
            cin>>key;
            addAfter(findFor(afterValue),key);
            cout << "operation completed" << endl;
            break;

        case 12:
            print();
            cout << "operation completed" << endl;
            break;
        case 13:
            deleteDuplicates();
            cout << "operation completed" << endl;
            break;
        case 14:
            count = countNodes();
            node = findMiddle(count);
            cout<<"Middle node : " << *(node->key)<<endl;
            cout << "operation completed" << endl;
            break;
        case 15:
            count = countNodes();
            node=findMiddle(count);
            deleteMiddle(node);
            cout << "operation completed" << endl;
            break;
        case 16:
            cout<<"enter the n th node  to print from the back : "<<endl;
            cin>>key;
            count=countNodes();

            printN_th(count, key);
            cout << "operation completed" << endl;
            break;
        case 17:
            reverseList();
            cout << "operation completed" << endl;
            break;
        case 18:
            cout<<"Enter position to rotate: "<<endl;
            cin>>key;
            rotateKth(key);
            cout << "operation completed" << endl;
            break;

        case 19:
            cout << "thank you!" << endl;
            exit(0);
        }
    }
}

void menu(){
    cout << "------------------" << endl;
    cout << "Singly Linked List" << endl;
    cout << "------------------" << endl;
    cout << " (1) push front ... (2) pop front ... (3) top front ..." << endl;
    cout << " (4) push back .... (5) pop back .... (6) top back ...." << endl;
    cout << " (7) find key ..... (8) erase key ... (9) empty ......." << endl;
    cout << "(10) add before .. (11) add after .. (12) print .......(13) Delete Duplicates............" << endl;
    cout << "(14) Find middle value ..." << endl;
    cout << "(15) Delete middle .... (16) Print N th node.... (17) Reverse the list ....(18) Rotate  " << endl;
    cout<< "(19) exit....."<<endl;
    cout << "------------------" << endl;
}

void pushFront(int key){
    Node* node = new Node(key);
    node->next = head;
    head = node;
    if(tail == NULL)
        tail = head;
}

void popFront(){
    Node *n= head;
    head= head->next;
    delete n;



}

int* topFront(){
    return head->key;
}

void pushBack(int key){

    Node *node = new Node;
    node->key = new int(key);
    node->next=NULL;
    tail->next = node;
    tail=node;


}

int* topBack(){

   return tail->key;
}

void popBack(){   //removes data from back//
    Node *node = new Node;
    node=head;
    if(head==tail){
        head=NULL;
        tail=NULL;

    }
    else{

    while(node->next->next != NULL){
        node = node->next;
    }

    Node *temp=tail;
    node->next=NULL;
    tail=node;
    delete temp;
    }

}

bool findKey(int key){

    Node *n= new Node;
    n=head;
    bool f=false;
    while(n!=NULL){
        if(*(n->key) == key){
            f=true;
            break;


        }

        n=n->next;

    }

     return f;

}

Node* findFor(int value){

     if(head==NULL){
        cout<<"List is empty. Add some values first"<<endl;
    }
    Node *p = head;
    bool found=false;
    Node *node = new Node;
    int data;

    while(p!=NULL){
        if(*(p->key)==value){
        found=true;           //value exists in list//
        node->key=p->key;
        node->next=p->next;

       return p;
        break;

        }
        p=p->next;

    }
    if(found==false){
        cout<<"Node not found" <<endl;
    }



}


void addAfter(Node* node , int data){

    Node *n=new Node;
    n->key=new int  (data);
    n->next= node->next;
    node->next=n;
    if(node==tail){
        tail=n;

    }






}



void addBefore( Node* node , int key){

    Node *newNode = new Node;
    newNode->key=new int (key);
    Node *p=head;
    if(head==node){
        newNode->next=  node;
        head=newNode;

    }
    else{
    while(p!=NULL){
        if(*(p->next->key)==*(node->key)){
            newNode->next=p->next;
            p->next=newNode;
            break;
        }


        p= p->next;
    }

}

}

void eraseKey(int key){

    bool found = false;
    Node *n=head;
    Node  *temp;
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    else{

        if(*(topFront())==key){
            temp=head;
            head=n->next;
            found=true;
        }
        else {

            while(n->next!=NULL){
                    if(*(n->next->key)==key){
                        temp=n->next;
                        n->next=n->next->next;
                        found=true;
                        break;
                    }
                  n=n->next;
            }
        }

        if(found==false){
            cout<<"Key not found, try again"<<endl;
        }

        delete temp;
    }

}



bool isEmpty(){


    if(head==NULL){
        return true;
    }

    else return false;

}


void deleteDuplicates(){

    Node *pre=head;
    Node *post;
    Node *temp;
    bool dup=false;

    while(pre!=NULL && pre->next!=NULL){
            post=pre;

        while(post->next!=NULL){

            if(*(pre->key)==*(post->next->key)){
                    dup=true;
                    temp=post->next;
                    if(post->next->next == NULL){
                        tail=post;
                        post->next=NULL;

                    }

                    else {
                        post->next=post->next->next;
                    }

                    delete temp;


            }

           else  {
                post=post->next;
           }
        }

        pre=pre->next;
    }

    if(dup==false){
        cout<<"No duplicated found to be deleted"<<endl;
    }

}

int countNodes(){

    int c=0;
    Node *p=head;
    while(p!=NULL){

        c++;
        p=p->next;
    }
        return c;
}


Node* findMiddle(int c){

    int mid=c/2;
    mid=mid+1;
    Node *middle;

    Node *p=head;
    if(head==NULL){
        cout<<"List is empty"<<endl;

    }

    else {
    for(int i=0;i<mid;i++){


        middle = p;
        p=p->next;

    }


    return middle;


    }

}


void deleteMiddle(Node* n){

    Node *p= head;
    Node *temp;
    bool found=false;

        if(*(topFront())==*(n->key)){
            temp=head;
            head=n->next;
            found=true;
    }

   else {
    while(p!=NULL){

        if(*(p->next->key)==*(n->key)){
            found=true;
            temp=n->next;
            p->next = p->next->next;
            break;


        }

       else  p=p->next;

    }

            delete temp;

   }


}

void printN_th(int c , int n){

    Node *p=head;
    int a;
    a=c-(n-1);
    int key;
    if(n<=0 || n>c){
        cout<<"Error !Node does not exists " <<endl;

    }
    else {
    for(int i=0;i<a;i++){

            key =*(p->key);
            p=p->next;




    }

    cout<<n<<"th node from the back is = " << key<<endl;


    }

}


void reverseList(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }

    else {

    Node *p=head;
    Node *pre=NULL;
    Node *post=NULL;
    while(p!=NULL){
        post = p->next;
        p->next = pre;
        pre = p;
        p=post;
    }

    head=pre;



    }
    cout<<"Reversed list : "<<endl;
    print();

}


void rotateKth(int n){

    Node *p=head;
    Node *temp;
    for(int i=0;i<n;i++){
            temp=p;
            p=p->next;

    }

    while(temp->next!=NULL){

        temp=temp->next;
    }

    temp->next=head;

}




void print(){
    Node* p = head;
    if(head==NULL){
        cout << "List is empty" << endl;
        return;
    }
    while(p!= NULL){
        cout << *(p->key) << " ";
        p = p->next;
    }
    cout << endl;
}


