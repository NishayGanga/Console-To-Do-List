#ifndef TODOLIST_H
#define TODOLIST_H
#include <string>
#include <string.h>
#include <list>
#include <iostream>

using namespace std;

class ToDoList
{
public:
    static ToDoList& getInstance();
    void AddTask(string usersTask);
    void RemoveTask(int pos);
    void toString(int &userDay, int &userMonth, int &userYear);
    void displayList();
    string DisplayString();
    string gettask();
    string getdate();
private:
    ToDoList();
    ~ToDoList();
    ToDoList(const ToDoList&) = delete;
    ToDoList& operator=(const ToDoList&) = delete;
    string task;
    string date;
    list<string> taskList;
    int day, month, year;
};

#endif // TODOLIST_H
