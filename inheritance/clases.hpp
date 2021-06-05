#ifndef CLASES_HPP_INCLUDED
#define CLASES_HPP_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

enum status {single,married,divorced,widower};
enum position {Pitcher,Catcher,Baseman,Fielder,Shortstop,Bat};
enum grade {elementary,high_school,university,master,doctoral};

class Person
{
private:
    string name;
    int age;
    string birthDate;
    enum status m_status;
public:
    void set_name(string n);
    string get_name();
    void set_age(int num);
    int get_age();
    void set_birthDate(string date);
    string get_birthDate();
    void set_mstatus(status s);
    enum status get_status();
    void print_information();
};

class Employee: public Person
{
private:
    string workPlace;
    string startDate;
    double years;
    double salary;
public:
    void set_workPlace(string place);
    string get_workPlace();
    void set_startDate(string date);
    string get_startDate();
    void set_LaborYears(double y);
    double get_LaborYears();
    void set_monthSalary(double s);
    double get_monthSalary();
    void print_information();
};

class BaseballPlayer: public Person
{
private:
    string team;
    enum position p_position;
    int games;
public:
    void set_team(string t);
    string get_team ();
    void set_position(position p);
    enum position get_position();
    void set_games(int g);
    int get_games();
    void print_information();
};

class Supervisor: public Employee
{
private:
    string group;
    int employees;
    int experience;
public:
    void set_group(string g);
    string get_group();
    void set_employees(int e);
    int get_employees();
    void set_expetience(int x);
    int get_experience();
    void print_information();
};

class Student: public Person
{
private:
    enum grade level;
    string campus;
    string career;
public:
    void set_level(grade g);
    enum grade get_level();
    void set_campus(string c);
    string get_campus();
    void set_career(string car);
    string get_career();
    void print_information();
};

class Teacher: public Person
{
private:
    enum grade level;
    string campus;
    vector <string> Asignatures;
public:
    void set_level(grade g);
    enum grade get_level();
    void set_campus(string c);
    string get_campus();
    void set_Asignature(string a);
    vector <string> get_Asignatures();
    void print_information();
};

#endif // CLASES_HPP_INCLUDED
