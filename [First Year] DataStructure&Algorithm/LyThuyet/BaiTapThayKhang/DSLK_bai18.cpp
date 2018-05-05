#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct member {
	string code;					// _1: ma nhan vien
	string name;					// _2: ho ten nhan vien
	string relationship;		// _3: tinh trang gia dinh
	int child;					// _4: so con
	string education;			// _5: trinh do van hoa
	float salaryCB;			// _6: luong co ban
	float salaryTL;			// _7: luong thuc linh
	int cntCP;					// _8: so ngay nghi co phep
	int cntKP;					// _9: so ngay nghi khong phep
	int cntLT;					// _10: so ngay lam them
	string result;				// _11: ket qua lam viec
	
	void enter_MaNhanVien() {
		cout << "Ma nhan vien: ";
		fflush(stdin);
		getline(cin, code);	
	}
	void write_MaNhanVien() {
		cout << "Ma nhan vien: " << code << endl;
	}
	void update_MaNhanVien(string MaNhanVien) {
		code = MaNhanVien;	
	}
	string get_MaNhanVien() {
		return code;
	}
	
	void enter_HoTenNhanVien() {
		cout << "Ho ten nhan vien: ";
		fflush(stdin);
		getline(cin, name);
	}
	void write_HoTenNhanVien() {
		cout << "Ho ten nhan vien: " << name << endl;
	}
	void update_HoTenNhanVien(string HoTenNhanVien) {
		name = HoTenNhanVien;
	}
	string get_HoTenNhanVien() {
		return name;
	}
	
	void enter_TinhTrangGiaDinh() {
		cout << "Tinh trang gia dinh: ";
		fflush(stdin);
		getline(cin, relationship);
	}
	void write_TinhTrangGiaDinh() {
		cout << "Tinh trang gia dinh: " << relationship << endl;	
	}
	void update_TinhTrangGiaDinh(string TinhTrangGiaDinh) {
		relationship = TinhTrangGiaDinh;
	}
	string get_TinhTrangGiaDinh() {
		return relationship;
	}
	
	void enter_SoCon() {
		cout << "So con: ";
		cin >> child;
	}
	void write_SoCon() {
		cout << "So con: " << child << endl;
	}
	void update_SoCon(int SoCon) {
		child = SoCon;
	}
	int get_SoCon() {
		return child;
	}
	
	void enter_TrinhDoVanHoa() {
		cout << "Trinh do van hoa: ";
		fflush(stdin);
		getline(cin, education);
	}
	void write_TrinhDoVanHoa() {
		cout << "Trinh do van hoa: " << education << endl;
	}
	void update_TrinhDoVanHoa(string TrinhDoVanHoa) {
		education = TrinhDoVanHoa;
	}
	string get_TrinhDoVanHoa() {
		return education;
	}
	
	void enter_LuongCoBan() {
		cout << "Luong co ban: ";
		cin >> salaryCB;	
	}
	void write_LuongCoBan() {
		cout << "Luong co ban: " << salaryCB << endl;
	}
	void update_LuongCoBan(float LuongCoBan) {
		salaryCB = LuongCoBan;
	}
	float get_LuongCoBan() {
		return salaryCB;
	}
	
	void write_LuongThucLinh() {
		cout << fixed;
		cout << setprecision(3);
		cout << "Luong thuc linh: " << salaryTL << endl;
	}
	void update_LuongThucLinh() {
		float PhuTroi = 0;
		float LuongCoBan = salaryCB;
		if (child > 2) PhuTroi += (LuongCoBan * 0.05);
		if (education == "CH") PhuTroi += (LuongCoBan * 0.10);
		PhuTroi += (LuongCoBan * 0.04 * cntLT);
		PhuTroi -= (LuongCoBan * 0.05 * cntKP);
		salaryTL = LuongCoBan + PhuTroi;	
	}
	float get_LuongThucLinh() {
		return salaryTL;
	}
	
	void enter_SoNgayNghiCoPhep() {
		cout << "So ngay nghi co phep: ";
		cin >> cntCP;
	}
	void write_SoNgayNghiCoPhep() {
		cout << "So ngay nghi co phep: " << cntCP << endl;
	}
	void update_SoNgayNghiCoPhep(int SoNgayNghiCoPhep) {
		cntCP = SoNgayNghiCoPhep;
	}
	int get_SoNgayNghiCoPhep() {
		return cntCP;
	}
	
	void enter_SoNgayNghiKhongPhep() {
		cout << "So ngay nghi khong phep: ";
		cin >> cntKP;
	}
	void write_SoNgayNghiKhongPhep() {
		cout << "So ngay nghi khong phep: " << cntKP << endl;
	}
	void update_SoNgayNghiKhongPhep(int SoNgayNghiKhongPhep) {
		cntKP = SoNgayNghiKhongPhep;
	}
	int get_SoNgayNghiKhongPhep() {
		return cntKP;
	}
	
	void enter_SoNgayLamThem() {
		cout << "So ngay lam them: ";
		cin >> cntLT;
	}
	void write_SoNgayLamThem() {
		cout << "So ngay lam them: " << cntLT << endl;
	}
	void update_SoNgayLamThem(int SoNgayLamThem) {
		cntLT = SoNgayLamThem;;
	}
	int get_SoNgayLamThem() {
		return cntLT;
	}
	
	void enter_KetQuaCongViec() {
		cout << "Ket qua cong viec: ";
		fflush(stdin);
		getline(cin, result);
	}
	void write_KetQuaCongViec() {
		cout << "Ket qua cong viec: " << result << endl;
	}
	void update_KetQuaCongViec(string KetQuaCongViec) {
		result = KetQuaCongViec;
	}
	string get_KetQuaCongViec() {
		return result;
	}
};

