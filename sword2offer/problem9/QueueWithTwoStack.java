/**
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 * 
 * 思路：
 * 入队：将元素压入栈1
 * 出队：判断栈2是否为空，
 *          若为空，则将栈1的元素依次弹出，压入栈2，栈2出栈
 *          否则，栈2直接出栈。
 * 
 * 缺点就是，当push操作积攒的数据过多时，下一次pop操作的开销会变得很大，从而导致pop操作的开销不稳定。
 * 解决方法应该是，在push中设置阀值，以提升pop操作的稳定性
 */

import java.util.Stack;

public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    
    public void push(int node) {
        stack1.push(node);
    }
    
    public int pop() throws Exception {
        if(stack2.isEmpty())
            while(!stack1.isEmpty())
                stack2.push(stack1.pop());
        if(stack2.isEmpty()) throw new Exception("queue is Empty");
        return stack2.pop();
    }
}