#include "TimKiem.h"
#include <iomanip>
#include <iostream>
void xuatTimKiemMaLop(SinhVien sv, string s, string s1){
	chuanHoaMaLop(&sv.maLop);
	chuanHoaTen(&sv.hoTen);
	if(sv.maLop.length() == 4){
		sv.maLop.erase(0,1);
	}
	
	if (s == sv.maLop || s1 == sv.maLop){
		TextColor(10);
		cout << setw(7) << left << sv.maLop << "\t";
		TextColor(7);
		cout << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
		goto next;
	}

		cout << setw(7) << left << sv.maLop << "\t";
		cout << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
next:
		int a= 0;
}
void timKiemTuanTuMaLop(list l){
	string s;
	cin.ignore();
	cout << "Nhap ma lop muon tim kiem: ";
	getline(cin, s);
	chuanHoaMaLop(&s);
	string s1 = "\n" + s;
	cout << endl;
	cout << "__________________________________________________________________\n\n";
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		xuatTimKiemMaLop(p->data, s, s1);
	}
	cout << "__________________________________________________________________\n\n";
}
//void timKiemTuanTuMaLop(list l){
//	string s;
//	cin.ignore();
//	cout << "Nhap ma lop muon tim kiem: ";
//	getline(cin, s);
//	chuanHoaMaLop(&s);
//	string s1 = "\n" + s;
//	for (node* p=l.pHead; p!=NULL; p=p->pNext){
//		string temp = p->data.maLop;
//		if (s == temp || s1 == temp ){
//			xuatCot();
//			xuat(p->data);
//			
//		}
//	}
//}

void xuatTimKiemMsv(SinhVien sv, string s){
	chuanHoaMaLop(&sv.maLop);
	chuanHoaTen(&sv.hoTen);
	if(sv.maLop.length() == 4){
		sv.maLop.erase(0,1);
	}
	
	if (s == sv.MSV){
		cout << setw(7) << left << sv.maLop << "\t";
		TextColor(10);
		cout << setw(12) << left << sv.MSV << "\t";
		TextColor(7);
		cout << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
		goto next;
	}

		cout << setw(7) << left << sv.maLop << "\t";
		cout << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
next:
		int a= 0;
}
void timKiemTuanTuMsv(list l){
	string s;
	cin.ignore();
	cout << "Nhap ma sinh vien muon tim kiem: ";
	getline(cin, s);
	cout << endl;
	cout << "__________________________________________________________________\n\n";
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		xuatTimKiemMsv(p->data, s);
	}
	cout << "__________________________________________________________________\n\n";
}
//void timKiemTuanTuMsv(list l){
//	string s;
//	cin.ignore();
//	cout << "Nhap ma sinh vien muon tim kiem: ";
//	getline(cin, s);
//	for (node* p=l.pHead; p!=NULL; p=p->pNext){
//		string temp = p->data.MSV;
//		if (s == temp){
//			xuatCot();
//			xuat(p->data);
//		}
//	}
//}


void xuatTimKiemNgaySinh(SinhVien sv, int ngay, int thang, int nam){
	chuanHoaMaLop(&sv.maLop);
	chuanHoaTen(&sv.hoTen);
	if(sv.maLop.length() == 4){
		sv.maLop.erase(0,1);
	}
	
	if (ngay == sv.date.ngay && thang == sv.date.thang && nam == sv.date.nam){
		cout << setw(7) << left << sv.maLop << "\t";
		cout << setw(12) << left << sv.MSV << "\t";
		cout << setw(20) << left << sv.hoTen << "\t";
		TextColor(10);
		cout << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t";
		TextColor(7);
		cout << setw(8) << left << sv.diemTB << endl;
		goto next;
	}

		cout << setw(7) << left << sv.maLop << "\t";
		cout << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
next:
		int a= 0;
}
void timKiemTuanTuNgaySinh(list l){
	int d, m, y;
	cin.ignore();
	cout << "Nhap ngay, thang, nam muon tim kiem: " << endl;
	cout << "Nhap ngay: "; cin >> d;
	cout << "Nhap thang: "; cin >> m;
	cout << "Nhap nam: "; cin >> y;
	cout << endl;
	cout << "__________________________________________________________________\n\n";
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		xuatTimKiemNgaySinh(p->data, d, m, y);
	}
	cout << "__________________________________________________________________\n\n";
}
//void timKiemTuanTuNgaySinh(list l){
//	int d, m, y;
//	cin.ignore();
//	cout << "Nhap ngay, thang, nam muon tim kiem: " << endl;
//	cout << "Nhap ngay: "; cin >> d;
//	cout << "Nhap thang: "; cin >> m;
//	cout << "Nhap nam: "; cin >> y;
//	for (node* p=l.pHead; p!=NULL; p=p->pNext){
//		if (d == p->data.date.ngay && m == p->data.date.thang && y == p->data.date.nam){
//			xuatCot();
//			xuat(p->data);
//		}
//	}
//}




