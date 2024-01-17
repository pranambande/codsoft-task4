#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;

    Task(const std::string& desc) : description(desc) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask(description);
        tasks.push_back(newTask);
        std::cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << "\n";
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};
void displayMenu() {
    std::cout << "1. Add a new task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Remove task\n";
    std::cout << "4. Quit\n";
}

int main() {
    ToDoList toDoList;

    while (true) {
        displayMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear buffer
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int index;
                std::cout << "Enter the task index to remove: ";
                std::cin >> index;
                toDoList.removeTask(index);
                break;
            }
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
