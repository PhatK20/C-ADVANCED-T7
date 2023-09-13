/*
 * File Name: StudentManagement.cpp
 * Author: Phat Bui Gia
 * Date: 08/09/2023
 * Description: This source file contains the implementation of the Student class
 * and related functions for a student management system using vectors.
 */

#include "StudentManagement.h"

vector<SinhVien> dataBaseSV;
double SinhVien::idCounter = 1000;

/*
 * Function: enumHocLuc
 * Description: Convert an enum value representing academic achievement to its corresponding string representation.
 * Input:
 *   h - An enum value of type HocLuc representing academic achievement (GIOI, KHA, TB, YEU).
 * Output:
 *   Returns a string representing the academic achievement.
 */
string enumHocLuc(HocLuc h)
{
	string strHocLuc;
	switch (h)
	{
	case GIOI:
		strHocLuc = "Gioi";
		break;
	case KHA:
		strHocLuc = "Kha";
		break;
	case TB:
		strHocLuc = "TB";
		break;
	case YEU:
		strHocLuc = "Yeu";
		break;
	}
	return strHocLuc;
}

/*
 * Function: enumGioiTinh
 * Description: Convert an enum value representing gender to its corresponding string representation.
 * Input:
 *   g - An enum value of type GioiTinh representing gender (NAM or NU).
 * Output:
 *   Returns a string representing the gender.
 */
string enumGioiTinh(GioiTinh g)
{
	string strGioiTinh;
	switch (g)
	{
	case NAM:
		strGioiTinh = "Nam";
		break;
	case NU:
		strGioiTinh = "Nu";
		break;
	}
	return strGioiTinh;
}

/*
 * Class: SinhVien
 * Method: setID
 * Description: Assigns a unique ID to the student object.
 *              This method increments the idCounter and assigns the new value to the student's ID.
 * Input: None
 * Output: None
 */
void SinhVien::setID()
{
	this->id = ++idCounter;
}

/*
 * Class: SinhVien
 * Method: setName
 * Description: Sets the name of the student.
 *              Prompts the user to input the student's name and assigns it to the student object.
 * Input: None (Uses cin for user input)
 * Output: None (Sets the 'name' member variable)
 */
void SinhVien::setName()
{
	string name;
	cout << "Nhap ten: ";
	cin >> name;
	this->name = name;
}

/*
 * Class: SinhVien
 * Method: setAge
 * Description: Sets the age of the student.
 *              Prompts the user to input the student's age and validates it within a reasonable range.
 * Input: None (Uses cin for user input)
 * Output: None (Sets the 'age' member variable)
 */
void SinhVien::setAge()
{
	double age;
	cout << "Nhap tuoi: ";
	cin >> age;
	while (!(age > 10 && age < 100))
	{
		cout << "Tuoi khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap tuoi: ";
		cin >> age;
	}
	this->age = age;
}

/*
 * Class: SinhVien
 * Method: setGioiTinh
 * Description: Sets the gender of the student.
 * Input: None (Uses cin for user input)
 * Output: None (Sets the 'gioiTinh' member variable)
 */
void SinhVien::setGioiTinh()
{
	int gioiTinh;
	cout << "Nhap gioi tinh (0:Nam/1:Nu): ";
	cin >> gioiTinh;
	while (!(gioiTinh == NAM || gioiTinh == NU))
	{
		cout << "Gioi tinh khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap gioi tinh (Nam/Nu): ";
		cin >> gioiTinh;
	}
	this->gioiTinh = enumGioiTinh((GioiTinh)gioiTinh);
}

/*
 * Class: SinhVien
 * Method: setDiemToan
 * Description: Sets the mathematics score of the student.
 *              Prompts the user to input the student's mathematics score and validates the input.
 * Input: None (Uses cin for user input)
 * Output: None (Sets the 'diemToan' member variable)
 */
