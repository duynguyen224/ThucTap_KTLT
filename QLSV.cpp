#include "QLSV.h"
#include "SapXep.h"
#include "TimKiem.h"
#include "ThongKe.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ===== danh sach =====
void khoiTaoDanhSach(list &l){
	l.pHead = NULL;
	l.pTail = NULL;
}
bool isEmpty(list l){
	if (l.pHead == NULL && l.pTail == NULL)
		return true;
	else return false;
}
node* khoiTaoNode(SinhVien sv){
	node* p = new node;
	if (p==NULL){
		cout << "Cap phat khong thanh cong ...";
		return NULL;
	}
	p->data = sv;
	p->pNext = NULL;
	return p;
}
void themCuoi(list &l, node* p){
	if (isEmpty(l) == true)
		l.pHead = l.pTail = p;
	else{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void xoaNode(list &l, node* n){
	if (l.pHead->data.MSV == n->data.MSV){ // n la node dau
		node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete(p);
		return;
	}
	else if (l.pTail->data.MSV == n->data.MSV){ // n la node cuoi
		node* p =l.pTail;
		for (node* k =l.pHead; k!= NULL; k=k->pNext){
			if (k->pNext->pNext == NULL){
				k->pNext = NULL;
				l.pTail = k;
				delete(p);
				break;
			}
		}
	}
	else{
		for (node* k=l.pHead; k!=NULL; k=k->pNext){
			if (k->pNext->data.MSV == n->data.MSV){
				node* temp = n;
				k->pNext = k->pNext->pNext;
				n->pNext = NULL;
				delete(temp);
				break;
			}
		}
	}
}


// ===== yeu cau de bai =====
void nhapThongTin(list &l){
	SinhVien sv;
	cin.ignore(); // xoa bo nho dem, tranh mac loi khi nhap.
	while (1){
		cout << "Nhap ma lop: "; getline(cin, sv.maLop);
		if (sv.maLop.length() != 3)
			cout << "Ma lop phai gom 3 ky tu\n";
		else break;
	}

	NhapMSV:
	while (1){
		cout << "Nhap ma sinh vien: "; getline(cin, sv.MSV);
		for (node* p =l.pHead; p!=NULL; p=p->pNext){
			if (sv.MSV == p->data.MSV){
				cout << "Ma sinh vien bi trung...\n";
				goto NhapMSV;
			}
		}
		if (sv.MSV.length() != 8)
			cout << "Ma sinh vien phai gom 8 ky tu...\n";
		else break;
	}

	while (1){
		string hoTenFake;
		cout << "Nhap ho ten: "; getline(cin, hoTenFake); 
		if (haveNumber(hoTenFake) == true){
			cout << "Ho ten khong hop le...\n";
		}
		else{
			sv.hoTen = hoTenFake;
			break;
		}
	}
	/*cout << "Nhap ho: "; getline(cin, sv.ho);
	sv.ho = sv.ho + " ";
	cout << "Nhap ten dem: "; getline(cin, sv.dem);
	sv.dem = sv.dem + " ";
	cout << "Nhap ten: "; getline(cin, sv.ten);
	sv.hoTen = sv.ho + sv.dem + sv.ten;*/

	while(1){
		//cout << "Nhap ngay thang nam sinh... ";
		//cout << "\n   Ngay sinh: "; cin >> sv.date.ngay;
        //cout << "   Thang sinh: "; cin >> sv.date.thang;
		//cout << "   Nam sinh: "; cin >> sv.date.nam;
		//if (kiemTraNgayThangNam(sv.date.ngay, sv.date.thang, sv.date.nam) == false)
			//cout << "Ngay thang nam khong hop le...\n";
		//else break;
		string d, m, y;
		cout << "Nhap ngay thang nam sinh...";
		cout << "\n   ngay sinh: "; getline(cin, d);
		cout << "   thang sinh: "; getline(cin, m);
		cout << "   nam sinh: "; getline(cin, y);
		int dayy, monthh, yearr;
		dayy = (int)::atof(d.c_str());
		monthh = (int)::atof(m.c_str());
		yearr = (int)::atof(y.c_str());
		if (dayy > 0 && monthh > 0 && yearr > 0 ){
			sv.date.ngay = dayy;
			sv.date.thang = monthh;
			sv.date.nam = yearr;
		}
		if (kiemTraNgayThangNam(sv.date.ngay, sv.date.thang, sv.date.nam) == false 
			|| haveString(d) == true || haveString(m) == true || haveString(y) == true)
			cout << "ngay thang nam khong hop le...\n";
		else break;
	}
	//cin.ignore();
	diemtb:
	while(1){
		// tạo 1 string khác để lưu điểm lúc nhập
		// convert nó sang float
		// nếu convert được thì kiểm tra xem trong khoảng 0, 10 không
		// nếu đúng thì lưu nó vào Điểm chính thức.
		string diem;
		cout << "Nhap diem trung binh: "; getline(cin, diem);
		if (haveString(diem) == true){
			cout << "Diem trung binh khong hop le...\n";
			goto diemtb;
		}
		float temp = ::atof(diem.c_str());
		if (temp >0 && temp <=10){
			sv.diemTB = temp;
			break;
		}
		if (sv.diemTB<0 || sv.diemTB>10 || haveString(diem) == true ){
			cout<< "Diem trung binh khong hop le...\n";
		}
	}

	node* p = khoiTaoNode(sv);
	
	// tach ten
	string s = p->data.hoTen;
	string delimiter = " ";
	size_t pos = 0;
	string token;
	int dem = 1;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);

		if (dem == 1){
			p->data.ho = token;
			p->data.ho = p->data.ho + " ";
			dem ++;
		}
		else if (dem == 2){
			p->data.dem = token;
			p->data.dem = p->data.dem + " ";
		}
			s.erase(0, pos + delimiter.length());
	}
	p->data.ten = s;

	// them vao danh sach
	themCuoi(l,p);
	
}
void inDanhSach(list &l){
	// chuan hoa Ho ten, Ma lop truoc khi in.
	for (node*p = l.pHead; p!=NULL; p=p->pNext){
		chuanHoaTen(&(p->data.hoTen));
		chuanHoaMaLop(&(p->data.maLop));
	}
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		if(p->data.maLop.length() == 4){
			p->data.maLop.erase(0,1);
		}
	}

	cout << endl;
	cout << "_________________________________________________________________\n\n";
    cout << setw(7) << left << "MALOP"
		 << setw(12) << left << "MSV" 
		 << setw(20) << left << "HO VA TEN" << "\t"
		 << setw(12) << left << "NGAY SINH"<< "\t"
		 << setw(8) << left << "DIEM TB" << endl;
	cout << "_________________________________________________________________\n\n";
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		cout << setw(7) << left << p->data.maLop
			 << setw(12) << left << p->data.MSV
			 << setw(20) << left << p->data.hoTen << "\t"
			 << setw(2) << left << p->data.date.ngay << "/" 
			 << setw(2) << left << p->data.date.thang << "/" 
			 << setw(8) << left << p->data.date.nam << "\t"
			 << setw(8) << left << p->data.diemTB << endl;
	}
	cout << "_________________________________________________________________\n\n";
}


