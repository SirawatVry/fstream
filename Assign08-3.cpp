#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int Menu();
void add_student(string FN);
void display_student(string FN);
void display_byid(string FN);
void report_grade(string FN);

int main()
{
	const string file_name = "student.dat";
	ifstream in_file;
	ofstream out_file;
	int c;
	do {
		system("cls");
		c = Menu();
		switch (c)
		{
		case 1: add_student(file_name); break;
		case 2: display_student(file_name); break;
		case 3: report_grade(file_name); break;
		case 4: display_byid(file_name); break;
		}
	} while (c != 0);
	cout << "Exit program." << endl;
	return(0);
}

int Menu()
{
	string line(25, '=');
	int choose;
	cout << "Program Add-Display Student Data\n" << line << endl;
	cout << ":      Main Menu              :\n";
	cout << line << endl;
	cout << ":  0 - Exit                   :\n";
	cout << ":  1 - Add Student            :\n";
	cout << ":  2 - Display Student        :\n";
	cout << ":  3 - Report Grade           :\n";
	cout << ":  4 - Display By Id          :\n";
	cout << " Enter choose : ";
	cin >> choose;
	return(choose);
}

void add_student(string FN)
{
	ofstream out_file(FN.c_str(), ios_base::out | ios_base::app);
	if (out_file.is_open())
	{
		string id, name, score;
		cout << "\n Add Student \n";
		cout << "Enter id : ";
		cin >> id;
		cout << "Enter name : ";
		cin >> name;
		cout << "Enter score : ";
		cin >> score;


		out_file << id << " " << name << " " << score << endl;
		out_file.close();
		cout << "\nSaved already.\n";
		system("pause");
	}
	else
		cout << "File could not opened." << endl;
}

void display_student(string FN)
{
	ifstream in_file(FN.c_str(), ios_base::in);
	if (in_file.is_open())
	{
		string id, name, score;
		string line(26, '=');
		int n = 0;
		cout << "\nList Student\n";
		cout << line << endl;
		cout << " No.	ID    Name   Score\n";
		cout << line << endl;
		in_file >> id >> name >> score;
		while (!in_file.eof())
		{
			n = n + 1;
			cout << right << setw(3) << n << " : " << right << setw(3) << id << "   " << left << setw(9) << name << setw(3) << score << endl;
			in_file >> id >> name >> score;
		}
		in_file.close();
		system("pause");
	}
	else
		cout << "File could not opened." << endl;
}

void display_byid(string FN)
{
	string id;
	cout << "Enter id ";
	cin >> id;
	ifstream in_file(FN.c_str(), ios_base::in);
	if (in_file.is_open()) {
		bool found = false;
		string id_in, name_in;
		in_file >> id_in >> name_in;
		if (id == id_in) found = true;
		while (!in_file.eof() && !found) {
			in_file >> id_in >> name_in;
			if (id == id_in) found = true;
		}
		in_file.close();
		if (found)
		{
			cout << "id : " << id << endl;
			cout << "Name : " << name_in << endl;
		}
		else cout << "ID : " << id << " not found.\n";
		system("pause");
	}
}

string calculate_grade(int score) {
	int scoreRanges[] = { 80, 75, 70, 65, 60, 55, 50, 0 };
	string gradeValues[] = { "A", "B+", "B", "C+", "C", "D+", "D", "F" };

	int numRanges = sizeof(scoreRanges) / sizeof(scoreRanges[0]);
	string grade = "F";

	for (int i = 0; i < numRanges; i++) {
		if (score >= scoreRanges[i]) {
			grade = gradeValues[i];
			break;
		}
	}
	return grade;
}


void report_grade(string FN) {
	ifstream in_file(FN.c_str(), ios_base::in);
	if (in_file.is_open()) {
		string id, name, score;
		string line(36, '=');
		int n = 0;
		cout << "\nList Student\n";
		cout << line << endl;
		cout << " No.    ID    Name    Score    Grade\n";
		cout << line << endl;
		in_file >> id >> name >> score;
		while (!in_file.eof()) {
			n = n + 1;
			cout << right << setw(4) << n << " : " << right << setw(5) << id << "   " << left << setw(10) << name << setw(7) << score;

			int scoreValue = stoi(score);
			string grade = calculate_grade(scoreValue);
			                                                                                               
			cout << " " << grade << endl;

			in_file >> id >> name >> score;
		}
		in_file.close();
		system("pause");
	}
	else {
		cout << "File could not be opened." << endl;
	}
}
