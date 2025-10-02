
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size >= capacity) {
        throw "List full";
    }
    names[size] = new char[strlen(name) + 1];
    strcpy(names[size], name);

    gpas[size] = gpa;
    size++;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr != nullptr) {
        *gpaPtr = newGpa;
    }
}
// TODO: implement printStudent

void printStudent(const char* name, const double& gpa) {
    std::cout << name << ", " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) {
    double sum = 0;
    if (size <= 0 || gpas == nullptr) {
        throw "No students";
    }
    for (int i = 0; i < size; i++) {
        sum += gpas[i];
    }
    return sum / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                char sp[100];
                double gpa;

                std::cout << "Enter name: ";
                std::cin >> sp;
                std::cout << "Enter GPA: ";
                std::cin >> gpa;
                try {
                    addStudent(sp, gpa, names, gpas, size, capacity);
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                int idx;
                double newGpa;

                std::cout << "Enter student index (0–" << size - 1 << "): ";
                std::cin >> idx;

                if (idx < size && idx >= 0) {
                    std::cout << "Enter new GPA: ";
                    std::cin >> newGpa;
                    updateGPA(&gpas[idx], newGpa);
                } else {
                    std::cout << "Wrong index!" << std::endl;
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic
                for (int i = 0; i < size; i++) {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try {
                    double avg = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << avg << std::endl;
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; i++) {
        delete[] names[i];
    }

    return 0;
}
