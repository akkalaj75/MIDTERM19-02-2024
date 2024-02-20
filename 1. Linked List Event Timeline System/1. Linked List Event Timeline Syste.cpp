/*1. Linked List: Event Timeline System
Real-World Scenario: Picture a social networking site where users can update their timelines. Every post is a snapshot of a user's day. 
From the most recent back to the first post of the day, the platform must show these events in the chronological sequence that they happened. 
For this, a linked list is the best data structure because it facilitates actions like scrolling through the day's events or adding a new event at the beginning to reflect the most recent occurrence in an effective manner.

Data Structure Suitability: The event timeline structure is ideal for a linked list because

It is effective to add new events as they occur since it permits continuous time insertion at the start.
Unlike an array, it can readily support a variable number of events without requiring resizing.
It is simple to traverse from the newest to the oldest event, mirroring how users would naturally go through the happenings of the day.
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

    // Function to display the timeline
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

// Main function to demonstrate the EventTimeline class
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
* This situation is well suited for a linked list since it makes it possible to insert and remove nodes (events) quickly and effectively without 
, having to reallocate or rearrange the entire data structure—a critical feature for a system that is updated often and experiences high activity.
*/
