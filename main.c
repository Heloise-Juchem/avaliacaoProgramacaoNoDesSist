
#include <stdio.h>
#include <sqlite3.h>

int main()
{

    sqlite3 *banco;

    int resultado;

    resultado = sqlite3_open("alunos.db", &banco);

    if (resultado == SQLITE_OK)
    {
        printf("Banco de dados conectado com sucesso!\n");
    }
    else
    {
        printf("Erro ao conectar ao banco!\n");
    }

char *sql =
"CREATE TABLE IF NOT EXISTS students ("
"id INTEGER PRIMARY KEY AUTOINCREMENT,"
"first_name TEXT NOT NULL,"
"last_name TEXT NOT NULL,"
"sex TEXT NOT NULL,"
"phone TEXT,"
"address TEXT"
");";

resultado = sqlite3_exec(banco, sql, NULL, NULL, NULL);

if (resultado != SQLITE_OK)
{
    printf("Erro ao criar tabela: %s\n",
           sqlite3_errmsg(banco));
}
else
{
    printf("Tabela criada com sucesso!\n");
}


    sqlite3_close(banco);

    return 0;
}
