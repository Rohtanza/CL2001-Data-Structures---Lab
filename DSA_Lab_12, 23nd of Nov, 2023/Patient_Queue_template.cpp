#include <iostream>
#include <vector>
using namespace std;

class Patient {
public:
    string name;
    int urgency;

    Patient(string name, int urgency) {
        this->name=name;
        this->urgency=urgency;
    }
};

class Heap {
public:
    vector<Patient> htree;

    int getParent(int child) {
       
    }

    int getLeft(int parent) {
        
    }

    int getRight(int parent) {
        
    }

    void swap(Patient *a, Patient *b) {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) {
        
        }
    }

   
void heapifyDown(int node) {
    
}


    void insert(Patient patient) {
        
    }

    void del() {
        
    }

    void updateUrgency(string patientName, int newUrgency) {
       
    }

    void display() {
        if (htree.empty()) {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++) {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};

int main() {
    Heap priorityQueue;

    // Schedule appointments
    Patient p1 ("Ali", 3);
    Patient p2 ("Bilal", 1);
    Patient p3 ("Alina", 2);
    Patient p4 ("Hashir", 4);

    priorityQueue.insert(p1);
    priorityQueue.insert(p2);
    priorityQueue.insert(p3);
    priorityQueue.insert(p4);

    // Display appointments
    priorityQueue.display();

    // Send next patient to the doctor
    cout << "Sending next patient to the doctor:" << endl;
    priorityQueue.del();
    priorityQueue.display();

    // Update urgency level
    priorityQueue.updateUrgency("Ali", 5);
    priorityQueue.display();

    return 0;
}
