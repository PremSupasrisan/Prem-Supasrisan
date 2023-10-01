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
////////////////////////////// ��С�ȵ������ͧ�ѡ
const int countRooms = 10;
string rooms[countRooms][7] ;
////////////////////////////// ��С�ȵ���ü����Ҿѡ
const int countGuests = 10;
string guests[countGuests][4];
int main()
{
	int menu , Rooms = 1;
	SetupRooms();
	do{
		
		cout << "MENU:" << endl;
        cout << "1. ��ͧ�ѡ" << endl; // ��������ͧ�ѡ
		cout << "2. �����Ҿѡ" << endl; // ��͡�����ż����Ҿѡ �����ͧ����ͧ�����Ҿѡ
        cout << "3. ��ä׹��ͧ�ѡ" << endl; 
        cout << "4. ��§ҹ��ͧ�ѡ" << endl;
		cout << "5. ���Ф����ͧ�ѡ" <<endl;
        cout << "0. �͡�ҡ�����" << endl;
        cout << "�ô���͡: ";
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
		{cout << "��سҡ�͡�����ա����\n";}
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
		//rooms[i][0] = ""; // �������ͧ��ͧ 1 : ���� | 0 : �Ѵ��  
		rooms[i][1] = "empty"; // ʶҹ���ͧ 1 : ��ҧ | 0 : �����ҧ
		rooms[i][2] = "0"; // �Ҥ���ͧ ���� : 2500 | �Ѵ�� : 1500
		rooms[i][3] = "-"; // ����-���ʡ��
		rooms[i][4] = "-"; // idCard
		rooms[i][5] = "-"; // ������
		
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
		guests[i][0] = "";  // ����-���ʡ��
		guests[i][1] = "";  // idCard
		guests[i][2] = "";	// ������
		guests[i][3] = "";	// �����Ţ��ͧ���ѡ
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
	rooms[realRoomNumber][1] = "notempty"; // ��ͧ�����ҧ
	rooms[realRoomNumber][3] = name + " " + surname; // ����-���ʡ��
	rooms[realRoomNumber][4] = idcard; // idCard
	rooms[realRoomNumber][5] = tel; // ������
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
        return; // �͡�ҡ�ѧ��ѹ��������Ţ��ͧ���١��ͧ
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
            cout << "�����Թ��������ó�" << endl;
            
            // ���絢�������ͧ�ѡ���׹
            rooms[realRoomNumber][1] = "empty";
            rooms[realRoomNumber][2] = "0";
            rooms[realRoomNumber][3] = "-";
            rooms[realRoomNumber][4] = "-";
            rooms[realRoomNumber][5] = "-";
        }
        else
        {
            cout << "��ҹ�������ö Checkout �����ͧ�ҡ��ҧ���Ф����ͧ" << endl;
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
