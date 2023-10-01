#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void AddRooms();
void AddGuests();
void CheckIn();
void CheckOut();
void Report();
void SetupRooms();
void Payment();
//void ChangeRoomDetail();
////////////////////////////// ประกาศตัวแปรห้องพัก
const int countRooms = 10;
string rooms[countRooms][7] ;
////////////////////////////// ประกาศตัวแปรผู้เข้าพัก
const int countGuests = 10;
string guests[countGuests][4];
int main()
{
	int menu , Rooms = 1;
	SetupRooms();
	do{
		
		cout << "MENU:" << endl;
        cout << "1. ห้องพัก" << endl; // ข้อมูลห้องพัก
		cout << "2. การเข้าพัก" << endl; // กรอกข้อมูลผู้เข้าพัก และห้องที่ต้องการเข้าพัก
        cout << "3. การคืนห้องพัก" << endl; 
        cout << "4. รายงานห้องพัก" << endl;
		cout << "5. ชำระค่าห้องพัก" <<endl;
        cout << "0. ออกจากโปรแกรม" << endl;
        cout << "โปรดเลือก: ";
        cin >> menu;
		if (menu == 1)
		{AddRooms();}
		
		else if (menu == 2)
		{CheckIn();}

		else if (menu == 3)
		{CheckOut();}

		else if (menu == 4)
		{Report();}
		
		else if (menu == 5)
		{Payment();}

		else
		{cout << "กรุณากรอกเมนูอีกครั้ง\n";}
		cout << endl;
		
	}while(menu != 0);

	system("pause");
	return 0;
}


void SetupRooms()
{
	for ( int i = 0 ; i < countRooms ; i++) 
	{
		if (i < 5)
		{
			rooms[i][0] = "air";
		}
		else 
		{
			rooms[i][0] = "fan"; 
		}
		//rooms[i][0] = ""; // ประเภทของห้อง 1 : แอร์ | 0 : พัดลม  
		rooms[i][1] = "empty"; // สถานะห้อง 1 : ว่าง | 0 : ไม่ว่าง
		rooms[i][2] = "0"; // ราคาห้อง แอร์ : 2500 | พัดลม : 1500
		rooms[i][3] = "-"; // ชื่อ-นามสกุล
		rooms[i][4] = "-"; // idCard
		rooms[i][5] = "-"; // เบอร์โทร
		
	}
}

void AddRooms()
{
	int roomNumber;
    cout << "Select Room : ";
    cin >> roomNumber;
    int realRoomNumber = roomNumber - 1;
	 if (realRoomNumber >= 0 && realRoomNumber < countRooms)
    {
        int roomPrice = (rooms[realRoomNumber][0] == "air") ? 2500 : 1500;	
		
		cout << "Room		: " << roomNumber   << " \t"<<endl;
		cout <<"Type		: "  << rooms[realRoomNumber][0] <<"\t"<<endl;
		cout <<"Price		: "<<roomPrice<<"\t"<<endl;
		cout <<"Status		: " << rooms[realRoomNumber][1] <<"\t"<<endl;
		cout <<"Name-Surname	: " << rooms[realRoomNumber][3] <<"\t\n"; 
		cout <<"IDcard		: " << rooms[realRoomNumber][4] <<"\t\n"; 
		cout <<"Tel		: " << rooms[realRoomNumber][5] <<"\t\n"; 
		cout <<"Payment		: "<<stoi(rooms[realRoomNumber][2]) <<"\t";
		cout << endl;
		cout << endl;
	 }
}

void AddGuests()
{
	for ( int i= 1 ; i <= countGuests ; i++) 
	{
		guests[i][0] = "";  // ชื่อ-นามสกุล
		guests[i][1] = "";  // idCard
		guests[i][2] = "";	// เบอร์โทร
		guests[i][3] = "";	// หมายเลขห้องที่พัก
	}
}

void CheckIn()
{
	int roomNumber = 0;
	string name,surname,idcard,tel;
	cout << "CheckIn\n";
	cout << "Choose Room Number\n";
	cout << "Air(1-5) | Fan(6-10) : "; 
	cin >> roomNumber;
	int realRoomNumber = roomNumber -1;
	cout << "Name	: ";
	cin >> name;
	cout << "Surname	: ";
	cin >> surname;
	cout << "IDcard	: ";
	cin >> idcard;
	cout << "Tel	: ";
	cin >> tel;
	rooms[realRoomNumber][1] = "notempty"; // ห้องไม่ว่าง
	rooms[realRoomNumber][3] = name + " " + surname; // ชื่อ-นามสกุล
	rooms[realRoomNumber][4] = idcard; // idCard
	rooms[realRoomNumber][5] = tel; // เบอร์โทร
}


void CheckOut()
{
    int roomNumber;
    cout << "Checkout" << endl;
    cout << "Room Number Checkout : ";
    cin >> roomNumber;
    int realRoomNumber = roomNumber - 1;

    if (realRoomNumber < 0 || realRoomNumber >= countRooms)
    {
        cout << "Invalid room number" << endl;
        return; // ออกจากฟังก์ชันถ้าหมายเลขห้องไม่ถูกต้อง
    }

    if (rooms[realRoomNumber][1] == "empty")
    {
        cout << "This Room is empty, can't checkout" << endl;
    }
    else
    {
        int roomPrice = (rooms[realRoomNumber][0] == "air") ? 2500 : 1500;

        if (stoi(rooms[realRoomNumber][2]) == roomPrice)
        {
            cout << "Checkout Room " << roomNumber << " And Pay " << rooms[realRoomNumber][2] << " Baht " << endl;
            cout << "ชำระเงินเสร็จสมบูรณ์" << endl;
            
            // รีเซ็ตข้อมูลห้องพักที่คืน
            rooms[realRoomNumber][1] = "empty";
            rooms[realRoomNumber][2] = "0";
            rooms[realRoomNumber][3] = "-";
            rooms[realRoomNumber][4] = "-";
            rooms[realRoomNumber][5] = "-";
        }
        else
        {
            cout << "ท่านไม่สามารถ Checkout ได้เนื่องจากค้างชำระค่าห้อง" << endl;
        }
    }
}



void Report()
{
    cout << "Report" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "Room";
    cout << setw(10) << left << "Type";
    cout << setw(10) << left << "Status";
    cout << setw(10) << left << "PRICE";
    cout << setw(20) << left << "Name-Surname";
    cout << setw(18) << left << "IDCard";
    cout << setw(10) << left << "Tel" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < countRooms; i++)
    {
        int roomPrice = (rooms[i][0] == "air") ? 2500 : 1500;

        cout << setw(10) << left << i + 1;
        cout << setw(10) << left << rooms[i][0];
        cout << setw(10) << left << rooms[i][1];
        cout << setw(10) << left << roomPrice;
        cout << setw(20) << left << rooms[i][3];
        cout << setw(18) << left << rooms[i][4];
        cout << setw(10) << left << rooms[i][5] << endl;
    }

    cout << "----------------------------------------------------------------------------------------" << endl;
}

void Payment()
{	
	int payroom = 0;
	cout << "Room number to pay : ";
	cin >> payroom;
	cout << "Payment : ";
	cin >> rooms[payroom-1][2];
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
