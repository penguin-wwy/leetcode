class Solution {
public:
    string multiply(string num1, string num2) {
    
   		vector<int> res(num1.size() + num2.size(), 0);
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	
	for(int i = 0; i < num1.size(); i++){
		for(int j = 0; j < num2.size(); j++){
			res[i + j] += (num1[i] - '0') * (num2[j] - '0');
		}
	}
	
 	int carry = 0;  
  	for (int i = 0; i < res.size(); i++)  
   	{  
    	int temp = res[i] + carry;  
     	res[i] = temp % 10;  
      	carry = temp / 10;  
   	}  
   	
   	for(int i = res.size() - 1; i >= 0; i--){
		if(res[i] != 0)
			break;
		res.pop_back();   	
   	}
   	
   	reverse(res.begin(), res.end());
   	string s;
   	for(int i = 0; i < res.size(); i++)
   		s += res[i] + '0';
   		
	return s.size() != 0 ? s : string("0");
    }
};