void SinhVien::setDiemToan()
{
	double diemToan;
	cout << "Nhap diem toan: ";
	cin >> diemToan;
	while (!(diemToan >= 0 && diemToan <= 10))
	{
		cout << "Diem toan khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap diem toan: ";
		cin >> diemToan;
	}
	this->diemToan = diemToan;
}

/*
 * Class: SinhVien
 * Method: setDiemLy
 * Description: Sets the physics score of the student.
 *              Prompts the user to input the student's physics score and validates the input.
 * Input: None (Uses cin for user input)
 * Output: None (Sets the 'diemLy' member variable)
 */
void SinhVien::setDiemLy()
{
	double diemLy;
	cout << "Nhap diem ly: ";
	cin >> diemLy;
	while (!(diemLy >= 0 && diemLy <= 10))
	{
		cout << "Diem ly khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap diem ly: ";
		cin >> diemLy;
	}
	this->diemLy = diemLy;
}

/*
 * Class: SinhVien
 * Method: setDiemHoa
 * Description: Sets the chemistry score of the student.
 *              Prompts the user to input the student's chemistry score and validates the input.
 * Input: None (Uses cin for user input)
 * Output: None (Sets the 'diemHoa' member variable)
 */
void SinhVien::setDiemHoa()
{
	double diemHoa;
	cout << "Nhap diem hoa: ";
	cin >> diemHoa;
	while (!(diemHoa >= 0 && diemHoa <= 10))
	{
		cout << "Diem hoa khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap diem hoa: ";
		cin >> diemHoa;
	}
	this->diemHoa = diemHoa;
}

/*
 * Class: SinhVien
 * Method: setDiemTB
 * Description: Calculates and sets the average score (diemTB) of the student.
 * Input: None
 * Output: None (Sets the 'diemTB' member variable)
 */
void SinhVien::setDiemTB()
{
	this->diemTB = (this->diemToan + this->diemLy + this->diemHoa) / 3;
}

/*
 * Class: SinhVien
 * Method: setHocLuc
 * Description: Determines the academic performance level (hocLuc) of the student.
 * Input: None
 * Output: None (Sets the 'hocLuc' member variable)
 */
void SinhVien::setHocLuc()
{

	int diem;
	if (this->diemTB >= 8)
		diem = GIOI;
	else if (this->diemTB >= 6.5)
		diem = KHA;
	else if (this->diemTB >= 5)
		diem = TB;
	else
		diem = YEU;
	this->hocLuc = enumHocLuc((HocLuc)diem);
}

/*
 * Class: SinhVien
 * Method: getID
 * Description: Get the student's ID.
 * Input: None
 * Output: Returns the ID of the student (double).
 */
double SinhVien::getID()
{
	return this->id;
}

/*
 * Class: SinhVien
 * Method: getName
 * Description: Get the student's name.
 * Input: None
 * Output: Returns the name of the student (string).
 */
string SinhVien::getName()
{
	return this->name;
}

/*
 * Class: SinhVien
 * Method: getAge
 * Description: Get the student's age.
 * Input: None
 * Output: Returns the age of the student (double).
 */
double SinhVien::getAge()
{
	return this->age;
}

/*
 * Class: SinhVien
 * Method: getGioiTinh
 * Description: Get the student's gender.
 * Input: None
 * Output: Returns the gender of the student (string).
 */
string SinhVien::getGioiTinh()
{
	return this->gioiTinh;
}

/*
 * Class: SinhVien
 * Method: getDiemToan
 * Description: Get the student's math score.
 * Input: None
 * Output: Returns the math score of the student (double).
 */
double SinhVien::getDiemToan()
{
	return this->diemToan;
}

/*
 * Class: SinhVien
 * Method: getDiemLy
 * Description: Get the student's physics score.
 * Input: None
 * Output: Returns the physics score of the student (double).
 */
double SinhVien::getDiemLy()
{
	return this->diemLy;
}

/*
 * Class: SinhVien
 * Method: getDiemHoa
 * Description: Get the student's chemistry score.
 * Input: None
 * Output: Returns the chemistry score of the student (double).
 */
