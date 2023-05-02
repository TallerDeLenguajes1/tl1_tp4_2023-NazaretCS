#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

 //Valores aleatoreos Formula: [MAX-MIN]+MIN

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
} typedef Tarea;


int CantTares();
void CargarTarea( Tarea **arretareas, int cantidadTareas);
void MostrarTareas(Tarea **arreTareas, int cantidad);
void Mostrar1Tarea(Tarea *tarea);
int consultarEstadoTarea( Tarea **arretareas, Tarea **arreTareasRealizadas, int cantidadTareas);
void listarTareas(Tarea ** arretareas, int cantidadTareas, Tarea ** arreTareasRealizadas, int indiceRealizadas);
void buscarTareaPorID(Tarea **arretareas, int cantidadTareas, Tarea ** arreTareasRealizadas, int indiceRealizadas);


int main(){

    int cantidadTareas, indiceRealizadas;
    Tarea **arretareas, **arreTareasRealizadas;
    //1. Desarrollar una interfaz por consola donde se solicite al usuario (es decir el empleado) cuantas tareas debe cargar.
    cantidadTareas = CantTares();


    // 2. Tendrá que generar un arreglo de doble punteros dinámicamente del tipo Tarea con la cantidad de tareas solicitadas en el punto anterior.Recuerde inicializar los arreglos apuntando a NULL.

    arretareas = (Tarea **)malloc(sizeof(Tarea *)*cantidadTareas);
    srand(time(NULL));

    for (int i = 0; i < cantidadTareas; i++) {
        arretareas[i] = NULL;
    }

    

   // 3 Desarrolle una interfaz de consola para cargar las tareas, ingresando su descripción y duración. Recuerde utilizar reserva de  memoria dinámica para la carga de la descripción.
  
    CargarTarea( arretareas, cantidadTareas);

    
    //MostrarTareas( arretareas, cantidadTareas);
    /* for (int i = 0; i < cantidadTareas; i++)
    {
        Mostrar1Tarea(arretareas[i]);
    } */
    

    //reservo la memoria para el segundo arreglo de tareas con la misma cantidad que el primero:
    arreTareasRealizadas = (Tarea **)malloc(sizeof(Tarea *)*cantidadTareas);
    
    indiceRealizadas = consultarEstadoTarea( arretareas, arreTareasRealizadas, cantidadTareas);
    //printf("La cantidad de tareas realizadas es de: %d",indiceRealizadas);



    //5. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas pendientes.
    listarTareas(arretareas, cantidadTareas, arreTareasRealizadas, indiceRealizadas);

    //6. Cree un nuevo branch llamado busca-tarea e implemente una función de búsqueda de tarea por nro. de id de nombre BuscarTarea. La misma devuelve la tarea solicitada.

    buscarTareaPorID(arretareas, cantidadTareas, arreTareasRealizadas, indiceRealizadas);
    
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

void CargarTarea( Tarea **arretareas, int cantidadTareas){

   // 3 Desarrolle una interfaz de consola para cargar las tareas, ingresando su descripción y duración. Recuerde utilizar reserva de  memoria dinámica para la carga de la descripción.

    char *buff = (char *)malloc(sizeof(char) *100);
    
    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("\n\nCARGADO DE LAS TARES");
        arretareas[i] = (Tarea *)malloc(sizeof(Tarea));  // se reserva la memoria dianamicamente en cada iteracion.

        arretareas[i]->TareaID = i+1;
        arretareas[i]->Duracion = rand() % 90 +10;
        printf("\nIngrese la descripcion de la tarea: \n");
        fflush(stdin);
        gets(buff);
        arretareas[i]->Descripcion = (char *)malloc(sizeof(char) * strlen(buff));
        strcpy(arretareas[i]->Descripcion, buff);
    }
    free(buff);
}

void MostrarTareas(Tarea **arreTareas, int cantidadTareas){
    printf("\n\nMOSTRAR TAREAS  \n");

    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("\n Datos de la Tarea: [ %d ]\n", arreTareas[i]->TareaID);
        printf("    ID Tarea:  %d\n",arreTareas[i]->TareaID);
        printf("    Duracion: %d\n",arreTareas[i]->Duracion);
        printf("    Descripcion: ");
        puts(arreTareas[i]->Descripcion);
    }
}

void Mostrar1Tarea(Tarea *tarea){
    printf("\n\nDatos de la Tarea: %d",tarea->TareaID);
    printf("\n    ID de la Tarea: %d\n", tarea->TareaID);
    printf("    Duracion: %d\n", tarea->Duracion);
    printf("    Descripcion: ");
    puts(tarea->Descripcion);
}


int consultarEstadoTarea( Tarea **arretareas, Tarea **arreTareasRealizadas, int cantidadTareas){

    int estado, indiceRealizadas=0;

    for (int i = 0; i < cantidadTareas; i++)
    {
        Mostrar1Tarea(arretareas[i]);

        do
        {
            printf("Esta tarea ya fue realizada?    Si = 1,  No = 0\n");
            scanf("%d", &estado);

            if (estado != 1 || estado != 0)
            {
                printf("por favor ingrese un valor que corresponda con lo solicitado... \n");
            }
        } while (estado != 1 && estado != 0);
        
        if (estado)
        {
            arreTareasRealizadas[indiceRealizadas] = arretareas[i];
            arretareas[i]=NULL;
            indiceRealizadas++;
        }
    }
    return indiceRealizadas;
}


void listarTareas(Tarea ** arretareas, int cantidadTareas, Tarea ** arreTareasRealizadas, int indiceRealizadas){

    printf("\n\nTAREAS PENDIENTES");
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (arretareas[i])
        {
            Mostrar1Tarea(arretareas[i]);
        }
    }

    printf("\n\nTAREAS PENDIENTES");
    for (int j = 0; j < indiceRealizadas; j++)
    {
        Mostrar1Tarea(arreTareasRealizadas[j]);
    } 
    
}


void buscarTareaPorID(Tarea **arretareas, int cantidadTareas, Tarea ** arreTareasRealizadas, int indiceRealizadas){
    int ID=999;

    

    do
    {
        printf("\nPor favor ingrese el ID de la Tarea que busca...\n(tenga en cuenta que solo tiene %d tareas Cargadas...)\n", cantidadTareas);
        scanf("%d",&ID);
        if (ID < 0 || ID > cantidadTareas)
        {
            printf("\nPor favor se solicita ingresar un dato que este dentro de los parametros solicitados...\n");
        }
        
    } while (ID < 0 || ID > cantidadTareas);
        
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (arretareas[i])
        {
            if (arretareas[i]->TareaID == ID)
            {
                Mostrar1Tarea(arretareas[i]);
                printf("\nLa tarea todavia no se encuentra realizada...\n");
            }
        }
        
        
    }

    for (int j = 0; j < indiceRealizadas; j++)
    {
        if (arreTareasRealizadas[j]->TareaID == ID)
        {
            Mostrar1Tarea(arreTareasRealizadas[j]);
            printf("\nLa tarea ya se realizo...\n");
        }
    }   
}
