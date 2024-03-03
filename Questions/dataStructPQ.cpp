#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int id;
    int priority;
    Node* next;
};

class PQueue {
private:
    unordered_map<int, Node*> priorityMap;
    Node* head;

public:
    PQueue() {
        head = nullptr;
    }

    void insert(int id, int priority) {
        Node* newNode = new Node;
        newNode->id = id;
        newNode->priority = priority;
        newNode->next = nullptr;

        if (head == nullptr || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr && curr->next->priority >= priority) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        priorityMap[id] = newNode;
    }

    int deleteMax() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
            return -1; // or any appropriate error code
        }

        Node* temp = head;
        head = head->next;
        int deletedId = temp->id;
        priorityMap.erase(deletedId);
        delete temp;

        return deletedId;
    }
};

int main() {
    PQueue pq;
    pq.insert(100, 1);
    pq.insert(101, 1);
    pq.insert(102, 2);
    pq.insert(103, 4);
    pq.insert(104, 4);
    pq.insert(105, 5);
    pq.insert(106, 2);
    pq.insert(107, 1);
    pq.insert(109, 2);

    cout << pq.deleteMax() << endl;
    cout << pq.deleteMax() << endl;
    cout << pq.deleteMax() << endl;
    cout << pq.deleteMax() << endl;

    return 0;
}
