# Remove Element :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/remove-element](https://leetcode-cn.com/problems/remove-element)
- ִ��ʱ��: 4 ms 
- �ڴ�����: N/A
- ͨ������: 2019-04-11 00:15
## ��Ŀ����
<p>����һ������ <em>nums�0�2</em>��һ��ֵ <em>val</em>������Ҫ <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">ԭ��</a></strong> �Ƴ�������ֵ���ځ0�2<em>val�0�2</em>��Ԫ�أ��������Ƴ���������³��ȡ�</p>

<p>��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">ԭ�� </a>�޸���������</strong>��</p>

<p>Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�</p>



<p><strong>ʾ�� 1:</strong></p>

<pre>���� <em>nums</em> = <strong>[3,2,2,3]</strong>, <em>val</em> = <strong>3</strong>,

����Ӧ�÷����µĳ��� <strong>2</strong>, ���� <em>nums </em>�е�ǰ����Ԫ�ؾ�Ϊ <strong>2</strong>��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre>���� <em>nums</em> = <strong>[0,1,2,2,3,0,4,2]</strong>, <em>val</em> = <strong>2</strong>,

����Ӧ�÷����µĳ��� <strong><code>5</code></strong>, ���� <em>nums </em>�е�ǰ���Ԫ��Ϊ <strong><code>0</code></strong>, <strong><code>1</code></strong>, <strong><code>3</code></strong>, <strong><code>0</code></strong>, <strong>4</strong>��

ע�������Ԫ�ؿ�Ϊ����˳��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
</pre>



<p><strong>˵��:</strong></p>

<p>Ϊʲô������ֵ��������������Ĵ���������?</p>

<p>��ע�⣬������������<strong>�����á�</strong>��ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�</p>

<p>����������ڲ���������:</p>

<pre>// <strong>nums</strong> ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
int len = removeElement(nums, val);

// �ں������޸�����������ڵ������ǿɼ��ġ�
// ������ĺ������صĳ���, �����ӡ��������<strong> �ó��ȷ�Χ��</strong> ������Ԫ�ء�
for (int i = 0; i < len; i++) {
�0�2 �0�2 print(nums[i]);
}
</pre>

## �ⷨ
```cpp
// Author: klinghui @ https://github.com/konglhui/Leetcode
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int size = nums.size();
        int times = 0;
        int i = 0;
        int ____size = size - 1 ;
        while(i + times < size)
        {
            if(nums[____size - times] == val)
            {
                times++;
                continue;
            }
            if(nums[i] == val)
            {
                swapNums(nums[____size - times],nums[i]);
                times++;
                continue;
            }
            i++;
        }
        return size - times;
    }
    
    void swapNums(int & a,int & b)
    {
        int c = a;
        a = b;
        b = c;
    }

};

```