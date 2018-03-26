#include"student.h"
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	student *s;
	student s1;
	s = &s1;
	int n, k, i, j;
    int course, GPA, c = 0;
    char name[20], id[20];
	cout << "Heden oyutnii medeelel oruulah we:";
    cin >> n;
    
    for(k = 0; k < n; k++){
    	
    	 
    	 do{
        cout << "\t" <<"Oyutnii id : ";
        cin >> id;
		
		for(int i = 0; i < k; i++){
         	if(s[i]->.get_id() == id)
         	   
         	    c++;
         		break;
		 }
		
		 if(c == 0){
		 	s[k]->set_id(id);
		 }	
         else{
         	cout << "Oyutnii dugaar dawhtsaj bna\n Dahin oruulna uu!!\n";
         	c = 0;
		 }
         	
         	
    	}while(s[k]->get_id() == 0);
		cout << "\t" <<"Oyutnii ner : ";
        cin >> name;
 			
		cout << "\t" <<"Oyutnii kurs : ";
        cin >> course;

		cout << "\t" <<"Oyutnii golch : ";
        cin >> GPA;

		//bubble sort
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++)
           
            if(strcmp(s[i]->get_name(),s[j]->get_name()) == 1){
                //swap hiih vildel
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
	
    }

    //print jagsaalt
    cout << "Jagsaalt:" << endl;

    //0 ees n hvrtel eremblegdsen oyutnii medeelliig hewlene
    for(k = 0; k < n; k++){
    	//emp[k] dugaar ajiltnii medeelliig showdata g.punktseer hewlene
        s[k]->name;    
    } 
    

    return 0;

}
