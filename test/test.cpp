#include "test.h"

void DealWithIP::setip(string s) {
	this->ip = s;
}

string* DealWithIP::getip() {
	return &ip;
}

void DealWithIP::setres(vector<int> r) {
	this->res = r;
}

vector<int>* DealWithIP::getres() {
	return &res;
}

void DealWithIP::Stringsplit(const string& str, const string& split, vector<int>& res)
{
	char* strc = new char[str.size() + 1];
	strcpy(strc, str.c_str());
	char* temp = strtok(strc, split.c_str());
	while (temp != NULL)
	{
		res.push_back(stoi(string(temp)));
		temp = strtok(NULL, split.c_str());
	}
	delete[] strc;
}

bool DealWithIP::isIPv4(vector<int>& res)
{
	int num = 0;
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
	{
		if ((*it < 0 || *it > 255) || (num == 0 && *it == 0))
			return false;
		num++;
	}
	if(num == 4)
		return true;
	return false;
}

bool calculate_ip_range(const string &ip, int num)
{
	vector<int> res;
	res.clear();
	DealWithIP* dwIP = new DealWithIP();

	dwIP->Stringsplit(ip, ".", res);
	dwIP->setres(res);

	if (dwIP->isIPv4(*dwIP->getres()))
	{
		dwIP->setip(ip);
	}
	else {
		cout << "不是一个正常的ip,请重新输入" << endl;
		return false;
	}

	for (int i = 0; i < num; i++) {
		
		vector<int>::iterator it = dwIP->getres()->begin();
		
		if (*(it + 3) + i > 255) {
			num -= i;
			i = 0;
			it[3] = 0;
			it[2] = it[2] + 1;
		}
		if (it[2] > 255) {
			it[1] = it[1] + 1;
			it[2] = 0;
		}
		if (it[1] > 255) {
			it[0] += 1;
			it[1] = 0;
		}
		if (it[0] > 255) {
			cout << "ip到达上线了！无法继续输出!" << endl;
			break;
		}
		cout << *it << "." << *(it + 1) << "." << *(it + 2) << "." << *(it + 3) + i;

		cout << endl;
	}
	delete dwIP;
	return true;
}
