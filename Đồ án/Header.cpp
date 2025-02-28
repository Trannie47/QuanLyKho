#include "Header.h"
// Để Phân biệt số hoặc chữ 
void Nhap(string Chuoi, string& a) {
	cout << Chuoi;
	getline(cin, a);
}
// Viết dùng cho hàm nhập số nguyen
void Nhap(string Chuoi, int& a)
{
	cout << Chuoi;
	cin >> a;
	cin.ignore();
}
// viet dung cho ham so thuc
void Nhap(string Chuoi, double& a)
{
	cout << Chuoi;
	cin >> a;
	cin.ignore();
}
// Để Phân biệt chữ có giới hạn 
void Nhap(string Chuoi, string& a, int gioiHan) {
	do {
		cout << Chuoi;
		getline(cin, a);

		if (a.length() > gioiHan) {
			cout << "Chuoi nhap vao vuot qua gioi han " << gioiHan << " ky tu. Vui long nhap lai." << endl;
		}
	} while (a.length() > gioiHan); // Lặp lại cho đến khi nhập đúng
}
// phan biet gioi han nguyen max
void Nhap(string Chuoi, int& a, int gioiHanMax) {
	do {
		cout << Chuoi;
		cin >> a;

		// Kiểm tra giá trị
		if (a > gioiHanMax) {
			cout << "Gia tri so nhap vao vuot qua gioi han " << gioiHanMax << ". Vui long nhap lai." << endl;
			cout << " Gioi han nhap la  " << gioiHanMax<<endl;
		}

		cin.ignore(); // Xóa bộ đệm sau khi nhập số
	} while (a > gioiHanMax); // Lặp lại cho đến khi nhập đúng
}
//phan biet gioi han nho nhat la lon nhat
void Nhap(string Chuoi, int& a, int gioiHanMin, int gioiHanMax)
{
	do {
		cout << Chuoi;
		cin >> a;

		// Kiểm tra giá trị
		if (a < gioiHanMin || a > gioiHanMax) {
			cout << "Gia tri nhap vao phai trong khoang [" << gioiHanMin << ", " << gioiHanMax << "]. Vui long nhap lai." << endl;
		}

		cin.ignore(); // Xóa bộ đệm sau khi nhập số
	} while (a < gioiHanMin || a > gioiHanMax); // Lặp lại cho đến khi nhập đúng
	

}
void Nhap(string Chuoi, double & a, double gioiHanMax) {
	do {
		cout << Chuoi;
		cin >> a;

		// Kiểm tra giá trị
		if (a > gioiHanMax) {
			cout << "Gia tri so nhap vao vuot qua gioi han " << gioiHanMax << ". Vui long nhap lai." << endl;
			cout << " Gioi han nhap la  " << gioiHanMax << endl;
		}
		cin.ignore(); // Xóa bộ đệm sau khi nhập số
	} while (a > gioiHanMax); // Lặp lại cho đến khi nhập đúng
}
// Kiểm tra năm nhuận
bool isNamNhuan(int year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}
// Kiểm tra tính hợp lệ của ngày
bool kiemtrangay(int ngay, int thang, int nam) {
	// Kiểm tra năm hợp lệ
	if (nam <= 0)
		return false;

	// Kiểm tra tháng hợp lệ
	if (thang < 1 || thang > 12)
		return false;

	// Số ngày trong từng tháng
	int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Kiểm tra năm nhuận
	if (isNamNhuan(nam) && thang == 2)
		ngayTrongThang[1] = 29;

	// Kiểm tra ngày hợp lệ
	if (ngay < 1 || ngay > ngayTrongThang[thang - 1])
		return false;

	return true;
}
void NhapNgay(string Chuoi, string& a)
{
	int ngay, thang, nam;
	do {
		cout << "Nhap ngay "<< Chuoi <<": ";
		cin >> ngay;
		cout << "Nhap thang "<< Chuoi <<": ";
		cin >> thang;
		cout << "Nhap nam " << Chuoi << ": ";
		cin >> nam;
		
		if (kiemtrangay(ngay, thang, nam) == false) {
			cout << "Ngay thang nam khong hop le!" << endl;
		}
		cin.ignore();
		
	} while (kiemtrangay(ngay, thang, nam) == false);
	
	a = (ngay < 10 ? "0" : "") + to_string(ngay) +
		(thang < 10 ? "0" : "") + to_string(thang) +
		to_string(nam);

}

void XuatNgay(string a)
{
	string tam = a;

	tam.insert(2, "/"); //thêm vào chuỗi ddmmyyyy thành dd/mmyyyy
	tam.insert(5, "/"); //thêm vào chuỗi dd/mmyyyy thành dd/mm/yyyy
	cout << tam;
}

string XuatNgayString(string a) {
	string tam = a;

	tam.insert(2, "/"); //thêm vào chuỗi ddmmyyyy thành dd/mmyyyy
	tam.insert(5, "/"); //thêm vào chuỗi dd/mmyyyy thành dd/mm/yyyy
	return tam;
}

bool IsContinue(string a,bool next)
{
	if (next ==  true) return false;
	int isNumberContinue = 0 ;
	do {
		if (isNumberContinue != 0 && isNumberContinue != 1) {
			cout << "Chi Duoc Nhap 0 va 1 thui nhe " << endl;
		}
		cout << "Ban Co Muon Tiep Tuc " + a + " KHONG ?" << endl;
		cout << "1. Tiep Tuc" << endl;
		cout << "0. Dung Lai" << endl;
		cout << "Xin moi ban chon : ";
		cin >> isNumberContinue;
		cout << endl;
		cin.ignore(); // Xóa bộ đệm sau khi nhập số
		system("cls");
		return (isNumberContinue == 1 ? true : false);
	} while (isNumberContinue != 0 && isNumberContinue != 1);
	
}

string LayChuoiNgayHienTai()
{

	//Lấy thời gian hiện tại
	time_t now = time(nullptr);
	tm local_time; // Khai báo biến tm

	// Sử dụng localtime_s để chuyển đổi
	localtime_s(&local_time, &now);

	/*string capture = "hello";*/
	// Xuất ngày hiện tại theo định dạng ddmmyyyy
	string capture =
		(local_time.tm_mday < 10 ? "0" : "") + to_string(local_time.tm_mday) +
		(local_time.tm_mon + 1 < 10 ? "0" : "") + to_string(local_time.tm_mon + 1) +
		to_string(1900 + local_time.tm_year);

	return capture;
	
}
//
//void hienThiMenu() {
//	cout << "\n***************** LUA CHON ****************" << endl;
//	cout << "1. Nhap thong tin phan loai thuoc" << endl;
//	cout << "2. Nhap thong tin thuoc" << endl;
//	cout << "3. Nhap thong tin nhap kho" << endl;
//	cout << "4. Nhap thong tin xuat kho" << endl;
//	cout << "5. Xuat thong tin phan loai thuoc" << endl;
//	cout << "6. Xuat thong tin thuoc" << endl;
//	cout << "7. Xuat thong tin nhap kho" << endl;
//	cout << "8. Xuat thong tin nha cung cap" << endl;
//	cout << "9. Xuat thong tin khach hang" << endl;
//	cout << "10. Nhap ngay giao hang" << endl;
//	cout << "11. Doc du lieu tu file phan loai thuoc" << endl;
//	cout << "12. Tim kiem phan loai thuoc theo ma" << endl;
//	cout << "13. Xoa phan loai thuoc (Phan loai dau)" << endl;
//	cout << "0. Thoat" << endl;
//}

void nhapBangPhanLoai(BANGPHANLOAI &a )
{
	Nhap("\n Nhap ten phan loai thuoc : ", a.TenPhanLoai,500);
	Nhap("\n Nhap ghi chu cua loai thuoc  : ", a.GhiChu);
}

void nhapBangThuoc(BANGTHUOC& a, NODEBANGPHANLOAIPTR list)
{
	Nhap("\n Nhap ten thuoc : ", a.TenThuoc, 500);
	a.PhanLoai =LayPhanTuBanPhanLoaiTaiViTri(list);
	Nhap("\n Nhap gia ban : ", a.GiaBan);
	Nhap("\n Nhap nha san xuat : ", a.NhaSanXuat);
	Nhap("\n Nhap so luong ton kho : ", a.SoLuongTonKho);
}

void nhapBangNhapKho(PHIEUNHAPXUAT& a, NODEBANGNHACUNCAPPTR list)
{
	a.NhapXuat = true;
	a.NhaCungCap = LayPhanTuNhaCungCapTaiViTri(list);
	NhapNgay("Nhap kho", a.NgayNhapXuat);
}
void nhapBangXuatKho(PHIEUNHAPXUAT& a, NODEBANGKHACHHANGPTR list)
{
	a.NhapXuat = false;
	a.KhachHang = LayPhanTuKhachHangTaiViTri(list);
	NhapNgay("xuat kho", a.NgayNhapXuat);
	
}
void nhapChiTietNhapXuat(BANGCHITIETNHAPXUAT& a, NODEBANGTHUOCPTR& listThuoc)
{
	if (a.NhapXuat) {
		if(!CapNhatSoLuongThuoc(listThuoc, a.Thuoc.MaThuoc, (-1) * a.SoLuong)) return ;
	}
	else {
		CapNhatSoLuongThuoc(listThuoc, a.Thuoc.MaThuoc,  a.SoLuong);
	}
	a.Thuoc = LayPhanTuBangThuocTaiViTri(listThuoc);
	Nhap("\n Nhap so Luong thuoc : ", a.SoLuong);
	Nhap("\n Nhap so Han Su Dung : ", a.HanSuDung);
	if (!a.NhapXuat) {
		if (!CapNhatSoLuongThuoc(listThuoc, a.Thuoc.MaThuoc, (-1) * a.SoLuong)) return;
	}
	else {
		CapNhatSoLuongThuoc(listThuoc, a.Thuoc.MaThuoc, a.SoLuong);
	}
}

void nhapNhaCungCap(BANGNHACUNGCAP& a)
{
	Nhap("\n Nhap ten nha cung cap thuoc : ",a.TenNCC);
	Nhap("\n Nhap dia chi nha cung cap thuoc : ",a.DiaChiNCC);
	Nhap("\n Nhap so dien thoai nha cung cap thuoc : ",a.SoDienThoaiNCC);
}

void nhapKhachHang(BANGKHACHHANG& a)
{
	Nhap("\n Nhap ten khach hang: ",a.TenKhachHang);
	Nhap("\n Nhap dia chi khach hang  : ",a.DiaChiKhachHang);
	Nhap("\n Nhap so dien thoai khach hang : ",a.SoDienThoaiKhachHang);	
}
void nhapBangPhanLoai(BANGPHANLOAI& a, NODEBANGPHANLOAIPTR list)
{
	bool lanDau = false;
	do{
		if (lanDau == true) {
			cout << "Ma Phan Loai Da Ton Tai" << endl;
		}
		Nhap("\n Nhap ma phan loai thuoc : ", a.MaPhanLoai, 10);
		lanDau = true;
	} while (kiemTra_TrungMa(list, a.MaPhanLoai));
	Nhap("\n Nhap ten phan loai thuoc : ", a.TenPhanLoai, 50);
	Nhap("\n Nhap ten Ghi Chu : ", a.GhiChu, 100);
	a.isDelete = false;
}
void nhapBangThuoc(BANGTHUOC& a, NODEBANGTHUOCPTR list, NODEBANGPHANLOAIPTR listPL) {
	bool lanDau = false;
	do {
		if (lanDau == true) {
			cout << "Ma thuoc Da Ton Tai" << endl;
		}
		Nhap("\n Nhap ma thuoc : ", a.MaThuoc, 10);
		lanDau = true;
	} while (kiemTra_TrungMa(list, a.MaThuoc));

	Nhap("\n Nhap ten thuoc : ", a.TenThuoc, 500);
	a.PhanLoai = LayPhanTuBanPhanLoaiTaiViTri(listPL);
	Nhap("\n Nhap gia ban : ", a.GiaBan);
	Nhap("\n Nhap nha san xuat : ", a.NhaSanXuat);
	Nhap("\n Nhap so luong ton kho : ", a.SoLuongTonKho);

	// Thêm thuộc tính isDelete và đặt mặc định là false (chưa bị xóa)
	a.isDelete = false;
}

void nhapBangNhapKho(PHIEUNHAPXUAT& a, NODEPHIEUNHAPXUATPTR listCT, NODEBANGNHACUNCAPPTR listcc)
{
	a.NhapXuat = true;
	a.KhachHang.MaKhachHang = "";
	a.MaNhapXuat = "";
	// Cái này sẽ dùng hàm riêng chứ không làm như vậy được 
	string ngayHienTaiStr = "N" + LayChuoiNgayHienTai();
	string maPhieuNhapHienTai = "";
	
	//Nhap("\n Nhap ma nhap vao kho  : ", a.MaNhapXuat, 10);  // cái này sẽ chuyển về mảng tự sinh tự động 
	NODEPHIEUNHAPXUATPTR p = listCT;
	while (p != NULL) {
		if (p->data.MaNhapXuat.find(ngayHienTaiStr) != string::npos) {
			string maNgayDanhDonTruoc = p->data.MaNhapXuat;
			string tam = maNgayDanhDonTruoc.substr(10,4); // Ví Dụ Nhập sẽ là N03112024 Nếu là đơn đầu tiên sẽ là N031120240001 Nếu là Đơn thứ 2 là N031120240002
			if (tam != "") {
				stringstream ss;
				int maDanhDonHienTai = stoi(tam)+1;
				ss << setw(4) << setfill('0') << maDanhDonHienTai;
				a.MaNhapXuat = ngayHienTaiStr + ss.str();
			}
			break;
		}
		p = p->next;
	}

	if (a.MaNhapXuat == "") {
		a.MaNhapXuat = ngayHienTaiStr +"0001";
	}
	a.NhaCungCap = LayPhanTuNhaCungCapTaiViTri(listcc);
	NhapNgay("Nhap kho", a.NgayNhapXuat);
	a.isDelete = false;
}

