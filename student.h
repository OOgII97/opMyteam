#ifndef OOP_student_h
#define OOP_student_h

class student{
	private:
		char *id;
		float GPA;
		static int count = 0;
	public:
		char *name;
		int course;
		student();
		student(char[] ,char[], int, float);
		void stud_copy(student &);
		student(student &stud);
		
		bool greatThan(student &);
		bool lessThan(student &);
		bool isEqual(student &);
		bool before(student &); 
		bool after(student &);

		char *get_name();
		char *get_id();
		int get_course();
		float get_GPA();
	

		void set_name(char[]);
		void set_id(char[]);
		void set_course(int);
		void set_GPA(float);

		~student();
		static void show_count();
		
};

#endif
