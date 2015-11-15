
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
	CyberDNS *DNS=new CyberDNS();
	vector<CyberExpert> experts;
	//vector<CyberPC*> cyberPC_;

	int day=0;
	int terminateDay;

	boost::property_tree::ptree pt;
	boost::property_tree::xml_parser::read_xml("computers.xml",pt);
	while(!pt.empty())
	{
		cout<<"Adding to server: "<<pt.get<string>("computer.name")<<endl;
		CyberPC* toAdd =new CyberPC(pt.get<string>("computer.os"),pt.get<string>("computer.name"));
				//cyberPC_.push_back(toAdd);
				DNS->AddPC(*toAdd);
		pt.pop_front();
	}

	cout<<"\n\n\n"<<endl;

	boost::property_tree::xml_parser::read_xml("network.xml",pt);
	while(!pt.empty())
	{
		cout<<"Connecting "<<pt.get<string>("wire.pointA")<<" to "<<pt.get<string>("wire.pointB")<<endl;
		DNS->GetCyberPC(pt.get<string>("wire.pointA")).AddConnection(pt.get<string>("wire.pointB"));
		DNS->GetCyberPC(pt.get<string>("wire.pointB")).AddConnection(pt.get<string>("wire.pointA"));
		pt.pop_front();
	}

	cout<<"\n\n\n"<<endl;

	boost::property_tree::xml_parser::read_xml("events.xml",pt);
	terminateDay=pt.get<int>("termination.time");
	while(day<=terminateDay)
	{
		cout<<"Day : " << day++ <<endl;
		if(pt.front().first.compare("clock-in")==0)
		{
			experts.push_back(CyberExpert(pt.get<string>("clock-in.name"),pt.get<int>("clock-in.workTime"),pt.get<int>("clock-in.restTime"),pt.get<int>("clock-in.efficiency")));
			pt.pop_front();
		}
		if(pt.front().first.compare("hack")==0)
		{
			cout<<"\tHack occured on "<<pt.get<string>("hack.computer")<<endl;
			DNS->GetCyberPC(pt.get<string>("hack.computer")).Infect(pt.get<string>("hack.wormOs"),pt.get<string>("hack.wormName"),pt.get<int>("hack.wormDormancy"));
			pt.pop_front();
		}

		for (unsigned int i = 0; i < experts.size(); ++i) {
			experts[i].Run(*DNS);
		}

		for (unsigned int i = 0; i < DNS->GetCyberPCList().size(); i++)
			DNS->GetCyberPC(DNS->GetCyberPCList()[i]).Run(*DNS);

	}

	delete DNS;
	//BOOST_FOREACH(CyberPC* pc ,cyberPC_)
	//	  delete pc;
}