void nhapNhaCungCap(BANGNHACUNGCAP& a, NODEBANGNHACUNCAPPTR list) {
	bool lanDau = false;
	do {
		if (lanDau == true) {
			cout << "Ma nha cung cap Da Ton Tai" << endl;
		}
		Nhap("\n Nhap ma nha cung cap thuoc : ", a.MaNCC);
		lanDau = true;
	} while (kiemTra_TrungMa(list, a.MaNCC));

	Nhap("\n Nhap ten nha cung cap thuoc : ", a.TenNCC);
	Nhap("\n Nhap dia chi nha cung cap thuoc : ", a.DiaChiNCC);
	Nhap("\n Nhap so dien thoai nha cung cap thuoc : ", a.SoDienThoaiNCC);

	a.isDelete = false;
}

void nhapBangXuatKho(PHIEUNHAPXUAT& a, NODEPHIEUNHAPXUATPTR listCT, NODEBANGKHACHHANGPTR listkh) {
	a.NhapXuat = false;
	a.NhaCungCap.MaNCC = "";

	string ngayHienTaiStr = "X" + LayChuoiNgayHienTai();
	a.MaNhapXuat = "";

	NODEPHIEUNHAPXUATPTR p = listCT;
	while (p != NULL) {
		if (p->data.MaNhapXuat.find(ngayHienTaiStr) != string::npos){
			string maNgayDanhDonTruoc = p->data.MaNhapXuat;
			// Ví Dụ Nhập sẽ là N03112024 Nếu là đơn đầu tiên sẽ là N031120240001 Nếu là Đơn thứ 2 là N031120240002
			string tam = maNgayDanhDonTruoc.substr(10,4); 
			if (tam != "") {
				stringstream ss;
				int maDanhDonHienTai = stoi(tam) + 1;
				ss << setw(4) << setfill('0') << maDanhDonHienTai;
				a.MaNhapXuat = ngayHienTaiStr + ss.str();
			}
			break;
		}
		p = p->next;
	}
	
	if (a.MaNhapXuat == "") {
		a.MaNhapXuat = ngayHienTaiStr + "0001";
	}
	a.KhachHang = LayPhanTuKhachHangTaiViTri(listkh);

	NhapNgay("Xuat kho: ", a.NgayNhapXuat);
	a.isDelete = false;
}

void nhapKhachHang(BANGKHACHHANG& a, NODEBANGKHACHHANGPTR list) {
	bool lanDau = false;
	do {
		if (lanDau == true) {
			cout << "Ma khach hang Da Ton Tai" << endl;
		}
		Nhap("\n Nhap ma khach hang : ", a.MaKhachHang);
		lanDau = true;
	} while (kiemTra_TrungMa(list, a.MaKhachHang));

	Nhap("\n Nhap ten khach hang: ", a.TenKhachHang);
	Nhap("\n Nhap dia chi khach hang  : ", a.DiaChiKhachHang);
	Nhap("\n Nhap so dien thoai khach hang : ", a.SoDienThoaiKhachHang);

	// false (khách hàng chưa bị xóa)
	a.isDelete = false;
}


void nhapChiTietNhapXuat(BANGCHITIETNHAPXUAT& a, NODEBANGCHITIETNHAPXUATPTR list, PHIEUNHAPXUAT phieuNhapXuat, NODEBANGTHUOCPTR& listThuoc)
{
	string matam = phieuNhapXuat.MaNhapXuat;
	a.NhapXuat = phieuNhapXuat.NhapXuat;
	string stt = "";
	NODEBANGCHITIETNHAPXUATPTR p =  list;
	a.MaChiTietNhapXuat = "";
	while (p != NULL) {
		string tam ="";
		if (p->data.MaChiTietNhapXuat.find(matam) != string::npos) {
			// Ví Dụ Mã Nhập sẽ là N03112024001 Nếu là đơn đầu tiên sẽ là N031120240001001 Nếu là Đơn thứ 2 là N031120240001002
			tam = p->data.MaChiTietNhapXuat.substr(14, 3); 
			if (tam != "") {
				stringstream ss;
				int maDanhDonHienTai = stoi(tam) + 1;
				ss << setw(4) << setfill('0') << maDanhDonHienTai;
				a.MaChiTietNhapXuat = matam + ss.str();
			}
			break;
		}
		p = p->next;
	}
	if (a.MaChiTietNhapXuat == "") {
		a.MaChiTietNhapXuat = matam + "0001";
	}
	a.phieuNhapXuat = phieuNhapXuat;
	
	a.Thuoc = LayPhanTuBangThuocTaiViTri(listThuoc);
	Nhap("So Luong thuoc: ", a.SoLuong);
	Nhap("Han Su dung : ", a.HanSuDung);
	a.isDelete = false;
	if (a.NhapXuat) {
		CapNhatSoLuongThuoc(listThuoc,a.Thuoc.MaThuoc, a.SoLuong);
	}
	else {
		CapNhatSoLuongThuoc(listThuoc, a.Thuoc.MaThuoc,(-1)* a.SoLuong);
	}
}


// hàm xuất dọc 
void xuatBangPhanLoai(BANGPHANLOAI a,int i) {
	if (i != 0) {
		cout << "So Thu Tu: " << i << endl;
	}
	cout << "Ma Phan Loai: " << a.MaPhanLoai << endl;
	cout << "Ten Phan Loai: " << a.TenPhanLoai << endl;
	if (a.GhiChu != "")
	{
		cout << "Ghi chu loai Thuoc: " << a.GhiChu << endl;
	}
	cout << endl;
}
void xuatBangPhanLoaiNgang(BANGPHANLOAI a,int i) 
{
	if (i == 0) {
		cout << left << setw(20) << a.MaPhanLoai
			<< setw(40) << a.TenPhanLoai
			<< setw(60) << (a.GhiChu != "" ? a.GhiChu : "") << endl;
	}
	else {
		cout << left << setw(5) << i <<  setw(20) << a.MaPhanLoai
			<< setw(40) << a.TenPhanLoai
			<< setw(60) << (a.GhiChu != "" ? a.GhiChu : "") << endl;

	}
	
}


void xuatBangThuoc(BANGTHUOC a, int i ) {
	if (i != 0) {
		cout << "STT: " << i << endl;
	}
	cout << "Ma Thuoc: " << a.MaThuoc << endl;
	cout << "Ten Thuoc: " << a.TenThuoc << endl;
	cout << "Ma Phan Loai: " << a.PhanLoai.MaPhanLoai << endl;
	cout << "So Luong Ton Kho: " << a.SoLuongTonKho << endl;
	cout << "Nha San Xuat: " << a.NhaSanXuat << endl;
	cout << "Gia Ban: " << a.GiaBan << endl;
}
void xuatBangThuocNgang(BANGTHUOC a, int i)
{
	if (i != 0) {
		cout << left << setw(5) << i;
	}

	cout << left << setw(15) << a.MaThuoc
		<< setw(25) << a.TenThuoc
		<< setw(20) << a.PhanLoai.MaPhanLoai
		<< setw(20) <<a.SoLuongTonKho 
		<< setw(30)<<a.NhaSanXuat
		<< setw(10)<<a.GiaBan << endl;
}

void xuatBangNhapKho(PHIEUNHAPXUAT a, int i) {
	cout << "Ma Nhap: " << a.MaNhapXuat << endl;
	cout << (a.NhapXuat?"Ngay Nhap: ":"Ngay Xuat: ") << XuatNgayString(a.NgayNhapXuat) << endl;
	if (a.NhapXuat == true) {
		xuatNhaCungCap(a.NhaCungCap);
	}
	else {
		xuatKhachHang(a.KhachHang);
		
	}
	cout << "Nhap Xuat: " << (!a.NhapXuat ? "Xuat" : "Nhap") << endl;
}
void xuatBangNhapKhoNgang(PHIEUNHAPXUAT a,int i)
{
	if (i != 0) {
		cout << left << setw(5) << i
			<< setw(20) << a.MaNhapXuat
			<< setw(40) << XuatNgayString(a.NgayNhapXuat)
			<< setw(60) << a.NhaCungCap.TenNCC
			<< setw(20) << (!a.NhapXuat ? "Xuat" : "Nhap") << endl;
	}
	else {
		cout << left << setw(20) << a.MaNhapXuat
			<< setw(40) << XuatNgayString(a.NgayNhapXuat)
			<< setw(60) << a.NhaCungCap.TenNCC
			<< setw(20) << (!a.NhapXuat ? "Xuat" : "Nhap") << endl;
	}
}

void xuatBangXuatKho(PHIEUNHAPXUAT a,int i) {
	if (i != 0) {
		cout << "So Thu Tu: " << i << endl;
	}
	cout << "Ma Xuat: " << a.MaNhapXuat << endl;
	cout << "Ngay Xuat: " << XuatNgayString(a.NgayNhapXuat) << endl;
	cout << "Ma Khach Hang: " << a.KhachHang.MaKhachHang << endl;
	cout << "NhapXuat: " << (!a.NhapXuat ? "Xuat" : "Nhap") << endl;
}
void xuatBangXuatKhoNgang(PHIEUNHAPXUAT a,int i )
{
	if (i != 0) {
		cout << left << setw(5) << i
			<< setw(20) << a.MaNhapXuat
			<< setw(40) << XuatNgayString(a.NgayNhapXuat)
			<< setw(60) << a.KhachHang.TenKhachHang
			<< setw(20) << (!a.NhapXuat ? "Xuat" : "Nhap") << endl;
	}
	else {
		cout << left << setw(20) << a.MaNhapXuat
			<< setw(40) << XuatNgayString(a.NgayNhapXuat)
			<< setw(60) << a.KhachHang.TenKhachHang
			<< setw(20) << (!a.NhapXuat ? "Xuat" : "Nhap") << endl;
	}
}

void xuatNhaCungCap(BANGNHACUNGCAP a, int i) {
	if (i != 0) {
		cout << "STT: " << i << endl;
	}
	cout << "Ma NCC: " << a.MaNCC << endl;
	cout << "Ten NCC: " << a.TenNCC << endl;
	cout << "Dia Chi NCC: " << a.DiaChiNCC << endl;
	cout << "So Dien Thoai NCC: " << a.SoDienThoaiNCC << endl;
}
void xuatNhaCungCapNgang(BANGNHACUNGCAP a, int i)
{
	if (i != 0) {
		cout << left << setw(5) << i;  // In số thứ tự chỉ khi i != 0
	}
	cout << left << setw(10) << a.MaNCC
		<< setw(30) << a.TenNCC
		<< setw(50) << a.DiaChiNCC
		<< setw(13) << a.SoDienThoaiNCC << endl;
}

void xuatKhachHang(BANGKHACHHANG a, int i ) {
	if (i != 0) {
		cout << "STT: " << i << endl;
	}
	cout << "Ma Khach Hang: " << a.MaKhachHang << endl;
	cout << "Ten Khach Hang: " << a.TenKhachHang << endl;
	cout << "Dia Chi Khach Hang: " << a.DiaChiKhachHang << endl;
	cout << "So Dien Thoai Khach Hang: " << a.SoDienThoaiKhachHang << endl;
}
void xuatKhachHangNgang(BANGKHACHHANG a, int i)
{
	if (i != 0) {
		cout << left << setw(5) << i;  // In số thứ tự chỉ khi i != 0
	}

	cout << setw(10) << a.MaKhachHang
		<< setw(30) << a.TenKhachHang
		<< setw(50) << a.DiaChiKhachHang
		<< setw(13) << a.SoDienThoaiKhachHang << endl;

}



void XuatChiTietNhapXuat(BANGCHITIETNHAPXUAT a,int i)
{
	cout << "Ma Chi Tiet Nhap Xuat:" << a.MaChiTietNhapXuat << endl;
	cout << "Han Su Dung:" << a.HanSuDung << endl;
	cout << "So Luong:" << a.SoLuong << endl;
	cout << "Ten Phan Loai Thuoc:" << a.Thuoc.PhanLoai.TenPhanLoai << endl;
	cout << "Ten Thuoc:" << a.Thuoc.TenThuoc << endl;

	
}

void XuatChiTietNhapXuatNgang(BANGCHITIETNHAPXUAT a, int i)
{
	if (i != 0) {
		cout << left << setw(5) << i;  // In số thứ tự chỉ khi i != 0
	}

	cout << setw(20) << a.MaChiTietNhapXuat
		<< setw(15) << a.HanSuDung
		<< setw(10) << a.SoLuong
		<< setw(30) << a.Thuoc.PhanLoai.TenPhanLoai
		<< setw(30) << a.Thuoc.TenThuoc << endl;
}


// bảng mã phân loại 
void khoiTaoBANGPHANLOAI(NODEBANGPHANLOAIPTR& list)
{
	list = NULL;
}

int isEmpty(NODEBANGPHANLOAIPTR list)
{
	return(list == NULL ? 1 : 0);
}

void giaiPhong(NODEBANGPHANLOAIPTR& list)
{
	NODEBANGPHANLOAIPTR p = list;
	while (p != NULL) {
		list = list->next;
		delete p;
		p = list;
	}
}

NODEBANGPHANLOAIPTR tao_Node_BangPhanLoai(BANGPHANLOAI x)
{
	NODEBANGPHANLOAIPTR p;
	p = new LISTBANGPHANLOAI;
	p->data = x;
	p->next = NULL;
	return p;
}

NODEBANGPHANLOAIPTR them_Dau(NODEBANGPHANLOAIPTR& list, BANGPHANLOAI x)
{
	NODEBANGPHANLOAIPTR p = tao_Node_BangPhanLoai(x);
	p->next = list;
	list = p;
	return p;
}

bool kiemTra_TrungMa(NODEBANGPHANLOAIPTR list, string ma)
{
	NODEBANGPHANLOAIPTR p = list;
	while (p != NULL) {
		if (p->data.MaPhanLoai == ma)
			return true;
		p = p->next;
	}
	return false;
}

