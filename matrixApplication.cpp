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
