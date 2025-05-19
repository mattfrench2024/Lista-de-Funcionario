#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <numeric>

struct Funcionario {
    int prontuario;
    std::string nome;
    double salario;

    void exibir() const {
        std::cout << "Prontuario: " << prontuario
                  << ", Nome: " << nome
                  << ", Salario: " << std::fixed << std::setprecision(2) << salario;
    }
};

class AdministradorFuncionarios {
private:
    std::vector<Funcionario> funcionarios;

public:
    void incluirFuncionario() {
        std::cout << "\nIncluir Novo Funcionario\n";
        int prontuario;
        std::cout << "Prontuario: ";
        std::cin >> prontuario;
        if (std::cin.fail()) {
            std::cout << "Prontuario inválido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (const auto& func : funcionarios) {
            if (func.prontuario == prontuario) {
                std::cout << "Prontuario já existente.\n";
                return;
            }
        }

        std::string nome;
        std::cout << "Nome: ";
        std::getline(std::cin, nome);

        double salario;
        std::cout << "Salario: ";
        std::cin >> salario;
        if (std::cin.fail()) {
            std::cout << "Salario inválido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        funcionarios.push_back({prontuario, nome, salario});
        std::cout << "Funcionario incluido com sucesso.\n";
    }

    void excluirFuncionario() {
        std::cout << "\nExcluir Funcionario\n";
        int prontuario;
        std::cout << "Informe o prontuario do funcionario a ser excluido: ";
        std::cin >> prontuario;
        if (std::cin.fail()) {
            std::cout << "Prontuario inválido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
            if (it->prontuario == prontuario) {
                funcionarios.erase(it);
                std::cout << "Funcionario excluido com sucesso.\n";
                return;
            }
        }
        std::cout << "Funcionario não encontrado.\n";
    }

    void pesquisarFuncionario() {
        std::cout << "\nPesquisar Funcionario\n";
        int prontuario;
        std::cout << "Informe o prontuario do funcionario a ser pesquisado: ";
        std::cin >> prontuario;
        if (std::cin.fail()) {
            std::cout << "Prontuario inválido.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (const auto& func : funcionarios) {
            if (func.prontuario == prontuario) {
                func.exibir();
                std::cout << "\n";
                return;
            }
        }
        std::cout << "Funcionario não encontrado.\n";
    }

    void listarFuncionarios() const {
        std::cout << "\nLista de Funcionarios\n";
        if (funcionarios.empty()) {
            std::cout << "Nenhum funcionario cadastrado.\n";
            return;
        }

        double totalSalarios = 0.0;
        for (const auto& func : funcionarios) {
            func.exibir();
            std::cout << "\n";
            totalSalarios += func.salario;
        }
        std::cout << "\nTotal de Salarios: " << std::fixed << std::setprecision(2) << totalSalarios << "\n";
    }
};

int main() {
    AdministradorFuncionarios administrador;
    int opcao;

    do {
        std::cout << "\nMenu de Opções:\n";
        std::cout << "0. Sair\n";
        std::cout << "1. Incluir\n";
        std::cout << "2. Excluir\n";
        std::cout << "3. Pesquisar\n";
        std::cout << "4. Listar\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cout << "Opção inválida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcao = -1;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                administrador.incluirFuncionario();
                break;
            case 2:
                administrador.excluirFuncionario();
                break;
            case 3:
                administrador.pesquisarFuncionario();
                break;
            case 4:
                administrador.listarFuncionarios();
                break;
            case 0:
                std::cout << "Saindo do programa.\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
