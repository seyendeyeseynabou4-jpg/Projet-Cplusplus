#ifndef EXO1_HPP
#define EXO1_HPP
#include <queue> 

    struct Service{
        std::string label;
        std::vector <orker> workers;
        std::queue <job> main_queue; 
        std::size_t current_frame;
    };
    struct Worker{
        std::string label;
        std::queue <Job> jobs;
    };


    struct Job{
        std::string label;
        std::size_t duration ;
        std::size_t remaining_time;
    };

    Service createService(std::string str);

    void addworker(Service &s , const Worker w);

    void addjob(Service &s, const Job j);

    void addjob(Worker &w, Job j);

    void dispatchNextJob(Service s ,size_t worker_id );



struct Job{
    std::string label;
    std::size_t duration ;
    std::size_t remaining_time;
};

Service createService(std::string str);

void addworker(Service &s , const Worker w);

void addjob(Service &s, const Job j);

void addjob(Worker &w, Job j);

void dispatchNextJob(Service s ,size_t worker_id );
#endif