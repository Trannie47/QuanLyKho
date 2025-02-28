#include <iostream>
#include <string>
#include <ctime> // Func Để lấy ngày // đường dẫn làm https://freetuts.net/ref/ham-ctime-trong-c-c++-495.html
#include <iomanip> // Để sử dụng setw và setfill
#include <fstream>
#include <cstdlib>
#include <sstream> 
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
/* struct BANGPHANLOAI
{
    string MaPhanLoai;
    string TenPhanLoai;
};
struct BANGTHUOC
{
    string MaThuoc;
    string TenThuoc;
    string MaPhanLoai;
    int SoLuongTonKho;
    double GiaBan;
};
struct BANGCHITIETNHAPXUAT
{
    string MaChiTietNhapXuat;
    int HanSuDung;
    string MaThuoc;
    string MaNhapXuat;
    bool NhapXuat;// false: xuất, true: nhập 
    int TrangThai;// false: xuất, true: nhập , 2 huỷ bỏ ,3 đang giao 
    int SoLuong;
};
struct BANGNHAPXUAT {
    string MaNhapXuat;
    bool NhapXuat;// false: xuất, true: nhập 
    string NgayNhapXuat;//DDMMYYYY
    string MaKhachHang;
    string MaNCC;
};
struct BANGNHACUNGCAP {
    string MaNCC;
    string TenNCC;
    string DiaChiNCC;
    string SoDienThoaiNCC;
};
struct BANGKHACHHANG {
    string MaKhachHang;
    string  TenKhachHang;
    string DiaChiKhachHang;
    string SoDienThoaiKhachHang;
};*/

struct BANGPHANLOAI
{
    string MaPhanLoai;  
    string TenPhanLoai; 
    string GhiChu;
    bool isDelete;
};
struct BANGTHUOC
{
    string MaThuoc;
    string TenThuoc;
    BANGPHANLOAI PhanLoai; 
    int SoLuongTonKho;
    string NhaSanXuat;
    double GiaBan;
    bool isDelete;
};
struct BANGNHACUNGCAP
{
    string MaNCC;
    string TenNCC;
    string DiaChiNCC;
    string SoDienThoaiNCC;
    bool isDelete;
};

struct BANGKHACHHANG
{
    string MaKhachHang;
    string TenKhachHang;
    string DiaChiKhachHang;
    string SoDienThoaiKhachHang;
    bool isDelete;
};


struct PHIEUNHAPXUAT
{
    string MaNhapXuat;         //nếu N là nhập X là xuất + ddmmyyyy + stt 
    bool NhapXuat;               // false là xuất, true là nhập
    string NgayNhapXuat;         // định dạng DDMMYYYY
    BANGKHACHHANG KhachHang;     // Lồng struct BANGKHACHHANG ( khi xuất mới có , còn nhập vào thì không)
    BANGNHACUNGCAP NhaCungCap;   // Lồng struct BANGNHACUNGCAP ( khi nhập mới có , xuất có bảng khách hàng)
    bool isDelete;
};

struct BANGCHITIETNHAPXUAT
{
    string MaChiTietNhapXuat;  
    int HanSuDung;                      // tinh theo thang
    bool NhapXuat;                      //  false là xuất, true là nhập
    //int TrangThai;                // 0: Xuất, 1: Nhập, 2: Hủy bỏ, 3: Đang giao
    int SoLuong;                    // Số lượng thuốc nhập/xuất
    BANGTHUOC Thuoc;                // Lồng struct BANGTHUOC, một thuốc có thể nằm trong nhiều bản chi tiết nhập xuất
    PHIEUNHAPXUAT phieuNhapXuat;
    bool isDelete;
};


struct LISTBANGPHANLOAI
{
    BANGPHANLOAI data;
    LISTBANGPHANLOAI* next;
};
typedef LISTBANGPHANLOAI* NODEBANGPHANLOAIPTR;

