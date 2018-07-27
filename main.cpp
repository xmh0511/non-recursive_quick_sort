#include <iostream>
#include <stack>
struct stack_data
{
    long begin;
    long end;
};
template<typename T>
void quick_sort(T& arr,long length)
{
    std::stack<stack_data> func_stack;
    func_stack.push(stack_data{0,length-1});
    while(!func_stack.empty())
    {
        stack_data data = func_stack.top();
        if(data.begin<data.end)
        {
            long left_iter = data.begin;
            long right_iter = data.end;
            int compare = arr[left_iter];
            func_stack.pop();
            while(left_iter!=right_iter)
            {
                while(left_iter<right_iter)
                {
                    if(arr[right_iter]<compare)
                    {
                        arr[left_iter] = arr[right_iter];
                        break;
                    }
                    --right_iter;
                }

                while(left_iter<right_iter)
                {
                    if(arr[left_iter]>compare)
                    {
                        arr[right_iter] = arr[left_iter];
                        break;
                    }
                    ++left_iter;
                }
            }
            arr[left_iter] = compare;
            func_stack.push(stack_data{data.begin,left_iter-1});
            func_stack.push(stack_data{left_iter+1,data.end});
        }else{
            func_stack.pop();
        }
    }
}
int main()
{
    int test[] = {10,0,8,50,2,6,11};
    quick_sort(test,7);
    for(int i =0;i<7;i++)
    {
        std::cout<<test[i]<<std::endl;
    }
    return 0;
}