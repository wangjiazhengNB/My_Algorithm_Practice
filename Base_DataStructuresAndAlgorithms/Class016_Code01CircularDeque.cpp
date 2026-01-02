#include <deque>
#include <list>

// 对应 Java 外部类 CircularDeque，使用命名空间包裹避免命名冲突
namespace CircularDeque {

    // 对应 Java 内部类 MyCircularDeque1（基于双端队列容器实现，逻辑完全一致）
    // 提交到 LeetCode 时，将类名改为 MyCircularDeque 即可
    class MyCircularDeque1 {
    public:
        // C++ std::deque 对应 Java Deque，此处也可指定 std::list 作为底层（与 Java LinkedList 一致）
        // 两种写法均可，逻辑无差异，此处使用 std::deque 更贴合 C++ 常用写法
        std::deque<int> deque;
        int size;       // 手动维护当前元素个数，与 Java 逻辑一致
        int limit;      // 队列最大容量，对应 Java k

        // 构造函数：初始化 size 和 limit，与 Java 逻辑一致
        MyCircularDeque1(int k) {
            size = 0;
            limit = k;
        }

        // 从队头插入元素，对应 Java insertFront
        bool insertFront(int value) {
            if (isFull()) {
                return false;
            } else {
                deque.push_front(value); // C++ push_front 对应 Java offerFirst
                size++;
                return true;
            }
        }

        // 从队尾插入元素，对应 Java insertLast
        bool insertLast(int value) {
            if (isFull()) {
                return false;
            } else {
                deque.push_back(value);  // C++ push_back 对应 Java offerLast
                size++;
                return true;
            }
        }

        // 删除队头元素，对应 Java deleteFront
        bool deleteFront() {
            if (isEmpty()) {
                return false;
            } else {
                size--;
                deque.pop_front(); // C++ pop_front 对应 Java pollFirst
                return true;
            }
        }

        // 删除队尾元素，对应 Java deleteLast
        bool deleteLast() {
            if (isEmpty()) {
                return false;
            } else {
                size--;
                deque.pop_back();  // C++ pop_back 对应 Java pollLast
                return true;
            }
        }

        // 获取队头元素（不删除），对应 Java getFront
        int getFront() {
            if (isEmpty()) {
                return -1;
            } else {
                return deque.front(); // C++ front 对应 Java peekFirst
            }
        }

        // 获取队尾元素（不删除），对应 Java getRear
        int getRear() {
            if (isEmpty()) {
                return -1;
            } else {
                return deque.back();  // C++ back 对应 Java peekLast
            }
        }

        // 判断队列是否为空，对应 Java isEmpty
        bool isEmpty() {
            return size == 0;
        }

        // 判断队列是否已满，对应 Java isFull
        bool isFull() {
            return size == limit;
        }
    };

    // 对应 Java 内部类 MyCircularDeque2（基于数组实现，常数操作更高效，逻辑完全一致）
    // 提交到 LeetCode 时，将类名改为 MyCircularDeque 即可
    class MyCircularDeque2 {
    public:
        int* deque;     // 对应 Java int[] deque，动态数组适配构造时指定容量
        int l, r;       // 队头/队尾指针，与 Java 逻辑一致
        int size;       // 当前元素个数
        int limit;      // 队列最大容量

        // 构造函数：初始化数组和成员变量，对应 Java MyCircularDeque2(int k)
        MyCircularDeque2(int k) {
            deque = new int[k];
            l = r = size = 0;
            limit = k;
        }

        // 析构函数：释放动态数组内存，避免内存泄漏
        ~MyCircularDeque2() {
            delete[] deque;
        }

        // 从队头插入元素，完全照搬 Java insertFront 逻辑
        bool insertFront(int value) {
            if (isFull()) {
                return false;
            } else {
                if (isEmpty()) {
                    l = r = 0;
                    deque[0] = value;
                } else {
                    // 队头指针循环左移，与 Java 三元运算符逻辑一致
                    l = (l == 0) ? (limit - 1) : (l - 1);
                    deque[l] = value;
                }
                size++;
                return true;
            }
        }

        // 从队尾插入元素，完全照搬 Java insertLast 逻辑
        bool insertLast(int value) {
            if (isFull()) {
                return false;
            } else {
                if (isEmpty()) {
                    l = r = 0;
                    deque[0] = value;
                } else {
                    // 队尾指针循环右移，与 Java 三元运算符逻辑一致
                    r = (r == limit - 1) ? 0 : (r + 1);
                    deque[r] = value;
                }
                size++;
                return true;
            }
        }

        // 删除队头元素，完全照搬 Java deleteFront 逻辑
        bool deleteFront() {
            if (isEmpty()) {
                return false;
            } else {
                // 队头指针循环右移，与 Java 三元运算符逻辑一致
                l = (l == limit - 1) ? 0 : (l + 1);
                size--;
                return true;
            }
        }

        // 删除队尾元素，完全照搬 Java deleteLast 逻辑
        bool deleteLast() {
            if (isEmpty()) {
                return false;
            } else {
                // 队尾指针循环左移，与 Java 三元运算符逻辑一致
                r = (r == 0) ? (limit - 1) : (r - 1);
                size--;
                return true;
            }
        }

        // 获取队头元素，完全照搬 Java getFront 逻辑
        int getFront() {
            if (isEmpty()) {
                return -1;
            } else {
                return deque[l];
            }
        }

        // 获取队尾元素，完全照搬 Java getRear 逻辑
        int getRear() {
            if (isEmpty()) {
                return -1;
            } else {
                return deque[r];
            }
        }

        // 判断队列是否为空，对应 Java isEmpty
        bool isEmpty() {
            return size == 0;
        }

        // 判断队列是否已满，对应 Java isFull
        bool isFull() {
            return size == limit;
        }
    };

} // 命名空间 CircularDeque 结束