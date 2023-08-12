#include "todolist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;
ToDoList::ToDoList() {

}
ToDoList::~ToDoList(){}

ToDoList& ToDoList::getInstance(){
    static ToDoList instance;
    return instance;
}

string ToDoList::getdate(){
    return date;
}

string ToDoList::gettask(){
    return task;
}

void ToDoList::AddTask(string usersTask){
    task = usersTask;


    ofstream OutputFile("data.txt", std::ios::app);

    if(OutputFile.is_open()){
        OutputFile<<DisplayString()<<endl;;
        OutputFile.close();
    }

    else{
        cerr<<"Error opening file.\n";
    }
}

string ToDoList::DisplayString(){
    string d = getdate();
    string t = gettask();
    string output = t +" "+ "- " + d;

    return output;
}

void ToDoList::toString(int &userDay, int &userMonth, int &userYear){
    day = userDay;
    month = userMonth;
    year = userYear;

    date = to_string(day)+"/"+to_string(month)+"/"+to_string(year);



}

void ToDoList::RemoveTask(int pos){
    ifstream InputFile("data.txt");
    string line;
    if(InputFile.is_open()){

        while (getline(InputFile, line)) {
        taskList.push_back(line);
            cout<<endl;
        }

    InputFile.close();
    }
    else{
        cerr<<"Error opening file";
    }

    pos = pos -1;

    auto it = next(taskList.begin(), pos);
    taskList.erase(it);

    const char* filename = "data.txt";
    remove(filename);

    ofstream OutputFile("data.txt");

    if(OutputFile.is_open()){
        for(auto l=taskList.begin(); l!=taskList.end();l++){
        OutputFile<<*l;
        }
        OutputFile.close();
    }
    else{
        cerr<<"Error opening file.\n";
    }
}

void ToDoList::displayList(){
    ifstream InputFile("data.txt");

    if(InputFile.is_open()){
        string line;
        while (getline(InputFile, line)) {
        cout<<line<<endl;
        }

        InputFile.close();
    }
    else{
        cerr<<"Error opening file";
    }
}
