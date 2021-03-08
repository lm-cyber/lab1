/*Из входного потока вводится последовательных целых неотрицательных чисел {ai}, i = 1, …, m.  Значение m заранее не известно и вводится из входного потока.

Сформировать непрямоугольную матрицу, i-ая строка которой содержит числа Фибоначчи, сумма которых равна i-му числу исходной последовательности, причем каждое число Фибоначчи входит в сумму не более одного раза (известно, что любое целое число можно представить в виде суммы чисел Фибоначчи).

Числа Фибоначчи определяются следующим соотношением:

Ф0 = 0, Ф1 = 1, Фi = Фi-1 + Фi-2, i = 2, 3, 4, . . .   .

В дополнительных функциях доступ к элементам массивов реализовать с помощью указателей.

Исходную последовательность и полученную матрицу вывести в выходной поток с необходимыми комментариями.*/


#include <stdio.h>
#include <malloc.h>

void malloc_do(int*** fabpp,int* fib,int** chekp,int m,int p)
{   
     int r,k,i,b;
     int **fabp,*chek;

     chek=(int*)malloc((m+1)*sizeof(int));
     fabp=(int**)malloc((m+1)*sizeof(int*));
     for (i=0;i<=m;++i)
     {  
        printf("%d ",i);      
        r=0;
        b=i;    
        k=p;
        fabp[i]=(int*)malloc(8*sizeof(int));
        fabp[i][0]=i;
        while(b!=0)
        {
            if(b>=fib[k])
            {

                b=b-fib[k];
                r++;
                fabp[i][r]=fib[k];
                
               
            } 
            k--;
                
        }
        chek[i]=r+1;
        fabp[i]=(int*)realloc(fabp[i],(r+1)*sizeof(int));
        
        
     }
    *chekp=chek;
    *fabpp=fabp;
    printf("\n");
}



void fibo(int m,int** fibp,int* p)
{
    

    int i,k,s;
    int *fib;
    fib=(int*)calloc(2,sizeof(int));
    fib[0]=0;
    fib[1]=1;
    k=1;
    for(i=1;i<=m;++i)
    {   
        s=i;
        if(fib[k]+fib[k-1]<=s)
            while(fib[k]+fib[k-1]<=s)
            {   
                k++;
                fib=(int*)realloc(fib,(k+1)*sizeof(int));
                fib[k]=fib[k-1]+fib[k-2];
               

            }

    }
    *p=k;
    *fibp=fib;
}


void  getInt(int* a)
{
     int n=0;
     while (n==0)
    {
         n = scanf("%d", a);
         if (n==0 || *a<=0)
        {
            scanf("%*[^\n]");
            n=0;
        }
    }
}


int main()
{
    int k, i, m,*fib,p,**fab,*chek;
    getInt(&m);
    fibo(m,&fib,&p);    

    malloc_do(&fab,fib,&chek,m,p);
    for(i=0;i<=m;i++)
    {   
        for(k=0;k<=chek[i];k++)
        {
            printf("%d ",fab[i][k]);

        }
        printf("\n");
    }

    for (i=0;i<=m;i++)
    {
       free(fab[i]);
    }
    free(fab);
    free(chek);
    free(fib);
    return 0;
}




