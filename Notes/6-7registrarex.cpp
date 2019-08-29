
class Course; //incomplete type declaration, simply telling compiler that course is the name of a class 
//avoid problem of compiler not knowing what course is


class Student 
{
	... 
	Course* m_studyList[10];
	...
};

class Course
{
	...
	Student* m_roster[1000];
	...
};


class Fan 
{
	public: 
		void turnOn(); 
		... 

}; 

class Rock 
{
	public: 
		double weight() const; 
	...
};

class Robot
{
	...
	Fan m_cooler; 
	Rock* m_rock; 
};

void Robot::blah(...)
{
	if (m_rock != nullptr && m_rock->weight() >= 20)
		m_cooler.turnOn(); 
}