// thêm phần tử cuối
NODEBANGPHANLOAIPTR them_Cuoi(NODEBANGPHANLOAIPTR& list, BANGPHANLOAI x)
{
	NODEBANGPHANLOAIPTR p;
	p = tao_Node_BangPhanLoai(x);
	if (list == NULL)
		list = p;
	else {
		NODEBANGPHANLOAIPTR q = list;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	return p; 
}

void nhap_DSPL(NODEBANGPHANLOAIPTR& list) {
	khoiTaoBANGPHANLOAI(list);             // Khoi tao danh sach lien ket
	BANGPHANLOAI x;            // Khai bao bien luu thong tin phan loai
	

	do {
		nhapBangPhanLoai(x);   // Nhap thong tin cho bang phan loai
		them_Cuoi(list, x);    // Them phan tu vao cuoi danh sach

		
	} while (IsContinue());            // Tiep tuc cho den khi nguoi dung chon dung
}
 //xuất cột dọc 
void xuat_DSPLdoc(NODEBANGPHANLOAIPTR list, bool stt ) {
	NODEBANGPHANLOAIPTR p = list;
	int i = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {  // Kiểm tra isDelete
			if (stt) {
				xuatBangPhanLoai(p->data,i);  // Gọi hàm xuất từng phần tử
			}
			else {
				xuatBangPhanLoai(p->data);
			}
		}
		i++;
		p = p->next;
	}
}

// xuất cột ngang
void xuat_DSPLngang(NODEBANGPHANLOAIPTR list, bool stt) {
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	if (stt == true) {
		cout << left << setw(5) << "STT" << setw(20) << "MaPhanLoai"
			<< setw(40) << "TenPhanLoai "
			<< setw(60) << "GhiChu" << endl;
		cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;
	} else {
		cout << left << setw(20) << "MaPhanLoai"
			<< setw(40) << "TenPhanLoai "
			<< setw(60) << "GhiChu" << endl;
		cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;
	}
	int i = 1;
	NODEBANGPHANLOAIPTR p = list;
	while (p != NULL) {
		if (!p->data.isDelete) {  // Kiểm tra isDelete
			if (stt == true)
				xuatBangPhanLoaiNgang(p->data,i);  // Gọi hàm xuất từng phần tử
			else
				xuatBangPhanLoaiNgang(p->data);
			i++;
		}
		p = p->next;  // Di chuyển đến phần tử tiếp theo
	}
}

bool docFilePhanLoai(NODEBANGPHANLOAIPTR& list) {
	const string filename = "phanloaithuoc.txt"; // Định nghĩa tên tệp

	// Mở tệp tin để đọc
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << endl;
		return false; // Trả về false nếu không mở được tệp
	}
	BANGPHANLOAI ttdoc; // Khai báo một biến để lưu thông tin đọc được
	string docdong; // Biến tạm để đọc cả dòng

	while (getline(file, docdong)) { // Đọc từng dòng từ tệp
		// Kiểm tra nếu dòng bắt đầu và kết thúc bằng dấu ngoặc đơn
		if (docdong.front() == '(' && docdong.back() == ')') {
			// Xóa dấu ngoặc
			docdong = docdong.substr(1, docdong.size() - 2);
			//(001`Thuoc khang sinh`Dieu tri nhiem khuan`0)
			int pos1 = docdong.find('`'); // Tìm vị trí của dấu ` đầu tiên
			int pos2 = docdong.find('`', pos1 + 1); // Tìm vị trí của dấu ` thứ hai
			int pos3 = docdong.find('`', pos2 + 1); // Tìm vị trí của dấu ` thứ ba

			if (pos3 > pos2 && pos2 > pos1 && pos1 >= 0) { // Kiểm tra nếu các dấu ` đều được tìm thấy
				ttdoc.MaPhanLoai = docdong.substr(0, pos1); // Lấy MaPhanLoai
				ttdoc.TenPhanLoai = docdong.substr(pos1 + 1, pos2 - pos1 - 1); // Lấy TenPhanLoai
				ttdoc.GhiChu = docdong.substr(pos2 + 1, pos3 - pos2 - 1); // Lấy GhiChu

				// Xác định isDelete
				string isDeleteStr = docdong.substr(pos3 + 1); // Lấy giá trị isDelete
				ttdoc.isDelete = (isDeleteStr == "true"); // Chuyển sang bool, "1" là true, "0" là false

				them_Cuoi(list, ttdoc); // Thêm vào danh sách liên kết
			}
		}
	}

	file.close(); // Đóng tệp sau khi hoàn tất
	return true; // Trả về true nếu thành công
}


bool ghiFilePhanLoai(NODEBANGPHANLOAIPTR list) {
	const string filename = "phanloaithuoc.txt";

	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << " de ghi du lieu" << endl;
		return false; // Trả về false nếu không mở được tệp
	}

	NODEBANGPHANLOAIPTR duyetptht = list;
	while (duyetptht != nullptr) {
		// Ghi dữ liệu theo định dạng (MaPhanLoai`TenPhanLoai`GhiChu)
		file << "(" << duyetptht->data.MaPhanLoai << "`"
			<< duyetptht->data.TenPhanLoai << "`"
			<< duyetptht->data.GhiChu <<"`" 
			<< (duyetptht->data.isDelete ? "true" : "false") << ")" << endl;
		duyetptht = duyetptht->next;
	}

	file.close();
	return true;
}
NODEBANGPHANLOAIPTR tim_Kiem(NODEBANGPHANLOAIPTR& list, BANGPHANLOAI x)
{
	NODEBANGPHANLOAIPTR p = list;
	while (p != NULL) {
		if (p->data.MaPhanLoai == x.MaPhanLoai)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void xoa_Dau(NODEBANGPHANLOAIPTR& list)
{
	NODEBANGPHANLOAIPTR p;
	if (list != NULL) {
		p = list;
		list = p->next;  // Chuyển đầu danh sách sang phần tử kế tiếp
        delete p;        // Xóa phần tử cũ
	}
}


void xoaPhanTuTaiViTriX(NODEBANGPHANLOAIPTR& list, int vitri, NODEBANGTHUOCPTR& listThuoc) {
	NODEBANGPHANLOAIPTR p = list;
	BANGPHANLOAI pl;
	int vitritaiphantu = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu)
			{
				p->data.isDelete = true;
				pl = p->data;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
	
	NODEBANGTHUOCPTR listThuocTam = listThuoc;
	while (listThuocTam != NULL) {
		if (listThuocTam->data.PhanLoai.MaPhanLoai.compare(pl.MaPhanLoai) == 0) {
			listThuocTam->data.isDelete = true;
			listThuocTam->data.PhanLoai = pl;
		}
		listThuocTam = listThuocTam->next;
	}
	
}

void suaPhanTuTaiViTriX(NODEBANGPHANLOAIPTR& list, int vitri, NODEBANGTHUOCPTR& listThuoc, NODEBANGCHITIETNHAPXUATPTR& listctnx) {
	NODEBANGPHANLOAIPTR p = list;
	BANGPHANLOAI pl;
	int vitritaiphantu = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {

			if (vitri == vitritaiphantu) {
				xuatBangPhanLoai(p->data);
				cout << "------------------------------------------" << endl;
				nhapBangPhanLoai(p->data);
				pl = p->data;
				break;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
	NODEBANGTHUOCPTR listThuocTam = listThuoc;
	while (listThuocTam != NULL) {
		if (listThuocTam->data.PhanLoai.MaPhanLoai.compare(pl.MaPhanLoai) == 0) {
			listThuocTam->data.PhanLoai = pl;
		}
		listThuocTam = listThuocTam->next;
	}
	NODEBANGCHITIETNHAPXUATPTR listctnxtam = listctnx;
	
	while (listctnxtam != NULL) {
		if (listctnxtam->data.Thuoc.PhanLoai.MaPhanLoai.compare(pl.MaPhanLoai) == 0) {
			listctnxtam->data.Thuoc.PhanLoai = pl;
		}
		listctnxtam = listctnxtam->next;
	}
}

int DemSoLuong(NODEBANGPHANLOAIPTR list) {
	NODEBANGPHANLOAIPTR p = list;
	int i = 0;
	while (p != NULL) {
		if (!p->data.isDelete) { // Chỉ đếm phần tử chưa bị đánh dấu xóa
			i++;
		}
		p = p->next;
	}
	return i;
}

BANGPHANLOAI LayPhanTuBanPhanLoaiTaiViTri(NODEBANGPHANLOAIPTR list) {
	xuat_DSPLngang(list,true);
	int vitri;
	cout << endl;
	Nhap("Vi Tri Phan Tu: ", vitri, 1, DemSoLuong(list));
	int vitritaiphantu = 1;
	NODEBANGPHANLOAIPTR p = list;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu) {
				return p->data;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}



//  bảng Nhà cung cấp
void khoiTaoBANGNHACUNCAP(NODEBANGNHACUNCAPPTR& list)
{ 
	list = NULL; 
}
int isEmpty(NODEBANGNHACUNCAPPTR list)
{ 
	return list == NULL ? 1 : 0;
}
void giaiPhong(NODEBANGNHACUNCAPPTR& list) {
	NODEBANGNHACUNCAPPTR p = list;
	while (p != NULL) {
		list = list->next;
		delete p;
		p = list;
	}
}
NODEBANGNHACUNCAPPTR tao_Node_BangNhaCungCap(BANGNHACUNGCAP x) {
	NODEBANGNHACUNCAPPTR p;
	p = new LISTBANGNHACUNGCAP;
	p->data = x;
	p->next = NULL;
	return p;
}
NODEBANGNHACUNCAPPTR them_Dau(NODEBANGNHACUNCAPPTR& list, BANGNHACUNGCAP x) {
	NODEBANGNHACUNCAPPTR p = tao_Node_BangNhaCungCap(x);
	p->next = list;
	list = p;
	return p;
}
bool kiemTra_TrungMa(NODEBANGNHACUNCAPPTR list, string ma)
{
	NODEBANGNHACUNCAPPTR p = list;
	while (p != NULL) {
		if (p->data.MaNCC == ma)
			return true;
		p = p->next;
	}
	return false;
}
NODEBANGNHACUNCAPPTR them_Cuoi(NODEBANGNHACUNCAPPTR& list, BANGNHACUNGCAP x) {
	NODEBANGNHACUNCAPPTR p = tao_Node_BangNhaCungCap(x);
	if (list == NULL) list = p;
	else {
		NODEBANGNHACUNCAPPTR q = list;
		while (q->next != NULL) q = q->next;
		q->next = p;
	}
	return p;
}


// Xuất danh sách nhà cung cấp dạng cột dọc
void xuat_DSNCCdoc(NODEBANGNHACUNCAPPTR list, bool stt) {
	NODEBANGNHACUNCAPPTR p = list;
	int i = 1;
	while (p != NULL) {
		// Kiểm tra isDelete, chỉ xuất khi isDelete là false
		if (!p->data.isDelete) {
			if (stt) {
				cout << "STT: " << i << endl;
			}
			xuatNhaCungCap(p->data);
			i++;
		}
		p = p->next;
	}
}

// Xuất danh sách nhà cung cấp dạng cột ngang
void xuat_DSNCCngang(NODEBANGNHACUNCAPPTR list, bool stt) {
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}

	// Tiêu đề cột
	if (stt) {
		cout << left << setw(5) << "STT" << setw(10) << "Ma NCC" 
			<< setw(30) << "Ten NCC" << setw(50) << "Dia chi" << setw(13)
			<< "SoDienThoaiNCC" << endl;
	}
	else {
		cout << left << setw(10) << "Ma NCC" << setw(30) << "Ten NCC" 
			<< setw(50) << "Dia chi" << setw(13)
			<< "SoDienThoaiNCC" << endl;
	}
	cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;

	NODEBANGNHACUNCAPPTR p = list;
	int i = 1;
	while (p != NULL) {
		// Kiểm tra isDelete, chỉ xuất khi isDelete là false
		if (!p->data.isDelete) {
			if (stt) {
				xuatNhaCungCapNgang(p->data, i); // Gọi hàm với số thứ tự
			} else {
				xuatNhaCungCapNgang(p->data,i); // Gọi hàm không có số thứ tự
			}
			i++;
		}
		p = p->next;
	}
}

bool docFileNCC(NODEBANGNHACUNCAPPTR& list) {
	const string filename = "nhacungcap.txt";
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << endl;
		return false;
	}

	BANGNHACUNGCAP ttdoc;
	string docdong;

	while (getline(file, docdong)) {
		// Kiểm tra nếu dòng có dạng '(...)'
		if (docdong.front() == '(' && docdong.back() == ')') {
			// Xóa dấu ngoặc đơn
			docdong = docdong.substr(1, docdong.size() - 2);

			// Tìm các dấu phân cách "`" giữa các phần dữ liệu
			int pos1 = docdong.find('`');
			int pos2 = docdong.find('`', pos1 + 1);
			int pos3 = docdong.find('`', pos2 + 1);
			int pos4 = docdong.find('`', pos3 + 1);

			// Kiểm tra nếu có đủ ba dấu phân cách
			if (pos4 > pos3 && pos3 > pos2 && pos2 > pos1 && pos1 >= 0) {
				// Lấy dữ liệu từ các phần trong dòng
				ttdoc.MaNCC = docdong.substr(0, pos1);
				ttdoc.TenNCC = docdong.substr(pos1 + 1, pos2 - pos1 - 1);
				ttdoc.DiaChiNCC = docdong.substr(pos2 + 1, pos3 - pos2 - 1);
				ttdoc.SoDienThoaiNCC = docdong.substr(pos3 + 1, pos4 - pos3 - 1);

				string isDeleteStr = docdong.substr(pos4 + 1); // Lấy giá trị isDelete
				ttdoc.isDelete = (isDeleteStr == "true");
				// Thêm vào danh sách
				them_Cuoi(list, ttdoc);
			}
		}
	}

	file.close();
	return true;
}


bool ghiFileNCC(NODEBANGNHACUNCAPPTR list) {
	const string filename = "nhacungcap.txt";
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << " de ghi du lieu" << endl;
		return false;
	}
	NODEBANGNHACUNCAPPTR duyet = list;
	while (duyet != nullptr) {
		file << "(" << duyet->data.MaNCC << "`"
			<< duyet->data.TenNCC << "`"
			<< duyet->data.DiaChiNCC << "`"
			<< duyet->data.SoDienThoaiNCC <<"`" <<
			(duyet->data.isDelete ? "true" : "false") << ")" << endl;
		duyet = duyet->next;
	}
	file.close();
	return true;
}

NODEBANGNHACUNCAPPTR tim_Kiem(NODEBANGNHACUNCAPPTR& list, BANGNHACUNGCAP x) {
	NODEBANGNHACUNCAPPTR p = list;
	while (p != NULL) {
		if (p->data.MaNCC == x.MaNCC) return p;
		p = p->next;
	}
	return NULL;
}
void xoa_Dau(NODEBANGNHACUNCAPPTR& list) {
	if (list != NULL) {
		NODEBANGNHACUNCAPPTR p = list;
		list = p->next;
		delete p;
	}
}
void xoaPhanTuTaiViTriX(NODEBANGNHACUNCAPPTR& list, int vitri) {
	NODEBANGNHACUNCAPPTR p = list;
	int vitritaiphantu = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu)
			{
				p->data.isDelete = true;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}

void suaPhanTuTaiViTriX(NODEBANGNHACUNCAPPTR& list, int vitri,NODEPHIEUNHAPXUATPTR &listnx, NODEBANGCHITIETNHAPXUATPTR& listctnx ) {
	NODEBANGNHACUNCAPPTR p = list;
	BANGNHACUNGCAP ncc;
	int vitritaiphantu = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu) {
				xuatNhaCungCap(p->data);
				ncc = p->data;
				cout << "----------Bang Thay Doi---------------" << endl;
				nhapNhaCungCap(ncc);
				p->data = ncc ;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
	

	NODEPHIEUNHAPXUATPTR listnxtam = listnx;
	while (listnxtam != NULL) {
			if (listnxtam->data.NhaCungCap.MaNCC.compare(ncc.MaNCC) == 0) {
				listnxtam->data.NhaCungCap = ncc;
				
			}
			
		
		listnxtam = listnxtam->next;
	}
	

	NODEBANGCHITIETNHAPXUATPTR listctnxtam = listctnx;
	while (listctnxtam != NULL) {
		if (listctnxtam->data.phieuNhapXuat.NhaCungCap.MaNCC.compare(ncc.MaNCC) == 0) {
			listctnxtam->data.phieuNhapXuat.NhaCungCap = ncc;
		}
		listctnxtam = listctnxtam->next;
	}
	
	
}

int DemSoLuong(NODEBANGNHACUNCAPPTR list) {
	NODEBANGNHACUNCAPPTR p = list;
	int i = 0;
	while (p != NULL) {
		if (!p->data.isDelete) {
			i++;
		}
		p = p->next;
	}
	return i;
}
BANGNHACUNGCAP LayPhanTuNhaCungCapTaiViTri(NODEBANGNHACUNCAPPTR list) {
	xuat_DSNCCngang(list,true);
	int vitri;
	cout << endl;
	Nhap("Vi Tri Phan Tu: ", vitri, 1, DemSoLuong(list));
	int vitritaiphantu = 1;
	NODEBANGNHACUNCAPPTR p = list;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu) {
				return p->data;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}

// Bảng khách hàng
void khoiTaoBANGKHACHHANG(NODEBANGKHACHHANGPTR& list) {
	list = NULL;
}

int isEmpty(NODEBANGKHACHHANGPTR list) {
	return (list == NULL ? 1 : 0);
}

void giaiPhong(NODEBANGKHACHHANGPTR& list) {
	NODEBANGKHACHHANGPTR p = list;
	while (p != NULL) {
		list = list->next;
		delete p;
		p = list;
	}
}

NODEBANGKHACHHANGPTR tao_Node_BangKhachHang(BANGKHACHHANG x) {
	NODEBANGKHACHHANGPTR p = new LISTBANGKHACHHANG;
	p->data = x;
	p->next = NULL;
	return p;
}

NODEBANGKHACHHANGPTR them_Dau(NODEBANGKHACHHANGPTR& list, BANGKHACHHANG x) {
	NODEBANGKHACHHANGPTR p = tao_Node_BangKhachHang(x);
	p->next = list;
	list = p;
	return p;
}

bool kiemTra_TrungMa(NODEBANGKHACHHANGPTR list, string ma) {
	NODEBANGKHACHHANGPTR p = list;
	while (p != NULL) {
		if (p->data.MaKhachHang == ma)
			return true;
		p = p->next;
	}
	return false;
}

NODEBANGKHACHHANGPTR them_Cuoi(NODEBANGKHACHHANGPTR& list, BANGKHACHHANG x) {
	NODEBANGKHACHHANGPTR p = tao_Node_BangKhachHang(x);
	if (list == NULL)
		list = p;
	else {
		NODEBANGKHACHHANGPTR q = list;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	return p;
}

void nhap_DSKH(NODEBANGKHACHHANGPTR& list) {
	khoiTaoBANGKHACHHANG(list);
	BANGKHACHHANG x;
	bool isContinue;

	do {
		nhapKhachHang(x);
		them_Dau(list, x);

	} while (IsContinue());
}

void xuat_DSKHDoc(NODEBANGKHACHHANGPTR list, bool stt) {
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	NODEBANGKHACHHANGPTR p = list;
	int i = 1;
	while (p != NULL) {
		// Chỉ xuất khi isDelete là false
		if (!p->data.isDelete) {
			if (stt == true) {
				xuatKhachHang(p->data, i);
			}
			else {
				xuatKhachHang(p->data);
			}
			i++;
		}
		p = p->next;
	}
}

void xuat_DSKHNgang(NODEBANGKHACHHANGPTR list, bool stt) {
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	if (stt == true) {
		cout << left << setw(5) << "STT" << setw(10) << "Ma KH" << setw(30) << "Ten KH" << setw(50)
			<< "Dia chi KH" << setw(13) << "So dien thoai KH" << endl;
		cout << setfill('-') << setw(110) << "" << setfill(' ') << endl;
	}
	else {
		cout << left << setw(10) << "Ma KH" << setw(30) << "Ten KH" << setw(50)
			<< "Dia chi KH" << setw(13) << "So dien thoai KH" << endl;
		cout << setfill('-') << setw(105) << "" << setfill(' ') << endl;
	}
	NODEBANGKHACHHANGPTR p = list;
	int i = 1;
	while (p != NULL) {
		// Chỉ xuất khi isDelete là false
		if (!p->data.isDelete) {
			if (stt == true) {
				xuatKhachHangNgang(p->data, i);
			}
			else {
				xuatKhachHangNgang(p->data);
			}
			i++;
		}
		p = p->next;
	}
}

bool docFileKH(NODEBANGKHACHHANGPTR& list) {
	const string filename = "khachhang.txt";
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << endl;
		return false;
	}
	BANGKHACHHANG ttdoc;
	string docdong;

	while (getline(file, docdong)) {
		if (docdong.front() == '(' && docdong.back() == ')') {
			docdong = docdong.substr(1, docdong.size() - 2);
			int pos1 = docdong.find('`');
			int pos2 = docdong.find('`', pos1 + 1);
			int pos3 = docdong.find('`', pos2 + 1);
			int pos4 = docdong.find('`', pos3 + 1);

			if (pos4 > pos3 && pos3 > pos2 && pos2 > pos1 && pos1 >= 0) {
				ttdoc.MaKhachHang = docdong.substr(0, pos1);
				ttdoc.TenKhachHang = docdong.substr(pos1 + 1, pos2 - pos1 - 1);
				ttdoc.DiaChiKhachHang = docdong.substr(pos2 + 1,pos3 - pos2 - 1);
				ttdoc.SoDienThoaiKhachHang = docdong.substr(pos3 + 1, pos4 - pos3  - 1);

				
				string isDeleteStr = docdong.substr(pos4 + 1); // Lấy giá trị isDelete
				ttdoc.isDelete = (isDeleteStr == "true");
				them_Cuoi(list, ttdoc);
			}
		}
	}

	file.close();
	return true;
}

bool ghiFileKH(NODEBANGKHACHHANGPTR list) {
	const string filename = "khachhang.txt";
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << " de ghi du lieu" << endl;
		return false;
	}

	NODEBANGKHACHHANGPTR duyetptht = list;
	while (duyetptht != nullptr) {
		// Chỉ ghi khách hàng có isDelete == false
		
		file << "(" << duyetptht->data.MaKhachHang << "`"
			<< duyetptht->data.TenKhachHang << "`"
			<< duyetptht->data.DiaChiKhachHang << "`"
			<< duyetptht->data.SoDienThoaiKhachHang << "`"
			<<(duyetptht->data.isDelete ? "true" : "false") 
			<< ")" << endl;
		
		duyetptht = duyetptht->next;
	}

	file.close();
	return true;
}


