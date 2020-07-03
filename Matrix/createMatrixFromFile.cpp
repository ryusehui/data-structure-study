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
