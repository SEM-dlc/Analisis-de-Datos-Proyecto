export module Module;

export void MyFunc()
{
    extern "C" {
        int calcularVentasDiarias() {
            int ventas_diarias[] = { 1000, 1500, 2000, 1800, 2500 };
            int num_ventas = sizeof(ventas_diarias) / sizeof(ventas_diarias[0]);

            int ganancia = 0;
            for (int i = 0; i < num_ventas; i++) {
                ganancia += ventas_diarias[i];
            }

            return ganancia;
        }
}