#include<cstdio>
class PriorityQueue{ //max heap
	static const int MAX_HEAP_SIZE=10000;
	int heap_size; 
	int heap[MAX_HEAP_SIZE+1];
private:
	static void swap(int* a, int* b){
		int tmp=*a;
		*a=*b;
		*b=tmp;
	}	
public:
	PriorityQueue(){
		this->heap_size=0;
	}
	
	void push(int value){
		if(this->heap_size==MAX_HEAP_SIZE){
			printf("heap is full!\n");
			return;
		}
		this->heap[++heap_size]=value;
		int value_idx = this->heap_size;
		int p_idx = value_idx/2;
		while(value_idx>1&& heap[p_idx]<heap[value_idx]){
			swap(&heap[p_idx], &heap[value_idx]);
			value_idx=p_idx;
			p_idx=value_idx/2;
		}
	}
	
	int pop(){
		if(this->heap_size==0){
			printf("heap is empty!\n");
			return -987654321;
		}
		int ret = this->heap[1];
		swap(&heap[1], &heap[heap_size]);
		heap_size--;
		
		int value_idx = 1;
		int c_idx = value_idx*2;
		if(c_idx+1<=heap_size){
			if(heap[c_idx]<=heap[c_idx+1]){
				c_idx=c_idx+1;
			}
		}
		while(c_idx<=heap_size && heap[value_idx]<heap[c_idx]){
			swap(&heap[value_idx], &heap[c_idx]);
			value_idx=c_idx;
			c_idx=c_idx*2;
			if(c_idx+1<=heap_size){
				if(heap[c_idx]<=heap[c_idx+1]){
					c_idx=c_idx+1;
				}
			}	
		}
		return ret;
	}	
};

int main(){
	PriorityQueue maxpq;
	
	maxpq.push(1);
	maxpq.push(3);
	maxpq.push(2);
	maxpq.push(4);
	maxpq.push(5);
	maxpq.push(7);
	maxpq.push(6);
	
	printf("pop: %d\n", maxpq.pop());
	printf("pop: %d\n", maxpq.pop());
	printf("pop: %d\n", maxpq.pop());
	printf("pop: %d\n", maxpq.pop());
	printf("pop: %d\n", maxpq.pop());
	printf("pop: %d\n", maxpq.pop());
	printf("pop: %d\n", maxpq.pop());
}
