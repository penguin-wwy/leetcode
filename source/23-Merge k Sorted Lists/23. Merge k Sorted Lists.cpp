/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void min_heap(vector<ListNode *>& heap, int index)
    {
    	int left = 2 * index;
    	int right = 2 * index + 1;
    	int least = index;
    
    	if (left < heap.size() + 1 && heap[least - 1]->val > heap[left - 1]->val)
    		least = left;
    
    	if (right < heap.size() + 1 && heap[least - 1]->val > heap[right - 1]->val)
    		least = right;
    
    	if (least != index){
    		swap(heap[least - 1], heap[index - 1]);
    
    		min_heap(heap, least);
    	}
    }
    
    void make_heap(vector<ListNode *>& heap)
    {
    	for (int i = heap.size() / 2; i > 0; i--)
    		min_heap(heap, i);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
    	if (lists.empty())
    		return NULL;
    
    	vector<ListNode *>heap;
    	heap.reserve(lists.size());
    	for (int i = 0; i < lists.size(); i++){
    		if (lists[i])
    			heap.push_back(lists[i]);
    	}
    		
    	make_heap(heap);
    	ListNode head(-1);
    	ListNode *p = &head;
    	while (!heap.empty()){
    		auto min_node = heap[0];
    		p->next = min_node;
    		p = p->next;
    		auto next = min_node->next;
    		if (next)
    			heap[0] = next;
    		else{
    			swap(heap[0], heap[heap.size() - 1]);
    			heap.pop_back();
    		}
    		min_heap(heap, 1);
    	}
    	return head.next;
    }
};