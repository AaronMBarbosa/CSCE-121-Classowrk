#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string id,string name) :
    id(id), name(name) {}
	
	

	
string Student::get_id()  {
	return id;
	
}
string Student::get_name() {
	return name;
	
}
void Student::addCourse(string course_id) {
	unsigned int p = 0;
	bool dupe = false;
	if (course_ids.size() > 0) {
	while(p <= course_ids.size()) {
		if (course_ids[p] == course_id) {
		dupe = true;	
		} 
		p++;
		
	}
	}
	if (dupe == false) {
	course_ids.push_back(course_id);
	}
}

void Student::listCourses() {
	if (!course_ids.empty()) {
	cout << "Courses for "<< id << "\n";
	for(unsigned int i = 0; i < course_ids.size(); i++) {
		cout << course_ids[i] << "\n";
	}
	} else {
		cout << "No Records" << endl;
	}
}



