#include "ThongKe.h"
#include "SapXep.h"

int demSinhVienTrongLop(list l, string lop){
	int dem = 0;
	for (node* p=l.pHead; p!= NULL; p=p->pNext){
		if (p->data.maLop == lop)
			dem ++;
	}
	return dem;
}

int* phanLoai(list l, string lop){ // phan loai xuat sac .... yeu trong mot lop
	int* arr = new int[5]; // luu so sinh vien xuat sac, gioi, kha, trung binh, yeu vao trong mang
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		if (p->data.maLop == lop){
			if (p->data.diemTB >= 9) arr[0]++; // xuat sac
			else if (p->data.diemTB >=8 && p->data.diemTB < 9 ) arr[1]++; // gioi
			else if (p->data.diemTB >=7 && p->data.diemTB < 8 ) arr[2]++; // kha
			else if (p->data.diemTB >=5 && p->data.diemTB < 7 ) arr[3]++; // trung binh
			else arr[4]++; // yeu
		}
	}
	return arr;
}

void thongKeTheoSoLuongSinhVien(list l){
	int tongSinhVien = 0;
	sapXepNoiBotMaLop(l);
	cout << "\n_______________________________________\n\n";
	cout << setw(7) << left << "MA LOP" << "\t"
		 << setw(8) << left << "TEN LOP" << "\t"
		 << setw (13) << left << "SO SINH VIEN" << endl;
	cout << "_______________________________________\n\n";
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		if(p->data.maLop.length() == 4){
			p->data.maLop.erase(0,1);
		}
		cout << setw(7) << left << p->data.maLop << "\t"
		   	<< setw(8) << left << p->data.maLop << "\t"
			<< setw(13) << left << demSinhVienTrongLop(l, p->data.maLop) << endl;
		tongSinhVien += demSinhVienTrongLop(l, p->data.maLop);
	}
	cout << "_______________________________________\n";
	cout << "\nTONG" << "\t\t\t" << tongSinhVien << endl;
	cout << "_______________________________________\n\n\n\n";
}

void thongKeTheoKetQuaHocTap(list l){
	int soLuongSinhVien_theokq[5] = {0,0,0,0,0}; // luu TONG so sinh vien xuat sac ... yeu cua cac lop
	sapXepNoiBotMaLop(l);
	cout << "\n________________________________________________________________________________________\n\n";
	cout << setw(10) << left << "MA LOP" << "\t"
		<< setw(10) << left << "XUAT SAC" << "\t"
		<< setw(10) << left << "GIOI" << "\t"
		<< setw(10) << left << "KHA" << "\t"
		<< setw(10) << left << "TRUNG BINH" << "\t"
		<< setw(10) << left << "YEU" << endl;

	cout << "________________________________________________________________________________________\n\n";
	cout << setw(10) << "      " << "\t"
		<< setw(5) << left << "SL" << setw(5) << left << "%" << "\t"
		<< setw(5) << left << "SL" << setw(5) << left << "%" << "\t"
		<< setw(5) << left << "SL" << setw(5) << left << "%" << "\t"
		<< setw(5) << left << "SL" << setw(5) << left << "%" << "\t"
		<< setw(5) << left << "SL" << setw(5) << left << "%" << endl;
	cout << "________________________________________________________________________________________\n\n";


	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		if(p->data.maLop.length() == 4){
			p->data.maLop.erase(0,1);
		}
		int* ptr = phanLoai(l, p->data.maLop);
		cout << setw(10) << left << p->data.maLop << "\t";
		cout << setw(5) << left << ptr[0] << setw(5) << left << ptr[0]/demSinhVienTrongLop(l, p->data.maLop)*100 << "\t";
		soLuongSinhVien_theokq[0] += ptr[0]; // so luong Xuat sac
		cout << setw(5) << left << ptr[1] << setw(5) << left << ptr[1]/demSinhVienTrongLop(l, p->data.maLop)*100 << "\t";
		soLuongSinhVien_theokq[1] += ptr[1]; // gioi
		cout << setw(5) << left << ptr[2] << setw(5) << left << ptr[2]/demSinhVienTrongLop(l, p->data.maLop)*100 << "\t";
		soLuongSinhVien_theokq[2] += ptr[2]; // kha
		cout << setw(5) << left << ptr[3] << setw(5) << left << ptr[3]/demSinhVienTrongLop(l, p->data.maLop)*100 << "\t";
		soLuongSinhVien_theokq[3] += ptr[3]; // tb
		cout << setw(5) << left << ptr[4] << setw(5) << left << ptr[4]/demSinhVienTrongLop(l, p->data.maLop)*100;
		soLuongSinhVien_theokq[4] += ptr[4]; // yeu
		cout <<endl;
	}
	cout << "________________________________________________________________________________________\n\n";

	int tongSoSinhVien = 0;
	for (int i=0; i<4; i++){
		tongSoSinhVien += soLuongSinhVien_theokq[i];
	}
	cout << setw(10) << "TONG" << "\t";

	cout << setw(5) << left << soLuongSinhVien_theokq[0] << setw(5) << left << soLuongSinhVien_theokq[0]*100/tongSoSinhVien << "\t";
	cout << setw(5) << left << soLuongSinhVien_theokq[1] << setw(5) << left << soLuongSinhVien_theokq[1]*100/tongSoSinhVien << "\t";
	cout << setw(5) << left << soLuongSinhVien_theokq[2] << setw(5) << left << soLuongSinhVien_theokq[2]*100/tongSoSinhVien << "\t";
	cout << setw(5) << left << soLuongSinhVien_theokq[3] << setw(5) << left << soLuongSinhVien_theokq[3]*100/tongSoSinhVien << "\t";
	cout << setw(5) << left << soLuongSinhVien_theokq[4] << setw(5) << left << soLuongSinhVien_theokq[4]*100/tongSoSinhVien;
	
	cout << "\n\n\n\n\n\n";
}