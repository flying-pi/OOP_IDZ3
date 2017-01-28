#pragma once

#ifndef MYMATRF_H
#define MYMATRF_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>

//_getch ���������� � ������������ �������,  ���������� � ����������� ����������
//conio.h is a C header file used mostly by MS-DOS compilers to provide console
// input/output.[1] It is not part of the C standard library or ISO C, nor is it defined by POSIX.

//��������� ������ ���������� ��������� ��������,  ��������� 1 �� ����� ��������� ��������
// 1 �������� ����� ����� ������
#define DiagFile(A)if(!A){cerr<<#A":������ ������ � ������";exit(1);}
using namespace std;

//���������� � ���������� ������� ������ ����� ���������� (��� ���������� ide �����
// � ������������� ������������ ����� ��������� � ��� ������ ��������� ��������� ����� � �������)
//�� �������� ���������� ���������� ����� � ��������, �� ����� ������� ������ ������
class MyMatrix
{
public:
	MyMatrix(int, int, int);
	void inKeyMatrix(int, int);
	void genMatrix(int, int);
	void printMatrix(int, int);
	void SortMatrixStrok(int, int, int(MyMatrix::*)(short, short));
	void SortMatrixStolb(int, int, int(MyMatrix::*)(short, short));

    void MinMaxStrokMatrix(int rowCount, int collumnCount,int * out, int(MyMatrix::*)(short, short));
    void MinMaxStolbMatrix(int rowCount, int collumnCount,int * out, int(MyMatrix::*)(short, short));
    int MinMaxElemMatrix(int rowCount, int collumnCount, int(MyMatrix::*)(short, short));
    void SumMatrixStrok(int rowCount,int collumnCount,int * out);
    void SumMatrixStolb(int rowCount,int collumnCount,int * out);
    int SumElemMatrix(int rowCount, int collumnCount);
    //�� ����������� �� �� ����� ������������� ������ ����� ����������
    void transpMatrix(int rowCount,int collumnCount);
	int incr(short, short);
	int decr(short, short);
	void outMatrFileBin();
	void outMatrFileBinVar(int, int);
	MyMatrix& inMatrFileBin(int, int);
	MyMatrix* inMatrFileBinVar(int, int);
	void outMatrFileTxt(int, int);
	MyMatrix& inMatrFileTxt(int, int);
private:
	void swap(short*, short*);
	short int matrix[50][20];
};
#endif