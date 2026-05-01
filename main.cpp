#include "LDLL.h"
#include "CDLL.h"
#include <iostream>
using namespace std;

int main() {
    // Linear Doubly Linked List
    LDLL ldll;
    ldll.insertAtHead(10);
    ldll.insertAtTail(20);
    ldll.display();   // Expected: 10 <-> 20

    // Circular Doubly Linked List
    CDLL cdll;
    cdll.insertAtHead(5);
    cdll.insertAtTail(15);
    cdll.display();   // Expected: 5 <-> 15 (circular)

    return 0;
}
