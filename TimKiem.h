#ifndef TIMKIEM_H
#define TIMKIEM_H
// nice bro
#include "QLSV.h"
#include <string.h>


void timKiemTuanTuMaLop(list l);
void timKiemTuanTuMsv(list l);
void timKiemTuanTuHoTen(list l);
void timKiemTuanTuNgaySinh(list l);
void timKiemTuanTuDiemTb(list l);

void xuatTimKiemMaLop(SinhVien sv, string s, string s1);
void xuatTimKiemMsv(SinhVien sv, string s);
void xuatTimKiemNgaySinh(SinhVien sv, int ngay, int thang, int nam);
void xuatTimKiemDiemTB(SinhVien sv, float diemTb);
void xuatTimKiemHoTen(SinhVien sv, string ho, string dem, string ten);
#endif
