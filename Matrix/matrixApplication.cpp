#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
 
class Matrix
{
private:
    int m;
    int n;
    int count;
    int** array;
    int** cArray;
    int** tArray;
    int** mArray;
    int** sArray;
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
            delete[] cArray[i];
            delete[] tArray[i];
            delete[] mArray[i];
            delete[] sArray[i];
        }
        delete [] array;
        delete [] cArray;
        delete [] tArray;
        delete [] mArray;
        delete [] sArray;
    }
    
    void inPut()
    {
        count = 0;
        cout << endl << "Get elements from file: ";
        ifstream in("INPUT.txt");
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                in >> array[i][j];
                if(array[i][j] != 0)
                    count++;
            }
        }
        in.close();
        cout << "DONE" << endl;
    }
    
    void outPut()
    {
        cout << "Print out two-dimensional array to file: ";
        ofstream out("OUTPUT.txt");
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                out << right << setw(5) << array[i][j];
                
            out << endl;
        }
        out.close();
        cout << "DONE" << endl;
    }
    
    void copyMatrix()
    {
        cout << "Display copy Matrix to file: ";
        ofstream copy("COPY.txt");
        cArray = 0;
        cArray = new int*[m];
        for(int i = 0; i < m; i++)
        {
            cArray[i] = new int[n];
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cArray[i][j] = array[i][j];
                copy << right << setw(5) << cArray[i][j];
            }
            copy << endl;
        }
        copy.close();
        cout << "DONE" << endl;
    }
    
    void transepose()
    {
        cout << endl << "Display transepose Matrix: " << endl;
        tArray = 0;
        tArray = new int*[n];
        for(int i = 0; i < n; i++)
        {
            tArray[i] = new int[m];
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                tArray[i][j] = array[j][i];
                cout << right << setw(5) << tArray[i][j];
            }
            cout << endl;
        }
    }
    
    void multiply()
    {
        cout << endl << "Display multiply Matrix: " << endl;
        mArray = 0;
        mArray = new int*[m];
        for(int i = 0; i < m; i++)
        {
            mArray[i] = new int[n];
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int result = 0;
                for(int k = 0; k < n; k++)
                    result = result + array[i][k] * cArray[k][j];
                    
                mArray[i][j] = result;
                cout << right << setw(8) << mArray[i][j];
            }
            cout << endl;
        }
    }
    
    void sparse()
    {
        cout << endl << "Display sparse Matrix: " << endl;
        sArray = 0;
        sArray = new int*[count];
        for(int i = 0; i < count; i++)
        {
            sArray[i] = new int[3];
        }
        
        cout << right;
        cout << setw(9) << "ROW" << setw(9) << "COL" << setw(9) << "VALUE" << endl;
        int k = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(array[i][j] != 0)
                {
                    sArray[k][0] = i;
                    sArray[k][1] = j;
                    sArray[k][2] = array[i][j];
                    
                    k++;
                }
            }
        }
        for(int i = 0; i < count; i++)
        {
            for(int j = 0; j < 3; j++)
                cout << setw(9) << sArray[i][j];
                
            cout << endl;
        }
    }
    
    void displayToFile()
    {
        cout << endl << "Display transepose Matrix to file: ";
        ofstream trans("TRANSEPOSE.txt");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                trans << right << setw(5) << tArray[i][j];
                
            trans << endl;
        }
        trans.close();
        cout << "DONE" << endl;
        
        cout << "Display multiply Matrix to file: ";
        ofstream mul("MULTIPLY.txt");
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                mul << right << setw(8) << mArray[i][j];
                
            mul << endl;
        }
        mul.close();
        cout << "DONE" << endl;
        
        cout << "Display sparse Matrix to file: ";
        ofstream sp("SPARSE.txt");
        sp << right;
        sp << setw(9) << "ROW" << setw(9) << "COL" << setw(9) << "VALUE" << endl;
        for(int i = 0; i < count; i++)
        {
            for(int j = 0; j < 3; j++)
                sp << setw(9) << sArray[i][j];
                
            sp << endl;
        }
        sp.close();
        cout << "DONE" << endl;
    }
};
    
