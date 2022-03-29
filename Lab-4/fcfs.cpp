#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>


using namespace std;
int num=4;
    

struct Process 
{
    string name;
    int arrival_time;
    int burst_time;
    int exit_time;
   
};

void file_open(ifstream& input);
void create_process_file(ifstream& input, Process process[]);
void process_simulation (Process process[], int num);


int main() {
    ifstream input_f;
  
    //opens file
    string line;
    file_open(input_f);

      
    //creates an array of struct that will now hold the data of each process from file input
    Process *process_1 = new Process[num];
    
    //reads data from file and will update process_1 array with data
    create_process_file(input_f, process_1);
    
    //close file
    input_f.close();
    
    //caluculates the wait-time and turnaround time of the process execution
    //and prints out results
    process_simulation(process_1, num);
   
    return 0;
}

void file_open(ifstream& input){
    
       input.open("processes.txt");
       if(input.fail()) 
       {
        cout << "Input File Did not Load " << endl;
        exit(1);
       }  
}


void create_process_file(ifstream& input, Process process[]){
    
    Process *p = new Process[num];
    int min = 0, temp = 0;
    
    //gets input from file
    for(int x = 0; x < num; x++) 
    {       
        input >> process[x].name;
        input >> process[x].burst_time;
        input >> process[x].arrival_time;         
    }
    
    //sorting processes based on arrival time.
    for(int y = 1; y < num; y++) {     
        for(int z = 0; z < num - 1; z++){           
            if(process[z].arrival_time > process[z+1].arrival_time) {
                p[0] = process[z];
                process[z] = process [z+1];
                process[z+1] = p[0];             
            }
        }
    }    
}

void process_simulation (Process process[], int num) {
    
    int wait_time = 0, turn_around = 0,exit_time=0;
    float wait_time1=0;
    //calculates and prints results
     for (int y = 0; y < num; y++) {
        
        cout << "Process " << y+1 << ": ";
        wait_time1+=wait_time;
        turn_around = (turn_around + process[y].burst_time);
        
        cout << "Process Name: " << process[y].name << " | " 
             << "Arrival Time: " << process[y].arrival_time << " | " 
             << "Burst Time: " << process[y].burst_time << " | " 
             << "Wait Time: " << wait_time << "s | " 
             << "Turnaround Time: " << (turn_around - process[y].arrival_time) 
             << "s " << endl << endl;
        
        wait_time = wait_time+ process[y].burst_time;
        
    }
    cout<<"Average wait time:"<< (wait_time1/num)
        << "s " << endl << endl;
}
