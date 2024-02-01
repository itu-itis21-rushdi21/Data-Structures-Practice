/*@Author
StudentName: MHD Kamal Rushdi
StudentID: 150210907
Date: 18/12/2023 */

#include<iostream>
#include<sstream>
#include<string.h>
#include<fstream>
#include<queue>
#include<stack>
#include<time.h>

using namespace std;
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
        //constructors
        Employee(int id, int salary, int department) {
            this->id = id;
            this->salary = salary;
            this->department = department;
        }
        //destructor
        ~Employee() {
        }
};

class Node {
    private:
        Employee* employee;
        Node* left;
        Node* right;
    public:
        //setters and getters
        Employee* get_employee() {
            return employee;
        }
        Node* get_left() {
            return left;
        }
        Node* get_right() {
            return right;
        }        
        void set_employee(Employee* employee) {
            this->employee = employee;
        }
        void set_left(Node* left) {
            this->left = left;
        }
        void set_right(Node* right) {
            this->right = right;
        }
        //constructors
        Node(Employee* employee) {
            this->employee = employee;
            this->left = NULL;
            this->right = NULL;
        }
        //destructor
        ~Node() {
        }
};

class Tree {
    private:
        Node* root;
    public:
        //setters and getters
        Node* get_root() {
            return root;
        }
        void set_root(Node* root) {
            this->root = root;
        }
        //constructors
        Tree() {
            this->root = NULL;
        }
        //destructor
        ~Tree() {
            queue<Node*> q;
            Node* temp;
            if(this->root != NULL)
                q.push(this->root);
            while(!q.empty()) {
                temp = q.front();
                q.pop();
                if(temp->get_left() != NULL)
                    q.push(temp->get_left()); 
                if(temp->get_right() != NULL)
                    q.push(temp->get_right());
                delete temp->get_employee();
                delete temp;
            }


        }
        //methods
        void insert(Employee* employee) {
            //** REMOVE FROM HERE IF NEEDED

            // this code was added to decrease the time needed to insert to the right_most of the tree
            // it servers to reduce that time from O(N) to O(1)
            // Note that without this piece of code the program will take very long time to pass the ordered_data test
            // more than 1 h probably
            // even with this part of code program will take long time 
            // this is due to the fact that this code doesn't reduce the times needed for delete and update operations (still O(N) in worst case)
            
            bool larger_than_all_ids = false; 
            if(employee->get_id() > latest_id) {
                latest_id = employee->get_id();
                larger_than_all_ids = true;
            } else if(latest_id == employee->get_id()){
                latest_id++;
                employee->set_id(latest_id);
                larger_than_all_ids = true; 
            }
            if(larger_than_all_ids == true) {
                Node* new_node = new Node(employee); 
                if(root == NULL) {
                    root = new_node;
                    return;
                }
                Node* right_most = root;
                while(right_most->get_right() != NULL) {
                    right_most = right_most->get_right();
                } 
                right_most->set_right(new_node);
                return;
            }

            //** REMOVE TO HERE IF NEEDED

            Node* new_node = new Node(employee);
            if(root == NULL) {
                root = new_node;
            } else {
                Node* temp = root;
                while(true) {
                    if(employee->get_id() < temp->get_employee()->get_id()) {
                        if(temp->get_left() == NULL) {
                            temp->set_left(new_node);
                            return;
                        }
                        temp = temp->get_left();
                    } else if(employee->get_id() > temp->get_employee()->get_id()) {
                        if(temp->get_right() == NULL) {
                            temp->set_right(new_node);
                            return;
                        }
                        temp = temp->get_right();
                    }
                }
            } 
        }