// ===== sua ho so =====
void suaHoSo(list &l){
	inDanhSach(l);
	cin.ignore();
	string strMsv;
	cout << "Nhap ma sinh vien muon sua ho so: ";
	getline(cin, strMsv);
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		if (strMsv == p->data.MSV){
			cout << "\n  1. Sua ma lop";
			cout << "\n  2. Sua ma sinh vien";
			cout << "\n  3. Sua ho ten";
			cout << "\n  4. Sua ngay sinh";
			cout << "\n  5. Sua diem trung binh";
			cout << "\n  6. Thoat";
			while (1){
				int chon;
				cout << "\nNhap vao lua chon: ";
				cin >> chon;
				if (chon == 1){
					system("cls");
					menu6();
					TextColor(10);
					cout << "\n  1. Sua ma lop";
					TextColor(7);
					cout << "\n  2. Sua ma sinh vien";
					cout << "\n  3. Sua ho ten";
					cout << "\n  4. Sua ngay sinh";
					cout << "\n  5. Sua diem trung binh";
					cout << "\n  6. Thoat";
					while (1){
						cin.ignore();
						cout << "\nNhap ma lop moi: "; getline(cin, p->data.maLop);
						if (p->data.maLop.length() != 3)
							cout << "Ma lop phai gom 3 ky tu\n";
						else break;
					}
				}
				else if (chon ==2){
					system("cls");
					menu6();
					cout << "\n  1. Sua ma lop";
					TextColor(10);
					cout << "\n  2. Sua ma sinh vien";
					TextColor(7);
					cout << "\n  3. Sua ho ten";
					cout << "\n  4. Sua ngay sinh";
					cout << "\n  5. Sua diem trung binh";
					cout << "\n  6. Thoat";
					cin.ignore();
					NhapMSVmoi:
					while (1){
						string s;
						cout << "\nNhap ma sinh vien moi: "; getline(cin, s);
						for (node* q =l.pHead; q!=NULL; q=q->pNext){
							if (s == q->data.MSV){
								cout << "Ma sinh vien bi trung...\n";
								goto NhapMSVmoi;
							}
						}
						if (s.length() != 8)
							cout << "Ma sinh vien phai gom 8 ky tu...\n";
						else{
							p->data.MSV = s;
							break;
						}
					}
				}
				else if (chon ==3){
					system("cls");
					menu6();
					cout << "\n  1. Sua ma lop";
					cout << "\n  2. Sua ma sinh vien";
					TextColor(10);
					cout << "\n  3. Sua ho ten";
					TextColor(7);
					cout << "\n  4. Sua ngay sinh";
					cout << "\n  5. Sua diem trung binh";
					cout << "\n  6. Thoat";
					cin.ignore();
					while (1){
						string hoTenFake;
						cout << "\nNhap ho ten: "; getline(cin, hoTenFake); 
						if (haveNumber(hoTenFake) == true){
							cout << "Ho ten khong hop le...\n";
						}
						else{
							p->data.hoTen = hoTenFake;

							break;
						}
					}
					// tach ten
					string s = p->data.hoTen;
					string delimiter = " ";
					size_t pos = 0;
					string token;
					int dem = 1;
					while ((pos = s.find(delimiter)) != std::string::npos) {
						token = s.substr(0, pos);

						if (dem == 1){
							p->data.ho = token;
							p->data.ho = p->data.ho + " ";
							dem ++;
						}
						else if (dem == 2){
							p->data.dem = token;
							p->data.dem = p->data.dem + " ";
						}
							s.erase(0, pos + delimiter.length());
					}
					p->data.ten = s;
				}
				else if (chon ==4){
					system("cls");
					menu6();
					cout << "\n  1. Sua ma lop";
					cout << "\n  2. Sua ma sinh vien";
					cout << "\n  3. Sua ho ten";
					TextColor(10);
					cout << "\n  4. Sua ngay sinh";
					TextColor(7);
					cout << "\n  5. Sua diem trung binh";
					cout << "\n  6. Thoat";
					cin.ignore();
					while(1){
						string d, m, y;
						cout << "\nNhap ngay thang nam sinh...";
						cout << "\n   ngay sinh: "; getline(cin, d);
						cout << "   thang sinh: "; getline(cin, m);
						cout << "   nam sinh: "; getline(cin, y);
						int dayy, monthh, yearr;
						dayy = (int)::atof(d.c_str());
						monthh = (int)::atof(m.c_str());
						yearr = (int)::atof(y.c_str());
						if (dayy > 0 && monthh > 0 && yearr > 0 ){
							p->data.date.ngay = dayy;
							p->data.date.thang = monthh;
							p->data.date.nam = yearr;
						}
						if (kiemTraNgayThangNam(p->data.date.ngay, p->data.date.thang, p->data.date.nam) == false 
							|| haveString(d) == true || haveString(m) == true || haveString(y) == true)
							cout << "ngay thang nam khong hop le...\n";
						else break;
					}
				}
				else if (chon ==5){
					system("cls");
					menu6();
					cout << "\n  1. Sua ma lop";
					cout << "\n  2. Sua ma sinh vien";
					cout << "\n  3. Sua ho ten";
					cout << "\n  4. Sua ngay sinh";
					TextColor(10);
					cout << "\n  5. Sua diem trung binh";
					TextColor(7);
					cout << "\n  6. Thoat";
					cin.ignore();
					diemtb:
					while(1){
						string diem;
						cout << "\nNhap diem trung binh: "; getline(cin, diem);
						if (haveString(diem) == true){
							cout << "Diem trung binh khong hop le...\n";
							goto diemtb;
						}
						float temp = ::atof(diem.c_str());
						if (temp >0 && temp <=10){
							p->data.diemTB = temp;
							break;
						}
						if (p->data.diemTB<0 || p->data.diemTB>10 || haveString(diem) == true ){
							cout<< "Diem trung binh khong hop le...\n";
						}
					}
				}
				else if (chon ==6){
					break;
				}

			}
		}
	}
}

