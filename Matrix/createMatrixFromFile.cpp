#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
 
class Matrix
{
private:
    int m;
    int n;
    int** array;
public:
    Matrix(int row, int col):m(row), n(col)
    {
        array = 0;
        array = new int*[row];
        for(int i = 0; i < row; i++)
        {
            array[i] = new int[col];
        }
    }
    ~Matrix()
    {
        for(int i = 0; i < m; i++)
        {
            delete[] array[i];
        }
        delete [] array;
    }
    void inPut()
    {
        ifstream in("INPUT_file.txt");
        cout << endl << "Get elements from file: ";
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                in >> array[i][j];
        }
        in.close();
        cout << "DONE" << endl;
    }
    void display()
    {
        ofstream out("OUTPUT_file.txt");
        cout << "Print out two-dimensional array to file: ";
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                out << setw(3) << array[i][j] << " ";
                
                out << endl;
        }
        out.close();
        cout << "DONE" << endl;
    }
    
    friend ostream& operator<<(ostream& os, const Matrix& matrix)
    {
        cout << endl << "The two-dimensional array for the file is: " << endl;
        for (int i = 0; i < matrix.m; i++)
        {
            for (int j = 0; j < matrix.n; j++)
                os << setw(3) << matrix.array[i][j] << " ";
                        
                os << endl;
        }
        
        return os;
    }
};
    
int main()
{
    int a = 0;
    int b = 0;
    cout << "Enter the row size: ";
    cin >> a;
    cout << "Enter the col size: ";
    cin >> b;
    
    Matrix g(a, b);
    g.inPut();
    g.display();
    cout << g;
    
    return 0;
}

/*
file needed

INPUT_file.txt
  1   2   3   4   5   6   7   8   9   10
 11  12  13  14  15  16  17  18  19   20
 21  22  23  24  25  26  27  28  29   30
 31  32  33  34  35  36  37  38  39   40
 41  42  43  44  45  46  47  48  49   50
 51  52  53  54  55  56  57  58  59   60
 61  62  63  64  65  66  67  68  69   70
 71  72  73  74  75  76  77  78  79   80
 81  82  83  84  85  86  87  88  89   90
 91  92  93  94  95  96  97  98  99  100
*/
