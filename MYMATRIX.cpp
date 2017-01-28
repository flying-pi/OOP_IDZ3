#include "MATRFILE.h"

extern ofstream coutFile;

void printArray(short *array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
		coutFile << setw(6) << array[i];
		if ((i + 1) % 13 == 0) {
			cout << endl;
			coutFile << endl;
		}
	}
}

MyMatrix::MyMatrix(int strok, int stolb, int KeyGen) {
	if (KeyGen == 1) {
		inKeyMatrix(strok, stolb);
		cout << "������������ ������� �������� " << strok << "x" << stolb << ":" << endl;
		coutFile << "������������ ������� �������� " << strok << "x" << stolb << ":" << endl;
		printMatrix(strok, stolb);
	}
	else {
		srand((unsigned)time(NULL));
		genMatrix(strok, stolb);
		cout << "������������ ������� �������� " << strok << "x" << stolb << ":" << endl;
		coutFile << "������������ ������� �������� " << strok << "x" << stolb << ":" << endl;
		printMatrix(strok, stolb);
	}
}

/// fixme �� �������� ���������� ��������
void MyMatrix::printMatrix(int strok, int stolb) {
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb; j++) {
			printf("%d\t", matrix[i][j]);
			coutFile << setw(4) << matrix[i][j];
		}
		printf("\n");
		coutFile << endl;
	}
}

void MyMatrix::inKeyMatrix(int strok, int stolb) {
	for (int i = 0; i < strok; i++)
		for (int j = 0; j < stolb; j++)
			scanf("%hd", &matrix[i][j]);
}

void MyMatrix::genMatrix(int strok, int stolb) {
	for (int i = 0; i < strok; i++)
		for (int j = 0; j < stolb; j++)
			matrix[i][j] = rand() % 100;
}

void MyMatrix::SortMatrixStrok(int strok, int stolb, int(MyMatrix::*FuncPtr)(short, short)) {
	for (int i = 0; i < strok; i++)
		for (int pass = 1; pass < stolb; pass++)
			for (int j = 0; j < stolb - 1; j++)
				if ((this->*FuncPtr)(matrix[i][j], matrix[i][j + 1]))
					swap(&matrix[i][j], &matrix[i][j + 1]);
}

void MyMatrix::SortMatrixStolb(int strok, int stolb, int(MyMatrix::*FuncPtr)(short, short)) {
	for (int j = 0; j < stolb; j++)
		for (int pass = 1; pass < strok; pass++)
			for (int i = 0; i < strok - 1; i++)
				if ((this->*FuncPtr)(matrix[i][j], matrix[i + 1][j]))
					swap(&matrix[i][j], &matrix[i + 1][j]);
}

void MyMatrix::swap(short *element1Ptr, short *element2Ptr) {
	short temp;
	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}

int MyMatrix::incr(short a, short b) { return b < a; }

int MyMatrix::decr(short a, short b) { return b > a; }

void MyMatrix::outMatrFileBin() {
	cout << "������ ������� ������� � ���� outMFBin.d\n";
	coutFile << "������ ������� ������� � ���� outMFBin.d\n";
	ofstream coutFileLoc;
	coutFileLoc.open("outMFBin.d", ios::binary);
	DiagFile(coutFileLoc);
	coutFileLoc.write((const char *)&matrix[0][0], sizeof(short) * 1000);
	coutFileLoc.close();
}

void MyMatrix::outMatrFileBinVar(int strok, int stolb) {
	cout << "������ ������� ������� � ���� outMFBil.d\n";
	coutFile << "������ ������� ������� � ���� outMFBil.d\n";
	ofstream coutFileLoc;
	coutFileLoc.open("outMFBil.d", ios::binary);
	DiagFile(coutFileLoc);
	for (int i = 0; i < strok; i++)
		coutFileLoc.write((const char *)&matrix[i][0], sizeof(short) * stolb);
}

MyMatrix &MyMatrix::inMatrFileBin(int strok, int stolb) {
	cout << "������ ������� ������� �� ����� outMFBin.d\n";
	coutFile << "������ ������� ������� �� ����� outMFBin.d\n";
	ifstream cinFile("outMFBin.d", ios::binary);
	DiagFile(cinFile);
	cinFile.read((char *)&matrix[0][0], sizeof(short) * 1000);
	//�������������� ������� ������ ������� read, ����� ����� �������� ������� �����������
	//���������� ���� short* matrix.
	//coutFileLoc.read((char*)matrix, sizeof(short) * 1000);
	//�������������� ������� ������ ������� read, ����� ����� �������� ������� �����������
	//���������� ���� short* (matrix+0).
	//coutFileLoc.read((char*)(matrix+0), sizeof(short) * 1000);
	//�������������� ������� ������ ������� read, ����� ����� �������� ������� �����������
	//���������� ���� short matrix[0].
	//coutFileLoc.read((char*)matrix[0], sizeof(short) * 1000);
	printMatrix(strok, stolb);
	return *this;
}

