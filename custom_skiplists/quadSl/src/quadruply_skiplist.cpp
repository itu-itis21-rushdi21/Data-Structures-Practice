/*@Author
StudentName: MHD Kamal Rushdi
StudentID: 150210907
Date: 08/01/2023 */

#include<iostream>
// used for reading and writing files, and string manipulation
#include<sstream>
#include<string.h>
#include<fstream>
// used for saving prev and next nodes in the insert function
#include<stack>
// used for random number generation and time
#include <cstdlib>
#include <ctime>
// used to set the max and min values of int in the sentinels
#include<limits>

using namespace std;
// global variable to keep track of the latest id
int latest_id = 0;

class Employee {
    private:
        int id;
        int salary;
        int department;
    public:
        //setters and getters
        int get_id() {
            return id;
        }

        int get_salary() {
            return salary;
        }

        int get_department() {
            return department;
        }

        void set_id(int id) {
            this->id = id;
        }

        void set_salary(int salary) {
            this->salary = salary;
        }

        void set_department(int department) {
            this->department = department;
        }
        //constructor
        Employee(int id, int salary, int department) {
            this->id = id;
            this->salary = salary;
            this->department = department;
        }
        //destructor
        ~Employee() {
        }
};

class QuadruplySkipList_Node {
    private:
        Employee* data;
        QuadruplySkipList_Node* next;
        QuadruplySkipList_Node* prev;
        QuadruplySkipList_Node* below;
        QuadruplySkipList_Node* above;
    public:
        QuadruplySkipList_Node(Employee* data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
            this->below = NULL;
            this->above = NULL;
        }
        // destructor
        ~QuadruplySkipList_Node() {
        }
        // setters and getters
        Employee* get_data() {
            return data;
        }

        QuadruplySkipList_Node* get_next() {
            return next;
        }

        QuadruplySkipList_Node* get_prev() {
            return prev;
        }

        QuadruplySkipList_Node* get_below() {
            return below;
        }

        QuadruplySkipList_Node* get_above() {
            return above;
        }

        void set_data(Employee* data) {
            this->data = data;
        }

        void set_next(QuadruplySkipList_Node* next) {
            this->next = next;
        }

        void set_prev(QuadruplySkipList_Node* prev) {
            this->prev = prev;
        }

        void set_below(QuadruplySkipList_Node* below) {
            this->below = below;
        }

        void set_above(QuadruplySkipList_Node* above) {
            this->above = above;
        }
};

class QuadruplySkipList {
    private:
        QuadruplySkipList_Node* head;
        QuadruplySkipList_Node* tail;
        int height;
    public:
        QuadruplySkipList(int height_in) {
            // one pointer to data of all vertically aligned nodes saves memeory and enable better searches
            Employee* head_data = (new Employee(numeric_limits<int>::min(), -1, -1));
            Employee* tail_data = (new Employee(numeric_limits<int>::max(), -1, -1));
            // create the head and tail nodes
            head = new QuadruplySkipList_Node(head_data);
            tail = new QuadruplySkipList_Node(tail_data);
            // link the head and tail (sentinels)
            head->set_next(tail);
            tail->set_prev(head);

            this->height = height_in;

            QuadruplySkipList_Node* new_head_lvl;
            QuadruplySkipList_Node* new_tail_lvl;
            QuadruplySkipList_Node* old_head;
            QuadruplySkipList_Node* old_tail;
            // create the rest of the lvls
            for(int i = 0; i < height_in - 1; i++) {
                // create the new lvl
                new_head_lvl = new QuadruplySkipList_Node(head_data);
                new_tail_lvl = new QuadruplySkipList_Node(tail_data);
                // set the old lvl above to the new lvl
                head->set_above(new_head_lvl);
                tail->set_above(new_tail_lvl);
                old_head = head;
                old_tail = tail;
                // go up one lvl
                head = head->get_above();
                tail = tail->get_above();     
                // set the new lvl below to the old lvl
                head->set_below(old_head);
                tail->set_below(old_tail);
                // link the head and tail (sentinels) of the new lvl
                head->set_next(tail);
                tail->set_prev(head);
            }
        }
        // destructor
        ~QuadruplySkipList() {
            // we destroy the list lvl by lvl from the up to the bottom
            // current lvl
            QuadruplySkipList_Node* current_lvl = head;
            // current node
            QuadruplySkipList_Node* current;
            // next lvl
            QuadruplySkipList_Node* next_lvl;
            // next node
            QuadruplySkipList_Node* next_current;
            // itreate over the lvls until we reach the bottom (NULL)
            while(current_lvl != NULL) {
                next_lvl = current_lvl->get_below();
                current = current_lvl;
                while(current != NULL) {
                    next_current = current->get_next();
                    
                    // employee is deleted one time in the bottom list
                    if(next_lvl == NULL) {
                        delete current->get_data();
                    }
                    
                    delete current;
                    current = next_current; 
                }
                current_lvl = next_lvl;
            }
        }
        // setters and getters
        QuadruplySkipList_Node* get_head() {
            return head;
        }

