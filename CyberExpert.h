#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "CyberPC.h"


class CyberExpert
{
private:
	std::string 	cyber_expert_name_;
    int cyber_expert_work_time_;
    int cyber_expert_rest_time_;
    int cyber_expert_efficiency_;
    CyberExpert(); // Prevent the use of an empty constructor
	// Add your own variables here

public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);
	// Add your own functions here
 	~CyberExpert();
};


#endif
