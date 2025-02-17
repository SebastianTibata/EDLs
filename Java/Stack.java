public class Stack<T> {
	private Node<T> head;
	private int size;
	
	public Stack() {
		this.head = null;
		this.size = 0;
	}
	
	public int getSize() {
		return size;
	}
	
	public boolean isEmpty() {
		return head == null;
	}
	
	public void push(T data) {
		Node<T> newNode = new Node<>(data);
		newNode.setNext(head);
		head = newNode;
		size++;
	}
	
	public T pop() {
		if (isEmpty()) {
			throw new IllegalStateException("La pila esta vacia");
		}
		
		T data = head.getData();
		head = head.getNext();
		size--;
		return data;
	}
	
	public T peek() {
		if (isEmpty()) {
			throw new IllegalStateException("La pila esta vacia");
		}
		
		return head.getData();
	}
	
	public void showStack() {
		Node<T> currentNode = head;
		
		while (currentNode != null) {
			System.out.print(currentNode.getData() + " -> ");
			currentNode = currentNode.getNext();
		}
		
		System.out.println("null");
	}
}
