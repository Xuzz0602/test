#include "test.h"

void test();
void TEST();

int main()
{
	//��������
	test();

	//��Ԫ����
	//TEST();

	system("pause");
	return 0;
}

void test() {

	string ip = "";
	int num = 0;

	do {
		cout << "��������ʼ��IPv4�ĵ�ַ:" << endl;
		cin >> ip;

		cout << "������Ҫ����ĸ�����" << endl;
		cin >> num;
		cout << "--------------------------------" << endl;
		if (calculate_ip_range(ip, num)) {
			break;
		}
		else {
			system("pause");
			system("cls");
		}
	} while (true);

}

void TEST() {

	calculate_ip_range("1.2.3.4", 5);
	cout << "-----------------------------" << endl;
	calculate_ip_range("10.111.111", 6);
	cout << "-----------------------------" << endl;
	calculate_ip_range("192.168.3.0.1", 7);
	cout << "-----------------------------" << endl;
	calculate_ip_range("110.1.2.253", 8);
	cout << "-----------------------------" << endl;
	calculate_ip_range("23.45.67.888", 5);
	cout << "-----------------------------" << endl;
	calculate_ip_range("23.45.254.250", 10);
	cout << "-----------------------------" << endl;
	calculate_ip_range("255.255.255.252", 6);
}