// ===== xoa ho so =====
void xoa(list &l){
	inDanhSach(l);
	cin.ignore();
	string strMsv;
	cout << "Nhap ma sinh vien muon xoa khoi danh sach: ";
	getline(cin, strMsv);
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		if (strMsv == p->data.MSV){ // xoa node p di
			xoaNode(l, p);
			break;
		}
	}
}

// ===== chuan hoa, kiem tra, mau sac =====
void TextColor(int color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	int wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void chuanHoaTen(string *s){
	while(s->at(0)==' ')
		s->erase(0, 1);
	while(s->at(s->length()-1)==' '||s->at(s->length()-1)<65 ||
		  s->at(s->length()-1)>122 )
		s->erase(s->length()-1, 1);
	for (int i=0; i<s->length()-1; i++){
		if (s->at(i)==s->at(i+1) ||s->at(i)<65 && s->at(i)!=32 ||s->at(i)>122 && s->at(i)!=32){
			s->erase(i, 1);
			i--;
		}
	}
	for (int i=0; i<s->length()-1; i++){
		if(s->at(i)>=65 && s->at(i)<=90)
			s->at(i) = s->at(i) + 32;
	}
	for (int i=1; i<s->length()-1; i++){
		if(s->at(i)==' '){
			s->at(i+1) = s->at(i+1) - 32;
		}
	}
	s->at(0) = s->at(0) - 32;
	if (s->size()==0)
		s = s + ' ';
} 
void chuanHoaMaLop(string *s){
	for(int i=0; i<=s->length()-1; i++){
		if (s->at(i)>=97 && s->at(i)<=122)
			s->at(i) = s->at(i) - 32;
	}
}
bool namNhuan(int nam){
	return ( ((nam%4==0) && (nam%100!=0))|| (nam%400==0) );
}
bool kiemTraNgayThangNam(int ngay, int thang, int nam){
	if (nam<0 || nam>2021)
		return false;
	if (thang<1 || thang>12)
		return false;
	if (ngay<1 || ngay>31)
		return false;
	if (thang==2){
		if(namNhuan(nam) && ngay<=29){
			return true;
		}
		else return false;
	}
	if (thang==1 ||thang==3 ||thang==5 ||thang==7 ||
		thang==8 ||thang==10 ||thang==12 && ngay<=31){
		return true;
	}
	if (thang==4 ||thang==6 ||thang==9 ||thang==11 && ngay<=30 )
		return true;
	else return false;
}
int demSoSinhVien(list l){
	int dem=0;
	for (node* p=l.pHead; p!=NULL; p=p->pNext)
		dem ++;
	return dem;
}

void xuatCot(){
	cout << endl;
    cout << setw(7) << left << "MALOP" << "\t"
		 << setw(12) << left << "MSV" << "\t"
		 << setw(20) << left << "HO VA TEN" << "\t"
		 << setw(12) << left << "NGAY SINH"<< "\t"
		 << setw(8) << left << "DIEM TB" << endl;
}
void xuat(SinhVien sv){
	chuanHoaMaLop(&sv.maLop);
	chuanHoaTen(&sv.hoTen);
	if(sv.maLop.length() == 4){
		sv.maLop.erase(0,1);
	}
	cout << setw(7) << left << sv.maLop << "\t"
			 << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
}
bool haveString(string s){
	for (int i=0; i<s.length(); i++){
		if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122  )
			return true;
	}
	return false;
}
bool haveNumber(string s){
	for (int i=0; i<s.length(); i++){
		if (s[i] >= 48 && s[i] <= 57)
			return true;
	}
	return false;
}


