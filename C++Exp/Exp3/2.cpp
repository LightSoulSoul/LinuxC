#include <iostream>
#include <iomanip>

const int COLUMN_SIZE = 3;
const int ROW_SIZE = 3;

int
addMatrix(int a[][COLUMN_SIZE], int b[][COLUMN_SIZE], int c[][COLUMN_SIZE],int rowSize);

int
multiplyMatrix(int a[][COLUMN_SIZE], int b[][COLUMN_SIZE], int c[][COLUMN_SIZE], int rowSize);

int main()
{
    int a[3][3] = {0};
    int b[3][3] = {0};
    int c1[3][3] = {0};
    int c2[3][3] = {0};

    std::cout << "Please input the Matrix A:" << std::endl;
    for (int i = 0; i < ROW_SIZE; ++i)
    {
        for (int j = 0; j < ROW_SIZE; ++j)
        {
            std::cin >> a[i][j];
        }
    }
    std::cout << "Please input the Matrix B:" << std::endl;
    for (int i = 0; i < ROW_SIZE; ++i)
    {
        for (int j = 0; j < ROW_SIZE; ++j)
        {
            std::cin >> b[i][j];
        }
    }
    std::cout << "A + B = " << std::endl;
    addMatrix(a, b, c1, ROW_SIZE);
    for (int i = 0; i < ROW_SIZE; ++i)
    {
        for (int j = 0; j < ROW_SIZE; ++j)
        {
            std::cout << std::setw(4) << c1[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "A * B = " << std::endl;
    multiplyMatrix(a, b, c2, ROW_SIZE);
    for (int i = 0; i < ROW_SIZE; ++i)
    {
        for (int j = 0; j < ROW_SIZE; ++j)
        {
            std::cout << std::setw(4) << c2[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;

}


int
addMatrix(int a[][COLUMN_SIZE], int b[][COLUMN_SIZE], int c[][COLUMN_SIZE],int rowSize)
{
    for (int i = 0; i < ROW_SIZE; ++i)
    {
        for (int j = 0; j < COLUMN_SIZE; ++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return 0;
}

int
multiplyMatrix(int a[][COLUMN_SIZE], int b[][COLUMN_SIZE], int c[][COLUMN_SIZE], int rowSize)
{
    for(int i = 0; i < ROW_SIZE; ++i)
    {
        for(int j = 0; j < ROW_SIZE; ++j)
        {
            for(int k = 0; k < COLUMN_SIZE ; ++k)
            {
                c[i][j]= c[i][j] + a[i][k]*b[k][j];
            }
        }
    }
    return 0;
}