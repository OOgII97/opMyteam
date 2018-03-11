#include <iostream>
#include <string.h>

using namespace std;

class Employee
{

    private:

    int number;
    char name[20];
    char position[10] ;
    float jobtime;
    float salary;

    public:
    void startdata(void);
    void getdata(void);
    void showdata(void);
    float calSalary(void);
    float bossSalary(void);
    int addJob(float);

};

void Employee::startdata(void){

    number = 0;
    strcpy(name," ");
    strcpy(position,"employee");
    jobtime = 0;

}
void Employee::getdata(void){

    cout << "Number: ";
    cin >> number;
    cout << "Name: ";
    cin >> name;
    cout << "Position: ";
    cin >> position;
    cout << "Jobtime: ";
    cin >> jobtime;

}

void Employee::showdata(void){

    cout << "Number = " << number << "\n";
    cout << "Name = " << name << "\n";
    cout << "Position = " << position << "\n";
    cout << "Jobtime = " << jobtime << "\n";

}

float Employee::calSalary(void){
    char boss[5];
    strcpy(boss,"boss");

    if(addJob(jobtime) == 1)
        jobtime++;

    if(strcmp(position,boss) == 0)
        return bossSalary();

    else
        return 300000 / 168 * (21*jobtime);
}

float Employee::bossSalary(void){
    return 500000 / 168 * (21*jobtime);
}

int Employee::addJob(float jobtime){
    return (jobtime > 0 && jobtime < 24);
}





int main()
{

    Employee emp1;
    emp1.startdata();
    emp1.getdata();
    emp1.showdata();
    cout << "Salary = " << emp1.calSalary();

    return 0;
}
