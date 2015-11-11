/*
 * CyberDNS.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: nadav
 */

#include "CyberDNS.h"
#include <boost/range/adaptor/map.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <iterator>

CyberDNS::CyberDNS() {
	// TODO Auto-generated constructor stub
}

CyberDNS::~CyberDNS() {

}

void CyberDNS::AddPC(CyberPC & cyber_pc_){
	cyber_DNS_.insert(std::pair<const std::string, CyberPC &>(cyber_pc_.getName(),cyber_pc_));
	keys.push_back(cyber_pc_.getName());
	std::cout<<cyber_pc_.getName()<<" connected to server"<<std::endl;
}
CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const{
	return cyber_DNS_.at(cyber_pc_name);
}
std::vector<std::string> CyberDNS::GetCyberPCList(){
	return keys;
}
CyberPC & CyberDNS::GetCyberPC(int pcNum) const{
	return GetCyberPC(keys[pcNum%keys.size()]);
}
