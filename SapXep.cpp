#include "SapXep.h"

void doiCho(SinhVien &x, SinhVien &y){
	SinhVien temp;
	temp = x;
	x = y;
	y = temp;
}
void sortedInsert_DTB(node** head_ref, node* new_node) {
    node* current; 
    /* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data.diemTB >= new_node->data.diemTB) {
		new_node->pNext = *head_ref; 
        *head_ref = new_node; 
    } 
    else{
        /* Locate the node before the point of insertion */
        current = *head_ref; 
		while (current->pNext!=NULL && 
			current->pNext->data.diemTB< new_node->data.diemTB) {
				current = current->pNext; 
        } 
		new_node->pNext = current->pNext; 
		current->pNext = new_node; 
    } 
} 
void sortedInsert_MaLop(node** head_ref, node* new_node){
	node* current; 
    /* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data.maLop >= new_node->data.maLop) {
		new_node->pNext = *head_ref; 
        *head_ref = new_node; 
    } 
    else{
        /* Locate the node before the point of insertion */
        current = *head_ref; 
		while (current->pNext!=NULL && 
			current->pNext->data.maLop< new_node->data.maLop) {
				current = current->pNext; 
        } 
		new_node->pNext = current->pNext; 
		current->pNext = new_node; 
    } 
}
void sortedInsert_MSV(node** head_ref, node* new_node){
	node* current; 
    /* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data.MSV >= new_node->data.MSV) {
		new_node->pNext = *head_ref; 
        *head_ref = new_node; 
    } 
    else{
        /* Locate the node before the point of insertion */
        current = *head_ref; 
		while (current->pNext!=NULL && 
			current->pNext->data.MSV< new_node->data.MSV) {
				current = current->pNext; 
        } 
		new_node->pNext = current->pNext; 
		current->pNext = new_node; 
    } 
}

