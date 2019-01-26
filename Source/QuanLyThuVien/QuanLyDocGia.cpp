#define _CRT_SECURE_NO_WARNINGS
#define MAX_DG 100
#define MAX_S 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"library.h"
char MaDocGia[MAX_DG][10], HoTen[MAX_DG][20], CMND[MAX_DG][10], NgaySinh[MAX_DG][10], Email[MAX_DG][50], DiaChi[MAX_DG][30];
int ngay[MAX_DG], thang[MAX_DG], nam[MAX_DG], gioitinh[MAX_DG];
int dem = 0;
char CMNDKT[10];
void XemThongTinDocGia(char MaDocGia[10],char HoTen[20],char CMND[10],char NgaySinh[10],char Email[50],char DiaChi[30],int ngay,int thang,int nam,int gioitinh)
{//in ra thong tin cua doc gia ma minh chon
	printf("\nma doc gia: %s\n", MaDocGia);
	printf("ten doc gia: %s\n", HoTen);
	printf("CMND: %s\n", CMND);
	if (gioitinh == 1)printf("gioi tinh: nam\n");
	else printf("gioi tinh: nu\n");
	printf("ngay sinh: %s\n", NgaySinh);
	printf("email: %s\n", Email);
	printf("dia chi: %s\n", DiaChi);
	printf("ngay cap the: %d/%d/%d", ngay, thang, nam);
	printf("\n");
	XuatNgayHetHan(ngay, thang, nam);
}
void XemDanhSachTatCaDocGia(int dem)
{//in ra danh sach cua tat ca cac doc gia
	printf("DANH SACH DOC GIA");
	int i;//i la bien dem doc gia thu ..
	for (i = 0;i < dem;i++)
	{
		printf("\ndoc gia thu            %d\n", i);
		XemThongTinDocGia(MaDocGia[i], HoTen[i], CMND[i], NgaySinh[i], Email[i], DiaChi[i], ngay[i], thang[i], nam[i], gioitinh[i]);
		printf("\n=================================================================");
	}
}
int ThoiGianHetHanTheThuVienCuaDocGiaK(int i)
{
	return (nam[i]+4) * 10000 + thang[i] * 100 + ngay[i];
}
void XemThongTinDocGiaThuK(int i)
{
	printf("\ndoc gia thu            %d\n", i);
	XemThongTinDocGia(MaDocGia[i], HoTen[i], CMND[i], NgaySinh[i], Email[i], DiaChi[i], ngay[i], thang[i], nam[i], gioitinh[i]);
	printf("\n=================================================================");
}
int KiemTraTrungMaDG(int SoDocGia, char MaDoGia[10])
{
	int i;
	for (i = 0;i < SoDocGia;i++)
	{
		if (strcmp(MaDoGia, MaDocGia[i]) == 0)return 1;
	}
	return 0;
}
int ThemDocGia()
{
	int a;//a la bien lua chon xem co tiep tuc nhap thong tin khong
		do
		{
			system("cls");
			printf("NHAP THONG TIN CUA DOC GIA \n");
			printf("doc gia thu                    %d\n", dem);
		flag21:;
			printf("nhap ma doc gia: ");
			gets_s(MaDocGia[dem]);
			NhapMaDocGia(dem);
			if (KiemTraTrungMaDG(dem, MaDocGia[dem]) == 1)
			{
				printf("\n ma doc gia da ton tai, hay nhap ma khac");
				goto flag21;
			}
			printf("neu ban nhap lai ma doc gia ma khac voi ban dau thi nhap 1, khong thi nhap 0:\n");scanf("%d%*c", &a);
			if (a == 1)goto flag21;
			printf("nhap ho va ten: ");
			gets_s(HoTen[dem]);
		flag20:;
			printf("gioi tinh(neu la nu thi nhap 0, neu la nam thi nhap 1): ");scanf("%d%*c", &gioitinh[dem]);
			if (gioitinh[dem] != 1 && gioitinh[dem] != 0)
			{
				printf("\nban nhap nham roi, nhap lai thoi....");
				goto flag20;
			}
			printf("nhap so CMND cua doc gia: ");scanf("%s", &CMND[dem]);
			printf("nhap ngay sinh(theo dang dd/mm/yyyy, vi du: 01/01/2016) bang so: ");scanf("%s", &NgaySinh[dem]);
			printf("nhap dia chi email: ");scanf("%s%*c", &Email[dem]);
			printf("nhap dia chi: ");
			gets_s(DiaChi[dem]);
		flag10:;
			printf("ban nen nhap bang so, dung thu nhap bang chu, xay ra loi tran man hinh\n");
			printf("nhap ngay lap the bang so: ");scanf("%d", &ngay[dem]);
			printf("nhap thang lap the bang so: ");scanf("%d", &thang[dem]);
			printf("nhap nam lap the bang so: ");scanf("%d", &nam[dem]);
			if (KiemTraTinhDungSaiCuaNgay(ngay[dem], thang[dem], nam[dem]) == 0)
			{//neu nguoi dung nhap ngay sai, vi du nhu thang 2 ma nguoi dung nhap 30 ngay thi se yeu cau nhap lai
				printf("\nban nhap sai roi, vui long nhap lai ngay thang nam");
				goto flag10;
			}
			XuatNgayHetHan(ngay[dem], thang[dem], nam[dem]);
			dem++;
		flag2:;
			printf("\nban co muon tiep tuc nhap thong tin khong? Neu co thi nhap 1,khong thi nhap 0:\n");scanf("%d%*c",&a);
			if (a != 1&&a != 0)//hoi nguoi dung co muon tiep tuc nhap thong tin khong, neu khong muon thi co the dung lai
			{
				printf("\nnhap lai\n");
				goto flag2;
			}
		} while (a==1);
	return dem;
}
void SuaThongTin(int n, int m)//n la lua chon thong tin cau nguoi dung, m la doc gia thu
{//thay the cac gia tri bang gia tri da sua ma nguoi dung nhap vao
		int ngaysua, thangsua, namsua, gioitinhsua;
		char Sua[50];
		if (n != 3&& n != 8)
		{
			printf("nhap thong tin sua: ");
			gets_s(Sua);
			if (n == 1)
			{
				strcpy(MaDocGia[m], Sua);//thay thong tin can sua bang thong tin moi vua nhap vao
				NhapMaDocGia(m);
			}
				if (n == 2)strcpy(HoTen[m], Sua);
				if (n == 4)strcpy(CMND[m], Sua);
				if (n == 5)strcpy(NgaySinh[m], Sua);
				if (n == 6)strcpy(Email[m], Sua);
		}
		else
		{
			if (n == 3)
			{
				printf("nhap thong tin sua: ");scanf("%d", &gioitinhsua);
				gioitinh[m] = gioitinhsua;
			}
			if (n == 8)
			{
				printf("nhap ngay sua bang so: ");scanf("%d", &ngaysua);
				printf("nhap thang sua bang so: ");scanf("%d", &thangsua);
				printf("nhap nam sua bang so: ");scanf("%d", &namsua);
				ngay[m] = ngaysua;
				thang[m] = thangsua;
				nam[m] = namsua;
			}
		}
		system("cls");//xuat thong tin doc gia da duoc sua
		printf("doc gia thu             %d", m);
		XemThongTinDocGia(MaDocGia[m], HoTen[m], CMND[m], NgaySinh[m], Email[m], DiaChi[m], ngay[m], thang[m], nam[m], gioitinh[m]);
}
int XoaThongTin(int m)
{
		if (m != dem)
		{
			strcpy(MaDocGia[m], MaDocGia[dem]);//thay the doc gia duoc chon de xoa bang doc gia o vi tri cuoi trong danh sach
			strcpy(HoTen[m], HoTen[dem]);
			gioitinh[m] = gioitinh[dem];
			strcpy(CMND[m], CMND[dem]);
			strcpy(NgaySinh[m], NgaySinh[dem]);
			strcpy(Email[m], Email[dem]);
			strcpy(DiaChi[m], DiaChi[dem]);
			ngay[m] = ngay[dem];
			thang[m] = thang[dem];
			nam[m] = nam[dem];
			dem--;
		}
		else
		{
			dem--;//so doc gia bi tru di mot nguoi vi doc gia duoc chon la nguoi o vi tri cuoi trong danh sach doc gia
		}
		XemDanhSachTatCaDocGia(dem);
		return dem;
}
void TimDocGiaTheoCMND()
{
	printf("nhap so CMND ma ban muon tim: ");scanf("%s", &CMNDKT);
	int i,tam=0;//tam la bien dung kiem tra co tim duoc so cmnd trung khong
	for (i = 0;i < dem;i++)
	{
		if (strcmp(CMNDKT,CMND[i])==0)
		{
			XemThongTinDocGia(MaDocGia[i], HoTen[i], CMND[i], NgaySinh[i], Email[i], DiaChi[i], ngay[i], thang[i], nam[i], gioitinh[i]);
			printf("\n=================================================================");
			tam++;
		}
	}
	if (tam==0)
	{
		printf("\nkhong tim thay du lieu");
		printf("\n=================================================================");
	}
}
int KiemTraChuoiCon(char a[20],char b[20])
{
	//a la chuoi lon
	//b la chuoi nho, kiem tra xem b co phai chuoi con cua a ko
	int i, j,dem=0;
	for (i = 0;a[i] != 0;i++)
	{
		if (a[i] == b[0])
		{
			for (j = 0;b[j] != 0;j++)
			{
				if (a[i + j] != b[j])return 0;
				else dem++;
			}
		}
	}
	if (dem>=2)return 1;
	else return 0;
}
void TimDocGiaTheoTen(char TenTim[10])
{
	int i,tam=0;//bien tam la bien dung de kiem tra co the tim duoc doc gia co cung ten khong
	for (i = 0;i < dem;i++)
	{
		if (KiemTraChuoiCon(HoTen[i], TenTim) == 1)
		{
			XemThongTinDocGia(MaDocGia[i], HoTen[i], CMND[i], NgaySinh[i], Email[i], DiaChi[i], ngay[i], thang[i], nam[i], gioitinh[i]);
			printf("\n=================================================================");
			tam++;
		}
	}
	if(tam==0)
	{
		printf("\nkhong tim thay du lieu");
		printf("\n===================================================================");
	}
}
int SoDG()
{
	while (1);
	return dem;
}
void DocGiaTheoGioiTinh()
{
	int i,Nam=0,Nu=0;
	for (i = 0;i < dem;i++)
	{
		if (gioitinh[i] == 1)Nam++;
		if (gioitinh[i] == 0)Nu++;
	}
	printf("\nco %d doc gia nam", Nam);
	printf("\nco %d doc gia nu", Nu);
}