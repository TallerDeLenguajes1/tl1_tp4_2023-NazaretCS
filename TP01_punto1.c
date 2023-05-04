#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Valores aleatoreos Formula: [MAX-MIN]+MIN

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
    int realizada;
} typedef Tarea;


struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
} typedef Nodo;

typedef struct Nodo* Lista;

int CantTares();
Lista CrearLista();
Lista CrearNodo();
void MostrarTareas(Lista tareas);
Lista CargarTarea(Lista tareasPendientes, int ID);
void Mostrar1Tarea(Tarea tarea);
void consultarEstadoTareas(Lista* listaTareasPendientes, Lista* listaTareasRealizadas);
void EstadoDeTareas(Lista tareasPendientes, Lista tareasRealizadas);
void BuscarTareaIDEnLasListas(Lista ListaTareas, Lista ListaTareasRealizadas, int ID);  // Busca la tarea en ambas listas e informa el estado de la misma
int BuscarTareaID(Lista listaTareas, int ID); //Busca tarea en una sola lista en espesifico.
void liberarMemoria(Lista * ListaTareas);


int main(){

    //int cantidadTareas;   

    //cantidadTareas = CantTares();

    // Desarrollo la interfas para que el usuaio sea quien decida si seguira ingresando tareas o no 
    int respuesta, i =0;



    Lista tareasPendientes;
    Lista tareasRealizadas;

    tareasPendientes = CrearLista();   
    tareasRealizadas = CrearLista();

    srand(time(NULL));


    do
    {
        printf("\nDesea seguir cargando tareas?\n   1 : Si...  0 : No...\n");
        scanf("%d",&respuesta);

        if (respuesta)
        {
            tareasPendientes = CargarTarea(tareasPendientes, i+1);
            i++;
        }
                
    } while (respuesta);
    

/*    Eran test para comprovar si me creeaban bien las listas
    printf("Lista de Tareas Pendientes:\n");
    MostrarTareas(tareasPendientes);
    printf("Lista de Tareas Realizadas:\n");
    MostrarTareas(tareasPendientes);
     */




   // 3 Desarrolle una interfaz de consola para cargar las tareas, ingresando su descripción y duración. Recuerde utilizar reserva de  memoria dinámica para la carga de la descripción.
  
    //Cargo las tareas la lista

   /*  for (int i = 0; i < cantidadTareas; i++)
    {
        tareasPendientes = CargarTarea(tareasPendientes, i+1);
    } */

    
    
    

    //MostrarTareas(tareasPendientes);
   

    //5. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas pendientes.


    consultarEstadoTareas(&tareasPendientes, &tareasRealizadas); 

    EstadoDeTareas(tareasPendientes, tareasRealizadas);


    int IDaBuscar;
    printf("\nIngrese el ID de la tarea que desea Buscar...\n");
    scanf("%d",&IDaBuscar);
   
    BuscarTareaIDEnLasListas(tareasPendientes, tareasRealizadas, IDaBuscar);

    liberarMemoria(&tareasPendientes);
    liberarMemoria(&tareasRealizadas);

    return 0;
}

int CantTares(){

    //1. Desarrollar una interfaz por consola donde se solicite al usuario (es decir el empleado) cuantas tareas debe cargar.

    int cantidadTareas;
    do
    {
        printf("\nIngrese la cantidad de Tareas que deve cargar el empleado\n");
        scanf("%d",&cantidadTareas);
        if (cantidadTareas <= 0)
        {
            printf("No se puede ingresar una cantidad de tareas Negativas");
        }
        
    } while (cantidadTareas <= 0);
    return cantidadTareas;
}



Lista CrearLista(){
    return NULL;
    // ara que la cabezera de la lista apunte a NULL
}


Lista CrearNodo(){  //Si la particularizo para el problema se podria llamar CrearTarea
    Lista newNodo = (Lista)malloc(sizeof(Nodo));
    //Una vez Creado el nodo me concentro en los datos que llevara

    int duracion = rand() % 90 +10;
    char *buff = (char *)malloc(sizeof(char)*200);

    fflush(stdin);
    printf("\nIngrese La descripcion de la tarea:");
    gets(buff);

    newNodo->T.Descripcion = (char *)malloc((strlen(buff)+1) * sizeof(char));
    strcpy( newNodo->T.Descripcion, buff);
    newNodo->T.Duracion = duracion;
    newNodo->Siguiente = NULL;
    free(buff);
    return newNodo;
}


Lista CargarTarea(Lista tareasPendientes, int ID){

    Lista nuevoNodo = CrearNodo();

    nuevoNodo->T.TareaID = ID;

    if (tareasPendientes)   // Tener cuidado con esta parte
    {
        Lista auxiliar = tareasPendientes;

        while (auxiliar->Siguiente != NULL)
        {
            auxiliar = auxiliar->Siguiente;
            // Si no es ultimo nodo sigo iterando hasta llegar a lo que nesesito
        }
        // Una vez que estoy en el ultimo nodo puedo enlazar mi nuevo nodo...
        auxiliar->Siguiente = nuevoNodo;
    
    } else {
        
        // Como mi lista no tiene ningun nodo directamente enlazo mi nuevo nodo al comienzo
        nuevoNodo->Siguiente = tareasPendientes;
        tareasPendientes = nuevoNodo;

    }
    return tareasPendientes;
}