void sapXepChonMaLop(list &l){
	node* temp = l.pHead; 
    // Traverse the List 
    while (temp) { 
        node* min = temp; 
		node* r = temp->pNext; 
  
        // Traverse the unsorted sublist 
        while (r) { 
			if (min->data.maLop > r->data.maLop) 
                min = r; 
  
			r = r->pNext; 
        } 
  
        // Swap Data 
		SinhVien x = temp->data; 
        temp->data = min->data; 
		min->data = x; 
		temp = temp->pNext; 
    }
}
void sapXepChenMaLop(list &l){
	// Khoi tao list moi chua danh sach da sap xep
    node* sorted = NULL; 
  
    // duyet list, them node vao list da sap xep
	node* current = l.pHead; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
		node* next = current->pNext; 
  
        // insert current in sorted linked list 
        sortedInsert_MaLop(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
	l.pHead = sorted;
}
void sapXepNoiBotMaLop(list &l){
	int swapped; //, i; 
    node* ptr1; 
    node* lptr = NULL; 
  
    /* Checking for empty list */
	if (l.pHead == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
		ptr1 = l.pHead; 
  
		while (ptr1->pNext != lptr) 
        { 
			if (ptr1->data.maLop > ptr1->pNext->data.maLop) 
            {  
				doiCho(ptr1->data, ptr1->pNext->data); 
                swapped = 1; 
            } 
			ptr1 = ptr1->pNext; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
}


void sapXepChonMsv(list &l){
	node* temp = l.pHead; 
    // Traverse the List 
    while (temp) { 
        node* min = temp; 
		node* r = temp->pNext; 
  
        // Traverse the unsorted sublist 
        while (r) { 
			if (min->data.MSV > r->data.MSV) 
                min = r; 
  
			r = r->pNext; 
        } 
  
        // Swap Data 
		SinhVien x = temp->data; 
        temp->data = min->data; 
		min->data = x; 
		temp = temp->pNext; 
    }
}
void sapXepChenMsv(list &l){
	// Khoi tao list moi chua danh sach da sap xep
    node* sorted = NULL; 
  
    // duyet list, them node vao list da sap xep
	node* current = l.pHead; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
		node* next = current->pNext; 
  
        // insert current in sorted linked list 
        sortedInsert_MSV(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
	l.pHead = sorted;
}
void sapXepNoiBotMsv(list &l){
	int swapped; //, i; 
    node* ptr1; 
    node* lptr = NULL; 
  
    /* Checking for empty list */
	if (l.pHead == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
		ptr1 = l.pHead; 
  
		while (ptr1->pNext != lptr) 
        { 
			if (ptr1->data.MSV > ptr1->pNext->data.MSV) 
            {  
				doiCho(ptr1->data, ptr1->pNext->data); 
                swapped = 1; 
            } 
			ptr1 = ptr1->pNext; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
}

//bool sapXepTen(node* left, node* right){
//	string s1 = left->data.hoTen;
//	string s2 = right->data.hoTen;
//    string lastName1, lastName2, midName1, midName2,firstName1,firstName2;
//
//    //int pos1, pos2;
//
//    for (int i = s1.size() - 1; i >= 0; i--) {
//        if (s1.at(i) == ' ') {
//            lastName1 = s1.substr(i + 1, s1.size() - 1 - (i));
//            for (int j = 0; j <=i; j++) {
//                if (s1.at(j) == ' ') {
//                    firstName1 = s1.substr(0, j);
//                    midName1 = s1.substr(j+1, i-(j+1));
//                    break;
//                } 
//            }
//            break;
//        } else if (i == 0) {
//            lastName1 = s1;
//        }
//    }
//
//
//   for (int i = s2.size() - 1; i >= 0; i--) {
//        if (s2.at(i) == ' ') {
//            lastName2 = s2.substr(i + 1, s2.size() - 1 - (i));
//            for (int j = 0; j <=i; j++) {
//                if (s2.at(j) == ' ') { 
//                    firstName2 = s2.substr(0, j);
//                    midName2 = s2.substr(j+1, i-(j+1));
//                    break;
//                } 
//            }
//            break;
//        } else if (i == 0) {
//            lastName2 = s2;
//        }
//    }
//
//    if (lastName1.length() < lastName2.length()) {
//        if (lastName1 < lastName2.substr(0, lastName1.length())) return true;
//        else return false;
//    } else if (lastName1.length() > lastName2.length()) {
//        if (lastName1.substr(0, lastName2.length()) < lastName2) return true;
//        else return false;
//    } else {
//        if (lastName1 < lastName2) return true;
//        else if (lastName1 == lastName2) {
//            if (firstName1 < firstName2) return true;
//            else {
//                if(firstName1 > firstName2) return false;
//                else{
//                    if(midName1<midName2) return true;
//                    else return false;
//                }
//            }
//        } else return false;
//    }
//}
void sapXepHoTen(list &l){
	for (node* p=l.pHead; p!=NULL; p=p->pNext){
		for (node* q=p->pNext; q!=NULL; q=q->pNext){
			if (p->data.ten > q->data.ten){
				doiCho(p->data, q->data);
			}
			else if (p->data.ten == q->data.ten && p->data.dem > q->data.dem){
				doiCho(p->data, q->data);
			}
			else if (p->data.ten == q->data.ten && p->data.dem == q->data.dem && p->data.ho > q->data.ho){
				doiCho(p->data, q->data);
			}
		}
	}
}


void sapXepNgaySinh(list &l){
	for (node* p =l.pHead; p!=NULL; p=p->pNext){
		for (node* q=p->pNext; q!=NULL; q=q->pNext){
			if (p->data.date.nam > q->data.date.nam){
				doiCho(p->data, q->data);
            } 
			else if (p->data.date.nam == q->data.date.nam && p->data.date.thang > q->data.date.thang){
                doiCho(p->data, q->data);
            } 
            else if (p->data.date.nam == q->data.date.nam && p->data.date.thang == q->data.date.thang && p->data.date.ngay > q->data.date.ngay){
				doiCho(p->data, q->data);
            } 
        } 
    }
}

void sapXepChonDTB(list &l){
	node* temp = l.pHead; 
    // duyet danh sach
    while (temp) { 
        node* min = temp; 
		node* r = temp->pNext; 
  
        // duyet danh sach chua sap xep
        while (r) { 
			if (min->data.diemTB > r->data.diemTB) 
                min = r; 
  
			r = r->pNext; 
        } 
  
        // doi cho data
		SinhVien x = temp->data; 
        temp->data = min->data; 
		min->data = x; 
		temp = temp->pNext; 
    } 
}
void sapXepChenDTB(list &l){
	// Khoi tao list moi chua danh sach da sap xep
    node* sorted = NULL; 
  
    // duyet list, them node vao list da sap xep
	node* current = l.pHead; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
		node* next = current->pNext; 
  
        // insert current in sorted linked list 
        sortedInsert_DTB(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
	l.pHead = sorted; 
}
void sapXepNoiBotDTB(list &l){
	int swapped; //, i; 
    node* ptr1; 
    node* lptr = NULL; 
  
    /* Checking for empty list */
	if (l.pHead == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
		ptr1 = l.pHead; 
  
		while (ptr1->pNext != lptr) 
        { 
			if (ptr1->data.diemTB > ptr1->pNext->data.diemTB) 
            {  
				doiCho(ptr1->data, ptr1->pNext->data); 
                swapped = 1; 
            } 
			ptr1 = ptr1->pNext; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

