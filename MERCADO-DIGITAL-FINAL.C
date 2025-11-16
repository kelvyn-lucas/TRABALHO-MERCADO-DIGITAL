/******************************************************************************
questoes para organizar o programa

A) Na estrutura CLIENTES
i. clientes.codigo = é formado pelos 6 primeiros dígitos do CPF do cliente.
ii. clientes.tel = é uma estrutura TELEFONES que possui fixo e celular como campos.



B) Na estrutura TELEFONES
i. Os campos fixo e móvel são strings a fim de guardar, além do número, a máscara do telefone
como no exemplo: (11) 3210-1000int codigo int codigo clientes cliente



C) Na estrutura PRODUTOS
i. produtos.codigo = é formado pelo valor inteiro dos 2 primeiros caracteres da marca do produto
e 2 caracteres do modelo do produto (tabela ASCII). Após isso aplicar a fórmula
hash=C1×313+C2×312+C3×311+C4×310 onde C1, C2, C3 e C4 são os valores numéricos
inteiros dos caracteres. Por exemplo: Marca: DELL Modelo: PRECISION iremos usar “DEPR”.
Sabendo que os valores inteiros das letras são: D → 68; E → 69; P → 80; R → 82 aplicamos
na formula hash= 68×313+69×312+80×311+82×310 que resulta hash= 2093659. O código será
então 2093659.
ii. produtos.modelo = é uma estrutura MODELOS que possui marca e modelo como campos.



D) Na estrutura CARRINHOS
i. carrinhos.cliente = é uma estrutura CLIENTES que guarda os dados do cliente para quem a
venda está sendo feita
ii. carrinhos.produto[3] = é um VETOR de estruturas PRODUTOS que permite guardar ao menos
3 dados de produtos que estão sendo vendidos.
iii. carrinhos.quantidade[3] = é um VETOR de inteiros que irá guardar a quantidade de cada item
adicionado ao carrinho. Há uma relação onde: carrinhos.quantidade[0] possui a quantidade de
produtos referente ao carrinhos.produto[0], carrinhos.quantidade[1] possui a quantidade de
produtos referente ao carrinhos.produto[1] e assim por diante.
iv. carrinhos.subtotal = guarda a soma de todos os valores da venda. Lembrando que é a soma de
qnt *valor produto.
v. carrinhos.desconto = guarda o valor do desconto (exemplo 10 para 10%). Também pode ser
modificado para validar um cupom de desconto caso a equipe queira fazer algo diferenciado.
vi. carrinhos.total = guarda o valor total da compra subtraído o valor do campo desconto. Por
exemplo, se R$ 1.000,00 é o subtotal da compra e o desconto é de 10%, o valor deste campo
total é de R$ 900,00





o programa ira rodar em um laço de repetiçao que se o usuario recebe um menu inicial onde ele podera escolher oque deseja operar
e se ele selecionar 0 o programa fecha
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>



/*structs do codigo*/


//Nota: a questão C fala como deve ser formado a função dos Produtos e como ela deve se comportar

//Nota: a questão D fala como deve ser formado a função dos Carrinhos e como ela deve se comportar

//Nota: alternativa 3 ja foi resolvida

