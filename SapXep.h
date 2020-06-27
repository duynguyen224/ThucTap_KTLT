#ifndef SAPXEP_H
#define SAPXEP_H

#include "QLSV.h"
//#include <algorithm>
#include <string.h>

void doiCho(SinhVien &x, SinhVien &y);
//void sortedInsert(node** head_ref, node* new_node);
void sortedInsert_DTB(node** head_ref, node* new_node);
void sortedInsert_MaLop(node** head_ref, node* new_node);
void sortedInsert_MSV(node** head_ref, node* new_node);


void sapXepChonMaLop(list &l);
void sapXepChenMaLop(list &l);
void sapXepNoiBotMaLop(list &l);


void sapXepChonMsv(list &l);
void sapXepChenMsv(list &l);
void sapXepNoiBotMsv(list &l);

//bool sapXepTen(node* left, node* right);
void sapXepHoTen(list &l);

void sapXepNgaySinh(list &l);

void sapXepChonDTB(list &l);
void sapXepChenDTB(list &l);
void sapXepNoiBotDTB(list &l);




#endif