double SinhVien::getDiemHoa()
{
	return this->diemHoa;
}

/*
 * Class: SinhVien
 * Method: getDiemTB
 * Description: Get the student's average score.
 * Input: None
 * Output: Returns the average score of the student (double).
 */
double SinhVien::getDiemTB()
{
	return this->diemTB;
}

/*
 * Class: SinhVien
 * Method: getHocLuc
 * Description: Get the student's academic performance level.
 * Input: None
 * Output: Returns the academic performance level of the student (string).
 */
string SinhVien::getHocLuc()
{
	return this->hocLuc;
}

/*
 * Class: HienThi
 * Method: giaoDien()
 * Description: Displays the menu options for the student management system.
 * Input: None
 * Output: None
 */
void HienThi::giaoDien()
{
	cout << "Danh sach cau lenh:" << endl;
	cout << "1. Them sinh vien" << endl;
	cout << "2. Cap nhat thong tin sinh vien theo ID" << endl;
	cout << "3. Xoa sinh vien theo ID" << endl;
	cout << "4. Tim kiem sinh vien bang ten" << endl;
	cout << "5. Sap xep sinh vien theo diem TB" << endl;
	cout << "6. Sap xep sinh vien theo ten" << endl;
	cout << "7. Hien thi danh sach sinh vien" << endl;
	cout << "8. Thoat chuong trinh" << endl;
}

/*
 * Function: tieuDeThongTinSV()
 * Description: Displays the header for the student information table.
 * Input: None
 * Output: None
 */
void tieuDeThongTinSV()
{
	cout << "Thong tin sinh vien: " << endl;
	printf(" ID   |   Ten   | Tuoi | Gioi tinh | Toan  |  Ly   |  Hoa  |  TB   | Hoc luc\n");
	printf("----------------------------------------------------------------------------\n");
}

/*
 * Function: hienThiThongTinSV(SinhVien sv)
 * Description: Displays the information of a student in a formatted table row.
 * Input:
 *   sv - A SinhVien object containing the student's information
 * Output: None
 */
void hienThiThongTinSV(SinhVien sv)
{
	printf(" %.0lf | %-7s | %-4.0lf |    %-6s | %-5.2lf | %-5.2lf | %-5.2lf | %-5.2lf | %s\n",
		   sv.getID(), sv.getName().c_str(), sv.getAge(),
		   sv.getGioiTinh().c_str(), sv.getDiemToan(),
		   sv.getDiemLy(), sv.getDiemHoa(),
		   sv.getDiemTB(), sv.getHocLuc().c_str());
}

/*
 * Class: HienThi
 * Method: themSV()
 * Description: Adds a new student to the database with user-entered information.
 * Input: None (User inputs student information through prompts)
 * Output: None (Displays success message and student information)
 */
void HienThi::themSV()
{
	SinhVien sv;
	cout << "Nhap thong tin sinh vien: " << endl;
	sv.setID();
	sv.setName();
	sv.setAge();
	sv.setGioiTinh();
	sv.setDiemToan();
	sv.setDiemLy();
	sv.setDiemHoa();
	sv.setDiemTB();
	sv.setHocLuc();
	dataBaseSV.push_back(sv);
	cout << endl;
	cout << "Them sinh vien thanh cong." << endl;
	tieuDeThongTinSV();
	hienThiThongTinSV(sv);

	cout << endl;
	cout << "0. Quay lai" << endl;
	cout << "1. Them sinh vien tiep" << endl;
	cout << "Nhap lua chon: ";
	int key;
	cin >> key;
	if (key == 1)
		themSV();
	else
		return;
}

/*
 * Class: HienThi
 * Method: capNhatSV()
 * Description: Update student information based on user input.
 * Input: None (User inputs student ID and information through prompts)
 * Output: None (Displays success messages and updated student information)
 */
