#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"
using namespace std;

Course::Course(string id, string title, Date startTime, Date endTime) :
id(id), title(title), startTime(startTime), endTime(endTime) {}
	

string Course::getID() { return id; } 
string Course::getTitle() { return title; }
Date Course::getStartTime() { return startTime; }
Date Course::getEndTime() { return endTime; }


void Course::addAttendanceRecord(AttendanceRecord ar) {
	if(ar.getDate() <= endTime && ar.getDate() >= startTime) {
	attendanceRecords.push_back(ar);
	} else {
		cout << "did not save this record." << endl;
	}
}

void Course::outputAttendance() {
	if (!attendanceRecords.empty()) {
	for(unsigned int i = 0; i < attendanceRecords.size(); i++) {
		cout << attendanceRecords[i].getDate().getDateTime() << ","; 
	    cout << attendanceRecords[i].getCourseID() << ",";
		cout << attendanceRecords[i].getStudentID() << endl;
	}
	} else {
		cout << "No Records" << endl;
	}
}

void Course::outputAttendance(string student_id) {
	int tracker = 0;
	if(!attendanceRecords.empty()) {
		for(unsigned int i = 0; i < attendanceRecords.size(); i++) {
			if (student_id == attendanceRecords[i].getStudentID()) {
				cout << attendanceRecords[i].getDate().getDateTime() << ","; 
				cout << attendanceRecords[i].getCourseID() << ",";
				cout << attendanceRecords[i].getStudentID() << endl;
				tracker = 1;
			}	
		}
	} else {
		cout << "No Records" << endl;
	}
	if (tracker==0) {
			cout << "No Records"<< endl;
		}
}
 