struct LISTBANGNHACUNGCAP
{
    BANGNHACUNGCAP data;
    LISTBANGNHACUNGCAP* next;
};
typedef LISTBANGNHACUNGCAP* NODEBANGNHACUNCAPPTR;

struct LISTBANGKHACHHANG
{
    BANGKHACHHANG data;
    LISTBANGKHACHHANG* next;
};
typedef LISTBANGKHACHHANG* NODEBANGKHACHHANGPTR;

struct LISTBANGCHITIETNHAPXUAT
{
    BANGCHITIETNHAPXUAT data;
    LISTBANGCHITIETNHAPXUAT* next;
};
typedef LISTBANGCHITIETNHAPXUAT* NODEBANGCHITIETNHAPXUATPTR;

struct LISTBANGTHUOC
{
    BANGTHUOC data;
    LISTBANGTHUOC* next;
};
typedef LISTBANGTHUOC* NODEBANGTHUOCPTR;

struct LISTPHIEUNHAPXUAT
{
    PHIEUNHAPXUAT data;
    LISTPHIEUNHAPXUAT* next;
};
typedef LISTPHIEUNHAPXUAT* NODEPHIEUNHAPXUATPTR;



//Hàm cơ bản  
void Nhap(string Chuoi, string& a);  // Để Phân biệt số hoặc chữ 
void Nhap(string Chuoi, int& a); // Viết dùng cho hàm nhập số nguyen
void Nhap(string Chuoi, double& a);// viet dung cho ham so thuc
void Nhap(string Chuoi, string& a, int gioiHan); // Để Phân biệt chữ có giới hạn 
void Nhap(string Chuoi, int& a, int gioiHanMax);// phan biet gioi han nguyen max
void Nhap(string Chuoi, int& a, int gioiHanMin, int gioiHanMax); //phan biet gioi han nho nhat la lon nhat
void Nhap(string Chuoi, double& a, double gioiHanMax);
bool isNamNhuan(int year);// Kiểm tra năm nhuận
bool kiemtrangay(int ngay, int thang, int nam);// Kiểm tra tính hợp lệ của ngày
void NhapNgay(string Chuoi, string& a);
void XuatNgay(string a);
string XuatNgayString(string a  );
bool IsContinue(string a = "", bool next = false);
string LayChuoiNgayHienTai();



// xuất bảng phân loại dọc ngang
void xuatBangPhanLoai(BANGPHANLOAI a,int i = 0);
void xuatBangPhanLoaiNgang(BANGPHANLOAI a,int i = 0);
void xuatBangThuoc(BANGTHUOC a, int i = 0);
void xuatBangThuocNgang(BANGTHUOC a, int i = 0);
void xuatBangNhapKho(PHIEUNHAPXUAT a, int i = 0);
void xuatBangNhapKhoNgang(PHIEUNHAPXUAT a,int i = 0);
void xuatBangXuatKho(PHIEUNHAPXUAT a,int i=0);
void xuatBangXuatKhoNgang(PHIEUNHAPXUAT a, int i = 0);
void xuatNhaCungCapNgang(BANGNHACUNGCAP a, int i=0);
void xuatNhaCungCap(BANGNHACUNGCAP a, int i = 0);
void xuatKhachHang(BANGKHACHHANG a, int i = 0);
void xuatKhachHangNgang(BANGKHACHHANG a,int i = 0);
void XuatChiTietNhapXuat(BANGCHITIETNHAPXUAT a,int i = 0);
void isDelete(BANGTHUOC& a);

// Nhập Khi thêm mới 
void nhapBangPhanLoai(BANGPHANLOAI& a, NODEBANGPHANLOAIPTR list);
void nhapBangThuoc(BANGTHUOC& a, NODEBANGTHUOCPTR list, NODEBANGPHANLOAIPTR listPL);
void nhapBangNhapKho(PHIEUNHAPXUAT& a, NODEPHIEUNHAPXUATPTR listCT,  NODEBANGNHACUNCAPPTR listcc);
void nhapBangXuatKho(PHIEUNHAPXUAT& a, NODEPHIEUNHAPXUATPTR listCT, NODEBANGKHACHHANGPTR listkh);
void nhapNhaCungCap(BANGNHACUNGCAP& a, NODEBANGNHACUNCAPPTR list);
void nhapKhachHang(BANGKHACHHANG& a, NODEBANGKHACHHANGPTR list);
void nhapChiTietNhapXuat(BANGCHITIETNHAPXUAT& a, NODEBANGCHITIETNHAPXUATPTR list, PHIEUNHAPXUAT phieuNhapXuat, NODEBANGTHUOCPTR &listThuoc);


