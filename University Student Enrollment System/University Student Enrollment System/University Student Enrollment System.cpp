#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
using namespace std;

//.............................Structures........................................//

struct student {
	string s_id;
	string s_name;
	string s_course;
};

struct course {
	string c_id;
	string c_name;
	string c_capacity;
};

struct courseEnrollment {
	string s_name;
	string c_name;
};
//.....................End of Structure...............................//


//.......................Functions...................................//
void addStudent();
void viewStudent();
void addCourse();
void viewCourse();
void courseEnrollment();
void withdrawEnrollment();
void checkCourseRoster();
bool adminLogin();
void addUser();
bool checkUserFileLogin(const string& username, const string& password);
//.......................End of Functions.........................//


//*************************  Admin Login Section  **************************//

//..............Add admin user details outfile............//
bool checkUserFileLogin(const string& username, const string& password) {
	ifstream file("users.txt");
	string user, pass;
	while (file >> user >> pass) {
		if (user == username && pass == password)
			return true;
	}
	return false;
}
//................Main Admin Section...............//
bool adminLogin() {
	string username, password;
	cout << "\n*********** Admin Login ***********\n";
	cout << "Enter Username : ";
	cin >> username;
	cout << "Enter Password : ";
	cin >> password;

	const string admin_username = "sadeepa";
	const string admin_password = "sadeepa1234";

	if (username == admin_username && password == admin_password) {
		cout << "\nLogin successful!!... Welcome, Main Admin " << username << "\n\n Press Enter to Continue...." << ".\n\n";
		cin.ignore();
		cin.get();
		return true;
		//...........End of Main Admin Section..........//
	}
	//Add admin User Checking..........
	else if (checkUserFileLogin(username, password)) {
		cout << "\nLogin successful!!... Welcome, Admin " << username << "  Press Enter to Continue...." << ".\n\n";
		cin.ignore();
		cin.get();
		return true;

	}
	else {
		cout << "\nIncorrect User Name or Password, Please Check and Try Again.\n\n\n";
		return false;
	}
}
//************************* End of Admin Login Section  **************************//


//...............................Add User Section...............................//
void addUser() {
	string username, password;
	cout << "\n*********** Add New Admin ***********\n\n";
	cout << "Enter New Admin Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	ofstream file("users.txt", ios::app);
	file << username << " " << password << endl;
	file.close();
	cout << "\nNew Admin Added Successfully!\n";
}
//.........................End of Add User Section...............................//


//.......................Main Menu Area...........................//
int main() {

	cout << "___________________________________________________________\n";
	cout << "|                                                         |\n";
	cout << "|     Central University - Faculty of Science             |\n";
	cout << "|_________________________________________________________|\n";
	cout << "|                                                         |\n";
	cout << "|     Welcome to Our University Enrollment System         |\n";
	cout << "|_________________________________________________________|\n\n";


	int user_input;
	int user_type;

	while (true) {
		//.....................User Type..........................//
		cout << "\n Select User Type :\n\n";
		cout << "\t 1 Student\n\n";
		cout << "\t 2 Admin\n";
		cout << "\n\nEnter Your Choice : ";
		cin >> user_type;
		system("cls");
		//...................End of User type....................//

		//...................Student Menu..........................//
		if (user_type == 1) {
			do {
				cout << "=========================================================\n";
				cout << "\t            Welcome, Student!\n";
				cout << "\t  Central University - Faculty of Science\n";
				cout << "=========================================================\n\n";

				cout << "\t  1\t Register\n";
				cout << "\t  2\t View All Courses\n";
				cout << "\t  3\t Enroll in Course\n";
				cout << "\t  4\t Withdraw from Course\n";
				cout << "\t  5\t Back\n";
				cout << "\t  6\t Exit\n";
				cout << "_____________________________________________________\n\n";

				cout << "Enter Your Choice :";
				cin >> user_input;

				switch (user_input) {
				case 1:
					addStudent();
					break;

				case 2: {
					viewCourse();
					break;
				}

				case 3: {
					courseEnrollment();
					break;
				}

				case 4: {
					withdrawEnrollment();
					break;
				}

				case 5: {
					system("cls");
					goto back_to_user_type;
				}

				case 6:
					cout << "\nThanks For Using Our System, Good Bye Student! Have a Nice Day...!!!\n";
					exit(0);

				default:
					cout << "\nInvalid input. Please enter a number between 1 and 6.\n";
					cin.ignore();
					cin.get();
					system("cls");
				}
			} while (true);
		}
		//...................End of Student Menu...........................//


		//..........................Admin Menu.............................//
		else if (user_type == 2) {
			if (!adminLogin()) {
				cout << "";
				continue;
			}
			system("cls");
			do {
				cout << "=========================================================\n";
				cout << "\t            Welcome, Admin!\n";
				cout << "\t  Central University - Faculty of Science\n";
				cout << "=========================================================\n\n";
				cout << "\t  1\t Add User\n";
				cout << "\t  2\t Add Student\n";
				cout << "\t  3\t Check Student List\n";
				cout << "\t  4\t Add New Course\n";
				cout << "\t  5\t View Courses\n";
				cout << "\t  6\t Enroll Student in Course\n";
				cout << "\t  7\t Withdraw Student from Course\n";
				cout << "\t  8\t Check Course Roaster\n";
				cout << "\t  9\t Log out\n";
				cout << "\t 10\t Exit\n";
				cout << "_____________________________________________________\n\n";

				cout << "Enter Your Choice : ";
				cin >> user_input;

				switch (user_input) {
				case 1:
					addUser();
					break;

				case 2:
					addStudent();
					break;

				case 3:
					viewStudent();
					break;

				case 4:
					addCourse();
					break;

				case 5:
					viewCourse();
					break;

				case 6:
					courseEnrollment();
					break;

				case 7:
					withdrawEnrollment();
					break;

				case 8:
					checkCourseRoster();
					break;

				case 9:
					system("cls");
					goto back_to_user_type;

				case 10:
					cout << "\nThanks For Using Our System, Good Bye Admin! Have a Nice Day...!!!\n";
					exit(0);

				default:
					cout << "\nInvalid input. Please enter a number between 1 and 9.\n";
					cin.ignore();
					cin.get();
					system("cls");
				}

			} while (true);
		}

		else {
			cout << "Invalid login please check and try again.\n";
		}

	back_to_user_type:;
	}

	system("pause");
	return 0;
}
// ...........................End of Admin Menu...........................//


