#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool calculate_ip_range(const string& ip, int num);

class DealWithIP
{
public:
	void setip(string s);
	string* getip();

	void setres(vector<int> r);
	vector<int>* getres();

	//�ָ�ip
	void Stringsplit(const string& str, const string& split, vector<int>& res);

	//�ж��Ƿ�����ȷ��ip��ַ
	bool isIPv4(vector<int>& res);

private:
	string ip;
	vector<int> res;
};