class MinStack {
 private:
  stack<int> m_stack;
  stack<int> min_stack;

 public:
  MinStack() {
    m_stack = stack<int>();
    min_stack = stack<int>();
  }

  void push(int x) {
    m_stack.push(x);
    if (min_stack.empty() || x <= min_stack.top()) {
      min_stack.push(x);
    }
  }

  void pop() {
    if (min_stack.top() == m_stack.top()) {
      min_stack.pop();
    }
    m_stack.pop();
  }

  int top() { return m_stack.top(); }

  int getMin() { return min_stack.top(); }
};
