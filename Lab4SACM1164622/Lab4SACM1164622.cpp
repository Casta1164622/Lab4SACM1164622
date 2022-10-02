#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> pista(70, 0);
int liebreVal = 1;
int tortugaVal = 2;
int liebrePos = 0;
int tortugaPos = 0;


void printPista() 
{
    for (int x = 0; x < 70; x++)
    {
        switch (pista[x])
        {
        case 1:
            cout << "H ";
            break;

        case 2:
            cout << "T ";
            break;

        case 3:
            cout << "OUCH! ";
            break;

        default:
            cout << "_ ";
            break;
        }
    }
    cout << "\n";
}

void changePos()
{
    for (int x = 0; x < 70; x++)
        pista[x] = 0;

    pista[tortugaPos] += tortugaVal;
    pista[liebrePos] += liebreVal;

}
void SetPos(int to, int value) 
{
    if (to == 2) 
    {
        tortugaPos += value;
        if (tortugaPos < 0)
            tortugaPos = 0;
        if (tortugaPos > 70)
            tortugaPos = 69;
    }
    if (to == 1) 
    {
        liebrePos += value;
        if (liebrePos < 0)
            liebrePos = 0;
        if (liebrePos > 70)
            liebrePos = 69;
    }
    changePos();
}

void genMove(int to) 
{
    int val = (rand() % 10) + 1;
    int move;
    if (to == 2)
    {
        if (val <= 5)
        {
            cout << "Tortuga: paso Veloz, 3 cuadros a la derecha\n";
            move = 3;
        }
        if (val >= 6 && val <= 7)
        {
            cout << "Tortuga: Resbalon, 6 cuadros a la izquierda\n";
            move = -6;
        }
        if (val >= 8)
        {
            cout << "Tortuga: Paso lento, 1 cuadro a la derecha\n";
            move = 1;
        }
        SetPos(to, move);
    }
    if (to == 1)
    {
        if (val <= 2)
        {
            cout << "Liebre: Duerme, no se mueve\n";
            move = 0;
        }
        if (val >= 3 && val <= 4)
        {
            cout << "Liebre: Gran salto, 9 cuadros a la derecha\n";
            move = 9;
        }
        if (val == 5)
        {
            cout << "Liebre: Gran resbalon, 12 cuadros a la izquierda\n";
            move = -12;
        }
        if (val >= 6 && val <= 8)
        {
            cout << "Liebre: Salto pequeño, 1 cuadro a la derecha\n";
            move = 1;
        }
        if (val >= 9)
        {
            cout << "Liebre: Respalon pequeño, 2 cuadros a la izquierda\n";
            move = -2;
        }
        SetPos(to, move);
    }
}
   

int main()
{
    cout << "¡BANG!\n¡Y ARRANCAN!\n";
    bool endRace = false;
    do
    {
        genMove(1);
        genMove(2);

        printPista();

        if (tortugaPos >= 69 && liebrePos >= 69)
        {
            endRace = true;
            cout << "Es un empate!";
        }
        else
        {
            if (tortugaPos >= 69)
            {
                endRace = true;
                cout << "¡LA TORTUGA GANA! ¡BRAVO!";
            }
            if (liebrePos >= 69)
            {
                endRace = true;
                cout << "La liebre gana. Ni hablar";
            }
        }

    } while (endRace == false);
}
