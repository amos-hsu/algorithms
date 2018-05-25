/**
 * 两个队列实现栈
 */

import java.util.Queue;

import com.sun.corba.se.impl.orbutil.graph.Node;

public class Solution {
    Queue<Integer> queue1 = new Queue<Integer>();
    Queue<Integer> queue2 = new Queue<Integer>();
    
    public void push(int node) {
        if(queue1.isEmpty() && queue2.isEmpty()){   //两个都为空，优先存入1
            queue1.add(node);
            return;
        }
        if(queue1.isEmpty()){   //1为空，存入2
            queue2.add(node);
            return;
        }
        if(queue2.isEmpty()){   //2为空，存入1
            queue1.add(node);
            return;
        }
    }
    
    public int pop() throws Exception {
        if(queue1.isEmpty() && queue2.isEmpty())
            throw new RuntimeException();
        if(queue2.isEmpty()){
            while(queue1.size() > 1)
                queue2.add(queue1.poll());
            return queue1.poll();
        }
        if(queue1.isEmpty()){
            while(queue2.size() > 1)
                queue1.add(queue2.poll());
            return queue1.poll();
        }
        return (Integer)null;
    }
}

/**
 * 另一种方式：
 * 入栈：将元素进队列A
 * 出栈：判断队列A中元素的个数是否为1，
 *       如果等于1，则出队列，
 *       否则将队列A中的元素依次出队列并放入队列B，直到队列A中的元素留下一个，
 *          然后队列A出队列，再把队列B中的元素出队列依次放入队列A中。
 * 
 * 比第一种复杂度高。
 */