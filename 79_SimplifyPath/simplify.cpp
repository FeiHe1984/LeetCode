class Solution {
private:
	vector<string>& split(const string& s, char delim, vector<string>& elems){
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)){
			/*Extracts characters from is and stores them into str
			* until the delimitation character delim is found*/
			elems.push_back(item);
		}
		return  elems;
	}

public:
	vector<string> split(const string& s, char delim){
		vector<string>  elems;
		split(s, delim, elems);

		return elems;
	}

	string simplifyPath(string path) {
		if (path.length() <= 1) return path;
		vector<string> each = split(path, '/');
		stack<string> res_stack;

		for (int i = 0; i<each.size(); i++){
			if (each[i].compare("..") == 0){
				if (!res_stack.empty()) res_stack.pop();
			}
			else if (each[i].compare(".") != 0 && !each[i].empty()){
				res_stack.push(each[i]);
			}
		}

		string result = "";
		if (res_stack.empty()) return "/";
		while (!res_stack.empty()){
			result = "/" + res_stack.top() + result;
			res_stack.pop();
		}
		return result;
	}
};