//Nota: a questão 5 e uma sugestão para validação para o correto funcionamento do codigo

 typedef struct telefones{
     char fixo[15];
     char celular[16];
 }telefones;
 
 typedef struct clientes{
     int codigo;
     char nome[50];
     double cpf;
     char sexo[10];
     struct telefones tel;
 }clientes;

 typedef struct modelos{
     char marca[20];
     char modelo [20];
 }modelos;
 
 typedef struct produtos{
     int codigo;
     char nome [20];
     double valor;
     struct modelos modelo;
 }produtos;

 typedef struct carrinhos{
     struct clientes cliente;
     struct produtos produto[3];
     int quantidade[3];
     double subtotal;
     double desconto;
     double total;
 }carrinhos;
 
 //Nota: cont 0 e referente a quantas vezes foi rodado o processo de cadastro de clientes
 //Nota: cont 1 e referente a quantas vezes foi rodado o processo de cadastro de produtos
 //Nota: cont 2 e referente a quantas vezes foi rodado o processo de listagem de clientes
 //Nota: cont 3 e referente a quantas vezes foi rodado o processo de listagem de produtos
 //Nota: cont 4 e referente a quantas vezes foi rodado o processo de efetuação de venda simples
 


 
 void ola(void);
 void mostraMenuInicial(void);
 int geraCodigoCliente(double cpf);
 void listarClientes(clientes c1[], int confirm);
 void ListarProdutos(produtos p1[], int confirm);
 int GeraCodigoProduto(produtos p1[], int cont1);
 
 struct clientes localizaCliente(int codigo, struct clientes cliente[3], int numClientes);
 struct produtos localizaProduto(int codigo, struct produtos produto[10], int numProdutos);
 double calculaSubtotal(struct carrinhos *carrinho);
 double calculaTotal(double subtotal, double desconto);
 void listarCarrinho(struct carrinhos *carrinho);
 void finalizarVenda(struct carrinhos *carrinho);
 void efetuarVenda(struct clientes cliente[3], int numClientes, struct produtos produto[10], int numProdutos, struct carrinhos *carrinho);


 
 
 
 
 
  void ola(void)
 {
     printf("Seja Bem vindo\n");
 }
 
 void mostraMenuInicial(){
     printf("Qual dessas opções voce deseja realizar ? ");
     printf("\n 1 - Cadastrar clientes \n 2 - Cadastrar produtos  \n 3 - Listar clientes cadastrados \n 4 - Listar produtos cadastrados \n 5 - Efetuar uma venda \n 0 - Sair do programa \n");

 }
 

 int geraCodigoCliente(double cpf){
     
         
         int codigo; 
         int verif;

         verif = cpf/10000000000;
         
         
         
         if(verif<=0){
         codigo = cpf/10000;
         }
         else{
             codigo = cpf/100000;
         }
         
         return codigo ;
     
 }
 
 void listarClientes(clientes c1[], int confirm ){
    
    int cont;
    
     if (confirm == 0){
         
         printf("Nenhum cliente cadastrado ainda!\n");
         
         return;
     }else{

     for( cont = 0; cont < confirm; cont++){
       
         
         printf("\n--------- Cliente %d ---------\n", cont + 1);
         printf("Nome: %s\n", c1[cont].nome);
          printf("CPF: "); 
         if(c1[cont].cpf<10000000000){
         printf("0");}
         printf("%.0lf\n", c1[cont].cpf);
         printf("Sexo: %s\n", c1[cont].sexo);
         printf("Código: %d\n", c1[cont].codigo);
         printf("Telefone fixo: %s\n", c1[cont].tel.fixo);
         printf("Telefone móvel: %s\n", c1[cont].tel.celular);
     }
     }
     
 }
 
  void ListarProdutos(produtos p1[], int confirm){
 
  int cont;
       if(confirm==0){
             printf("Nenhum produto cadastrado ainda!\n");
       }else{
     
     
     for( cont = 0; cont < confirm; cont++){
         printf("\n---------- Produto %d ----------\n", cont + 1);
         printf("Produto: %s\n", p1[cont].nome);
         printf("Modelo: %s\n", p1[cont].modelo.modelo);
         printf("Marca: %s\n", p1[cont].modelo.marca);  
         printf("Codigo: %d\n", p1[cont].codigo);
         printf("Valor: R$ %.2lf\n", p1[cont].valor);
     }
 }
     
  }
 
 
 int GeraCodigoProduto(produtos p1[], int cont1) {
     int C1=p1[cont1].modelo.marca[0];
     int C2=p1[cont1].modelo.marca[1];
     int C3=p1[cont1].modelo.modelo[0];
     int C4=p1[cont1].modelo.modelo[1];
     int codigo;
       
     codigo = (C1*31*31*31)+(C2*31*31)+(C3*31)+(C4*1);
     return codigo;
 } 
 
 
 
 struct clientes localizaCliente(int codigo, struct clientes cliente[3], int numClientes) {
     int i;
     for (i = 0; i < numClientes; i++) {
         if (cliente[i].codigo == codigo) {
             return cliente[i]; 
         }
     }
    
     struct clientes clienteVazio = {0}; 
     return clienteVazio;
 }
 
 struct produtos localizaProduto(int codigo, struct produtos produto[10], int numProdutos) {
     int i;
     for (i = 0; i < numProdutos; i++) {
         if (produto[i].codigo == codigo) {
             return produto[i]; 
         }
     }
     struct produtos produtoVazio = {0}; 
     return produtoVazio;
 }
 
 double calculaSubtotal(struct carrinhos *carrinho) {
     double subtotal = 0.0;
     int i;
     for (i = 0; i < 3; i++) {
         subtotal += (*carrinho).produto[i].valor * (*carrinho).quantidade[i];
     }
     return subtotal;
 }
 
 double calculaTotal(double subtotal, double desconto) {
     if (desconto < 0.0) desconto = 0.0;     
     if (desconto > 100.0) desconto = 100.0; 
     
     double valorDesconto = subtotal * (desconto / 100.0);
     return subtotal - valorDesconto;
 }
 
 void listarCarrinho(struct carrinhos *carrinho) {
     printf("\n--- Itens no Carrinho ---\n");
     printf("Cliente: %s (Cód: %d)\n", (*carrinho).cliente.nome, (*carrinho).cliente.codigo);
     printf("----------------------------------------\n");
 
     int i;
     int carrinhoVazio = 1; 
     
     for (i = 0; i < 3; i++) {
         if ((*carrinho).quantidade[i] > 0) {
             carrinhoVazio = 0; 
             printf("Item %d: %s (Cód: %d)\n", i + 1, (*carrinho).produto[i].nome, (*carrinho).produto[i].codigo);
             printf("  Marca: %s, Modelo: %s\n", (*carrinho).produto[i].modelo.marca, (*carrinho).produto[i].modelo.modelo);
             printf("  Qtd: %d x R$ %.2f = R$ %.2f\n",
                    (*carrinho).quantidade[i],
                    (*carrinho).produto[i].valor,
                    (*carrinho).produto[i].valor * (*carrinho).quantidade[i]);
         }
     }
     
     if (carrinhoVazio) {
         printf("Carrinho vazio.\n");
     }
     printf("----------------------------------------\n");
 }
 
 void finalizarVenda(struct carrinhos *carrinho) {
     printf("\n================= RECIBO FINAL =================\n");
     listarCarrinho(carrinho); 
     
     printf("SUBTOTAL: R$ %.2f\n", (*carrinho).subtotal);
     printf("DESCONTO: %.1f%%\n", (*carrinho).desconto);
     printf("TOTAL...: R$ %.2f\n", (*carrinho).total);
     printf("\nObrigado pela compra, %s!\n", (*carrinho).cliente.nome);
     printf("================================================\n");
 

     struct carrinhos carrinhoVazio = {0};
     *carrinho = carrinhoVazio;
 }
 
 void efetuarVenda(struct clientes cliente[3], int numClientes, struct produtos produto[10], int numProdutos, struct carrinhos *carrinho) {
     
     int cod_cliente, cod_produto, i;
     
     if (numClientes == 0) {
         printf("Erro: Impossível vender sem clientes cadastrados.\n");
         return;
     }
     if (numProdutos == 0) {
         printf("Erro: Impossível vender sem produtos cadastrados.\n");
         return;
     }
     
    
     struct carrinhos carrinhoVazio = {0};
     *carrinho = carrinhoVazio;
 
     printf("\n--- Efetuar Venda ---\n");
     printf("Clientes disponíveis:\n");
     listarClientes(cliente, numClientes); 
     
     printf("\nDigite o código do cliente: ");
     scanf("%d", &cod_cliente);
     
     struct clientes clienteEncontrado = localizaCliente(cod_cliente, cliente, numClientes);
     
     if (clienteEncontrado.codigo == 0) {
         printf("Cliente com código %d não encontrado. Venda cancelada.\n", cod_cliente);
         return;
     }
     
     (*carrinho).cliente = clienteEncontrado; 
     system("clear");
     printf("Cliente selecionado: %s\n", (*carrinho).cliente.nome);
 
     printf("\n--- Adicionar Produtos ao Carrinho ---\n");
     for (i = 0; i < 3; i++) {
         printf("\nProdutos disponíveis:\n");
         ListarProdutos(produto, numProdutos); 
         
         printf("\nDigite o código do produto %d/3 (ou 0 para parar): ", i + 1);
         scanf("%d", &cod_produto);
         
         if (cod_produto == 0) {
             printf("Seleção de produtos encerrada.\n");
             break; 
         }
         
         struct produtos produtoEncontrado = localizaProduto(cod_produto, produto, numProdutos);
         
         if (produtoEncontrado.codigo == 0) {
             system("clear");
             printf("Produto com código %d não encontrado. Tente novamente\n", cod_produto);
             printf("\nPressione Enter para continuar...");
             getchar();
             getchar();
             system("clear");

             i--; 
             continue; 
         }
         
         int quantidade = 0;
         printf("Digite a quantidade para '%s': ", produtoEncontrado.nome);
         scanf("%d", &quantidade);
         
         if (quantidade <= 0) {
             printf("Quantidade inválida. Tente novamente para este slot.\n");
             i--; 
             continue;
         }
         
         (*carrinho).produto[i] = produtoEncontrado; 
         (*carrinho).quantidade[i] = quantidade;
         printf("'%s' (Qtd: %d) adicionado ao carrinho.\n", produtoEncontrado.nome, quantidade);
     }
     
     if ((*carrinho).quantidade[0] == 0 && (*carrinho).quantidade[1] == 0 && (*carrinho).quantidade[2] == 0) {
         printf("Nenhum produto adicionado. Venda cancelada.\n");
         return;
     }
 
     system("clear");
     listarCarrinho(carrinho);
     
     (*carrinho).subtotal = calculaSubtotal(carrinho);
     printf("SUBTOTAL: R$ %.2f\n", (*carrinho).subtotal);
 
     printf("\nDigite o desconto (ex: 10 para 10%%): ");
     scanf("%lf", &(*carrinho).desconto);
 
     (*carrinho).total = calculaTotal((*carrinho).subtotal, (*carrinho).desconto);
     
     finalizarVenda(carrinho); 
 }
 
 

     