// Khi thay đổi 
void nhapBangPhanLoai(BANGPHANLOAI& a);
void nhapNhaCungCap(BANGNHACUNGCAP& a);
void nhapKhachHang(BANGKHACHHANG& a);
void nhapBangThuoc(BANGTHUOC& a, NODEBANGPHANLOAIPTR list);
void nhapBangNhapKho(PHIEUNHAPXUAT& a, NODEBANGNHACUNCAPPTR list);
void nhapBangXuatKho(PHIEUNHAPXUAT& a,  NODEBANGKHACHHANGPTR list);
void nhapChiTietNhapXuat(BANGCHITIETNHAPXUAT& a, NODEBANGTHUOCPTR& listThuoc);
// bool nhapxuat(PHIEUNHAPXUAT& a);

// BẢNG PHÂN LOẠI
void khoiTaoBANGPHANLOAI(NODEBANGPHANLOAIPTR& list);
int isEmpty(NODEBANGPHANLOAIPTR list);
void giaiPhong(NODEBANGPHANLOAIPTR& list);
NODEBANGPHANLOAIPTR tao_Node_BangPhanLoai(BANGPHANLOAI x);
NODEBANGPHANLOAIPTR them_Dau(NODEBANGPHANLOAIPTR& list, BANGPHANLOAI x);
bool kiemTra_TrungMa(NODEBANGPHANLOAIPTR list, string ma);
NODEBANGPHANLOAIPTR them_Cuoi(NODEBANGPHANLOAIPTR& list, BANGPHANLOAI x);
void xuat_DSPLdoc(NODEBANGPHANLOAIPTR list, bool stt = false);
void xuat_DSPLngang(NODEBANGPHANLOAIPTR list,bool stt = false);
bool docFilePhanLoai(NODEBANGPHANLOAIPTR& list);
bool ghiFilePhanLoai(NODEBANGPHANLOAIPTR list);
NODEBANGPHANLOAIPTR tim_Kiem(NODEBANGPHANLOAIPTR & list, BANGPHANLOAI x);
void xoa_Dau(NODEBANGPHANLOAIPTR& list);
void xoaPhanTuTaiViTriX(NODEBANGPHANLOAIPTR& list, int vitri,NODEBANGTHUOCPTR &listThuoc);
void suaPhanTuTaiViTriX(NODEBANGPHANLOAIPTR& list, int vitri, NODEBANGTHUOCPTR& listThuoc, NODEBANGCHITIETNHAPXUATPTR& listctnx);
int DemSoLuong(NODEBANGPHANLOAIPTR list);
BANGPHANLOAI LayPhanTuBanPhanLoaiTaiViTri(NODEBANGPHANLOAIPTR list);

