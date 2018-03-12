#include <iostream>
#include <string.h>

using namespace std;

class Employee
{

    private:

    int number;
    char *name;
    char *position;
    float salary;
    float jobtime;
    float bossSalary(void);

    public:

     Employee();
     Employee(char *, char *, int ,float , float);
    ~Employee();

    // Garaanii utga onooh gishvvn punkts
    void startdata(void);
    // Garaas ugugdul unshih gishvvn punkts
    void setdata(void);
    // Ugugdliin utgiig haruulah g/punkts
    void showdata(void);
    // salary g/ogogdliin utgiig butsaah gishvvn punkts
    float getpay();
    // ajilchdiin tsalin tootsooloh g/punkts
    float calSalary(void);
    // nemelt tsag tootsoh g/punkts
    int addJob(float);

};

Employee::Employee(){

    name = new char[7];
    strcpy(name," ");
    position = new char[10];
    strcpy(position,"position");
    number = 0;
    salary = 0;
    jobtime = 0;

}
Employee::Employee(char *n, char *p, int a, float s, float j){

    name = new char [ strlen(n) + 1 ];
    strcpy (name,n);
    position = new char [strlen(p) + 1];
    strcpy (position,p);
    number = a;
    salary = s;
    jobtime = j;

}

Employee::~Employee(){

    cout<<"The object "<<position<<" is deleted;"<<endl;
    delete position;

    cout<<"The object "<<name<<" is deleted;"<<endl;
    delete name;
    
}


void Employee::setName(char *n){
    if(name)
        delete name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
    
}

void Employee::startdata(void){
    //numberd 0 utga onoono
    number = 0;
    //name d strcpy punktseer hooson utga onoono
    strcpy(name," ");
    //position strcpy punktseer ajiltan gesen utga onoono
    strcpy(position,"ajiltan");
    //ajilsan tsagt 0 gesen utga onoono
    jobtime = 0;

}

//garaas utga awah punktsiin todorhoilson heseg
void Employee::setdata(void){
    //ajilchinii number garaas awah
    cout << "Number: ";
    cin >> number;
    //ajilchnii ner garaas awah
    cout << "Name: ";
    cin >> name;
    //alban tushaal garaas awah
    cout << "Position: ";
    cin >> position;
    //ajilsan tsag garaas awah 1-8 hoorond bna
    cout << "Jobtime: ";
    cin >> jobtime;

}

//ajilchnii medeelel haruulah gishvvn punkts todorhoilson heseg
void Employee::showdata(void){

    cout << "Number = " << number << "\n";
    cout << "Name = " << name << "\n";
    cout << "Position = " << position << "\n";
    cout << "Salary = " << salary << endl;

}

//tsalin tootsoh gishvvn punkts
float Employee::calSalary(void){  
    //garaas unshsan position(alban tushaal) boss hvsnegtiinhtiin utgatai adil esehiig shalgana
    if(strcmp(position,"zahiral") == 0)
        //adil bwal zahirliin tsalin bodoh g.punktsiig duudna
        bossSalary();
    //vgvi bol hewiin ajilchnii tsalin bodoj salary-d utgiig onoono
    else
        //niit awah tsalin / ajillah niit tsag * (ajilsan honog* ajilsan tsag)
        salary = 300000 / 168 * (21*jobtime);
}

//zahirliin tsalin bodoh gishvvn punkts
float Employee::bossSalary(void){
    //niit awah tsalin / ajillah niit tsag * (ajilsan honog* ajilsan tsag)
    salary = 500000 / 168 * (21*jobtime);
}

//nemelt tsag tootsoh g.punkts
int Employee::addJob(float j){
    // odort ajilsan tsag ni 0 oos ih 24 oos baga bwal 1 iig butsaana esreg tohioldold 0 iig butsaana
    if(jobtime > 0 && jobtime < 24){
        jobtime += j;
        return 1; 
    }
    else 
        return 0;
}
//ajilchnii tsalind handah g.punkts
float Employee::getpay(){
    //punkts duudsan ved tuhain ajilchnii salary-g butsaana
    return salary;
}



int main()
{
    //obiekten hvsneg vvsgene, mun engiin empk nertei obiekt vvsgene
    Employee emp[10],empk;
    //ashiglah parametervvdee zarlana
    int n, k, i, j;

    //n ajiltnii toog garaas unshina
    cout << "Oruulah ajiltanii too:";
    cin >> n;
    //0 -ees n hvrtel ajiltanii medeelel garaas unshina
    for(k = 0; k < n; k++){
        //emp[k] dugaar ajiltnii medeelliig unshina
        emp[k].setdata();
        //emp[k] dugaar ajiltnii tsalin tootsoolon salary -d ni utgiig ni hadgalna
        emp[k].calSalary();
    }

    

   //bubble sort
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++)
            //omnoh ajiltnii tsalin daraagiin ajiltnii tsalingaas baga bwal swap hiine
            if(emp[i].getpay() < emp[j].getpay()){
                //swap hiih vildel
                empk = emp[i];
                emp[i] = emp[j];
                emp[j] = empk;
            }
    }

    //print jagsaalt
    cout << "Jagsaalt:" << endl;

    //0 ees n hvrtel eremblegdsen ajilnii medeelliig hewlene
    for(k = 0; k < n; k++){
        cout << k+1 <<":\n";
        //emo[k] dugaar ajiltnii medeelliig showdata g.punktseer hewlene
        emp[k].showdata();
    }
        
    

    return 0;
}