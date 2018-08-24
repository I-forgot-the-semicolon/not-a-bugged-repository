#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int n = 0;
double pi;

int main(int argc, char* argv[])
{
        if(argc > 1)
        {
          for(int i = atoi(argv[1])-1; i >= 0; --i)
          {
                  pi = pi + (6/(pow(++n, 2)));
          }
          pi = sqrt(pi);
          cout << "pi: " << setprecision(20) << pi << endl;
        }
        else
        {
          cout << "Uso: " << argv[0] << " numero_iteracciones" << endl;
        }

        return 0;
}