// Bảng nhà cung cấp
void khoiTaoBANGNHACUNCAP(NODEBANGNHACUNCAPPTR& list);
int isEmpty(NODEBANGNHACUNCAPPTR list);
void giaiPhong(NODEBANGNHACUNCAPPTR& list);
NODEBANGNHACUNCAPPTR tao_Node_BangNhaCungCap(BANGNHACUNGCAP x);
NODEBANGNHACUNCAPPTR them_Dau(NODEBANGNHACUNCAPPTR& list, BANGNHACUNGCAP x);
bool kiemTra_TrungMa(NODEBANGNHACUNCAPPTR list, string ma);
NODEBANGNHACUNCAPPTR them_Cuoi(NODEBANGNHACUNCAPPTR& list, BANGNHACUNGCAP x);
void xuat_DSNCCdoc(NODEBANGNHACUNCAPPTR list,bool stt = false);
void xuat_DSNCCngang(NODEBANGNHACUNCAPPTR list, bool stt = false);
bool docFileNCC(NODEBANGNHACUNCAPPTR& list);
bool ghiFileNCC(NODEBANGNHACUNCAPPTR list);
NODEBANGNHACUNCAPPTR tim_Kiem(NODEBANGNHACUNCAPPTR& list, BANGNHACUNGCAP x);
void xoa_Dau(NODEBANGNHACUNCAPPTR& list);
void xoaPhanTuTaiViTriX(NODEBANGNHACUNCAPPTR& list, int vitri);
void suaPhanTuTaiViTriX(NODEBANGNHACUNCAPPTR& list, int vitri, NODEPHIEUNHAPXUATPTR& listnx, NODEBANGCHITIETNHAPXUATPTR& listctnx);
int DemSoLuong(NODEBANGNHACUNCAPPTR list);
BANGNHACUNGCAP LayPhanTuNhaCungCapTaiViTri(NODEBANGNHACUNCAPPTR list);

// Bảng khách hàng
void khoiTaoBANGKHACHHANG(NODEBANGKHACHHANGPTR& list);
int isEmpty(NODEBANGKHACHHANGPTR list);
void giaiPhong(NODEBANGKHACHHANGPTR& list);
NODEBANGKHACHHANGPTR tao_Node_BangKhachHang(BANGKHACHHANG x);
NODEBANGKHACHHANGPTR them_Dau(NODEBANGKHACHHANGPTR& list, BANGKHACHHANG x);
bool kiemTra_TrungMa(NODEBANGKHACHHANGPTR list, string ma);
NODEBANGKHACHHANGPTR them_Cuoi(NODEBANGKHACHHANGPTR& list, BANGKHACHHANG x);
void nhap_DSKH(NODEBANGKHACHHANGPTR& list);
void xuat_DSKHDoc(NODEBANGKHACHHANGPTR list, bool stt = false);
void xuat_DSKHNgang(NODEBANGKHACHHANGPTR list,bool stt = false);
bool docFileKH(NODEBANGKHACHHANGPTR& list);
bool ghiFileKH(NODEBANGKHACHHANGPTR list);
NODEBANGKHACHHANGPTR tim_Kiem(NODEBANGKHACHHANGPTR& list, BANGKHACHHANG x);
void xoa_Dau(NODEBANGKHACHHANGPTR& list);
void xoaPhanTuTaiViTriX(NODEBANGKHACHHANGPTR& list, int vitri);
void suaPhanTuTaiViTriX(NODEBANGKHACHHANGPTR& list, int vitri, NODEPHIEUNHAPXUATPTR& listnx, NODEBANGCHITIETNHAPXUATPTR& listctnx);
int DemSoLuong(NODEBANGKHACHHANGPTR list);
BANGKHACHHANG LayPhanTuKhachHangTaiViTri(NODEBANGKHACHHANGPTR list);


