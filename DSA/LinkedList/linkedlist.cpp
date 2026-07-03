#include<iostream>
#include<vector>
using namespace std;

// Node class - represents each element in the linked list
class Node {
    public:
    int data;           // stores the value
    Node* next;         // points to the next node
    
    public:
    Node(int data1, Node* nextNode){
        data = data1;
        next = nextNode;
    }
      public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* covertArr2LL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size();i++){
        Node* temp = new Node(arr[i]);  // abhi temp pe arr [0] ke liye temp kuch aisa hoga jisme [12][null]
        mover->next = temp;
        mover = temp;
    } 
    return head;
};
void printLL(Node* head){
      Node* mover = head;
     while(mover!=nullptr){
          cout<<mover->data <<" ";
          mover = mover->next;
     }
};
// Deletion of Linked List 
Node* removeHeadofLL(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
// remove Tail 
Node* removeTail(Node* head){
    if(head == nullptr || head->next==nullptr) return NULL;
    Node* mover = head;
    while(mover->next->next!=nullptr){
        mover = mover->next;
    }
    delete mover->next;
    mover->next = nullptr;
    return head;
}

Node* removeKthNode(Node* head, int k){
    if(head == nullptr || k <= 0) return head;
    if(k == 1){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    Node* mover = head;
    int counter = 1;
    while(mover != nullptr && mover->next != nullptr){
        if(counter == k - 1){
            Node* toDelete = mover->next;
            mover->next = mover->next->next;
            delete toDelete;
            break;
        }
        mover = mover->next;
        counter++;
    }
    return head;
};

// Deletion of a LinkedList at head ->
Node* removeNodeByElement(Node* head ,int element){

         if(head==nullptr) return NULL;
       
            if(head->data==element && head->next==nullptr) {
                delete head;
                return NULL;
            };
           if(head->data == element && head->next != nullptr) {
    Node* temp = head->next;
    delete head;
    return temp;
}
            Node* mover = head;

            Node* prev = nullptr;
            while(mover!=nullptr){
                if(mover->data==element){
                  prev->next=mover->next;
                  break;
                }
                prev=mover;
                mover=mover->next;
            }
            delete mover;
            return head;       
}
   
Node* insertNodeToHead (Node* head,int element) {
          if(head==nullptr) return new Node(element);
     
          return new Node(element, head);          
}
Node* insertToTail (Node* head,int element){
   if(head==nullptr) return new Node(element);
   Node* mover = head;
   while(mover->next!=nullptr){
    mover = mover->next;
   }
   Node* newNode = new Node(element);
   mover->next = newNode;
   return head;
}
Node* insertNodeAtKthPosition(Node* head, int k , int element){
//    I am making sure that K will be and gte to 0 and lte to the size of the Node 
    if(k==1){
        return new Node(element, head);
    }
    int index = 1;
    Node* mover = head;
    while(mover!=nullptr && index < k ){
             index = index+1;
              if(index == k ){
               Node* newNode = new Node(element,mover->next);
               mover->next = newNode;
            break;
        }
        mover=mover->next;
    }
    return head;
}
Node * insertNodeAtGivenVal(Node* head , int value , int element){
       if(head==nullptr) return nullptr;
       Node* mover = head;
       if(mover->data==value) {
         
       }
}

// Node* insertElementAtPosition(){
     
// }



// Insertion and Deletion in a LinkedList  -> 
// head 
// position 
// value
// last

// Insertion and Deletion And Creation in a Double LinkedList -> 
// head 
// position 
// value
// last
Node * convertToDLL(){}
int main (){
    // Create an array of numbers to build our linked list
    vector<int> arr = {12, 5, 8, 12};

    Node* head = covertArr2LL(arr);
    // cout << head->data;
    printLL(head);
    cout<<endl;
    // cout << "<-  Before Deleting the Head Node" << endl;
    // // removeHeadofLL(head);
    //  Node* newHead = removeHeadofLL(head);
    // printLL(newHead);
  


    // printLL(head);
    // cout << "<-  Before Deleting the kth Node" << endl;
    // // removeHeadofLL(head);
    //  Node* newHead = removeKthNode(head , 2);
    // printLL(newHead);
    

    // cout << "<- After Deleting the kth Node " << endl;
  Node* newHead = insertNodeAtKthPosition(head,80,25);
  printLL(newHead);


    
}