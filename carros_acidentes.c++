//Percebemos o quão importante é você estar ciente de como é o funcionamento dos comandos em lógica de programação. Cada comando possui um propósito e 
//com ele podemos perceber qual é o melhor comando para realizar determinada atividade. Neste sentido, analisemos o caso problematizador abaixo:
//O IBGE (Instituto Brasileiro de Geografia e Estatística) desejou realizar uma estatística nas cidades pertencentes ao estado do Paraná,
//verificando dados sobre acidentes de trânsito. Neste estudo, precisava-se obter alguns dados, que podemos verificar abaixo:

//código da cidade;
//número de veículos de passeio;
//número de acidentes de trânsito com vítimas.

//Desejava-se saber ainda:

//qual o maior e o menor índice de acidentes de trânsito e a que cidades pertencem;
//qual a média de veículos nas cidades juntas;
//qual a média de acidentes de trânsito nas cidades com menos de 2000 veículos de passeio.
//Analisando, assim, o nosso caso problematizador, você, aluno(a), deverá realizar um algoritmo que resolva este problema.
//Utilize-se de todos os conceitos aprendidos até o presente momento. Bom trabalho.


#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Write C++ code here

    string mun_Cod_Nome[399][1], maior_Cod_Nome, menor_Cod_Nome, novoCadastro;
    int mun_Car_Acid[399][3], i, j, soma_Veiculos, mun_Cadastrados, mun_Menos2000, soma_Acid_2000, maior_Car_Acid, menor_Car_Acid;
    soma_Veiculos = 0;
    mun_Cadastrados = 0;
    soma_Acid_2000 = 0;
    mun_Menos2000 = 0;
    float media_Veiculos, media_Acid_2000;
    
    i = 0;//contador variável para o índice de linha

//trecho de código para cadastrar informações de identificação do município, dados de veículos e acidentes, seguido de calculo de media de veículos;
//o trecho de código será repetido enquanto o usuário indicar que deseja realizar novo cadastro (do-while)    
    do {        
        j=0; //contador variável para o índice de coluna
    //trecho de código para armazenar código do município na matriz inteiro[i][0]
        std::cout << "\nInforme o CODIGO do Municipio: ";
        std::cin >> mun_Car_Acid[i][j];

    //trecho de código para armazenar nome do município na matriz string[i][0]
        std::cout << "Informe o NOME do Municipio: ";
        std::cin >> mun_Cod_Nome[i][j];

        j++;
        
    //trecho de código para armazenar número de veículos na matriz inteiro[i][1]
        std::cout << "Informe o NUMERO DE VEICULOS DE PASSEIO do Municipio: ";
        std::cin >> mun_Car_Acid[i][j];
        soma_Veiculos = soma_Veiculos + mun_Car_Acid[i][j];

        j++;
    
    //trecho de código para armazenar número de acidentes na matriz inteiro[i][2]
        std::cout << "Informe o NUMERO DE ACIDENTES COM VITIMA do Municipio: ";
        std::cin >> mun_Car_Acid[i][j];
        
        i++;
        std::cout << "\nDados cadastrados com sucesso.\n";
    
    //trecho de código para calcular a media de veículos       
        mun_Cadastrados = mun_Cadastrados + 1;
        std::cout << "Numero de municipios cadastrados: " << mun_Cadastrados  << "\n";
        media_Veiculos = soma_Veiculos / mun_Cadastrados;
        std::cout << "Numero total de VEICULOS DE PASSEIO cadastrados ate o momento: " << soma_Veiculos << " (uma media de " << media_Veiculos << " veiculos/municipio.)\n";
        
        std::cout << "\nDeseja cadastrar os dados de outro municipio? Digite S para sim e N para nao: ";
        std::cin >> novoCadastro;
        
    } while (novoCadastro == "s" && i <= 399);

//trecho de código para calcular média de acidentes com vítima considerando dados apenas dos municípios com menos de 2000 veículos
    for(i == 0; i == mun_Cadastrados; i++){
        j = 1;
        if(mun_Car_Acid[i][j] < 2000){
            mun_Menos2000 = mun_Menos2000 + 1;
            soma_Acid_2000 = soma_Acid_2000 + mun_Car_Acid[i][2];
        }
    }
    media_Acid_2000 = soma_Acid_2000 / mun_Menos2000;
    std::cout << "Media de ACIDENTES DE TRANSITO COM VITIMA nos municipios com MENOS DE 2000 VEICULOS de passeio: " << media_Acid_2000 << "/municipio.\n";   

//trecho de código para descobrir o registro com o maior número de acidentes e o respectivo município
    maior_Car_Acid = 0;
    for(i == 0; i == mun_Cadastrados; i++){
        if(mun_Car_Acid[i][2] > maior_Car_Acid){
            maior_Car_Acid = mun_Car_Acid[i][2];
            maior_Cod_Nome = mun_Car_Acid[i][0];
        }
    }
    
    std::cout << "Municipio com maior registro de ACIDENTES COM VITIMA: " << maior_Cod_Nome << ", com um registro de " << maior_Car_Acid << " acidentes.\n";

//trecho de código para descobrir o registro do menor número de acidentes e o respectivo município:    
    for(i == 0; i == mun_Cadastrados; i++){
        menor_Car_Acid = maior_Car_Acid;        
        if(mun_Car_Acid[i][2] < menor_Car_Acid){
          menor_Car_Acid = mun_Car_Acid[i][2];
          menor_Cod_Nome = mun_Cod_Nome[i][0];  
        }
    }     
    std::cout << "Municipio com menor registro de ACIDENTES COM VITIMA: " << menor_Cod_Nome << ", com um registro de " << menor_Car_Acid << " acidentes.\n";
    std::cout << "\nAlgoritmo Finalizado";

return 0;
}