// Bảng thuốc
void khoiTaoBANGTHUOC(NODEBANGTHUOCPTR& list);
int isEmpty(NODEBANGTHUOCPTR list);
void giaiPhong(NODEBANGTHUOCPTR& list);
int DemSoLuong(NODEBANGTHUOCPTR list);
NODEBANGTHUOCPTR tao_Node_BangThuoc(BANGTHUOC x);
NODEBANGTHUOCPTR them_Dau(NODEBANGTHUOCPTR& list, BANGTHUOC x);
bool kiemTra_TrungMa(NODEBANGTHUOCPTR list, string ma);
NODEBANGTHUOCPTR them_Cuoi(NODEBANGTHUOCPTR& list, BANGTHUOC x);
void nhap_DSBT(NODEBANGTHUOCPTR& list,NODEBANGPHANLOAIPTR listpl);
void xuat_DSBTDoc(NODEBANGTHUOCPTR list,bool stt = false);
void xuat_DSBTNgang(NODEBANGTHUOCPTR list,bool stt = false);
bool docFileBangThuoc(NODEBANGTHUOCPTR& list);
bool ghiFileBangThuoc(NODEBANGTHUOCPTR list);
NODEBANGTHUOCPTR tim_Kiem(NODEBANGTHUOCPTR& list, BANGTHUOC x);
void xoa_Dau(NODEBANGTHUOCPTR& list);
void xoaPhanTuTaiViTriX(NODEBANGTHUOCPTR& list, int vitri);
void suaPhanTuTaiViTriX(NODEBANGTHUOCPTR& list, int vitri,NODEBANGPHANLOAIPTR listPL ,NODEBANGCHITIETNHAPXUATPTR& listctnx);
void tinhTongSoLuongThuoc(BANGTHUOC& thuoc, BANGCHITIETNHAPXUAT ctnx, bool isDelele = false);
void CapNhatThuoc(NODEBANGTHUOCPTR& listThuoc, BANGTHUOC thuoc, NODEBANGCHITIETNHAPXUATPTR& listctnx);
void CapNhatThuoc(NODEBANGTHUOCPTR& listThuoc, BANGTHUOC thuoc);
bool CapNhatSoLuongThuoc(NODEBANGTHUOCPTR& listThuoc, string mathuoc, int soLuong);
BANGTHUOC LayPhanTuBangThuocTaiViTri(NODEBANGTHUOCPTR list);


// Phiếu nhập xuất
void khoiTaoPHIEUNHAPXUAT(NODEPHIEUNHAPXUATPTR& list);
int isEmpty(NODEPHIEUNHAPXUATPTR list);
void giaiPhong(NODEPHIEUNHAPXUATPTR& list);
NODEPHIEUNHAPXUATPTR tao_Node_PhieuNhapXuat(PHIEUNHAPXUAT x);
NODEPHIEUNHAPXUATPTR them_Dau(NODEPHIEUNHAPXUATPTR& list, PHIEUNHAPXUAT x);
bool kiemTra_TrungMa(NODEPHIEUNHAPXUATPTR list, string ma);
NODEPHIEUNHAPXUATPTR them_Cuoi(NODEPHIEUNHAPXUATPTR& list, PHIEUNHAPXUAT x);
void nhap_DSPNX(NODEPHIEUNHAPXUATPTR& list, NODEBANGNHACUNCAPPTR listkh);
void xuat_DSPNX(NODEPHIEUNHAPXUATPTR list, bool nhapxuat);
void xuat_DSPNXngang(NODEPHIEUNHAPXUATPTR list, bool nhapxuat,bool stt = false);
bool docFilePhieuNhapXuat(NODEPHIEUNHAPXUATPTR& list);
bool ghiFilePhieuNhapXuat(NODEPHIEUNHAPXUATPTR list);
NODEPHIEUNHAPXUATPTR tim_Kiem(NODEPHIEUNHAPXUATPTR& list, PHIEUNHAPXUAT x);
void xoa_Dau(NODEPHIEUNHAPXUATPTR& list);
void xoaPhanTuTaiViTriX(NODEPHIEUNHAPXUATPTR& list, int vitri, bool nhapxuat, NODEBANGCHITIETNHAPXUATPTR& listCT, NODEBANGTHUOCPTR& listthuoc);
void suaPhanTuTaiViTriX(NODEPHIEUNHAPXUATPTR& list, int vitri, NODEBANGKHACHHANGPTR listkh, NODEBANGNHACUNCAPPTR listncc, NODEBANGCHITIETNHAPXUATPTR& listctnx, bool nhapxuat);
int DemSoLuong(NODEPHIEUNHAPXUATPTR list, bool nhapxuat);
PHIEUNHAPXUAT LayPhanTuPhieuNhapXuatTaiViTri(NODEPHIEUNHAPXUATPTR list, bool nhapxuat);

