int main() 
{
	Company myCompany: 
	myCompany.hire("Ricky", 80000, 34);
	myCompany.hire("Lucy", 40000, 32); 

	Company yourCompany; 
	yourCompany.hire("Fred", 50000, 51);

	myCompany.setBonusRate(.02);
	myCompany.giveBonuses();
}

class Employee {
	public: 
		Employee(string nm, double sal, int ag);
	private:
		string m_name; 	
		double m_salary; 
		int m_age; 
		Company* m_company; //a pointer to the company that that employee works for 
};

Employee::Employee(string nm, double sal, int ag){
	m_name = nm; 
	m_salary = sal; 
	m_age = ag; 
	m_company = c; 
}
void Employee::receiveBonus() const 
{
	cout << "Pay to the order of " << m_name << "$" << (m_company->bonusRate() *m_salary) << endl;  
}

class Company{ 
	public: 
	Company(); 
	void hire(string nm, double sal, int ag);
	void setBonusRate(); 
	void giveBonuses(); 
	private: 
		Employee* m_employees[100];
		int m_nEmployees;
		double m_bonusRate; 
};

Company::Company(){ 
	m_nEmployees = 0; 
	m_bonusRate = 0; 
}

double Company::bonusRate()const {
	return m_bonusRate; 
}

void Company::setBonusRate(double pct){
	m_bonusRate = pct; 
}

void Company::hire(string nm, double sal, int ag){
	//error checking omitted
	//every member function has a pointer available to it, a pointer to the object it was called on 
	//in this case it's Company 
	m_employees[m_nEmployees] = new Employee(nm, sal, ag, this);
	m_nEmployees++;
}

void Company::giveBonuses(){
	for (int i = 0; k < m_nEmployees; k++){
		m_employees[k]->receiveBonus();//it's up to employee to deal with the receiving bonus
	}

}


int main(){
	Company myCompany; 
	myCompany.hire("Ricky", 80000, 34);
	myCompany.hire("Lucy", 40000, 32); 

	Company yourCompany; 
	yourCompany.hire("Fred", 50000, 51); 

	myCompany.setBonusRate(.02);
	myCompany.giveBonuses();

}