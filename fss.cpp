#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    ifstream file;

    // รับชื่อไฟล์จากผู้ใช้
    cout << "โปรแกรมอ่านไฟล์แบบ Text File และแสดงบนหน้าจอ 24 บรรทัดต่อครั้ง\n";
    cout << "ป้อนชื่อไฟล์: ";
    cin >> filename;

    // เปิดไฟล์
    file.open(filename);
	//ถ้าไฟล์เปิดไม่ได้
    if (!file.is_open()) {
        cout << "ไม่สามารถเปิดไฟล์ " << filename << " ได้\n";
        return 1;
    }

    string line;
    int linesDisplayed = 0;

    while (getline(file, line)) 
	{
        cout << line << std::endl;
        linesDisplayed++; // นับจำนวนบรรทัด

       if (linesDisplayed == 24) {
    cout << "กด Enter เพื่อดำเนินการต่อ...";
    cin.ignore(); // หรือ cin.get();
    linesDisplayed = 0;
}
    }

    // ปิดไฟล์
    file.close();

    return 0;
}
