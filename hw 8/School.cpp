#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime> 
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
      students.push_back(Student(uin, name));
    }
  }
}

void School::addAttendanceData(string filename){
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  
   while (!ifs.eof()) {
	   int wow = 0;
       string line;
       getline(ifs, line);
	   istringstream ss(line);
	   string date;
	   getline(ss,date,',');
	   std::tm a = {};
	   istringstream timesplit(date);
	   timesplit >> std::get_time(&a, "%Y-%m-%d %H:%M:%S");
	   Date att(a.tm_year-100+2000, a.tm_mon+1, a.tm_mday, a.tm_hour,a.tm_min,a.tm_sec);
	   string classid;
	   getline(ss,classid,',');
	   string studentid;
	   getline(ss,studentid,',');
	   if (!ss.fail()) {
			AttendanceRecord ar(classid,studentid,att);
			while (courses[wow].getID() != classid) {
				wow += 1;
			}
			courses[wow].addAttendanceRecord(ar);
		}
		
   }
	
}
void School::addCourses(string filename) { 
ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
	  struct std::tm t = {0};
	  struct std::tm w = {0};
	  
	  string line;
	  getline(ifs, line);
	  istringstream ss(line);
	  string classnum;
	  getline(ss,classnum,',');
	  string start;
	  getline(ss,start,',');
	  if (start.size() == 4) {
		  start = "0"+start;
	  }

	  
	  
	  istringstream time(start);
	  time >> get_time(&t,"%H:%M");
	  int sthr = t.tm_hour;
	  int stmn = t.tm_min;
	  
	  string end;
	  getline(ss,end,',');
	  if (end.size() == 4) {
		  end = "0"+end;
	  }
	  
	  istringstream time2(end);
	  time2 >> get_time(&w,"%H:%M");
	  int edhr = w.tm_hour;
	  int edmn = w.tm_min;
	  
	  
	  Date d(sthr,stmn,0);
	  Date d2(edhr,edmn,0);
	  if (d.getHour() == 00 && d.getMin() == 00) {
		  break;
	  }
		  
	  
	  string name;
	  getline(ss,name,',');
	  if (ss.eof()) {
      courses.push_back(Course(classnum, name, d, d2));
	  continue;
      }
	  string name2; 
	  getline(ss, name2, ',');
	  if (ss.eof()) {
      courses.push_back(Course(classnum, name, d, d2));
	  continue;
      }
	  name = name + "," + name2;
	  string name3; 
	  getline(ss, name3, ',');
	  name = name + "," + name3;
	 if (!ss.fail()) {
      courses.push_back(Course(classnum, name, d, d2));
    }
  }
  

}


void School::listCourses() {
	if (!courses.empty()) {
	for (unsigned int k = 0; k < courses.size(); k++) {
	Course s(courses[k]);
	cout << s.getID() << ",";
	cout << s.getStartTime().getTime(false) << ",";
	cout << s.getEndTime().getTime(false) << ",";
	cout << s.getTitle();
	cout << endl;
	}
	} else {
		string error = "No Courses";
		cout << error << endl;
	}
}
void School::listStudents() {
	if (!students.empty()) {
	for (unsigned int i = 0; i < students.size(); i++) {
	Student s(students[i]);
	cout << s.get_id() << ",";
	cout << s.get_name();
	cout << endl;
	}
	} else {
		string error = "No Students";
		cout << error << endl;
	}
}
void School::outputCourseAttendance(string course_id) {
	for (unsigned int i = 0; i < courses.size(); i++) {
		Course s(courses[i]);
		if (s.getID()== course_id) {
			s.outputAttendance();
		}
		
	}
	cout << endl;
}
void School::outputStudentAttendance(string student_id, string course_id) {

		for (unsigned int i = 0; i < courses.size(); i++) {
			Course s(courses[i]);
			  for (unsigned int w = 0; w < students.size(); w++) {	
				Student l(students[w]);
					if (s.getID()== course_id && l.get_id() == student_id) {
						s.outputAttendance(student_id);
					
					}
				}
		}
	cout << endl;
}

