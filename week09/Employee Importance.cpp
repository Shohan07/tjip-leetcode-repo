/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
//TC : O(N) where N is the number of employees. 
//SC : O(N) 
class Solution {
public:
    void calcSum(unordered_map<int, Employee*> &emp, int id, int &sum) 
    {
        sum += emp[id] -> importance;
        
        for(auto subId : emp[id] -> subordinates)
        {
            calcSum(emp, subId, sum);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> emp;
        for(auto it : employees)
        {
            emp[it -> id] = it; 
        }
        int sum = 0;
        
        calcSum(emp, id, sum);
      
        return sum;
    }
    
};
