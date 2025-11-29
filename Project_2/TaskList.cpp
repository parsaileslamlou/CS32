#include "TaskList.h"
#include <iostream>

TaskList::TaskList() : head(nullptr), tail(nullptr), listSize(0) {}

TaskList::~TaskList() {
    clear(); // calls helper function to clear TaskList
}

TaskList::TaskList(const TaskList& other) {
    copyList(other); // calls helper function
}

bool TaskList::empty() const{
    if(listSize == 0) { return true; }
    return false; // checks if empty
}
TaskList& TaskList::operator=(const TaskList& rhs) {
    if (this == &rhs) return *this;
        // Free current contents
        freeList();
        // Deep copy rhs into this
        copyList(rhs);
        return *this;
}



int TaskList::size() const {
    return listSize;
}

void TaskList::addBack(const std::string& task) {
    Node* newNode = new Node{task, nullptr, tail}; // next=nullptr, prev=old tail
    if (tail == nullptr) {
        // list is empty
        head = newNode;
    } else {
        //iterate till we reach new last node
        tail->next = newNode;
    }
    //save the newNode as the new new tail
    tail = newNode;
    listSize++;
}
bool TaskList::removeFront() {
    if(head == nullptr) return false; // if list is empty
    else{
        listSize--;
        Node* temp = head->next;
        delete head;
        head = temp;
        if(head != nullptr) head->prev = nullptr;
        else { tail = nullptr; }
        return true;
        // remove first node and sets second node to head.
        //if head is now nullptr tail is also set to nullptr
    }
}

bool TaskList::get(int pos, std::string& task) const {
    if (pos < 0 || pos >= listSize || head == nullptr){ return false; }

    Node* currNode = head;
    for (int index = 0; index < pos && currNode != nullptr; index++){
        currNode = currNode->next;
    }
    if (currNode != nullptr) {
        task = currNode->task;
        return true;
    }
    return false;
}


int TaskList::find(const std::string& task) const {
    int index = 0;
    Node* currNode = head;
    //if task was found return index, if not return -1 (node is found by iterating through list and checking each node
    while(currNode != nullptr){
        if(currNode->task == task) return index;
        index++;
        currNode = currNode->next;
    }
    return -1;
}

void TaskList::clear() {
    freeList(); // calls freeList helper
}

void TaskList::printAll() const {
    //iterates through list and prints each stack, prints noithing if list empty
    if(head == nullptr) { return; }
    Node* iter = head;
    while(iter != nullptr){
        std::cerr << iter->task << std::endl;
        iter = iter->next;
    }
}

void TaskList::copyList(const TaskList& other) { //deep copy
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    
    if (other.head == nullptr) return;

    // copy the first node
    head = new Node{other.head->task, nullptr, nullptr};
    Node* thisCurr = head;
    Node* otherCurr = other.head->next;

    // copy remaining nodes
    while (otherCurr != nullptr) {
        thisCurr->next = new Node{otherCurr->task, nullptr, thisCurr};
        thisCurr = thisCurr->next;
        otherCurr = otherCurr->next;
    }
    tail = thisCurr;
    listSize = other.listSize;
}
void TaskList::freeList() {
    //iterates through and clears list while ensuring no memory leaks
    while (head != nullptr) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    tail = nullptr;
    listSize = 0;
    
}

TaskList::Node* TaskList::getNode(int pos) const {
    //if pos invalid
    if (pos <0 || pos >= listSize) return nullptr;
    int index = 0;
    // iterates through till reached pos
    Node* currNode = head;
    while(currNode != nullptr && index < pos){
        currNode = currNode->next;
        index++;
    }
    return currNode; 
}