void HienThi::capNhatSV()
{
	int id;
	cout << "Nhap ID can cap nhat: ";
	cin >> id;
	if (!dataBaseSV.empty())
	{
		for (int i = 0; i < dataBaseSV.size(); i++)
		{
			if (dataBaseSV[i].getID() == id)
			{
			thongTinCapNhat:
				cout << "Thong tin sinh vien muon cap nhat" << endl;
				cout << "0. Quay lai" << endl;
				cout << "1. Cap nhat ten" << endl;
				cout << "2. Cap nhat tuoi" << endl;
				cout << "3. Cap nhat gioi tinh" << endl;
				cout << "4. Cap nhat diem" << endl;

			capNhatSV:
				int key;
				cout << "Nhap lua chon: ";
				cin >> key;

				switch (key)
				{
				case 0:
					return;
				case 1:
					dataBaseSV[i].setName();
					cout << "Nhap ten moi thanh cong." << endl;
					break;
				case 2:
					dataBaseSV[i].setAge();
					cout << "Nhap tuoi moi thanh cong." << endl;
					break;
				case 3:
					dataBaseSV[i].setGioiTinh();
					cout << "Nhap gioi tinh moi thanh cong." << endl;
					break;
				case 4:
					cout << "Chon diem can cap nhat: " << endl;
					cout << "0. Quay lai" << endl;
					cout << "1. Toan" << endl;
					cout << "2. Ly" << endl;
					cout << "3. Hoa" << endl;
				capNhatDiem:
					int keyDiem;
					cout << "Nhap lua chon: ";
					cin >> keyDiem;
					switch (keyDiem)
					{
					case 0:
						goto thongTinCapNhat;
					case 1:
						dataBaseSV[i].setDiemToan();
						cout << "Nhap diem toan moi thanh cong." << endl;
						break;
					case 2:
						dataBaseSV[i].setDiemLy();
						cout << "Nhap diem ly moi thanh cong." << endl;
						break;
					case 3:
						dataBaseSV[i].setDiemHoa();
						cout << "Nhap diem hoa moi thanh cong." << endl;
						break;
					default:
						cout << "Lua chon khong hop le." << endl;
						goto capNhatDiem;
					}
					break;
				default:
					cout << "Lua chon khong hop le." << endl;
					goto capNhatSV;
				}
				cout << endl;
				tieuDeThongTinSV();
				hienThiThongTinSV(dataBaseSV[i]);
				cout << endl;
				int luaChon;
				cout << "0. Quay lai" << endl;
				cout << "1. Tiep tuc cap nhat" << endl;
				cout << "Nhap lua chon: ";
				cin >> luaChon;
				cout << endl;
				if (luaChon == 1)
					goto thongTinCapNhat;
				else
					return;
			}
		}
	}
	else
	{
		cout << "ID khong ton tai." << endl;
		cout << endl;
	}
}

/*
 * Class: HienThi
 * Method: xoaSV()
 * Description: Delete a student from the database based on user input.
 * Input:
 *   None (User inputs student ID through prompts)
 * Output:
 *   None (Displays student information, confirmation prompts, and success messages)
 */
void HienThi::xoaSV()
{
	int id;
	cout << "Nhap ID can xoa: ";
	cin >> id;
	if (!dataBaseSV.empty())
	{
		for (int i = 0; i < dataBaseSV.size(); i++)
		{
			if (dataBaseSV[i].getID() == id)
			{
				tieuDeThongTinSV();
				hienThiThongTinSV(dataBaseSV[i]);
				cout << endl;
				int key;
				cout << "0. Quay lai" << endl;
				cout << "1. Chac chan xoa" << endl;
				cout << "Nhap lua chon: ";
				cin >> key;
				if (key == 1)
				{
					dataBaseSV.erase(dataBaseSV.begin() + i);
					cout << "Xoa sinh vien thanh cong." << endl;
					cout << "0. Quay lai" << endl;
					cout << "1. Tiep tuc xoa" << endl;
					cout << "Nhap lua chon: ";
					cin >> key;
					if (key == 1)
						xoaSV();
					else
						return;
				}
				else
					return;
			}
		}
	}
	else
	{
		cout << "ID khong ton tai." << endl;
		cout << endl;
	}
}

