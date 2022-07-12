#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    ifstream amatrix("test5a.txt");
    ifstream bmatrix("test5b.txt");
    ofstream cmatrix("c.txt");
    int str1, str2, stolb1, stolb2;
    double** a, ** b, ** c;
    //ввод параметров матриц
    cout << "Введите количество строк первой матрицы: ";
    cin >> str1;
    cout << "Введите количество столбцов первой матрицы: ";
    cin >> stolb1;
    cout << "Введите количество строк второй матрицы: ";
    cin >> str2;
    cout << "Введите количество столбцов второй матрицы: ";
    cin >> stolb2;
    if (stolb1 != str2)
    {
        cout << "Умножение невозможно!";
        return 0;
    }
    a = new double* [stolb1];
    b = new double* [stolb2];
    //ввод матрицы a
    for (int i = 0; i < str1; i++)
    {
        a[i] = new double[stolb1];
    }
    for (int i = 0; i < str1; i++)
    {
        for (int j = 0; j < stolb1; j++)
            amatrix >> a[i][j];
    }
    //ввод матрицы b
    for (int i = 0; i < str2; i++)
    {
        b[i] = new double[stolb2];
    }
    for (int i = 0; i < str2; i++)
    {
        for (int j = 0; j < stolb2; j++)
            bmatrix >> b[i][j];
    }


    //перемножение матриц
    c = new double* [str1];
    for (int i = 0; i < str1; i++)
    {
        c[i] = new double[stolb2];
        for (int j = 0; j < stolb2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < stolb1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    //вывод матрицы
    for (int i = 0; i < str1; i++)
    {
        for (int j = 0; j < stolb2; j++)
            cmatrix << c[i][j] << " ";
        cmatrix << endl;
    }
    amatrix.close();
    bmatrix.close();
    cmatrix.close();
    return 0;
}