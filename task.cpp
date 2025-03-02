#include "task.h"

// Task class method implementations
Task::Task(string desc) : description(desc), completed(false) {} // Initializes the task with a description

void Task::markCompleted() { completed = true; } // Marks the task as completed 

bool Task::isCompleted() const { return completed; } // Returns true if the task is completed, false otherwise

string Task::getDescription() const { return description; } // Returns the task description 

// Displays the task with indication of the completion status 
void Task::display() const {
    cout << "[" << (completed ? "✔" : "✖") << "] " << description << endl;
}

// TaskManager class method implementations
// Adds a new task to the list
void TaskManager::addTask(const string& description) {
    tasks.push_back(make_shared<Task>(description));
}

// Marks a specific task as completed by its index
void TaskManager::completeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index]->markCompleted();
    } else {
        cerr << "Invalid task index!" << endl;
    }
}

// Displays all tasks, handling the case when no tasks are available
void TaskManager::displayTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";
        tasks[i]->display();
    }
}

// Saves all tasks to a specified file in a CSV format
void TaskManager::saveTasks(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for saving!" << endl;
        return;
    }
    for (const auto& task : tasks) {
        file << task->getDescription() << "," << task->isCompleted() << endl;
    }
    file.close();
}

// Loads tasks from a specified file, ensuring proper format handling
void TaskManager::loadTasks(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "No previous task data found." << endl;
        return;
    }
    tasks.clear(); // Clear any existing tasks before loading new ones
    string description;
    int completed;
    while (getline(file, description, ',') && file >> completed) {
        file.ignore();  // Ignore newline
        auto task = make_shared<Task>(description);
        if (completed) task->markCompleted();
        tasks.push_back(task);
    }
    file.close();
}
