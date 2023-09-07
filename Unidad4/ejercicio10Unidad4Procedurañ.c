#include <stdio.h>

#define MESES 12
#define MAQUINAS 20

// Definir una estructura para el consumo de combustible
struct ConsumoCombustible {
    float litros[MESES][MAQUINAS];
};

// Función recursiva para calcular la cantidad total de combustible utilizada en un mes específico
float calcularTotalMes(const struct ConsumoCombustible *datos, int mes, int maquina) {
    if (mes < 0 || mes >= MESES) {
        return 0;
    }
    return datos->litros[mes][maquina] + calcularTotalMes(datos, mes - 1, maquina);
}

// Función para calcular el gasto promedio de combustible de todas las máquinas en un mes específico
float calcularPromedioMes(const struct ConsumoCombustible *datos, int mes) {
    float total = 0;
    for (int i = 0; i < MAQUINAS; i++) {
        total += datos->litros[mes][i];
    }
    return total / MAQUINAS;
}

// Función para encontrar el mes con el mayor gasto de combustible para una máquina específica
int encontrarMayorGastoMes(const struct ConsumoCombustible *datos, int mes, int maquina, float *maxGasto) {
    if (mes < 0) {
        *maxGasto = 0;
        return -1; // Indica que no se encontró un mes con mayor gasto
    }

    float gastoActual = datos->litros[mes][maquina];
    float maxGastoAnterior;
    int mesAnterior = encontrarMayorGastoMes(datos, mes - 1, maquina, &maxGastoAnterior);

    if (gastoActual > maxGastoAnterior) {
        *maxGasto = gastoActual;
        return mes;
    } else {
        *maxGasto = maxGastoAnterior;
        return mesAnterior;
    }
}

int main() {
    struct ConsumoCombustible datos;

    // Inicializar los datos de consumo de combustible (aquí puedes llenar los valores)

    int mesDeseado = 5;
    int maquinaDeseada = 0; // Cambia esto para la máquina deseada (de 0 a 19)

    float totalMes5 = calcularTotalMes(&datos, mesDeseado, maquinaDeseada);
    printf("La cantidad total de combustible utilizada en el mes %d por la máquina %d es: %.2f litros.\n", mesDeseado, maquinaDeseada, totalMes5);

    float promedioMes5 = calcularPromedioMes(&datos, mesDeseado);
    printf("El gasto promedio de combustible de todas las máquinas en el mes %d es: %.2f litros.\n", mesDeseado, promedioMes5);

    float maxGasto;
    int mesMayorGasto = encontrarMayorGastoMes(&datos, MESES - 1, maquinaDeseada, &maxGasto);
    printf("El mes con mayor gasto de combustible para la máquina %d es el mes %d con %.2f litros.\n", maquinaDeseada, mesMayorGasto, maxGasto);

    return 0;
}
