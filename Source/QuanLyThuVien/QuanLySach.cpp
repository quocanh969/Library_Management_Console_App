#define _CRT_SECURE_NO_WARNINGS
#define MAX_DG 100
#define MAX_S 100
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"library.h"
int dem1 = 0;//bien dem1 la so quyen sach co trong thu vien
char MaSach[MAX_S][10], TenSach[MAX_S][30], TacGia[MAX_S][20], NXB[MAX_S][30];
int NamXB[MAX_S], SoQuyen[MAX_S],GiaSach[MAX_S], TheLoai[MAX_S];
char MaSachKT[10];
int ThongKe1 = 0, ThongKe2 = 0, ThongKe3 = 0;
void XemDanhSachSach(char MaSach[10],char TenSach[30],char TacGia[20],char NXB[30],int NamXB,int TheLoai,int GiaSach,int SoQuyen)
{
	//xem danh sach cac sach co trong thu vien
	printf("\nma sach: %s", MaSach);
	printf("\nten sach: %s", TenSach);
	printf("\nten tac gia: %s", TacGia);
	printf("\nten nha xuat ban: %s", NXB);
	printf("\nnam xuat ban: %d", NamXB);
	if (TheLoai == 1)printf("\nthe loai: Hoc Tap");
	else if (TheLoai == 2)printf("\nthe loai: Doi Song");
	else if (TheLoai == 3)printf("\nthe loai: Giai Tri");
	printf("\nsach co gia: %d dong", GiaSach);
	printf("\nso quyen: %d", SoQuyen);
}
void XemDanhSachTatCaSach(int dem)
{//in ra danh sach tat ca sach
	printf("\nDANH SACH SACH");
	int i;
	for (i = 0;i < dem;i++)
	{
		printf("\nsach thu              %d\n", i);
		XemDanhSachSach(MaSach[i], TenSach[i], TacGia[i], NXB[i], NamXB[i], TheLoai[i], GiaSach[i], SoQuyen[i]);
		printf("\n==================================================================");
	}
}
int KiemTraTrungMaS(int SoQuyenSach, char MaSa[10])
{
	int i;
	for (i = 0;i < SoQuyenSach;i++)
	{
		if (strcmp(MaSa, MaSach[i]) == 0)return 1;
	}
	return 0;
}
int ThemSach()
{
	int b;//b la bien lua chon co tiep tuc them sach hay ngung lai
	do
	{
		printf("Luu y: the loai sach chi co 3 loai: hoc tap, giai tri, doi song\n");
		printf("sach thu                %d\n", dem1);
	flag22:;
		printf("nhap ma sach: ");
		gets_s(MaSach[dem1]);
		NhapMaSach(dem1);
		if (KiemTraTrungMaS(dem1, MaSach[dem1]) == 1)
		{
			printf("\n  ma sach da ton tai, ban hay nhap ma khac");
			goto flag22;
		}
		printf("neu ban nhap lai ma doc gia ma khac voi ban dau thi nhap 1, khong thi nhap 0:\n");scanf("%d%*c", &b);//ki hieu %*c nham de bo qua ki tu \n trong scanf, nhu v thi ta moi co the dung ham gets_s o duoi
		if (b == 1)goto flag22;
		printf("nhap ten sach: ");
		gets_s(TenSach[dem1]);
		printf("nhap ten tac gia: ");
		gets_s(TacGia[dem1]);
		printf("nhap ten nha xuat ban: ");
		gets_s(NXB[dem1]);
		printf("nhap nam xuat ban bang so: ");scanf("%d", &NamXB[dem1]);
		printf("nhap the loai sach bang cach chon cac so 1,2,3:\n1 la Hoc Tap\n2 la Doi Song\n3 la Giai Tri");
	flag8:;//thu vien chi phan loai thanh 3 loai sach, nen nguoi dung co the nhap 1,2,3 de su dung de dang hon
		printf("\nnhap ma the loai sach: ");scanf("%d", &TheLoai[dem1]);
		if (TheLoai[dem1] != 1&&TheLoai[dem1]!=2&&TheLoai[dem1]!=3)
		{
			printf("============nhap lai=============");
			goto flag8;
		}
		printf("nhap gia tien cua sach: ");scanf("%d", &GiaSach[dem1]);
		SoQuyen[dem1]=NhapSoQuyenSach(dem1);
		dem1++;
	flag9:;
		printf("\nban co muon tiep tuc nhap thong tin khong? Neu co thi nhap 1,khong thi nhap 0:");scanf("%d%*c", &b);
		if (b != 1&&b != 0)
		{
			printf("\nnhap lai");goto flag9;
		}
		system("cls");
	} while (b == 1);
	return dem1;
}
void SuaThongTinSach(int n, int m)
{
	//thay the cac gia tri bang gia tri da sua ma nguoi dung nhap vao
		int NamXBSua, SoQuyenSua,GiaSachSua,TheLoaiSua;
		char Sua[50];
		if (n != 7 && n != 8)
		{
			printf("\nnhap thong tin sua: ");
			gets_s(Sua);
			if (n == 1)
			{
				strcpy(MaSach[m], Sua);//thay the thong tin duoc chon bang thong tin vua nhap
				NhapMaSach(m);
			}
				if (n == 2)strcpy(TenSach[m], Sua);
				if (n == 3)strcpy(TacGia[m], Sua);
				if (n == 4)strcpy(NXB[m], Sua);
		}
		else if (n == 5)
		{
			printf("\nnhap the loai sach sua bang cach chon cac so 1,2,3:\n1 la Hoc Tap\n2 la Doi Song\n3 la Giai Tri");scanf("%d", &TheLoaiSua);
			TheLoai[m] = TheLoaiSua;
		}
		else if (n == 6)
		{
			printf("\nnhap thong sua bang so: ");scanf("%d", &GiaSachSua);
			GiaSach[m] = GiaSachSua;
		}
		else if (n == 7)
		{
			printf("\nnhap thong tin sua bang so: ");scanf("%d", &NamXBSua);
			NamXB[m] = NamXBSua;
		}
		else if (n == 8)
		{
			printf("\nnhap thong tin sua bang so: ");scanf("%d", &SoQuyenSua);
			SoQuyen[m] = SoQuyenSua;
		}
}
int XoaSach(int m)
{
		if (m != dem1-1)
		{
			strcpy(MaSach[m], MaSach[dem1-1]);//thay the thong tin sasch duoc chon bang thong tin cua sach o vi tri cuoi roi giam so sach di 1
			strcpy(TenSach[m], TenSach[dem1-1]);
			strcpy(TacGia[m], TacGia[dem1-1]);
			strcpy(NXB[m], NXB[dem1-1]);
			TheLoai[m] = TheLoai[dem1-1];
			GiaSach[m] = GiaSach[dem1-1];
			NamXB[m] = NamXB[dem1-1];
			SoQuyen[m] = SoQuyen[dem1-1];
			dem1--;
		}
		if (m == 5)
		{
			dem1--;
		}
		XemDanhSachTatCaSach(dem1);
		return dem1;
}
void XemThongTinSach(char MaSach[10], char TenSach[30], char TacGia[20], char NXB[30], int TheLoai, int GiaSach, int NamXB, int SoQuyen)
{
	//printf("\nQuyen sach thu                  %d", dem1);
	printf("\nISBN cua sach la: %s", MaSach);
	printf("\nTen cua sach la: %s", TenSach);
	printf("\nTac gia cua sach la: %s", TacGia);
	printf("\nNha xuat ban cua sach la: %s", NXB);
	printf("\nThe loai cua sach la: %s", TheLoai);
	if (TheLoai == 1)printf("\nthe loai: Hoc Tap");
	else if (TheLoai == 2)printf("\nthe loai: Doi Song");
	else if (TheLoai == 3)printf("\nthe loai: Giai Tri");
	printf("\nNam xuat ban cua sach la: %d", NamXB);
	printf("\nSach co %d quyen", SoQuyen);
}
void TimKiemSachTheoISBN()
{
	printf("\nnhap ISBN ma ban muon tim: ");scanf("%s", &MaSachKT);
	int i,tam=0;//bien tam dung den kiem tra xem co tim duoc sach co cung ISBN
	for (i = 0;i < dem1;i++)
	{
		if (strcmp(MaSachKT,MaSach[i])==0)
		{
			XemDanhSachSach(MaSach[i], TenSach[i], TacGia[i], NXB[i], NamXB[i], TheLoai[i], GiaSach[i], SoQuyen[i]);
			printf("\n==================================================================");
			tam++;
		}
	}
	if (tam==0)
	{
		printf("\nkhong tim thay du lieu");
		printf("\n===================================================================");
	}
}
void TimKiemSachTheoTen(char TenTim[30])
{
	int i, tam = 0;
	for (i = 0;i < dem1;i++)
	{
		if (KiemTraChuoiCon(TenSach[i], TenTim) == 1)
		{
			XemDanhSachSach(MaSach[i], TenSach[i], TacGia[i], NXB[i], NamXB[i], TheLoai[i], GiaSach[i], SoQuyen[i]);
			printf("\n===================================================================");
			tam++;
		}
	}
	if (tam==0)
	{
		printf("\nkhong tim thay du lieu");
		printf("\n=======================================================================");
	}
}
int SoSachCoTrongThuVien()
{
	int i,tong=0;
	for (i = 0;i < dem1;i++)
	{
		tong = tong + SoQuyen[i];
	}
	return tong;
}
void SachTheoTheLoai()
{
	int i;
	for (i = 0;i < dem1;i++)
	{
		if (TheLoai[i] == 1)ThongKe1=ThongKe1+SoQuyen[i];
		if (TheLoai[i] == 2)ThongKe2=ThongKe2+SoQuyen[i];
		if (TheLoai[i] == 3)ThongKe3=ThongKe3+SoQuyen[i];
	}
	printf("\nco %d sach thuoc the loai hoc tap", ThongKe1);
	printf("\nco %d sach thuoc the loai giai tri", ThongKe2);
	printf("\nco %d sach thuoc the loai giai tri*",ThongKe3);
}
int GiaSach1(char MaS[10])
{
	int giatien,i;
	for (i = 0;i < dem1;i++)
	{
		if (strcmp(MaS,MaSach[i])==0)return GiaSach[i];
	}
}