import java.util.*;

public class MyQueueStackPQ {
    static Boolean trueBool, falseBool;
    static Integer a, b;

    public static void main(String[] args) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Arrays.asList(1, 323, 435435, -1000));
        a = priorityQueue.peek();
        b = priorityQueue.poll();
        trueBool = a.equals(b);
        trueBool = a.equals(-1000);
        priorityQueue.remove();
        System.out.println(priorityQueue);

        Stack<Integer> stack = new Stack<>();
        stack.push(/*item:*/32);
        a = stack.peek();
        b = stack.peek();
        trueBool = (a.equals(b));
        stack.pop();

        Deque<Integer> deque = new LinkedList<>();
        deque.addLast(97);
        deque.addFirst(32);
        a = deque.getFirst();
        b = deque.getLast();
        Integer c = ((LinkedList<Integer>) deque).get(1);
        a = deque.poll();
        b = deque.poll();
        falseBool = a.equals(b);

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(/*e:*/1);
        queue.offer(2);
        ((LinkedList<Integer>) queue).offerLast(3);
        while (!queue.isEmpty()) {
            System.out.println(queue.poll());
        }
    }
}