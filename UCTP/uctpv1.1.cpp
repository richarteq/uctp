/*
 @file uctpv1.1.cpp

 @datetime 2019-10-14 11:10:25 a.m.
 @version 1.1
 @author Richart Smith Escobedo Quispe
 @contact rescobedoq@unsa.edu.pe
 
 @description
 Implementation for initial solution (of the instances) of Curriculum Based Course Timetabling 2007.
 This code read the input file dataset for Curriculum Based Course Timetabling to vectors what containt structs.
 http://www.cs.qub.ac.uk/itc2007/curriculmcourse/course_curriculm_index.htm
 
 @structs e, r, curricula and constraint.
 @vectors E, R, curriculaVector, contraintsVector, p, timetable and X.

 @copyright 2019, Richart Smith Escobedo Quispe. All Rights Reserved.
 @licence GPLv3 - https://www.gnu.org/licenses/gpl-3.0.html
*/

#include <bits/stdc++.h>
using namespace std;

/* ******************** <structs ******************** */
/**/
//	e = event
struct e{
	string courseId;
	string teacherName;
	int lecturesNumber;
	int minWorkingDays;
	int studentsNumber;
};
//	r = room
struct r{
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

string printDay(int dayId);

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
	string labelCourses; int n;	// n = The total number of events
	string labelRooms; int m;		// m = The total number of rooms
	
	string labelDays; int daysNumber;
	string labelPeriodsPerDay; int t;	// t = The total number of periods
	
	string labelCurricula; int curriculaNumber;
	string labelConstraints; int constraintsNumber;
	/**/
	/* ******************** iFile/variables> ******************** */

	/* ******************** <iFile/variables/read ******************** */
	/**/
	iFile>>labelInstance>>nameInstance;	
	iFile>>labelCourses>>n;	// n = The total number of events
	iFile>>labelRooms>>m;		// m = The total number of rooms
	
	iFile>>labelDays>>daysNumber;
	iFile>>labelPeriodsPerDay>>t;	// t = The total number of periods
	
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
	cout<<labelCourses<<" "<<n<<endl;
	cout<<labelRooms<<" "<<m<<endl;
	cout<<labelDays<<" "<<daysNumber<<endl;
	cout<<labelPeriodsPerDay<<" "<<t<<endl;
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


	/* ******************** <vectors_othersVariables ******************** */
	/**/
	int i,j,k;
	string line;

	vector<e> E;	//	Set of the events,	E = {e1,..., en},	|E| = n
	vector<r> R;	//	Set of the rooms,		R = {r1,...,rm},	|R| = m

	// The total number of scheduling periods is the product of the days times the day timeslots.
	vector<int> p;	//	Set of the periods,	P = {p1,....,pt},	|P| = t
	vector<std::vector<int>> timetable;
	for(i=1; i<=t; i++){
		p.push_back(-1);
	}
	for(i=1; i<=daysNumber; i++){
		timetable.push_back(p);
	}	
	/**/
	/* ******************** vectors_othersVariables> ******************** */

	/* ******************** <iFile/read/events ******************** */
	/**/
	getline(iFile,line);
	getline(iFile,line);

	struct e course;
	
	getline(iFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=n;i++){
		iFile>>course.courseId>>course.teacherName>>course.lecturesNumber>>course.minWorkingDays>>course.studentsNumber;
		E.push_back(course);
	}
	if( tolower(showData)=='y' ){cout<<" "<<E.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:E){
			cout<<item.courseId<<"\t"<<item.teacherName<<"\t"<<item.lecturesNumber<<"\t"<<item.minWorkingDays<<"\t"<<item.studentsNumber<<endl;
		}
	}
	/**/
	/* ******************** iFile/read/events> ******************** */

	/* ******************** <iFile/read/rooms ******************** */
	/**/
	getline(iFile,line);
	getline(iFile,line);

	struct r room;
	
	getline(iFile,line);
	if( tolower(showData)=='y' ){cout<<endl<<line;}
	for(i=1;i<=m;i++){
		iFile>>room.roomId>>room.capacity;
		R.push_back(room);
	}
	if( tolower(showData)=='y' ){cout<<" "<<R.size()<<endl;}

	if( tolower(showData)=='y' ){
		for(auto item:R){
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
	/* ******************** <iFile/read/constraints ******************** */
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
	/* ******************** <memory/vectors/size ******************** */
	cout<<endl<<"|----------- VECTORS IN MEMORY ---------|";
	cout<<endl<<"|\t"<<"E.size() = "<<E.size()<<"\t|";
	cout<<endl<<"|\t"<<"R.size() = "<<R.size()<<"\t\t|";
	cout<<endl<<"|\t"<<"curriculaVector.size() = "<<curriculaVector.size()<<"\t|";
	cout<<endl<<"|\t"<<"constraintsVector.size() = "<<constraintsVector.size()<<"\t|";
	cout<<endl<<"|---------------------------------------|"<<endl;
	/**/
	/* ******************** memory/vectors/size> ******************** */
	//cout<<endl;

	/**/
	/* ******************** <Xsolution/initialize ******************** */
	vector<std::vector<std::vector<int>>> X;

	for(i=1; i<=m; i++){
		X.push_back(timetable);
	}
	/**/
	/* ******************** Xsolution/initialize> ******************** */

	/**/
	/* ******************** <Xsolution/print ******************** */
	int rO=0, dA, pE;
	for(auto item:X){
		cout<<endl<<"room "<<rO<<" : "<<R[rO].roomId;
		dA=0;
		for(auto item2:item){
			cout<<endl<<"\tday "<<dA<<" : "<<printDay(dA)<<endl;
			pE=0;
			for(auto item3:item2){
				if(pE==0){cout<<"\t\t";}
				cout<<item3<<"\t";
				pE++;
			}
			dA++;
		}
		rO++;
	}
	cout<<endl;
	/**/
	/* ******************** Xsolution/print> ******************** */

	return 0;
}

string printDay(int dayId){
	switch(dayId){
		case 0: return "Monday"; break;
		case 1: return "Tuesday"; break;
		case 2: return "Wednesday"; break;
		case 3: return "Thursday"; break;
		case 4: return "Friday"; break;
		case 5: return "Saturday"; break;
		case 6: return "Sunday"; break;
		default: return "Badday";
	}
}
