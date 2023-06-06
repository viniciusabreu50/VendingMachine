#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct produto {
  string nome;
  float preco;
  int estoque;
};

int ApresentacaoVendingMachine(struct produto produtos[40]);

int ConfirmaCompra(struct produto produtos[40],int codigo);

float RecebeDinheiro(struct produto produtos[40], int codigo);

float FinalizaCompra(float dinheiro_cliente, int codigo, struct produto produtos[40]);

void ModoAdministrador(struct produto produtos[40], float faturamento_vendingmachine);
//codigo para entrar no modo administrador: 999
//senha: 753951

int main() { //codigo para "desligar" a vending machine e resetar os dados: 111
  struct produto produtos[40];
  int codigo, numero_digitado, finalizacao_programa;
  float dinheiro_cliente, faturamento_vendingmachine, possibilidade_faturamento, troco;

  faturamento_vendingmachine = 0;

  produtos[0].nome = "Batata Lays Classica 80g";
  produtos[0].preco = 7.00;
  produtos[0].estoque = 10;

  produtos[1].nome = "Batata Lays Creme de Cebola 135g";
  produtos[1].preco = 11.50;
  produtos[1].estoque = 10;

  produtos[2].nome = "Batata Lays Sal e Vinagre 80g";
  produtos[2].preco = 7.00;
  produtos[2].estoque = 10;

  produtos[3].nome = "Batata Lays Barbecue 80g";
  produtos[3].preco = 7.90;
  produtos[3].estoque = 10;

  produtos[4].nome = "Batata Lays Cream Cheese 68g";
  produtos[4].preco = 6.65;
  produtos[4].estoque = 10;

  produtos[5].nome = "Batata Lays Sal Marinho 68g";
  produtos[5].preco = 6.65;
  produtos[5].estoque = 10;

  produtos[6].nome = "Cheetos Patas de Cheedar 61g";
  produtos[6].preco = 4.80;
  produtos[6].estoque = 10;

  produtos[7].nome = "Cheetos Lua de Parmesao 40g";
  produtos[7].preco = 2.70;
  produtos[7].estoque = 10;

  produtos[8].nome = "Cheetos Onda de Requeijao 230g";
  produtos[8].preco = 12.00;
  produtos[8].estoque = 10;

  produtos[9].nome = "Cheetos Sortidos Mix de Queijos - 41g";
  produtos[9].preco = 3.00;
  produtos[9].estoque = 10;

  produtos[10].nome = "Cheetos Tubo de Queijo Cheedar 39g";
  produtos[10].preco = 3.20;
  produtos[10].estoque = 10;

  produtos[11].nome = "Fandangos Presunto 230g";
  produtos[11].preco = 12.00;
  produtos[11].estoque = 10;

  produtos[12].nome = "Fandangos Queijo 115g";
  produtos[12].preco = 12.50;
  produtos[12].estoque = 10;

  produtos[13].nome = "Stiksy 120g";
  produtos[13].preco = 5.90;
  produtos[13].estoque = 10;

  produtos[14].nome = "Doritos Queijo Nacho 140g";
  produtos[14].preco = 9.00;
  produtos[14].estoque = 10;

  produtos[15].nome = "Doritos Sweet Chili 140g";
  produtos[15].preco = 9.00;
  produtos[15].estoque = 10;

  produtos[16].nome = "Doritos Original 84g";
  produtos[16].preco = 6.00;
  produtos[16].estoque = 10;

  produtos[17].nome = "Cebolitos 110g";
  produtos[17].preco = 10.00;
  produtos[17].estoque = 10;

  produtos[18].nome = "Baconzitos 103g";
  produtos[18].preco = 9.80;
  produtos[18].estoque = 10;

  produtos[19].nome = "Coca-Cola lata 350ml";
  produtos[19].preco = 4.00;
  produtos[19].estoque = 10;

  produtos[20].nome = "Coca-Cola Zero lata 350ml";
  produtos[20].preco = 3.50;
  produtos[20].estoque = 10;

  produtos[21].nome = "Coca-Cola 600ml";
  produtos[21].preco = 5.50;
  produtos[21].estoque = 10;

  produtos[22].nome = "Pepsi lata 350ml";
  produtos[22].preco = 3.00;
  produtos[22].estoque = 10;

  produtos[23].nome = "Pepsi 600ml";
  produtos[23].preco = 4.20;
  produtos[23].estoque = 10;

  produtos[24].nome = "Guaraná Antartica lata 350ml";
  produtos[24].preco = 3.80;
  produtos[24].estoque = 10;

  produtos[25].nome = "Guaraná Antartica zero lata 350ml";
  produtos[25].preco = 3.30;
  produtos[25].estoque = 10;

  produtos[26].nome = "Guaraná Antartica 600ml";
  produtos[26].preco = 5.00;
  produtos[26].estoque = 10;

  produtos[27].nome = "Fanta Laranja lata 350ml";
  produtos[27].preco = 3.60;
  produtos[27].estoque = 10;

  produtos[28].nome = "Fanta Guaraná lata 350ml";
  produtos[28].preco = 3.60;
  produtos[28].estoque = 10;

  produtos[29].nome = "Fanta Uva lata 350ml";
  produtos[29].preco = 3.60;
  produtos[29].estoque = 10;

  produtos[30].nome = "Água Crystal sem gás 500ml";
  produtos[30].preco = 2.25;
  produtos[30].estoque = 10;

  produtos[31].nome = "Água Crystal com gás 500ml";
  produtos[31].preco = 2.80;
  produtos[31].estoque = 10;

  produtos[32].nome = "Água Prata sem gás 510ml";
  produtos[32].preco = 2.50;
  produtos[32].estoque = 10;

  produtos[33].nome = "Água Prata com gás 510ml";
  produtos[33].preco = 3.00;
  produtos[33].estoque = 10;

  produtos[34].nome = "Redbull Tradicional lata 250ml";
  produtos[34].preco = 7.00;
  produtos[34].estoque = 10;

  produtos[35].nome = "Monster Tradicional lata 269ml";
  produtos[35].preco = 6.00;
  produtos[35].estoque = 10;

  produtos[36].nome = "Kit Kat 45g";
  produtos[36].preco = 3.50;
  produtos[36].estoque = 10;

  produtos[37].nome = "Trento Tradicional 32g";
  produtos[37].preco = 2.00;
  produtos[37].estoque = 10;

  produtos[38].nome = "Trento Duo 32g";
  produtos[38].preco = 2.00;
  produtos[38].estoque = 10;

  produtos[39].nome = "Trento Avelã 32g";
  produtos[39].preco = 2.00;
  produtos[39].estoque = 10;

  codigo = 0;

  while(codigo != 12345){

    codigo = ApresentacaoVendingMachine(produtos);

    if(codigo == 111){
      cout << "Têm certeza que quer finalizar? Após a finalização os dados de estoque e faturamento serão perdidos. Digite 1 para confirmar ou 0 para cancelar: ";
      cin >> finalizacao_programa;

      if(finalizacao_programa == 1){
        break;
      }

      else{
        cout << endl << endl;
        continue;
      }
    }

    else if(codigo == 999){
      ModoAdministrador(produtos, faturamento_vendingmachine);
      continue;
    }

    if(produtos[codigo - 1].estoque == 0){
      cout << "O produto selecionado não está disponível no momento." << endl << endl;
    }

    else {
      numero_digitado = ConfirmaCompra(produtos, codigo);

      if(numero_digitado == 1){

        dinheiro_cliente = RecebeDinheiro(produtos, codigo);
        troco = FinalizaCompra(dinheiro_cliente, codigo, produtos);
        if(troco == 0){
          faturamento_vendingmachine += dinheiro_cliente;
        }

        else if(troco > 0){
          faturamento_vendingmachine += dinheiro_cliente - troco;
        }
      }

      else if(numero_digitado == 0){
        cout << "Compra cancelada." << endl << endl;
      }

      else{
        cout << "Dígito inválido." << endl << endl;
      }
    }
  }
  return 0;
}

