/* 
 * File:   annealing.h
 * Author: jaime
 *
 * Created on April 11, 2016, 7:08 PM
 */

#ifndef ANNEALING_H
#define	ANNEALING_H

#include "time.h"
#include <vector>
#include <cmath>

class Annealing{
public:
    
    int tamCromossomo;//tamanho de tabuleiro
    int qtMaxExecucoes;//quantidade maxima de execucao
    float temperaturaInicial, a;

    std::vector<int> cromossomo;
    std::vector<int> novoVizinho;
    std::vector<int> melhorSolucao;
    //vetor de aptidao para um dado cromossomo 
    std::vector<int> aptidao;

    //Construtor
    Annealing(int tamCromossomo, float temperaturaInicial,float a );
    Annealing();

    ~Annealing();
    

    
    //metodos
    int fitness(std::vector<int> cromossomo);//mesmo que a do genetico --->melhor vizinho
    void criarCromossomo();
    std::vector<int> criarVizinho(std::vector<int> cromossomo);
    std::vector<int> run();
    bool zeroColisao(std::vector<int> cromossomo);
    std::vector<int> getCromossomo();

};


//funcoes:
Annealing::~Annealing(){
    
}
//cronstrutor
Annealing::Annealing(int tamCromossomo,float temperaturaInicial,float a){
    srand(time(0));
    this->tamCromossomo = tamCromossomo;
    this->temperaturaInicial = temperaturaInicial;
    this->a = a;

    this->cromossomo.reserve(tamCromossomo);
    this->novoVizinho.reserve(tamCromossomo);
}
//debugacao
Annealing::Annealing(){
    this->tamCromossomo = 4;
    this->cromossomo.reserve(this->tamCromossomo);

}

//debugacao ok
std::vector<int> Annealing::criarVizinho(std::vector<int> cromossomo){
    this->cromossomo = cromossomo;
    int randomico, randomico2;
//    bool temNaLinha = true;
    randomico = rand() % (this->tamCromossomo);//gera um randomico de 0 ate o tamanho do cromossomo-1
    randomico2 = rand() % (this->tamCromossomo);
    //condocoes para quando numero for maior q o maximo
    while (randomico2 == this->cromossomo[randomico]){
//        for(int i=0; i<this->tamCromossomo; i++){
//            if(randomico2 == this->cromossomo[i])
//                randomico2 = rand() % (this->tamCromossomo - 1);
//        }
        randomico2 = rand() % (this->tamCromossomo - 1);
    }
    this->cromossomo[randomico] = randomico2;
//    else{
//        this->cromossomo[randomico] = 0;
//    }
    return this->cromossomo;    
}

//[0,1,2,3]
//[0,1,2,0]
//debugacao ok
std::vector<int> Annealing::getCromossomo(){
    return this->cromossomo;
}



std::vector<int> Annealing::run(){
    criarCromossomo();
    this->melhorSolucao = this->cromossomo;
    
    //float a = 0.95;
    //float temperaturaInicial = 100;
    double temperatura = this->temperaturaInicial;
    int t = 1;
    double prob;
    int dE;
    while((temperatura > pow(10,-10)) && (zeroColisao(this->melhorSolucao) == false)){
        temperatura = this->temperaturaInicial * pow(this->a,t);
        //std::cout<<temperatura<<std::endl;
        this->novoVizinho = criarVizinho(this->melhorSolucao);
    
    ///-------------            
        t = t + 1;
        dE = (fitness(this->melhorSolucao) - fitness(this->novoVizinho));
        for(int i =0; i <this->tamCromossomo;i++){
        //std::cout<<this->melhorSolucao[i]<<" ";
        }
        //std::cout<<std::endl;
        if ( fitness(this->novoVizinho) < fitness(this->melhorSolucao)){
            //std::cout<<"não alterado"<<std::endl;
            this->melhorSolucao = this->novoVizinho;
        }
        else {
            prob = exp(-dE/temperatura);
            if ( (rand()/(double)RAND_MAX) < prob){
                //std::cout<<"alterado"<<std::endl;
                this->melhorSolucao = this->novoVizinho;
            }
        }
    }
    //std::cout<<temperatura<<"  "<<zeroColisao(this->melhorSolucao)<<std::endl;
    for(int i =0; i <this->tamCromossomo;i++){
        //std::cout<<this->melhorSolucao[i]<<" ";
    }
    return this->melhorSolucao;
}



//checa se já há uma solução para o problema
//debugacao ok
bool Annealing::zeroColisao(std::vector<int> _cromossomo){
    int ColisoesTotal;
    ColisoesTotal = fitness(_cromossomo);
    if(ColisoesTotal == 0){
        return true;
    }
    else{
        return false;
    }
}



//cria um vetor de inteiros de tamanho n que vão representar a posição da rainha no tabuleiro
//debugacao ok
void Annealing::criarCromossomo(){
	this->cromossomo.clear();//limpar cromossomo caso já tenha valores
	this->cromossomo.reserve(this->tamCromossomo);//definir tamanho do cromossomo

	for(int i=0; i<this->tamCromossomo; i++){
		this->cromossomo.push_back(int(rand()%this->tamCromossomo));
		for(int j=0; j<i; j++){//verifica se a posição já foi escolhida
			if(this->cromossomo[i] == this->cromossomo[j])
				this->cromossomo[i] = int(rand()%this->tamCromossomo);
		}
	}
}


//calcula a quantidade de colisões do cromossomo na população[posicao]
//debugacao ok
int Annealing::fitness(std::vector<int> _cromossomo){//-->melhor vizinho
        this->cromossomo = _cromossomo;
	int numColisoes;
	numColisoes = 0;
	int distancia;
	for (int referencia = 0; referencia < this->tamCromossomo; ++referencia)
	{
		//checar linha
		for (int j = 0; j < this->tamCromossomo; ++j)
		{
			if(referencia != j)
			{
				//mesma linha
				if(this->cromossomo[referencia] == this->cromossomo[j]){ 
					numColisoes++;
				}
				//mesma diagonal
				distancia = abs(referencia-j);//distancia em colunas
				//se a linha de referência for igual a linha j+distância em colunas, 
				//quer dizer que está na mesma diagonal
				if(this->cromossomo[referencia] == this->cromossomo[j]+distancia
				   || this->cromossomo[referencia] == this->cromossomo[j]-distancia){
					numColisoes++;
				}
			}
		}
	}
	return numColisoes;//para o cromossomo
}


#endif	/* ANNEALING_H */

