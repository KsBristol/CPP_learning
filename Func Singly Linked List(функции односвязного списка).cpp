#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct lst
{
	int data;
	lst *tail;
};

lst *createlst(int length)
{
    /*Функция создания списка*/
    lst* curr = 0, // Адрес очередного элемента списка
        *next = 0; // Адрес следующего за очередным элемента списка
    // Начинаем создавать список с последнего элемента
    for (int i = 1; i <= length; ++i) {
    // Создаем очередной элемент списка
    curr = new lst;
    // В адресную часть записываем адрес следующего
    // за очередным элемента списка
    curr -> tail = next;
    // Запоминаем адрес очередного элемента в качестве
    // следующего элемента для следующего шага цикла
    next = curr;
}
    // Возвращаем адрес последнего созданного элемента, 
    // как адрес первого элемента списка
    return curr;
}

void appendlst(lst *curr){
    /*Функция Добавление элемента к списку*/ 
    
    // Выполняем цикл пока адрес очередного элемента списка не равен 0
    while (curr)
    {
        // Вводим данные в информационную часть очередного элемента с клавиатуры
        cin >> curr -> data; 
        // Делаем очередным следующий элемент списка. Для этого переменной
        // Curr присваиваем адрес следующего элемента списка. Последний элемент 
        // списка содержит в адресной части 0, поэтому кода мы обработаем последний 
        // элемент списка, переменная Curr станет равна 0, и цикл закончится
        curr = curr -> tail;
    }
    
}

lst *sortedlst(lst *curr, int length) {
    /*Функция пузырьковой сортировки списка*/
    lst *currNode = curr;
    int len = length;
    int itr = 0;
    bool swapped;

    // Iterating over the whole linked list
    while (itr < len) {
        lst *traverseNode = curr;
        lst *prevNode = curr;
        swapped = false;

        while (traverseNode->tail) {

            // Temporary pointer to store the next
            // pointer of traverseNode
            lst *ptr = traverseNode->tail;
            if (traverseNode->data > ptr->data) {
                swapped = true;
                if (traverseNode == curr) {

                    // Performing swap operations and
                    // updating the head of the linked list
                    traverseNode->tail = ptr->tail;
                    ptr->tail = traverseNode;
                    prevNode = ptr;
                    curr = prevNode;
                }
                else {

                    // Performing swap operation
                    traverseNode->tail = ptr->tail;
                    ptr->tail = traverseNode;
                    prevNode->tail = ptr;
                    prevNode = ptr;
                }
                continue;
            }
            prevNode = traverseNode;
            traverseNode = traverseNode->tail;
        }

        // If no swap occurred, break the loop
        if (!swapped) {
            break;
        }

        ++itr;
    }

    // Returning the head of the linked list
    return curr;
}


void findchislo(lst *curr, int chislo)
{
	/*функция поиска по значению*/
    
    // флаг на найденное значение
    bool fl = false;
    if (curr == nullptr) cout << "The list is empty";
	
    while (curr != nullptr) {
        if (curr->data == chislo) fl = true;
        curr = curr->tail;
    }

    if(fl) cout << "List item found";
    else cout << "List item not found";
}

void delchislo(lst *curr, int chislo){
    /*функция удаления элемента по значению*/
    if (curr == nullptr) return; // Если список пуст, ничего не делаем

    // Если нужно удалить головной элемент
    if (curr->data == chislo) {
        lst* temp = curr;
        curr = curr->tail;
        delete temp;
        cout << "List item deleted\n";
        return;
        }
        
    
    while (curr->tail != nullptr) {
        if (curr->tail->data == chislo) {
            lst* temp = curr->tail;
            curr->tail = curr->tail->tail; // Пропускаем удаляемый узел
            delete temp; // Освобождаем память
            cout << "List item deleted\n";
            return;
        }
            curr = curr->tail;
    }
    cout << "List item not found\n";
}

int printlst(lst *curr){
    /* Функция вывода элементов списка на экран*/
    if (curr == nullptr) {cout << "The list is empty"; return 0;}
    
    while (curr)
    {
    // Выводим информационную часть очередного элемента на экран
        cout << curr -> data << ' '; 
        curr = curr -> tail;
    }
    cout << endl;

    return 0;
}

int main() {
    int n;
    std::cin >> n;
    if (n < 0) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    } 
    if (n == 0) {
        std::cout << "The array contains no elements." << std::endl;
        return 0;
    }
    
    // создание списка
    lst *list = createlst(n);
    
    //добавление элементов в конец списка
    appendlst(list);

    int chislo{};
    cin >> chislo;
    
    //сортировка списка 
    //list = sortedlst(list, n);
    
    // поиск по значению
    //findchislo(list, chislo);

    //удаление по значению
    delchislo(list, chislo);

    // печать списка
    printlst(list);


    return 0;
}