//....................Add Student Section...................//

void addStudent() {

	string existing_id;
	student details;

	cout << "\n\nEnter Student id : ";
	cin >> details.s_id;

	//...Check Student duplicate IDs...//

	ifstream check_file("students.txt");
	bool exists = false;
	while (getline(check_file, existing_id)) {
		if (existing_id == details.s_id) {
			exists = true;
			break;
		}

	}
	check_file.close();

	if (exists) {
		cout << "\n Student with ID '" << details.s_id << "' already exists. Please use different Student Id...\n\n";
		cout << "Press Enter to return to menu...";
		cin.ignore();
		cin.get();
		system("cls");
		return;
	}
	//...End of Check Student duplicate IDs...//

	ofstream s_file("students.txt", ios::app);
	cout << endl;

	s_file << details.s_id << endl;

	cout << "Enter Student Name : ";
	cin.ignore();
	getline(cin, details.s_name);//.......for student names with spaces
	s_file << details.s_name << endl;

	cout << "\nEnter Course Name : ";
	getline(cin, details.s_course);//.......for course names with spaces
	s_file << details.s_course << endl;

	s_file << "____________________________" << endl;
	cout << "\nStudent Added Successfully...\n\n";
	cout << "Press 'Enter' Key to come back Main Menu";

	cin.get();
	system("cls");

}
//....................End of Add Student Section...................//

//....................View Student Section...................//
void viewStudent() {
	ifstream s_file("students.txt");
	cout << endl;
	cout << "All Students List\n\n";

	string line;

	while (getline(s_file, line)) {
		cout << "" << line << endl;

	}

	s_file.close();
	cin.ignore();
	cin.get();
	system("cls");

}
//....................End of View Student Section...................//


//.....................Add Course Section....................//

void addCourse() {
	ofstream c_file("courses.txt", ios::app);
	cout << endl;

	string existing_id;
	course details;

	cout << "Enter Course id : ";
	cin >> details.c_id;

	//...Check Courses duplicate IDs...//

	ifstream check_file("courses.txt");
	bool exists = false;
	while (getline(check_file, existing_id)) {
		if (existing_id == details.c_id) {
			exists = true;
			break;
		}

	}
	check_file.close();
	if (exists) {
		cout << "\n Course ID '" << details.c_id << "' already exists. Please use different Course Id...\n\n";
		cout << "Press Enter to return to menu...";
		cin.ignore();
		cin.get();
		system("cls");
		return;
	}
	//...End of Check Courses duplicate IDs...//

	c_file << details.c_id << endl;

	cout << "Enter Course Name : ";
	cin.ignore();
	getline(cin, details.c_name);//.......for courses name with spaces
	c_file << details.c_name << endl;

	cout << "Enter Maximum Capacity : ";
	cin >> details.c_capacity;
	c_file << details.c_capacity << endl;

	c_file << "____________________________" << endl;
	cout << "\nCourse Added Successfully...\n\n";
	cout << "Press 'Enter' Key to come back Main Menu";
	cin.ignore();
	cin.get();
	system("cls");
}
//.....................End of Add Course Section....................//