// Bảng chi tiết nhập xuất
void khoiTaoBANGCHITIETNHAPXUAT(NODEBANGCHITIETNHAPXUATPTR& list);
int isEmpty(NODEBANGCHITIETNHAPXUATPTR list);
void giaiPhong(NODEBANGCHITIETNHAPXUATPTR& list);
NODEBANGCHITIETNHAPXUATPTR tao_Node_BangChiTietNhapXuat(BANGCHITIETNHAPXUAT x);
NODEBANGCHITIETNHAPXUATPTR them_Dau(NODEBANGCHITIETNHAPXUATPTR& list, BANGCHITIETNHAPXUAT x);
bool kiemTra_TrungMa(NODEBANGCHITIETNHAPXUATPTR list, string ma);
NODEBANGCHITIETNHAPXUATPTR them_Cuoi(NODEBANGCHITIETNHAPXUATPTR& list, BANGCHITIETNHAPXUAT x);
void nhap_DSCTNX(NODEBANGCHITIETNHAPXUATPTR& list, PHIEUNHAPXUAT phieuNhapXuat, NODEBANGTHUOCPTR listThuoc);
void xuat_DSCTNX(NODEBANGCHITIETNHAPXUATPTR list);
void xuat_DSCTNXNgang(NODEBANGCHITIETNHAPXUATPTR list,bool stt = false);
bool docFileCTNX(NODEBANGCHITIETNHAPXUATPTR& list);
bool ghiFileCTNX(NODEBANGCHITIETNHAPXUATPTR list);
NODEBANGCHITIETNHAPXUATPTR tim_Kiem(NODEBANGCHITIETNHAPXUATPTR& list, BANGCHITIETNHAPXUAT x);
void xoa_Dau(NODEBANGCHITIETNHAPXUATPTR& list);
void xoaPhanTuTaiViTriX(NODEBANGCHITIETNHAPXUATPTR& list, int vitri, NODEBANGTHUOCPTR& listthuoc);
void suaPhanTuTaiViTriX(NODEBANGCHITIETNHAPXUATPTR& list, int vitri, NODEBANGTHUOCPTR& listthuoc);
void xoaPhanTuTheoMa(NODEBANGCHITIETNHAPXUATPTR& list, string Ma, NODEBANGTHUOCPTR& listthuoc);
void suaPhanTuTheoMa(NODEBANGCHITIETNHAPXUATPTR& list, string Ma, NODEBANGTHUOCPTR& listthuoc);
NODEBANGCHITIETNHAPXUATPTR laydanhsachbangchitiettumaphieunhap(NODEBANGCHITIETNHAPXUATPTR& list, string ma);
int DemSoLuongTheoMaPhieuNhapXuat(NODEBANGCHITIETNHAPXUATPTR list, string maphieu);
BANGCHITIETNHAPXUAT LayBangChitietNhapXuatTaiViTri(NODEBANGCHITIETNHAPXUATPTR list, int vt,string maphieu);

//

// menu
void MenuMain(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void docFileToanBo(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void ghiFileToanBo(NODEBANGPHANLOAIPTR pl, NODEBANGKHACHHANGPTR kh, NODEBANGNHACUNCAPPTR ncc, NODEBANGTHUOCPTR thuoc, NODEPHIEUNHAPXUATPTR pnx, NODEBANGCHITIETNHAPXUATPTR ctnx);

void MenuBangPhanLoai(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void MenuBangThuoc(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void MenuBangKhachHang(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void MenuBangNhaCungCap(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void MenuBangNhapKho(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void MenuBangXuatKho(NODEBANGPHANLOAIPTR& pl, NODEBANGKHACHHANGPTR& kh, NODEBANGNHACUNCAPPTR& ncc, NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);
void MenuBangChiTietNhapXuat(PHIEUNHAPXUAT phieu,NODEBANGTHUOCPTR& thuoc, NODEPHIEUNHAPXUATPTR& pnx, NODEBANGCHITIETNHAPXUATPTR& ctnx);