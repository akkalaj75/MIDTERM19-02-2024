/*1. Linked List: Event Timeline System
Real-Life Scenario: Imagine a social media platform that allows users to post updates on their timeline. Each post can be seen as an event in a user's day. 
The platform needs to display these events in the order they occurred, from the most recent back to the first post of the day. 
A linked list is an ideal data structure for this, as it efficiently supports operations like adding a new event at the beginning (to represent the latest event) or browsing through the day's events.

Data Structure Suitability: 
A linked list is perfect for the event timeline system because:

It allows for constant time insertion at the beginning, making it efficient to add new events as they happen.
It can easily accommodate a varying number of events without the need for resizing (unlike an array).
Traversal from the most recent to the oldest event is straightforward, reflecting the natural way users would browse through a day's events.

Linked List Code for Event Timeline System:*/

#include <iostream>
#include <string>
using namespace std;

// Node structure for a linked list
struct EventNode {
    string event;
    EventNode* next;

    EventNode(string event) : event(event), next(nullptr) {}
};

// Linked List class for the event timeline
class EventTimeline {
private:
    EventNode* head;
    int size;
public:
    EventTimeline() : head(nullptr), size(0) {}

    // Function to add an event to the timeline
    void addEvent(string event) {
        EventNode* newNode = new EventNode(event);
        newNode->next = head;
        head = newNode;
        size++;
    }

    /// Function to display the timeline
    void displayTimeline() {
        EventNode* temp = head;
        while (temp != nullptr) {
            cout << temp->event << endl;
            temp = temp->next;
        }
    }

    // Destructor to clean up memory
    ~EventTimeline() {
        while (head != nullptr) {
            EventNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to demonstrate the EventTimeline class:
int main() {
    EventTimeline myTimeline;
    myTimeline.addEvent("Liked a post");
    myTimeline.addEvent("Commented on a picture");
    myTimeline.addEvent("Posted a new photo");

    cout << "Current Timeline Events:\n";
    myTimeline.displayTimeline();

    return 0;
}
/*
* The linked list is suitable here because it allows for efficient insertion and deletion of nodes (events) without the need to reallocate or reorganize the entire data structure,
which is crucial for a system with high activity and frequent updates.
*/