void MostrarTareas(Lista tareas){
    Lista auxiliar = tareas;
    printf("\n\nMOSTRADO DE TODAS LAS TAREAS\n");

    if (auxiliar==NULL)
    {
        printf("\nLa Lista se encuentra Vacia\n");
    } else {
        while (auxiliar != NULL)
        {
            printf("\n  ID TAREA %d\n", auxiliar->T.TareaID);
            printf("    Tienen una duracion de: %d\n",auxiliar->T.Duracion);
            printf("    Descripcion: %s\n",auxiliar->T.Descripcion);
            auxiliar = auxiliar->Siguiente;
        }
    }    
}


void Mostrar1Tarea(Tarea tarea){
    printf("\n  ID TAREA %d\n", tarea.TareaID);
    printf("    Tienen una duracion de: %d\n",tarea.Duracion);
    printf("    Descripcion: %s\n",tarea.Descripcion);
}



void consultarEstadoTareas(Lista* listaTareasPendientes, Lista* listaTareasRealizadas){

    int realizada;
    Lista listaTareasPendientesAux = NULL;
    Nodo* puntProxNodoAux = NULL;

    printf("\n\n- Ahora analicemos cada tarea:\n");

    while(*listaTareasPendientes != NULL){

        puntProxNodoAux = (*listaTareasPendientes)->Siguiente;

        Mostrar1Tarea((*listaTareasPendientes)->T);

        do
        {
            printf("Fue realizada? 1: si, 0; no\n");
            scanf("%d", &realizada);

        } while (realizada != 0 && realizada != 1);
    
        if(realizada == 1){
            (*listaTareasPendientes)->Siguiente = *listaTareasRealizadas;
            // El puntero del nodo a agregar a la lista de tareas realizadas apuntará al último nodo agregado a dicha lista.
            *listaTareasRealizadas = *listaTareasPendientes;
            // La cabecera de la lista de tareas realizadas apunta al nodo recién agregado a la lista.
        } else {
            (*listaTareasPendientes)->Siguiente = listaTareasPendientesAux;
            // El puntero del nodo a agregar a la lista de tareas pendientes (auxiliar) apuntará al último nodo agregado a dicha lista.
            listaTareasPendientesAux = *listaTareasPendientes;
            // El puntero del nodo a agregar a la lista de tareas pendientes (auxiliar) apuntará al último nodo agregado a dicha lista.
        }
        // Se usa una lista auxiliar para tareas pendientes a fin de evitar tener que revincular nodos de la lista de tareas pendientes y considerar distintos casos donde el nodo que puede ser pasado a la lista de tareas realizadas esté o al principio, o en el medio, o al final de la lista de tareas pendientes original.

        *listaTareasPendientes = puntProxNodoAux;
    }
    *listaTareasPendientes = listaTareasPendientesAux;
}


void EstadoDeTareas(Lista tareasPendientes, Lista tareasRealizadas){
    printf("\n\n TAREAS PENDIENTES\n");
    MostrarTareas(tareasPendientes);

    printf("\n\n TAREAS REALIZADAS\n");
    MostrarTareas(tareasRealizadas);
}


int BuscarTareaID(Lista listaTareas, int ID){
    
    printf("\nBusqueda de la Tarea %d\n",ID);
    Lista auxiliar = listaTareas;
    int bandera = 0;

    while (auxiliar)
    {
        if (auxiliar->T.TareaID == ID)
        {
            printf("\nTarea Encontrada:\n");
            Mostrar1Tarea(auxiliar->T);
            bandera = 1;
        }
        auxiliar = auxiliar->Siguiente;
    }     
    return bandera;  
}
void BuscarTareaIDEnLasListas(Lista ListaTareas, Lista ListaTareasRealizadas, int ID){

    
    int estado = BuscarTareaID(ListaTareas, ID);
    if (estado)
    {
        printf("Estado de la tarea:\n     PENDIENTE\n");
    } else {
        estado = BuscarTareaID(ListaTareasRealizadas, ID);
        printf("Estado de la tarea:\n     REALIZADA\n");
    }
    //printf("Saliendo a BuscarTareas1");
}



void liberarMemoria(Lista * ListaTareas){
    Nodo* auxLiberarMemoria = NULL;

    while (ListaTareas)
    {
        free((*ListaTareas)->T.Descripcion);
        auxLiberarMemoria = *ListaTareas;
        *ListaTareas = (*ListaTareas)->Siguiente;
        free(auxLiberarMemoria);
    }
}



