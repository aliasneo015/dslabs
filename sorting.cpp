#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>


using namespace std;

static unsigned int depth = 0;

class Sorting
{
public:
    void couting_sort(std::vector<int>& nums)
    {
    }

    void peigonhole_sort(std::vector<std::pair<int, char> >& values)
    {
    }

    void radix_lsd_sort(std::vector<int>& nums)
    {
    }

    void radix_msd_sort(std::vector<int>& nums)
    {

    }


    void radix_binary_msd(std::vector<int>& nums)
    {
        if (!nums.size()) {
            return;
        }

        return radix_binary_msd_impl(nums, 0, nums.size()-1, (~((UINT_MAX<<1)>>1))>>1);
    }

    void radix_binary_msd_impl(std::vector<int>& nums, int l, int r, unsigned int pos)
    {
        //Debug
        //std::cout << "l=" << l << ", r=" << r << ", pos=" << std::hex << pos << std::dec << std::endl;
        //display(nums);

        //increment call count
        depth++;

        //base case
        if (l>=r || pos == 0) {
            return;
        }

        int lo = l;
        int ro = r;

        while (l<=r) {
            // 1? , move to ones bin
            // else, move to zeros bin
            if (nums[l] & pos) {
                swap(nums[l], nums[r]);
                r--;
            }
            else {
                l++;
            }
        }

        //next term
        pos >>= 1;

        //recursively sort zeros bin
        radix_binary_msd_impl(nums, lo, l-1, pos);

        //recursively sort ones bin
        radix_binary_msd_impl(nums, l, ro, pos);
    }

public: //helper methods
    template <class T>
    void swap(T& l, T& r) {
        T t = l;
        l = r;
        r = t;
    }

    template <class T>
    void display(const std::vector<T>& v)
    {
        for(auto i = v.begin(); i != v.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }

};


class Test
{
public:
    void test_radix_binary_msd(Sorting& s)
    {
        depth = 0;
        //std::vector<int> nums = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
        //std::vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        std::vector<int> nums = {28,8,27,1,15,14,20,11,16,8,9,5,4,3,2,0,17};

        std::cout << "orig:" << std::endl;
        s.display(nums);
        s.radix_binary_msd(nums);

        std::cout << "sorted:" << std::endl;

        std::cout << "call depth=" << depth << endl;
        s.display(nums);
    }
};

int main()
{
    Sorting s;
    Test t;

    t.test_radix_binary_msd(s);
    
    return 0;
}
