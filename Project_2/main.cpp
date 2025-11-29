#include "TaskList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
    TaskList list;
    
    // Initial  tests
    assert(list.empty());
    assert(list.size() == 0);
    assert(!list.removeFront()); // Removing from empty list should fail

    // Add one element  test
    list.addBack("Task A");
    assert(!list.empty());
    assert(list.size() == 1);
    assert(list.find("Task A") == 0);
    assert(list.find("Missing") == -1);

    string temp;
    assert(list.get(0, temp) && temp == "Task A");

    // Remove single element
    assert(list.removeFront());
    assert(list.empty());
    assert(list.size() == 0);

    // Add multiple elements
    list.addBack("Task A");
    list.addBack("Task B");
    list.addBack("Task C");
    list.addBack("Task D");
    assert(list.size() == 4);

    // Validate get() for all poositions
    string t;
    assert(list.get(0, t) && t == "Task A");
    assert(list.get(1, t) && t == "Task B");
    assert(list.get(2, t) && t == "Task C");
    assert(list.get(3, t) && t == "Task D");

    // Find elements that exist/dont exist
    assert(list.find("Task C") == 2);
    assert(list.find("Task E") == -1);

    // Remove all elements one by one
    int prevSize = list.size();
    while (list.removeFront()) {
        assert(list.size() == --prevSize);
    }
    assert(list.empty());

    // Test copy constructor
    list.addBack("Test A");
    list.addBack("Test B");
    list.addBack("test C");
    TaskList copy(list);
    // Both should have same content
    assert(copy.size() == list.size());
    for (int i = 0; i < list.size(); i++) {
        string t1, t2;
        assert(list.get(i, t1));
        assert(copy.get(i, t2));
        assert(t1== t2);
    }
    // Deep copy test
    list.removeFront();
    assert(list.size() == copy.size() - 1);
    string c0;
    assert(copy.get(0, c0) && c0 == "Test A"); // copy intact

    //Test copy assignment operator
    TaskList assigned;
    assigned = list;
    assert(assigned.size() == list.size());
    for (int i = 0; i < list.size(); i++) {
        string x, y;
        assert(list.get(i, x));
        assert(assigned.get(i, y));
        assert(x == y);
    }

    // Modify assigned and check for mistaken shallow copy
    assigned.addBack("Test D");
    assert(assigned.size() == list.size() + 1);

    string origLast, assignedLast;
    assert(assigned.get(assigned.size() - 1, assignedLast) && assignedLast == "Test D");
    assert(!list.get(list.size(), origLast));
    // Original should beunchanged

    // Testing Clear
    assigned.clear();
    assert(assigned.empty());
    assigned.addBack("New Entry 1");
    assigned.addBack("New Entry 2");
    assert(assigned.size() == 2);
    string a, b;
    assert(assigned.get(0, a) && a == "New Entry 1");
    assert(assigned.get(1, b) && b == "New Entry 2");
    return 0;
}
