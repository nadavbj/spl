/*
 * CyberExpert.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: nadav
 */

#include "CyberExpert.h"

CyberExpert::CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_) {
	this->cyber_expert_name_=cyber_expert_name_;
	this->cyber_expert_efficiency_=cyber_expert_efficiency_;
	this->cyber_expert_work_time_=cyber_expert_work_time_;
	this->cyber_expert_rest_time_=cyber_expert_rest_time_;
	daysSinceClockedIn=0;
	numOfCheckedPcs=0;
	std::cout<<"Clock-In: "<<cyber_expert_name_<<" began working";
}

CyberExpert::~CyberExpert() {
	// TODO Auto-generated destructor stub
}

void CyberExpert::Clean(CyberPC & cyber_pc){
	std::cout<<cyber_expert_name_<<" examining "<<cyber_pc.getName();
	cyber_pc.Disinfect();
}

void CyberExpert::Run(const CyberDNS & server){
	daysSinceClockedIn++;
	if(daysSinceClockedIn%(cyber_expert_work_time_+cyber_expert_rest_time_)<=cyber_expert_work_time_){

		if((daysSinceClockedIn)%(cyber_expert_work_time_+cyber_expert_rest_time_)==0)
					std::cout<<cyber_expert_name_<<" is back to work"<<std::endl;

		for (int i = 0;  i < cyber_expert_efficiency_; ++ i) {
			Clean(server.GetCyberPC(numOfCheckedPcs++));
		}

		if((daysSinceClockedIn+1)%(cyber_expert_work_time_+cyber_expert_rest_time_)>cyber_expert_work_time_)
			std::cout<<cyber_expert_name_<<" is taking a break"<<std::endl;
	}

}
