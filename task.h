#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <memory> 

using namespace std;

// Task class to represent individual tasks
class Task {
private:
    string description; // Task description 
    bool completed; // Task status - if the task is completed or not 

public:
    Task(string desc); //Initialize a task with description 
    void markCompleted(); // Mark task as completed 
    bool isCompleted() const; // Returns true of the task is completed 
    string getDescription() const; // Returns task description 
    void display() const; // Displays Task information 
};

// Task Manager class to handle tasks
class TaskManager {
private:
    vector<shared_ptr<Task> > tasks;  // Using smart pointers to manage memory

public:
    void addTask(const string& description); // Add a new task to the list 
    void completeTask(int index); // Marks a task as completed based on the index 
    void displayTasks() const; // Display all the tasks in the list 
    void saveTasks(const string& filename) const; // Saves tasks to a file 
    void loadTasks(const string& filename); // Load tasks from a file 
};

#endif  
