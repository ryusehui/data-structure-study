#include <iostream>
using namespace std;
 
class Matrix
{
private:
    int m;
    int n;
    int** array;
public:
    Matrix()
    {
        array = 0;
        
        cout << "Enter the row size and column size: ";
        cin >> m >> n;
        array = new int*[m];
        for(int i = 0; i < m; i++)
        {
            array[i] = new int[n];
        }
    }
    ~Matrix()
    {
        for(int i = 0; i < m; i++)
        {
            delete[] array[i];
        }
    }
    void inPut()
    {
        cout << "Enter elements of two-dimensional array: ";
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> array[i][j];
        }
    }
    void display()
    {
        cout << "Print out two-dimensional array: " << endl;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                cout << array[i][j] << " ";
            
            cout << endl;
        }
    }
};
 
int main()
{
    Matrix g;
    g.inPut();
    g.display();
    
    return 0;
}
