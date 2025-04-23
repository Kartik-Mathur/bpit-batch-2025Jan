class Pair {
public:
	int price;
	int span;
};

class StockSpanner {
public:
	stack<Pair> s;

	StockSpanner() {

	}

	int next(int price) {
		int x = 1;
		while (!s.empty() and price >= s.top().price) {
			x += s.top().span;
			s.pop();
		}

		s.push({price, x});
		return x;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */