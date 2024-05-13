#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

double calcularGanancia(double ventas, double costos) 
{
    double ganancia;
    __asm 
    {
        fld ventas
        fsub costos
        fstp ganancia
    }
    return ganancia;
}

int main() 
{
    const int NUM_DIAS = 7;
    std::vector<double> ventasDiarias(NUM_DIAS);
    double totalVentas = 0.0;

    for (int i = 0; i < NUM_DIAS; ++i) 
    {
        std::cout << "Ingrese las ventas para el dia " << (i + 1) << ": ";
        std::cin >> ventasDiarias[i];
        totalVentas += ventasDiarias[i];
    }

    double minVenta = *std::min_element(ventasDiarias.begin(), ventasDiarias.end());
    double maxVenta = *std::max_element(ventasDiarias.begin(), ventasDiarias.end());
    double gananciaTotal = calcularGanancia(totalVentas, 0.0);
    double porcentajeGanancia;

    __asm 
    {
        fld gananciaTotal
        fdiv totalVentas
        fmul
        fstp porcentajeGanancia
    }

    std::cout << "La ganancia total es: $" << gananciaTotal << std::endl;
    std::cout << "El dia con la menor venta fue: $" << minVenta << std::endl;
    std::cout << "El dia con la mayor venta fue: $" << maxVenta << std::endl;

    return 0;
}
