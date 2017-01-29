/* 
 * File:   main.cpp
 * Author: jaime
 *
 * Created on April 11, 2016, 7:06 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include "genetico.h"
#include "annealing.h"
using namespace std;

int main(int argc, char* argv[]){
        
    vector<int> cromossomo;
        //---------------------------Genetico

        /*
	if(argc != 6 ){
		cout << "Comandos para rodar: ./a.out tamCromossomo tamPop probMutacao probCrossover qtMaxGeracoes"<<endl;
		exit(0);
	}
	int tamCromossomo = atoi(argv[1]);
	int tamPop = atoi(argv[2]);
	float probMutacao = atof(argv[3]);
	float probCrossover = atof(argv[4]);
	int qtMaxGeracoes = atoi(argv[5]);
        
	Genetico * g = new Genetico(tamCromossomo, tamPop, probMutacao, probCrossover, qtMaxGeracoes);
	g->run();
         delete g;
        
    
        
        
        //-----------------------Annealing
        
        
        
        if(argc != 6 ){
		cout << "Comandos para rodar: ./a.out tamCromossomo tamPop probMutacao probCrossover qtMaxGeracoes"<<endl;
		exit(0);
	}
	int tamCromossomo = atoi(argv[1]);
	float temperturaInicial = atoi(argv[3]);
	float _a = atof(argv[4]);

        Annealing * a = new Annealing(tamCromossomo, temperturaInicial, _a);
        a->run();
       
    
        //delete a;//nao pode deletar, da bug no netbeans. 
    
        
        */
        
        //-------DEBUGACAO
    float media = 0;
    int k;
    
    
    
    
    
    
    
    
    
    int amostra=100; 
    
int tamCromossomo = 10;
int tamPop =15;
float probMutacao = 0.0001;
float probCrossover = 0.7;
int qtMaxGeracoes = 50000;
    
    
    
    
    //Annealing * a = new Annealing(tamanho, temperatura, resfriamento);
    Genetico * g = new Genetico(tamCromossomo, tamPop, probMutacao, probCrossover, qtMaxGeracoes);
    int teste;
    for (int i=0; i<amostra; i++){
        teste = g->run();
        //cout<<endl;
        k = g->fitness(teste);
        media+=k;
    }
        
        cout<<"\nColisoes: "<<(int)media/amostra<<endl;
            //delete a;
        delete g;
        
        /*
        cout<<"\n------>criou a";

        a->criarCromossomo();
        cout<<"\n------>criou Cromossomo";




        //cromossomo[0] = 0;
        //cromossomo[1] = 1;
        //cromossomo[2] = 2;
        //cromossomo[3] = 3;
        //a->criarCromossomo();
        cromossomo = a->getCromossomo();
        vizinho = a->criarVizinho(cromossomo);
        cout<<"\n------>Pegou o cromossomo\n";
        cout<<"-----Cromossomo ";
        for(int i=0;i<4;i++){
            cout<<cromossomo[i]<<" ";
        }
        //cromossomo = a->criarVizinho(cromossomo);
        cout<<"\n------criou vizinho: ";
        for(int i=0;i<4;i++){
            cout<<vizinho[i]<<" ";
        }
        int gol;
        gol = a->fitness(cromossomo);
        cout<<"\n------teste de fitness: ";
        cout<<gol<<endl;
        cout<<"------teste de zero colisoes: ";
        cout<<a->zeroColisao(cromossomo);
        a->run();
        */
        //delete g;
        //delete a;
	return 0;
}

