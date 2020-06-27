#include "QLSV.h"
#include "SapXep.h"
#include "TimKiem.h"
#include <iostream>
using namespace std;

int main (){
	list l;
	khoiTaoDanhSach(l);

	// doc file "sinhvien.txt", ghi vao List
	ifstream fileIn;
	fileIn.open("sinhvien.txt", ios_base::in);
	docDanhSach(fileIn, l);
	fileIn.close();
	// menu

	menu(l);
	

	// ghi List vao file "sinhvienOut.txt"
	ghiDanhSach(l);
	system("pause");
}