int main()
{
 int opcoes,cont=0,cont1=0,cont2=0,cont3=0,cont4=0,confirm1,codigosubs,contador_cliente,validador_CPF=0;
 char substituir=0;
 
     clientes c1[3];
     produtos p1[10];
     
     carrinhos car1 = {0}; 
 
     ola();
 do{
     mostraMenuInicial();
         scanf(" %d",&opcoes);
     
     if(opcoes>5){
         printf("digite uma opção valida\n");
     }else{
         switch (opcoes){
             case 1:
             
             system("clear");  
             
             if(cont==3){
                 printf("\nVocê quer substituir algum cliente Sim(s) ou Não(n)? :");
                 scanf(" %c",&substituir);
                 if(substituir=='s'){
                   for(contador_cliente=0;contador_cliente<3;contador_cliente++){
                       printf("%s\n%d",c1[contador_cliente].nome,c1[contador_cliente].codigo); 
                   }
                   
                   
                   
                   do{
                   printf("\ndigite o codigo do cliente que deseja substituir!!");
                     printf("\ncaso não deseja substituir nenhum digite (0): ");
                     scanf("%d",&codigosubs);
                     if(codigosubs==c1[0].codigo){
                         cont=0;
                     }else{
                         if(codigosubs==c1[1].codigo){
                             cont=1;
                         }else{
                             if(codigosubs==c1[2].codigo){
                                 cont=2;
                             }else{
                                 if(codigosubs==0){
                                     cont=3;
                                 }
                                 printf("\nDigite um valor valido");
                                 }
                             }
                         }
                   }while(codigosubs!=c1[0].codigo&&codigosubs!=c1[1].codigo&&codigosubs!=c1[2].codigo&&codigosubs!=0);
                   }
              }
             
             /*cadastrar clientes*/
             if(cont<=2){
              printf("=================Cadastrar clientes=================\n");
              printf("Digite o nome do cliente: ");
              scanf(" %50[^\n]", c1[cont].nome);
              do{
                  validador_CPF = 0;
              printf("Digite o CPF do cliente: ");
              scanf("%lf", &c1[cont].cpf);
              switch (cont){
                      case 0:
                      if(c1[cont].cpf==c1[1].cpf||c1[cont].cpf==c1[2].cpf){
                          printf("Esse CPF já existe \nDigite um CPF Diferente");
                          validador_CPF=1;
                      }
                      break;
                      case 1:
                      if(c1[cont].cpf==c1[0].cpf||c1[cont].cpf==c1[2].cpf){
                          printf("Esse CPF já existe \nDigite um CPF Diferente");
                          validador_CPF=1;
                      }
                      break;
                      case 2:
                      if(c1[cont].cpf==c1[0].cpf||c1[cont].cpf==c1[1].cpf){
                          printf("Esse CPF já existe \nDigite um CPF Diferente");
                          validador_CPF=1;
                      }
                      break;
              }}while(validador_CPF==1);
              c1[cont].codigo = geraCodigoCliente(c1[cont].cpf);
              
              printf("Qual e o sexo do cliente Feminino(f) ou Masculino(m):");
              char verif_sexo;
              scanf(" %c",&verif_sexo);
              while(verif_sexo!='m' && verif_sexo!='M' && verif_sexo!='f' && verif_sexo!='F'){
                  printf("Sexo inválido, digite novamente o sexo do cliente: Feminino(f) ou Masculino(m)");
                  scanf(" %c", &verif_sexo);
              }
              if(verif_sexo == 'm' || verif_sexo == 'M' ){
                /*como não podemos usar bibliotecas, defini os caracteres do 
                array sexo casa por casa manualmente, é meio gambiarra mas não encontrei outra forma de fazer*/
      c1[cont].sexo[0] = 'M';
      c1[cont].sexo[1] = 'a';
      c1[cont].sexo[2] = 's';
      c1[cont].sexo[3] = 'c';
      c1[cont].sexo[4] = 'u';
      c1[cont].sexo[5] = 'l';
      c1[cont].sexo[6] = 'i';
      c1[cont].sexo[7] = 'n';
      c1[cont].sexo[8] = 'o';
      c1[cont].sexo[9] = '\0';
      
              }
              else{
                  c1[cont].sexo[0] = 'F';
                  c1[cont].sexo[1] = 'e';
                  c1[cont].sexo[2] = 'm';
                  c1[cont].sexo[3] = 'i';
                  c1[cont].sexo[4] = 'n';
                  c1[cont].sexo[5] = 'i';
                  c1[cont].sexo[6] = 'n';
                  c1[cont].sexo[7] = 'o';
                  c1[cont].sexo[8] = '\0';
                  c1[cont].sexo[9] = '\0';
 
              }
              
              //telefone
              printf("Digite o telefone fixo do cliente: ");
              scanf(" %15[^\n]",c1[cont].tel.fixo);
              printf("Digite o telefone movel do cliente: ");
              scanf(" %16[^\n]",c1[cont].tel.celular);
              
              
              
              
              
              system("clear");
              
              cont++;
             } 
             break;
             
             case 2:
             
             system("clear");
             
             if(cont1 >= 10) {
                 printf("Limite de produtos atingido (10).\n");
             } else {
                 /*Cadastrar produtos*/
                 printf("=================Cadastrar produtos=================");
                 printf("\nDigite o nome do produto: ");
                 scanf(" %20[^\n]",p1[cont1].nome);
                 
                 printf("Digite a marca do produto: ");
                 scanf(" %20[^\n]",p1[cont1].modelo.marca);
                 printf("Digite o modelo do produto: ");
                 scanf(" %20[^\n]",p1[cont1].modelo.modelo);
                 
                 printf("Digite o valor do produto: ");
                 scanf("%lf",&p1[cont1].valor);
                 
                 p1[cont1].codigo = GeraCodigoProduto(p1, cont1);
                 
                 system("clear");
                 
                 cont1++;
             }
             break;
             
             case 3:
               
               system("clear");
               
                 printf("=================Listar clientes cadastrados=================\n");
               
                 listarClientes(c1, cont);
                 
                 printf("\nPressione Enter para continuar...");
                 getchar(); 
                 getchar(); 
                 system("clear");
                 
                 cont2++;
             break;
               
             case 4:
             //Listar produtos cadastrados
             system("clear");
             printf("=================Listar produtos cadastrados=================\n");
             
                 ListarProdutos(p1, cont1);
                 
                 printf("\nPressione Enter para continuar...");
                 getchar(); 
                 getchar(); 
                 system("clear");
                 
             cont3++;
             break; 
             
             
             case 5:
             system("clear");
             
             efetuarVenda(c1, cont, p1, cont1, &car1);
             
             cont4++; 
             
             printf("\nPressione Enter para voltar ao menu...");
             getchar(); 
             getchar(); 
             system("clear");
             
             break;
         }
     }
 }while( opcoes != 0 );
 
 
 /*confirm=cont2;
 confirm=cont3;
 confirm=cont4;*/
 
 
 
 cont2=0;
 cont3=0;
 cont4=0;
 
 system("clear");
 printf("Obrigado até mais !!!");
 
     return 0;
 }
