#define _CRT_SECURE_NO_WARNINGS
#define MAX_DG 100
#define MAX_S 100
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"library.h"
char MaDG[MAX_DG][10];
char MaS[MAX_S][10];
char MaDGKT[10];
char MaSKT[10];
int SoCuon[MAX_S];
int ngaymuonkt, thangmuonkt, nammuonkt;
int ngaytra, thangtra, namtra;
int ngaymuon[MAX_DG], thangmuon[MAX_DG], nammuon[MAX_DG];
int tamp[MAX_S],Thongke[MAX_DG];
int tientra=0;
int DG[MAX_DG][MAX_S];
void GanGiaTri(int SoDocGia,int SoQuyenSach)
{//ham gan gia tri, DG[i][j] la mang duoc dung de xac dinh nguoi dung thu i dang giu bao nhieu cuon sach thu j
	int i,j;
	for (i = 0;i < SoDocGia;i++)
	{
		for (j = 0;j < SoQuyenSach;j++)
			DG[i][j] = 0;
	}
}
void NhapMaDocGia(int dem)
{//nhap vao ma doc gia o muc quan ly doc gia
	printf("nhap lai ma doc gia: ");
	gets_s(MaDG[dem]);
}
void NhapMaSach(int dem)
{//nhap vao ma sach o muc quan ly sach
	printf("nhap lai ma sach: ");
	gets_s(MaS[dem]);
}
void NhapNgayMuon()
{//nhap ngay muon roi xuat ra luon ngay du kien tra
flag14:;
	printf("ban nen nhap bang so, dung thu nhap bang chu, xay ra loi tran man hinh\n");
	printf("nhap ngay muon bang so: ");scanf("%d", &ngaymuonkt);
	printf("nhap thang muon bang so: ");scanf("%d", &thangmuonkt);
	printf("nham nam muon bang so: ");scanf("%d", &nammuonkt);
	if (KiemTraTinhDungSaiCuaNgay(ngaymuonkt, thangmuonkt, nammuonkt) == 1)
	{
		XuatNgayTraDuKien(ngaymuonkt, thangmuonkt, nammuonkt);
	}
	else
	{
		printf("\nban nhap ngay thang nam khong hop le, vui long nhap lai");
		goto flag14;
	}
}
int NhapSoQuyenSach(int dem)
{//nhap so quyen sach cua sach o muc quan ly sach
	printf("nhap so quyen sach cua sach: ");scanf("%d", &SoCuon[dem]);
	return SoCuon[dem];
}
void GanGiaTriTamp(int SoQuyenSach)
{//ham gan gia tri bien tamp de co gia tri bang so cuon sach ban dau, vi trong qua trinh muon, tra sach thi bien SoCuon se bi thay doi
	int i;
	for (i = 0;i < SoQuyenSach;i++)
	{
		tamp[i] = SoCuon[i];
	}
}
int PhieuMuonSach(int SoDocGia,int SoQuyenSach)
{//ham dien thong tin cho phieu muon sach
	int c;
flag13:;
	printf("nhap ma doc gia cua ban: ");scanf("%s", &MaDGKT);//nhap ma doc gia cua nguoi muon
	NhapNgayMuon();
	int i, tam1 = 0;//bien tam1 kiem tra xem co tim duoc doc gia co cung ma doc gia can tim khong
	for (i = 0;i < SoDocGia;i++)
	{//kiem tra ma doc gia de tranh truong hop nguoi ngoai chua dang ki da xin vao muon sach
		if (strcmp(MaDGKT,MaDG[i])==0)
		{
			if ((nammuonkt * 10000 + thangmuonkt * 100 + ngaymuonkt) > (ThoiGianHetHanTheThuVienCuaDocGiaK(i)))
			{
				printf("\nthe thu vien cua ban da het han su dung, vui long them doc gia va xoa thong tin the cu de lam the moi");
				_getch();
				return 0;
			}
			for (int t = 0;t < SoQuyenSach;t++)
			{
				if (DG[i][t] > 0)
				{
					printf("\nban phai tra het sach thi moi duoc quyen muon tiep!!");
					_getch();
					return 0;
				}
			}
			ngaymuon[i] = ngaymuonkt;
			thangmuon[i] = thangmuonkt;
			nammuon[i] = nammuonkt;
			tam1++;
		}
	}

	if (tam1 == 0)
	{//yeu cau nhap lai neu nhu nhap sai
		system("cls");
		printf("\nWARNING!!! ma doc gia cua ban khong tim thay trong danh sach\nban hay nhap lai\n");
		goto flag13;
	}
	else
	{
		 do
		{
			printf("\nnhap ISBN cua sach ma ban muon: ");scanf("%s", &MaSKT);
			int j;
			for (j = 0;j < SoQuyenSach;j++)
			{
				if (strcmp(MaSKT, MaS[j]) == 0)
				{
					if (SoCuon[j] < 0)
					{
						printf("\n!! WARNING: hien sach %s da duoc muon het, ban co the quay lai sau khi co sach moi duoc bo sung");
						_getch();
						return 0;
				}
					SoCuon[j]--;//bien SoCuon chinh la so cuon sach hien gio dang o trong thu vien, nhung cuon bi muon thi SoCuon se tru 1 don vi
				}
			}
		flag21:;
			printf("\nban co muon tiep tuc nhap thong tin de muon tiep khong?\nNeu co thi nhap 1,khong thi nhap 0:\n");scanf("%d", &c);
			if (c != 1 && c != 0)
			{//hoi nguoi dung co muon muon sach khong, neu khong thi co the dung lai, con tro se chay toi flag21
				printf("\nnhap lai\n");
				goto flag21;
			}
		 } while (c == 1);
	}
	int a, b;
	for (a = 0;a < SoDocGia;a++)
	{
		if (strcmp(MaDGKT, MaDG[a]) == 0)
		{
			for (b = 0;b < SoQuyenSach;b++)
			{
				DG[a][b] = DG[a][b] + tamp[b] - SoCuon[b];
			}
		}
	}
	return 1;
}
void DanhSachISBNMuon(int SoDocGia,int SoQuyenSach)
{//ham hien thi thong tin cua nguoi dung hien dang muon bao nhieu quyen sach
	
	int i, j;
	for (i = 0;i < SoDocGia;i++)
	{
		if (strcmp(MaDGKT, MaDG[i]) == 0)
		{
			for (j = 0;j < SoQuyenSach;j++)
			{
				if (DG[i][j]>0)
				{
					//So cuon sach ma nguoi dung giu=So cuon sach ban dau-So cuon sach dang o trong thu vien
					printf("\nban co ma so doc gia %s dang muon %d quyen sach %s\n", MaDGKT, DG[i][j], MaS[j]);
				}
				else if (DG[i][j] < 0)printf("\nban khong muon quyen sach %s",MaS[j]);
			}
		}
	}
}
void PhieuTraSach(int SoDocGia, int SoQuyenSach)
{//ham dien thong tin vao phieu tra sach
flag15:;
	int x, tam = 0, q;
	printf("\nnhap ma doc gia cua ban: ");scanf("%s", &MaDGKT);
	printf("ban nen nhap bang so, dung thu nhap bang chu, xay ra loi tran man hinh\n");
	printf("nhap ngay tra sach hom nay bang so: ");scanf("%d", &ngaytra);
	printf("nhap thang tra sach hom nay bang so: ");scanf("%d", &thangtra);
	printf("nhap nam tra sach hom nay bang so: ");scanf("%d", &namtra);
	for (x = 0;x < SoDocGia;x++)
	{
		if (strcmp(MaDGKT, MaDG[x]) == 0)
		{
			tam++;//bien tam nham kiem tra xem co tim duoc dung doc gia trong danh sach khong, neu khong thi yeu cau nhap lai
		}
	}
	if (tam == 0)
	{
		printf("\nma doc gia ban nhap vao khong co trong danh sach\nvui long nhap lai");
		_getch();
		goto flag15;
	}
	system("cls");
	int e;
	for (e = 0;e < SoDocGia;e++)
	{
		printf("ban muon vao ngay %d/%d/%d", ngaymuon[e], thangmuon[e], nammuon[e]);
		if ((nammuon[e] * 10000 + thangmuon[e] * 100 + ngaymuon[e]) > (namtra * 10000 + thangtra * 100 + ngaytra))
		{
			printf("\nban nhap ngay tra sai roi vi no o truoc ngay muon,nhap lai thoi");
			_getch();
			goto flag15;
		}
	}
flag16:;
	do
	{
		printf("nhap ISBN ma ban muon tra: ");scanf("%s", &MaSKT);
		int i, j;//nhap vao ma sach ma nguoi dung muon tra, moi lan chi tra mot quyen nhung co the tra nhieu lan
		for (i = 0;i < SoDocGia;i++)
		{
			if (strcmp(MaDGKT, MaDG[i]) == 0)
			{
				for (j = 0;j < SoQuyenSach;j++)
				{
					if (strcmp(MaSKT, MaS[j]) == 0)
					{
						DG[i][j] = DG[i][j] - tamp[j] + SoCuon[j];
						SoCuon[j]++;
					}
				}
			}
		}
	flag22:;
		printf("\nNeu ban muon tra sach tiep thi nhap 1, neu khong thi nhap 0:");scanf("%d", &q);
		if (q != 1 && q != 0)
		{//hoi nguoi dung co muon tiep tuc tra sach khong, neu khong thi co the dung lai
			printf("\nban nhap sai cu phap roi, nhap lai:");goto flag22;
		}
	} while (q == 1);
	system("cls");
	DanhSachISBNMuon(SoDocGia, SoQuyenSach);
	printf("\n");
	int k;
	for (k = 0;k < SoDocGia;k++)
	{
		if (strcmp(MaDGKT, MaDG[k]) == 0)
		{
			
			{
				if (KiemTraNgayTreHan(ngaymuon[k], thangmuon[k], nammuon[k], ngaytra, thangtra, namtra) == 1)
				{//ham kiem tra ngay tre han neu tre han thi xuat ra so tien can phai dong, neu khong thi xuat ban da tra sach dung han
					Thongke[k]=1;
					for (int i = 0;i < SoDocGia;i++)
					{
						for (int j = 0;j < SoQuyenSach;j++)
						{
							tientra = tientra + DG[i][j] * GiaSach1(MaS[j]);
						}
					}
					printf("\ncan than voi quyen sach ban dang giu\nneu ban lam mat thi so tien ma ban phai tra de den bu cho thu vien la: %d", tientra);
				}
				else Thongke[k] = 0;
			}
			
		}
	}//neu nguoi dung lam mat sach thi hoc phai den bu cho thu vien so tien bang 200% gia tri quyen sach ho lam mat
}
int SachDuocMuon(int SoDocGia,int SoQuyenSach)
{//ham thong ke so sach duoc muon
	int i, j, thongke = 0;
	for (i = 0;i < SoDocGia;i++)
	{
		for (j = 0;j < SoQuyenSach;j++)
		{
			if (DG[i][j] != 0)thongke = thongke + DG[i][j];//bien thong ke
		}
	}
	return thongke;
}
int NguoiTreHan(int SoDocGia)
{//ham thong ke so nguoi tra sach tre
	int i, j;
	printf("\nDANH SACH DOC GIA TRE HAN");
	printf("\n=============================================================");
	for (i = 0;i < SoDocGia;i++)
	{
		if (Thongke[i] == 1)
		{
			XemThongTinDocGiaThuK(i);
		}
	}
	return 0;
}