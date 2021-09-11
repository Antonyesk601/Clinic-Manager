#include "Humans.h"
Human::Human() 
{
	SetName("");
	phoneNumbers = new std::list<std::string>();
	SetPhone("00000000000");
	onlineContacts = new std::list<std::string>();
	SetOnlineContact("facebook.com");
	fiscalInfo = 0;
	fiscalInfoDetails= new std::list<float>();
	SetFiscalInfoDetail(0.00f);
}
Human::Human(const Human& human)
{
	SetName(human.name);
	phoneNumbers = new std::list<std::string>();
	for (std::string number : *(human.phoneNumbers)) 
	{
		SetPhone(number);
	}
	onlineContacts = new std::list<std::string>();
	for (std::string contact : *(human.onlineContacts))
	{
		SetOnlineContact(contact);
	}
	
	fiscalInfo = human.fiscalInfo;
	useFiscalInfoDetails = human.useFiscalInfoDetails;
	if (useFiscalInfoDetails) 
	{
		fiscalInfoDetails = new std::list<float>();
		for (std::string number : *(human.phoneNumbers))
		{
			SetPhone(number);
		}
	}
}