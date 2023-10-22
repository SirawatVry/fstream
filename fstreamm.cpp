#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int Menu();
void AddStudent(string FN);
void DisplayStudent(string FN);
int main()
{
	const string Filename = "student.dat"; // กำหนดชื่อไฟล์ลงในตัวแปรเพื่อสร้างไฟล์ตามชื่อที่ใส่
	ifstream InFile; //ใช้อ่านข้อมูลจากไฟล์
	ofstream OutFile;//ใช้เขียนข้อมูลลงในไฟล์
	int c;
	do {
		system("cls"); //คำสั่งเคลียร์หน้าจอ ใช้ในการทำให้การแสดงดูง่ายใส่ก็ได้
		c = Menu();
		switch(c) //menuแบบปกติ
		{
			case 1 : AddStudent(Filename); break;
			case 2 : DisplayStudent(Filename); break;
		}
	} while(c != 0);
	cout << "Exit program." << endl;
	return(0);
}
int Menu()
{
	string line(25,'=');
	int Choose;
	cout << "Program Add-Display Student Data\n";
	cout << line << endl;
	cout << ": Main Menu :\n";
	cout << line << endl;
	cout << ": 0 - Exit :\n";
	cout << ": 1 - Add Student :\n";
	cout << ": 2 - Display Student :\n";
	cout << line << endl;
	cout << " Enter choose : ";
	cin >> Choose;
	return(Choose);
}
void AddStudent(string FN)
{
//ฟังค์ชั่นเปิดเพื่อเขียนต่อ
	ofstream OutFile/*ประกาศในการจะเขียนข้อมูล*/(FN.c_str()/*แปลงจาก string เป็น char เพื่อให้สามารถเปิดไฟล์โดยตรง*/, ios_base::out | ios_base::app);//ใช้ในการเปิดไฟล์เพื่อเขียนต่อจากที่เขียนไว้
	if (OutFile.is_open()) { //ถ้าเปิดไฟล์ได้
		string Id, Name; //ประกาศรับค่าประเภท string ชื่อ Id Name
		cout << "\n Add Student \n";
		cout << "Enter id : ";
		cin >> Id;
		cout << "Enter name : ";
		cin >> Name;

		OutFile << Id << " " << Name << endl;//เขียนข้อมูลลงไฟล์
		OutFile.close();//ปิดโหมดการเขียน
		char Wait;
		cin.get(Wait);//รอการรับค่า Enter ในการดำเนินการต่อ
		cout << "\nSaved already ,Press Enter to continue";
		cin.get(Wait);
	}
	else cout << "File could not opened." << endl;//ถ้าเปิดไฟล์ไม่ได้
}
void DisplayStudent(string FN)
{
	ifstream InFile(FN.c_str(), ios_base::in); //เปิดไฟล์ในโหมดอ่าน
	if (InFile.is_open()) {//เช็คการเปิดของไฟล์
		string Id, Name;//กำหนดค่า
		string line(30,'=');
		int n = 0;
		cout << "\nList Student\n";
		cout << line << endl;
		cout << " No. Id Name \n";
		cout << line << endl;
// read data from file student.dat
	InFile >> Id >> Name;//อ่านข้อมูล Id และ Name
	while (!InFile.eof()) {  //ลูปในการอ่านข้อมูล Id และ Name จนกว่าข้อมูลจะหมด
		n = n + 1;
		cout << right << setw(3) << n << " : ";
		cout << left << setw(6) << Id;
		cout << " " << Name << endl;
		InFile >> Id >> Name;//อ่านข้อมูลจากไฟล์แล้วนำไปเก็บใส่ตัวแปร Id และ Name
	}
	InFile.close(); //ปิดไฟล์ในโหมดการอ่าน
	char Wait;
	cin.get(Wait);
	cout << "\nPress Enter to continue";
	cin.get(Wait);
	}
	else cout << "File could not opened." << endl;
}
