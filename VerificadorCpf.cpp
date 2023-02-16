// Bibliotecas :
#include <cctype>
#include <iostream>
#include <string>
using std::string, std::cin, std::cout;

// Variáveis:
string cpf;

// Funções:
bool verificacao() { // Verificar os dígitos do cpf e validá-los
  int x = 9, y = 10;

  for (int a = 0; a < 2; a++) {
    int soma_validacao = 0;

    for (int i = 0; i < x; i++) {
      int num = cpf[i] - '0';
      soma_validacao += (num * (y - i));
    }
    int resto = (soma_validacao * 10) % 11;

    if (resto == 10) {
      resto = 0;
    }

    if (resto != (cpf[x] - '0')) {
      return false;
    }

    x += 1;
    y += 1;
  }
  return true;
}

void validaCpf() {
  bool digitoDiferente = false;
  bool haLetra = false;

  for (int i = 1; i < (cpf.size()); i++) {
    if (!isdigit(cpf[i])) { // verifica se há apenas numeros entre os caracteres
      haLetra = true;
    }

    if ((cpf[i - 1] - '0') !=
        (cpf[i] - '0')) { // Verifica se todos os caracteres do cpf são iguais
      digitoDiferente = true;
    }
  }

  cout << "CPF: " << cpf << " (";

  if (haLetra) {
    cout << "Inválido - Não deve haver letras ou caracteres especiais no cpf)"
         << std::endl;

  } else {
    if (cpf.size() < 11) {
      cout << "Inválido - Caracteres insuficientes)" << std::endl;

    } else if (cpf.size() > 11) {
      cout << "Inválido - Número de caracteres excedido)" << std::endl;

    } else {
      if (digitoDiferente) {
        if (verificacao()) {
          cout << "Válido)" << std::endl;

        } else {
          cout << "Inválido)" << std::endl;
        }

      } else {
        cout << "Inválido - Cpf não pode possuir apenas caracteres iguais)"
             << std::endl;
      }
    }
  }
}

// Main
int main() {
  std::cout << "Digite O Cpf:" << std::endl;
  std::cin >> cpf;
  validaCpf();
}