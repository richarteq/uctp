/*
 @file uctpv1.0.cpp

 @datetime 2019-10-11 10:14:10 a.m.
 @version 1.0
 @author Richart Smith Escobedo Quispe
 @contact rescobedoq@unsa.edu.pe
 
 @description
 Implementation for initial solution (of the instances) of Curriculum Based Course Timetabling 2007.
 This code read the input file dataset for Curriculum Based Course Timetabling to vectors what containt structs.
 http://www.cs.qub.ac.uk/itc2007/curriculmcourse/course_curriculm_index.htm
 
 @structs course, room, curricula and constraint.
 @vectors coursesVector, roomsVector, curriculaVector and contraintsVector.

 @copyright 2019, Richart Smith Escobedo Quispe. All Rights Reserved.
 @licence GPLv3 - https://www.gnu.org/licenses/gpl-3.0.html
*/

#include <bits/stdc++.h>
using namespace std;

/* ******************** <structs ******************** */
/**/
//	event
struct course{
	string courseId;
	string teacherName;
	int lecturesNumber;
	int minWorkingDays;
	int studentsNumber;
};
//	room
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
	
	/* ******************** <iFile ******************** */
	/**/
	//string iPath = "Datasets/Early/comp01.ctt";
	//string iPath = "Datasets/Late/comp08.ctt";
	//string iPath = "Datasets/Hidden/comp15.ctt";
	string iPath = "Datasets/example.ctt";
	ifstream iFile (iPath);
	/**/
	/* ******************** iFile> ******************** */

	/* ******************** <iFile/variables ******************** */
	/**/
	string labelInstance, nameInstance;
	string labelCourses; int coursesNumber;	// The total number of events
	string labelRooms; int roomsNumber;			// The total number of rooms
	
	string labelDays; int daysNumber;
	string labelPeriodsPerDay; int periodsPerDayNumber;	// The total number of periods
	
	string labelCurricula; int curriculaNumber;
	string labelConstraints; int constraintsNumber;
	/**/
	/* ******************** iFile/variables> ******************** */

	/* ******************** <iFile/variables/read ******************** */
	/**/
	iFile>>labelInstance>>nameInstance;	
	iFile>>labelCourses>>coursesNumber;	// The total number of events
	iFile>>labelRooms>>roomsNumber;			// The total number of rooms
	
	iFile>>labelDays>>daysNumber;
	iFile>>labelPeriodsPerDay>>periodsPerDayNumber;	// The total number of periods
	
	iFile>>labelCurricula>>curriculaNumber;
	iFile>>labelConstraints>>constraintsNumber;
	/**/
	/* ******************** iFile/variables/read> ******************** */

	/* ******************** <iFile/variables/print ******************** */
	/**/
	cout<<endl<<"|-----------------------------------------------|";
	cout<<endl<<"|"<<"\tCurriculum based Course timetabling\t"<<"|";
	cout<<endl<<"|-----------------------------------------------|"<<endl<<endl;
	cout<<"Instance file :"<<" "<<iPath<<endl;
	cout<<labelInstance<<" "<<nameInstance<<endl;
	cout<<labelCourses<<" "<<coursesNumber<<endl;
	cout<<labelRooms<<" "<<roomsNumber<<endl;
	cout<<labelDays<<" "<<daysNumber<<endl;
	cout<<labelPeriodsPerDay<<" "<<periodsPerDayNumber<<endl;
	cout<<labelCurricula<<" "<<curriculaNumber<<endl;
	cout<<labelConstraints<<" "<<constraintsNumber<<endl;
	/**/
	/* ******************** iFile/variables/print> ******************** */

	/* ******************** <iFile/showData ******************** */
	/**/
	char showData;
	showData='y'; // 'y' or 'n'
	/**/
	/* ******************** iFile/showData> ******************** */


	/* ******************** <iFile/read/courses ******************** */
	/**/
	vector<course> coursesVector;
	int i;
	string line;
		
	getline(iFile,line);
	getline(iFile,line);

	struct course courseStruct;
	
	getline(iFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=coursesNumber;i++){
		iFile>>courseStruct.courseId>>courseStruct.teacherName>>courseStruct.lecturesNumber>>courseStruct.minWorkingDays>>courseStruct.studentsNumber;
		coursesVector.push_back(courseStruct);
	}
	if( tolower(showData)=='y' ){cout<<" "<<coursesVector.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:coursesVector){
			cout<<item.courseId<<"\t"<<item.teacherName<<"\t"<<item.lecturesNumber<<"\t"<<item.minWorkingDays<<"\t"<<item.studentsNumber<<endl;
		}
	}
	/**/
	/* ******************** iFile/read/courses> ******************** */

	/* ******************** <iFile/read/rooms ******************** */
	/**/
	vector<room> roomsVector;

	getline(iFile,line);
	getline(iFile,line);

	struct room roomStruct;
	
	getline(iFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=roomsNumber;i++){
		iFile>>roomStruct.roomId>>roomStruct.capacity;
		roomsVector.push_back(roomStruct);
	}
	if( tolower(showData)=='y' ){cout<<" "<<roomsVector.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:roomsVector){
			cout<<item.roomId<<"\t"<<item.capacity<<endl;
		}
	}
	/**/
	/* ******************** iFile/read/rooms> ******************** */

	/* ******************** <iFile/read/curricula ******************** */
	/**/
	vector<curricula> curriculaVector;

	getline(iFile,line);
	getline(iFile,line);

	struct curricula curriculaStruct;
	int j;
	string memberId;
	
	getline(iFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=curriculaNumber;i++){
		iFile>>curriculaStruct.curriculumId>>curriculaStruct.coursesNumber;
		curriculaStruct.membersId.clear();
		for(j=1;j<=curriculaStruct.coursesNumber;j++){
			iFile>>memberId;
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
	/* ******************** iFile/read/curricula> ******************** */

	/**/
	/* ******************** iFile/read/constraints> ******************** */
	vector<constraint> constraintsVector;

	getline(iFile,line);
	getline(iFile,line);

	struct constraint constraintStruct;
	
	getline(iFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=constraintsNumber;i++){
		iFile>>constraintStruct.courseId>>constraintStruct.day>>constraintStruct.dayPeriod;
		constraintsVector.push_back(constraintStruct);
	}
	if( tolower(showData)=='y' ){cout<<" "<<constraintsVector.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:constraintsVector){
			cout<<item.courseId<<"\t"<<item.day<<"\t"<<item.dayPeriod<<endl;
		}		
	}
	/**/
	/* ******************** iFile/read/constraints> ******************** */

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
