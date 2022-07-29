typedef struct {
    int num;
    char *nome;
    struct listIds *prox;
} listIds;

typedef struct valorar{
    float valor;
    char *tipo;
};


void generateHeader();
void generateFooter();
void defineVar(char *lista_ids, int type);
void printLine();
void printSimb();
int findVar(char *nome);
void printnoj(int var);