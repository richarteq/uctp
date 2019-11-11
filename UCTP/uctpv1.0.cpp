/*
 @file uctpv1.0.cpp
 @datetime 2019-10-11 10:14:09 a.m.
 @version 1.0
 @author Richart Smith Escobedo Quispe
 @contact: rescobedoq@unsa.edu.pe
 
 @description
 Implementation for initial solution (of the instances) of Curriculum Based Course Timetabling 2007.
 This code read the input file dataset for Curriculum Based Course Timetabling.
 http://www.cs.qub.ac.uk/itc2007/curriculmcourse/course_curriculm_index.htm
 
 @structs course, room, curricula and constraint
 @vectors coursesVector, roomsVector, curriculaVector and contraintsVector.

 @copyright 2019 Richart Smith Escobedo Quispe. All Rights Reserved.
 @licence GPLv3 - https://www.gnu.org/licenses/gpl-3.0.html
*/

#include <bits/stdc++.h>
using namespace std;

/* ******************** <structs ******************** */
/**/
struct course{
	string courseId;
	string teacherName;
	int lecturesNumber;
	int minWorkingDays;
	int studentsNumber;
};
struct room{
	string roomId;
	int capacity;
};
struct curricula{
	string curriculumId;
	int coursesNumber;
	vector<string> membersId;
};
struct constraint{
	string courseId;
	int day;
	int dayPeriod;
};
/**/
/* ******************** structs> ******************** */