NODEBANGKHACHHANGPTR tim_Kiem(NODEBANGKHACHHANGPTR& list, BANGKHACHHANG x) {
	NODEBANGKHACHHANGPTR p = list;
	while (p != NULL) {
		if (p->data.MaKhachHang == x.MaKhachHang) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void xoa_Dau(NODEBANGKHACHHANGPTR& list) {
	NODEBANGKHACHHANGPTR p;
	if (list != NULL) {
		p = list;
		list = p->next;
		delete p;
	}
}

void xoaPhanTuTaiViTriX(NODEBANGKHACHHANGPTR& list, int vitri) {
	NODEBANGKHACHHANGPTR p = list;
	int vitritaiphantu = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu)
			{
				p->data.isDelete = true;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}

void suaPhanTuTaiViTriX(NODEBANGKHACHHANGPTR& list, int vitri, NODEPHIEUNHAPXUATPTR& listnx, NODEBANGCHITIETNHAPXUATPTR& listctnx) {
	NODEBANGKHACHHANGPTR p = list;
	BANGKHACHHANG kh;
	int vitritaiphantu = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu) {
				xuatKhachHang(p->data);
				kh = p->data;
				cout << "----------Bang Thay Doi---------------" << endl;
				nhapKhachHang(kh);
				p->data = kh;
				break;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}

	NODEPHIEUNHAPXUATPTR listnxtam = listnx;
	while (listnxtam != NULL) {
		if (listnxtam->data.KhachHang.MaKhachHang.compare(kh.MaKhachHang) == 0) {
			listnxtam->data.KhachHang = kh;
		}
		listnxtam = listnxtam->next;
	}
	

	NODEBANGCHITIETNHAPXUATPTR listctnxtam = listctnx;
	while (listctnxtam != NULL) {
		if (listctnxtam->data.phieuNhapXuat.KhachHang.MaKhachHang.compare(kh.MaKhachHang) == 0) {
			listctnxtam->data.phieuNhapXuat.KhachHang = kh;
		}
		listctnxtam = listctnxtam->next;
	}
	
}

int DemSoLuong(NODEBANGKHACHHANGPTR list)
{
	NODEBANGKHACHHANGPTR p = list;
	int i = 0;
	while (p != NULL) {
		if (!p->data.isDelete) {
			i++;
		}
		p = p->next;
	}
	return i;
}

BANGKHACHHANG LayPhanTuKhachHangTaiViTri(NODEBANGKHACHHANGPTR list) {
	xuat_DSKHNgang(list,true);
	int vitri;
	cout << endl;
	Nhap("Vi Tri Phan Tu: ", vitri, 1, DemSoLuong(list));
	int vitritaiphantu = 1;
	NODEBANGKHACHHANGPTR p = list;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu) {
				return p->data;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}


 //Bảng thuốc
void khoiTaoBANGTHUOC(NODEBANGTHUOCPTR& list) {
	list = NULL;
}

int isEmpty(NODEBANGTHUOCPTR list) {
	return (list == NULL ? 1 : 0);
}

void giaiPhong(NODEBANGTHUOCPTR& list) {
	NODEBANGTHUOCPTR p = list;
	while (p != NULL) {
		list = list->next;
		delete p;
		p = list;
	}
}

NODEBANGTHUOCPTR tao_Node_BangThuoc(BANGTHUOC x) {
	NODEBANGTHUOCPTR p = new LISTBANGTHUOC;
	p->data = x;
	p->next = NULL;
	return p;
}

NODEBANGTHUOCPTR them_Dau(NODEBANGTHUOCPTR& list, BANGTHUOC x) {
	NODEBANGTHUOCPTR p = tao_Node_BangThuoc(x);
	p->next = list;
	list = p;
	return p;
}

bool kiemTra_TrungMa(NODEBANGTHUOCPTR list, string ma) {
	NODEBANGTHUOCPTR p = list;
	while (p != NULL) {
		if (p->data.MaThuoc == ma)
			return true;
		p = p->next;
	}
	return false;
}

NODEBANGTHUOCPTR them_Cuoi(NODEBANGTHUOCPTR& list, BANGTHUOC x) {
	NODEBANGTHUOCPTR p = tao_Node_BangThuoc(x);
	if (list == NULL)
		list = p;
	else {
		NODEBANGTHUOCPTR q = list;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	return p;
}

void nhap_DSBT(NODEBANGTHUOCPTR& list, NODEBANGPHANLOAIPTR listpl) {
	khoiTaoBANGTHUOC(list);
	BANGTHUOC x;
	do {
		nhapBangThuoc(x, list, listpl);
		them_Dau(list, x);

	
	} while (IsContinue());
}


int DemSoLuong(NODEBANGTHUOCPTR list) {
	NODEBANGTHUOCPTR p = list;
	int i = 0;
	while (p != NULL) {
		if (!p->data.isDelete) {
			i++;
		}
		p = p->next;
	}
	return i;
}

void xuat_DSBTDoc(NODEBANGTHUOCPTR list, bool stt) {
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}

	NODEBANGTHUOCPTR p = list;
	int i = 1;
	while (p != NULL) {
		// Chỉ xuất khi isDelete là false
		if (!p->data.isDelete) {
			if (stt == true)
				xuatBangThuoc(p->data);
			else
				xuatBangThuoc(p->data, i);
			i++;
			cout << endl;
		}
		p = p->next;
	}
}

void xuat_DSBTNgang(NODEBANGTHUOCPTR list, bool stt) {
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	if (stt == true) {
		cout << left << setw(5) << "STT"
			<< setw(15) << "Ma Thuoc"
			<< setw(25) << "Ten Thuoc"
			<< setw(20) << "Ten Phan Loai"
			<< setw(20) << "So Luong Ton Kho"
			<< setw(30) << "Nha San Xuat"
			<< setw(10) << "Gia Ban" << endl;
		cout << setfill('-') << setw(120) << "" << setfill(' ') << endl;
	}
	else {
		cout << left << setw(15) << "Ma Thuoc"
			<< setw(25) << "Ten Thuoc"
			<< setw(20) << "Ten Phan Loai"
			<< setw(20) << "So Luong Ton Kho"
			<< setw(30) << "Nha San Xuat"
			<< setw(10) << "Gia Ban" << endl;
		cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;
	}

	NODEBANGTHUOCPTR p = list;
	int i = 1;
	while (p != NULL) {
		if (!p->data.isDelete) { // Chỉ xuất khi isDelete là false
			xuatBangThuocNgang(p->data, (stt == true? i :0));
			i++;
		}
		p = p->next;
	}
}

bool docFileBangThuoc(NODEBANGTHUOCPTR& list) {
	const string filename = "thuoc.txt";
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Không thể mở file " << filename << endl;
		return false;
	}

	BANGTHUOC ttdoc;
	string docdong;

	while (getline(file, docdong)) {
		// Kiểm tra chuỗi có bắt đầu và kết thúc bằng dấu ngoặc đơn
		if (!docdong.empty() && docdong.front() == '(' && docdong.back() == ')') {
			docdong = docdong.substr(1, docdong.size() - 2);  // Loại bỏ dấu ngoặc đơn

			// Xác định vị trí của dấu ngắt "`" giữa các trường
			int pos1 = docdong.find('`');
			int pos2 = docdong.find('`', pos1 + 1);
			int pos3 = docdong.find('`', pos2 + 1);
			int pos4 = docdong.find('`', pos3 + 1);
			int pos5 = docdong.find('`', pos4 + 1);
			int pos6 = docdong.find('`', pos5 + 1);
			int pos7 = docdong.find('`', pos6 + 1);
			int pos8 = docdong.find(')', pos7 + 1);
		
			if (pos7 > pos6 && pos6 > pos5 && pos5 > pos4 && pos4 > pos3 && pos3 > pos2 && pos2 > pos1 && pos1 >= 0) {
				// Parse fields as required
				ttdoc.MaThuoc = docdong.substr(0, pos1);
				ttdoc.TenThuoc = docdong.substr(pos1 + 1, pos2 - pos1 - 1);

				ttdoc.PhanLoai.MaPhanLoai = docdong.substr(pos2 + 2, pos3- pos2 -2);
				ttdoc.PhanLoai.TenPhanLoai = docdong.substr(pos3 + 1, pos4 - pos3 - 2);
			
				ttdoc.SoLuongTonKho = stoi(docdong.substr(pos4 + 1, pos5 - pos4 - 1));
				ttdoc.NhaSanXuat = docdong.substr(pos5 + 1, pos6 - pos5 - 1);
				ttdoc.GiaBan = stof(docdong.substr(pos6 + 1, pos7 - pos6 - 1));
				// Parse isDelete field as boolean
				ttdoc.isDelete = (docdong.substr(pos7 + 1) == "true");

				// Add the parsed record to the list
				them_Cuoi(list, ttdoc);
			}
		}
	}

	file.close();
	return true;
}