        void remove(int id) {
            if (root == NULL) {
                cout << "ERROR: An invalid ID to delete\n";
                return;
            }

            Node* current = root;
            Node* parent = NULL;
            
            while (current != NULL && current->get_employee()->get_id() != id) {
                parent = current;
                if (id < current->get_employee()->get_id()) {
                    current = current->get_left();
                } else {
                    current = current->get_right();
                }
            }

            if (current == NULL) {
                cout << "ERROR: An invalid ID to delete\n";
                return; 
            }

            // Case 1: Node with either one or children NULL
            if (current->get_left() == NULL || current->get_right() == NULL) {
                Node* newChild = current->get_left() ? current->get_left() : current->get_right();

                // If the node to be deleted is the root
                if (parent == NULL) {
                    root = newChild;
                } else if (parent->get_left() == current) {
                    parent->set_left(newChild);
                } else {
                    parent->set_right(newChild);
                }

                delete current->get_employee(); 
                delete current; 
            }
            // Case 2: Node with both children
            else {
                Node* successorParent = current;
                Node* successor = current->get_right();
                // Find inorder successor (leftmost node in the right subtree)
                while (successor->get_left() != NULL) {
                    successorParent = successor;
                    successor = successor->get_left();
                }

                // Swap values with the successor
                current->get_employee()->set_id(successor->get_employee()->get_id());
                current->get_employee()->set_salary(successor->get_employee()->get_salary());
                current->get_employee()->set_department(successor->get_employee()->get_department());

                // Delete the inorder successor
                if (successorParent != current) {
                    successorParent->set_left(successor->get_right());
                } else {
                    successorParent->set_right(successor->get_right());
                }

                delete successor->get_employee(); 
                delete successor; 
            }
        }
        Employee* search(int id) {
            Node* temp = this->root;
            while(temp != NULL) {
                if(temp->get_employee()->get_id() > id) {
                    temp = temp->get_left();
                } else if(temp->get_employee()->get_id() < id) {
                    temp = temp->get_right();
                } else {
                    return temp->get_employee();
                }
            }
            return NULL;
        }
        int getHeight() {
            queue<Node*> q;
            int height = 0;
            if(root == NULL) 
                return 0;
            q.push(root);
            while(!q.empty()) {
                int level_size = q.size();
                for(int i = 0; i < level_size; i++) {
                    Node* temp = q.front();
                    q.pop();
                    if(temp->get_left() != NULL)
                        q.push(temp->get_left());
                    
                    if(temp->get_right() != NULL)
                        q.push(temp->get_right());
                }
                height++;
            }
            return height;
        }

        void printToFile(ofstream &output_file) {
            stack<Node*> s;
            Node* temp = root;
            stringstream data;
            data<< "Employee_ID;Salary;Department"<< endl;
            while (temp != NULL || s.empty() == false) {
                // Reach the left most Node of the temp Node
                while (temp != NULL) {
                    s.push(temp);
                    temp = temp->get_left();
                }
                
                temp = s.top();
                s.pop();

                data << temp->get_employee()->get_id() << ";" << temp->get_employee()->get_salary() << ";" << temp->get_employee()->get_department() << endl;
                
                temp = temp->get_right();
            }
            if(this->root != NULL)
                output_file << data.rdbuf();
        }  

        void printToConsole() {
            stack<Node*> s;
            Node* temp;
            if(this->root != NULL)
                s.push(this->root);
            while(!s.empty()) {
                temp = s.top();
                s.pop();
                cout << temp->get_employee()->get_id() << ";" << temp->get_employee()->get_salary() << ";" << temp->get_employee()->get_department() << "\n";
                if(temp->get_right() != NULL) {
                    s.push(temp->get_right());
                }
                if(temp->get_left() != NULL) {
                    s.push(temp->get_left());
                }
            }
        }
        
};

int main(int argc, char* argv[]) {
    //clock_t start = clock();
    fstream read_file;
    read_file.open(argv[1], ios::in);
    if(!read_file) {
        cout << "Cannot open read file!" << endl;
        return 1;
    }

    string unused;
    getline(read_file, unused);
    Tree* employees_tree = new Tree();
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
            employees_tree->insert(employee);
        }
    }
    read_file.close();

    fstream operation_file;
    operation_file.open(argv[2], ios::in);
    if(!operation_file) {
        cout << "Cannot open operation file!" << endl;
        return 1;
    }
    
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
            // these news are deleted inside the remove function and inside the tree destructor
            Employee* employee = new Employee(latest_id, stoi(salary), stoi(department));
            employees_tree->insert(employee);
        } else if(operation_type == "UPDATE") {
            getline(ss_operation, id, ';');
            getline(ss_operation, salary, ';');
            getline(ss_operation, department);
            Employee* employee = employees_tree->search(stoi(id));
            if(employee == NULL) {
                cout<< "ERROR: An invalid ID to update\n";
            } else {
                employee->set_salary(stoi(salary));
                employee->set_department(stoi(department));
            }
        } else if(operation_type == "DELETE"){
            getline(ss_operation, id);
            employees_tree->remove(stoi(id));
        } else if(operation_type == "PRINT"){
            cout<< "P\n";
            employees_tree->printToConsole();
        } else if(operation_type == "HEIGHT") {
            cout << "H " << employees_tree->getHeight() << "\n";
        }
    }
    
    operation_file.close();
    ofstream write_file;
    write_file.open("output.csv");
    if(!write_file) {
        cout<< "Cannot open write file" << endl;
        return 1;
    } 
    employees_tree->printToFile(write_file);
    write_file.close(); 
    delete employees_tree;

    // clock_t end = clock();
    // (double) (end - start) * 1000 / CLOCKS_PER_SEC;
    return 0;
}