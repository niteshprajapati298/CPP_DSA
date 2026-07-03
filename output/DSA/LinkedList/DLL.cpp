#include<iostream>
#include<vector>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1,
        next = next1,
        back = back1;
    }
       Node(int data1){
        data = data1,
        next = nullptr,
        back = nullptr;
    }
};
Node* convertToDLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
     Node* temp = new Node(arr[i],nullptr,prev);
     prev->next = temp;
     prev = temp;
    }
    return head;
}
void printDLL(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHeadOfDLL(Node* head){
   if(head==nullptr || head->next==nullptr) { 
     delete head;
    return nullptr; 
   }
   Node* temp = head;
   head = head->next;
   head->back = nullptr;
   delete temp;
   return head;

   
}
Node* deleteTailOfDLL(Node* head){
    if(head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* mover = head;
    while(mover->next->next != nullptr) {
        mover = mover->next;
    }

    Node* temp = mover->next;
    mover->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node* deleteKthNode(Node* head ,int k){
    if(k==1) return deleteHeadOfDLL(head);
    Node* mover = head;
    int count = 1;

    while(mover != nullptr && count < k){
      mover = mover->next;
      count++;
    }
        if(mover == nullptr)
        return head; // k out of range
   if(mover->next==nullptr) return deleteTailOfDLL(head);
   Node* temp = mover;
   mover->back->next = temp->next;
   mover->next->back = temp->back;
   temp->back = nullptr;
   temp->next = nullptr;
   delete temp;
   return head;
}

void deleteNode(Node* temp){
   Node* prev = temp->back;
   Node* front = temp->next;

   if(front==nullptr){
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
   }
   prev->next = front;
   front->back = prev;
   temp->next = nullptr;
   temp->back = nullptr;
   delete temp;
}

Node* insertElementBeforeHead(Node* head, int element){
    Node* newHead = new Node(element,head,nullptr);
    head->back = newHead;
    return newHead;
}
Node* insertElementBeforeTail(Node* head, int element){
    Node* mover = head;
    while(mover->next != nullptr){
         mover = mover->next;
    }

    Node* prev = mover->back;
    cout << "Mover: " << mover->data << endl << "Prev: "<< prev->data << endl;
    Node* newNode = new Node(element,mover,prev);
    mover->back = newNode;
    prev->next = newNode;
    cout << "Mover Back Data: " << mover->back->data << endl;
    cout << "Prev Next Data"<<prev->next->data<<endl;
    cout << "New Node : " << newNode->data << endl;
     return head;
}


Node* insertElementKthPos(Node* head, int k , int element){
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr){
        count++;
      if(count == k) break;
     temp = temp->next;
   }
   cout <<"Count : " << count << endl;
   cout <<"Temp : " << temp->data << endl;

    if(k==1) return insertElementBeforeHead(head, element);
    else if(temp->next==nullptr) return insertElementBeforeTail(head,element);
    Node* prev = temp->back;
    Node* newNode = new Node(element,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* insertBeforeNode(Node* head, int element , Node* target){
    if(head==nullptr) return nullptr;
    if(head==target) return insertElementBeforeHead(head,element);
    Node* prev = head;
    
    while(prev->next!=target ){
        cout<< "Prev->Node -> " << prev << " ||  Prev->Data -> "<< prev->data << endl;

        prev = prev->next;
    }
    cout<<"Prev Next -> "<<prev->next<<endl;
    cout <<"Prev Back ->  "<< prev->back<<endl;
        // cout <<"Target Data ->  "<< target->back<<endl;

    Node* newNode = new Node(element,prev->next,prev);
    prev->next = newNode;
    target->back = newNode;
    cout<<"NewNode->Next -> " << newNode->next<<endl;
    return head;

}

Node* reverseDLL(Node* head){
    Node* mover = head;
    int count = 0;
    while(mover!=nullptr){
        // Node temp = *mover;
        Node* back = mover->back;
        Node* front = mover->next; 
        mover->next = back;
        mover->back = front;
        count ++;
        if(front!=nullptr){
           mover = front;
        }
        else {
            break;
        }
    }
    return mover;
}
int main (){
    // Create an array of numbers to build our linked list
    vector<int> arr = {12, 5, 8, 12,21};
 
    Node* head = convertToDLL(arr);
    // Node* head = convertToDLL(arr);
    // Node* newHead = deleteHeadOfDLL(head);
    // Node* newHead = deleteTailOfDLL(head);

    // Node* newHead2 = deleteTailOfDLL(newHead);

    // // cout << head->data;
    cout << "before Insertion : ";
    printDLL(head);
    cout << endl;

//     // Node* newHead3 = deleteTailOfDLL(newHead2);
// //    deleteNode(head->next);
//       Node* newNode = insertElementBeforeTail(head, 400);
//      Node* newNode2 = insertElementBeforeTail(newNode, 490);
    //  Node* newNode = insertElementKthPos(head,1,24);
    //   insertElementBeforeHead(head, 490);
    // Node* newNode = insertBeforeNode(head,29,head->next->next->next->next->next);
    Node* newHead = reverseDLL(head);
    cout << "After Insertion : ";
    printDLL(newHead);
    cout << endl;
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
//   Node* newHead = insertNodeAtKthPosition(head,80,25);
//   printLL(newHead);


    
}