bool ghiFileBangThuoc(NODEBANGTHUOCPTR list) {
	const string filename = "thuoc.txt";
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << " de ghi du lieu" << endl;
		return false;
	}

	NODEBANGTHUOCPTR duyetptht = list;
	while (duyetptht != NULL) {
		
		file << "("
			<< duyetptht->data.MaThuoc << "`"
			<< duyetptht->data.TenThuoc << "`"
			<< "("
			<< duyetptht->data.PhanLoai.MaPhanLoai << "`"
			<< duyetptht->data.PhanLoai.TenPhanLoai << ")" << "`"
			<< duyetptht->data.SoLuongTonKho << "`"
			<< duyetptht->data.NhaSanXuat << "`"
			<< duyetptht->data.GiaBan << "`"
			<< (duyetptht->data.isDelete ? "true" : "false") 
			<< ")" << endl;
		
		duyetptht = duyetptht->next;
	}

	file.close();
	return true;
}


NODEBANGTHUOCPTR tim_Kiem(NODEBANGTHUOCPTR& list, BANGTHUOC x) {
	NODEBANGTHUOCPTR p = list;
	while (p != NULL) {
		if (p->data.MaThuoc == x.MaThuoc) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void xoa_Dau(NODEBANGTHUOCPTR& list) {
	NODEBANGTHUOCPTR p;
	if (list != NULL) {
		p = list;
		list = p->next;
		delete p;
	}
}

void xoaPhanTuTaiViTriX(NODEBANGTHUOCPTR& list, int vitri) {
	NODEBANGTHUOCPTR p=list;
	int vitritaiphantu = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu)
			{
				p->data.isDelete = true;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}

void suaPhanTuTaiViTriX(NODEBANGTHUOCPTR& list, int vitri, NODEBANGPHANLOAIPTR listPL, NODEBANGCHITIETNHAPXUATPTR& listctnx) {
	NODEBANGTHUOCPTR p = list;
	BANGTHUOC thuoc;
	int vitritaiphantu = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu) {
				thuoc = p->data;
				cout << "-----------Bang Thuoc Goc----------" << endl;
				xuatBangThuoc(thuoc);
				cout << "----------------------------------" << endl;
				nhapBangThuoc(thuoc, listPL);
				p->data = thuoc;
				break;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
	CapNhatThuoc(list, thuoc, listctnx);
}

void tinhTongSoLuongThuoc(BANGTHUOC& thuoc, BANGCHITIETNHAPXUAT ctnx,bool isDelele ) {
	if (isDelele == false) { // Nếu không xoá 
		if (ctnx.NhapXuat) {
			thuoc.SoLuongTonKho += ctnx.SoLuong;
		}
		else {
			if (thuoc.SoLuongTonKho > ctnx.SoLuong) {
				thuoc.SoLuongTonKho -= ctnx.SoLuong;
			}
			else if (thuoc.SoLuongTonKho == ctnx.SoLuong) {
				thuoc.SoLuongTonKho -= ctnx.SoLuong;
				cout << "So Luong Thuoc Da Het Khong Du Cho Don Hang Tiep Theo" << endl;
			}
			else {
				cout << "Khong Du So Luong Thuoc" << endl;
			}
		}
	}
	else { // nếu xoá đơn
		if (!ctnx.NhapXuat) {
			thuoc.SoLuongTonKho += ctnx.SoLuong;
		}
		else {
			if (thuoc.SoLuongTonKho > ctnx.SoLuong) {
				thuoc.SoLuongTonKho -= ctnx.SoLuong;
			}
			else if (thuoc.SoLuongTonKho == ctnx.SoLuong) {
				thuoc.SoLuongTonKho -= ctnx.SoLuong;
				cout << "So Luong Thuoc Da Het Khong Du Cho Don Hang Tiep Theo" << endl;
			}
			else {
				cout << "Khong Du So Luong Thuoc" << endl;
			}
		}
	}
}

void CapNhatThuoc(NODEBANGTHUOCPTR& listThuoc, BANGTHUOC thuoc, NODEBANGCHITIETNHAPXUATPTR& listctnx) {
	NODEBANGTHUOCPTR p = listThuoc;
	while (p != NULL)
	{
		if (p->data.MaThuoc.compare(thuoc.MaThuoc) == 0) {
			p->data = thuoc;
		}
		p = p->next;
	}
	

	if (listctnx != NULL) {
		NODEBANGCHITIETNHAPXUATPTR listctnxtam = listctnx;
		while (listctnxtam != NULL)
		{
			if (listctnxtam->data.Thuoc.MaThuoc.compare(thuoc.MaThuoc) == 0) {
				listctnxtam->data.Thuoc = thuoc;
			}
			listctnxtam = listctnxtam->next;
		}
		
	}
}

void CapNhatThuoc(NODEBANGTHUOCPTR& listThuoc, BANGTHUOC thuoc) {
	NODEBANGTHUOCPTR p = listThuoc;
	while (p !=NULL)
	{
		if ( p->data.MaThuoc.compare(thuoc.MaThuoc) == 0 ) {
			p->data = thuoc;
		}
		p = p->next;
	}
}

bool CapNhatSoLuongThuoc(NODEBANGTHUOCPTR& listThuoc, string mathuoc, int soLuong) {
	NODEBANGTHUOCPTR p = listThuoc;
	bool IsCapNhat = false;
	while (p != NULL)
	{
		if (p->data.MaThuoc.compare(mathuoc) == 0) {
			int SoLuongTonKho = p->data.SoLuongTonKho;
			SoLuongTonKho += soLuong;
			if (SoLuongTonKho > 0) {
				p->data.SoLuongTonKho = SoLuongTonKho;
				IsCapNhat = true;
			}
			else if (SoLuongTonKho == 0) {
				p->data.SoLuongTonKho = SoLuongTonKho;
				IsCapNhat = true;
				cout << "So Luong Thuoc Da Het Khong Du Cho Don Hang Tiep Theo" << endl;
			}
			else {
				cout << "Khong Du So Luong Thuoc" << endl;
			}
			
		}
		p = p->next;
	}
	return IsCapNhat;
}

BANGTHUOC LayPhanTuBangThuocTaiViTri(NODEBANGTHUOCPTR list) {
	xuat_DSBTNgang(list, true);
	int vitri;
	cout << endl;
	Nhap("Vi Tri Phan Tu: ", vitri, 1, DemSoLuong(list));
	int vitritaiphantu = 1;
	NODEBANGTHUOCPTR p = list;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (vitri == vitritaiphantu) {
				return p->data;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}



// Phiếu nhập xuất
void khoiTaoPHIEUNHAPXUAT(NODEPHIEUNHAPXUATPTR& list) {
	list = NULL;
}


int isEmpty(NODEPHIEUNHAPXUATPTR list) {
	return (list == NULL ? 1 : 0);
}


void giaiPhong(NODEPHIEUNHAPXUATPTR& list) {
	NODEPHIEUNHAPXUATPTR p = list;
	while (p != NULL) {
		list = list->next;
		delete p;
		p = list;
	}
}

// Tạo node mới với dữ liệu là một phiếu nhập xuất
NODEPHIEUNHAPXUATPTR tao_Node_PhieuNhapXuat(PHIEUNHAPXUAT x) {
	NODEPHIEUNHAPXUATPTR p = new LISTPHIEUNHAPXUAT;
	p->data = x;
	p->next = NULL;
	return p;
}


NODEPHIEUNHAPXUATPTR them_Dau(NODEPHIEUNHAPXUATPTR& list, PHIEUNHAPXUAT x) {
	NODEPHIEUNHAPXUATPTR p = tao_Node_PhieuNhapXuat(x);
	p->next = list;
	list = p;
	return p;
}

bool kiemTra_TrungMa(NODEPHIEUNHAPXUATPTR list, string ma) {
	NODEPHIEUNHAPXUATPTR p = list;
	while (p != NULL) {
		if (p->data.MaNhapXuat == ma)
			return true;
		p = p->next;
	}
	return false;
}

NODEPHIEUNHAPXUATPTR them_Cuoi(NODEPHIEUNHAPXUATPTR& list, PHIEUNHAPXUAT x) {
	NODEPHIEUNHAPXUATPTR p = tao_Node_PhieuNhapXuat(x);
	if (list == NULL)
		list = p;
	else {
		NODEPHIEUNHAPXUATPTR q = list;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	return p;
}

// Nhập danh sách phiếu nhập xuất từ người dùng
void nhap_DSPNX(NODEPHIEUNHAPXUATPTR& list, NODEBANGNHACUNCAPPTR listkh) {
	khoiTaoPHIEUNHAPXUAT(list);
	PHIEUNHAPXUAT x;
	do {
		// Nhập thông tin phiếu nhập xuất
		nhapBangNhapKho(x,list, listkh);
		// Đảm bảo isDelete là false khi thêm mới
		x.isDelete = false;  // Mặc định là không bị xóa
		them_Dau(list, x);   // Thêm phiếu vào danh sách
	} while (IsContinue());
}


// Xuất danh sách phiếu nhập xuất
void xuat_DSPNX(NODEPHIEUNHAPXUATPTR list,bool nhapxuat) 
{
	NODEPHIEUNHAPXUATPTR p = list;
	int i = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete) 
		{  // Kiểm tra nếu phần tử chưa bị xóa
			if (p->data.NhapXuat == nhapxuat) 
			{
			xuatBangNhapKho(p->data, i);  // Xuất phiếu nhập xuất
			cout << endl;
			i++;
		    }
			
	    }
		p = p->next;
	}
}

void xuat_DSPNXngang(NODEPHIEUNHAPXUATPTR list, bool nhapxuat,bool stt)
{
	NODEPHIEUNHAPXUATPTR p = list;
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	if (stt == true) {
		cout << left << setw(5) << "STT"
			<< setw(20) << "Ma Nhap Xuat"
			<< setw(40) << "Ngay Nhap Xuat"
			<< setw(60) << (nhapxuat == true ? "Nha Cung Cap" : "Khach Hang")
			<< setw(20) << "Nhap Xuat" << endl;

		cout << setfill('-') << setw(145) << "" << setfill(' ') << endl;
	}
	else {
		cout << left << setw(20) << "Ma Nhap Xuat"
			<< setw(40) << "Ngay Nhap Xuat"
			<< setw(60) << (nhapxuat == true ? "Nha Cung Cap" : "Khach Hang")
			<< setw(20) << "Nhap Xuat" << endl;
		cout<<  setfill('-') << setw(140) << "" << setfill(' ') << endl;
	}
	
	int i = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete)
		{  // Kiểm tra nếu phần tử chưa bị xóa
			if (p->data.NhapXuat == nhapxuat)
			{
				if (p->data.NhapXuat) {
					xuatBangNhapKhoNgang(p->data,(stt ? i : 0));  // Xuất phiếu nhập xuất
				}
				else  {
					xuatBangXuatKhoNgang(p->data,(stt ? i : 0));  // Xuất phiếu nhập xuất
				}
				i++;
			}

		}
		p = p->next;
	}
}


