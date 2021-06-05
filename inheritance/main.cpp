#include <iostream>
#include <vector>
#include "clases.hpp"

using namespace std;

int main()
{
    Person Person1;
    Person1.set_age(27);
    Person1.set_name("Gerardo Fuentes");
    Person1.set_mstatus(single);
    Person1.set_birthDate("March 6th 1988");
    Person1.print_information();
    cout<<endl;

    Employee Employee1;
    Employee1.set_name("Juan Garcia");
    Employee1.set_age(36);
    Employee1.set_mstatus(married);
    Employee1.set_birthDate("January 15th 1979");
    Employee1.set_workPlace("Hewlett Packard");
    Employee1.set_startDate("June 16th 2000");
    Employee1.set_LaborYears(14.5);
    Employee1.set_monthSalary(29550.0);
    Employee1.print_information();
    cout<<endl;

    BaseballPlayer BaseballPlayer1;
    BaseballPlayer1.set_name("Carlos Perez");
    BaseballPlayer1.set_age(25);
    BaseballPlayer1.set_birthDate("August 21st 1990");
    BaseballPlayer1.set_mstatus(single);
    BaseballPlayer1.set_team("New York Mets");
    BaseballPlayer1.set_position(Fielder);
    BaseballPlayer1.set_games(48);
    BaseballPlayer1.print_information();
    cout<<endl;

    Supervisor Supervisor1;
    Supervisor1.set_name("Jose Gonzalez");
    Supervisor1.set_age(37);
    Supervisor1.set_mstatus(divorced);
    Supervisor1.set_birthDate("April 16th 1978");
    Supervisor1.set_workPlace("Intel");
    Supervisor1.set_startDate("May 6th 2003");
    Supervisor1.set_LaborYears(12.5);
    Supervisor1.set_monthSalary(35260);
    Supervisor1.set_group("Engineering");
    Supervisor1.set_employees(12);
    Supervisor1.set_expetience(5);
    Supervisor1.print_information();
    cout<<endl;

    Student Student1;
    Student1.set_name("Maria Martinez");
    Student1.set_birthDate("September 19th 1993");
    Student1.set_age(22);
    Student1.set_mstatus(single);
    Student1.set_level(university);
    Student1.set_campus("Universidad de Guanajuato");
    Student1.set_career("Enfermeria");
    Student1.print_information();
    cout<<endl;

    Teacher Teacher1;
    Teacher1.set_name("Ana Mendez");
    Teacher1.set_birthDate("February 16th 1974");
    Teacher1.set_age(41);
    Teacher1.set_mstatus(divorced);
    Teacher1.set_level(master);
    Teacher1.set_campus("Universidad de Leon");
    Teacher1.set_Asignature("Antropologia");
    Teacher1.set_Asignature("Historia");
    Teacher1.set_Asignature("Filosofia");
    Teacher1.print_information();
    cout<<endl;

    return 0;
}
