#include "Humans.h"

Human::Human() 
{
	SetName("");
	phoneNumbers = new std::list<std::string>();
	SetPhone("00000000000");
	onlineContacts = new std::list<std::string>();
	SetOnlineContact("facebook.com");
	useFiscalInfoDetails = true;
	fiscalInfoDetails= new std::list<FinancialRecord>();
	SetFiscalInfoDetail(FinancialRecord(0.00f,true));
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
	
	total = human.total;
	unfulfilledtotal= human.unfulfilledtotal;
	useFiscalInfoDetails = human.useFiscalInfoDetails;
	if (useFiscalInfoDetails)
	{
		fiscalInfoDetails = new std::list<FinancialRecord>();
		for (FinancialRecord detail : *(human.fiscalInfoDetails))
		{
			SetFiscalInfoDetail(detail);
		}
	}
}

Human::Human(const std::string& name, const std::string& number,const std::string&  contact, bool useDetail,const FinancialRecord& record)
{
	SetName(name);
	phoneNumbers = new std::list<std::string>();
	SetPhone(number);
	onlineContacts = new std::list<std::string>();
	SetOnlineContact(contact);
	useFiscalInfoDetails = useDetail;
	fiscalInfoDetails = new std::list<FinancialRecord>();
	SetFiscalInfoDetail(record);
}

void Human::SetName(const std::string& Name) 
{
	name = Name;
}

void Human::SetPhone(const std::string& Phone)
{
	if (Phone.size() == 11) 
	{
		phoneNumbers->push_back(Phone);
	}

}

void Human::SetOnlineContact(const std::string& contact)
{
	onlineContacts->push_back(contact);
}

void Human::SetFiscalInfoDetail(const FinancialRecord& record)
{
	fiscalInfoDetails->push_back(record);
	CalculateFiscalInfoSum();
}

void Human::CalculateFiscalInfoSum() 
{
	for (FinancialRecord record : *fiscalInfoDetails) 
	{
		if (!record.fulfilled) 
		{
			unfulfilledtotal += record.fiscalinfo;
		}
		total += record.fiscalinfo;
	}
}

void Human::DelPhone(const std::string& Phone) 
{
	phoneNumbers->remove(Phone);
	delete &Phone;
}

void Human::DelOnlineContact(const std::string& contact) 
{
	onlineContacts->remove(contact);
	delete& contact;
}

void Human::DelFiscalInfoDetail(const FinancialRecord& record) 
{
	fiscalInfoDetails->remove(record);
	delete& record;
}

const std::string& Human::GetName()
{
	return name;
}

const std::list<std::string>* Human::GetPhone()
{
	return phoneNumbers;
}

const std::list<std::string>* Human::GetOnlineContacts()
{
	return onlineContacts;
}

const std::list<FinancialRecord>* Human::getFinancialDetails()
{
	return fiscalInfoDetails;
}



FinancialRecord::FinancialRecord() 
{
	fiscalinfo = 0.00f;
	fulfilled = true;
}

FinancialRecord::FinancialRecord(float value, bool Fulfilled) 
{
	fiscalinfo = value;
	fulfilled = Fulfilled;
}



PetOwner::PetOwner(const std::string& name, const std::string& number, const std::string&  contact,const bool& useDetail,const FinancialRecord& record, Pet& pet):Human(name,number,contact,useDetail,record)
{
	AddPet(pet);
	CoOwners = new std::list<PetOwner&>();
}

PetOwner::PetOwner() : Human() 
{
	Pets = new std::list<Pet&>();
	Pet pet=Pet();
	AddPet(pet);
	CoOwners = new std::list<PetOwner&>();
}

PetOwner::PetOwner(const PetOwner& Other):Human(Other)
{
	for(Pet p:*(Other.Pets))
		AddPet(p);
	for(PetOwner co:*(Other.CoOwners))
		AddCoOwner(co);
}

void PetOwner::AddCoOwner(PetOwner& other) 
{
	other.CoOwners->push_back(*this);
	this->CoOwners->push_back(other);
	other.Pets = this->Pets;
}

void PetOwner::DelCoOwner(PetOwner& other) 
{
	other.CoOwners->remove(*this);
	this->CoOwners->remove(other);
	other.Pets = new std::list<Pet&>();
}

const std::list<PetOwner&>* PetOwner::getCoOwners() 
{
	return CoOwners;
}

void PetOwner::AddPet(Pet& newPet)
{
	Pets->push_back(newPet);
}

void PetOwner::DelPet(Pet& removedPet)
{
	Pets->remove(removedPet);
}

const std::list<Pet&>* PetOwner::getPets()
{
	return Pets;
}