bool docFilePhieuNhapXuat(NODEPHIEUNHAPXUATPTR& list) {
	const string filename = "phieunhapxuat.txt";
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << endl;
		return false;
	}

	PHIEUNHAPXUAT ttdoc;
	string docdong;

	while (getline(file, docdong)) {
		if (docdong.front() == '(' && docdong.back() == ')') {
			docdong = docdong.substr(1, docdong.size() - 2);  // Loại bỏ dấu ngoặc đơn

			int pos1 = docdong.find('`');
			int pos2 = docdong.find('`', pos1 + 1);
			int pos3 = docdong.find('`', pos2 + 1);
			int pos4 = docdong.find('`', pos3 + 1);
			int pos5 = docdong.find('`', pos4 + 1);
			int pos6 = docdong.find('`', pos5 + 1);
			int pos7 = docdong.find('`', pos6 + 1);

			int pos8 = docdong.find('`', pos7 + 1);
			int pos9 = docdong.find('`', pos8 + 1);
			int pos10 = docdong.find('`', pos9 + 1);
			int pos11 = docdong.find('`', pos10 + 1);
			int pos12 = docdong.find(')', pos11 + 1);

			if (pos12 > pos11 && pos11 > pos10 && pos10 > pos9 && pos9 > pos8 && pos8 > pos7 && pos7 > pos6 &&
				pos6 > pos5 && pos5 > pos4 && pos4 > pos3 && pos3 > pos2 && pos2 > pos1 && pos1 >= 0) {
				// MaNhapXuat
				ttdoc.MaNhapXuat = docdong.substr(0, pos1);

				// NhapXuat
				ttdoc.NhapXuat = (docdong.substr(pos1 + 1, pos2 - pos1 - 1) == "true");

				// NgayNhapXuat
				ttdoc.NgayNhapXuat = docdong.substr(pos2 + 1, pos3 - pos2 - 1);

				// KhachHang 
				ttdoc.KhachHang.MaKhachHang = docdong.substr(pos3 + 2, pos4 - pos3 - 2);
				ttdoc.KhachHang.TenKhachHang = docdong.substr(pos4 + 1, pos5 - pos4 - 1);
				ttdoc.KhachHang.DiaChiKhachHang = docdong.substr(pos5 + 1, pos6 - pos5 - 1);
				ttdoc.KhachHang.SoDienThoaiKhachHang = docdong.substr(pos6 + 1, pos7 - pos6 - 2);

				// NhaCungCap
				ttdoc.NhaCungCap.MaNCC = docdong.substr(pos8 + 2, pos9 - pos8 - 2);
				ttdoc.NhaCungCap.TenNCC = docdong.substr(pos9 + 1, pos10 - pos9 - 1);
				ttdoc.NhaCungCap.DiaChiNCC = docdong.substr(pos10 + 1, pos11 - pos10 - 1);
				ttdoc.NhaCungCap.SoDienThoaiNCC = docdong.substr(pos11 + 1, pos12 - pos11 - 1);

				
				string isDeleteStr = docdong.substr(pos12 + 1); // Lấy giá trị isDelete
				ttdoc.isDelete = (isDeleteStr == "true"); // Chuyển sang bool, "1" là true, "0" là false

				// Thêm vào danh sách
				them_Cuoi(list, ttdoc);
			}
		}
	}

	file.close();
	return true;
}

// Ghi file phiếu nhập xuất
bool ghiFilePhieuNhapXuat(NODEPHIEUNHAPXUATPTR list) {
	const string filename = "phieunhapxuat.txt";
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << " de ghi du lieu" << endl;
		return false;
	}

	NODEPHIEUNHAPXUATPTR duyetptht = list;
	while (duyetptht != nullptr) {
		// Ghi thông tin cơ bản
		file << "("
			<< duyetptht->data.MaNhapXuat << "`"
			<< (duyetptht->data.NhapXuat ? "true" : "false") << "`"
			<< duyetptht->data.NgayNhapXuat << "`";


		// Ghi thông tin NhaCungCap nếu là phiếu nhập
		if (duyetptht->data.NhapXuat) {
			file << "("
				<< "" << "`"  // Chỗ này có thể bỏ qua nếu không có thông tin
				<< "" << "`"
				<< "" << "`"
				<< "" << "`"
				<< ")" << "`";

			file << "("
				<< duyetptht->data.NhaCungCap.MaNCC << "`"
				<< duyetptht->data.NhaCungCap.TenNCC << "`"
				<< duyetptht->data.NhaCungCap.DiaChiNCC << "`"
				<< duyetptht->data.NhaCungCap.SoDienThoaiNCC << ")";
		}
		// Ghi thông tin KhachHang nếu là phiếu xuất
		else {
			file << "("
				<< duyetptht->data.KhachHang.MaKhachHang << "`"
				<< duyetptht->data.KhachHang.TenKhachHang << "`"
				<< duyetptht->data.KhachHang.DiaChiKhachHang << "`"
				<< duyetptht->data.KhachHang.SoDienThoaiKhachHang
				<< ")" << "`";

			file << "("
				<< "" << "`"
				<< "" << "`"
				<< "" << "`"
				<< "" << "`" 
				<< ")";
		}
		file << "`" << (duyetptht->data.isDelete ? "true" : "false") << ")" << endl;
		duyetptht = duyetptht->next;
	}

	file.close();
	return true;
}

// Tìm kiếm phiếu nhập xuất theo mã
NODEPHIEUNHAPXUATPTR tim_Kiem(NODEPHIEUNHAPXUATPTR& list, PHIEUNHAPXUAT x) {
	NODEPHIEUNHAPXUATPTR p = list;
	while (p != NULL) {
		if (p->data.MaNhapXuat == x.MaNhapXuat) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// Xóa đầu danh sách phiếu nhập xuất
void xoa_Dau(NODEPHIEUNHAPXUATPTR& list) {
	NODEPHIEUNHAPXUATPTR p;
	if (list != NULL) {
		p = list;
		list = p->next;
		delete p;
	}
}

// Xóa phần tử tại vị trí chỉ định trong danh sách phiếu nhập xuất
void xoaPhanTuTaiViTriX(NODEPHIEUNHAPXUATPTR& list, int vitri,bool nhapxuat, NODEBANGCHITIETNHAPXUATPTR& listCT, NODEBANGTHUOCPTR& listthuoc) {
	NODEPHIEUNHAPXUATPTR p = list;
	PHIEUNHAPXUAT phieu;
	int vitritaiphantu = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete) {
			if (nhapxuat == p->data.NhapXuat) {
				if (vitri == vitritaiphantu)
				{
					phieu = p->data;
					p->data.isDelete = true;
				}
				vitritaiphantu++;
			}
		}
		p = p->next;
	}
	NODEBANGCHITIETNHAPXUATPTR ct = listCT;
	while (ct != NULL)
	{
		if (!ct->data.isDelete) {
			if (ct->data.phieuNhapXuat.MaNhapXuat == phieu.MaNhapXuat) {
				xoaPhanTuTheoMa(listCT, ct->data.MaChiTietNhapXuat,listthuoc);
			}
		}
		ct = ct->next;
	}
}



void suaPhanTuTaiViTriX(NODEPHIEUNHAPXUATPTR& list, int vitri, NODEBANGKHACHHANGPTR listkh,
NODEBANGNHACUNCAPPTR listncc, NODEBANGCHITIETNHAPXUATPTR& listctnx, bool nhapxuat) {
	NODEPHIEUNHAPXUATPTR p = list;
	PHIEUNHAPXUAT pnx;
	int vitritaiphantu = 1;

	// Duyệt danh sách để tìm phần tử tại vị trí cần sửa
	while (p != NULL) {
		if (!p->data.isDelete && p->data.NhapXuat == nhapxuat) {
			if (vitritaiphantu == vitri) {
				// Thao tác xuất và nhập dữ liệu dựa trên NhapXuat
				if (p->data.NhapXuat) { // Nhập kho
					xuatBangNhapKho(p->data);
					nhapBangNhapKho(p->data, listncc);
				}
				else { // Xuất kho
					xuatBangXuatKho(p->data);
					nhapBangXuatKho(p->data, listkh);
				}
				pnx = p->data; // Lưu dữ liệu đã cập nhật
				break;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}

	// Cập nhật dữ liệu tương ứng trong danh sách chi tiết nhập xuất
	NODEBANGCHITIETNHAPXUATPTR listctnxtam = listctnx;
	while (listctnxtam != NULL) {
		if (!listctnxtam->data.isDelete && listctnxtam->data.phieuNhapXuat.MaNhapXuat == pnx.MaNhapXuat) {
			listctnxtam->data.phieuNhapXuat = pnx;
		}
		listctnxtam = listctnxtam->next;
	}
}


int DemSoLuong(NODEPHIEUNHAPXUATPTR list,bool nhapxuat)
{
	NODEPHIEUNHAPXUATPTR p = list;
	int i = 0;
	while (p != NULL) {
		if (!p->data.isDelete) 
		{
			if (p->data.NhapXuat == nhapxuat) 
			{
				i++;
			}
			
		}
		p = p->next;
	}
	return i;
}




PHIEUNHAPXUAT LayPhanTuPhieuNhapXuatTaiViTri(NODEPHIEUNHAPXUATPTR list, bool nhapxuat)
{
	xuat_DSPNXngang(list, nhapxuat,true);
	int vitri;
	cout << endl;
	Nhap("Vi Tri Phan Tu: ", vitri, 1, DemSoLuong(list, nhapxuat));
	int vitritaiphantu = 1;
	NODEPHIEUNHAPXUATPTR p = list;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (p->data.NhapXuat == nhapxuat) {
				if (vitri == vitritaiphantu) {
					return p->data;
				}
				vitritaiphantu++;
			}
		}
		p = p->next;
	}
	
		
}


// Bảng chi tiết nhập xuất
void khoiTaoBANGCHITIETNHAPXUAT(NODEBANGCHITIETNHAPXUATPTR& list)
{
	list = NULL;
}

int isEmpty(NODEBANGCHITIETNHAPXUATPTR list)
{
	return (list == NULL ? 1 : 0);
}

void giaiPhong(NODEBANGCHITIETNHAPXUATPTR& list)
{
	NODEBANGCHITIETNHAPXUATPTR p = list;
	while (p != NULL) {
		list = list->next;
		delete p;
		p = list;
	}
}
NODEBANGCHITIETNHAPXUATPTR tao_Node_BangChiTietNhapXuat(BANGCHITIETNHAPXUAT x)
{
	NODEBANGCHITIETNHAPXUATPTR p = new LISTBANGCHITIETNHAPXUAT;
	p->data = x;
	p->next = NULL;
	return p;
}

NODEBANGCHITIETNHAPXUATPTR them_Dau(NODEBANGCHITIETNHAPXUATPTR& list, BANGCHITIETNHAPXUAT x)
{
	NODEBANGCHITIETNHAPXUATPTR p = tao_Node_BangChiTietNhapXuat(x);
	p->next = list;
	list = p;
	return p;
}

bool kiemTra_TrungMa(NODEBANGCHITIETNHAPXUATPTR list, string ma)
{
	NODEBANGCHITIETNHAPXUATPTR p = list;
	while (p != NULL) {
		if (p->data.MaChiTietNhapXuat == ma)
			return true;
		p = p->next;
	}
	return false;
}

NODEBANGCHITIETNHAPXUATPTR them_Cuoi(NODEBANGCHITIETNHAPXUATPTR& list, BANGCHITIETNHAPXUAT x)
{
	NODEBANGCHITIETNHAPXUATPTR p = tao_Node_BangChiTietNhapXuat(x);
	if (list == NULL)
		list = p;
	else {
		NODEBANGCHITIETNHAPXUATPTR q = list;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	return p;
}

void nhap_DSCTNX(NODEBANGCHITIETNHAPXUATPTR& list, PHIEUNHAPXUAT phieuNhapXuat, NODEBANGTHUOCPTR listThuoc) {
	BANGCHITIETNHAPXUAT chiTiet;
	khoiTaoBANGCHITIETNHAPXUAT(list);  // Khởi tạo danh sách chi tiết nhập xuất

	do {
		nhapChiTietNhapXuat(chiTiet, list, phieuNhapXuat, listThuoc);  // Nhập chi tiết phiếu nhập xuất

		// Đảm bảo `isDelete` là `false` khi thêm mới
		chiTiet.isDelete = false;
		them_Dau(list, chiTiet);  // Thêm chi tiết vào cuối danh sách

	} while (IsContinue());  // Tiếp tục nhập nếu người dùng muốn
}


void xuat_DSCTNX(NODEBANGCHITIETNHAPXUATPTR list) {
	NODEBANGCHITIETNHAPXUATPTR p = list;
	int i = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {  // Kiểm tra nếu phần tử chưa bị xóa
			XuatChiTietNhapXuat(p->data);  // Xuất chi tiết phiếu nhập xuất
			cout << endl;
			i++;
		}
		p = p->next;  // Chuyển sang phần tử tiếp theo trong danh sách
	}
}

