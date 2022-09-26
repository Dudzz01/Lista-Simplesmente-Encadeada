#include <stdio.h>
void inserirInicio(int dado);
void imprimir(int lista);
void busca(int lista, int dado);
void quebra(int dado);
void excluirLista(int lista);
void removerElemento(int lista, int dado);


typedef struct No{
    int dado;
    No *proximo;
}No;

No *inicio1 = nullptr;
No *inicio2 = nullptr;

void inserirInicio(int dado){
    No *novo = new No();
    novo->dado = dado;
    novo->proximo = inicio1;
    inicio1 = novo;
}

void imprimir(int lista){
    switch (lista) {
        case 1:
            if (inicio1 != nullptr) {
                No *aux;
                for (aux = inicio1; aux != nullptr; aux = aux->proximo) {
                    printf("Num end: %p || Numero do dado da estrutura: %d\n", aux, aux->dado);
                }
            }else {
                printf("Lista vazia\n");
            }
            break;
        case 2:
            if (inicio2 != nullptr) {
                No *aux;
                for (aux = inicio2; aux != nullptr; aux = aux->proximo) {
                    printf("Num end: %p || Numero do dado da estrutura: %d\n", aux, aux->dado);
                }
            } else {
                printf("Lista vazia\n");
            }
            break;

        default:
            printf("Lista nao encontrada");
            break;
    }





}

void busca(int lista, int dado){
    switch(lista){
        case 1:
            No *aux;
            for(aux = inicio1; aux!= nullptr; aux = aux->proximo ){
                 if(aux->dado == dado){
                     printf("O dado %d foi encontrado na lista %d com o endereco %p",aux->dado,lista,aux);
                     return;
                 }

            }
            printf("O dado nao foi encontrado na lista %d",lista);
            break;
        case 2:
            No *auxx;
            for(auxx = inicio2; auxx!= nullptr; auxx = auxx->proximo ){
                if(auxx->dado == dado){
                    printf("O dado %d foi encontrado na lista %d com o endereco %p",auxx->dado,lista,auxx);
                    return;
                }

            }
            printf("O dado nao foi encontrado na lista %d",lista);
            break;

        default:
            printf("Lista nao encontrada");

            break;
    }
}

No * buscaQuebra(int dado){

    No *aux = inicio1;
    No *anterior = inicio1;
    while(aux!= nullptr) {

        if (aux->dado == dado) {
            return anterior;
        }

        anterior = aux;
        aux = aux->proximo;
    }
    return nullptr;


}

void quebra(int dado){
    No *aux = buscaQuebra(dado);

    if(aux == nullptr){
        printf("Numero nao encontrado");
        return;
    }

    if(inicio2 != nullptr){
        printf("Lista ja quebrada");
        return;
    }

      if(inicio1!= nullptr) {

          if (dado != inicio1->dado) {
              inicio2 = aux->proximo;
              aux->proximo = nullptr;


          } else {
              inicio2 = nullptr;
              inicio1 = aux;
          }

      }




}

void excluirLista(int lista){
   No *aux;
   int cont = 0;
   if(lista == 1) {
       while (inicio1 != nullptr) {
             aux = inicio1;
             inicio1 = inicio1->proximo;
             delete(aux);
             cont++;
           printf("Numero de elementos deletados: %d\n", cont);
       }
   }

}

void removerElemento(int lista, int dado){
    if(lista == 1 && inicio1!= nullptr){
        No *aux;

        for(aux = inicio1; aux!=nullptr; aux = aux->proximo){
            if(dado == aux->dado){

                delete(aux);
                return;
            }
        }

    }
    else if(lista == 2 && inicio2!= nullptr){
        No *aux;
        for(aux = inicio2; aux!= nullptr; aux = aux->proximo){
            if(dado == aux->dado){
                delete(aux);
                return;
            }
        }
    }
    else{
        printf("Lista nao encontrada e/ou dado nao encontrado");
    }
}

int main() {

    int vet_par[] = {2,4,6,8,10};
    int vet_impar[] = {1,3,5,7,9};
    int j = 4;
    for(int i = 0; i<10; i++){
        if((i+1)%2 == 0){
            inserirInicio(vet_impar[j]);
            j--;
        }
        else{
            inserirInicio(vet_par[j]);

        }
    }

    imprimir(1);
    excluirLista(1);
    imprimir(1);
    //busca(1,7);
  //  quebra(7);
    //printf("Lista 2\n");
    //imprimir(2);
   // printf("Lista 1\n");
   // imprimir(1);
   // removerElemento(1,6);
//    printf("Lista apos remover elemento\n ");
   // imprimir(1);
    /*excluirLista(2);
    printf("Lista 2 apos ser excluida\n");
    imprimir(2);
    excluirLista(1);
    printf("Lista 1 apos ser excluida\n");
    imprimir(1);*/
    return 0;
}
