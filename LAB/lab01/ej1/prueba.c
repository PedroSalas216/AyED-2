#include <stdio.h>

int funcion(int n[])
{
    n[1] = 1216753192;
    return 10;
}

void imprimeArreglo(int a[], unsigned int n_max)
{
    unsigned int i = 0;
    printf("[");

    while (i < n_max)
    {
        if (i == n_max - 1)
        {
            printf("%d",a[i]);
        }else
        {
            printf("%d,",a[i]);
        }       
        i++;            
    }
    printf("]\n");

}
void i()
{
	if(1){printf("a");}
}

int main()
{   
    int a[3];
    a[0] = 1;
    a[1] = 1;
    a[2] = 1;
    int b = 0;
	
    i();
    imprimeArreglo(a,3);
    printf("%d\n",b);

    b = funcion(a);
    
    imprimeArreglo(a,3);
    printf("%d\n",b);

    return 0;
}