member getmember() {
	member p;
	p.enter_MaNhanVien();
	p.enter_HoTenNhanVien();
	p.enter_TinhTrangGiaDinh();
	p.enter_SoCon();
	p.enter_TrinhDoVanHoa();
	p.enter_LuongCoBan();
	p.enter_SoNgayNghiCoPhep();
	p.enter_SoNgayNghiKhongPhep();
	p.enter_SoNgayLamThem();
	p.enter_KetQuaCongViec();
	return p;
}

struct node {
	member info;
	node *left;
	node *right;
};

node *getnode(member tmp) {
	node *p = new node;
	p->info = tmp;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void writenode(member *p) {
	p->write_MaNhanVien();
	p->write_HoTenNhanVien();
	p->write_TinhTrangGiaDinh();
	p->write_SoCon();
	p->write_TrinhDoVanHoa();
	p->write_LuongCoBan();
	p->write_SoNgayNghiCoPhep();
	p->write_SoNgayNghiKhongPhep();
	p->write_SoNgayLamThem();
	p->write_LuongThucLinh();
	p->write_KetQuaCongViec();
}

struct listnode {
	node *head;
	node *tail;
	listnode() {
		head = NULL;
		tail = NULL;
	}
	void addTail(node *tmp) {
		if (head == NULL) {
			head = tail = tmp;
			return;
		}
		tail->right = tmp;
		tmp->left = tail;
		tail = tmp;
	}
	void listSalary() {
		node *tmp = head;
		while (1) {
			cout << "nhan vien: ";
			cout << (tmp->info).get_HoTenNhanVien();
			cout << " | luong thuc linh: ";
			(tmp->info).update_LuongThucLinh();
			cout << (tmp->info).get_LuongThucLinh();
			cout << endl;
			if (tmp == tail) return;
			tmp = tmp->right;
		}
	}
	member *find(string tmp) {
		if (head == NULL) return NULL;
		node *p = head;
		while (1) {
			if ((p->info).get_MaNhanVien() == tmp) return &(p->info);
			if (p == tail) return NULL;
			p = p->right;
		}
	}
};

void enter(listnode &list) {
	member a = getmember();
	node *b = getnode(a);
	(b->info).update_LuongThucLinh();
	list.addTail(b);
}

void quest1(listnode list) {
	cout << "danh sach luong: " << endl;
	list.listSalary();
}

void quest2(listnode list) {
	cout << "Nhap ma so cua nhan vien can tim:" << endl;
	string tmp;
	cin.ignore();
	getline(cin, tmp);
	cout << "Thong tin nhan vien can tim: ";
	member *p = list.find(tmp);
	if (p == NULL) 
		cout << "Khong co!" << endl;
	else {
		writenode(p);
	}
}

listnode list;

int n = 3; // cho danh sach co n nhan vien 
int main() {
	
	for (int i = 1; i <= n; ++i) {
		cout << "Nhap thong tin nhan vien thu " << i << ": " << endl;
		enter(list);
	}
	
	cout << "Bang chon: " << endl;
	cout << "0: Thoat" << endl;
	cout << "1: Xem bang luong" << endl;
	cout << "2: Tim thong tin cua mot nhan vien" << endl;
	cout << "-----------------------------------------" << endl;
	int choose;
	while (1) {
		cout << "Moi chon: "; cin >> choose;
		switch (choose) {
			case 1: quest1(list); break;
			case 2: quest2(list); break;
			default: 
				return 0;
		}
		cout << endl;
	}
	 
	return 0;
} 