void xuat_DSCTNXNgang(NODEBANGCHITIETNHAPXUATPTR list,bool stt ) {
	NODEBANGCHITIETNHAPXUATPTR p = list;
	if (list == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	if (stt == true) {
		cout << left << setw(5) << "STT"
			<< setw(20) << "MaChiTietNhapXuat"
			<< setw(15) << "HanSuDung"
			<< setw(10) << "SoLuong"
			<< setw(30) << "TenPhanLoaiThuoc"
			<< setw(30) << "TenThuoc" << endl;

		cout << setfill('-') << setw(145) << "" << setfill(' ') << endl;
	}
	else {
		cout << left << setw(20) << "MaChiTietNhapXuat"
			<< setw(15) << "HanSuDung"
			<< setw(10) << "SoLuong"
			<< setw(30) << "TenPhanLoaiThuoc"
			<< setw(30) << "TenThuoc" << endl;
		cout << setfill('-') << setw(140) << "" << setfill(' ') << endl;
	}

	int i = 1;
	while (p != NULL)
	{
		if (!p->data.isDelete)
		{  // Kiểm tra nếu phần tử chưa bị xóa
			XuatChiTietNhapXuatNgang(p->data, (stt ? i : 0));  // Xuất phiếu nhập xuất
			i++;
			

		}
		p = p->next;
	}
}


bool docFileCTNX(NODEBANGCHITIETNHAPXUATPTR& list) {
	const string filename = "chitietnhapxuat.txt";
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << endl;
		return false;
	}

	BANGCHITIETNHAPXUAT ttdoc;
	string docdong;

	while (getline(file, docdong)) {
		// Kiểm tra xem dòng có dữ liệu hay không trước khi dùng front() và back()
		if (!docdong.empty() && docdong.front() == '(' && docdong.back() == ')') {
			docdong = docdong.substr(1, docdong.size() - 2);  // Loại bỏ dấu ngoặc đơn

			int pos1 = docdong.find('`');
			int pos2 = docdong.find('`', pos1 + 1);
			int pos3 = docdong.find('`', pos2 + 1);
			int pos4 = docdong.find('`', pos3 + 1);
			int pos5 = docdong.find('`', pos4 + 1);
			int pos6 = docdong.find('`', pos5 + 1);
			int pos7 = docdong.find('`', pos6 + 1);

			int pos8 = docdong.find('`', pos7 + 1);
			int pos9 = docdong.find('`', pos8 + 1);
			int pos10 = docdong.find('`', pos9 + 1);
			int pos11 = docdong.find('`', pos10 + 1);
			int pos12 = docdong.find('`', pos11 + 1);

			int pos13 = docdong.find('`', pos12 + 1);
			int pos14 = docdong.find('`', pos13 + 1);
			int pos15 = docdong.find('`', pos14 + 1);
			int pos16 = docdong.find('`', pos15 + 1);
			int pos17 = docdong.find('`', pos16 + 1);
			int pos18 = docdong.find('`', pos17 + 1);
			int pos19 = docdong.find('`', pos18 + 1);

			if (pos10 > pos9 && pos9 > pos8 && pos8 > pos7 && pos7 > pos6 &&
				pos6 > pos5 && pos5 > pos4 && pos4 > pos3 && pos3 > pos2 && pos2 > pos1 && pos1 >= 0) {
				// MaNhapXuat
				ttdoc.MaChiTietNhapXuat = docdong.substr(0, pos1);

				// NgayNhapXuat
				ttdoc.HanSuDung = stoi(docdong.substr(pos1 + 1, pos2 - pos1 - 1));

				// NhapXuat
				ttdoc.NhapXuat = (docdong.substr(pos2 + 1, pos3 - pos2 - 1) == "true");

				// SoLuong
				ttdoc.SoLuong = stoi(docdong.substr(pos3 + 1, pos4 - pos3 - 1));

				// Thuoc
				ttdoc.Thuoc.MaThuoc = docdong.substr(pos4 + 2, pos5 - pos4 - 2);
				ttdoc.Thuoc.TenThuoc = docdong.substr(pos5 + 1, pos6 - pos5 - 1);

				// Thuoc.PhanLoai
				ttdoc.Thuoc.PhanLoai.MaPhanLoai = docdong.substr(pos6 + 2, pos7 - pos6 - 2);
				ttdoc.Thuoc.PhanLoai.TenPhanLoai = docdong.substr(pos7 + 1, pos8 - pos7 - 3);

				// PhieuNhapXuat
				ttdoc.phieuNhapXuat.MaNhapXuat = docdong.substr(pos8 + 2, pos9 - pos8 - 2);
				ttdoc.phieuNhapXuat.NhapXuat = (docdong.substr(pos9 + 1, pos10 - pos9 - 1) == "true");
				ttdoc.phieuNhapXuat.NgayNhapXuat = docdong.substr(pos10 + 1, pos11 - pos10 - 1);

				// KhachHang
				ttdoc.phieuNhapXuat.KhachHang.MaKhachHang = docdong.substr(pos11 + 2, pos12 - pos11 - 2);
				ttdoc.phieuNhapXuat.KhachHang.TenKhachHang = docdong.substr(pos12 + 1, pos13 - pos12 - 1);
				ttdoc.phieuNhapXuat.KhachHang.DiaChiKhachHang = docdong.substr(pos13 + 1, pos14 - pos13 - 1);
				ttdoc.phieuNhapXuat.KhachHang.SoDienThoaiKhachHang = docdong.substr(pos14 + 1, pos15 - pos14 - 1);

				// NhaCungCap
				ttdoc.phieuNhapXuat.NhaCungCap.MaNCC = docdong.substr(pos15 + 2, pos16 - pos15 - 2);
				ttdoc.phieuNhapXuat.NhaCungCap.TenNCC = docdong.substr(pos16 + 1, pos17 - pos16 - 1);
				ttdoc.phieuNhapXuat.NhaCungCap.DiaChiNCC = docdong.substr(pos17 + 1, pos18 - pos17 - 1);
				ttdoc.phieuNhapXuat.NhaCungCap.SoDienThoaiNCC = docdong.substr(pos18 + 1, pos19 - pos18 - 1);

				// Thêm trường isDelete (mặc định là false nếu không có trường này trong file)
				ttdoc.isDelete = (docdong.substr(pos19 + 1) == "true");

				// Thêm vào danh sách
				them_Cuoi(list, ttdoc);
			}
		}
	}

	file.close();
	return true;
}


bool ghiFileCTNX(NODEBANGCHITIETNHAPXUATPTR list) {
	const string filename = "chitietnhapxuat.txt";
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file " << filename << " de ghi du lieu" << endl;
		return false;
	}

	NODEBANGCHITIETNHAPXUATPTR duyet = list;
	while (duyet != nullptr) {
		file << "("
			<< duyet->data.MaChiTietNhapXuat << "`"
			<< duyet->data.HanSuDung << "`"
			<< (duyet->data.NhapXuat ? "true" : "false") << "`"
			<< duyet->data.SoLuong << "`";

		// Thông tin về thuốc 
		file << "("
			<< duyet->data.Thuoc.MaThuoc << "`"
			<< duyet->data.Thuoc.TenThuoc << "`"
			<< "(" << duyet->data.Thuoc.PhanLoai.MaPhanLoai << "`"
			<< duyet->data.Thuoc.PhanLoai.TenPhanLoai << ")"
			<< ")`";

		// Thông tin về phiếu nhập/xuất
		file << "("
			<< duyet->data.phieuNhapXuat.MaNhapXuat << "`"
			<< (duyet->data.phieuNhapXuat.NhapXuat ? "true" : "false") << "`"
			<< duyet->data.phieuNhapXuat.NgayNhapXuat << "`";

		// Ghi thông tin khách hàng nếu là phiếu xuất
		if (!duyet->data.NhapXuat) {
	   
			file << "("
				<< duyet->data.phieuNhapXuat.KhachHang.MaKhachHang << "`"
				<< duyet->data.phieuNhapXuat.KhachHang.TenKhachHang << "`"
				<< duyet->data.phieuNhapXuat.KhachHang.DiaChiKhachHang << "`"
				<< duyet->data.phieuNhapXuat.KhachHang.SoDienThoaiKhachHang << ")`";

			// Phần nhà cung cấp để trống
			file << "("
				<< "" << "`"
				<< "" << "`"
				<< "" << "`"
				<< "" << ")";
		}
		// Ghi thông tin nhà cung cấp nếu là phiếu nhập
		else {
			// Phần khách hàng để trống
			file << "("
				<< "" << "`"
				<< "" << "`"
				<< "" << "`"
				<< "" << ")`";

			file << "("
				<< duyet->data.phieuNhapXuat.NhaCungCap.MaNCC << "`"
				<< duyet->data.phieuNhapXuat.NhaCungCap.TenNCC << "`"
				<< duyet->data.phieuNhapXuat.NhaCungCap.DiaChiNCC << "`"
				<< duyet->data.phieuNhapXuat.NhaCungCap.SoDienThoaiNCC << ")";
		}

		file << "`" << (duyet->data.isDelete ? "true" : "false") << ")" << endl;

		duyet = duyet->next;
	}

	file.close();
	return true;
}

void xoaPhanTuTaiViTriX(NODEBANGCHITIETNHAPXUATPTR& list, int vitri, NODEBANGTHUOCPTR& listthuoc)
{
	NODEBANGCHITIETNHAPXUATPTR p = list;
	int vitritaiphantu = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {

			if (vitri == vitritaiphantu) {
				p->data.isDelete = true;
				CapNhatSoLuongThuoc(listthuoc, p->data.Thuoc.MaThuoc,(p->data.NhapXuat ?  1 : (-1)) * p->data.SoLuong);
				break;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}

void suaPhanTuTaiViTriX(NODEBANGCHITIETNHAPXUATPTR& list, int vitri, NODEBANGTHUOCPTR& listthuoc) {
	NODEBANGCHITIETNHAPXUATPTR p = list;
	int vitritaiphantu = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {

			if (vitri == vitritaiphantu) {
				nhapChiTietNhapXuat(p->data, listthuoc);
				break;
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}
void xoaPhanTuTheoMa(NODEBANGCHITIETNHAPXUATPTR& list, string Ma, NODEBANGTHUOCPTR& listthuoc) {
	NODEBANGCHITIETNHAPXUATPTR p = list;
	int vitritaiphantu = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {

			if (p->data.MaChiTietNhapXuat.compare(Ma) == 0) {
				p->data.isDelete = true;
				if (p->data.NhapXuat) {
					if (!CapNhatSoLuongThuoc(listthuoc, p->data.Thuoc.MaThuoc, (-1) * p->data.SoLuong)) return;
				}
				else {
					CapNhatSoLuongThuoc(listthuoc, p->data.Thuoc.MaThuoc, p->data.SoLuong);
				}
				
			}
			vitritaiphantu++;
		}
		p = p->next;
	}
}
void suaPhanTuTheoMa(NODEBANGCHITIETNHAPXUATPTR& list, string Ma, NODEBANGTHUOCPTR& listthuoc)
{
	NODEBANGCHITIETNHAPXUATPTR p = list;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (p->data.MaChiTietNhapXuat == Ma) {
				// Sửa thông tin chi tiết nhập xuất
				nhapChiTietNhapXuat(p->data, listthuoc);
				return;
			}
		}
		p = p->next;
	}
}
NODEBANGCHITIETNHAPXUATPTR laydanhsachbangchitiettumaphieunhap(NODEBANGCHITIETNHAPXUATPTR& list,  string ma)
{
	NODEBANGCHITIETNHAPXUATPTR danhsach = NULL; // Danh sách lưu các phần tử phù hợp
	NODEBANGCHITIETNHAPXUATPTR p = list;

	while (p != NULL) {
		if (!p->data.isDelete) { // Bỏ qua các phần tử bị xóa
			if (p->data.phieuNhapXuat.MaNhapXuat == ma) { // Kiểm tra mã chi tiết nhập xuất
				// Tạo một node mới để thêm vào danh sách kết quả
				them_Cuoi(danhsach, p->data);
			}
		}
		p = p->next; // Duyệt phần tử tiếp theo
	}
	return danhsach;
}

int DemSoLuongTheoMaPhieuNhapXuat(NODEBANGCHITIETNHAPXUATPTR list, string maphieu) {
	NODEBANGCHITIETNHAPXUATPTR p = list;
	int i = 0;
	while (p != NULL) {
		if (!p->data.isDelete)
		{
			if (p->data.phieuNhapXuat.MaNhapXuat == maphieu)
			{
				i++;
			}

		}
		p = p->next;
	}
	return i;
}

BANGCHITIETNHAPXUAT LayBangChitietNhapXuatTaiViTri(NODEBANGCHITIETNHAPXUATPTR list, int vt, string maphieu) {
	NODEBANGCHITIETNHAPXUATPTR p = list;
	int vtht = 1;
	while (p != NULL) {
		if (!p->data.isDelete) {
			if (p->data.phieuNhapXuat.MaNhapXuat == maphieu) {
				if (vt == vtht) {
					return p->data;
				}
				vtht++;
			}
		}
		p = p->next;
	}
	
}


void docFileToanBo(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx)
{
	khoiTaoBANGCHITIETNHAPXUAT(ctnx);
	khoiTaoBANGKHACHHANG(kh);
	khoiTaoBANGPHANLOAI(pl);
	khoiTaoBANGTHUOC(thuoc);
	khoiTaoBANGKHACHHANG(kh);
	khoiTaoBANGNHACUNCAP(ncc);
	khoiTaoPHIEUNHAPXUAT(pnx);

	docFileKH(kh);
	docFileNCC(ncc);
	docFileBangThuoc(thuoc);
	docFilePhieuNhapXuat(pnx);
	docFileCTNX(ctnx);
	docFilePhanLoai(pl);
}


void ghiFileToanBo(NODEBANGPHANLOAIPTR pl, NODEBANGKHACHHANGPTR kh, NODEBANGNHACUNCAPPTR ncc, NODEBANGTHUOCPTR thuoc, NODEPHIEUNHAPXUATPTR pnx, NODEBANGCHITIETNHAPXUATPTR ctnx)
{
	ghiFilePhanLoai(pl);         
	ghiFileBangThuoc(thuoc);     
	ghiFileKH(kh);               
	ghiFileNCC(ncc);             
	ghiFilePhieuNhapXuat(pnx);   
	ghiFileCTNX(ctnx);          
}


void MenuMain(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, 
	NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx) {
	int luaChon;
	do {
		cout << "=========================================" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Menu Bang Phan Loai" << endl;
		cout << "2. Menu Bang Thuoc" << endl;
		cout << "3. Menu Khach Hang" << endl;
		cout << "4. Menu Nha Cung Cap" << endl;
		cout << "5. Menu Bang Nhap Kho" << endl;
		cout << "6. Menu Bang Xuat Kho" << endl;
		cout << "=========================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon,1,6);

		switch (luaChon) {
		case 1:
			MenuBangPhanLoai(pl, kh, ncc, thuoc, pnx, ctnx);
			break;
		case 2:
			MenuBangThuoc(pl, kh, ncc, thuoc, pnx, ctnx);
			break;
		case 3:
			MenuBangKhachHang(pl, kh, ncc, thuoc, pnx, ctnx);
			break;
		case 4:
			MenuBangNhaCungCap(pl, kh, ncc, thuoc, pnx, ctnx);
			break;
		case 5:
			MenuBangNhapKho(pl, kh, ncc, thuoc, pnx, ctnx);
			break;
		case 6:
			MenuBangXuatKho(pl, kh, ncc, thuoc, pnx, ctnx);
			break;
		
		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}
	
	} while (IsContinue("Chon Menu chinh khong")); // Khi chọn 18, thoát chương trình
}

void MenuBangPhanLoai(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc,
	NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx) {
	int luaChon;
	bool isBack = false;
	do {
		system("cls");
		xuat_DSPLngang(pl,true);
		cout << "=========================================" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Them Phan Loai" << endl;
		cout << "2. Sua Phan Loai" << endl;
		cout << "3. Xoa Phan Loai" << endl;
		cout << "4. Xuat DS Phan Loai" << endl;
		cout << "5. Tro Ve Menu Chinh" << endl;
		cout << "=========================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon, 1, 5);

		switch (luaChon) {
		case 1: {
			BANGPHANLOAI bangphanloai;
			nhapBangPhanLoai(bangphanloai,pl);
			them_Dau(pl,bangphanloai);
			break;
		}
		case 2: {
			int vt;
			Nhap("Nhap Vi Tri Can Sua :", vt, 1, DemSoLuong(pl));
			suaPhanTuTaiViTriX(pl, vt,thuoc,ctnx);
			break;

		}
		case 3:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Xoa :", vt, 1, DemSoLuong(pl));
			xoaPhanTuTaiViTriX(pl, vt, thuoc);
			break;
		}
		case 4:
		{
			system("cls");
			MenuMain(pl, kh, ncc, thuoc, pnx, ctnx);
			break;
		}
		case 5:
		{
			system("cls");
			isBack = true;
			break;
		}

		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}
		

	} while (IsContinue("Chon  Menu Bang Phan Loai", isBack)); // Khi chọn 18, thoát chương trình
	
}

