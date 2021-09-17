#pragma once
#include <string>
#include<list>
#include "Pet.h"

template <class T>
T getListItem(std::list<T>, int);
class FinancialRecord {
public:
	FinancialRecord();
	FinancialRecord(float, bool);
	float fiscalinfo;
	bool fulfilled;
	bool operator==(const FinancialRecord& a) const;
};

class Human
{
public:
	Human();
	Human(const Human&);
	Human(const std::string&,const std::string& = "00000000000",const std::string& = "facebook.com", bool=true,const FinancialRecord& = FinancialRecord());
public:
	void SetName(const std::string&);
	void SetPhone(const std::string&);
	void DelPhone(const std::string&);
	void SetOnlineContact(const std::string&);
	void DelOnlineContact(const std::string&);
	void SetFiscalInfoDetail (const FinancialRecord&);
	void DelFiscalInfoDetail (const FinancialRecord&);
	const std::string& GetName();
	const std::list<std::string>*  GetPhone();
	const std::list<std::string>* GetOnlineContacts();
	const std::list<FinancialRecord>* getFinancialDetails();
	bool operator== (const Human& H)const;
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
	PetOwner(const std::string&,const std::string&,const std::string&,const bool&, const FinancialRecord&, Pet&);
public:
	void AddCoOwner(PetOwner&);
	void DelCoOwner(PetOwner&);
	const std::list<PetOwner*>* getCoOwners();
	void AddPet(Pet&);
	void DelPet(Pet&);
	const std::list<Pet*>* getPets();
	bool operator== (const PetOwner& p1) const;
private:
	std::list<Pet*>* Pets;
	std::list<PetOwner*>* CoOwners;
};
