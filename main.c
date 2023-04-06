#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Definimos estructuras
typedef struct {
    char rut[12];
    char nombre_completo[50];
    int edad;
    char cod_plan[4];
    char descripcion_plan[20];
    char desde[11];
    char hasta[11];
    char cod_sede[4];
    char ubicacion_sede[20];
} Cliente;

typedef struct {
    char cod_plan[4];
    char descripcion_plan[20];
} Plan;

typedef struct {
    char cod_sede[4];
    char ubicacion_sede[20];
} Sede;

//
//Variables globales
#define MAX_LINE_LENGTH 200

Cliente* lista_clientes;
int num_clientes;
Plan* lista_planes;
Sede* lista_sedes;
int cambios_realizados;

//
//Funciones basicas
Cliente* leer_archivo_clientes(char* nombre_archivo, int* num_clientes) {
  FILE* archivo;
  char linea[MAX_LINE_LENGTH];
  char* campo;
  Cliente* lista_clientes = NULL;
  Plan* lista_planes = NULL;
  Sede* lista_sedes = NULL;
  *num_clientes = 0;
  int capacidad = 0;
  int contador = 0;
  
  archivo = fopen(nombre_archivo, "r");
  if (archivo == NULL) {
    printf("Error al abrir el archivo %s.\n", nombre_archivo);
    return NULL;
  }

  // Leer y descartar la primera línea (nombres de las columnas)
  if (fgets(linea, MAX_LINE_LENGTH, archivo) == NULL) {
    printf("Error al leer el archivo %s.\n", nombre_archivo);
    fclose(archivo);
    return NULL;
  }
  
  // Leer cada línea del archivo y guardar los datos en una estructura Cliente
  while (fgets(linea, MAX_LINE_LENGTH, archivo) != NULL) {
    if (contador >= capacidad) {
        capacidad += 10;
        lista_clientes = (Cliente*) realloc(lista_clientes, capacidad * sizeof(Cliente));
        if (lista_clientes == NULL) {
            printf("Error al asignar memoria.\n");
            fclose(archivo);
            return NULL;
        }
    }
      
    // Separar los campos de la línea usando la coma como separador
    campo = strtok(linea, ",");
    strcpy(lista_clientes[contador].rut, campo);
    campo = strtok(NULL, ",");
    strcpy(lista_clientes[contador].nombre_completo, campo);
    campo = strtok(NULL, ",");
    lista_clientes[contador].edad = atoi(campo);
    campo = strtok(NULL, ",");
    strcpy(lista_clientes[contador].cod_plan, campo);
    campo = strtok(NULL, ",");
    strcpy(lista_clientes[contador].descripcion_plan, campo);
    campo = strtok(NULL, ",");
    strcpy(lista_clientes[contador].desde, campo);
    campo = strtok(NULL, ",");
    strcpy(lista_clientes[contador].hasta, campo);
    campo = strtok(NULL, ",");
    strcpy(lista_clientes[contador].cod_sede, campo);
    campo = strtok(NULL, ",");
    strcpy(lista_clientes[contador].ubicacion_sede, campo);
    
    contador++;
  }
  
  fclose(archivo);
  *num_clientes = contador;
  return lista_clientes;
}

void imprimir_clientes(Cliente* lista_clientes, int num_clientes, int indice) {
    if (indice >= num_clientes) {         
        return;
    }
    
    printf("\n");
    printf("@imprimir_clientes():\n");
    printf("Cliente numero %d\n", indice+1);
    printf("RUT: %s\n", lista_clientes[indice].rut);
    printf("Nombre completo: %s\n", lista_clientes[indice].nombre_completo);
    printf("Edad: %d\n", lista_clientes[indice].edad);
    printf("Código de plan: %s\n", lista_clientes[indice].cod_plan);
    printf("Descripción de plan: %s\n", lista_clientes[indice].descripcion_plan);
    printf("Fecha desde: %s\n", lista_clientes[indice].desde);
    printf("Fecha hasta: %s\n", lista_clientes[indice].hasta);
    printf("Código de sede: %s\n", lista_clientes[indice].cod_sede);
    printf("Ubicación de sede: %s\n", lista_clientes[indice].ubicacion_sede);
    printf("\n");
    
    imprimir_clientes(lista_clientes, num_clientes, indice+1);
}

//
// Funciones solicitadas por enunciado de la tarea

