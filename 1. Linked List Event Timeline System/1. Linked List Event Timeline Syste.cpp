/*1. Linked List: Event Timeline System
Real-World Scenario:
Imagine a vibrant social networking site where users share their daily experiences through posts on their timelines. Each post represents a snapshot of a user's day, capturing moments from the most recent back to the first post of the day.

Purpose of the Linked List:
The platform must display these events in the chronological sequence they occurred, allowing users to scroll through their day's events easily. For this purpose, a linked list emerges as the optimal data structure. Here's why:

Advantages of Using a Linked List:
Efficient Event Addition:

The linked list allows for efficient addition of new events as they occur.
New events can be inserted at the beginning of the list, reflecting the most recent occurrence.
This continuous time insertion at the start is much more effective compared to other data structures like arrays.
Dynamic Size Management:

Unlike arrays, a linked list can readily accommodate a variable number of events without the need for resizing.
This flexibility is crucial in a social networking platform where the number of events per day can vary widely among users.
Natural Event Traversal:

The structure of a linked list naturally mirrors how users would naturally go through the happenings of their day.
Users typically start with the most recent events and scroll back to explore earlier moments.
Traversing from the newest to the oldest event is simple and intuitive with a linked list.
Benefits for User Experience:
Seamless Scrolling: Users can easily scroll through their timeline, smoothly transitioning from one event to the next.
Real-Time Updates: New events appear instantly at the top of the timeline, providing users with immediate access to the latest happenings.
Efficient Memory Usage: Linked lists optimize memory usage by dynamically allocating memory only when needed, reducing wasted space.
Implementation Considerations:
Node Structure: Each node in the linked list would represent a single event, containing details such as timestamp, user, post content, and links to the next event.
Insertion Logic: Adding a new event involves creating a new node and updating the pointers to maintain the linked list's continuity.
Traversal: Users can easily navigate through the timeline by following the pointers from one event to the next, allowing for seamless browsing.
Conclusion:
In summary, the use of a linked list in the Event Timeline System of a social networking platform offers numerous advantages. It provides an efficient and flexible way to manage and display a user's daily events, enhancing the overall user experience. By leveraging the inherent strengths of linked lists, such as dynamic insertion, easy traversal, and optimized memory usage, the platform can deliver a responsive and intuitive timeline interface for its users to enjoy.
*/
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
/*Real-World Scenario: Picture a social networking site where users can update their timelines. 
Every post is a snapshot of a user's day. 
From the most recent back to the first post of the day, the platform must show these events in the chronological sequence that they happened. 
For this, a linked list is the best data structure because it facilitates actions like scrolling through the day's events or adding a new event at the beginning to reflect the most recent occurrence in an effective manner.

Data Structure Suitability: The event timeline structure is ideal for a linked list because

It is effective to add new events as they occur since it permits continuous time insertion at the start.
Unlike an array, it can readily support a variable number of events without requiring resizing.
It is simple to traverse from the newest to the oldest event, mirroring how users would naturally go through the happenings of the day.
* This situation is well suited for a linked list since it makes it possible to insert and remove nodes (events) quickly and effectively without 
, having to reallocate or rearrange the entire data structure—a critical feature for a system that is updated often and experiences high activity.
*/
