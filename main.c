#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arvore.c"




int main(void){
    node* root = NULL;
    clock_t tempo;
    int u = 0, d,n=100,i,y,x,k=0;
    double vec_in[4],vec_re[4],vec_bus[4];
    printf("Crescente\n");
    while(n < 1000000){
        int vector[n];
    	tempo = clock();
        for(int i=0;i<n;i++){
            x = i;
            y = i;
           root = insert(root, x, y);
        }
        vec_in[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        tempo = clock();
        for(int i=0;i<(n/2);i++){
            k = i;
            root = remove_item(root, k);
        }
        vec_re[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=(n/2);i<n;i++){
            k = i;
            node* s = search(root, k);
        }
        for(int i=(n/2);i<n;i++){
            k= i+n;
            node* s = search(root, k);
        }
        vec_bus[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        u++;
        n = n *10;
    }
    n = 100;
    u = 0;
    for(int i=0;i<4;i++){
        printf("%d\n",n);
        printf("inser %lf\n",vec_in[i]);
        printf("Remo  %lf\n",vec_re[i]);
        printf("Busca %lf\n",vec_bus[i]);
        printf("\n\n");
        n=n*10;
    }
     printf("Aleatorio\n");
    while(n < 1000000){
        int vector[n];
    	tempo = clock();
        for(int i=0;i<n;i++){
            vector[i] = i + (rand()%n);
            x = vector[i];
            y = vector[i];
            root = insert(root, x, y);
        }
        vec_in[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        tempo = clock();
        for(int i=0;i<(n/2);i++){
            k = i;
            root = remove_item(root, k);
        }
        vec_re[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=(n/2);i<n;i++){
            k = i;
            node* s = search(root, k);
        }
        for(int i=(n/2);i<n;i++){
            k = vector[i]+n;
            node* s = search(root, k);
        }
        vec_bus[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        u++;
        n = n *10;
    }
    n = 100;
    u = 0;
    for(int i=0;i<4;i++){
        printf("%d\n",n);
        printf("inser %lf\n",vec_in[i]);
        printf("Remo  %lf\n",vec_re[i]);
        printf("Busca %lf\n",vec_bus[i]);
        printf("\n\n");
        n=n*10;
    }
    printf("Decrescente\n");
      while(n < 1000000){
        int vector[n];
    	tempo = clock();
        for(int i=n;i<=0;i--){
            vector[i] = i + (rand()%50);
            x = i;
            y = i;
            root = insert(root, x, y);
        }
        vec_in[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        tempo = clock();
        for(int i=n;i<=(n/2);i--){
            k = i;
            root = remove_item(root, k);
        }
        vec_re[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=(n/2);i<=0;i--){
            k = vector[i];
            node* s = search(root, k);
        }
         for(int i=(n/2);i<=0;i--){
            k = vector[i]+n;
            node* s = search(root, k);
        }
        vec_bus[u] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        u++;
        n = n *10;
    }
    n =100;
    for(int i=0;i<4;i++){
        printf("%d\n",n);
        printf("inser %lf\n",vec_in[i]);
        printf("Remo  %lf\n",vec_re[i]);
        printf("Busca %lf\n",vec_bus[i]);
        printf("\n\n");
        n=n*10;
    }

    free_tree(root);

    return 0;
}