int main()
{
    int a = 0;
    int b = 0;
    cout << "Enter the row size (It should be 26): ";
    cin >> a;
    cout << "Enter the col size (It should be 26): ";
    cin >> b;
    
    Matrix g(a, b);
    g.inPut();
    g.copyMatrix();
    g.outPut();
    g.transepose();
    g.multiply();
    g.sparse();
    g.displayToFile();
    
    return 0;
}

/*
file needed

INPUT.txt
    0    0    7    1  342    0    0    2  118    0    1    0    0    3   76    0    0    1   35    9    9    0    1    0    5    0
    0    0    9    9    2    2    3    1    0    0    0    5   11    5    0   10    0    0    2    1    0    0    8    0    0    0
    6    5    0    1    0    9    5    0    0    0    1    0    7    9    1   10    2    5   39   40    1    3    7    1    1    0
    1   10   13    0   12    0    5    5   89    0    2    3    7    3    0    1    0   43   30   22    0    0    4    0    2    0
  388    0    3   11    0    2    2    0    0    0    0    3    0    5   93    0    0   14   12    6   15    0    1    0   18    0
    0   15    0    3    1    0    5    2    0    1    0    3    4    1    0    0    0    6    4   12    0    0    2    0    0    0
    5    1   11   11    9    2    0    0    0    0    1    3    0    0    2    1    3    5   13   21    0    0    1    0    3    0
    1    8    0    3    0    0    0    0    0    0    2    3   12   14    2    3    0    3    1   11    0    0    2    1    0    0
  103    0    0    0  146    0    1    0    0    0    0    6    0    0   49    0    0    0    2    1   47    0    2    0   15    0
    0    1    1    9    0    0    1    0    0    0    0    2    1    0    0    0    0    0    5    0    0    0    0    0    0    0
    1    2    8    4    1    1    2    5    0    0    0    0    5    0    2    0    0    0    6    0    0    0    4    0    0    3
    2   10    1    4    0    4    5    6   13    0    1    0    0   14    2    5    0   11   10    2    0    0    0    0    0    0
    1    3    7    8    0    2    0    6    0    0    4    4    0  180    0    6    0    0    9   15   13    3    2    2    3    0
    2    7    6    5    3    0    1   19    1    0    4   35   78    0    0    7    0   28    5    7    0    0    1    2    0    2
   91    1    1    3  116    0    0    0   25    0    2    0    0    0    0   14    0    2    4   14   39    0    0    0   18    0
    0   11    1    2    0    6    5    0    2    9    0    2    7    6   15    0    0    1    3    6    0    4    1    0    0    0
    0    0    1    0    0    0   27    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0   15    0   30   12    2    2    8    2    0    5    8    4   20    1   14    0    0   12   22    4    0    0    1    0    0
   11    8   27   33   35    4    0    1    0    1    0   27    0    6    1    7    0   14    0   15    0    0    5    3   20    1
    3    4    9   42    7    5   19    5    0    1    0   14    9    5    5    6    0   11   37    0    0    2   19    0    7    6
   20    0    0    0   44    0    0    0   64    0    0    0    0    2   43    0    0    4    0    0    0    0    2    0    8    0
    0    0    7    0    0    3    0    0    0    0    0    1    0    0    1    0    0    0    8    3    0    0    0    0    0    0
    2    2    1    0    1    0    0    2    0    0    1    0    0    0    0    7    0    6    3    3    1    0    0    0    0    0
    0    0    0    2    0    0    0    0    0    0    0    0    0    0    0    0    0    0    9    0    0    0    0    0    0    0
    0    0    2    0   15    0    1    7   15    0    0    0    2    0    6    1    0    7   36    8    5    0    0    1    0    0
    0    0    0    7    0    0    0    0    0    0    0    7    5    0    0    0    0    2   21    3    0    0    0    0    3    0
*/
