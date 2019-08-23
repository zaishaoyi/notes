#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
// ��������
// ð������
// ����Ԫ������������ÿһ��
// ʱ�临�Ӷ�O��n^2��, �ȶ�
void bubbleSort(vector<int>& arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// ѡ������
// ÿһ�α���ѡ����СԪ�ط��ڶ���
// ʱ�临�Ӷ�O(n^2), ���ȶ�
void selectSort(vector<int>& arr) {
	for (size_t i = 0; i < arr.size() - 1; i++) {
		int min = arr[i];
		int index = i;
		for (size_t j = i; j < arr.size(); j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		if (index != i) {
			swap(arr[index], arr[i]);
		}
	}
}

// ��������
// ѡȡһ����׼ֵ�����ڸ�ֵ��Ԫ�ط������ұߣ�С�ڸ�ֵ��Ԫ�ط��������
// ���������߷ֱ���еݹ�
// ���ƶ�����from up to down
// ʱ�临�Ӷ�O(nlogn),���ȶ�
void quickSort(vector<int>& arr, int left, int right) {
	// ֻ��һ��Ԫ�ز�����
	if (left >= right - 1) {
		return;
	}
	int lindex = left;
	int rindex = right - 1;
	int std = arr[lindex];
	while (lindex < rindex) {
		while (lindex < rindex) {
			if (arr[rindex] < std) {
				arr[lindex] = arr[rindex];
				lindex++;
				break;
			}
			rindex--;
		}
		while (lindex < rindex) {
			if (arr[lindex] > std) {
				arr[rindex] = arr[lindex];
				rindex--;
				break;
			}
			lindex++;
		}
	}
	arr[lindex] = std;
	quickSort(arr, left, lindex);
	quickSort(arr, lindex + 1, right);
}

// insertSort
// ʱ�临�Ӷ�O��n^2��,���ȶ�
void insertSort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = 0;
		for (; j < i; j++) {
			if (arr[j] > arr[i]) {
				break;
			}
		}
		int temp = arr[i];
		for (int k = i; k > j; k--) {
			arr[k] = arr[k - 1];
		}
		arr[j] = temp;
	}
}

void insertSortV2(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i - 1;
		for (; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				break;
			}
		}
		int temp = arr[i];
		for (int k = i; k > j + 1; k--) {
			arr[k] = arr[k - 1];
		}
		arr[j + 1] = temp;
	}
}

void heapSort(vector<int>& arr) {
	for (int i = 0; i )
}
void rand_vec(vector<int>& arr, int size = 10, int low = 0, int high = 100) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		arr.push_back((rand() % (high - low + 1)) + low);
	}
}

void output(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	vector<int> arr;
	for (int i = 0; i < 3; i++) {
		arr.clear();
		rand_vec(arr);
		std::cout << i << " original vector:" << std::endl;
		output(arr); 
		insertSortV2(arr);
		std::cout << i << " sorted vector:" << std::endl;
		output(arr);
		std::cout << "-------------------------" << std::endl;

	}
	system("pause");
	return 0;
}