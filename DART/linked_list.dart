class Node {
  final int value;
  Node? next;

  Node({
    required this.value,
    this.next = null,
  });

  @override
  String toString() {
    return '<Node{value: $value, next: $next}>';
  }
}

class LinkedList {
  Node head;

  LinkedList({
    required this.head,
  });

  int size() {
    Node? current = head;
    int counter = 1;

    while (current?.next != null) {
      current = current!.next;
      counter++;
    }
    return counter++;
  }

  @override
  String toString() {
    Node? current = head;
    String str = '<LinkedList [head: ${current.value}] ->';
    int counter = 1;

    while (current?.next != null) {
      current = current!.next;
      str += ' [$counter :${current!.value}] ->';
      counter++;
    }
    str += ' [tail: ${current!.value}] size=${counter += 1}>';
    return str;
  }

  void prepend(int value) {
    Node? current = head;
    Node newNode = Node(value: value, next: current);
    head = newNode;
  }

  void append(int value) {
    Node? current = head;
    while (current?.next != null) {
      current = current!.next;
    }
    current!.next = Node(value: value);
  }

  void insert(int value, int index) {
    if (index == 0) {
      prepend(value);
      return;
    }
    Node? current = head;
    int counter = 0;
    while (counter < index - 1) {
      current = current!.next;
      counter++;
    }
    current!.next = Node(value: value, next: current.next);
  }

  void remove_index(int index) {
    Node? current = head;
    Node? previous = null;

    if (index == 0) {
      head = new Node(value: current.next!.value, next: current.next!.next);
      return;
    }

    while (current?.next != null && index > 0) {
      previous = current;
      current = current!.next;
      index--;
    }

    if (current == null) {
      return;
    }

    previous!.next = current.next;
  }

  void reverse() {
    Node? current = head;
    Node? previous = null;
    Node? next = null;

    while (current != null) {
      next = current.next;
      current.next = previous;
      previous = current;
      current = next;
    }
    head = previous!;
  }

  List<int>? search(int target) {
    Node? current = head;
    int counter = 0;
    List<int> result = [];

    while (current != null) {
      if (current.value == target) {
        result.add(counter);
      }
      current = current.next;
      counter++;
    }
    if (result.isEmpty) {
      print('$target not found');
      return null;
    } else {
      return result;
    }
  }
}
