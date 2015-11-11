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
	this->cyber_expert_rest_time_=cyber_expert_rest_time_;

}

CyberExpert::~CyberExpert() {
	// TODO Auto-generated destructor stub
}

void CyberExpert::Clean(CyberPC & cyber_pc){
	cyber_pc.Disinfect();
}