// ===== sap xep =====
void cacThuatToanSapXep(){
	cout << "\n\tCac thuat toan sap xep: ";
	cout << "\n\t\t1. Sap xep chon";
	cout << "\n\t\t2. Sap xep chen";
	cout << "\n\t\t3. Sap xep noi bot";
}
void cacKhoa(){
	cout << "\nCac khoa: ";
	cout << "\n\t1. Ma lop";
	cout << "\n\t2. Ma sinh vien";
	cout << "\n\t3. Ho ten";
	cout << "\n\t4. Ngay sinh";
	cout << "\n\t5. Diem trung binh";
}
void khoa1(){
	cout << "\nCac khoa: ";
	TextColor(10);
	cout << "\n\t1. Ma lop";
	TextColor(7);
	cout << "\n\t2. Ma sinh vien";
	cout << "\n\t3. Ho ten";
	cout << "\n\t4. Ngay sinh";
	cout << "\n\t5. Diem trung binh";
}
//void khoa2(){
//	cout << "\nCac khoa: ";
//	cout << "\n\t1. Ma lop";
//	TextColor(10);
//	cout << "\n\t2. Ma sinh vien";
//	TextColor(7);
//	cout << "\n\t3. Ho ten";
//	cout << "\n\t4. Ngay sinh";
//	cout << "\n\t5. Diem trung binh";
//}
//void khoa3(){
//	cout << "\nCac khoa: ";
//	cout << "\n\t1. Ma lop";
//	cout << "\n\t2. Ma sinh vien";
//	TextColor(10);
//	cout << "\n\t3. Ho ten";
//	TextColor(7);
//	cout << "\n\t4. Ngay sinh";
//	cout << "\n\t5. Diem trung binh";
//}
//void khoa4(){
//	cout << "\nCac khoa: ";
//	cout << "\n\t1. Ma lop";
//	cout << "\n\t2. Ma sinh vien";
//	cout << "\n\t3. Ho ten";
//	TextColor(10);
//	cout << "\n\t4. Ngay sinh";
//	TextColor(7);
//	cout << "\n\t5. Diem trung binh";
//}
//void khoa5(){
//	cout << "\nCac khoa: ";
//	cout << "\n\t1. Ma lop";
//	cout << "\n\t2. Ma sinh vien";
//	cout << "\n\t3. Ho ten";
//	cout << "\n\t4. Ngay sinh";
//	TextColor(10);
//	cout << "\n\t5. Diem trung binh";
//	TextColor(7);
//}
void menuSapXep(list l){
	cacKhoa();
	int chonThuatToan, chonKhoaSapXep;
	cout << "\n\nChon khoa can sap xep: "; cin >> chonKhoaSapXep;
	cacThuatToanSapXep();
	cout << "\n\nChon thuat toan sap xep: "; cin >> chonThuatToan;

	switch (chonKhoaSapXep){
	case 1:{
		if (chonThuatToan == 1){
			sapXepChonMaLop(l);
		}
		if (chonThuatToan == 2) sapXepChenMaLop(l);
		if (chonThuatToan == 3) sapXepNoiBotMaLop(l);
		break;
		   }
	case 2:{
		if (chonThuatToan == 1) sapXepChonMsv(l);
		if (chonThuatToan == 2) sapXepChenMsv(l);
		if (chonThuatToan == 3) sapXepNoiBotMsv(l);
		break;
		   }
	case 3:{
		if (chonThuatToan == 1) sapXepHoTen(l);
		if (chonThuatToan == 2) sapXepHoTen(l);
		if (chonThuatToan == 3) sapXepHoTen(l);
		break;
		   }
	case 4:{
		if (chonThuatToan == 1) sapXepNgaySinh(l);
		if (chonThuatToan == 2) sapXepNgaySinh(l);
		if (chonThuatToan == 3) sapXepNgaySinh(l);
		break;
		   }
	case 5:{
		if (chonThuatToan == 1) sapXepChonDTB(l);
		if (chonThuatToan == 2) sapXepChenDTB(l);
		if (chonThuatToan == 3) sapXepNoiBotDTB(l);
		break;
		   }
	default:
		break;
	}
}


