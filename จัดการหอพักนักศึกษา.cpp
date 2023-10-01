#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ��С�ȿѧ��ѹ������������������
void CheckRooms();
void CheckIn();
void CheckOut();
void Report();
void SetupRooms();
void Payment();

const int countRooms = 10; // �ӹǹ��ͧ��������;ѡ
string rooms[countRooms][7]; // ���ҧ�红����Ţͧ��ͧ�ѡ

int main() {
    int menu, Rooms = 1;
    SetupRooms(); // ���¡��ѧ��ѹ SetupRooms() ���͡�˹����������鹢ͧ��ͧ�ѡ

    do {
        cout << "Program Dormitory : \n";
        cout << "1. Checkin" << endl; // �ʴ��������͡��ͧ�ѡ
        cout << "2. Checkroom" << endl; // �ʴ����ٷ����㹡��ŧ����¹�����Ҿѡ
        cout << "3. Payment" << endl; // �ʴ����ٷ����㹡������ҷ�
        cout << "4. Report" << endl; // �ʴ���§ҹ��ͧ�ѡ
        cout << "5. Checkout" << endl; // �ʴ����ٷ����㹡�ê����Թ
        cout << "0. Exit program" << endl; // �ʴ���������Ѻ�͡�ҡ�����
        cout << "Select menu: ";
        cin >> menu;

        // ��Ǩ�ͺ���ٷ���������͡������¡��ѧ��ѹ�������Ǣ�ͧ
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

// �ѧ��ѹ���������ͧ�ѡ
void SetupRooms() {
    for (int i = 0; i < countRooms; i++) {
        if (i < 5) {
            rooms[i][0] = "air"; // ��ͧ����
        } else {
            rooms[i][0] = "fan"; // ��ͧ�Ѵ��
        }

        rooms[i][1] = "Empty"; // ʶҹ���ͧ ��ҧ
        rooms[i][2] = "0"; // �Ҥ���ͧ
        rooms[i][3] = "-"; // ����-���ʡ��
        rooms[i][4] = "-"; // idCard
        rooms[i][5] = "-"; // ������
    }
}

// �ѧ��ѹ������������ͧ�ѡ
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

// �ѧ��ѹŧ����¹�����Ҿѡ
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
    rooms[realRoomNumber][1] = "notEmpty"; // ��ͧ�����ҧ
    rooms[realRoomNumber][3] = name + " " + surname; // ����-���ʡ��
    rooms[realRoomNumber][4] = idcard; // idCard
    rooms[realRoomNumber][5] = tel; // ������
    cout << "--------------------------------" << endl;
}

// �ѧ��ѹ����ҷ�
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
        return; // �͡�ҡ�ѧ��ѹ��������Ţ��ͧ���١��ͧ
    }

    if (rooms[realRoomNumber][1] == "empty") {
        cout << "This Room is empty, can't checkout" << endl;
    } else {
        int roomPrice = (rooms[realRoomNumber][0] == "air") ? 2500 : 1500;

        if (stoi(rooms[realRoomNumber][2]) == roomPrice) {
            cout << "Payment completed successfully." << endl;
            cout << "Checkout Room " << roomNumber << "." << endl;

            // ���絢�������ͧ�ѡ���׹
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

// �ѧ��ѹ���ҧ��§ҹ��ͧ�ѡ
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

// �ѧ��ѹ�Ѻ�����Թ
void Payment() {
    int payroom = 0;
    cout << "--------------------------------" << endl;
    cout << "Payment\n";
    cout << "--------------------------------" << endl;
    cout << "Room number to pay : ";
    cin >> payroom;
    cout << "Payment : ";
    cin >> rooms[payroom - 1][2]; // �Ѻ��Ҩҡ�������кѹ�֡�繡�ê����Թ
    cout << "--------------------------------" << endl;
}

/*void ChangeRoomDetail()
{
	int choice,roomNumber;
	
	cout << "�����Ţ��ͧ����ͧ�������¹������ : " ;
	cin >> roomNumber ; 
	int realRoomNumber = roomNumber - 1 ;
	int roomPrice = (rooms[realRoomNumber][0] == "1")	?	2500 : 1500 ;
	cout << "��ͧ�����Ţ : " << realRoomNumber + 1 << " \t";
	cout <<"��������ͧ : "  <<rooms[realRoomNumber][0] <<"\t"; 
	cout <<"ʶҹ���ͧ : " <<rooms[realRoomNumber][1]<<"\t"; 
	cout <<"�Ҥ���ͧ : "<<roomPrice;
	cout << "���� : " << endl;
    cout << "1. ����¹��������ͧ�ѡ" << endl;
    cout << "2. ����¹ʶҹ���ͧ�ѡ" << endl;
	cin >> choice ;
	if(choice == 1)
	{
		cout << "1. ��ͧ����" << endl;
		cout << "2. ��ͧ�Ѵ��" << endl;
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
		// ʶҹ���ͧ 1 : ��ҧ | 0 : �����ҧ
		cout << "1. ��ҧ" << endl;
		cout << "2. �����ҧ" << endl;
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