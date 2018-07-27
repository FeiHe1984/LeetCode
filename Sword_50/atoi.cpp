class Solution {
public:
	enum Status{ kValid = 0, kInvalid };
	int g_nStatus = kValid;

	int StrToInt(string str) {
		g_nStatus = kInvalid;
		long long num = 0;
		const char* cstr = str.c_str();
		if ((cstr != NULL) && (*cstr != '\0')){
			int minus = 1;
			if (*cstr == '-'){
				minus = -1;
				cstr++;
			}
			else if (*cstr == '+')
				cstr++;

			while (*cstr != '\0'){
				if (*cstr > '0' && *cstr < '9'){
					g_nStatus = kValid;
					num = num * 10 + (*cstr - '0');
					cstr++;
					if (((minus>0) && (num > 0x7FFFFFFF)) ||
						((minus<0) && (num > 0x80000000))){
						g_nStatus = kInvalid;
						num = 0;
						break;
					}

				}
				else{
					g_nStatus = kInvalid;
					num = 0;
					break;
				}
			}
			if (g_nStatus == kValid)
				num = num * minus;
		}
		return (int)num;
	}
};