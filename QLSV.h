#ifndef QLSV_H
#define QLSV_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;


// ===== khai bao cac cau truc =====
typedef struct Date{
	int ngay, thang, nam;
};
typedef struct SinhVien{
	string maLop;
	string MSV;
	string ho;
	string dem;
	string ten;
	string hoTen;
	Date date;
	float diemTB;
};
typedef struct node{
	SinhVien data;
	node* pNext;
};
typedef struct list{
	node* pHead;
	node* pTail;
};


// ===== danh sach =====
void khoiTaoDanhSach(list &l);
bool isEmpty(list l);
node* khoiTaoNode(SinhVien sv);
void themCuoi(list &l, node* p);
void xoaNode(list &l, node* n);

// ===== yeu cau de bai =====
void nhapThongTin(list &l); 
void inDanhSach(list &l); 

// ===== sua ho so =====
void suaHoSo(list &l);
	
// == xoa ho so =====
void xoa(list &l);

// ===== chuan hoa, kiem tra =====
void chuanHoaTen(string *s);
void chuanHoaMaLop(string *s);
bool namNhuan(int nam);
bool kiemTraNgayThangNam(int ngay, int thang, int nam);
int demSoSinhVien(list l);
void xuatCot();
void xuat(SinhVien sv);
bool haveString(string s);
bool haveNumber(string s);

// ===== sap xep =====
void cacThuatToanSapXep();
void cacKhoa();
//void khoa1();
//void khoa2();
//void khoa3();
//void khoa4();
//void khoa5();
void menuSapXep(list l);


// ===== tim kiem =====
void cacThuatToanTimKiem();
void menuTimKiem(list l);


// ===== thong ke =====
void menuThongKe(list l);


// ===== menu =====
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();


void bangMenuChay();
void bangMenuThuong();
void menu(list &l);


// ===== thao tac tren file =====
void docThongTinSinhVien(ifstream &fileIn, SinhVien &sv); // doc thong tin 1 sinh vien
void docDanhSach(ifstream &fileIn, list &l); // doc danh sach sinh vien
void ghiThongTinSinhVien(ostream &fileOut, SinhVien &sv); // ghi thong tin 1 sinh vien
void ghiDanhSach(list l);


void TextColor(int color);

#endif