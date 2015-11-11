/*
 * Simulation.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: nadav
 */
#include "CyberDNS.h"
#include "CyberExpert.h"
#include "CyberPC.h"
#include "CyberWorm.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

using namespace std;

int main(int argc, char **argv)
{
	CyberDNS DNS;
	vector<CyberExpert> experts;
	vector<string>v;

	//using boost::property_tree::xml_parser;
	boost::property_tree::ptree pt;
	boost::property_tree::xml_parser::read_xml("computers.xml",pt);
	while(!pt.empty())
	{
		DNS.AddPC(*new CyberPC(pt.get<string>("computer.os"),pt.get<string>("computer.name")));
		pt.pop_front();
	}
v=DNS.GetCyberPCList();
cout<<v[0]<<endl;


}




