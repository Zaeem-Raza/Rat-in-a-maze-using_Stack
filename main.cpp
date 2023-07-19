#include "Stack.cpp"
#include <time.h>
using namespace std;
struct Point
{
    int x, y;
};
void print(char **mat, int row, int col);
bool findPath(char **mat, Point source, Point destination, int row, int col);
int main()
{
    int rows, cols;
    cout << "Enter Order (n-by-m): ";
    cin >> rows >> cols;
    while (rows <= 0 || cols <= 0)
    {
        cout << "Invalid order\nEnter Again: ";
        cin >> rows >> cols;
    }
    char **matrix;
    matrix = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = '0';
        }
    }
    srand(time(0));
    int x, y;
    int num = (rows * cols) * 60 / 100;
    for (int i = 0; i < num; i++)
    {
        x = rand() % rows;
        y = rand() % cols;
        if (matrix[x][y] == '1')
        {
            i--;
        }
        else
        {
            matrix[x][y] = '1';
        }
    }
    print(matrix, rows, cols);
    Point p1;
    cout << "Enter Source: ";
    cin >> p1.x >> p1.y;
    while ((p1.x < 0 || p1.x >= rows) || (p1.y < 0 || p1.y >= cols))
    {
        cout << "Invalid Input\nEnter Again: ";
        cin >> p1.x >> p1.y;
    }
    Point p2;
    cout << "Enter destiny: ";
    cin >> p2.x >> p2.y;
    if (!findPath(matrix, p1, p2, rows, cols))
    {
        cout << "Path does not exist";
    }
    return 0;
}
bool findPath(char **mat, Point source, Point destination, int row, int col)
{
    // 1 is open
    // 0 is close
    int a = source.x;
    int b = source.y;
    if (mat[a][b] == 0)
        return false; // source is 0
    Stack<Point> st;
    st.push({a, b});
    // a and b are curent indices
    cout << "Source: " << a << "," << b << endl;
    cout << "Destination: " << destination.x << "," << destination.y << endl;
    while (!st.isEmpty())
    {
        // move right
        if ((a >= 0 && a <= row) && (b >= 0 && b < col) && (mat[a][b + 1] == '1'))
        {
            mat[a][b] = 3;
            st.push({a, ++b});
        }
        // move to bottom
        else if ((a >= 0 && a < row) && (b >= 0 && b <= col) && (mat[a + 1][b] == '1'))
        {
            mat[a][b] = 3;
            st.push({a + 1, b});
            a++;
        }
        // move to left
        else if ((a >= 0 && a <= row) && (b > 0 && b <= col) && (mat[a][b - 1] == '1'))
        {
            mat[a][b] = 3;
            st.push({a, b - 1});
            b--;
        }
        // move to top
        else if ((a > 0 && a <= row) && (b >= 0 && b <= col) && (mat[a - 1][b] == '1'))
        {
            mat[a][b] = 3;
            st.push({a - 1, b});
            a--;
        }
        else
        {
            mat[a][b] = '3';
            st.pop();
            a = st.stackTop().x;
            b = st.stackTop().y;
        }
        if (a == destination.x && b == destination.y)
        {
            Stack<Point> st2;
            while (!st.isEmpty())
            {
                st2.push(st.stackTop());
                st.pop();
            }
            while (!st2.isEmpty())
            {
                int d = st2.stackTop().x;
                int f = st2.stackTop().y;
                cout << "(" << st2.stackTop().x << "," << st2.stackTop().y << ")"
                     << ",";
                mat[d][f] = '*';
                st2.pop();
            }
            print(mat, row, col);
            return true;
        }
    }
    return false;
}
void print(char **mat, int row, int col)
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // if there is any '3' mark, replace it to original i.e '0'
            if (mat[i][j] == '3')
            {
                mat[i][j] == '1';
            }
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}