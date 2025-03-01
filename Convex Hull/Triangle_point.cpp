#include <iostream>
using namespace std;
bool checkDeterminent(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int D = (x1 * (y2 - y3)) - (x2 * (y1 - y3)) + (x3 * (y1 - y2));
    // cout << D << endl;
    if (D < 0)
        return true;
    else if (D > 0)
        return false;
}
void checkValidity(int tri[2][3], int num[2][100],int n)
{
    for (int i = 0;i < n;i++)
    {
        int a = checkDeterminent(tri[0][0], tri[1][0], tri[0][1], tri[1][1], num[0][i], num[1][i]);
        int b = checkDeterminent(tri[0][1], tri[1][1], tri[0][2], tri[1][2], num[0][i], num[1][i]);
        int c = checkDeterminent(tri[0][2], tri[1][2], tri[0][0], tri[1][0], num[0][i], num[1][i]);
        if (a == true && b == true && c == true)
        {
            cout << "the point lies inside!" << endl;
        }
        else
        {
            cout << "The point doesn't lies inside" << endl;
        }
    }
}

int main()
{
    int tri[2][3], num[100][100], n;
    cout << "Enter the vertices of triangle" << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << "Enter " << j + 1 << "vertex" << endl;
        for (int i = 0; i < 2; i++)
        {
            cin >> tri[i][j];
        }
    }

    cout << "Enter the number of points you want to check" << endl;
    cin >> n;
    cout << "Enter the points " << endl;
    for (int j = 0; j < n; j++)
    {
        // cout << "Enter " << j+1 << "vertex" << endl;
        for (int i = 0; i < 2; i++)
        {
            cin >> num[i][j];
        }
    }
    checkValidity(tri, num,n);
}