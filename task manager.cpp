#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    void setDescription(const string& desc) {
        description = desc;
        completed = false; 
    }

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }

private:
    string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const string& description) {
        Task task;
        task.setDescription(description);
        tasks.push_back(task);
    }

    void markTaskCompleted(size_t index) {
        if (index < tasks.size()) {
            tasks[index].markCompleted();
        } else {
            cerr << "Invalid task number.\n";
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". " << tasks[i].getDescription()
                 << " [" << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]\n";
        }
    }

private:
    vector<Task> tasks;
};

void displayMenu() {
	cout << "\n\t=================================";
    cout << "\n\t    To-Do List Application";
    cout << "\n\t=================================\n	";
    cout << "\n\t1. Add Task\n";
    cout << "\t2. Mark Task as Completed\n";
    cout << "\t3. View Tasks\n";
    cout << "\t4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ToDoList todoList;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); // To ignore the leftover newline character
            string description;
            cout << "Enter task description: ";
            getline(cin, description);
            todoList.addTask(description);
            break;
        }
        case 2: {
            size_t taskNumber;
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            todoList.markTaskCompleted(taskNumber - 1);
            break;
        }
        case 3:
            todoList.viewTasks();
            break;
        case 4:
            cout << "Exiting the application.\n";
            break;
        default:
            cerr << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
