#include <iostream>
#include <vector>
#include "clases.hpp"
using namespace std;

///Funciones de la clase Person
    void Person::set_name(string n)
    {
       this->name=n;
    }
    string Person::get_name()
    {
        return this->name;
    }
    void Person::set_age(int num)
    {
       this->age=num;
    }
    int Person::get_age()
    {
        return this->age;
    }
    void Person::set_birthDate(string date)
    {
        this->birthDate=date;
    }
    string Person::get_birthDate()
    {
        return this->birthDate;
    }
    void Person::set_mstatus(status s)
    {
        this->m_status=s;
    }
    enum status Person::get_status()
    {
        return this->m_status;
    };
    void Person::print_information()
    {
        cout<<"Name: "<<this->get_name()<<endl;
        cout<<"Birth Date: "<<this->get_birthDate()<<endl;
        cout<<"Age: "<<this->get_age()<<endl;
        cout<<"Status: ";
        switch(this->get_status())
        {
        case single:
            cout<<"Single";break;
        case married:
            cout<<"Married";break;
        case divorced:
            cout<<"Divorced";break;
        case widower:
            cout<<"Widower";break;
        }
        cout<<endl;
    }

///Funciones de la clase Employee
    void Employee::set_workPlace(string place)
    {
        this->workPlace=place;
    }
    string Employee::get_workPlace()
    {
        return this->workPlace;
    }
    void Employee::set_startDate(string date)
    {
        this->startDate=date;
    }
    string Employee::get_startDate()
    {
        return this->startDate;
    }
    void Employee::set_LaborYears(double y)
    {
        this->years=y;
    }
    double Employee::get_LaborYears()
    {
        return this->years;
    }
    void Employee::set_monthSalary(double s)
    {
        this->salary=s;
    }
    double Employee::get_monthSalary()
    {
        return this->salary;
    }
    void Employee::print_information()
    {
        Person::print_information();
        cout<<"Ocupation: Employee"<<endl;
        cout<<"Work Place: "<<this->get_workPlace()<<endl;
        cout<<"Start Date: "<<this->get_startDate()<<endl;
        cout<<"Labor Years: "<<this->get_LaborYears()<<endl;
        cout<<"Salary: $"<<this->get_monthSalary()<<endl;
    }

///Funciones de la clase BaseballPlayer
    void BaseballPlayer::set_team(string t)
    {
        this->team=t;
    }
    string BaseballPlayer::get_team ()
    {
        return this->team;
    }
    void BaseballPlayer::set_position(position p)
    {
        this->p_position=p;
    }
    enum position BaseballPlayer::get_position()
    {
        return this->p_position;
    };
    void BaseballPlayer::set_games(int g)
    {
        this->games=g;
    }
    int BaseballPlayer::get_games()
    {
        return this->games;
    }
    void BaseballPlayer::print_information()
    {
        Person::print_information();
        cout<<"Ocupation: Baseball player"<<endl;
        cout<<"Team: "<<this->get_team()<<endl;
        cout<<"Position: ";
        switch(this->get_position())
        {
        case Pitcher:
            cout<<"Pitcher"; break;
        case Baseman:
            cout<<"Baseman"; break;
        case Catcher:
            cout<<"Catcher"; break;
        case Shortstop:
            cout<<"Shortstop"; break;
        case Fielder:
            cout<<"Fielder"; break;
        case Bat:
            cout<<"Bat"; break;
        }
        cout<<endl;
        cout<<"Games played: "<<this->get_games()<<endl;
    }

///Funciones de la clase Supervisor
    void Supervisor::set_group(string g)
    {
        this->group=g;
    }
    string Supervisor::get_group()
    {
        return this->group;
    }
    void Supervisor::set_employees(int e)
    {
        this->employees=e;
    }
    int Supervisor::get_employees()
    {
        return this->employees;
    }
    void Supervisor::set_expetience(int x)
    {
        this->experience=x;
    }
    int Supervisor::get_experience()
    {
        return this->experience;
    }
    void Supervisor::print_information()
    {
        Employee::print_information();
        cout<<"Position: Supervisor"<<endl;
        cout<<"Group: "<<this->get_group()<<endl;
        cout<<"Employees: "<<this->get_employees()<<endl;
        cout<<"Experience: "<<this->get_experience()<<" years"<<endl;
    }

///Funciones de la clase Student
    void Student::set_level(grade g)
    {
        this->level=g;
    }
    enum grade Student::get_level()
    {
        return this->level;
    }
    void Student::set_campus(string c)
    {
        this->campus=c;
    }
    string Student::get_campus()
    {
        return this->campus;
    }
    void Student::set_career(string car)
    {
        this->career=car;
    }
    string Student::get_career()
    {
        return this->career;
    }
    void Student::print_information()
    {
        Person::print_information();
        cout<<"Ocupation: Student"<<endl;
        cout<<"Grade: ";
        switch(this->get_level())
        {
        case elementary:
            cout<<"Elementary";break;
        case high_school:
            cout<<"High School";break;
        case university:
            cout<<"University";break;
        case master:
            cout<<"Master Degree";break;
        case doctoral:
            cout<<"Doctoral";break;
        }
        cout<<endl;
        cout<<"School: "<<this->get_campus()<<endl;
        cout<<"Career: "<<this->get_career()<<endl;
    }

///Funciones de la clase Teacher
    void Teacher::set_level(grade g)
    {
        this->level=g;
    }
    enum grade Teacher::get_level()
    {
        return this->level;
    }
    void Teacher::set_campus(string c)
    {
        this->campus=c;
    }
    string Teacher::get_campus()
    {
        return this->campus;
    }
    void Teacher::set_Asignature(string a)
    {
        this->Asignatures.push_back(a);
    }
    vector <string> Teacher::get_Asignatures()
    {
        return this->Asignatures;
    }
    void Teacher::print_information()
    {
        Person::print_information();
        cout<<"Ocupation: Teacher"<<endl;
        cout<<"Grade: ";
        switch(this->get_level())
        {
        case elementary:
            cout<<"Elementary";break;
        case high_school:
            cout<<"High School";break;
        case university:
            cout<<"University";break;
        case master:
            cout<<"Master Degree";break;
        case doctoral:
            cout<<"Doctoral";break;
        }
        cout<<endl;
        cout<<"School: "<<this->get_campus()<<endl;
        cout<<"Asignatures: ";
        vector <string> aux=this->get_Asignatures();
        int size=aux.size();
        for(int i=0;i<size;i++)
            cout<<aux[i]<<" ";
        cout<<endl;

    }
