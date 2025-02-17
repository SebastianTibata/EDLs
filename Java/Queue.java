public class Queue<T> {
	private Node<T> head;
	private Node<T> tail;
	private int size;
	
	public Queue() {
		this.head = null;
		this.tail = null;
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
		
		if (isEmpty()) {
			head = newNode;
			tail = newNode;
		} else {
			tail.setNext(newNode);
			tail = newNode;
		}
		
		size++;
	}

	public T pop() {
		if (isEmpty()) {
			throw new IllegalStateException("La cola esta vacia");
		}
		
		T data = head.getData();
		head = head.getNext();
		size--;
		return data;
	}
	
	public T peek() {
		if (isEmpty()) {
			throw new IllegalStateException("La cola esta vacia");
		}
		
		return head.getData();
	}
	
	public void showQueue() {
		Node<T> currentNode = head;
		
		while (currentNode != null) {
			System.out.print(currentNode.getData() + " -> ");
			currentNode = currentNode.getNext();
		}
		
		System.out.println("null");
	}
}
