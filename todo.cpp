#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i=0; i<MAX_TASKS; i++){
        tasks[i] = nullptr;
    }

}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i=0; i<MAX_TASKS;i++){
        delete[] tasks[i];
        tasks[i] = nullptr;
    }

}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int len=0;
    while (str[len] != '\0'){
        len = len + 1;
    }
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int len_src = string_length(src);

    for (int i=0;i<len_src;i++){
        dest[i] = src[i];
    }

    dest[len_src] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    int num_task=0;
    int len_task = string_length(task);

    for (int i=0;i<MAX_TASKS;i++){
        if (tasks[i] != nullptr){
            num_task = num_task + 1;
        }
        else {
            tasks[i] = new char[len_task];
            string_copy(tasks[i], task);
            return;
        }
    }
    
    throw std::overflow_error("Task list is full");   // throw when full
    
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    int num_task=0;
    while (tasks[num_task] != nullptr){
        num_task = num_task + 1;
    }

    if (index < 0 || index >= MAX_TASKS){
        throw std::out_of_range("Invalid task index");
    }
    else{
        delete[] tasks[index];
        for (int i=index;i<num_task-1;i++){
            tasks[i] = tasks[i+1];       // memory에서 data는 그대로 있고, pointer만 바뀐다. tasks[3]이 delete되면 tasks[3]의 새로운 pointer를 tasks[4]가 원래 찍던 곳에 찍도록 한다. 
        }
        tasks[num_task-1] = nullptr;    // 마지막 task pointer는 nullptr이 된다.
    }
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = 0;
    while (tasks[count] != nullptr){
        count = count + 1;
    }

    return const_cast<const char**>(tasks);
}