/*
 * CyberPC.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: nadav
 */

#include "CyberPC.h"

CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name) {
	cyber_pc_name_=cyber_pc_name;
	cyber_pc_os_=cyber_pc_os;

}

CyberPC::~CyberPC() {
	if(cyber_worm_!= NULL)
		delete cyber_worm_;
}

const std::string CyberPC::getName(){
	return cyber_pc_name_;
}
void CyberPC::AddConnection(std::string  second_pc){
	cyber_pc_connections_.push_back(second_pc);
}
void CyberPC::Infect(CyberWorm & worm){
	if(cyber_worm_== NULL && cyber_pc_os_.compare(worm.getWormOs())==0){
		cyber_worm_= &worm;
		cyber_pc_time_to_infect_=cyber_worm_->getWormDormancyTime();
	}
}
void CyberPC::Run(const CyberDNS & server)
{
	if(cyber_worm_!= NULL){
		if(cyber_pc_time_to_infect_==0){
			for (int i = 0; i < cyber_pc_connections_.size(); ++i) {
				server.GetCyberPC(cyber_pc_connections_[i]).Infect(*cyber_worm_);
			}
		}
		else
			cyber_pc_time_to_infect_--;
	}
}
void CyberPC::Disinfect(){
	delete cyber_worm_;
	cyber_worm_=NULL;
}
