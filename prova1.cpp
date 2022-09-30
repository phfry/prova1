#include<stdio.h>

typedef int dado;

struct Node {

    dado valor;
    Node* prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct List {

    Node* cabeca, * cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista está vazia ou não
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
        Node* novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        }
        else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor) { //O(1)
        Node* novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        }
        else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n)
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node* tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else {
                Node* tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else {
                Node* penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

    Node* find(dado x) { //O(n)
        Node* tmp = cabeca;
        while (tmp != NULL) {
            if (tmp->valor == x) {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }

    Node* clear() {
        while (size > 0) {
            popBack();
        }
        return cabeca;
    }

    Node* popBackValor(dado valor) {
        int count = 0;
        if (size > valor) {
            while (count != valor) {
                popBack();
                count++;
            }
        }
        else {

            clear();
        }
        return cauda;
    }

    Node* popSegundo() {

        if (cabeca == cauda) {
            NULL;
        }
        else {

            Node* tmp;
            tmp = cabeca;
            cabeca = cabeca->prox;
            popFront();
            tmp->prox = cabeca;
            cabeca = tmp;

        }
        return cabeca;
    }

    Node* insertSize() {

        pushBack(size);

        return cauda;
    }

    Node* insertN(dado valor) {

        dado cont = 1;
        while (cont <= valor) {
            pushBack(cont);
            cont++;
        }
        return cauda;

    }

    Node* insertPenul(dado valor) {
        Node* novo = new Node(valor);
        if (cabeca == cauda) {
            NULL;
        }
        else {
            Node* penul = cabeca;
            while (penul->prox != cauda) {
                penul = penul->prox;
            }
            penul->prox = novo;
            novo->prox = cauda;
            size++;
        }

        return cauda;
    }

    Node* removeN(dado valor) {
        Node* tmp = cabeca;
        Node* tmp2;
        Node* tmp3;
        dado cont = 1;
        if (size < valor) {
            return NULL;
        }
        else {

            if (valor == 1) {
                return popFront();
            }
            while (cont != valor) {
                tmp2 = tmp;
                tmp = tmp->prox;

                cont++;
            }

            tmp3 = tmp->prox;

            delete(tmp);
            tmp2->prox = tmp3;
            size--;
        }
        return cabeca;
    }

    void q1(dado valor) {

        if (size < valor) {
            while (size < valor) {
                pushFront(0);
            }

        }
        else if (size > valor) {
            while (size > valor) {
                popBack();
            }
        }
    }

    void q3() {

        Node* tmp = cabeca; 
            int a = size;
        
        for (dado i = 0; i != a; i++) {
            pushBack(tmp->valor);
            //printf("teste");
            tmp = tmp->prox;

        }

    }

    void q4(dado valor) {
        dado i = 1;
        while (i != valor + 1) {
            if (find(i) == NULL) {
                pushBack(i);
            }
            i++;

        }
    }

};

    int main() {
        List l;
        l.pushFront(5);
        l.pushFront(4);
        l.pushFront(3);
        l.pushFront(2);
        l.pushFront(1);
        
        //l.q1(2);
        //l.q3();
        l.q4(23);
        //l.insertPenul(45);
        //l.removeN(1);
        //l.insertN(5);
        //l.insertSize();
        //l.popSegundo();
        //l.popFront();
        //l.popBackValor(2);

        l.print();
        printf("%d\n", l.size);
        return 0;
    };