        QuadruplySkipList_Node* get_tail() {
            return tail;
        }

        int get_height() {
            return height;
        }

        void set_head(QuadruplySkipList_Node* head) {
            this->head = head;
        }

        void set_tail(QuadruplySkipList_Node* tail) {
            this->tail = tail;
        }

        void set_height(int height) {
            this->height = height;
        }
        // functions
        void insert(Employee* data) {
            // id logic
            // cover initial adding when shuffled
            if(data->get_id() > latest_id) {
                latest_id = data->get_id();
            // cover adding new values after initial
            } else if(data->get_id() == latest_id) {
                latest_id++;
                data->set_id(latest_id);
            }
            
            // random lvl of the new added node
            int node_height = 1;
            while(node_height < this->height && rand()%2 == 0) {
                node_height++;
            }
            // create the new added node lvl 1
            QuadruplySkipList_Node* n_node = new QuadruplySkipList_Node(data);
            // pointer to the lvl_1 when inserting
            QuadruplySkipList_Node* n_lvl = n_node;
            // add the other lvls if exist
            QuadruplySkipList_Node* new_lvl;
            QuadruplySkipList_Node* old_lvl;
            // create the rest of the lvls if exist
            for(int i = 0; i < node_height - 1; i++) {
                new_lvl = new QuadruplySkipList_Node(data);
                // set the above and below pointers
                n_node->set_above(new_lvl);
                old_lvl = n_node;
                n_node = n_node->get_above();
                n_node->set_below(old_lvl);
            }
            // find all the previous and the next pointers of the new node
            QuadruplySkipList_Node* it = head;
            stack<QuadruplySkipList_Node*> prev_ptrs;
            stack<QuadruplySkipList_Node*> next_ptrs;
            // we stop when we reach the bottom
            while(it != NULL) {
                // when we overshoot the value we save a possible prev and next the we go down
                if(it->get_next()->get_data()->get_id() > data->get_id()) {
                    prev_ptrs.push(it);
                    next_ptrs.push(it->get_next());
                    it = it->get_below();
                } else {
                    it = it->get_next();
                }
            }
            // insert the node
            // we will use only the needed pointers from the stacks 
            // the rest will remain the same (heigher than added node)
            for(int i = 0; i < node_height; i++) {
                QuadruplySkipList_Node* prev_temp = prev_ptrs.top();
                QuadruplySkipList_Node* next_temp = next_ptrs.top();
                prev_ptrs.pop();
                next_ptrs.pop();
                // we link from bottom up
                prev_temp->set_next(n_lvl);
                n_lvl->set_prev(prev_temp);
                next_temp->set_prev(n_lvl);
                n_lvl->set_next(next_temp);
                // go up one lvl
                n_lvl = n_lvl->get_above();
            }
            // the other stack elements (heigher than added node remain the same)
        }

        void remove(int id) {
            // find the node to be deleted
            QuadruplySkipList_Node* it = head;
            while(it != NULL) {
                if(it->get_data()->get_id() == id) {
                    break;
                }
                if(it->get_next()->get_data()->get_id() > id) {
                    it = it->get_below();
                } else {
                    it = it->get_next();
                }
            }
            // if it is NULL then we didn't find the value
            if(it == NULL) {
                cout << "ERROR: An invalid ID to delete\n";
                return;
            }
            // it have pointer to the top of the node to be deleted
            // we delete top down while setting prev and next
            QuadruplySkipList_Node* prev_temp; 
            QuadruplySkipList_Node* next_temp; 
            QuadruplySkipList_Node* below_temp;
            // we have one pointer employee so we delete it once
            delete it->get_data();
            // we itreate over the node to be deleted and delete lvl by lvl until we reach the bottom
            while(it != NULL) {
                // save "it" below, prev and next
                below_temp = it->get_below();
                prev_temp = it->get_prev();
                next_temp = it->get_next();
                // delete the node "it" is pointing to
                delete it;
                // set the prev and next of it to each other
                prev_temp->set_next(next_temp);
                next_temp->set_prev(prev_temp);
                // we iterate below till we reach the edge with NULL
                it = below_temp;
            }
            return;
        }

