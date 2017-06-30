/*11995-DataStructures*/

#include <iostream>

using namespace std;

   
//QUEUE------------------------------

int queue[501103];
int first_queue, last_queue;
int queue_test;   

int pop_queue(){
    if(first_queue <= last_queue){
        first_queue++;
        return queue[first_queue - 1];
    }
    return -1;
}
void bushback_queue(int n){
    last_queue++;
    queue[last_queue] = n;
}
//-----------------------------------



//STACK------------------------------
int stack[510103];
int first_stack;
int stack_test;

int pop_stack(){
    if(first_stack >= 1){
        first_stack--;
        return stack[first_stack + 1];    
    }
    return -1;
}
void bush_stack(int n){
    first_stack++;
    stack[first_stack] = n;        
}
//-----------------------------------



//PRIORITY QUEUE---------------------
int priority_queue[510103];
int priority_queue_test;
int first_p_queue;
int last_p_queue;
int a;

void bush_priority_queue(int n){
    if(first_p_queue <= last_p_queue){
        last_p_queue++;
        priority_queue[last_p_queue] = n;
        for(int i = last_p_queue; i > first_p_queue; i--){
            if(priority_queue[i] > priority_queue[i - 1]){
                a = priority_queue[i];
                priority_queue[i] = priority_queue[i - 1];
                priority_queue[i - 1] = a;
            }
            else{
                break;    
            }    
        }
    }
    else{
        last_p_queue++;
        priority_queue[last_p_queue] = n;    
    }
}
int pop_priority_queue(){
    if(first_p_queue <= last_p_queue){
        first_p_queue++;
        return priority_queue[first_p_queue - 1];
    }
    return -1;
}

//-----------------------------------
int main(){
    freopen("exam.INP","r",stdin);
    freopen("exam.OUT","w",stdout);
    int inout, value;
    int n;
    
    
    while(cin >> n){
    //QUEUE
    first_queue = 1;
    last_queue = 0;
    queue_test = 1;
    
    //STACK
    first_stack = 0;
    stack_test = 1;
    
    //PRIORITY QUEUE
    first_p_queue = 1;
    last_p_queue = 0;
    priority_queue_test = 1;
    
        for(int i = 1; i <= n; i++){
            cin >> inout >> value;
            if(inout == 1){
                bushback_queue(value);
                bush_stack(value);
                bush_priority_queue(value);    
            }
            else{
                if(value != pop_queue()){
                    queue_test = 0;            
                }
                if(value != pop_stack()){
                    stack_test = 0;    
                }
                if(value != pop_priority_queue()){
                    priority_queue_test = 0;    
                }
            }
        }
        if((queue_test + stack_test + priority_queue_test) >= 2){
            cout << "not sure" << endl;
        }
        else if((queue_test + stack_test + priority_queue_test) == 0){
            cout << "impossible" << endl;    
        }
        else{
            if(queue_test == 1){
                cout << "queue" << endl;    
            }
            if(stack_test == 1){
                cout << "stack" << endl;    
            }
            if(priority_queue_test == 1){
                cout << "priority queue" << endl;    
            }    
        }
    }
}   
