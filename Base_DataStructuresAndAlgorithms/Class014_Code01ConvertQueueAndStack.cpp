#include <stack>
#include <queue>
#include <list>

// 用栈实现队列（对应 LeetCode 232 题）
class MyQueue {
private:
    // 私有方法：倒数据（与 Java 中 inToOut 逻辑完全一致）
    // 1) out 栈为空时才能倒数据  2) 倒数据时必须将 in 栈倒完
    void inToOut() {
        if (out.empty()) {
            while (!in.empty()) {
                // C++ 栈 pop() 不返回值，需先取 top() 再 pop()
                int val = in.top();
                in.pop();
                out.push(val);
            }
        }
    }

public:
    std::stack<int> in;   // 对应 Java 的 in 栈
    std::stack<int> out;  // 对应 Java 的 out 栈

    // 构造函数：初始化两个空栈（C++ 栈默认构造即为空栈，无需额外操作）
    MyQueue() {}

    // 入队操作：与 Java 逻辑一致
    void push(int x) {
        in.push(x);
        inToOut();
    }

    // 出队操作：适配 C++ 栈语法，逻辑不变
    int pop() {
        inToOut();
        int val = out.top();  // 先获取栈顶元素
        out.pop();            // 再弹出栈顶元素（C++ pop() 无返回值）
        return val;
    }

    // 获取队头元素（不弹出）：适配 C++ 栈语法
    int peek() {
        inToOut();
        return out.top();  // C++ stack::top() 对应 Java Stack::peek()
    }

    // 判断队列是否为空：与 Java 逻辑一致
    bool empty() {
        return in.empty() && out.empty();
    }
};

// 用队列实现栈（对应 LeetCode 225 题）
class MyStack {
public:
    // C++ queue 对应 Java Queue，指定底层容器为 list 与 Java LinkedList 一致
    std::queue<int, std::list<int>> queue;

    // 构造函数：初始化空队列（C++ 队列默认构造即为空队列）
    MyStack() {}

    // 入栈操作：O(n) 时间复杂度，与 Java 逻辑完全一致
    void push(int x) {
        int n = queue.size();
        queue.push(x);  // C++ queue::push() 对应 Java Queue::offer()
        // 循环将前 n 个元素移到队尾，模拟栈的入栈逻辑
        for (int i = 0; i < n; ++i) {
            int val = queue.front();  // 先获取队头元素
            queue.pop();              // 弹出队头元素（C++ queue::pop() 无返回值）
            queue.push(val);          // 将队头元素移到队尾
        }
    }

    // 出栈操作：适配 C++ 队列语法，逻辑不变
    int pop() {
        int val = queue.front();  // 获取队头元素（对应栈顶元素）
        queue.pop();              // 弹出队头元素
        return val;
    }

    // 获取栈顶元素：对应 Java Queue::peek()
    int top() {
        return queue.front();
    }

    // 判断栈是否为空：对应 Java Queue::isEmpty()
    bool empty() {
        return queue.empty();
    }
};