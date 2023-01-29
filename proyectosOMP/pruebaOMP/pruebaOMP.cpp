// pruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 50
#define mostrar 25

void imprimeArreglo(float*d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        a[i] = i * 5;
        b[i] = (i + 10) * 2.5;
    }
    int parte = chunk;

    #pragma omp parallel for \
    shared(a, b, c, parte) private(i) \
    schedule(static, parte)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl; imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl; imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl; imprimeArreglo(c);
}

void imprimeArreglo(float*d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
        std::cout << std::endl;
}