MyMatrix *MyMatrix::inMatrFileBinVar(int strok, int stolb) {
	cout << "������ ������� ������� �� ����� outMFBil.d\n";
	coutFile << "������ ������� ������� �� ����� outMFBil.d\n";
	ifstream cinFile("outMFBil.d", ios::binary);
	DiagFile(cinFile);
	for (int i = 0; i < strok; i++)
		cinFile.read((char *)&matrix[i][0], sizeof(short) * stolb);
	printMatrix(strok, stolb);
	return this;
}

void MyMatrix::outMatrFileTxt(int strok, int stolb) {
	cout << "������ ������� ������� � ���� outMFTxt.d\n";
	coutFile << "������ ������� ������� � ���� outMFTxt.d\n";
	ofstream coutFileLoc;
	DiagFile(coutFileLoc);
	coutFileLoc.open("outMFTxt.d");
	for (int i = 0; i < strok; i++)
		for (int j = 0; j < stolb; j++)
			coutFileLoc << matrix[i][j] << ' ';
}

MyMatrix &MyMatrix::inMatrFileTxt(int strok, int stolb) {
	cout << "������ ������� ������� �� ����� outMFTxt.d\n";
	coutFile << "������ ������� ������� �� ����� outMFTxt.d\n";
	ifstream cinFile("outMFTxt.d");
	DiagFile(cinFile);
	for (int i = 0; i < strok; i++)
		for (int j = 0; j < stolb; j++)
			cinFile >> matrix[i][j];
	printMatrix(strok, stolb);
	return *this;
}

void MyMatrix::MinMaxStrokMatrix(int rowCount, int collumnCount, int *out, int (MyMatrix::*comparator)(short, short)) {
	if (collumnCount == 0)
		return;
	for (int i = 0; i < rowCount; i++) {
		int item = matrix[i][0];
		for (int j = 0; j < collumnCount; j++) {
			if ((this->*comparator)(item, matrix[i][j]))
				item = matrix[i][j];
		}
		out[i] = item;
	}
}

void MyMatrix::MinMaxStolbMatrix(int rowCount, int collumnCount, int *out, int (MyMatrix::*comparator)(short, short)) {
	if (rowCount == 0)
		return;
	for (int i = 0; i < collumnCount; i++) {
		int item = matrix[0][i];
		for (int j = 0; j < rowCount; j++) {
			if ((this->*comparator)(item, matrix[j][i]))
				item = matrix[j][i];
		}
		out[i] = item;
	}
}

int MyMatrix::MinMaxElemMatrix(int rowCount, int collumnCount, int (MyMatrix::*comparator)(short, short)) {
	int item = matrix[0][0];
	for (int i = 0; i < collumnCount; i++) {
		for (int j = 0; j < rowCount; j++) {
			if ((this->*comparator)(item, matrix[j][i]))
				item = matrix[j][i];
		}
	}
	return item;
}

void MyMatrix::SumMatrixStrok(int rowCount, int collumnCount, int *out) {
	if (collumnCount == 0)
		return;
	for (int i = 0;i<rowCount;i++)
		out[i] = 0;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < collumnCount; j++) {
			out[i] += matrix[i][j];
		}
	}
}

void MyMatrix::SumMatrixStolb(int rowCount, int collumnCount, int *out) {
	if (rowCount == 0)
		return;
	for (int i = 0;i<collumnCount;i++)
		out[i] = 0;
	for (int i = 0; i < collumnCount; i++) {
		for (int j = 0; j < rowCount; j++) {
			out[i] += matrix[j][i];
		}
	}
}

int MyMatrix::SumElemMatrix(int rowCount, int collumnCount) {
	int result = 0;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < collumnCount; j++) {
			result += matrix[i][j];
		}
	}
	return result;
}

void MyMatrix::transpMatrix(int rowCount, int collumnCount) {
	if (collumnCount != rowCount)
		return;
	for (int i = 0; i < rowCount; i++) {
		for (int j = i; j < collumnCount; j++) {
			swap(&matrix[i][j], &matrix[j][i]);
		}
	}
}

