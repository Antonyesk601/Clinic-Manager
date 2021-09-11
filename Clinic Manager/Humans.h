#pragma once
#include <string>
#include<list>
#include "Pet.h"
class FinancialRecord {
public:
	FinancialRecord();
	FinancialRecord(float, bool);
	float fiscalinfo;
	bool fulfilled;
};

class Human
{
public:
	Human();
	Human(const Human&);
	Human(std::string, std::string = "00000000000", std::string = "facebook.com",bool=true, FinancialRecord = FinancialRecord());
public:
	void SetName(const std::string&);
	void SetPhone(const std::string&);
	void DelPhone(const std::string&);
	void SetOnlineContact(const std::string&);
	void DelOnlineContact(const std::string&);
	void SetFiscalInfoDetail (const FinancialRecord&);
	void DelFiscalInfoDetail (const FinancialRecord&);

private:
	void CalculateFiscalInfoSum();
private:
	std::string name;
	std::list <std::string>* phoneNumbers;
	std::list <std::string>* onlineContacts;
	float unfulfilledtotal;
	float  total;
	bool useFiscalInfoDetails;
	std::list <FinancialRecord>* fiscalInfoDetails;
};

class PetOwner : public Human 
{
public:
	PetOwner();
	PetOwner(const PetOwner&);
	PetOwner(const std::string&,const std::string&,const std::string&,const bool&, const FinancialRecord&,const std::list<Pet>&);
public:
	void MakeCoOwner(const PetOwner&);
private:

private:
	
};
