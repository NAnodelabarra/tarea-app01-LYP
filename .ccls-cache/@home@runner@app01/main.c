#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de Cliente
struct Cliente {
    char rut[12];
    char nombre_completo[50];
    int edad;
    char cod_plan[4];
    char descripcion_plan[20];
    char desde[11];
    char hasta[11];
    char cod_sede[4];
    char ubicacion_sede[50];
    struct Cliente* siguiente;
};



// Declaración de las funciones
void mostrar_menu();
void agregar_cliente();
void quitar_cliente();
void editar_cliente();
void agregar_plan();
void quitar_plan();
void cambiar_plan();
void agregar_sede();
void quitar_sede();
void cambiar_sede();
void buscar_cliente_por_rut();
int validar_rut(char rut[]);
int validar_edad(int edad);
int validar_fecha(char fecha[]);
int validar_cod_plan(char cod_plan[]);
int validar_cod_sede(char cod_sede[]);
int validar_plan_existente(char cod_plan[]);
int validar_sede_sin_clientes(char cod_sede[]);
int validar_rut_existente(char rut[]);
int validar_cambio_plan(char rut[], char cod_plan[]);
int validar_cambio_sede(char rut[], char cod_sede[]);

// Variables globales
struct Cliente* lista_clientes = NULL; // Puntero al primer cliente
int num_clientes = 0; // Número actual de clientes




void contar_clientes() {
    FILE* archivo = fopen("bigmuscle.csv", "r"); // Abrir archivo en modo lectura
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    char caracter;
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') {
            num_clientes++; // Actualizar número de clientes
            //printf("total de filas: %i\n", num_clientes);
        }
    }
    fclose(archivo); // Cerrar archivo
}

void guardar_cliente_en_archivo(struct Cliente cliente) {
    FILE* archivo = fopen("bigmuscle.csv", "a"); // Abrir archivo en modo append
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(archivo, "%s,%s,%d,%s,%s,%s,%s,%s,%s\n", cliente.rut, cliente.nombre_completo, cliente.edad,
            cliente.cod_plan, cliente.descripcion_plan, cliente.desde, cliente.hasta, cliente.cod_sede,
            cliente.ubicacion_sede);
    fclose(archivo); // Cerrar archivo
}





int main() {
    int opcion;
    
    //contar_clientes();
    //printf("total de clientes: %d\n", num_clientes);

    do {
        mostrar_menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregar_cliente();
                break;
            case 2:
                quitar_cliente();
                break;
            case 3:
                editar_cliente();
                break;
            case 4:
                agregar_plan();
                break;
            case 5:
                quitar_plan();
                break;
            case 6:
                cambiar_plan();
                break;
            case 7:
                agregar_sede();
                break;
            case 8:
                quitar_sede();
                break;
            case 9:
                cambiar_sede();
                break;
            case 10:
                buscar_cliente_por_rut();
                break;
            case 11:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 11);

    return 0;
}

// Función para mostrar el menú de opciones
void mostrar_menu() {
    printf("\n--- BigMuscle ---\n");
    printf("1. Agregar cliente\n");
    printf("2. Quitar cliente\n");
    printf("3. Editar datos de un cliente\n");
    printf("4. Agregar plan\n");
    printf("5. Quitar plan\n");
    printf("6. Cambiar plan a un cliente\n");
    printf("7. Agregar sede\n");
    printf("8. Quitar sede\n");
    printf("9. Cambiar sede a un cliente\n");
    printf("10. Buscar cliente por RUT\n");
    printf("11. Salir\n");
    printf("------------------\n");
}


