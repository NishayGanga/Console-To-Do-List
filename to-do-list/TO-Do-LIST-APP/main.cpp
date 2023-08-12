#include <iostream>
#include "todolist.h"

using namespace std;

int main()
{
    ToDoList& list = ToDoList::getInstance();
    int day, month, year, pos, input, loop(0);

    while(loop == 0){
    string task = "";
    cout<<"Enter a task"<<endl;
    cin>>ws;
    getline(cin, task);
    cout<<"Enter a day the task is due, eg. 01..31"<<endl;
    cin>>day;
    cout<<"Enter the month the task is due eg. 01..12"<<endl;
    cin>>month;
    cout<<"Enter the year the task is due eg. 2023"<<endl;
    cin>>year;
    list.toString(day,month,year);
    list.AddTask(task);
    list.displayList();
    cout<<"Enter the number -1 if you want to remove something from the list"<<endl;
    cin>>input;
    if(input == -1){
        cout<<"Enter the line number you want to remove from the list"<<endl;
        cin>>pos;
        list.RemoveTask(pos);
    }
    cout<<"Do you want to add another task, enter the number 0"<<endl;
    cin>>loop;
    }


    return 0;
}
