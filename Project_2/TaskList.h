#ifndef TASKLIST_H
#define TASKLIST_H
#include <iostream>
#include <string>
class TaskList{
    private:
        struct Node{
            std::string task;
            Node* next;
            Node* prev;
        };
        Node* head;
        Node* tail;
        int listSize;
    
    public:
        TaskList();
        ~TaskList();
        TaskList(const TaskList& other);
        TaskList& operator=(const TaskList& other);
        bool empty() const;
        int size() const;
        void addBack(const std::string& task);
        bool removeFront();
        bool get(int pos, std::string& task) const;
        int find(const std::string& task) const;
        void clear();
        void printAll() const;
    private:
        void copyList(const TaskList& other);
        void freeList();
        Node* getNode(int pos) const;
};
#endif // TASKLIST_H
