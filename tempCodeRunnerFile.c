#include<stdio.h>

int main(void){

    int estado = 9;

        /* do
        {
            printf("Esta tarea ya fue realizada?    Si = 1,  No = 0\n");
            scanf("%d", &estado);

            if (estado != 1 || estado != 0)
            {
                printf("por favor ingrese un valor que corresponda con lo solicitado... \n");
            }
            
        } while (estado != 1 && estado != 0);
 */
    int ID=999;
    int mayor = 90;

    do
    {
        printf("\nPor favor ingrese el ID de la Tarea que busca...\n(tenga en cuenta que solo tiene %d tareas Cargadas...)\n", mayor);
        scanf("%d",&ID);
        if(ID < 0 || ID > mayor){
            printf("Entro por mal dato ingresado");
        }
    } while (ID < 0 || ID > mayor);
        

    return 0;
}