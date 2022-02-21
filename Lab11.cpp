#include <iostream>

using namespace std;
int n = 10;     //Кол-во элементов
struct point
{
    int key;
    point* next;
};

point* make_point(int n)
{
    point* first, * p;
    first = NULL;
    for (int i = n;i > 0;i--)
    {
        p = new(point);
        p->key = i;
        p->next = first;
        first = p;
    }
    return first;
}

point* print_point(point* first)
{
    if (first == NULL)return NULL;
    point* p = first;
    while (p != NULL)
    {
        cout << p->key << " ";
        p = p->next;
    }
    return first;
}

point* delete_point(point* first, int k, int index)
{
    point* p = first;
    while (k > 0)
    {
        if (index == 0) {
            p = p->next;
        }
        else
        {
            point* x = first;
            x->next = p->next->next;
        }
        n--;
        k--;
        index++;
    }
    return p;
}

point* insert_point(point* first, int a, int index)
{
    struct point* temp, * p;
    temp = (struct point*)malloc(sizeof(point));
    p = first->next; 
    first->next = temp; 
    temp->key = a; 
    temp->next = p;
    return(temp);
}

int main()
{
    point* head = make_point(n);
    //Вывод списка
    print_point(head);

    cout << "\n";
    //удаление
    int k = 3;
    int index = 2;
    head = delete_point(head, k,index);
    print_point(head);

    cout << "\n";
    //вставка одного элемента
    index = 1;
    int a = 40;
    head = insert_point(head, a, index);
    print_point(head);

    delete head;
}

