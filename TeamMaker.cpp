#include <iostream>
#include <string.h>
#include <vector>
#include <random>

using namespace std;

int main()
{
        //Declaracion de variables necesarias...
        int numerojugadores, numeroaleatorio;
        vector<string> equipoblanco, equiponegro, nombresjugadores;
        string nombre;

        //Declaracion de semilla para generar numero aleatorio para rellenar los equipos
        random_device semilla;
        mt19937 rng(semilla());
        uniform_int_distribution<int> gen(1, 2);

        cout << "Ingrese el numero de jugadores: ";
        cin >> numerojugadores;

        for(int i=0; i < numerojugadores; i++)
        {
                cout << i+1 << ". ";
                cin >> nombre;
                nombresjugadores.push_back(nombre);
                numeroaleatorio = gen(rng);
                //Si el numero generado es 1...
                if(numeroaleatorio == 1)
                {
                        //Se comprueba que no se ha alcanzado el tamaño maximo del equipo
                        //Si lo ha hecho se rellena el otro equipo...
                        if(equipoblanco.size() < numerojugadores/2)
                        {
                                equipoblanco.push_back(nombresjugadores[i]);
                        }
                        else
                        {
                                equiponegro.push_back(nombresjugadores[i]);
                        }

                }
                else
                {
                        //Se comprueba que no se ha alcanzado el tamaño maximo del equipo
                        //Si lo ha hecho se rellena el otro equipo...
                        if(equiponegro.size() < numerojugadores/2)
                        {
                                equiponegro.push_back(nombresjugadores[i]);
                        }
                        else
                        {
                                equipoblanco.push_back(nombresjugadores[i]);
                        }
                }
        }

        cout << "Equipo blanco: ";
        for(auto it = equipoblanco.begin(); it != equipoblanco.end(); it++)
        {
                cout << *it << " ";
        }
        cout << endl <<"Equipo negro: ";
        for(auto it = equiponegro.begin(); it != equiponegro.end(); it++)
        {
                cout << *it << " ";
        }
        cout << endl;
}
