#include <iostream>
#include <string>
using namespace std;

typedef char stack_el_t;

typedef struct list {
    stack_el_t value;
    struct list* next;
} stack_t;

void init(stack_t* head) {
    head->next = NULL;
}

void push(stack_t* l, stack_el_t value) {
    stack_t* x = new stack_t;

    x->value = value;
    x->next = l->next;
    l->next = x;
}

stack_el_t pop(stack_t* l) {
    stack_el_t el = l->next->value;
    void* x = l->next;
    l->next = l->next->next;
    delete x;
    return el;
}

void print(stack_t* h) {
    h = h->next;
    cout << h->value << ' ';
    h = h->next;
    cout << '\n';
}

void conjunt(stack_t* l)
{
    char a = pop(l);
    char b = pop(l);
    if (a == 't' && b == 't')
    {
        a = 't';
        push(l, a);
        pop(l);
    }
    else
        a = 'f';
    push(l, a);
}

void alternate(stack_t* l)
{
    char a = pop(l);
    char b = pop(l);
    if (a == 'f' && b == 'f')
    {
        a = 'f';
        push(l, a);
        pop(l);
    }
    else
        a = 't';
    push(l, a);
}

void negate(stack_t* l)
{
    char a = pop(l);
    if (a == 't')
    {
        a = 'f';
        push(l, a);
    }
    else if (a == 'f')
    {
        char a = 't';
        push(l, a);
    }

}

int main() {
    stack_t s;
    int n;
    string sequence;
    init(&s);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sequence;
        for (int j = 0; j < sequence.length(); j++)
        {
            if (sequence[j] == 'N')
                negate(&s);
            else if (sequence[j] == 'K')
                conjunt(&s);
            else if (sequence[j] == 'A')
                alternate(&s);
            else
                push(&s, sequence[j]);

        }
        print(&s);

    }

    return 0;
}
