#include <stdio.h>

int main(void) {
  int usuario = 50000;
  int sel, valor;
  printf("1 - Saque \n");
  printf("2 - Deposito \n");
  printf("3 - Extrato \n");

  scanf("%d", &sel);

  switch(sel){
    case 1:
    printf("Digite o valor do saque: \n");
    scanf("%d", &valor);
      
    if (valor > usuario) {
      printf("Saldo insuficiente");
    } else {
      usuario = usuario - valor;
      printf("Saque efetuado com sucesso");
    } 
    break;
    case 2:
    printf("Digite o valor do deposito: \n");
    scanf("%d", &valor);
    if (valor > 0){
      usuario = usuario + valor;
      printf("Deposito efetuado com sucesso");
    }
    else{
      printf("Valor invalido");
    }
    break;

    case 3:
    printf("Seu saldo atual eh: %d", usuario);
    break;

    default:
    printf("Opção inválida");
    
  }
  return 0;
}
