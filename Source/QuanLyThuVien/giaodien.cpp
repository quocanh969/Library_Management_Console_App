#include<stdio.h>
#include"library.h"
void MenuChinh()
{
	//ham thiet lap menu chinh de nguoi dung lua chon
	printf("******************************MENU GIAO TIEP******************************\n");
	printf("* Ban nhap vao mot so de co the chon cac chuc nang sau:                  *\n");
	printf("*     1. Quan ly doc gia                                                 *\n");
	printf("*     2. Quan ly sach                                                    *\n");
	printf("*     3. Lap phieu muon sach                                             *\n");
	printf("*     4. Lap phieu tra sach                                              *\n");
	printf("*     5. Thong ke co ban                                                 *\n");
	printf("*     6. Thoat                                                           *\n");
	printf("*                                                                        *\n");
	printf("**************************************************************************\n");
}
void Menu1()
{
	//ham thiet lap menu cua Quan ly doc gia
	printf("******************************QUAN LY DOC GIA*****************************\n");
	printf("* Ban nhap vao mot so de co the chon cac chuc nang sau:                  *\n");
	printf("*     1. Xem danh sach doc gia trong thu vien                            *\n");
	printf("*     2. Them doc gia                                                    *\n");
	printf("*     3. Chinh sua thong tin doc gia                                     *\n");
	printf("*     4. Xoa thong tin doc gia                                           *\n");
	printf("*     5. Tim kiem doc gia theo CMND                                      *\n");
	printf("*     6. Tim kiem sach theo ten                                          *\n");
	printf("*     7. Thoat                                                           *\n");
	printf("*                                                                        *\n");
	printf("**************************************************************************\n");
}
void Menu2()
{
	//ham thiet lap menu cua Quan ly sach
	printf("********************************QUAN LY SACH******************************\n");
	printf("* Ban nhap vao mot so de co the chon cac chuc nang sau:                  *\n");
	printf("*     1. Xem danh sach cac sach trong thu vien                           *\n");
	printf("*     2. Them sach                                                       *\n");
	printf("*     3. Chinh sua thong tin mot quyen sach                              *\n");
	printf("*     4. Xoa thong tin sach                                              *\n");
	printf("*     5. Tim kiem sach theo ISBN                                         *\n");
	printf("*     6. Tim kiem sach theo ten sach                                     *\n");
	printf("*     7. Thoat                                                           *\n");
	printf("*                                                                        *\n");
	printf("**************************************************************************\n");
}
void Menu5()
{
	//ham thiet lap menu cua Thong ke co ban
	printf("****************************THONG KE CO BAN*******************************\n");
	printf("* Ban nhap vao mot so de co the chon cac chuc nang sau:                  *\n");
	printf("*     1. Thong ke so luong sach trong thu vien                           *\n");
	printf("*     2. Thong ke so luong sach theo the loai                            *\n");
	printf("*     3. Thong ke so luong doc gia                                       *\n");
	printf("*     4. Thong ke so luong doc gia theo gioi tinh                        *\n");
	printf("*     5. Thong ke so sach dang duoc muon                                 *\n");
	printf("*     6. Thong ke danh sach doc gia bi tre han                           *\n");
	printf("*     7. Thoat                                                           *\n");
	printf("*                                                                        *\n");
	printf("**************************************************************************\n");
}
void MenuChonThongTin()
{
	//ham thiet lap menu chon thong tin can chinh sua
	printf("********************CHON THONG TIN CAN CHINH SUA**************************\n");
	printf("* Ban nhap vao mot so de co the chon cac thong tin sau:                  *\n");
	printf("*     1. Chinh sua Ma doc gia                                            *\n");
	printf("*     2. Chinh sua Ho ten doc gia                                        *\n");
	printf("*     3. Chinh sua Gioi tinh doc gia                                     *\n");
	printf("*     4. Chinh sua CMND doc gia                                          *\n");
	printf("*     5. Chinh sua Ngay sinh doc gia                                     *\n");
	printf("*     6. Chinh sua Email doc gia                                         *\n");
	printf("*     7. Chinh sua Dia chi doc gia                                       *\n");
	printf("*     8. Chinh sua Ngay thang lap the doc gia                            *\n");
	printf("*     9. Thoat                                                           *\n");
	printf("*                                                                        *\n");
	printf("**************************************************************************\n");
}
void MenuChonThongTinSach()
{
	//ham thiet lap menu chon thong tin can chinh sua
	printf("********************CHON THONG TIN CAN CHINH SUA**************************\n");
	printf("* Ban nhap vao mot so de co the chon cac thong tin sau:                  *\n");
	printf("*     1. Chinh sua Ma sach                                               *\n");
	printf("*     2. Chinh sua Ten sach                                              *\n");
	printf("*     3. Chinh sua Tac gia sach                                          *\n");
	printf("*     4. Chinh sua NXB cua sach                                          *\n");
	printf("*     5. Chinh sua The loai cua sach                                     *\n");
	printf("*     6. Chinh sua Gia de dat sach                                       *\n");
	printf("*     7. Chinh sua Nam xuat ban sach                                     *\n");
	printf("*     8. Chinh sua So quyen sach                                         *\n");
	printf("*     9. Thoat                                                           *\n");
	printf("*                                                                        *\n");
	printf("**************************************************************************\n");
}
void MenuThongKe()
{
	//ham thiet lap menu thong ke
	printf("********************//////////THONG KE//////////**************************\n");
	printf("* Ban nhap vao mot so de co the chon cac thong tin sau:                  *\n");
	printf("*     1. Thong ke so luong sach trong thu vien                           *\n");
	printf("*     2. Thong ke so luong sach theo the loai                            *\n");
	printf("*     3. Thong ke so luong doc gia                                       *\n");
	printf("*     4. Thong ke so luong doc gia theo gioi tinh                        *\n");
	printf("*     5. Thong ke so luong sach dang duoc muon                           *\n");
	printf("*     6. Thong ke so luong doc gia bi tre han                            *\n");
	printf("*     7. Thoat                                                           *\n");
	printf("*                                                                        *\n");
	printf("**************************************************************************\n");
}