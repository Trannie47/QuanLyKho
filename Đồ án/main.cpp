#include "Header.h"


int main()
{
    NODEBANGPHANLOAIPTR listPL;
	NODEBANGKHACHHANGPTR listKH;
	NODEBANGNHACUNCAPPTR listNCC;
	NODEBANGTHUOCPTR listThuoc;
	NODEPHIEUNHAPXUATPTR listPNX;
	NODEBANGCHITIETNHAPXUATPTR listCTNX;
	docFileToanBo(listPL, listKH, listNCC, listThuoc, listPNX, listCTNX);
	MenuMain(listPL, listKH, listNCC, listThuoc, listPNX, listCTNX);
	ghiFileToanBo(listPL, listKH, listNCC, listThuoc, listPNX, listCTNX);
}

