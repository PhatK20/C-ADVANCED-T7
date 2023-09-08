/*
* File Name: StudentClass_Vector.cpp
* Author: Phat Bui Gia
* Date: 08/09/2023
* Description: student management system using vector
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum
{
	GIOI,
	KHA,
	TB,
	YEU
} HocLuc;

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

typedef enum
{
	NAM,
	NU
} GioiTinh;

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
class SinhVien
{
private:
	static double idCounter;
	double id;
	string name;
	double age;
	string gioiTinh;
	double diemToan;
	double diemLy;
	double diemHoa;
	double diemTB;
	string hocLuc;

public:
	void setID();
	void setName();
	void setAge();
	void setGioiTinh();
	void setDiemToan();
	void setDiemLy();
	void setDiemHoa();
	void setDiemTB();
	void setHocLuc();

	double getID();
	string getName();
	double getAge();
	string getGioiTinh();
	double getDiemToan();
	double getDiemLy();
	double getDiemHoa();
	double getDiemTB();
	string getHocLuc();
};

double SinhVien::idCounter = 1000;

void SinhVien::setID()
{
	this->id = idCounter++;
}
void SinhVien::setName()
{
	string name;
	cout << "Nhap ten: ";
	cin >> name;
	this->name = name;
}

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

void SinhVien::setDiemTB()
{
	this->diemTB = (this->diemToan + this->diemLy + this->diemHoa) / 3;
}

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
double SinhVien::getID()
{
	return this->id;
}

string SinhVien::getName()
{
	return this->name;
}

double SinhVien::getAge()
{
	return this->age;
}

string SinhVien::getGioiTinh()
{
	return this->gioiTinh;
}

double SinhVien::getDiemToan()
{
	return this->diemToan;
}

double SinhVien::getDiemLy()
{
	return this->diemLy;
}

double SinhVien::getDiemHoa()
{
	return this->diemHoa;
}

double SinhVien::getDiemTB()
{
	return this->diemTB;
}

string SinhVien::getHocLuc()
{
	return this->hocLuc;
}

vector<SinhVien> dataBaseSV;

class HienThi
{
private:
public:
	void giaoDien();
	void themSV();
	void capNhatSV();
	void xoaSV();
	void timKiemSV();
	void sapXepSVTheoDiemTB();
	void sapXepSVTheoTen();
	void danhSachSV();
};

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

void hienThiThongTinSV(SinhVien sv)
{
	cout << "Thong tin sinh vien: " << endl;
	cout << "Name: " << sv.getName() << endl;
	cout << "Age: " << sv.getAge() << endl;
	cout << "Gioi tinh: " << sv.getGioiTinh() << endl;
	cout << "Diem toan: " << sv.getDiemToan() << endl;
	cout << "Diem ly: " << sv.getDiemLy() << endl;
	cout << "Diem hoa: " << sv.getDiemHoa() << endl;
	cout << "Diem TB: " << sv.getDiemTB() << endl;
	cout << "Hoc luc: " << sv.getHocLuc() << endl;
}
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

void HienThi::capNhatSV()
{
	int id;
	cout << "Nhap ID can cap nhat: ";
	cin >> id;
	if (!dataBaseSV.empty() && id >= dataBaseSV.front().getID() && id <= dataBaseSV.back().getID())
	{
		for (int i = 0; i < dataBaseSV.size(); i++)
		{
			if (dataBaseSV[i].getID() == id)
			{
				cout << "Thong tin sinh vien muon cap nhat" << endl;
				cout << "0. Quay lai" << endl;
				cout << "1. Cap nhat ten" << endl;
				cout << "2. Cap nhat tuoi" << endl;
				cout << "3. Cap nhat gioi tinh" << endl;
				cout << "4. Cap nhat diem toan" << endl;
				cout << "5. Cap nhat diem ly" << endl;
				cout << "6. Cap nhat diem hoa" << endl;

				int key;
			capNhatSV:
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
					dataBaseSV[i].setDiemToan();
					cout << "Nhap diem toan moi thanh cong." << endl;
					break;
				case 5:
					dataBaseSV[i].setDiemLy();
					cout << "Nhap diem ly moi thanh cong." << endl;
					break;
				case 6:
					dataBaseSV[i].setDiemHoa();
					cout << "Nhap diem hoa moi thanh cong." << endl;
					break;
				default:
					cout << "Lua chon khong hop le." << endl;
					goto capNhatSV;
				}
				cout << endl;
				hienThiThongTinSV(dataBaseSV[i]);
				int luaChon;
				cout << "0. Quay lai" << endl;
				cout << "1. Tiep tuc cap nhat" << endl;
				cout << "Nhap lua chon: ";
				cin >> luaChon;
				if (luaChon == 1)
					goto capNhatSV;
				else
					return;
			}
		}
	}
	else
	{
		cout << "ID khong ton tai." << endl;
	}
}

void HienThi::xoaSV()
{
	int id;
	cout << "Nhap ID can xoa: ";
	cin >> id;
	if (!dataBaseSV.empty() && id >= dataBaseSV.front().getID() && id <= dataBaseSV.back().getID())
	{
		for (int i = 0; i < dataBaseSV.size(); i++)
		{
			if (dataBaseSV[i].getID() == id)
			{
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
	}
}

void HienThi::timKiemSV()
{
	string tenSV;
	cout << "Nhap ten sinh vien can tim: ";
	cin >> tenSV;
	for (int i = 0; i < dataBaseSV.size(); i++)
	{
		if (dataBaseSV[i].getName() == tenSV)
		{
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
}

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
	}
	else
		cout << "Danh sach rong." << endl;
}

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
	}
	else
		cout << "Danh sach rong." << endl;
}

void HienThi::danhSachSV()
{
	if (!dataBaseSV.empty())
	{
		printf(" ID   |   Ten   | Tuoi | Gioi tinh | Toan  |  Ly   |  Hoa  |  TB   | Hoc luc\n");
		printf("-------------------------------------------------------------\n");
		for (int i = 0; i < dataBaseSV.size(); i++)
		{
			SinhVien sv = dataBaseSV[i];
			printf(" %.0lf | %-7s | %-4.0lf |    %-6s | %-5.2lf | %-5.2lf | %-5.2lf | %-5.2lf | %s\n",
				   dataBaseSV[i].getID(), dataBaseSV[i].getName().c_str(), dataBaseSV[i].getAge(),
				   dataBaseSV[i].getGioiTinh().c_str(), dataBaseSV[i].getDiemToan(),
				   dataBaseSV[i].getDiemLy(), dataBaseSV[i].getDiemHoa(),
				   dataBaseSV[i].getDiemTB(), dataBaseSV[i].getHocLuc().c_str());

			cout << endl;
		}
	}
	else
		cout << "Danh sach rong." << endl;
}
int main()
{
	HienThi menu;
	bool exitProgram = false;

	while (!exitProgram)
	{
		cout << "/*******************************************/" << endl;
		menu.giaoDien();
		int luaChon;
	luaChon:
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			menu.themSV();
			break;
		case 2:
			menu.capNhatSV();
			break;
		case 3:
			menu.xoaSV();
			break;
		case 4:
			menu.timKiemSV();
			break;
		case 5:
			menu.sapXepSVTheoDiemTB();
			break;
		case 6:
			menu.sapXepSVTheoTen();
			break;
		case 7:
			menu.danhSachSV();
			break;
		case 8:
			exitProgram = true;
			break;
		default:
			cout << "Lua chon khong hop le." << endl;
			goto luaChon;
		}
	}
	return 0;
}