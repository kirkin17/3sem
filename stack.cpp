#include <iostream>
#define STACK_SIZE 5

struct stack
{
    int DATA[STACK_SIZE]; //cтек с размером из дефайна
    int TOP; //номер элемента вершины стека. -1 - пусто

    stack() //конструктор с инициализацией
    {
        for (int i = 0; i < STACK_SIZE; i++)
        {
            DATA[i] = 0;
        }
        TOP = -1;
    }

    bool push(int a)
    {
        if (full()) return false;
        else
        {
            TOP++;
            DATA[TOP] = a;
            return true;
        }
    }

    int pop()
    {
        if (empty()) return 0;
        else
        {
            int result;
            result = DATA[TOP]; //запоминаем значение
            DATA[TOP] = 0;      //"удаляем" элемент
            --TOP;              //смещаем вершину стека
            return result;
        }
    }

    bool empty()
    {
        if (TOP == -1) return 1; //-1 означает пустой стек
        else return 0;
    }

    bool full()
    {
        if (TOP == STACK_SIZE-1) return 1; //-1, т.к. массив начинается с нулевого элемента
        else return 0;
    }

    void print() //просто печатает стек
    {
        std::cout << "Cтек: ";
        for (int i = 0; i < STACK_SIZE; i++)
        {
            std::cout << DATA[i] << " ";
        }
        std::cout << std::endl;
    }
};




int main() //меню для проврки и отладки
{
    setlocale(LC_ALL, "ru");
    stack st;
    int menu = 0;
    int a;
    while (1)
    {
        while (1)
        {
            system("cls");
            st.print();
            std::cout << std::endl << "1. push\n2. pop\n3. Тестовый сценарий\n\n\nВыберите действие: ";
            std::cin >> menu;
            if (menu == 1)
            {
                system("cls");
                std::cout << "Введите значение: ";
                std::cin >> a;
                if (!st.push(a))
                {
                    std::cout << "Стек заполнен!";
                    system("TIMEOUT 3");
                }
            }
            if (menu == 2)
            {
                system("cls");
                if (a = st.pop())
                {
                    std::cout << a << std::endl;
                    system("TIMEOUT 3");
                }
                else
                {
                    std::cout << "Стек пуст!";
                    system("TIMEOUT 3");
                }
            }
            if (menu == 3)
            {
                st.push(3);
                st.push(5);
                st.push(7);
                st.pop();
                st.push(8);
                st.pop();
                st.pop();
                st.push(1);
                st.pop();
                st.pop();
            }
        }
    }
}