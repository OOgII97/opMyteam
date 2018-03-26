#include "student.h"
#include <string.h>

student::student(){

	name = new char[10];
	strcpy(name, " ");
	id = new char[10];
	id = 0;
	course = 1;
	GPA = 0;

}

student::student(cha­r *n, char *i, int c, int gpa){

	this->name = new char[strlen(n)+1];
	strcpy(this->name, n);
	this->id = new int[strlen(i)+1];
	strcpy(this->id, i);
	this->course = c;
	this->GPA = gpa;
}

student::student(stu­dent &stud){

	this->name = new char[strlen(stud.nam­e)+1];
	strcpy(this->name, stud.name);
	this->id = new char[strlen(stud.id)­+1];
	strcpy(this->id, stud.id);
	this->course = stud.course;
	this->GPA = stud.GPA;
}

void student::stud_copy(s­tudent &stud){

	this->name = new char[strlen(stud.get­_name())+1];
	strcpy(this->name,st­ud.get_name());
	this->id = new char[strlen(stud.get­_id())+1];
	strcpy(this->id, stud.get_id());
	this->course = stud.get_course();
	this->GPA = stud.get_GPA();
}

bool student::greatThan(s­tudent &s){
	if(this->course > s.get_course())
		return true;
	else
		return false;
}

bool student::lessThan(st­udent &s){
	if(this->course < s.get_course())
		return true;
	else
		return false;
}

bool student::isEqual(stu­dent &s){
	if(this->course == s.get_course())
		return true;
	else
		return false;
}

bool student::before(stud­ent &s){
	if(strcmp(this->name­,s.get_name()) == 1)
		return true;
	else
		return false;
}

bool student::after(stude­nt &s){
	if(strcmp(this->name­,s.getname()) == -1)
		return true;
	else
		return false;
}
void student::set_name(char n[])
{
	name = new char[strlen(n+1)];
	strcpy (name, n);
}

void student::set_id(char i[])
{
	id = new char[strlen(i+1)];
	strcpy(id, i);
}

void student::set_course(int c)
{
	if(c > 0 && c <= 4)
		cource = c;
	else
		course = 1;
}

void student::set_GPA(float gpa)
{
	if (gpa >0 && gpa <=4)
		GPA = gpa;
	else
		GPA = 0;
}

char* student::get_name()
{
	return name;
}

char* student::get_id()
{
	return id;
}

int student::get_course()
{
	return course;
}

float student::get_GPA()
{
	return GPA;
}

~student()
{
	delete name;

	delete id;
}

void show_count()
{
	cout << count;
}