void MenuBangThuoc(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx) {
	int luaChon;
	bool isBack = false;
	do {
		system("cls");
		xuat_DSBTNgang(thuoc, true);
		cout << "=========================================" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Them Bang Thuoc" << endl;
		cout << "2. Sua Bang Thuoc" << endl;
		cout << "3. Xoa Bang Thuoc" << endl;
		cout << "4. Tro Ve Menu Chinh" << endl;
		cout << "=========================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon, 1, 5);

		switch (luaChon) {
		case 1: {
			BANGTHUOC bangthuoc;
			nhapBangThuoc(bangthuoc,thuoc,pl);
			them_Dau(thuoc,bangthuoc);
			break;
		}
		case 2: {
			int vt;
			Nhap("Nhap Vi Tri Can Sua :", vt, 1, DemSoLuong(thuoc));
			suaPhanTuTaiViTriX(thuoc, vt,pl, ctnx);
			break;

		}
		case 3:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Xoa :", vt, 1, DemSoLuong(thuoc));
			xoaPhanTuTaiViTriX(thuoc, vt);
			break;
		case 4:
		{
			system("cls");
			isBack = true;
			break;
		}

		}

		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}

	} while (IsContinue("Chon Menu Bang Thuoc", isBack));
}

void MenuBangKhachHang(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx) {
	int luaChon;
	bool isBack = false;
	do {
		system("cls");
		xuat_DSKHNgang(kh, true);
		cout << "=========================================" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Them Bang Khach Hang" << endl;
		cout << "2. Sua Bang Khach Hang" << endl;
		cout << "3. Xoa Bang Khach Hang" << endl;
		cout << "4. Tro Ve Menu Chinh" << endl;
		cout << "=========================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon, 1, 5);

		switch (luaChon) {
		case 1: {
			BANGKHACHHANG khachhang;
			nhapKhachHang(khachhang,kh);
			them_Dau(kh, khachhang);
			break;
		}
		case 2: {
			int vt;
			Nhap("Nhap Vi Tri Can Sua :", vt, 1, DemSoLuong(kh));
			cout << endl;
			suaPhanTuTaiViTriX(kh,vt,pnx,ctnx);
			break;

		}
		case 3:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Xoa :", vt, 1, DemSoLuong(kh));
			xoaPhanTuTaiViTriX(kh,vt);
			break;
		case 4:
		{
			system("cls");
			isBack = true;
			break;
		}

		}

		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}

	} while (IsContinue("Cho Menu Bang Khach Hang", isBack)); // Khi chọn 18, thoát chương trình
}

void MenuBangNhaCungCap(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx) {
	int luaChon;
	bool isBack = false;
	do {
		system("cls");
		xuat_DSNCCngang(ncc, true);
		cout << "=========================================" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Them Bang Nha Cung Cap" << endl;
		cout << "2. Sua Bang Nha Cung Cap" << endl;
		cout << "3. Xoa Bang Nha Cung Cap" << endl;
		cout << "4. Tro Ve Menu Chinh" << endl;
		cout << "=========================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon, 1, 5);

		switch (luaChon) {
		case 1: {
			BANGNHACUNGCAP nhacungcap;
			nhapNhaCungCap(nhacungcap,ncc);
			them_Dau(ncc,nhacungcap);
			break;
		}
		case 2: {
			int vt;
			Nhap("Nhap Vi Tri Can Sua :", vt, 1, DemSoLuong(ncc));
			suaPhanTuTaiViTriX(ncc,vt, pnx, ctnx);
			break;

		}
		case 3:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Xoa :", vt, 1, DemSoLuong(ncc));
			xoaPhanTuTaiViTriX(ncc,vt);
			break;
		case 4:
		{
			system("cls");
			isBack = true;
			break;
		}

		}

		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}

	} while (IsContinue("Nhap Menu Bang Nha Cung Cap", isBack));
}
void MenuBangNhapKho(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx)
{
	int luaChon;
	bool isBack = false;
	do
	{
		system("cls");
		xuat_DSPNXngang(pnx,true,true);
		cout << endl;
		cout << "============ MenuBangNhapKho ============" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Them Phieu Nhap Kho" << endl;
		cout << "2. Sua Phieu Nhap Kho" << endl;
		cout << "3. Xoa Phieu Nhap Kho" << endl;
		cout << "4. Xuat DS Phieu Nhap Kho" << endl;
		cout << "5. Tro Ve Menu Chinh" << endl;
		cout << "=========================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon, 1, 5);
		cout << endl;

		switch (luaChon) {
		case 1:
		{
			PHIEUNHAPXUAT phieu;
			nhapBangNhapKho(phieu, pnx, ncc);
			them_Dau(pnx, phieu);
			do {
				BANGCHITIETNHAPXUAT ct;
				cout << endl;
				cout << "Bang Chi Tiet Nhap Kho " << endl;
				nhapChiTietNhapXuat(ct, ctnx, phieu, thuoc);
				
				them_Dau(ctnx, ct);
				cout << "-----------------------------" << endl;
			} while (IsContinue("Nhap Ban Chi Tiet Nhap Kho"));
			break;
		}
		case 2:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Sua :", vt);
			suaPhanTuTaiViTriX(pnx, vt, kh, ncc, ctnx,true);
			break;
		}
		case 3:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Xoa :", vt);
			xoaPhanTuTaiViTriX(pnx, vt,true, ctnx, thuoc);
			break;
		}
		case 4:
		{
			PHIEUNHAPXUAT phieu=  LayPhanTuPhieuNhapXuatTaiViTri(pnx, true);
			MenuBangChiTietNhapXuat(phieu, thuoc, pnx, ctnx);
			break;
		}
		case 5:
		{
			system("cls");
			isBack = true;
			break;
		}
		
		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}
		 
	}while (IsContinue("Chon Menu Nhap Kho", isBack));
}

void  MenuBangXuatKho(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc,
	NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx)
{
	int luaChon;
	bool isBack = false;
	do
	{
		system("cls");
		xuat_DSPNXngang(pnx, false, true);
		cout << "============ MenuBangXuatKho ============" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Them Phieu Xuat Kho" << endl;
		cout << "2. Sua Phieu Xuat Kho" << endl;
		cout << "3. Xoa Phieu Xuat Kho" << endl;
		cout << "4. Xuat DS Phieu Xuat Kho" << endl;
		cout << "5. Tro Ve Menu Chinh" << endl;
		cout << "=========================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon, 1, 5);

		switch (luaChon) {
		case 1:
		{
			PHIEUNHAPXUAT phieu;
			nhapBangXuatKho(phieu, pnx,kh);
			them_Dau(pnx, phieu);
			do {
				BANGCHITIETNHAPXUAT ct;
				cout << "Bang Chi Tiet Xuat Kho " << endl;
				nhapChiTietNhapXuat(ct, ctnx, phieu, thuoc);

				them_Dau(ctnx, ct);
				cout << "-----------------------------" << endl;
			} while (IsContinue("Nhap Ban Chi Tiet Xuat Kho"));
			break;
		}
		case 2:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Sua :", vt);
			suaPhanTuTaiViTriX(pnx, vt, kh, ncc, ctnx, false);
			break;
		}
		case 3:
		{
			int vt;
			Nhap("Nhap Vi Tri Can Xoa :", vt);
			xoaPhanTuTaiViTriX(pnx, vt,false, ctnx, thuoc);
			break;
		}
		case 4:
		{
			PHIEUNHAPXUAT phieu = LayPhanTuPhieuNhapXuatTaiViTri(pnx, false);
			MenuBangChiTietNhapXuat(phieu, thuoc, pnx, ctnx);
			break;
		}
		case 5:
		{
			system("cls");
			isBack = true;
			break;
		}

		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}

	} while (IsContinue("Chon Menu Nhap Kho", isBack));
}
void MenuBangChiTietNhapXuat(PHIEUNHAPXUAT phieu,NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx) {
	int luaChon;
	bool isBack = false;
	do
	{
		NODEBANGCHITIETNHAPXUATPTR dstam = NULL;
		dstam = laydanhsachbangchitiettumaphieunhap(ctnx, phieu.MaNhapXuat);
		system("cls");
		xuat_DSCTNXNgang(dstam, true);
		cout << "=================MA"+phieu.MaNhapXuat+"=====================" << endl;
		cout << "Chon thao tac:" << endl;
		cout << "1. Them Bang Chi tiet" << endl;
		cout << "2. Sua Bang Chi tiet" << endl;
		cout << "3. Xoa Bang Chi tiet" << endl;
		cout << "4. Tro Ve MENU " << ( phieu.NhapXuat ?"nhap " :"xuat ") << endl;
		cout << "=============================================================" << endl;

		Nhap("Nhap lua chon cua ban: ", luaChon, 1, 4);

		switch (luaChon) {
		case 1:
		{
			BANGCHITIETNHAPXUAT ct;
			cout << "Bang Chi Tiet Xuat Kho " << endl;
			nhapChiTietNhapXuat(ct, ctnx, phieu, thuoc);

			them_Dau(ctnx, ct);
			them_Dau(dstam, ct);
			cout << "-----------------------------" << endl;
			break;
		}
		case 2:
		{
			int vt;
			cout << endl;
			Nhap("Nhap Vi Tri Can Sua :", vt,1,DemSoLuongTheoMaPhieuNhapXuat(ctnx, phieu.MaNhapXuat));
			BANGCHITIETNHAPXUAT chitiet = LayBangChitietNhapXuatTaiViTri(ctnx, vt, phieu.MaNhapXuat);
			suaPhanTuTheoMa(ctnx, chitiet.MaChiTietNhapXuat, thuoc);
			dstam = laydanhsachbangchitiettumaphieunhap(ctnx, phieu.MaNhapXuat);
			break;
		}
		case 3:
		{
			int vt;
			cout << endl;
			Nhap("Nhap Vi Tri Can Xoa :", vt, 1, DemSoLuongTheoMaPhieuNhapXuat(ctnx, phieu.MaNhapXuat));
			BANGCHITIETNHAPXUAT chitiet = LayBangChitietNhapXuatTaiViTri(ctnx, vt, phieu.MaNhapXuat);
			xoaPhanTuTheoMa(ctnx, chitiet.MaChiTietNhapXuat, thuoc);
			dstam = laydanhsachbangchitiettumaphieunhap(ctnx, phieu.MaNhapXuat);
			break;
		}
		case 4:
		{
			system("cls");
			isBack = true;
			break;
		}

		default:
			cout << "Lua chon khong hop le! Vui long chon lai." << endl;
			break;
		}

	} while (IsContinue("Chon Menu chi tiet nhap xuat kho voi ma " +phieu.MaNhapXuat , isBack));
}