int ApresentacaoVendingMachine(struct produto produtos[40]){
  int i, codigo;
  system("pause");
  cout << "Bem-Vindo! Para escolher um produto, basta pressionar o(s) número(s) do código referente ao produto desejado:" << endl;

  for(i = 0; i < 40; i++){
    cout << setprecision(2) << fixed;
    cout << i + 1 << " - " << produtos[i].nome << " - " << produtos[i].preco << endl;
  }

  cout << endl;

  cin >> codigo;

  return codigo;
}//Apresentação que está sempre disponível para que o usuário verifique todos os produtos e preços da vending machine

int ConfirmaCompra(struct produto produtos[40],int codigo){
  int numero;

  cout << endl << "Você selecionou o(a) " << produtos[codigo - 1].nome << ". O valor da compra é: R$" << produtos[codigo - 1].preco << "." << endl << "Se deseja finalizar a compra, digite o número 1 e se deseja cancelar sua compra, digite o número 0." << endl << endl;

  cin >> numero;

  return numero;
}

float RecebeDinheiro(struct produto produtos[40], int codigo){
  float dinheiro_cliente;

  cout << endl << "O valor final da sua compra é R$" << produtos[codigo - 1].preco << endl << "Insira o dinheiro no local indicado na máquina e em seguida, informe a quantia que foi inserida:" << endl << "R$";

  cin >> dinheiro_cliente;

  return dinheiro_cliente;
}

