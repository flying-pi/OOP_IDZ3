#include "MATRFILE.h"

void printArray(short *, int);

//глобальный обьект не допустимы в обьектноорентированом С++.
// При крайней необходимости следует использовать патерн сингелтон
//поскольку он допускает контроль над изминением элемента с глобальной областю видимости
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
    //дублирование кода ввывода в файл и на консоль.  Можно было использовать тот факт что используется
    // обьекты с одинаковым родительским классом
    for (;;) {
        cout << "ОБРАБОТКА МАТРИЦЫ ЦЕЛЫХ ЧИСЕЛ:\n"
             << "1-ввод данных с клавиатуры\n"
             << "2-генерирование чисел\n"
             << "3-записать матрицу в файл\n"
             << "4-восстановить матрицу из файла\n"
             << "5-минимальные элементы в строках матрицы\n"
             << "6-максимальные элементы в строках матрицы\n"
             << "7-минимальные элементы в столбцах матрицы\n"
             << "8-максимальные элементы в столбцах матрицы\n"
             << "9-минимальный элемент матрицы\n"
             << "10-максимальный элемент матрицы\n"
             << "11-суммы элементов по строкам матрицы\n"
             << "12-суммы элементов по столбцам матрицы\n"
             << "13-сумма всех элементов матрицы\n"
             << "14-сортировка по возрастанию элементов строк матрицы\n"
             << "15-сортировка по убыванию элементов строк матрицы\n"
             << "16-сортировка по возрастанию элементов столбцов матрицы\n"
             << "17-сортировка по убыванию элементов столбцов матрицы\n"
             << "18-транспонирование матрицы, если strok=stolb\n"
             << "19-перейти к обработке другой матрицы\n"
             << "20-завершить программу\n";
        coutFile << "ОБРАБОТКА МАТРИЦЫ ЦЕЛЫХ ЧИСЕЛ:\n"
                 << "1-ввод данных с клавиатуры\n"
                 << "2-генерирование чисел\n"
                 << "3-записать матрицу в файл\n"
                 << "4-восстановить матрицу из файла\n"
                 << "5-минимальные элементы в строках матрицы\n"
                 << "6-максимальные элементы в строках матрицы\n"
                 << "7-минимальные элементы в столбцах матрицы\n"
                 << "8-максимальные элементы в столбцах матрицы\n"
                 << "9-минимальный элемент матрицы\n"
                 << "10-максимальный элемент матрицы\n"
                 << "11-суммы элементов по строкам матрицы\n"
                 << "12-суммы элементов по столбцам матрицы\n"
                 << "13-сумма всех элементов матрицы\n"
                 << "14-сортировка по возрастанию элементов строк матрицы\n"
                 << "15-сортировка по убыванию элементов строк матрицы\n"
                 << "16-сортировка по возрастанию элементов столбцов матрицы\n"
                 << "17-сортировка по убыванию элементов столбцов матрицы\n"
                 << "18-транспонирование матрицы, если strok=stolb\n"
                 << "19-перейти к обработке другой матрицы\n"
                 << "20-завершить программу\n";
        coutFile.flush();
        cout << "\nВведите количество строк из [1-50] и столбцов из [1-20] матрицы:\n"
             << "Строк=";
        coutFile << "\nВведите количество строк из[1 - 50] и столбцов из[1 - 20] матрицы:\n"
                 << "Строк=";
        scanf("%d", &strok);
        coutFile << strok << endl;
        cout << "Столбцов=";
        coutFile << "Столбцов=";
        scanf("%d", &stolb);
        coutFile << stolb << endl;
        cout << "Ввод данных с клавиатуры(1) или генерирование(2)?";
        coutFile << "Ввод данных с клавиатуры(1) или генерирование(2)? ";
        scanf("%d", &KeyGen);
        coutFile << KeyGen << endl;
        //имя ob1(с определенным шрифтом читается оби) незначимое,  заменеено на matrix из за крайнего неудобства
        int *buf = new int[max(strok, stolb)];
        MyMatrix matrix(strok, stolb, KeyGen);
        do {
            cout << "\n\nВведите операцию обработки матрицы из набора [3-20]: ";
            coutFile << "\n\nВведите операцию обработки матрицы из набора [3-20]: ";
            scanf("%d", &operation);
            coutFile << operation << endl;

            //магичиские числа, можно было использовать константы либо же перечисление
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
                    cout << "\nМинимальные элементы в строках матрицы:\t";
                    coutFile << "\nМинимальные элементы в строках матрицы:\t\t";
                    printLinerArray(buf, strok);
                    break;

                case 6:
                    matrix.MinMaxStrokMatrix(strok, stolb, buf, &MyMatrix::decr);
                    cout << "\nМаксимальные элементы в строках матрицы:\t";
                    coutFile << "\nМаксимальные элементы в строках матрицы:\t";
                    printLinerArray(buf, strok);
                    break;
                case 7:
                    matrix.MinMaxStolbMatrix(strok, stolb, buf, &MyMatrix::incr);
                    cout << "\nМинимальные элементы в столбцах матрицы:\t";
                    coutFile << "\nМинимальные элементы в столбцах матрицы:\t\t";
                    printLinerArray(buf, stolb);
                    break;
                case 8:
                    matrix.MinMaxStolbMatrix(strok, stolb, buf, &MyMatrix::decr);
                    cout << "\nМаксимальные элементы в столбцах матрицы:\t";
                    coutFile << "\nМаксимальные элементы в столбцах матрицы:\t";
                    printLinerArray(buf, stolb);
                    break;
                case 9: {
                    int minItem = matrix.MinMaxElemMatrix(strok, stolb, &MyMatrix::incr);
                    cout << "\nMинимальный элемент матрицы:\t" << minItem;
                    coutFile << "\nMинимальный элемент матрицы:\t" << minItem;
                }
                    break;
                case 10: {
                    int maxItem = matrix.MinMaxElemMatrix(strok, stolb, &MyMatrix::decr);
                    cout << "\nМаксимальный элемент матрицы:\t" << maxItem;
                    coutFile << "\nМаксимальный элемент матрицы:\t" << maxItem;
                }
                    break;
                case 11:
                    matrix.SumMatrixStrok(strok,stolb,buf);
                    cout << "\nCуммa элементов по строкам матрицы\t";
                    coutFile << "\nCуммa элементов по строкам матрицы\t";
                    printLinerArray(buf, strok);
                    break;
                case 12:
                    matrix.SumMatrixStolb(strok,stolb,buf);
                    cout << "\nCуммa элементов по столбцам матрицы\t";
                    coutFile << "\nCуммa элементов по столбцам матрицы\t";
                    printLinerArray(buf, stolb);
                    break;
                case 13:{
                    int sum = matrix.SumElemMatrix(strok,stolb);
                    cout << "\nCуммa элементов матрицы\t" << sum;
                    coutFile << "\nCуммa элементов матрицы\t" << sum;
                }
                    break;
                case 14:
                    matrix.SortMatrixStrok(strok, stolb, &MyMatrix::incr);
                    cout << "Элементы строк матрицы по возрастанию:\n";
                    coutFile << "Элементы строк матрицы по возрастанию:\n";
                    matrix.printMatrix(strok, stolb);
                    break;
                case 15:
                    matrix.SortMatrixStrok(strok, stolb, &MyMatrix::decr);
                    cout << "Элементы строк матрицы по убыванию:\n";
                    coutFile << "Элементы строк матрицы по убыванию:\n";
                    matrix.printMatrix(strok, stolb);
                    break;
                case 16:
                    matrix.SortMatrixStolb(strok, stolb, &MyMatrix::incr);
                    cout << "Элементы столбцов матрицы по возрастанию:\n";
                    coutFile << "Элементы столбцов матрицы по возрастанию:\n";
                    matrix.printMatrix(strok, stolb);
                    break;
                case 17:
                    matrix.SortMatrixStolb(strok, stolb, &MyMatrix::decr);
                    cout << "Элементы столбцов матрицы по убыванию:\n";
                    coutFile << "Элементы столбцов матрицы по убыванию:\n";
                    matrix.printMatrix(strok, stolb);
                    break;
                case 18:
                    if(strok!=stolb) {
                        cout << "Транспонирование матрицы не представляется возможным:\n";
                        coutFile << "Транспонирование матрицы не представляется возможным:\n";
                        break;
                    }
                    matrix.transpMatrix(strok,stolb);
                    matrix.printMatrix(strok, stolb);
                    break;
            }
        } while (operation < 19);
        delete[] buf;
        //оператор goto в данном случае не оправдан
        if (operation == 20) goto Exit;
        cout << '\n';
    }
    Exit:
    return 0;
}