// ===== tim kiem =====
void cacThuatToanTimKiem(){
	cout << "\nCac thuat toan tim kiem: ";
	cout << "\n\t1. Tim kiem tuan tu";
	//cout << "\n\t2. Tim kiem nhi phan";
}
void menuTimKiem(list l){
	int chonTimKiem, chonKhoaTimKiem;
	cacThuatToanTimKiem();
	cout << "\n\nChon thuat toan tim kiem: "; cin >> chonTimKiem;
	cacKhoa();
	cout << "\n\nChon khoa tim kiem: "; cin >> chonKhoaTimKiem;

	switch (chonKhoaTimKiem)
	{
	case 1:{
		if (chonTimKiem == 1) timKiemTuanTuMaLop(l);
		//if (chonTimKiem == 2) cout << "tim kiem nhi phan Ma lop";
		break;
		   }
	case 2:{
		if (chonTimKiem == 1) timKiemTuanTuMsv(l);
		//if (chonTimKiem == 2) cout << "tim kiem nhi phan MSV";
		break;
		   }
	case 3:{
		if (chonTimKiem == 1)  timKiemTuanTuHoTen(l);
		//if (chonTimKiem == 2) cout << "tim kiem nhi phan Ho Ten";
		break;
		   }
	case 4:{
		if (chonTimKiem == 1) timKiemTuanTuNgaySinh(l);
		//if (chonTimKiem == 2) cout << "tim kiem nhi phan Ngay Sinh";
		break;
		   }
    case 5:{
		if (chonTimKiem == 1) timKiemTuanTuDiemTb(l);
		//if (chonTimKiem == 2) cout << "tim kiem nhi phan Diem TB";
		break;
		   }
	default:
		break;
	}
}


