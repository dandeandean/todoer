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

void print_menu(std::string version) {
    std::cout << "TODOer (" << version <<") | A TODO Manager... \nTASKS:\n\n";
    std::cout << " /$$$$$$$$ /$$$$$$  /$$$$$$$   /$$$$$$                         \n";
    std::cout << "|__  $$__//$$__  $$| $$__  $$ /$$__  $$                        \n";
    std::cout << "   | $$  | $$  \\ $$| $$  \\ $$| $$  \\ $$  /$$$$$$   /$$$$$$  \n" ;
    std::cout << "   | $$  | $$  | $$| $$  | $$| $$  | $$ /$$__  $$ /$$__  $$    \n";
    std::cout << "   | $$  | $$  | $$| $$  | $$| $$  | $$| $$$$$$$$| $$  \\__/   \n";
    std::cout << "   | $$  | $$  | $$| $$  | $$| $$  | $$| $$_____/| $$          \n";
    std::cout << "   | $$  |  $$$$$$/| $$$$$$$/| $$$$$$/|  $$$$$$$| $$           \n";
    std::cout << "   |__/   \\______/ |_______/  \\______/  \\_______/|__/       \n";
    std::cout << "_______________________________________________________________\n";
}

void show_options(void) {

}
void show_tasks( std::__1::list<Task> tasks ){
        std::list<Task>::iterator it;
        for (it=tasks.begin(); it != tasks.end(); it ++ ) {
            std::string doneness = it->isDone()? "Done" : "TODO";
            std::cout << it->getId() 
                << " | " << it->getDescription() 
                << " | " << doneness 
                << "\n";
        }
}

int main( void ) {
    std::list<Task> tasks;
    std::list<Task>::iterator it;
    tasks.clear();
    std::string VERSION = "v1.0";
    char input_option;
    int id_buf;
    std::string desc_buffer;


    Task new_task;
    // Gamer Loop
    while (input_option != 'q') {
        system("clear");
        show_tasks(tasks);

        if (tasks.empty()){
            print_menu(VERSION);
        }
        std::cout << "What's next?\n" 
            << "[a]dd\n"
            << "[c]omplete\n"
            << "[r]emove\n"
            << "[q]uit\n->";
        std::cin.clear(); // This is needed to fix getting too much input
        std::cin >> input_option;
        switch (input_option){

            case ('c'):
                std::cout << "Enter ID to complete \n\t->";
                std::cin.clear();
                std::cin >> id_buf;
                for (it=tasks.begin(); it != tasks.end(); it ++ ) {
                    if (it->getId() == id_buf){
                        it->finish();
                        break;
                    }
                }
                break;

            case ('a'):
                std::cout << "Please input the description \n\t->";
                std::cin.clear();
                std::cin.ignore();
                std::getline(std::cin, desc_buffer);
                new_task.create(tasks.size() , desc_buffer);
                tasks.push_back(new_task);
                break;

            case ('r'):
                std::cout << "Enter ID to delete \n\t->";
                std::cin.clear();
                std::cin >> id_buf;
                for (it=tasks.begin(); it != tasks.end(); it ++ ) {
                    if (it->getId() == id_buf){
                        tasks.erase(it);
                        break;
                    }
                }
                break;

            default: 
                break;

        }

    }

    return 0;
}