float FinalizaCompra(float dinheiro_cliente, int codigo, struct produto produtos[40]){
  float troco;

  troco = dinheiro_cliente - produtos[codigo - 1].preco;

  if (troco < 0){
    cout << "O valor inserido não é suficiente para realizar a compra." << endl << "Compra cancelada." << endl << endl;
    return -1;
  }

  else if (troco == 0){
    cout << "Sem troco, retire o produto no local indicado na máquina." << endl << endl;
    produtos[codigo - 1].estoque -= 1;
    return 0;
  }
  else {
    cout << "Seu troco é R$" << troco << endl << "Retire o produto junto com seu troco no local indicado na máquina" << endl << endl;
    produtos[codigo - 1].estoque -= 1;
    return troco;
  }
}

void ModoAdministrador(struct produto produtos[40], float faturamento_vendingmachine){
  int i, senha, opcao, codigo, qtd_reposicao, decisao_estoque;
  codigo = 99;
  opcao = 0;
  cout << "Informe a senha para prosseguir:";
  cin >> senha;
  cout << endl;

  if(senha == 753951){
    while(opcao != 4){

      cout << "Escolha a opção de gerenciamento desejada digitando o número correspondente à opção:" << endl << "1 - Lista contendo todos os produtos e a quantidade de estoque de cada produto." << endl << "2 - Realizar uma reposição de estoque." << endl << "3 - Consultar o faturamento atual e o faturamento possível." << endl << "4 - Sair do Modo Administrador." << endl;
      cin >> opcao;
      cout << endl;



      if(opcao == 1){
        for(i = 0; i < 40; i++){
          cout << i + 1 << " - " << produtos[i].nome << " - Estoque: " << produtos[i].estoque << endl;
        }
        cout << endl;
      }

      else if(opcao == 2){
        for(i = 0; i < 40; i++){
          cout << i + 1 << " - " << produtos[i].nome << " - Estoque: " << produtos[i].estoque << endl;
      }
        while(codigo != 0){
          cout << endl << "Digite o código do produto que deseja repôr: ";
          cin >> codigo;

          cout << "Você selecionou " << produtos[codigo - 1].nome << ". Informe a quantidade da reposição feita: ";
          cin >> qtd_reposicao;
          produtos[codigo - 1].estoque += qtd_reposicao;
          cout << "Reposição realizada com sucesso!" << endl << endl;

          cout << "Se deseja realizar a reposição de mais um produto digite qualquer número, se deseja encerrar a reposição de estoque digite 0: ";
          cin >> decisao_estoque;
          cout << endl;

          if(decisao_estoque == 0){
            cout << "Reposição de estoque encerrada." << endl << endl;
            break;
          }
        }
      }

      else if(opcao == 3){
        int i;
        float faturamento_possivel = 0;

        for(i = 0; i < 40; i++){
          faturamento_possivel += produtos[i].preco * produtos[i].estoque;
        }

        cout << "O faturamento atual da máquina: R$" << faturamento_vendingmachine << endl << "O faturamento possível a ser alcançado é: R$" << faturamento_possivel + faturamento_vendingmachine << endl << endl;
      }

      else if(opcao == 4){
        cout << "Saindo do Modo Administrador..." << endl << endl;
        break;
      }
    }
  }
  else{
    cout << "Senha Inválida." << endl << endl;
  }
}