        Employee* search(int search_id) {
            QuadruplySkipList_Node* it = head;
            // we stop when we reach the bottom
            while(it != NULL) {
                // if we found the value return it
                if(it->get_data()->get_id() == search_id) {
                    return it->get_data();
                }
                // if we overshoot the value we go down
                if(it->get_next() != NULL) {
                    if(it->get_next()->get_data()->get_id() > search_id) {
                        it = it->get_below();
                    } else {
                        it = it->get_next();
                    }
                }
            }
            // if we didn't find the value return NULL (we reached the bottom and hit NULL)
            return NULL;
        }

        void dumpToFile(ofstream& out_file) {
            QuadruplySkipList_Node* temp = head;
            stringstream data;
            data<< "Employee_ID;Salary;Department"<< endl;
            // go as down as possiable
            while(temp->get_below() != NULL) {
                temp = temp->get_below();
            }
            // start from after the head
            temp = temp->get_next();
            //now iterate over the bottom list to print all the values
            // we compare get data not temp and tail cause temp is pointing to the bottom of the tail while tail points to the top 
            while(temp->get_data() != tail->get_data()) {
                data << temp->get_data()->get_id() << ";" << temp->get_data()->get_salary() << ";" << temp->get_data()->get_department() << endl;
                temp = temp->get_next();
            }
            if(head != tail) {
                out_file << data.rdbuf();
            }
        }
};

int main(int argc, char* argv[]) {
    
    // seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //clock_t start = clock();
    // create the skip list
    // initial height is 15 cause it is suitable for 500k id
    // the most suitable height is log2(n) where n is the number of ids
    QuadruplySkipList* S = new QuadruplySkipList(15); 
    
    fstream read_file;
    read_file.open(argv[1], ios::in);
    if(!read_file) {
        cout << "Cannot open read file!" << endl;
        return 1;
    }
    // skip the first line
    string unused;
    getline(read_file, unused);
    // read the file line by line and insert the employees
    string line;
    while(!read_file.eof()) {
        getline(read_file, line);
        if(line != ""){
            istringstream ss_line(line);
            string id, salary, department;
            getline(ss_line, id, ';');
            getline(ss_line, salary, ';');
            getline(ss_line, department);
            Employee* employee = new Employee(stoi(id), stoi(salary), stoi(department));
            S->insert(employee);
        }
    }
    read_file.close();
    // open the operation file
    fstream operation_file;
    operation_file.open(argv[2], ios::in);
    if(!operation_file) {
        cout << "Cannot open operation file!" << endl;
        return 1;
    }
    // read the file line by line and apply the operations
    string operation;
    while(!operation_file.eof()) {
        getline(operation_file, operation);
        istringstream ss_operation(operation);
        string operation_type;
        getline(ss_operation, operation_type, ';');
        string id, salary, department;
        if(operation_type.back() == '\r' && !operation_type.empty()){
            operation_type.pop_back();
        }        
        if(operation_type == "ADD") {
            getline(ss_operation, salary, ';');
            getline(ss_operation, department);
            Employee* employee = new Employee(latest_id, stoi(salary), stoi(department));
            S->insert(employee);
        } else if(operation_type == "UPDATE") {
            getline(ss_operation, id, ';');
            getline(ss_operation, salary, ';');
            getline(ss_operation, department);
            Employee* employee = S->search(stoi(id));
            // if the id is not found we print an error
            if(employee == NULL) {
                cout<< "ERROR: An invalid ID to update\n";
            } else {
                employee->set_salary(stoi(salary));
                employee->set_department(stoi(department));
            }
        } else if(operation_type == "DELETE"){
            getline(ss_operation, id);
            S->remove(stoi(id));
        }
    }
    // close the files
    operation_file.close();
    ofstream write_file;
    write_file.open("quadruply_output.csv");
    if(!write_file) {
        cout<< "Cannot open write file" << endl;
        return 1;
    } 
    // dump the list to the file
    S->dumpToFile(write_file);
    write_file.close(); 

    //clock_t end = clock();
    //cout << (double) (end - start) * 1000 / CLOCKS_PER_SEC;
    
    // delete the list (free the memory)
    delete S;

    return 0;
}