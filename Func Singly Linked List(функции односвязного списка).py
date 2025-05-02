class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        """добавляет новый узел в начало списка. Это делается путем создания нового 
        узла с переданными данными и установки его в качестве новой головы списка. 
        Новый узел теперь указывает на предыдущую голову списка, тем самым 
        становясь первым элементом."""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        """добавляет новый узел в конец списка. Если список пуст, новый узел 
        становится головой списка. В противном случае, метод продвигается до 
        последнего узла и добавляет новый узел после него."""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def delete_node(self, key):
        """удаляет узел по заданному ключу (значению `data`). Если удаляемый узел 
        является головой списка, голова смещается на следующий узел. 
        В противном случае находится предыдущий узел для удаляемого
        узла, и его ссылка `next` изменяется на узел, следующий за удаляемым."""
        current = self.head
        if current and current.data == key:
            self.head = current.next
            current = None
            return
        prev = None
        while current and current.data != key:
            prev = current
            current = current.next
        if current is None:
            return
        prev.next = current.next
        current = None

    def search(self, key):
      """выполняет поиск узла по его значению. Метод возвращает `True`, 
      если узел с заданным значением найден в списке, и `False` — в противном случае."""
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    def get_size(self):
      """возвращает количество узлов в списке, перебирая 
      все узлы от головы до конца и подсчитывая их."""
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count

    def print_list(self):
      """проходит по всем узлам списка, начиная с головы, и выводит 
      их данные на экран. Перебор продолжается до тех пор, пока 
      не будет достигнут конец списка (`current.next` равен `None`)."""
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")
