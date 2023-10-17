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
    // Dodaje element na pocz¹tek listy.
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
    // Dodaje element na koniec listy.
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
    // Dodaje element pod wskazany indeks.
    void insertAt(int index, int value) {
        if (index < 0) {
            std::cout << "Nieprawidlowy index" << std::endl;
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
    // Usuwa element z pocz¹tku listy.
    void removeFromFront() {
        if (isEmpty()) {
            std::cout << "Lista jest pusta" << std::endl;
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
    //Wyświetla listę odwrotnie
    void displayReverse() {
        Node* current = tail;
         while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
    }
    std::cout << std::endl;
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
    //Usuwanie elementu z konca listy
    void removeFromEnd() {
    if (isEmpty()) {
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}
    //usuniecie z podanego indeksu
    void removeAt(int index) {
    if (index < 0) {
        std::cout << "Nieprawidlowy index" << std::endl;
        return;
    }
    if (index == 0) {
        removeFromFront();
    }
    else if (index >= size() - 1) {
        removeFromEnd();
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
     //wyswietlenie nastepnego elementu
    void displayNext(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            if (current->next != nullptr) {
                std::cout << "Następny element: " << current->next->data << std::endl;
            } else {
                std::cout << "Brak następnego elementu" << std::endl;
            }
            return;
        }
        current = current->next;
    }
    std::cout << "Element o podanej wartości nie istnieje w liście" << std::endl;
    }
    //wyswietlenie poprzedniego elementu
    void displayPrevious(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            if (current->prev != nullptr) {
                std::cout << "Poprzedni element: " << current->prev->data << std::endl;
            } else {
                std::cout << "Brak poprzedniego elementu" << std::endl;
            }
            return;
        }
        current = current->next;
    }
    std::cout << "Element o podanej wartości nie istnieje w liście" << std::endl;
    }
    //wyczyszczenie listy
    void clear() {
    while (!isEmpty()) {
        removeFromFront();
    }
    std::cout << "Lista została wyczyszczona." << std::endl;
    }
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

    std::cout << "Lista w odwrotnej kolejności: ";
    myList.displayReverse();
    
    myList.removeFromFront();
    std::cout << "Lista po usunieciu z przodu: ";
    myList.display();

    myList.removeFromEnd();
    std::cout << "Lista po usunieciu z tylu: ";
    myList.display();
    
    myList.removeAt(1);
    std::cout << "Lista po usunięciu na index 1: ";
    myList.display();

    myList.displayNext(1);
    myList.displayPrevious(1);
    
    myList.clear();
    
    return 0;
}
