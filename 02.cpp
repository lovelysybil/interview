#include "iostream"
using namespace std;

//二维数组中的查找 从右上角或者左下角开始查找
bool findNumInMatrix(int *matrix, int rows, int columns, int number)
{
    bool found = false;

    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns-1;

        while(row < rows && column >= 0)
        {
            if(matrix[columns*row + column] > number)
                column--;
            else if(matrix[columns*row + column] < number)
                row++;
            else
            {
                found = true;
                break;
            }
        }
    }

    return found;
}
