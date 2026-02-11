#include <iostream> 
#include <sstream>
#include <random>
#include <vector> 
#include <string> 
#include <queue> 
#include "exo1.hpp"

Service createService(std::string str){
    Service s ;
    s.label=str;
    s.workers={};
    s.current_frame=0;

    return service ;
}

void addworker(Service &s , Worker w){
    s.workers.push_back(w);
}


void addjob(Service &s, const Job j){
    s.main_queue.push_back(j);
}


void addjob(Worker &w, Job j){
    w.jobs.push_back(j);
}

// void dispatchNextJob(Service s ,size_t worker_id ){
//     s.workers[worker_id].jobs.push_back(jobs);
    
// }

int main(){
 Service service = createService("Passage en caisse");
    // const std::size_t nb_workers = 5;
    // const std::size_t nb_jobs = 50;
    // TaskManager::Distribution distribution = TaskManager::Distribution::RANDOM;
    return 0; 
}