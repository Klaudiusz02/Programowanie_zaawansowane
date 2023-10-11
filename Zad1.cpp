#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    // Dodaj element na pocz¹tek listy.
    void addToFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    // Dodaj element na koniec listy.
    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    // Dodaj element pod wskazany indeks.
    void insertAt(int index, int value) {
        if (index < 0) {
            std::cout << "Invalid index." << std::endl;
            return;
        }
        if (index == 0) {
            addToFront(value);
        }
        else {
            Node* newNode = new Node(value);
            if (index >= size()) {
                addToEnd(value);
            }
            else {
                Node* current = head;
                for (int i = 0; i < index; i++) {
                    current = current->next;
                }
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }
    // Usuñ element z pocz¹tku listy.
    void removeFromFront() {
        if (isEmpty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    // Zwraca iloœæ elementów w liœcie.
    int size() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    // Sprawdza, czy lista jest pusta.
    bool isEmpty() const {
        return head == nullptr;
    }
    // Wyœwietla zawartoœæ listy.
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    DoublyLinkedList myList;

    std::cout << "Pusta lista : ";
    myList.display();
    myList.addToFront(1);
    myList.addToFront(2);
    myList.addToEnd(3);
    std::cout << "Lista po dodaniu elementow : ";
    myList.display();
    myList.insertAt(1, 4);
    std::cout << "Lista po dodaniu na index 1: ";
    myList.display();
    myList.removeFromFront();
    std::cout << "Lista po usunieciu z przodu: ";
    myList.display();
    return 0;
}
