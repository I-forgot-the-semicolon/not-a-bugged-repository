#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

double maptoReal(int x, int anchoimagen, double MaxR, double MinR)
{
        double rango = MaxR - MinR;
        return x * (rango/anchoimagen) + MinR;
}

double maptoImaginary(int y, int altoimagen, double MaxI, double MinI)
{
        double rango = MaxI - MinI;
        return y * (rango/altoimagen) + MinI;
}

int MandelbrotN(double cr, double ci, int iteraccionesmax)
{
        int i  = 0;
        double zr = 0.0, zi = 0.0;
        while(i < iteraccionesmax && zr*zr+zi*zi < 4.0)
        {
                double temp = zr*zr - zi*zi + cr;
                zi = 2.0 * zr * zi + ci;
                zr=temp;
                i++;
        }
        return i;
}

int main()
{
        string magicnumber = "P3 ", ancho, alto, maxcolorvalue = "255 ", r, g, b;
        int iteraccionesmax, opcion;

        cout << "Resolucion automatica (1) / Resolucion especifica(2): ";
        cin >> opcion;
        if(opcion == 1)
        {
                cout << "HD (1) / FullHD (2) / 2K (3) / 4K (4): ";
                cin >> opcion;
                if(opcion == 1)
                {
                        ancho = "1280 ";
                        alto = "720 ";
                }
                if(opcion == 2)
                {
                        ancho = "1920 ";
                        alto = "1080 ";
                }
                if(opcion == 3)
                {
                        ancho = "2048 ";
                        alto = "1080 ";
                }
                if(opcion == 4)
                {
                        ancho = "3840 ";
                        alto = "2160 ";
                }
                if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
                {
                        cout << "Cerrando: " << opcion;
                        exit(-1);
                }


        }
        else
        {
                cout << "Ancho: ";
                cin >> ancho;
                cout << "Alto: ";
                cin >> alto;
                ancho = ancho + " ";
                alto = alto + " ";
        }

        cout << "Iteracciones: ";
        cin >> iteraccionesmax;
        cout << "Modo de color automatico (1) / Modo de color especifico (2): ";
        cin >> opcion;
        if(opcion == 1)
        {
                r = "255 ";
                g = "255 ";
                b = "255 ";
        }
        else
        {
                cout << "r-> ";
                cin >> r;
                r = r + " ";
                cout << "g-> ";
                cin >> g;
                g = g + " ";
                cout << "b-> ";
                cin >> b;
                b = b + " ";
        }

        ofstream imagen("imagen.ppm");
        imagen.write(magicnumber.c_str(), magicnumber.size());
        imagen.write(ancho.c_str(), ancho.size());
        imagen.write(alto.c_str(), alto.size());
        imagen.write(maxcolorvalue.c_str(), maxcolorvalue.size());

        for(int y = 0; y < atoi(alto.c_str()); y++)
        {
                for(int x = 0; x < atoi(ancho.c_str()); x++)
                {
                        double cr = maptoReal(x, atoi(ancho.c_str()), 0.7, -1.5);
                        double ci = maptoImaginary(y, atoi(alto.c_str()), 1.0, -1.0);
                        int n = MandelbrotN(cr, ci, iteraccionesmax);
                        int red = (n % atoi(r.c_str()));
                        int green = (n % atoi(g.c_str()));
                        int blue = (n % atoi(b.c_str()));
                        imagen << red << " " << green << " " << blue << " ";
                }
                imagen << endl;
        }


        imagen.close();
}
