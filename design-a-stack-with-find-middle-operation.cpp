class Solution {
public:
	template <typename T>
	class Stack {
		// http://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
		//
		// How to implement a stack which will support following operations in O(1) time complexity?
		//  1) push() which adds an element to the top of stack.
		//  2) pop() which removes an element from top of stack.
		//  3) findMiddle() which will return middle element of the stack.
		//  4) deleteMiddle() which will delete the middle element.
		//                 
		//      stack size: 0 1 2 3 4 5 6 ...
		// index of middle: - 1 1 2 2 3 3 ...

	public:
		Stack() {
			_size = 0;
		}
		bool empty() {
			return _size == 0;
		}
		void push(T val) {
			_list.push_back(val);
			_size++;
			if (_size == 1) {
				_middle = _list.begin();
			}
			else if ((_size % 2) != 0){
				_middle++;
			}
		}
		T& top() {
			return _list.back();
		}
		void pop() {
			_list.pop_back();
			_size--;
			if (_size > 0 && (_size % 2) == 0) {
				_middle--;
			}
		}
		T& findMiddle() {
			return (*_middle);
		}
		void deleteMiddle() {
			auto p = _middle;
			_size--;
			if (_size <= 1) {
				_list.erase(p);
				_middle = _list.begin();
				return;
			}
			_middle--;
			_list.erase(p);
			if ((_size % 2) != 0) {
				_middle++;
			}
		}
	private:
		list<T> _list;
		typename list<T>::iterator _middle;
		int _size;
	};
	void test() {
		Stack<int> s;
		s.push(3);
		s.push(4);
		s.push(5);
		for (int i = 0; i < 3; i++) {
			int m = s.findMiddle();
			cout << m << endl;
			s.deleteMiddle();
		}
	}
};
