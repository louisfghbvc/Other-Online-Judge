// the trick is when old number stack empty. dump all new number stack to it.
// don't need to dump every operation. 
// avg O(1).

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        void pop() {
            toOld();
            stack_oldest_on_top.pop();
        }

        int front() {
            toOld();
            return stack_oldest_on_top.top();
        }

        void toOld(){
            if(stack_oldest_on_top.empty()){
                while(stack_newest_on_top.size()){
                    int new_val = stack_newest_on_top.top(); stack_newest_on_top.pop();
                    stack_oldest_on_top.push(new_val);
                }
            }
        }
};
