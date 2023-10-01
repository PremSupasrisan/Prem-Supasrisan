#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ประกาศฟังก์ชันทั้งหมดที่จะใช้ในโปรแกรม
void CheckRooms();
void CheckIn();
void CheckOut();
void Report();
void SetupRooms();
void Payment();

const int countRooms = 10; // จำนวนห้องทั้งหมดในหอพัก
string rooms[countRooms][7]; // ตารางเก็บข้อมูลของห้องพัก

int main() {
    int menu, Rooms = 1;
    SetupRooms(); // เรียกใช้ฟังก์ชัน SetupRooms() เพื่อกำหนดค่าเริ่มต้นของห้องพัก

    do {
        cout << "Program Dormitory : \n";
        cout << "1. Checkin" << endl; // แสดงเมนูเลือกห้องพัก
        cout << "2. Checkroom" << endl; // แสดงเมนูที่ใช้ในการลงทะเบียนผู้เข้าพัก
        cout << "3. Payment" << endl; // แสดงเมนูที่ใช้ในการเช็คเอาท์
        cout << "4. Report" << endl; // แสดงรายงานห้องพัก
        cout << "5. Checkout" << endl; // แสดงเมนูที่ใช้ในการชำระเงิน
        cout << "0. Exit program" << endl; // แสดงเมนูสำหรับออกจากโปรแกรม
        cout << "Select menu: ";
        cin >> menu;

        // ตรวจสอบเมนูที่ผู้ใช้เลือกและเรียกใช้ฟังก์ชันที่เกี่ยวข้อง
        if (menu == 1) 
		{CheckIn();} 

		else if (menu == 2)
		{CheckRooms();}

		else if (menu == 3)
		{Payment();}

		else if (menu == 4) 
		{cout << endl;
		 Report();	}

		else if (menu == 5) 
		{CheckOut();}

		else if (menu == 0) 
		{break;} 

		else 
		{cout << "Please try again\n";}
        
		cout << endl;

    } while (menu != 0);

    system("pause");
    return 0;
}

// ฟังก์ชันเริ่มต้นห้องพัก
void SetupRooms() {
    for (int i = 0; i < countRooms; i++) {
        if (i < 5) {
            rooms[i][0] = "air"; // ห้องแอร์
        } else {
            rooms[i][0] = "fan"; // ห้องพัดลม
        }

        rooms[i][1] = "Empty"; // สถานะห้อง ว่าง
        rooms[i][2] = "0"; // ราคาห้อง
        rooms[i][3] = "-"; // ชื่อ-นามสกุล
        rooms[i][4] = "-"; // idCard
        rooms[i][5] = "-"; // เบอร์โทร
    }
}

