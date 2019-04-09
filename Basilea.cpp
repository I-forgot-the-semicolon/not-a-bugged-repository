#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void piloop(int b)
{
        double pi;
        int n = 0;
        for(int i = b; i > 0; --i)
        {
                pi = pi + (6/(pow(++n, 2)));
        }
        pi = sqrt(pi);
        cout << "Pi: " << setprecision(10) << pi << endl;
}

int main(int argc, char* argv[])
{
        if(argc > 1)
        {
                piloop(atoi(argv[1]));
        }
        else
        {
                int iteracciones;
                cout << "Tambien puedes usar: " << argv[0] << " numero_iteracciones" << endl << "Numero iteracciones: ";
                cin >> iteracciones;
                piloop(iteracciones);

        }

        return 0;
}
