#pragma once
#include <string>
#include<list>
class Human
{
public:
	Human();
	Human(const Human&);
	Human(std::string, std::string = "00000000000", std::string = "facebook.com", float = 0.00f);
	~Human();
public:
	void SetName(const std::string&);
	void SetPhone(const std::string&);
	void SetOnlineContact(const std::string&);
	void SetFiscalInfoDetail (float);

private:
	void CalculateFiscalInfoSum();
private:
	std::string name;
	std::list <std::string>* phoneNumbers;
	std::list <std::string>* onlineContacts;
	float fiscalInfo;
	bool useFiscalInfoDetails;
	std::list <float>* fiscalInfoDetails;
};

