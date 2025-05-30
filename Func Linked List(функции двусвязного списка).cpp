#include <iostream>

class Node { // отдельный элемент списка
    public:
        double data; // данные 
        Node* prev, * next; // указатели на предыдущий и следующий элементы

    public:
        Node(double data) {
            this->data = data;
            this->prev = this->next = nullptr;
        }
};

class LinkedList { // методы по работе со списком
    public:
        Node* head, * tail; // указатели на первый и последний элемент создаваемого списка

    public: 
        LinkedList() { // конструктор
            this->head = this->tail = nullptr;
}
        ~LinkedList() { // деструктор
            while (head != nullptr) // пока не дойдем до null 
            pop_front(); // удаляем сначала
    }

    Node* push_front(double data) { // добавление нового элемента в начало
        Node* ptr = new Node(data); // создание объекта списка
        
        // Установка связей
        ptr->next = head; // ссылка на ptr.следующий = head 
        if (head != nullptr) // если head существует
            head->prev = ptr;  // значение head предыдущего равно созданному объекту
        if (tail == nullptr) // если созданный объект единственный
            tail = ptr; // tail передвигаем на него

        head = ptr; // head передвигаем на созданны объект

        return ptr; 
        }


    Node* push_back(double data) { // добавление нового элемента в конец
        Node* ptr = new Node(data); // создание объекта списка

        // Установка связей
        ptr->prev = tail;  // ссылка на ptr.предыдущий = tail
        if (tail != nullptr) // если tail существует
            tail->next = ptr; // значение tail следующего равно созданному объекту
        if (head == nullptr) // если созданный объект единственный
            head = ptr; // head передвигаем на него

        tail = ptr; // tail передвигаем на созданны объект

        return ptr;
        }


    void pop_front() { // удаление элемента с начала списка
        if (head == nullptr) return; // если head == null , то удалять нечего

        Node* ptr = head->next; // создание временного указателя равному второму элементу
        if (ptr != nullptr) // если второй элемент существует
            ptr->prev = nullptr; // ссылку на предыдущий элемент у второго обнуляем 
        else  // если не существует
            tail = nullptr;  

        delete head; // очищаем память, обнуляем первый элемент
        head = ptr; // перемещаем указатель head на второй элемент
    }


    void pop_back() { // удаление элемента с конца списка
        if (tail == nullptr) return; // если tail == null , то удалять нечего

        Node* ptr = tail->prev; // создание временного указателя равному предпоследнему элементу
        if (ptr != nullptr) // если предпоследний элемент существует
            ptr->next = nullptr; // ссылку на следующий элемент у предпоследнего обнуляем
        else // если не существует
            head = nullptr;

        delete tail; // очищаем память, обнуляем последний элемент
        tail = ptr; // перемещаем указатель tail на предпоследний элемент
    }

    Node* getAt(int index) { // метод для произвольного доступа к элементу списка
        Node* ptr = head; // временный указатель, кот ссылается на head (индекс 0)
        int n = 0; // счетчик 

        while (n != index) { // пока не дойдем до нужного индекса

        if (ptr == nullptr) // если объект не существует или дошли до конца
            return ptr;

        ptr = ptr->next; // передвигаем указатель на следующий элемент
        n++;
        }

        return ptr;
    }


    Node* operator [] (int index) { // возвращает ссылку на элемент по определенному индексу
        return getAt(index);
    }

    
    Node* insert(int index, double data) { // вставка элемента в произвольное место
        Node* right = getAt(index); // получем указатель справа
        if (right == NULL) // если нет элемента справа
            return push_back(data); // Добавляем элемент в конец

        Node* left = right->prev; // получем указатель слева
            if (left == nullptr) // если нет элемента слева
                return push_front(data); // добавляем элемент в начало 

        Node* ptr = new Node(data); // создание нового объекта

        // Настраиваем связи у нового объекта относительно старых
        ptr->prev = left;
        ptr->next = right;
        left->next = ptr;
        right->prev = ptr;

        return ptr;
        }

    void erase(int index) { // удаление промежуточного элемента
        Node* ptr = getAt(index); // получем указатель на элемент который хотим удалить
        if (ptr == nullptr) // если объект не находим
            return;

        if (ptr->prev == nullptr) { // если если предыдущий элемент отсутствует
            pop_front(); // то искомый элемент - первый элемент и удаляем его через pop_front()
            return;
        }

        if (ptr->next == nullptr) { // если если следуюший элемент отсутствует
            pop_back(); // то искомый элемент - последний элемент и удаляем его через pop_back()
            return;
        }

        Node* left = ptr->prev; // ссылка на объект слева
        Node* right = ptr->next; // ссылка на объект справа
        
        // Настройка связей
        left->next = right; 
        right->prev = left;

        // Удаляем элемент и очищаем память
        delete ptr;
    }

};

int main()
{
    LinkedList lst;  // создание списка
    lst.push_back(1.0); // добавление элемента
    lst.push_back(2.0); // добавление элемента
    lst.push_back(3.0); // добавление элемента
    lst.push_back(4.0); // добавление элемента

    // вывод списка
    for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)
        std::cout << ptr->data << " ";

    std::cout << std::endl;

    // вывод списка в обратном порядке
    for (Node* ptr = lst.tail; ptr != NULL; ptr = ptr->prev)
        std::cout << ptr->data << " " ;

    std::cout << std::endl;

    // вывод отдельных элементов по индексу(тестим operator[])
    std::cout << "lst[1] = " << lst[1]->data << std::endl;
    std::cout << "lst[0] = " << lst[0]->data << std::endl;
    std::cout << "lst[3] = " << lst[3]->data << std::endl;

    // вставка элементов
    lst.insert(2, -5.0);
    lst.insert(20, -10.0);
    // удаление промежуточного элемента
    lst.erase(3);
    lst.erase(30);

    // вывод списка после изменений
    for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)
        std::cout << ptr->data << " ";
        std::cout << std::endl;

    return 0;
}

/*
1 2 3 4 
4 3 2 1 
lst[1] = 2
lst[0] = 1
lst[3] = 4
1 2 -5 4 -10 */
