//Question link -- https://leetcode.com/problems/implement-queue-using-stacks/
//Author -- Saumya Sachdev

class MyQueue {
    Stack<Integer> queue = new Stack<Integer>();

    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        Stack<Integer> temp = new Stack<Integer>();
        while(!queue.empty()) {
            temp.push(queue.pop());
        }
        queue.push(x);
        while(!temp.empty()) {
            queue.push(temp.pop());
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return queue.pop();
    }

    /** Get the front element. */
    public int peek() {
        return queue.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return queue.empty();
    }
}

public class QueueUsingStack{
  public static void main(String args[]) {
    MyQueue obj = new MyQueue();
    obj.push(x);
    int param_2 = obj.pop();
    int param_3 = obj.peek();
    boolean param_4 = obj.empty();
  }
}
