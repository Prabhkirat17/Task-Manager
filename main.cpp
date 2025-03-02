#include "task.h"

int main() {
    TaskManager manager;
    manager.loadTasks("tasks.txt"); // Load previously saved tasks from the file
    int choice;
    string desc;

    do {
        // Display menu options
        cout << "\nTask Manager" << endl;
        cout << "1. Add Task\n2. Mark Task as Completed\n3. View Tasks\n4. Save & Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer to handle new lines

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, desc);
                manager.addTask(desc);
                break;
            case 2:
                manager.displayTasks();
                cout << "Enter task number to mark as completed: ";
                int index;
                cin >> index;
                manager.completeTask(index - 1);
                break;
            case 3:
                manager.displayTasks();
                break;
            case 4:
                manager.saveTasks("tasks.txt");
                cout << "Tasks saved. Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
