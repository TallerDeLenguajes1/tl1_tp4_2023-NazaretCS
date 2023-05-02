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



int main(){

    int cantidadTareas;
   

    //1. Desarrollar una interfaz por consola donde se solicite al usuario (es decir el empleado) cuantas tareas debe cargar.
    cantidadTareas = CantTares();


    // 2. Tendrá que generar un arreglo de doble punteros dinámicamente del tipo Tarea con la cantidad de tareas solicitadas en el punto anterior.Recuerde inicializar los arreglos apuntando a NULL.
    // En esta implementacion se reemplaza los arreglos por dos listas

    Lista tareasPendientes;
    Lista tareasRealizadas;

    tareasPendientes = CrearLista();
    tareasRealizadas = CrearLista();

    srand(time(NULL));

    printf("Lista de Tareas Pendientes:\n");
    MostrarTareas(tareasPendientes);
    printf("Lista de Tareas Realizadas:\n");
    MostrarTareas(tareasPendientes);
    

   // 3 Desarrolle una interfaz de consola para cargar las tareas, ingresando su descripción y duración. Recuerde utilizar reserva de  memoria dinámica para la carga de la descripción.
  
    //Cargo las tareas la lista
    for (int i = 0; i < cantidadTareas; i++)
    {
        tareasPendientes = CargarTarea(tareasPendientes, i+1);
    }
    

    //MostrarTareas(tareasPendientes);

    consultarEstado(tareasPendientes, tareasRealizadas);
    

    //5. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas pendientes.


   


    //6. Cree un nuevo branch llamado busca-tarea e implemente una función de búsqueda de tarea por nro. de id de nombre BuscarTarea. La misma devuelve la tarea solicitada.

   


    //7. Vuelva al branch main e implemente también una nueva versión de la función BuscarTarea en donde la misma sea por palabra clave en vez de por Id. (uno le manda una palabra y te tiene que devolver la primera tarea que contenga dicha palabra).


    
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



void consultarEstado(Lista * listaPedndientes, Lista* listaRealizadas){
 
    printf("\nAnalizaremos Tarea por Tare:\n");

    

    while (*listaPedndientes != NULL)
    {
        /* code */
    }
    
}


/* Nodo* quitarNodo(Lista * listaPendientes){

    Nodo* aux = NULL;
    if (*listaPendientes != NULL){
        aux = *listaPendientes;
        *listaPendientes = (*listaPendientes)->Siguiente;

    }
    
} */
