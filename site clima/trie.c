#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//criação do tipo ASCII
typedef struct ASCIITrie{
	int val;
	int ESTADO;
	struct ASCIITrie* filhos[256];
}ASCIITrie;

//Setar Nós
ASCIITrie* Criar(){
	ASCIITrie *noh;
	int i;
	noh = malloc(sizeof(ASCIITrie));
	noh->ESTADO = 0;
	noh->val = 0;
	
	for(i = 0; i < 256; i++){
		noh->filhos[i] = NULL;
	}
	
	return noh;
}

//Busca de palavras
ASCIITrie* Buscar_R(ASCIITrie* T, unsigned char *chave, int tm,int p){

	if(T == NULL){
		return NULL;
	}
	
	if(p == tm){
		return T;
	}

    return	Buscar_R(T->filhos[chave[p]],chave,tm,p+1);
}

ASCIITrie* Buscar(ASCIITrie* T, unsigned char *chave){

	return Buscar_R(T,chave,strlen(chave),0);
}

//Inserção das palavras
void Inserir_R(ASCIITrie **T,unsigned char *chave, int val, int tm,int p){

	if(*T == NULL){
		(*T) = Criar();
	}
	if(p == tm){
		(*T)->val= val;
		(*T)->ESTADO = 1;
		return;
	}

	 Inserir_R(&(*T)->filhos[chave[p]], chave, val, tm, p+1);
}

void Inserir(ASCIITrie **T, unsigned char *chave, int val){

	 Inserir_R(T, chave, val, strlen(chave), 0);
}


int main(){
	ASCIITrie *arv = NULL;
	//arv->
	
	Inserir(&arv,"Rato",4);
	printf("Aqui");
	printf("%s",Buscar(arv,"Rato"));
	
	return 0;
}