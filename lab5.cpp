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
    float bossSalary();

    public:

     Employee();
     Employee(char *, char *, int ,float , float);
    ~Employee();
	
	void setName(char *);
	char * getName();
	
	void setPos(char *);
	char * getPos();
	
	void setNum(int );
	int getNum();
	
	void setTime(int );
	int getTime();
    // Garaas ugugdul unshih gishvvn punkts
    void showdata();
    // salary g/ogogdliin utgiig butsaah gishvvn punkts
    float getpay();
    // ajilchdiin tsalin tootsooloh g/punkts
    float calSalary();
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

    delete position;

    delete name;
    
}


void Employee::setName(char *n){
    if(name)
        delete name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
    
}

char * Employee::getName(){
	return name;
}

void Employee::setPos(char *p){
	if(position)
		delete position;
	position = new char[strlen(p)+1];
	strcpy(position, p);
}

char * Employee::getPos(){
	return position;
}

void Employee::setNum(int n){
	number = n;
}

int Employee::getNum(){
	return number;
}

void Employee::setTime(int j){
	jobtime = j;
}

int Employee::getTime(){
	return jobtime;
}


//ajilchnii medeelel haruulah gishvvn punkts todorhoilson heseg
void Employee::showdata(){

    cout << "Number = " << number << "\n";
    cout << "Name = " << name << "\n";
    cout << "Position = " << position << "\n";
    cout << "Salary = " << salary << endl;

}

//tsalin tootsoh gishvvn punkts
float Employee::calSalary(){  
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
float Employee::bossSalary(){
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
    int number, jobTime, count = 0;
    char name[10], position[10];

    //n ajiltnii toog garaas unshina
    cout << "Oruulah ajiltanii too:";
    cin >> n;
    //0 -ees n hvrtel ajiltanii medeelel garaas unshina
    for(k = 0; k < n; k++){
    	
    	 //ahiltanii dugaariig shalgaj utga onooh dawtalt
    	 do{
		 //shineer oruulah dugaariig garaas unshih
         cout << "\t" <<"Ajiltnii dugaar : ";
         cin >> number;
         //oruulsan dugaariig omnoh obiektiin ajilchdiin dugaartai dawhtsaj bgaa esehiig shalgah dawtalt
         for(int i = 0; i < k; i++){
         	if(emp[i].getNum() == number)
         	    //herew ajilchdiin dugaar dawhtsal tooluuriig nemegdvvlen dawtaltiig duusgana.
         	    count++;
         		break;
		 }
		 //herew tooluur oorchlogdoogvi bol k dahi ajilchnii dugaariig gishvvn ogogdold onoono6
		 if(count == 0){
		 	emp[k].setNum(number);
		 }
         //esregtohioldold aldaag hewlen count iin utgiig 0 bolgoj dahin deerh vildlvvdiig dawtana.	
         else{
         	cout << "Ajiltnii dugaar dawhtsaj bna\n Dahin oruulna uu!!\n";
         	count = 0;
		 }
         	
         //herew k ajilt gishvvn ugugdul anhnii utgaasaa oor garaas utga awhad dawtalt duusna	
    	}while(emp[k].getNum() == 0);
    	
      	 cout << "\t" <<"Ajiltnii ner : ";
         cin >> name;
         emp[k].setName(name);
         
         cout << "\t" <<"Alban tushaal : ";
         cin >> position;
         emp[k].setPos(position);
         
         cout << "\t" <<"Ajilsan tsag : ";
         cin >> jobTime;
         emp[k].setTime(jobTime);  
         
         emp[k].calSalary(); 
         
         }

    

   //bubble sort
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++)
            //omnoh ajiltnii ner ni daraagiin ajiltnii nerees omno bwal swap hiine
            if(strcmp(emp[i].getName(),emp[j].getName()) == 1){
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
    	//emp[k] dugaar ajiltnii medeelliig showdata g.punktseer hewlene
        emp[k].showdata();    
    } 
    

    return 0;
}
