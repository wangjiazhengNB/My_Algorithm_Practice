#include <queue>
#include <stack>
#include <list>

// 对应 Java 外部类 QueueStackAndCircularQueue，使用命名空间避免命名冲突
namespace QueueStackAndCircularQueue {

    // 直接用 C++ 内部的队列实现（底层默认 deque，可指定为 list 对应 Java LinkedList）
    class Queue1 {
    public:
        // C++ queue 对应 Java Queue，指定底层容器为 list 与 Java LinkedList 一致
        std::queue<int, std::list<int>> queue;

        // 判断队列是否为空
        bool isEmpty() {
            return queue.empty();
        }

        // 向队列尾部加入元素
        void offer(int num) {
            queue.push(num); // C++ push 对应 Java offer
        }

        // 从队列头部弹出并返回元素
        int poll() {
            int frontVal = queue.front(); // C++ front 获取头部元素（不弹出）
            queue.pop(); // C++ pop 仅弹出（不返回值）
            return frontVal;
        }

        // 返回队列头部元素（不弹出）
        int peek() {
            return queue.front();
        }

        // 返回队列元素个数
        int size() {
            return queue.size();
        }
    };

    // 刷题常用的数组实现队列（常数时间更优，对应 Java Queue2）
    class Queue2 {
    public:
        int* queue; // 动态数组对应 Java int[]
        int l;
        int r;

        // 构造函数：初始化队列容量
        Queue2(int n) {
            queue = new int[n]; // 分配动态内存
            l = 0;
            r = 0;
        }

        // 析构函数：释放动态内存，避免内存泄漏
        ~Queue2() {
            delete[] queue;
        }

        // 判断队列是否为空
        bool isEmpty() {
            return l == r;
        }

        // 向队列尾部加入元素
        void offer(int num) {
            queue[r++] = num;
        }

        // 从队列头部弹出并返回元素
        int poll() {
            return queue[l++];
        }

        // 返回队列头部元素（不弹出）
        int head() {
            return queue[l];
        }

        // 返回队列尾部元素
        int tail() {
            return queue[r - 1];
        }

        // 返回队列元素个数
        int size() {
            return r - l;
        }
    };

    // 直接用 C++ 内部的栈实现（对应 Java Stack1）
    class Stack1 {
    public:
        std::stack<int> stack; // C++ stack 对应 Java Stack

        // 判断栈是否为空
        bool isEmpty() {
            return stack.empty();
        }

        // 向栈顶压入元素
        void push(int num) {
            stack.push(num);
        }

        // 从栈顶弹出并返回元素
        int pop() {
            int topVal = stack.top(); // C++ top 获取栈顶元素（不弹出）
            stack.pop(); // C++ pop 仅弹出（不返回值）
            return topVal;
        }

        // 返回栈顶元素（不弹出）
        int peek() {
            return stack.top();
        }

        // 返回栈元素个数
        int size() {
            return stack.size();
        }
    };

    // 刷题常用的数组实现栈（常数时间更优，对应 Java Stack2）
    class Stack2 {
    public:
        int* stack; // 动态数组对应 Java int[]
        int size;

        // 构造函数：初始化栈容量
        Stack2(int n) {
            stack = new int[n];
            size = 0;
        }

        // 析构函数：释放动态内存
        ~Stack2() {
            delete[] stack;
        }

        // 判断栈是否为空
        bool isEmpty() {
            return size == 0;
        }

        // 向栈顶压入元素
        void push(int num) {
            stack[size++] = num;
        }

        // 从栈顶弹出并返回元素
        int pop() {
            return stack[--size];
        }

        // 返回栈顶元素（不弹出）
        int peek() {
            return stack[size - 1];
        }

        // 返回栈元素个数（注意：与成员变量 size 同名，需通过 this 区分或直接返回）
        int size() {
            return this->size;
        }
    };

    // 设计循环队列（对应 Java 内部类 MyCircularQueue，逻辑完全一致）
    // 测试链接 : https://leetcode.cn/problems/design-circular-queue/
    class MyCircularQueue {
    public:
        int* queue;
        int l, r, size, limit;

        // 构造函数：初始化循环队列容量
        MyCircularQueue(int k) {
            queue = new int[k];
            l = r = size = 0;
            limit = k;
        }

        // 析构函数：释放动态内存
        ~MyCircularQueue() {
            delete[] queue;
        }

        // 入队操作：队列未满时加入元素，返回 true；否则返回 false
        bool enQueue(int value) {
            if (isFull()) {
                return false;
            } else {
                queue[r] = value;
                // r 循环更新：到达末尾则跳回 0
                r = (r == limit - 1) ? 0 : (r + 1);
                size++;
                return true;
            }
        }

        // 出队操作：队列非空时弹出头部元素，返回 true；否则返回 false
        bool deQueue() {
            if (isEmpty()) {
                return false;
            } else {
                // l 循环更新：到达末尾则跳回 0
                l = (l == limit - 1) ? 0 : (l + 1);
                size--;
                return true;
            }
        }

        // 返回队列头部元素（不弹出），队列为空返回 -1
        int Front() {
            if (isEmpty()) {
                return -1;
            } else {
                return queue[l];
            }
        }

        // 返回队列尾部元素，队列为空返回 -1
        int Rear() {
            if (isEmpty()) {
                return -1;
            } else {
                int last = (r == 0) ? (limit - 1) : (r - 1);
                return queue[last];
            }
        }

        // 判断队列是否为空
        bool isEmpty() {
            return size == 0;
        }

        // 判断队列是否已满
        bool isFull() {
            return size == limit;
        }
    };

} // 命名空间 QueueStackAndCircularQueue 结束