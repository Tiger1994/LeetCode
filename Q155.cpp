#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	vector<int> _s;
	int _min = INT_MAX;
	MinStack() {

	}

	void push(int x) {
		_s.push_back(x);
		_min = min(_min, x);
	}

	void pop() {
		_s.pop_back();
		_min = INT_MAX;
		for (auto it = _s.begin(); it != _s.end(); it++) _min = min(_min, *it);
	}

	int top() {
		return _s.back();
	}

	int getMin() {
		return _min;
	}
};

class MinStack2 {
public:
	struct Prev {
		Prev(int x): val_(x){}
		int val_;
		Prev *prev_ = nullptr;
	};
	int INIT_CAPACITY = 8;
	Prev *prev_min_ = nullptr;
	int min_ = INT_MAX;
	int count_ = 0;
	int capacity_ = INIT_CAPACITY;
	int *data_ = nullptr;
	MinStack2() {
		data_ = new int[capacity_];
	}
	~MinStack2(){}
	void push(int x) {
		if (x <= min_) {
			Prev *old = prev_min_;
			prev_min_ = new Prev(min_);
			prev_min_->prev_ = old;
			min_ = x;
		}
		if (count_ == capacity_) {
			increaseCapacity();
		}
		data_[count_] = x;
		count_++;
	}
	void pop() {
		if (count_ > 0 && data_[--count_] == min_) {
			min_ = prev_min_->val_;
			prev_min_ = prev_min_->prev_;
		}
	}
	int top() {
		if (count_ == 0) return 0;
		return data_[count_ - 1];
	}
	int getMin() {
		return min_;
	}

private:
	void increaseCapacity() {
		int new_capacity = 2 * capacity_;
		int *datacopy = new int[new_capacity];
		for (int i = 0; i < capacity_; i++) {
			datacopy[i] = data_[i];
		}
		delete[] data_;
		data_ = datacopy;
		capacity_ = new_capacity;
	}
};

int main(void) {
	MinStack2 a;
	a.push(0);
	a.push(1);
	int x = a.top();
	a.pop();
	x = a.getMin();
	return 0;
}