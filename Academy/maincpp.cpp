#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name, age

class Human
{
	static const int TYPE_WIDTH = 12;
	static const int NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static int count; //���������� ����������� ����������
	std::string last_name;
	std::string first_name;
	int age;
public:
	static int get_count()
	{
		return count;
	}
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
		count++;
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		count--;
		cout << "HDestructor:\t" << this << endl;

	}

	// Methods
	virtual std::ostream& info(std::ostream& os)const // base class
	{
		os.width(TYPE_WIDTH); // ����� width(n) ������ ������ ����,� ������� ����� �������� ��������
		os << std::left;
		os << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";

		//strchr(const char* str, char symbol); � ��������� ������ ������� ��������� ������
		// (symbol), � ���������� ��������� �� ��������� ������, ��� nullptr, 
		// ���� ��������� ������ ����������� � ��������� ������.

		//return os << last_name << " " << first_name << " " << age;

		os.width(NAME_WIDTH);
		os << last_name;
		os.width(NAME_WIDTH);
		os << first_name;
		os.width(AGE_WIDTH);
		os << age;
		return os;
	}

};
int Human::count = 0; //������������� ����������� ���������� (��������� � ����������� ������ - Class difinition)

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
	static const int SPECIALITY_WIDTH = 32;
	static const int GROUP_WIDTH = 8;
	static const int RAT_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating; //������������
	double attendance;//������������
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
	Student(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
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
	std::ostream& info(std::ostream& os)const override
	{
		//return Human::info(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(GROUP_WIDTH);
		os << group;
		os.width(RAT_WIDTH);
		os << rating;
		os.width(RAT_WIDTH);
		os << attendance;
		return os;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience
class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 32;
	static const int EXPERIENCE_WIDTH = 5;
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
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
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
	std::ostream& info(std::ostream& os)const override
	{
		//return Human::info(os) << " " << speciality << " " << experience;
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(EXPERIENCE_WIDTH);
		os << experience;
		return os;
	}
	
};

#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject

class Graduate :public Student
{
	std::string subject;
	
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	

	// Constructors
	Graduate 
	(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	 // Methods
	std::ostream& info(std::ostream& os)const override
	{
		
		return Student::info(os) << " " << get_subject();
    }
};
	
void Print(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		group[i]->info(cout);
		cout << delimiter << endl;
	}
	cout << "���������� ��������: " << group[0]->get_count() << endl;
	cout << "���������� ��������: " << Human::get_count() << endl;
}


void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);

	for (int i = 0; i < n; i++)
	{
		fout << *group[i]<< endl;
	}
	fout.close();
	std::string cmd = "start notepad ";
	cmd += filename;
	system(cmd.c_str());// ����� c_str ���������� ������ � ���� ������� �������� (char*)
}


Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//1. ������������ ���������� �������� � �����
		n = 0;
		std::string buffer;
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.size() < 20)continue;
			n++;
		}
		cout << "���������� ��������: " << n << endl;
		//2. �������� ������ ��� ��������
		group = new Human* [n];
		//3. ������������ � ������ ������ ��� ���� ����� ��������� �� ���� ���� �������.
		cout << "Position " << fin.tellg() << endl; // ����� tellg() ���������� ������� get  ������� ������� �� ������. -1 ����� �����
		fin.clear();
		fin.seekg(0); //����� seekg(n) ��������� get ������ �� ������ � ��������� ������� "n";
		cout << "Position " << fin.tellg() << endl; // ����� tellg() ���������� ������� get  ������� ������� �� ������. -1 ����� �����


	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	// 4. ��������� ����
	fin.close();
	return group;
}


void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
		cout << delimiter << endl;
	}
}

//#define INHERITANCE
//#define POLYMORPHISM
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pincman", "Jessie", 22, "Chemistry", "WW_220", 95, 98);
	student.info();

	Graduate graduate("Shreder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch Heisenberg");
	graduate.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM

	Human* group[] =
	{
		new Student("Pincman", "Jessie", 22, "Chemistry", "WW_220", 95, 98),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Shreder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch Heisenberg"),
		new Student("Vercetty","Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimiter << endl;
	}

#endif POLYMORPHISM

		
	int n = 0;
	Human** group = Load("group.txt", n);
	Print(group, n);
	Clear(group, n);

}