#include <filesystem>
#include <iostream>
#include<fstream>
#include<vector>
#include<string>


class Task {
private:
    std::string title;
    std::string description;
    std::string due_date;
    bool completed;

public:

    void set_title(std::string& title) {
        this ->title = title;
    }

    void setDescription(const std::string& new_description) {
        this-> description = new_description;
    }

    void setDueDate(const std::string& new_due_date) {
        this->due_date = new_due_date;
    }

    void markCompleted(bool completed) {
        this->completed = completed;
    }

    void displayTask() const {
        std::cout << title;
        std::cout << description;
        // optimiZe lAter
    }

    std::string getTitle() {
        return title;
    }

    std::string getDescription() {
        return  description;
    }

    std::string getDueDate() {
        return  due_date;
    }

    bool isCompleted() const{
        return completed;
    }

};

class ToDoList {

private:
    std::vector<Task> tasks;


public:
    void addTask( Task& new_task) {
        std::string title;
        std::cout << "Enter your task title: ";
        std::getline(std::cin, title);

        new_task.set_title(title);

        tasks.push_back(new_task);
    };

    void removeTask(std::string& task_title) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->getTitle() == task_title) {
                tasks.erase(it);
                break;
            }
        }
    }

    void updateTask( std::string& task_title) {
        std::cout << "What would you like to update as the new description? " << "\n";

        for( auto i = tasks.begin(); i != tasks.end(); i++) {
            if (i->getTitle() == task_title) {
                i->set_title(task_title);
            }
        }

    };

    void markTaskCompleted( std::string& task_title) {
        for( auto i = tasks.begin(); i != tasks.end(); i++) {
            if (i->getTitle() == task_title) {
                i->markCompleted(true);
            }
        }
    };

    void displayAllTasks() const {
        for(auto i : tasks) {
            std::cout << "Task: " << i.getTitle() << "\n";
            std::cout << "      "<< i.getDescription() << " \n";
        }
    };

    void displayIncompleteTasks() const {
        for(auto i : tasks) {
            if(!i.isCompleted()) {
                std::cout << i.getTitle();
            }
        }
    };

    void displayCompletedTasks() const {
        for(auto i : tasks) {
            if(i.isCompleted()) {
                std::cout << i.getTitle();
            }
        }
    };

    bool taskExists(const std::string& task_title) const {
        for(auto i : tasks) {
            if (i.getTitle() == task_title) {
                std::cout << " Task Exist! ";
                return true;
            }
        }
        std::cout << "Task Does Not Exist :( ";
        return  false;
    };

    void saveToFile( std::string& filename) const {
        std::ofstream myfile (filename);


            for( auto i : tasks) {
                myfile << i.getTitle() << "\n" << i.getDescription() << "\n" << i.isCompleted() << "\n";
            }



    };

    void loadFromFile( std::string& filename) {
        std::string contents;
        std::ifstream myfile (filename);


            while(!myfile.eof()) {
                std::getline(myfile,contents);

            }

    };

};

class Primary {
private:
    ToDoList Todo;
    Task t;

public:
    void displayMenu() {
        std::cout<< "1. Create Task: \n";
        std::cout<< "2. Remove Task:  \n";
        std::cout<< "3. Update Task:  \n";
        std::cout<< "4. Review Task: \n";
        std::cout<< "5. Save Task: \n";
        std::cout<< "6. Load Previous Task: \n";
        std::cout<< "7. Exit Program: \n";
    };
    void executeOption(int option);
    void userInput() {
        int input;
        std::cin >> input;
        std::cin.ignore();
        switch(input){

            case 1: {
                Todo.addTask(t);
                break;
            }

            case 2: {
                std::string title;
                std::cout << "Enter the task you would like to remove: "; std::cin >> title;
                Todo.removeTask(title);
                break;
            }

            case 3: {
                std::string title;
                std::cout << "Enter the task you would like to update: "; std::cin >> title;
                Todo.updateTask(title);
                break;
            }

            case 4: {
                Todo.displayAllTasks();
                break;
            }

            case 5: {
                std::string title;
                std::cout << "Enter the task you would save to file: "; std::cin >> title;
                Todo.saveToFile(title);
                break;
            }

            case 6: {
                std::string title;
                std::cout << "Enter the file you would save to open: "; std::cin >> title;
                Todo.loadFromFile(title);
                break;

            }

            case 7: {
                std::cout << "exiting program...";
                break;

            }

        }

    };
    void displayWelcomeMessage() {
        std::cout << " Hello! Welcome to the to do list project.";
    };
    void handleFileOperations();
};

int main() {

    Primary program;

    bool running = false;

    do {
        running = true;
        program.displayMenu();
        program.userInput();


    }while(running == true);


    return 0;
}
