
#include "CyberPC.h"

CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name) {
	cyber_pc_name_=cyber_pc_name;
	cyber_pc_os_=cyber_pc_os;
	cyber_pc_time_to_infect_=0;
}

CyberPC::~CyberPC() {
	//std::cout<<cyber_pc_name_<< " killed " <<std::endl;
	if(cyber_worm_!= NULL)
	{delete cyber_worm_;}
}

const std::string CyberPC::getName(){
	return cyber_pc_name_;
}
void CyberPC::AddConnection(std::string  second_pc){
	cyber_pc_connections_.push_back(second_pc);
	std::cout<<"\t"<<cyber_pc_name_<<" now connected to "<<second_pc<<std::endl;
}
void CyberPC::Infect(CyberWorm & worm){
	if(cyber_pc_os_.compare(worm.getWormOs())==0){
		if(cyber_worm_!= NULL){
			delete cyber_worm_;
		}

		cyber_worm_= new CyberWorm(worm);
		cyber_pc_time_to_infect_=cyber_worm_->getWormDormancyTime();
		std::cout<<"\t\t"<<cyber_pc_name_<<" infected by "<<worm.getName()<<std::endl;
	}
	else
	{
		std::cout<<"\t\tWorm "<<worm.getName()<<" is incompatible with "<<cyber_pc_name_<<std::endl;
	}
}
void CyberPC::Infect(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time){
	if(cyber_pc_os_.compare(cyber_worm_os)==0){
		if(cyber_worm_!= NULL)
			delete cyber_worm_;
		cyber_worm_=new CyberWorm(cyber_worm_os,cyber_worm_name,cyber_worm_dormancy_time);
		cyber_pc_time_to_infect_=cyber_worm_->getWormDormancyTime();
		std::cout<<"\t\t"<<cyber_pc_name_<<" infected by "<<cyber_worm_name<<std::endl;
	}
}

void CyberPC::Run(const CyberDNS & server)
{
	if(cyber_worm_!= NULL){
		if(cyber_pc_time_to_infect_==0){

			std::cout<<"\t"<<cyber_pc_name_<<" infecting..."<<std::endl;
			for (unsigned int i = 0; i < cyber_pc_connections_.size(); ++i) {
				server.GetCyberPC(cyber_pc_connections_[i]).Infect(*cyber_worm_);
			}
		}
		else
		{
			std::cout<<"\t"<<cyber_pc_name_<<": Worm "<<cyber_worm_->getName()<<" is dormant"<<std::endl;
			cyber_pc_time_to_infect_--;
		}
	}
}
void CyberPC::Disinfect(){
	if(cyber_worm_==NULL)
		return;
	std::cout<<"\tWorm "<<cyber_worm_->getName()<<" successfully removed from "<<cyber_pc_name_<<std::endl;
	delete cyber_worm_;
	cyber_worm_=NULL;
}