/*
 * Class: HienThi
 * Method: timKiemSV()
 * Description: Search for a student by name in the database and display their information if found.
 * Input:
 *   None (User inputs student name through prompts)
 * Output:
 *   None (Displays student information, confirmation prompts, and success/failure messages)
 */
void HienThi::timKiemSV()
{
	string tenSV;
	cout << "Nhap ten sinh vien can tim: ";
	cin >> tenSV;
	for (int i = 0; i < dataBaseSV.size(); i++)
	{
		if (dataBaseSV[i].getName() == tenSV)
		{
			tieuDeThongTinSV();
			hienThiThongTinSV(dataBaseSV[i]);
			cout << endl;
			int key;
			cout << "0. Quay lai" << endl;
			cout << "1. Tiep tuc tim kiem" << endl;
			cout << "Nhap lua chon: ";
			cin >> key;
			if (key == 1)
				timKiemSV();
			else
				return;
		}
	}
	cout << "Ten sinh vien khong ton tai." << endl;
	cout << endl;
}

/*
 * Class: HienThi
 * Method: sapXepSVTheoDiemTB()
 * Description: Sorts the list of students in ascending order of their average scores (diemTB).
 * Input:
 *   None
 * Output:
 *   None (Displays success or error messages)
 */
void HienThi::sapXepSVTheoDiemTB()
{
	if (!dataBaseSV.empty())
	{
		int i, j, minIndex;
		for (i = 0; i < dataBaseSV.size() - 1; i++)
		{
			minIndex = i;
			for (j = i + 1; j < dataBaseSV.size(); j++)
			{
				if (dataBaseSV[j].getDiemTB() < dataBaseSV[minIndex].getDiemTB())
					minIndex = j;
			}
			SinhVien temp = dataBaseSV[minIndex];
			dataBaseSV[minIndex] = dataBaseSV[i];
			dataBaseSV[i] = temp;
		}
		cout << "Sap Xep theo diem TB thanh cong." << endl;
		cout << endl;
	}
	else
	{
		cout << "Danh sach rong." << endl;
		cout << endl;
	}
}

/*
 * Class: HienThi
 * Method: sapXepSVTheoTen()
 * Description: Sorts the list of students in ascending order of their names.
 * Input:
 *   None
 * Output:
 *   None (Displays success or error messages)
 */
void HienThi::sapXepSVTheoTen()
{
	if (!dataBaseSV.empty())
	{
		int i, j, minIndex;
		for (i = 0; i < dataBaseSV.size() - 1; i++)
		{
			minIndex = i;
			for (j = i + 1; j < dataBaseSV.size(); j++)
			{
				if (dataBaseSV[j].getName() < dataBaseSV[minIndex].getName())
					minIndex = j;
			}
			SinhVien temp = dataBaseSV[minIndex];
			dataBaseSV[minIndex] = dataBaseSV[i];
			dataBaseSV[i] = temp;
		}
		cout << "Sap xep theo ten thanh cong." << endl;
		cout << endl;
	}
	else
	{
		cout << "Danh sach rong." << endl;
		cout << endl;
	}
}

/*
 * Class: HienThi
 * Method: danhSachSV()
 * Description: Displays the list of students and their information if the list is not empty.
 *              Otherwise, it displays a message indicating an empty list.
 * Input:
 *   None
 * Output:
 *   None
 */
void HienThi::danhSachSV()
{
	if (!dataBaseSV.empty())
	{
		tieuDeThongTinSV();
		for (int i = 0; i < dataBaseSV.size(); i++)
		{
			hienThiThongTinSV(dataBaseSV[i]);
		}
	}
	else
		cout << "Danh sach rong." << endl;
}
