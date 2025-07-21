#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	} 
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	// Constructors
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;

	}

	// Methods
	void info()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}

};
#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	// Constructors
	Student
		(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;

	}
	~Student()
	{
		cout << "Destructor:\t" << endl;
	}

	// Methods
	void info()const
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};
#define GRADUATE_TAKE_PARAMETERS const std::string& discipline, const std::string& specialization, int course
#define GRADUATE_GIVE_PARAMETERS discipline, specialization, course

class Graduate :public Human
{
	std::string dis�ipline;
	std::string specialization;
	int course;
public:
	const std::string& get_discipline()const
	{
		return dis�ipline;
	}
	const std::string& get_specialization()const
	{
		return specialization;
	}
	int get_course()const
	{
		return course;
	}
	void set_discipline(const std::string& discipline)
	{
		this->dis�ipline = discipline;
	}
	void set_specialization(const std::string& specialization)
	{
		this->specialization = specialization;
	}
	void set_course(int course)
	{
		this->course = course;
	}

	// Constructors
	Graduate 
	(HUMAN_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_discipline(discipline);
		set_specialization(specialization);
		set_course(course);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	 // Methods
	void info()const
	{
		Human::info();
		cout << dis�ipline << " " << specialization << " " << course << endl;
	}

};


#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience
class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	// Constructors
	Teacher
	(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;

	}
	~Teacher()
	{
		cout << " TDestructor:\t" << this << endl;
	}
	// Methods
	void info()const
	{
		Human::info();
		cout << speciality << " " << experience << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pincman", "Jessie", 22, "Chemistry", "WW_220", 95, 98);
	student.info();

	Graduate graduate("Abu", "Garcia", 23, "Biology", "Cardiology", 6);
	graduate.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();
}