// ฟังก์ชันเพิ่มข้อมูลห้องพัก
void CheckRooms() {
    int roomNumber;
    cout << "--------------------------------" << endl;
    cout << "Select Room : ";
    cin >> roomNumber;
    int realRoomNumber = roomNumber - 1;

    if (realRoomNumber >= 0 && realRoomNumber < countRooms) {
        int roomPrice = (rooms[realRoomNumber][0] == "air") ? 2500 : 1500;

        cout << "Room        : " << roomNumber << " \t" << endl;
        cout << "Type        : " << rooms[realRoomNumber][0] << "\t" << endl;
        cout << "Price       : " << roomPrice << "\t" << endl;
        cout << "Status      : " << rooms[realRoomNumber][1] << "\t" << endl;
        cout << "Name-Surname: " << rooms[realRoomNumber][3] << "\t\n";
        cout << "IDcard      : " << rooms[realRoomNumber][4] << "\t\n";
        cout << "Tel         : " << rooms[realRoomNumber][5] << "\t\n";
        cout << "Payment     : " << stoi(rooms[realRoomNumber][2]) << "\t";
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

// ฟังก์ชันลงทะเบียนผู้เข้าพัก
void CheckIn() {
    int roomNumber = 0;
    string name, surname, idcard, tel;
    cout << "--------------------------------" << endl;
    cout << "Checkin\n";
    cout << "--------------------------------" << endl;
    cout << "Choose Room Number\n";
    cout << "Air(1-5) | Fan(6-10) : ";
    cin >> roomNumber;
    int realRoomNumber = roomNumber - 1;
    cout << "Name    : ";
    cin >> name;
    cout << "Surname : ";
    cin >> surname;
    cout << "IDcard  : ";
    cin >> idcard;
    cout << "Tel     : ";
    cin >> tel;
    rooms[realRoomNumber][1] = "notEmpty"; // ห้องไม่ว่าง
    rooms[realRoomNumber][3] = name + " " + surname; // ชื่อ-นามสกุล
    rooms[realRoomNumber][4] = idcard; // idCard
    rooms[realRoomNumber][5] = tel; // เบอร์โทร
    cout << "--------------------------------" << endl;
}

// ฟังก์ชันเช็คเอาท์
void CheckOut() {
    int roomNumber;
    cout << "--------------------------------" << endl;
    cout << "Checkout\n";
    cout << "--------------------------------" << endl;
    cout << "Room Number Checkout : ";
    cin >> roomNumber;
    int realRoomNumber = roomNumber - 1;

    if (realRoomNumber < 0 || realRoomNumber >= countRooms) {
        cout << "Invalid room number" << endl;
        return; // ออกจากฟังก์ชันถ้าหมายเลขห้องไม่ถูกต้อง
    }

    if (rooms[realRoomNumber][1] == "empty") {
        cout << "This Room is empty, can't checkout" << endl;
    } else {
        int roomPrice = (rooms[realRoomNumber][0] == "air") ? 2500 : 1500;

        if (stoi(rooms[realRoomNumber][2]) == roomPrice) {
            cout << "Payment completed successfully." << endl;
            cout << "Checkout Room " << roomNumber << "." << endl;

            // รีเซ็ตข้อมูลห้องพักที่คืน
            rooms[realRoomNumber][1] = "empty";
            rooms[realRoomNumber][2] = "0";
            rooms[realRoomNumber][3] = "-";
            rooms[realRoomNumber][4] = "-";
            rooms[realRoomNumber][5] = "-";
        } else {
            cout << "You cannot check out because there is an outstanding room charge." << endl;
        }
    }
    cout << "--------------------------------" << endl;
}

// ฟังก์ชันสร้างรายงานห้องพัก
void Report() {
    cout << "Report" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "Room";
    cout << setw(10) << left << "Type";
    cout << setw(12) << left << "Status";
    cout << setw(10) << left << "PRICE";
    cout << setw(20) << left << "Name-Surname";
    cout << setw(18) << left << "IDCard";
    cout << setw(10) << left << "Tel" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < countRooms; i++) {
        int roomPrice = (rooms[i][0] == "air") ? 2500 : 1500;

        cout << setw(10) << left << i + 1;
        cout << setw(10) << left << rooms[i][0];
        cout << setw(12) << left << rooms[i][1];
        cout << setw(10) << left << roomPrice;
        cout << setw(20) << left << rooms[i][3];
        cout << setw(18) << left << rooms[i][4];
        cout << setw(10) << left << rooms[i][5] << endl;
    }

    cout << "------------------------------------------------------------------------------------------" << endl;
}

// ฟังก์ชันรับชำระเงิน
void Payment() {
    int payroom = 0;
    cout << "--------------------------------" << endl;
    cout << "Payment\n";
    cout << "--------------------------------" << endl;
    cout << "Room number to pay : ";
    cin >> payroom;
    cout << "Payment : ";
    cin >> rooms[payroom - 1][2]; // รับค่าจากผู้ใช้และบันทึกเป็นการชำระเงิน
    cout << "--------------------------------" << endl;
}

/*void ChangeRoomDetail()
{
	int choice,roomNumber;
	
	cout << "หมายเลขห้องที่ต้องการเปลี่ยนข้อมูล : " ;
	cin >> roomNumber ; 
	int realRoomNumber = roomNumber - 1 ;
	int roomPrice = (rooms[realRoomNumber][0] == "1")	?	2500 : 1500 ;
	cout << "ห้องหมายเลข : " << realRoomNumber + 1 << " \t";
	cout <<"ประเภทห้อง : "  <<rooms[realRoomNumber][0] <<"\t"; 
	cout <<"สถานะห้อง : " <<rooms[realRoomNumber][1]<<"\t"; 
	cout <<"ราคาห้อง : "<<roomPrice;
	cout << "เมนู : " << endl;
    cout << "1. เปลี่ยนประเภทห้องพัก" << endl;
    cout << "2. เปลี่ยนสถานะห้องพัก" << endl;
	cin >> choice ;
	if(choice == 1)
	{
		cout << "1. ห้องแอร์" << endl;
		cout << "2. ห้องพัดลม" << endl;
		cin >> choice ;
		if(choice == 1)
		{
			rooms[realRoomNumber][0] = "air";
		}
		else if(choice ==2)
		{
			rooms[realRoomNumber][0] = "fan";
		}
	}else if(choice == 2)
	{
		// สถานะห้อง 1 : ว่าง | 0 : ไม่ว่าง
		cout << "1. ว่าง" << endl;
		cout << "2. ไม่ว่าง" << endl;
		cin >> choice ;
		if(choice == 1)
		{	
			rooms[realRoomNumber][1] = "empty";
		}
		else if(choice ==2)
		{
			rooms[realRoomNumber][1] = "notempty";
		}
	}
	system("cls");
}*/