//.....................View Course Section....................//
void viewCourse() {
	ifstream c_file("courses.txt");
	cout << endl;
	cout << "All Courses List\n\n";
	string line;

	while (getline(c_file, line)) {
		cout << "" << line << endl;
	}

	c_file.close();
	cout << "\nPress 'Enter' Key to come back Main Menu";
	cin.ignore();
	cin.get();
	system("cls");

}
//................End View Courses Section..................//


//.......................Course Enrollment Section..................//

void courseEnrollment() {
	time_t now = time(0);
	tm localdate;
	localtime_s(&localdate, &now);

	string student_name, course_name;
	cout << "\n************* Enroll in Course *************\n";
	cout << "Enter Student Name : ";
	cin >> student_name;
	cout << "Enter Course Name : ";
	cin >> course_name;

	ofstream outfile("enrollment.txt", ios::app);
	if (!outfile) {
		cout << "Error opening file!" << endl;
		return;
	}

	outfile << student_name << "," << course_name << ",ENROLLED,"
		<< (1900 + localdate.tm_year) << "-"
		<< (1 + localdate.tm_mon) << "-"
		<< localdate.tm_mday << endl;

	outfile.close();

	cout << "\nEnrollment Recorded Successfully...\n";
	cout << "Press Enter to return to menu...";
	cin.ignore();
	cin.get();
	system("cls");
}
//...................end of course enrollment section................//


//....................withdraw student from course..............//

void withdrawEnrollment() {

	time_t now = time(0);
	tm localdate;
	localtime_s(&localdate, &now);

	string id, course;
	cout << "\n--------------------- Withdraw Course --------------------------------------------\n";
	cout << endl;
	cout << " Enter Student Name : ";
	cin >> id;
	cout << " Enter Course Name : ";
	cin >> course;

	ofstream outfile("enrollment.txt", ios::app);

	outfile << id << "," << course << ",WITHDRAWN,"
		<< (1900 + localdate.tm_year) << "-"
		<< (1 + localdate.tm_mon) << "-"
		<< localdate.tm_mday << endl;

	outfile.close();

	cout << "\n Withdrawal Recorded Successfully.\n";
	cout << "\n\n";
	cout << "Press Enter to return to menu...";
	cin.ignore();
	cin.get();
	system("cls");
}
//.............end of withdraw student from course.................//



//................Check Course Roaster.................//
void checkCourseRoster() {
	string course;
	cout << "\n___________________________ Course Roster ___________________________\n";
	cout << "Enter Course Name : ";
	cin >> course;

	ifstream infile("enrollment.txt");
	if (!infile) {
		cout << "Error opening enrollment file.\n";
		return;
	}

	vector<string> enrolled;
	vector<string> withdrawn;
	string line;

	while (getline(infile, line)) {
		stringstream ss(line);
		string s_name, c_name, status, date;
		getline(ss, s_name, ',');
		getline(ss, c_name, ',');
		getline(ss, status, ',');
		getline(ss, date);

		if (c_name == course) {
			if (status == "ENROLLED") {
				enrolled.push_back(s_name + " (Enrolled on: " + date + ")");
			}
			else if (status == "WITHDRAWN") {
				withdrawn.push_back(s_name + " (Withdrawn on: " + date + ")");
			}
		}
	}

	infile.close();

	if (enrolled.empty() && withdrawn.empty()) {
		cout << "\nNo enrollment records found for course: " << course << "\n";
	}
	else {
		cout << "------------------------------\n";
		cout << "\n ********Students Enrolled in " << course << " ********\n\n";
		for (string& s : enrolled)
			cout << s << endl;

		cout << "\n********Students Withdrawn from " << course << " ********\n\n";
		for (string& s : withdrawn)
			cout << s << endl;
	}

	cout << "\n________________________________________________________________________________\n";
	cout << "\nPress Enter to return to menu...";
	cin.ignore();
	cin.get();
	system("cls");
}
//................End of Check Course Roaster.................//





