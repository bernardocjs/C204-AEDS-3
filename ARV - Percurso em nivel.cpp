#include<iostream>
#include<list>

using namespace std;

// Struct para armazenar os elementos de uma �rvore bin�ria
struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode *treenodeptr;

// Insere elementos em uma �rvore bin�ria
void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info) // subarvore esquerda
        tInsere(p->esq, x);
    else // subarvore direita
        tInsere(p->dir, x);
}
// Realiza um percurso em n�vel na �rvore
void emNivel(treenodeptr t)
{
    treenodeptr n;
    list<treenodeptr> q;
    if (t!=NULL)
    {
        q.push_back(t);
        while (!q.empty())
        {
            n = *q.begin();
            q.pop_front();
            if (n->esq != NULL)
                q.push_back(n->esq);
            if (n->dir != NULL)
                q.push_back(n->dir);
            cout << n->info << " ";
        }
        cout << endl;
    }
}

int main()
{
    treenodeptr arvore = NULL;
    int x;
    // Lendo elementos e inserindo na �rvore
    cin >> x;
    while(x != -1)
    {
        tInsere(arvore, x);
        cin >> x;
    }
    // Percurso em n�vel
    emNivel(arvore);
    
    return 0;
}