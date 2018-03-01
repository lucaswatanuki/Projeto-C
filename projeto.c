#include "[FUNC03&].h"

	typedef struct lista {	
		int codigo; 	
		int quantidade;
		int qnt_padrao;
		float preco;
		char nome[30];
		struct lista *proximo;
	}t_lista;

		int iniciar(t_lista **inicio);
		int cadastro(t_lista **inicio, int codigo, int quantidade, char nome[30], float preco);
		int consulta(t_lista *inicio);
		int repete(t_lista *inicio, int codigo, int qp);
		int salvar(t_lista *inicio);
		int load(t_lista **inicio);
		int relatorio(t_lista *inicio);
		int remover(t_lista **inicio);
		int tamanho(t_lista *inicio,int *tam);
		int inverte(t_lista **inicio); int on=0;

int main() {
		
		int erro, q = 0, codigo, quantidade, qp;	
		char nome[30];	
		float preco;
		t_lista *inicio;
		
		iniciar(&inicio);

	do {	
	voltar:
	q = menu();

			switch (q) {
				
				case 1: 
			
				sub_menu(q);
				
	/*	printf("[<-]voltar	[ESPACO]continuar\n");		
		while(1){	
		Sleep(100);	
			if(GetAsyncKeyState(VK_LEFT)){ goto voltar; break; }
			else 
			if(GetAsyncKeyState(VK_SPACE)){ break; }}*/
			
					printf("  CODIGO: "); scanf("%d", &codigo); 
					fflush(stdin);	printf("  NOME: "); gets(nome);
					printf("  QUANTIDADE: "); scanf("%d", &quantidade);
					printf("  PRECO: "); scanf("%f", &preco);					
				
		
				
					qp = 0;
				
					erro = repete(inicio, codigo, qp);
				
					if (erro == 2) { 
						printf("\n  JA RESGISTRADO\n"); system("pause"); break;}
					
					if (erro == 0) {
						erro = cadastro(&inicio, codigo, quantidade, nome, preco);
						printf("\n  CONCLUIDO\n"); system("pause");}
				break;

				case 2:
					
					sub_menu(q);
					
					if(inicio==NULL){
						printf("  NENHUM PRODUTO REGISTRADO\n"); }
						
					else{
					
						
						consulta(inicio);
							
							}
						
					
					system("pause");
				break;
				
				case 3:
				
					sub_menu(q);
				
					erro = salvar(inicio);
				 	
					if (erro == 0) {
						printf("  CONCLUIDO\n");}
					
					else 
					
					printf("  VAZIO\n"); 
					
					system("pause");
				break;
				
				case 4:
					
					sub_menu(q);
					
					erro = load(&inicio);
									
					if (erro == 1 || erro == 2) { 
							printf("IMPOSSIVEL DE CONCLUIR O CARREGAMENTO\n");
					}
					
					if(erro == 0){
							printf(" REGISTROS CARREGADOS\n");
							erro = inverte(&inicio);}
						
					system("pause");
				break;

				case 5:
					
					sub_menu(q);
					
						if (inicio == NULL) { 
							printf("  ESTOQUE VAZIO\n"); system("pause"); break;}
						
						printf("  CODIGO DO PRODUTO: "); scanf("%d", &codigo);
						printf("  QUANTIDADE: "); scanf("%d", &qp);
				
						erro = repete(inicio, codigo, qp);
				
						if (erro == 3) { printf("\n  QUANTIDADE EM FALTA NO ESTOQUE\n"); }
						if (erro == 2) { printf("\n  PEDIDO REALIZADO COM SUCESSO\n"); }
						if (erro == 0) { printf("\n  PRODUTO NAO REGISTRADO\n"); }
					
					system("pause");
				break;

				case 6:
				
					sub_menu(q);
					
					erro = relatorio(inicio);
					
					if(erro==1){printf("IMPOSSIVEL DE EXECUTAR O RELATORIO\n");}
				system("pause");
				break;
			}
	} while (q != 7); return 0;}

int iniciar(t_lista **inicio) {*inicio = NULL; return 0;}

int cadastro(t_lista **inicio, int codigo, int quantidade, char nome[30], float preco) {
	
	t_lista *proximo;			// cria um ponteiro pra estrutura t_lista

	proximo = (t_lista *)malloc(sizeof(t_lista)); // criando um Nó  a partir de alocação de memória

	proximo->proximo = *inicio;		// o Nó aponta para o início da Estrutura
	*inicio = proximo;				// inicio aponta pro nó

	proximo->codigo = codigo;				//	transferencia de dados
	proximo->quantidade = quantidade;
	proximo->qnt_padrao = quantidade;
	proximo->preco = preco;
	strcpy(proximo->nome, nome);
	
return 0;}