void agregar_cliente(Cliente** lista_clientes, int* num_clientes) {
    Cliente nuevo_cliente;
    int i;
    printf("\n@agregar_cliente():\n");
    
    // Pedir los datos del nuevo cliente al usuario
    printf("Ingrese el RUT del nuevo cliente (Sin puntos, con guion): ");
    scanf("%s", nuevo_cliente.rut);
    printf("Ingrese el nombre completo del nuevo cliente: ");
    scanf(" %[^\n]", nuevo_cliente.nombre_completo);
    printf("Ingrese la edad del nuevo cliente: (INT) ");
    scanf("%d", &nuevo_cliente.edad);
    printf("Ingrese el código de plan del nuevo cliente: ");
    scanf("%s", nuevo_cliente.cod_plan);
    printf("Ingrese la descripción de plan del nuevo cliente: ");
    scanf(" %[^\n]", nuevo_cliente.descripcion_plan);
    printf("Ingrese la fecha desde del nuevo cliente (formato DD/MM/AAAA): ");
    scanf("%s", nuevo_cliente.desde);
    printf("Ingrese la fecha hasta del nuevo cliente (formato DD/MM/AAAA): ");
    scanf("%s", nuevo_cliente.hasta);
    printf("Ingrese el código de sede del nuevo cliente: ");
    scanf("%s", nuevo_cliente.cod_sede);
    printf("Ingrese la ubicación de sede del nuevo cliente: ");
    scanf(" %[^\n]", nuevo_cliente.ubicacion_sede);
    
    // Comprobar que el RUT del nuevo cliente no exista en la lista de clientes
    for (i = 0; i < *num_clientes; i++) {
        if (strcmp(nuevo_cliente.rut, (*lista_clientes)[i].rut) == 0) {
            printf("Error: el RUT %s ya está registrado.\n", nuevo_cliente.rut);
            return;
        }
    }
    
    // Añadir el nuevo cliente a la lista de clientes
    *num_clientes += 1;
    *lista_clientes = (Cliente*) realloc(*lista_clientes, (*num_clientes) * sizeof(Cliente));
    if (*lista_clientes == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
  
    (*lista_clientes)[*num_clientes - 1] = nuevo_cliente;
  
    printf("\nSe agrego exitosamente el siguiente  cliente:");
    imprimir_clientes(*lista_clientes, *num_clientes, *num_clientes - 1);
    printf("\n");
  
}

// Función para quitar un cliente
void quitar_cliente() {
    // Implementar código aquí
}

// Función para editar los datos de un cliente
void editar_cliente() {
    // Implementar código aquí
}

// Función para agregar un plan
void agregar_plan() {
    // Implementar código aquí
}

// Función para quitar un plan
void quitar_plan() {
    // Implementar código aquí
}

// Función para cambiar el plan y la vigencia de un cliente
void cambiar_plan_cliente() {
    // Implementar código aquí
}

// Función para agregar una sede
void agregar_sede() {
    // Implementar código aquí
}

// Función para quitar una sede
void quitar_sede() {
    // Implementar código aquí
}

// Función para cambiar la sede de un cliente
void cambiar_sede_cliente() {
    // Implementar código aquí
}

// Función para buscar un cliente por RUT
void buscar_cliente_rut() {
    // Implementar código aquí
}

//
// Funciones verificadoras

// Función para mostrar el menú principal
void mostrar_menu_principal() {
  printf("MENU PRINCIPAL\n");
  printf("Ingrese un numero:\n");
  printf("( 1 ) Agregar cliente\n");
  printf("( 2 ) Quitar cliente\n");
  printf("( 3 ) Editar datos del cliente\n");
  printf("( 4 ) Agregar plan\n");
  printf("( 5 ) Quitar plan\n");
  printf("( 6 ) Cambiar plan y vigencia de un cliente\n");
  printf("( 7 ) Agregar sede\n");
  printf("( 8 ) Quitar sede\n");
  printf("( 9 ) Cambiar sede de un cliente\n");
  printf("( 10) Buscar cliente por RUT\n");
  printf("( 11) Salir\n");
  printf("\n");
}

int marcador() {
  int opcion = 0;
  
  // Implementar código aquí para leer los datos del archivo "bigmuscle.csv"
  // y cargarlos en las listas de clientes, planes y sedes
  
  while (opcion != 11) {
    mostrar_menu_principal();
    scanf("%d", &opcion);
    switch (opcion) {
      case 1:
        agregar_cliente(&lista_clientes, &num_clientes);
        cambios_realizados = 1;
        break;
      case 2:
        quitar_cliente();
        cambios_realizados = 1;
        break;
      case 3:
        editar_cliente();
        cambios_realizados = 1;
        break;
      case 4:
        agregar_plan();
        cambios_realizados = 1;
        break;
      case 5:
        quitar_plan();
        cambios_realizados = 1;
        break;
      case 6:
        cambiar_plan_cliente();
        cambios_realizados = 1;
        break;
      case 7:
        agregar_sede();
        cambios_realizados = 1;
        break;
      case 8:
        quitar_sede();
        cambios_realizados = 1;
        break;
      case 9:
        cambiar_sede_cliente();
        cambios_realizados = 1;
        break;
      case 10:
        buscar_cliente_rut();
        break;
      case 11:
        break;
      default:
        printf("Opción inválida.\n");
        break;
    }
  }
  
  // Implementar código aquí para liberar la memoria de las listas de clientes, planes y sedes
  
}

int init() {

  int cambios_realizados = 0;
  int num_planes = 0;
  int num_sedes = 0;
  
  printf("\n@init():\n");
  lista_clientes = leer_archivo_clientes("bigmuscle.csv", &num_clientes);
  if (lista_clientes == NULL) {
    printf("Error al leer el archivo de clientes.\n");
    return 1;
  }
  
  if (num_clientes > 0) {
    printf("Se encontraron %d clientes.\n", num_clientes);
    //imprimir_clientes(lista_clientes, num_clientes, 0);
  } else {
    printf("No se encontraron clientes en el archivo.\n");
  }
  
  printf("\n");
  return 0;
}

int end() {
  if (cambios_realizados) {
    // Implementar código aquí para guardar los datos en el archivo "bigmuscle.csv"
    // y en el archivo de respaldo "bigmuscle.bak"
  }
  free(lista_clientes);
  return 0;
}

int orq() {
    init();
    marcador();
    end();
    return 0;
}

int main() {
    orq();
    return 0;
}
