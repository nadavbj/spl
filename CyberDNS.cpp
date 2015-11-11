/*
 * CyberDNS.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: nadav
 */

#include "CyberDNS.h"

CyberDNS::CyberDNS() {
	// TODO Auto-generated constructor stub

}

CyberDNS::~CyberDNS() {

}

void CyberDNS::AddPC(CyberPC & cyber_pc_){
	cyber_DNS_.insert(std::pair<std::string,CyberPC*>(cyber_pc_.getName(),&cyber_pc_));
}
CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const{
return cyber_DNS_[cyber_pc_name];
}
std::vector<std::string> CyberDNS::GetCyberPCList(){

}