void agregar_cliente() {
    struct Cliente nuevo_cliente;
    printf("Ingresar RUT (sin puntos ni guion): ");
    scanf("%s", nuevo_cliente.rut);
    printf("Ingresar nombre completo: ");
    scanf("%s", nuevo_cliente.nombre_completo);
    printf("Ingresar edad: ");
    scanf("%d", &nuevo_cliente.edad);
    printf("Ingresar codigo de plan: ");
    scanf("%s", nuevo_cliente.cod_plan);
    printf("Ingresar descripcion de plan: ");
    scanf("%s", nuevo_cliente.cod_plan);
    
    printf("Ingresar fecha de inicio del plan (dd/mm/aaaa): ");
    scanf("%s", nuevo_cliente.desde);
    printf("Ingresar fecha de termino del plan (dd/mm/aaaa): ");
    scanf("%s", nuevo_cliente.hasta);
    
    printf("Ingresar codigo de sede: ");
    scanf("%s", nuevo_cliente.cod_sede);
    
    printf("Ingresar ubicacion de sede: ");
    scanf("%s", nuevo_cliente.ubicacion_sede);

    guardar_cliente_en_archivo(nuevo_cliente);
    lista_clientes[num_clientes] = nuevo_cliente;
    num_clientes++;
    printf("Cliente agregado correctamente.\n");
}

// Función para quitar un cliente de la lista
void quitar_cliente() {
    // TODO: Implementar código para quitar un cliente de la lista
}

// Función para editar los datos de un cliente de la lista
void editar_cliente() {
    // TODO: Implementar código para editar los datos de un cliente de la lista
}

// Función para agregar un nuevo plan a la lista de planes
void agregar_plan() {
    // TODO: Implementar código para agregar un nuevo plan a la lista de planes
}

// Función para quitar un plan de la lista de planes
void quitar_plan() {
    // TODO: Implementar código para quitar un plan de la lista de planes
}

// Función para cambiar el plan de un cliente
void cambiar_plan() {
    // TODO: Implementar código para cambiar el plan de un cliente
}

// Función para agregar una sede
void agregar_sede() {
    // TODO: Implementar código para quitar una sede de la lista de sedes
}
// Función para quitar una sede de la lista de sedes
void quitar_sede() {
    // TODO: Implementar código para quitar una sede de la lista de sedes
}

// Función para cambiar la sede de un cliente
void cambiar_sede() {
    // TODO: Implementar código para cambiar la sede de un cliente
}

// Función para buscar un cliente por RUT
void buscar_cliente_por_rut() {
    // TODO: Implementar código para buscar un cliente por RUT
}

// Función para validar un RUT
int validar_rut(char rut[]) {
    // TODO: Implementar código para validar un RUT
    return 1;
}

// Función para validar la edad de un cliente
int validar_edad(int edad) {
    // TODO: Implementar código para validar la edad de un cliente
    return 1;
}

// Función para validar una fecha
int validar_fecha(char fecha[]) {
    // TODO: Implementar código para validar una fecha
    return 1;
}

// Función para validar el código de un plan
int validar_cod_plan(char cod_plan[]) {
    // TODO: Implementar código para validar el código de un plan
    return 1;
}

// Función para validar el código de una sede
int validar_cod_sede(char cod_sede[]) {
    // TODO: Implementar código para validar el código de una sede
    return 1;
}

// Función para validar que un plan existe
int validar_plan_existente(char cod_plan[]) {
    // TODO: Implementar código para validar que un plan existe
    return 1;
}

// Función para validar que una sede no tenga clientes registrados
int validar_sede_sin_clientes(char cod_sede[]) {
    // TODO: Implementar código para validar que una sede no tenga clientes registrados
    return 1;
}

// Función para validar que un RUT no esté repetido
int validar_rut_existente(char rut[]) {
    // TODO: Implementar código para validar que un RUT no esté repetido
    return 1;
}

// Función para validar que se puede cambiar el plan de un cliente
int validar_cambio_plan(char rut[], char cod_plan[]) {
    // TODO: Implementar código para validar que se puede cambiar el plan de un cliente
    return 1;
}

// Función para validar que se puede cambiar la sede de un cliente
int validar_cambio_sede(char rut[], char cod_sede[]) {
    // TODO: Implementar código para validar que se puede cambiar la sede de un cliente
    return 1;
}
