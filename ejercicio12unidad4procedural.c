#include <stdio.h>
#include <string.h>

// Definir una estructura para representar la información de una sucursal
struct Sucursal {
    int numero;
    char nombre[50];
    char direccion[100];
    char telefono[15];
};

// Definir una estructura para representar la información de un producto
struct Producto {
    int codigo;
    char nombre[50];
    int calorias;
    float precio;
};

// Definir una estructura para representar la información de una venta
struct Venta {
    int numeroSucursal;
    int codigoProducto;
    int cantidad;
};

int main() {
    // Definir un arreglo de sucursales (puedes agregar más)
    struct Sucursal sucursales[4] = {
        {1, "Sucursal 1", "Dirección 1", "Teléfono 1"},
        {2, "Sucursal 2", "Dirección 2", "Teléfono 2"},
        {3, "Sucursal 3", "Dirección 3", "Teléfono 3"},
        {4, "Sucursal 4", "Dirección 4", "Teléfono 4"}
    };

    // Definir un arreglo de productos (puedes agregar más)
    struct Producto productos[10] = {
        {1, "Producto 1", 100, 5.0},
        {2, "Producto 2", 150, 4.5},
        {3, "Producto 3", 200, 6.0},
        // ...
    };

    // Declarar un arreglo para almacenar la cantidad de productos vendidos por sucursal
    int cantidadVendidaPorSucursal[4] = {0};

    // Declarar un arreglo para almacenar el importe total de productos vendidos por sucursal
    float importeTotalPorSucursal[4] = {0};

    // Variables para registrar la sucursal y el producto con mayor importe de venta
    char sucursalMayorVenta[50];
    char productoMayorVenta[50];
    float mayorImporteVenta = 0;

    // Variables para registrar el producto con mayor consumo de calorías por sucursal
    char productoMayorCaloriasPorSucursal[4][50];
    int mayorCaloriasPorSucursal[4] = {0};

    // Variables para registrar la sucursal con menor importe vendido por producto
    char sucursalMenorImportePorProducto[10][50];
    char sucursalTelefonoMenorImporte[10][15];
    float menorImportePorProducto[10] = {0};

    // Iniciar el ingreso de ventas
    struct Venta venta;
    printf("Ingrese el número de sucursal, código de producto y cantidad vendida (0 para terminar):\n");
    
    while (1) {
        scanf("%d", &venta.numeroSucursal);
        if (venta.numeroSucursal == 0) {
            break; // Salir del bucle si se ingresa 0
        }

        scanf("%d %d", &venta.codigoProducto, &venta.cantidad);

        // Actualizar la cantidad de productos vendidos por sucursal
        cantidadVendidaPorSucursal[venta.numeroSucursal - 1] += venta.cantidad;

        // Calcular el importe total de productos vendidos por sucursal
        float precioProducto = productos[venta.codigoProducto - 1].precio;
        float importeVenta = precioProducto * venta.cantidad;
        importeTotalPorSucursal[venta.numeroSucursal - 1] += importeVenta;

        // Actualizar el registro del producto con mayor importe de venta
        if (importeVenta > mayorImporteVenta) {
            mayorImporteVenta = importeVenta;
            strcpy(sucursalMayorVenta, sucursales[venta.numeroSucursal - 1].nombre);
            strcpy(productoMayorVenta, productos[venta.codigoProducto - 1].nombre);
        }

        // Actualizar el producto con mayor consumo de calorías por sucursal
        if (venta.cantidad * productos[venta.codigoProducto - 1].calorias > mayorCaloriasPorSucursal[venta.numeroSucursal - 1]) {
            mayorCaloriasPorSucursal[venta.numeroSucursal - 1] = venta.cantidad * productos[venta.codigoProducto - 1].calorias;
            strcpy(productoMayorCaloriasPorSucursal[venta.numeroSucursal - 1], productos[venta.codigoProducto - 1].nombre);
        }

        // Actualizar el registro de la sucursal con menor importe vendido por producto
        if (importeVenta < menorImportePorProducto[venta.codigoProducto - 1] || menorImportePorProducto[venta.codigoProducto - 1] == 0) {
            menorImportePorProducto[venta.codigoProducto - 1] = importeVenta;
            strcpy(sucursalMenorImportePorProducto[venta.codigoProducto - 1], sucursales[venta.numeroSucursal - 1].nombre);
            strcpy(sucursalTelefonoMenorImporte[venta.codigoProducto - 1], sucursales[venta.numeroSucursal - 1].telefono);
        }
    }

    // Imprimir resultados
    printf("a) Cantidad de productos vendidos por sucursal:\n");
    for (int i = 0; i < 4; i++) {
        printf("Sucursal %s: %d productos vendidos.\n", sucursales[i].nombre, cantidadVendidaPorSucursal[i]);
    }

    printf("b) Importe total de productos vendidos por sucursal:\n");
    for (int i = 0; i < 4; i++) {
        printf("Sucursal %s: $%.2f de importe total.\n", sucursales[i].nombre, importeTotalPorSucursal[i]);
    }

    printf("c) Sucursal y producto con mayor importe de venta:\n");
    printf("Sucursal: %s, Producto: %s, Importe: $%.2f\n", sucursalMayorVenta, productoMayorVenta, mayorImporteVenta);

    printf("d) Producto con mayor consumo de calorías por sucursal:\n");
    for (int i = 0; i < 4; i++) {
        printf("Sucursal %s, Producto: %s, Consumo de calorías: %d\n", sucursales[i].nombre, productoMayorCaloriasPorSucursal[i], mayorCaloriasPorSucursal[i]);
    }

    printf("e) Sucursal con menor importe vendido por producto:\n");
    for (int i = 0; i < 10; i++) {
        printf("Producto %s, Sucursal: %s, Teléfono: %s, Importe: $%.2f\n", productos[i].nombre, sucursalMenorImportePorProducto[i], sucursalTelefonoMenorImporte[i], menorImportePorProducto[i]);
    }

    return 0;
}
