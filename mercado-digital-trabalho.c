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
 //Nota: cont[0]e referente a quantas vezes foi rodado o processo de cadastro de clientes
 //Nota: cont[1]e referente a quantas vezes foi rodado o processo de cadastro de produtos
 //Nota: cont[2]e referente a quantas vezes foi rodado o processo de listagem de clientes
 //Nota: cont[3]e referente a quantas vezes foi rodado o processo de listagem de produtos
 //Nota: cont[4]e referente a quantas vezes foi rodado o processo de efetuação de venda simples
 int opcoes,cont=0,cont1=0,cont2=0,cont3=0,cont4=0, confirm1;



 /*funçoes do codigo*/
 
 
 
 
  void ola(void)
 {
     printf("ola \n Seja Bem vindo");
 }
 void mostraMenuInicial(){
      printf("\nQual dessas opções voce deseja realizar ? ");
    printf("\n 1 - Cadastrar clientes \n 2 - Cadastrar produtos  \n 3 - Listar clientes cadastrados \n 4 - Listar produtos cadastrados \n 5 - Efetuar uma venda simples \n 0 - Sair do programa \n");

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
 void listarClientes(clientes c1[], telefones t1[], int confirm){
   
   
    if (cont == 0){
        printf("Nenhum cliente cadastrado ainda!\n");
        return;
    }else{

    for( confirm = 0; confirm < cont; confirm++){
      
          
        printf("\n---------Cliente %d---------\n", cont+1);
        printf("Nome: %s\n", c1[confirm].nome);
         printf("CPF: "); 
        if(c1[confirm].cpf<10000000000){
        printf("0");}
        printf("%.0lf\n", c1[confirm].cpf);
        printf("Código: %d\n", c1[confirm].codigo);
        printf("Telefone fixo: %s\n", t1[confirm].fixo);
        printf("Telefone móvel: %s\n", t1[confirm].celular);
    }
    }
   

    getchar();
    getchar();
    system("clear");
}
 void ListarProdutos(produtos p1[],modelos m1[],int confirm){
 
     if(cont1==0){
          printf("Nenhum produto cadastrado ainda!\n");
     }else{
    
    
    for( confirm = 0; confirm < cont1; confirm++){
printf("\n----------produtos----------\nProduto:%s\n",p1[confirm].nome);
printf("Modelo:%s\n",m1[confirm].modelo);
printf("Marca:%s\n",m1[confirm].marca);
printf("Codigo: %d\n",p1[confirm].codigo);
printf("Valor:%0.2lf",p1[confirm].valor);
}
}
            
            
            getchar();
            getchar();
            system("clear");
 }
 
 
 
 int GeraCodigoProduto(produtos p1[], modelos m1[], int cont1) {
    int confirm=cont1;
    int C1=m1[confirm].marca[0];
    int C2=m1[confirm].marca[1];
    int C3=m1[confirm].modelo[0];
    int C4=m1[confirm].modelo[1];
    int codigo;
     
    codigo = (C1*31*31*31)+(C2*31*31)+(C3*31)+(C4*1);
    return codigo;
} 
 
 
 
 
int main()
{
    telefones t1[3];
    clientes c1[3];
    modelos m1[10];
    produtos p1[10];
    carrinhos car1;
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
            
            /*cadastrar clientes*/
             printf("\n\n\n\n\n\n--------------------Cadastrar clientes--------------------\n");
            printf("Digite o nome do cliente: ");
            scanf(" %50[^\n]", &c1[cont].nome);
            printf("Digite o CPF do cliente: ");
            scanf("%lf", &c1[cont].cpf);
            c1[cont].codigo = geraCodigoCliente(c1[cont].cpf);
            //telefone
            printf("Digite o telefone fixo do cliente: ");
            scanf(" %15[^\n]",&t1[cont].fixo);
            printf("Digite o telefone movel do cliente: ");
            scanf(" %16[^\n]",&t1[cont].celular);
            
            
            
            
            
            system("clear");
            cont++;
            break;
            case 2:
            
            system("clear");
            
            /*Cadastrar produtos*/
                printf("\n\n\n\n\n--------------------Cadastrar produtos--------------------\n");
                printf("\nDigite o nome do produto: ");
                scanf(" %20[^\n]",&p1[cont1].nome);
                printf("Digite a marca do produto: ");
                scanf(" %20[^\n]",&m1[cont1].marca);
                printf("Digite o modelo do produto: ");
                scanf(" %20[^\n]",&m1[cont1].modelo);
                printf("Digite o valor do produto: ");
                scanf("%lf",&p1[cont1].valor);
                p1[cont1].codigo = GeraCodigoProduto(p1, m1, cont1);
             
                system("clear");
             
                cont1++;
            break;
            case 3:
             
              system("clear");
              
                printf("\n\n--------------------Listar clientes cadastrados--------------------\n");
             
                listarClientes(c1, t1, cont);
             
                cont2++;
            break;
             
            case 4:
            //Listar produtos cadastrados
            system("clear");
            printf("--------------------Listar produtos cadastrados--------------------\n");
                ListarProdutos(p1, m1, cont1);
            cont3++;
            break; 
            
            
            case 5:
            system("clear");
            //Efetuar uma venda simples
            printf("\n\tEfetuar uma venda simples\n");
            printf("Selecione o Cliente:");
             confirm1=cont;
             cont=0;
             do{
                 //apagar codigo c1[cont].codigo=0; após criar a validação do codigo ultilizando os 6 primeiros digitos 
         c1[cont].codigo=0;
         printf("\n---------clientes--------\nNome:%s\nCodigo:%d",c1[cont].nome,c1[cont].codigo);
         cont++;
         }while(cont<confirm1);
            
            
            
            
            getchar();
            getchar();
            system("clear");
            cont4++;
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