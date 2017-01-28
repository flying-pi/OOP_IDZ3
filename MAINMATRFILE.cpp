#include <algorithm>

#include "MATRFILE.h"
#include<locale.h>  



using namespace std;
void printArray(short *, int);

//���������� ������ �� ��������� � ��������������������� �++.
// ��� ������� ������������� ������� ������������ ������ ���������
//��������� �� ��������� �������� ��� ���������� �������� � ���������� ������� ���������
ofstream coutFile;

void printLinerArray(int *array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << '\t';
		coutFile << array[i] << '\t';
	}
}

int main() {
	setlocale(LC_ALL, ".1251");

	coutFile.open("outfile.d");
	DiagFile(coutFile);
	set_new_handler(0);
	int strok, stolb, KeyGen, operation;
	//������������ ���� ������� � ���� � �� �������.  ����� ���� ������������ ��� ���� ��� ������������
	// ������� � ���������� ������������ �������
	for (;;) {
		cout << "��������� ������� ����� �����:\n"
			<< "1-���� ������ � ����������\n"
			<< "2-������������� �����\n"
			<< "3-�������� ������� � ����\n"
			<< "4-������������ ������� �� �����\n"
			<< "5-����������� �������� � ������� �������\n"
			<< "6-������������ �������� � ������� �������\n"
			<< "7-����������� �������� � �������� �������\n"
			<< "8-������������ �������� � �������� �������\n"
			<< "9-����������� ������� �������\n"
			<< "10-������������ ������� �������\n"
			<< "11-����� ��������� �� ������� �������\n"
			<< "12-����� ��������� �� �������� �������\n"
			<< "13-����� ���� ��������� �������\n"
			<< "14-���������� �� ����������� ��������� ����� �������\n"
			<< "15-���������� �� �������� ��������� ����� �������\n"
			<< "16-���������� �� ����������� ��������� �������� �������\n"
			<< "17-���������� �� �������� ��������� �������� �������\n"
			<< "18-���������������� �������, ���� strok=stolb\n"
			<< "19-������� � ��������� ������ �������\n"
			<< "20-��������� ���������\n";
		coutFile << "��������� ������� ����� �����:\n"
			<< "1-���� ������ � ����������\n"
			<< "2-������������� �����\n"
			<< "3-�������� ������� � ����\n"
			<< "4-������������ ������� �� �����\n"
			<< "5-����������� �������� � ������� �������\n"
			<< "6-������������ �������� � ������� �������\n"
			<< "7-����������� �������� � �������� �������\n"
			<< "8-������������ �������� � �������� �������\n"
			<< "9-����������� ������� �������\n"
			<< "10-������������ ������� �������\n"
			<< "11-����� ��������� �� ������� �������\n"
			<< "12-����� ��������� �� �������� �������\n"
			<< "13-����� ���� ��������� �������\n"
			<< "14-���������� �� ����������� ��������� ����� �������\n"
			<< "15-���������� �� �������� ��������� ����� �������\n"
			<< "16-���������� �� ����������� ��������� �������� �������\n"
			<< "17-���������� �� �������� ��������� �������� �������\n"
			<< "18-���������������� �������, ���� strok=stolb\n"
			<< "19-������� � ��������� ������ �������\n"
			<< "20-��������� ���������\n";
		coutFile.flush();
		cout << "\n������� ���������� ����� �� [1-50] � �������� �� [1-20] �������:\n"
			<< "�����=";
		coutFile << "\n������� ���������� ����� ��[1 - 50] � �������� ��[1 - 20] �������:\n"
			<< "�����=";
		scanf("%d", &strok);
		coutFile << strok << endl;
		cout << "��������=";
		coutFile << "��������=";
		scanf("%d", &stolb);
		coutFile << stolb << endl;
		cout << "���� ������ � ����������(1) ��� �������������(2)?";
		coutFile << "���� ������ � ����������(1) ��� �������������(2)? ";
		scanf("%d", &KeyGen);
		coutFile << KeyGen << endl;
		//��� ob1(� ������������ ������� �������� ���) ����������,  ��������� �� matrix �� �� �������� ����������
		int *buf = new int[max(strok, stolb)];
		MyMatrix matrix(strok, stolb, KeyGen);
		do {
			cout << "\n\n������� �������� ��������� ������� �� ������ [3-20]: ";
			coutFile << "\n\n������� �������� ��������� ������� �� ������ [3-20]: ";
			scanf("%d", &operation);
			coutFile << operation << endl;

			//���������� �����, ����� ���� ������������ ��������� ���� �� ������������
			switch (operation) {
			case 3:
				matrix.outMatrFileBin();
				matrix.outMatrFileBinVar(strok, stolb);
				matrix.outMatrFileTxt(strok, stolb);
				break;
			case 4:
				matrix.inMatrFileBin(strok, stolb).inMatrFileBinVar(strok, stolb)->
					inMatrFileTxt(strok, stolb);
				break;
			case 5:
				matrix.MinMaxStrokMatrix(strok, stolb, buf, &MyMatrix::incr);
				cout << "\n����������� �������� � ������� �������:\t";
				coutFile << "\n����������� �������� � ������� �������:\t\t";
				printLinerArray(buf, strok);
				break;

			case 6:
				matrix.MinMaxStrokMatrix(strok, stolb, buf, &MyMatrix::decr);
				cout << "\n������������ �������� � ������� �������:\t";
				coutFile << "\n������������ �������� � ������� �������:\t";
				printLinerArray(buf, strok);
				break;
			case 7:
				matrix.MinMaxStolbMatrix(strok, stolb, buf, &MyMatrix::incr);
				cout << "\n����������� �������� � �������� �������:\t";
				coutFile << "\n����������� �������� � �������� �������:\t\t";
				printLinerArray(buf, stolb);
				break;
			case 8:
				matrix.MinMaxStolbMatrix(strok, stolb, buf, &MyMatrix::decr);
				cout << "\n������������ �������� � �������� �������:\t";
				coutFile << "\n������������ �������� � �������� �������:\t";
				printLinerArray(buf, stolb);
				break;
			case 9: {
				int minItem = matrix.MinMaxElemMatrix(strok, stolb, &MyMatrix::incr);
				cout << "\nM���������� ������� �������:\t" << minItem;
				coutFile << "\nM���������� ������� �������:\t" << minItem;
			}
					break;
			case 10: {
				int maxItem = matrix.MinMaxElemMatrix(strok, stolb, &MyMatrix::decr);
				cout << "\n������������ ������� �������:\t" << maxItem;
				coutFile << "\n������������ ������� �������:\t" << maxItem;
			}
					 break;
			case 11:
				matrix.SumMatrixStrok(strok, stolb, buf);
				cout << "\nC���a ��������� �� ������� �������\t";
				coutFile << "\nC���a ��������� �� ������� �������\t";
				printLinerArray(buf, strok);
				break;
			case 12:
				matrix.SumMatrixStolb(strok, stolb, buf);
				cout << "\nC���a ��������� �� �������� �������\t";
				coutFile << "\nC���a ��������� �� �������� �������\t";
				printLinerArray(buf, stolb);
				break;
			case 13: {
				int sum = matrix.SumElemMatrix(strok, stolb);
				cout << "\nC���a ��������� �������\t" << sum;
				coutFile << "\nC���a ��������� �������\t" << sum;
			}
					 break;
			case 14:
				matrix.SortMatrixStrok(strok, stolb, &MyMatrix::incr);
				cout << "�������� ����� ������� �� �����������:\n";
				coutFile << "�������� ����� ������� �� �����������:\n";
				matrix.printMatrix(strok, stolb);
				break;
			case 15:
				matrix.SortMatrixStrok(strok, stolb, &MyMatrix::decr);
				cout << "�������� ����� ������� �� ��������:\n";
				coutFile << "�������� ����� ������� �� ��������:\n";
				matrix.printMatrix(strok, stolb);
				break;
			case 16:
				matrix.SortMatrixStolb(strok, stolb, &MyMatrix::incr);
				cout << "�������� �������� ������� �� �����������:\n";
				coutFile << "�������� �������� ������� �� �����������:\n";
				matrix.printMatrix(strok, stolb);
				break;
			case 17:
				matrix.SortMatrixStolb(strok, stolb, &MyMatrix::decr);
				cout << "�������� �������� ������� �� ��������:\n";
				coutFile << "�������� �������� ������� �� ��������:\n";
				matrix.printMatrix(strok, stolb);
				break;
			case 18:
				if (strok != stolb) {
					cout << "���������������� ������� �� �������������� ���������:\n";
					coutFile << "���������������� ������� �� �������������� ���������:\n";
					break;
				}
				matrix.transpMatrix(strok, stolb);
				matrix.printMatrix(strok, stolb);
				break;
			}
		} while (operation < 19);
		delete[] buf;
		//�������� goto � ������ ������ �� ��������
		if (operation == 20) goto Exit;
		cout << '\n';
	}
Exit:
	return 0;
}