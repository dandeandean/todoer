#include <iostream>
#include <list>

class Task {
private:
    int id;
    std::string description;
    bool done;
public:
    Task() : id(0), description(""), done(false) {}
    bool create(int new_id, std::string new_desc){
        id = new_id;
        description = new_desc;
        return true;
    }
    int getId(void) {return id;}
    std::string getDescription(void) {return description;}
    bool isDone(void) { return done;}
    void finish(void) {done = true; }
};


int main( void ) {
    std::list<Task> tasks;
    std::list<Task>::iterator it;
    tasks.clear();
    std::string VERSION = "v1.0";
    char input_option;
    int completed_id;
    std::string desc_buffer;


    Task new_task;
    // Gamer Loop
    while (true) {
        system("clear");
        std::cout << "TODOer (" << VERSION <<") | A TODO Manager... \nTASKS:\n\n";
        for (it=tasks.begin(); it != tasks.end(); it ++ ) {
            std::string doneness = it->isDone()? "Done" : "TODO";
            std::cout << it->getId() 
                << " | " << it->getDescription() 
                << " | " << doneness 
                << "\n";
        }
        if (tasks.empty()){
            std:: cout << "Looks like you're all done!\n";
        }
        std::cout << "What's next?\n" 
            << "[a]dd\n"
            << "[c]omplete\n"
            << "[r]emove\n"
            << "[q]uit\n ->";
        std::cin >> input_option;
        switch (input_option){
            case ('q'):
                // TODO: This is bad
                break;

            case ('c'):
                std::cout << "Enter ID to complete \n->";
                std::cin >> completed_id;
                for (it=tasks.begin(); it != tasks.end(); it ++ ) {
                    if (it->getId() == completed_id){
                        it->finish();
                        break;
                    }
                }
                break;

            case ('a'):
                std::cout << "Please input the description \n->";
                std::cin.clear();
                std::cin.ignore();
                std::getline(std::cin, desc_buffer);
                new_task.create(tasks.size() , desc_buffer);
                tasks.push_back(new_task);
                break;

            case ('r'):
                break;

            default: 
                break;

        }

    }

    return 0;
}