int main(int argc, char *argv[]) {
	
	/* ******************** <instanceFile ******************** */
	/**/
	//string instancePath = "Datasets/Early/comp01.ctt";
	//string instancePath = "Datasets/Late/comp08.ctt";
	//string instancePath = "Datasets/Hidden/comp15.ctt";
	string instancePath = "Datasets/example.ctt";
	ifstream instanceFile (instancePath);
	/**/
	/* ******************** instanceFile> ******************** */

	/* ******************** <instanceFile/variables ******************** */
	/**/
	string textName, nameValue;
	string textCourses; int coursesNumber;
	string textRooms; int roomsNumber;
	string textDays; int daysNumber;
	string textPeriodsPerDay; int periodsPerDayNumber;
	string textCurricula; int curriculaNumber;
	string textConstraints; int constraintsNumber;
	/**/
	/* ******************** instanceFile/variables> ******************** */

	/* ******************** <instanceFile/variables/read ******************** */
	/**/
	instanceFile>>textName>>nameValue;	
	instanceFile>>textCourses>>coursesNumber;
	instanceFile>>textRooms>>roomsNumber;
	instanceFile>>textDays>>daysNumber;
	instanceFile>>textPeriodsPerDay>>periodsPerDayNumber;
	instanceFile>>textCurricula>>curriculaNumber;
	instanceFile>>textConstraints>>constraintsNumber;
	/**/
	/* ******************** instanceFile/variables/read> ******************** */

	/* ******************** <instanceFile/variables/print ******************** */
	/**/
	cout<<endl<<"|-----------------------------------------------|";
	cout<<endl<<"|"<<"\tCurriculum based Course timetabling\t"<<"|";
	cout<<endl<<"|-----------------------------------------------|"<<endl<<endl;
	cout<<"Instance file :"<<" "<<instancePath<<endl;
	cout<<textName<<" "<<nameValue<<endl;
	cout<<textCourses<<" "<<coursesNumber<<endl;
	cout<<textRooms<<" "<<roomsNumber<<endl;
	cout<<textDays<<" "<<daysNumber<<endl;
	cout<<textPeriodsPerDay<<" "<<periodsPerDayNumber<<endl;
	cout<<textCurricula<<" "<<curriculaNumber<<endl;
	cout<<textConstraints<<" "<<constraintsNumber<<endl;
	/**/
	/* ******************** instanceFile/variables/print> ******************** */

	/* ******************** <instanceFile/showData ******************** */
	/**/
	char showData;
	showData='y'; // 'y' or 'n'
	/**/
	/* ******************** instanceFile/showData> ******************** */


	/* ******************** <instanceFile/toVector/courses ******************** */
	/**/
	vector<course> coursesVector;
	int i;
	string line;
		
	getline(instanceFile,line);
	getline(instanceFile,line);

	struct course courseStruct;
	
	getline(instanceFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=coursesNumber;i++){
		instanceFile>>courseStruct.courseId>>courseStruct.teacherName>>courseStruct.lecturesNumber>>courseStruct.minWorkingDays>>courseStruct.studentsNumber;
		coursesVector.push_back(courseStruct);
	}
	if( tolower(showData)=='y' ){cout<<" "<<coursesVector.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:coursesVector){
			cout<<item.courseId<<"\t"<<item.teacherName<<"\t"<<item.lecturesNumber<<"\t"<<item.minWorkingDays<<"\t"<<item.studentsNumber<<endl;
		}
	}
	/**/
	/* ******************** instanceFile/toVector/courses> ******************** */

	/* ******************** <instanceFile/toVector/rooms ******************** */
	/**/
	vector<room> roomsVector;

	getline(instanceFile,line);
	getline(instanceFile,line);

	struct room roomStruct;
	
	getline(instanceFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=roomsNumber;i++){
		instanceFile>>roomStruct.roomId>>roomStruct.capacity;
		roomsVector.push_back(roomStruct);
	}
	if( tolower(showData)=='y' ){cout<<" "<<roomsVector.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:roomsVector){
			cout<<item.roomId<<"\t"<<item.capacity<<endl;
		}
	}
	/**/
	/* ******************** instanceFile/toVector/rooms> ******************** */

	/* ******************** <instanceFile/toVector/curricula ******************** */
	/**/
	vector<curricula> curriculaVector;

	getline(instanceFile,line);
	getline(instanceFile,line);

	struct curricula curriculaStruct;
	int j;
	string memberId;
	
	getline(instanceFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=curriculaNumber;i++){
		instanceFile>>curriculaStruct.curriculumId>>curriculaStruct.coursesNumber;
		curriculaStruct.membersId.clear();
		for(j=1;j<=curriculaStruct.coursesNumber;j++){
			instanceFile>>memberId;
			curriculaStruct.membersId.push_back(memberId);
		}
		//cout<<endl;
		curriculaVector.push_back(curriculaStruct);
	}
	if( tolower(showData)=='y' ){cout<<" "<<curriculaVector.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:curriculaVector){
			cout<<item.curriculumId<<"\t"<<item.coursesNumber<<"\t";
			for(auto member:item.membersId){
				cout<<member<<"\t";
			}
			cout<<endl;
		}
	}
	/**/
	/* ******************** instanceFile/toVector/curricula> ******************** */

	/**/
	/* ******************** instanceFile/toVector/constraints> ******************** */
	vector<constraint> constraintsVector;

	getline(instanceFile,line);
	getline(instanceFile,line);

	struct constraint constraintStruct;
	
	getline(instanceFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=constraintsNumber;i++){
		instanceFile>>constraintStruct.courseId>>constraintStruct.day>>constraintStruct.dayPeriod;
		constraintsVector.push_back(constraintStruct);
	}
	if( tolower(showData)=='y' ){cout<<" "<<constraintsVector.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:constraintsVector){
			cout<<item.courseId<<"\t"<<item.day<<"\t"<<item.dayPeriod<<endl;
		}		
	}
	/**/
	/* ******************** instanceFile/toVector/constraints> ******************** */

	/**/
	/* ******************** memory/vectors/size> ******************** */
	cout<<endl<<"|----------- VECTORS IN MEMORY ---------|";
	cout<<endl<<"|\t"<<"coursesVector.size() = "<<coursesVector.size()<<"\t|";
	cout<<endl<<"|\t"<<"roomsVector.size() = "<<roomsVector.size()<<"\t\t|";
	cout<<endl<<"|\t"<<"curriculaVector.size() = "<<curriculaVector.size()<<"\t|";
	cout<<endl<<"|\t"<<"constraintsVector.size() = "<<constraintsVector.size()<<"\t|";
	cout<<endl<<"|---------------------------------------|"<<endl;
	/**/
	/* ******************** memory/vectors/size> ******************** */

	cout<<endl;

	return 0;
}
