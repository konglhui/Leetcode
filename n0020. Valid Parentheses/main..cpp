// Author: Netcan @ https://github.com/netcan/Leetcode-Rust
// Zhihu: https://www.zhihu.com/people/netcan
class Solution {
public:
	const std::unordered_map<char,char> maps = { {'(',')'},{'{', '}'},{'[' , ']' } };
	bool isValid(string s) {

		stack<char> temp;
		for(const auto& ss:s)
		{
			auto temp_map = maps.find(ss);
			if (temp_map != maps.end())
			{
				temp.push(temp_map->second);
				continue;
			}
			if (temp.empty() || !(temp.top() == ss))
				return false;
			temp.pop();
		}
        if(temp.empty())
		    return true;
        return false;
	}
};
