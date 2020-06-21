# Remove Duplicates from Sorted Array :star:
- ��Ŀ��ַ: [https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array)
- ִ��ʱ��: 24 ms 
- �ڴ�����: N/A
- ͨ������: 2019-03-17 22:59
## ��Ŀ����
<p>����һ���������飬����Ҫ��<strong><a href="http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> ԭ��</a></strong> ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�</p>

<p>��Ҫʹ�ö��������ռ䣬������� <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">ԭ�� </a>�޸��������� </strong>����ʹ�� O(1) ����ռ����������ɡ�</p>



<p><strong>ʾ���0�21:</strong></p>

<pre>�������� <em>nums</em> = <strong>[1,1,2]</strong>, 

����Ӧ�÷����µĳ��� <strong>2</strong>, ����ԭ���� <em>nums </em>��ǰ����Ԫ�ر��޸�Ϊ <strong><code>1</code></strong>, <strong><code>2</code></strong>�� 

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�</pre>

<p><strong>ʾ���0�22:</strong></p>

<pre>����<em> nums </em>= <strong>[0,0,1,1,1,2,2,3,3,4]</strong>,

����Ӧ�÷����µĳ��� <strong>5</strong>, ����ԭ���� <em>nums </em>��ǰ���Ԫ�ر��޸�Ϊ <strong><code>0</code></strong>, <strong><code>1</code></strong>, <strong><code>2</code></strong>, <strong><code>3</code></strong>, <strong><code>4</code></strong>��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
</pre>



<p><strong>˵��:</strong></p>

<p>Ϊʲô������ֵ��������������Ĵ���������?</p>

<p>��ע�⣬������������<strong>�����á�</strong>��ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�</p>

<p>����������ڲ���������:</p>

<pre>// <strong>nums</strong> ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
int len = removeDuplicates(nums);

// �ں������޸�����������ڵ������ǿɼ��ġ�
// ������ĺ������صĳ���, �����ӡ��������<strong>�ó��ȷ�Χ��</strong>������Ԫ�ء�
for (int i = 0; i < len; i++) {
�0�2 �0�2 print(nums[i]);
}
</pre>

## �ⷨ
```cpp
// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.empty())return 0;
		int num = 0;
        int temp = nums[0] - 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > temp)
			{
                temp = nums[i];
				nums[num] = temp;
				num++;
			}
		}
		return num;
	}
};

```