int remover(t_lista **inicio){
	
	if(*inicio != NULL){
		t_lista *aux; 
		aux=*inicio;
		*inicio=(*inicio)->proximo;
		free(aux);}
		
	else 
	
	return 1;
	
return 0;}

int consulta(t_lista *inicio) { 
	int j, c=0;
	if (inicio == NULL) {return 1;}
	
	else
	
		printf("%c",204);for(j=0;j<30;j++){printf("%c",205);}printf("%c\n",185);
		printf("%c Cod\tQtd\tR$$\tNome   %c\n",186,186);
		printf("%c",204);for(j=0;j<30;j++){printf("%c",205);}printf("%c\n",185);
		
	while (inicio != NULL) {
		printf("  %d\t%d\t%.2f\t%s\n", inicio->codigo, inicio->quantidade,inicio->preco ,inicio->nome);
		printf("%c",204);for(j=0;j<30;j++){printf("%c",205);}printf("%c\n",185);
			c = c + inicio->quantidade;
			inicio = inicio->proximo;
			}
			
			printf("\nQuantidade total de itens no estoque: %d\n", c);
			
		printf("\n");
		
return 0;}

int tamanho(t_lista *inicio,int *tam){
	
	t_lista *percorre;
	*tam=0;
	
	if(inicio!= NULL){
		
		percorre=inicio;
		
		while(percorre!=NULL){
			(*tam)++;
			percorre=percorre->proximo;}}
			
	else 
	
*tam=0;}
	
int inverte(t_lista **inicio){
	
	int tam,codigo,quantidade,qnt_padrao,preco,i;
	char nome[30];
	t_lista *aux;
	
	tamanho(*inicio,&tam);
	
	if(tam==0){return 1;}
	
	else
	
	if(tam==1){return 2;}
	
	else
	
		iniciar(&aux);
	
		for(i=1;i<=tam;i++){
			
			codigo=(*inicio)->codigo;
			quantidade=(*inicio)->quantidade;
			strcpy(nome,(*inicio)->nome);
			preco=(*inicio)->preco;
			remover(inicio);
			cadastro(&aux,codigo,quantidade,nome,preco);}
			
	*inicio=aux;
	
return 0;}
	
int repete(t_lista *inicio, int codigo, int qp) {
	
	while (inicio != NULL) {
		if (inicio->codigo == codigo) {
			
			if (inicio->quantidade < qp) {return 3;}
								
			else 
			
			inicio->quantidade = inicio->quantidade - qp;on=1; return 2;}
			
	inicio = inicio->proximo;}
	
return 0;}

int salvar(t_lista *inicio) {
	
	FILE *arq = fopen("saida.txt", "w");
	
	if (inicio == NULL) { return 1; }

	while (inicio != NULL) {
	
		fprintf(arq, "%d %s %d %f\n", inicio->codigo, inicio->nome, inicio->quantidade, inicio->preco);
		
		inicio = inicio->proximo;}
		
	fclose(arq);
	
return 0;}

int load(t_lista **inicio) {
	
	int c, q;
	float p;
	char n[30];

	FILE *arq = fopen("saida.txt", "r");
	
	if (arq == NULL){
		return 2;
	}
	
	if (*inicio != NULL) { return 1; }
	
	
	while (fscanf(arq, "%d %s %d %f", &c, n, &q, &p) != EOF) {
		
		cadastro(inicio, c, q, n, p);}
		
	fclose(arq);
	
return 0;}

int relatorio(t_lista *inicio) { 

	int y[100],x[100],i=0,sizey,sizex,n,j,py=5;
	t_lista *aux;

	if(on==0){
		return 1;
	}else
	

	if(inicio==NULL){
	return 1;}
	
	else
	
	aux=inicio;
		printf("P = Produto\tC = Codigo\nV = Vendas\tE = Estoque\n");
		printf("%c",204);for(j=0;j<30;j++){printf("%c",205);}printf("%c\n",185);
		printf("  P  C  V   E   $\tNome\n");
		printf("%c",204);for(j=0;j<30;j++){printf("%c",205);}printf("%c\n",185);
	
	while (inicio != NULL) {
		py++;
			x[i]=i+1;
			y[i]=inicio->qnt_padrao-inicio->quantidade;
			
			printf("  %d  %d  %02d  %02d\t%.2f\t%s\n",x[i],inicio->codigo,y[i],inicio->quantidade,inicio->preco ,inicio->nome);
		
		printf("%c",204);for(j=0;j<30;j++){printf("%c",205);}printf("%c\n",185);
				
			inicio = inicio->proximo;i++;}
			
	sizey = y[0];
    
	for (n = 0; n < i; ++n){if (y[n] > sizey) sizey = y[n];}
	tamanho(aux,&sizex);
	
	sizex=sizex+2;
	

	graph(sizex,sizey,x,y);
	
	
		gotoxy(0,20);
//system("pause");

return 0;}
