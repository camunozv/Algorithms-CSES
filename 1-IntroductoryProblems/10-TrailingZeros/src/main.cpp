#include <bits/stdc++.h> // includes several standard libraries, including <iostream>
#define LLUI unsigned long long int
using namespace std;

int trailingZeros(LLUI nummer);
int main()
{
    LLUI n = 0;
    cin >> n;

    // Multiplicar hasta antesito de irme a overflow. Justo ahi contar el número de ceros. Guardar el resultado.
    // Reiniciar la variable acumuladora a 1. Y empezar a multiplicar de nuevo donde me quedé. Así hasta el final
    // del ciclo.

    // Puedo multiplicar los digitos cada 5 veces contar el número de veces que se divide el número por 10.

    // ¿Cómo verificar antes de entrar a overflow?

    cout << trailingZeros(n) << "\n";
    cout << "Well done nigger \n";
    return 0;
}

int trailingZeros(LLUI nummer)
{

    LLUI product = 1;
    int zerosCounter = 0;

    for (LLUI i = 5; i <= nummer; i += 5)
    {
        product = (i) * (i - 1);
        while (product % 10 == 0)
        {
            zerosCounter++;
            product = product / 10;
        }

        product = 1;
    }

    // (a + b) mod m == (a mod m + b mod m) mod m
    // (a - b) mod m == (a mod m - b mod m) mod m
    // (a * b) mod m == (a mod m * b mod m) mod m
    
    // 8 * 9 * 50 == 3600

    // usar modulo 10 como un hijo de perra
    return zerosCounter;
}