// ===== thong ke =====
void menuThongKe(list l){
	cout << "\nCac kieu thong ke: ";
	cout << "\n\t1. Theo lop";
	cout << "\n\t2. Theo ket qua hoc tap";

	int chonKieuThongKe;
	cout << "\n\nChon kieu thong ke: "; cin >> chonKieuThongKe;
	if (chonKieuThongKe == 1){
		thongKeTheoSoLuongSinhVien(l);
	}
	else{
		thongKeTheoKetQuaHocTap(l);
	}
}


// ===== menu =====
void bangMenuThuong(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	cout << "\n|        1. THEM MOI HO SO            |";
	cout << "\n|        2. IN DANH SACH              |";
	cout << "\n|        3. SAP XEP                   |";
	cout << "\n|        4. TIM KIEM                  |";
	cout << "\n|        5. THONG KE                  |";
	cout << "\n|        6. SUA HO SO                 |";
	cout << "\n|        7. XOA                       |";
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void menu1(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	TextColor(10);
	cout << "\n|        1. THEM MOI HO SO            |";
	TextColor(7);
	cout << "\n|        2. IN DANH SACH              |";
	cout << "\n|        3. SAP XEP                   |";
	cout << "\n|        4. TIM KIEM                  |";
	cout << "\n|        5. THONG KE                  |";
	cout << "\n|        6. SUA HO SO                 |";
	cout << "\n|        7. XOA                       |";
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void menu2(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	cout << "\n|        1. THEM MOI HO SO            |";
	TextColor(10);
	cout << "\n|        2. IN DANH SACH              |";
	TextColor(7);
	cout << "\n|        3. SAP XEP                   |";
	cout << "\n|        4. TIM KIEM                  |";
	cout << "\n|        5. THONG KE                  |";
	cout << "\n|        6. SUA HO SO                 |";
	cout << "\n|        7. XOA                       |";
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void menu3(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	cout << "\n|        1. THEM MOI HO SO            |";
	cout << "\n|        2. IN DANH SACH              |";
	TextColor(10);
	cout << "\n|        3. SAP XEP                   |";
	TextColor(7);
	cout << "\n|        4. TIM KIEM                  |";
	cout << "\n|        5. THONG KE                  |";
	cout << "\n|        6. SUA HO SO                 |";
	cout << "\n|        7. XOA                       |";
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void menu4(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	cout << "\n|        1. THEM MOI HO SO            |";
	cout << "\n|        2. IN DANH SACH              |";
	cout << "\n|        3. SAP XEP                   |";
	TextColor(10);
	cout << "\n|        4. TIM KIEM                  |";
	TextColor(7);
	cout << "\n|        5. THONG KE                  |";
	cout << "\n|        6. SUA HO SO                 |";
	cout << "\n|        7. XOA                       |";
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void menu5(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	cout << "\n|        1. THEM MOI HO SO            |";
	cout << "\n|        2. IN DANH SACH              |";
	cout << "\n|        3. SAP XEP                   |";
	cout << "\n|        4. TIM KIEM                  |";
	TextColor(10);
	cout << "\n|        5. THONG KE                  |";
	TextColor(7);
	cout << "\n|        6. SUA HO SO                 |";
	cout << "\n|        7. XOA                       |";
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void menu6(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	cout << "\n|        1. THEM MOI HO SO            |";
	cout << "\n|        2. IN DANH SACH              |";
	cout << "\n|        3. SAP XEP                   |";
	cout << "\n|        4. TIM KIEM                  |";
	cout << "\n|        5. THONG KE                  |";
	TextColor(10);
	cout << "\n|        6. SUA HO SO                 |";
	TextColor(7);
	cout << "\n|        7. XOA                       |";
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void menu7(){
	cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	cout << "\n|        1. THEM MOI HO SO            |";
	cout << "\n|        2. IN DANH SACH              |";
	cout << "\n|        3. SAP XEP                   |";
	cout << "\n|        4. TIM KIEM                  |";
	cout << "\n|        5. THONG KE                  |";
	cout << "\n|        6. SUA HO SO                 |";
	TextColor(10);
	cout << "\n|        7. XOA                       |";
	TextColor(7);
	cout << "\n|        8. THOAT                     |";
	cout << "\n\n=======================================\n";
}
void bangMenuChay(){
	//cout << "\n========== QUAN LY SINH VIEN ==========" << endl;
	string s1 = "\n========== QUAN LY SINH VIEN ==========\n";
	//cout << "\n|        1. THEM MOI HO SO            |";
	string s2 = "\n|        1. THEM MOI HO SO            |";
	//cout << "\n|        2. IN DANH SACH              |";
	string s3 = "\n|        2. IN DANH SACH              |";
	//cout << "\n|        3. SAP XEP                   |";
	string s4 = "\n|        3. SAP XEP                   |";
	//cout << "\n|        4. TIM KIEM                  |";
	string s5 = "\n|        4. TIM KIEM                  |";
	//cout << "\n|        5. THONG KE                  |";
	string s6 = "\n|        5. THONG KE                  |";
	//cout << "\n|        6. SUA HO SO                 |";
	string s7 = "\n|        6. SUA HO SO                 |";
	//cout << "\n|        7. XOA                       |";
	string s8 = "\n|        7. XOA                       |";
	//cout << "\n|        8. THOAT                     |";
	string s9 = "\n|        8. THOAT                     |";
	//cout << "\n\n=======================================";
	string s10 = "\n\n=======================================\n";
	
	string s = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9 + s10;

	for (int i=0; i< s.length(); i++){
		TextColor(10);
		cout << s[i];
		Sleep(2);
		TextColor(7);
	}
	cout << endl;
}

void menu(list &l){
	bangMenuChay();
	while (1){
		int luaChon;
		cout << "\nNhap vao lua chon: ";
		cin >> luaChon;

		if (luaChon == 1){
			system("cls");
			menu1();
			nhapThongTin(l);
			system("pause");
			system("cls");
			bangMenuThuong();
		}
		else if (luaChon == 2){
			system("cls");
			menu2();
			inDanhSach(l);
			system("pause");
			system("cls");
			bangMenuThuong();
		}
		else if (luaChon == 3){
			system("cls");
			menu3();
			menuSapXep(l);
			system("pause");
			system("cls");
			bangMenuThuong();
		}
		else if (luaChon == 4){
			system("cls");
			menu4();
			menuTimKiem(l);
			system("pause");
			system("cls");
			bangMenuThuong();
		}
		else if (luaChon == 5){
			system("cls");
			menu5();
			menuThongKe(l);
			system("pause");
			system("cls");
			bangMenuThuong();
		}
		else if (luaChon == 6){
			system("cls");
			menu6();
			suaHoSo(l);
			system("pause");
			system("cls");
			bangMenuThuong();
		}
		else if (luaChon == 7){
			system("cls");
			menu7();
			xoa(l);
			system("pause");
			system("cls");
			bangMenuThuong();
		}
		else if (luaChon == 8){
			break;
		}
	}
}


// ===== thao tac tren file =====
void docThongTinSinhVien(ifstream &fileIn, SinhVien &sv){
	// doc ma lop
	getline(fileIn, sv.maLop, ','); // doc ma lop, sau do con tro chi vi nhay qua dau phay
	fileIn.seekg(1,1); // dich con tro chi vi 1 byte de bo qua khoang trang
	//chuanHoaMaLop(&sv.maLop);
	// doc ma sinh vien
	getline(fileIn, sv.MSV, ',');
	fileIn.seekg(1,1);
	// doc ho
	getline(fileIn, sv.ho, ' ');
	chuanHoaTen(&sv.ho);
	sv.ho = sv.ho + " ";
	//doc dem
	getline(fileIn, sv.dem, ' ');
	chuanHoaTen(&sv.dem);
	sv.dem = sv.dem + " ";
	
	//fileIn.seekg(1,1);
	// doc ten
	getline(fileIn, sv.ten, ',');
	chuanHoaTen(&sv.ten);
	fileIn.seekg(1,1);
	


	sv.hoTen = sv.ho + sv.dem + sv.ten;
	// doc ho ten
	//getline(fileIn, sv.hoTen, ',');
	//fileIn.seekg(1,1);

	// doc date
	fileIn >> sv.date.ngay;
	fileIn.seekg(1,1);
	fileIn >> sv.date.thang;
	fileIn.seekg(1,1);
	fileIn >> sv.date.nam;
	fileIn.seekg(1,1);
	// doc diem
	fileIn >> sv.diemTB;
}
void docDanhSach(ifstream &fileIn, list &l){
	for (int i=0; i<10; i++){
		SinhVien sv;
		docThongTinSinhVien(fileIn, sv);
		node* p = khoiTaoNode(sv);
		themCuoi(l,p);
	}
}
void ghiThongTinSinhVien(ofstream &fileOut, SinhVien sv){
	fileOut << sv.maLop << ", ";
	fileOut << sv.MSV << ", ";

	//fileOut << sv.ho << " " << sv.ten << ", ";
	fileOut << sv.hoTen << ", ";

	fileOut << sv.date.ngay << "/";
	fileOut << sv.date.thang << "/";
	fileOut << sv.date.nam << ", ";
	fileOut << sv.diemTB;
	fileOut << endl;
}
void ghiDanhSach(list l){
	// chuan hoa truoc khi ghi
	for (node*p = l.pHead; p!=NULL; p=p->pNext){
		chuanHoaTen(&(p->data.hoTen));
		chuanHoaMaLop(&(p->data.maLop));
		if(p->data.maLop.length() == 4){
			p->data.maLop.erase(0,1);
		}
	}
	// ghi danh sach
	ofstream fileOut;
	fileOut.open("sinhvienOut.txt", ios::out);
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		ghiThongTinSinhVien(fileOut, p->data);
	}
	fileOut.close();
}