void xuatTimKiemDiemTB(SinhVien sv, float diemTb){
	chuanHoaMaLop(&sv.maLop);
	chuanHoaTen(&sv.hoTen);
	if(sv.maLop.length() == 4){
		sv.maLop.erase(0,1);
	}
	
	if (diemTb == sv.diemTB){
		cout << setw(7) << left << sv.maLop << "\t"
			 << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t";
		TextColor(10);
		cout << setw(8) << left << sv.diemTB << endl;
		TextColor(7);
		goto next;
	}

		cout << setw(7) << left << sv.maLop << "\t";
		cout << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
next:
		int a= 0;
}
void timKiemTuanTuDiemTb(list l){
	float diem;
	cin.ignore();
	cout << "Nhap diem trung binh muon tim kiem: ";
	cin >> diem;
	cout << endl;
	cout << "__________________________________________________________________\n\n";
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		xuatTimKiemDiemTB(p->data, diem);
	}
	cout << "__________________________________________________________________\n\n";
}
//void timKiemTuanTuDiemTb(list l){
//	float s;
//	cin.ignore();
//	cout << "Nhap diem trung binh muon tim kiem: ";
//	cin >> s;
//	for (node* p=l.pHead; p!=NULL; p=p->pNext){
//		float temp = p->data.diemTB;
//		if (s == temp){
//			xuatCot();
//			xuat(p->data);
//		}
//	}
//}





void xuatTimKiemHoTen(SinhVien sv, string ten, string ten1, string ho, string dem, string tenn){
	chuanHoaMaLop(&sv.maLop);
	chuanHoaTen(&sv.hoTen);
	if(sv.maLop.length() == 4){
		sv.maLop.erase(0,1);
	}
	
	if (ten == sv.ten || ten == sv.dem || ten == sv.ho 
			      ||ten1 == sv.ten || ten1 == sv.dem ||ten1 == sv.ho 
				  ||ten == sv.hoTen 
				  || ten == sv.ho + sv.dem || ten1 == sv.ho + sv.dem
				  ||ten == sv.dem + sv.ten || ten1 == sv.dem + sv.ten
				  ||ten == sv.ho + sv.ten || ten1 == sv.ho + sv.ten){
		cout << setw(7) << left << sv.maLop << "\t"
			 << setw(12) << left << sv.MSV << "\t";
		TextColor(10);
			cout << setw(20) << left << sv.hoTen << "\t";
		TextColor(7);
			cout << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t";
		cout << setw(8) << left << sv.diemTB << endl;
		goto next;
	}

		cout << setw(7) << left << sv.maLop << "\t";
		cout << setw(12) << left << sv.MSV << "\t"
			 << setw(20) << left << sv.hoTen << "\t"
			 << setw(2) << left << sv.date.ngay << "/" 
			 << setw(2) << left << sv.date.thang << "/" 
			 << setw(8) << left << sv.date.nam << "\t"
			 << setw(8) << left << sv.diemTB << endl;
next:
		int a= 0;
}
void timKiemTuanTuHoTen(list l){
	string ten;
	cin.ignore();
	cout << "Nhap ten muon tim kiem: ";
	getline(cin, ten);
	chuanHoaTen(&ten);
	string ten1 = ten + " ";
	// tach Ho, dem, ten --> luu lai
	SinhVien sv2;
	string s = ten;
	string delimiter = " ";
	size_t pos = 0;
	string token;
	int dem = 1;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);

		if (dem == 1){
			sv2.ho = token;
			sv2.ho = sv2.ho + " ";
			dem ++;
		}
		else if (dem == 2){
			sv2.dem = token;
			sv2.dem = sv2.dem + " ";
		}
			s.erase(0, pos + delimiter.length());
	}
	sv2.ten = s;

	cout << endl;
	cout << "__________________________________________________________________\n\n";
	for (node* p =l.pHead; p!=NULL; p=p->pNext){
		xuatTimKiemHoTen(p->data, ten, ten1, sv2.ho, sv2.dem, sv2.ten );
	}
	cout << "__________________________________________________________________\n\n";
}
//void timKiemTuanTuHoTen(list l){
//	string ten;
//	cin.ignore();
//	cout << "Nhap ten muon tim kiem: ";
//	getline(cin, ten);
//	chuanHoaTen(&ten);
//	string ten1 = ten + " ";
//	int dem =0;
//	int check = 0;
//	for (node* p =l.pHead; p!=NULL; p=p->pNext){
//		if (ten == p->data.ten || ten == p->data.dem || ten == p->data.ho 
//			      ||ten1 == p->data.ten || ten1 == p->data.dem ||ten1 == p->data.ho 
//				  ||ten == p->data.hoTen 
//				  || ten == p->data.ho + p->data.dem || ten1 == p->data.ho + p->data.dem
//				  ||ten == p->data.dem + p->data.ten || ten1 == p->data.dem + p->data.ten
//				  ||ten == p->data.ho + p->data.ten || ten1 == p->data.ho + p->data.ten){
//			if (check == dem){
//				xuatCot();
//			}
//			xuat(p->data);
//			dem = 1;
//		}
//	}
//	if (dem == 0)
//		cout << "Khong tim thay..." << endl;
//}