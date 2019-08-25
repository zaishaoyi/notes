#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
// https://blog.csdn.net/hellozhxy/article/details/79911867
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
/**********************
 * 1��ð������
 * �Ƿ�Ƚ����� �Ƚ�����
 * ƽ��ʱ�临�Ӷȣ�O(n^2)
 * �������� O(n) ԭʼ����˳�����С���Ҫ��¼������������һ�ֱ���û�з����������������Ѿ��������账��
 * ������ O(n^2) ԭʼ������������
 * ����ʽ��In-Place
 * �ռ临�Ӷȣ� O(1)
 * �ȶ��ԣ� �ȶ�
 */
/*********************************
 * ������ bool �� BOOL������
 * bool ���ͣ�C++�ؼ��֣�һ���ֽڴ�С��ȡֵ true(1)/false(0)
 * BOOL ���ͣ�C++�к궨�壨#define FALSE 0�����ĸ��ֽڴ�С(��Щ����int��Ϊ�����ֽ�)��ʵ��Ϊint��,ȡֵTRUE(1)/FALSE(0)
 * int�ʹ�С�����������Ը�������Ӳ����ѡ����ʵĴ�С��������Ҫ����Լ����
 *     1��short��int������Ϊ16λ��long������Ϊ32λ
 *     2��short�ͳ��Ȳ��ܳ���int�ͣ���int�Ͳ��ܳ���long�͡�
 * �⼴��˵�������͵ı����������ɱ�������������
*/

void BubbleSort(int arr[], int len) {
	if (NULL == arr) {
		return;
	}
	for (int i = 0; i < len; i++) {
		bool is_swap = false;
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				is_swap = true;
			}
		}
		if (!is_swap) {
			break;
		}
	}

}
/**********************************************
 * 2��ѡ������
 * �Ƿ�Ƚ����� �Ƚ�����
 * ƽ��ʱ�临�Ӷȣ� O��N^2��
 * �������� O(N^2)
 * �������� O(N^2)
 * ����ʽ��In-Place
 * �ռ临�Ӷȣ� O(1)
 * �ȶ��ԣ� ���ȶ�������{5��5��2}����������¿���һ�����ݣ���Out-Place������������ʵ�֣����ȶ�
 */ 
void SelectionSort(int arr[], int len) {
	if (NULL == arr) {
		return;
	}
	for (int i = 0; i < len; i++) {
		int min = arr[i];
		int index = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		if (index != i) {
			swap(arr[i], arr[index]);
		}
	}
}

/******************************************
 * 3����������
 * �Ƿ�Ƚ����� �Ƚ�����
 * ƽ��ʱ�临�Ӷȣ� O��N^2��
 * �������� O(N)
 * �������� O(N^2)
 * ����ʽ��In-Place
 * �ռ临�Ӷȣ� O(1)
 * �ȶ��ԣ� �ȶ�
 */
// ֱ��д��
void InsertionSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	for (int i = 1; i < len; i++) {
		int std = arr[i];
		int j = i - 1;
		for (j = i - 1; j >= 0; j--) {
			if (std > arr[j]) {
				break;
			}
		}
		for (int k = i; k > j + 1; k--) {
			arr[k] = arr[k - 1];
		}
		arr[j + 1] = std;
	}
}
void InsertionSortV2(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	for (int i = 1; i < len; i++) {
		int std = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > std) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = std;
	}
}
/***********************************
* 4��ϣ������
* desc: �򵥲�������ĸĽ��棬�ֳ���С���������������������������ȱȽϾ����Զ������Ԫ��
* �Ƿ�Ƚ����� �Ƚ�����
* ƽ��ʱ�临�Ӷȣ� O��NlogN��
* �������� O(NlogN)
* �������� O(NlogN)
* ����ʽ��In-Place
* �ռ临�Ӷȣ� O(1)
* �ȶ��ԣ� ���ȶ�
*/
// 4��ϣ������
void ShellSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}

	int gap = len / 2;
	while (gap > 0) {
		// gap֮ǰ��Ԫ��Ϊ�������һ��Ԫ�صļ���
		// ���Դ�gap��󣬵���ÿ��Ԫ�����������е�λ��
		for (int i = gap; i < len; i++) {
			int j = i;
			int std = arr[i];
			while ((j - gap >= 0) && (arr[j - gap] > arr[j])) {
				swap(arr[j - gap], arr[j]);
				j -= gap;
			}
		}

		// ��Сgap
		gap = gap / 2;
	}
}

/***********************************
* 5���鲢����
* desc: ���η�����ѡ������һ���������������ݵ�Ӱ�졣
* �Ƿ�Ƚ����� �Ƚ�����
* ƽ��ʱ�临�Ӷȣ� O��NlogN��
* �������� O(NlogN)
* �������� O(NlogN)
* ����ʽ��Out-Place
* �ռ临�Ӷȣ� O(n)
* �ȶ��ԣ� �ȶ�
*/

// C++���ܷ������飬����ͨ������ָ��ʵ��
void merge(int arr[], int left, int right) {
	if (right - left < 1) {
		return;
	}
	int len = right - left + 1;
	int mid = len / 2;
	int *temp = new int[len];
	int i = left;
	int j = left + mid;
	int temp_len = 0;
	while ((i < left + mid) || (j <= right)) {
		if (i >= left + mid) {
			temp[temp_len++] = arr[j++];
		}
		else if (j > right) {
			temp[temp_len++] = arr[i++];
		}
		else if (arr[i] < arr[j]) {
			temp[temp_len++] = arr[i++];
		}
		else {
			temp[temp_len++] = arr[j++];
		}
	}
	for (int k = 0; k < temp_len; k++) {
		arr[left + k] = temp[k];
	}
	delete[] temp;
	temp = NULL;
}
void MergeSort(int arr[], int begin, int end) {
	int len = end - begin + 1;
	if (len < 2) {
		return;
	}
	int mid = len / 2;
	MergeSort(arr, begin, begin + mid - 1);
	MergeSort(arr, begin + mid, end);
	merge(arr, begin, end);

}

/****************************************
 * 6����������
 * �Ƿ�Ƚ����� �Ƚ�����
 * ƽ��ʱ�临�Ӷȣ� O��NlogN��
 * �������� O(NlogN)
 * �������� O(N^2)
 * ����ʽ��In-Place
 * �ռ临�Ӷȣ� O(1)
 * �ȶ��ԣ� ���ȶ�
 */
int partition(int arr[], int start, int end) {
	int privot = arr[start];
	int left = start;
	int right = end;
	while (left < right) {
		while ((left < right) && (arr[right] > privot)) {
			right--;
		}
		if (left < right) {
			arr[left++] = arr[right];
		}
		while ((left < right) && (arr[left] < privot)) {
			left++;
		}
		if (left < right) {
			arr[right--] = arr[left];
		}
	}
	arr[left] = privot;
	return left;
}
void QuickSort(int arr[], int start, int end) {
	int len = end - start + 1;
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	int pos = partition(arr, start, end);
	if (pos > start) {
		QuickSort(arr, start, pos - 1);
	}
	if (pos < end) {
		QuickSort(arr, pos + 1, end);
	}
}

/************************************
 * 7��������
 * �Ƿ�Ƚ����� �Ƚ�����
 * ƽ��ʱ�临�Ӷȣ� O��NlogN��
 * �������� O(NlogN)
 * �������� O(NlogN)
 * ����ʽ��In-Place
 * �ռ临�Ӷȣ� O(1)
 * �ȶ��ԣ� ���ȶ�
 */
// ��ǰ�ڵ� i
// ���ӽڵ� 2*i + 1
// ���ӽڵ� 2*i + 2
// ���ڵ� ��i - 1��/2
// ���һ����Ҷ�ӽڵ㣺(len -1)/2
// �����󶥶�
void HeadAdjust(int arr[], int i, int len) {
	int std = arr[i];
	while (2 * i + 1 < len) {
		int iMax = 2 * i + 1;
		if ((2 * i + 2 < len) && (arr[2 * i + 1] < arr[2 * i + 2])) {
			iMax = 2 * i + 2;
		}
		if (arr[iMax] > std) {
			arr[i] = arr[iMax];
			i = iMax;
			continue;
		}
		break;
	}
	arr[i] = std;
}
void HeapSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	// �����󶥶�
	for (int i = (len - 1) / 2; i >= 0; i--) {
 		HeadAdjust(arr, i, len);
	}
	for (int j = len - 1; j > 0; j--) {
		swap(arr[0], arr[j]);
		HeadAdjust(arr, 0, j);
	}
}
/************************************
 * 8����������
 * �Ƿ�Ƚ����� �ǱȽ�����
 * ƽ��ʱ�临�Ӷȣ� O��N+K��������N��0-K֮������֣�
 * �������� O(N+K)
 * �������� O(N+K)
 * ����ʽ��Out-Place
 * �ռ临�Ӷȣ� O(K)
 * �ȶ��ԣ� �ȶ�
*/
// 8����������
void CountingSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	if (max == min) {
		return;
	}
	int* bucket = new int[max - min + 1];
	memset(bucket, 0, sizeof(int) * (max - min + 1));
	int bias = min - 0;
	for (int i = 0; i < len; i++) {
		bucket[arr[i] - bias] += 1;
	}
	int index = 0;
	int i = 0;
	while (i < max - min + 1) {
		if (bucket[i] > 0) {
			arr[index++] = i + bias;
			bucket[i] -= 1;
		} else {
			i++;
		}
		
	}
	delete[] bucket;
	bucket = NULL;
}

/********************************
 * 9��Ͱ����
 * �Ƿ�Ƚ����� �ǱȽ�����
 * ƽ��ʱ�临�Ӷȣ� O��N+K��������N��0-K֮������֣�
 * �������� O(N+K)
 * �������� O(N+K)
 * ����ʽ��Out-Place
 * �ռ临�Ӷȣ� O(K)
 * �ȶ��ԣ� �ȶ�
 */
// 
void BucketSort(int arr[], int len, int bucket_size) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	// ͳ�����뷶Χ
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	// ��ʼ������
	int range = max - min + 1;
	int bucket_count = range / bucket_size + 1;
	int** buckets = new int*[bucket_count];
	for (int i = 0; i < bucket_count; i++) {
		buckets[i] = new int[bucket_size];
		memset(buckets[i], 0, sizeof(int) * bucket_size);
	}

	// �������
	for (int i = 0; i < len; i++) {
		int row = (arr[i] - min) / bucket_size;
		int col = (arr[i] - min) % bucket_size;
 		buckets[(arr[i] - min) / bucket_size][(arr[i] - min) % bucket_size] += 1;
	}

	// ������
	int index = 0;
	for (int i = 0; i < bucket_count; i++) {
		int j = 0;
		while (j < bucket_size) {
			if (buckets[i][j] > 0) {
				arr[index++] = bucket_size * i + j + min;
				buckets[i][j] --;
			} else {
				j++;
			}
		}
	}
	// ɾ����̬����
	for (int i = 0; i < bucket_count; i++) {
		delete[] buckets[i];
		buckets[i] = NULL;
	}
	delete[] buckets;
	buckets = NULL;
}

/********************************
* 10����������
* �Ƿ�Ƚ����� �ǱȽ�����
* ƽ��ʱ�临�Ӷȣ� O��N*K����KΪ�������������λ����
* �������� O(N*K)
* �������� O(N*K)
* ����ʽ��Out-Place
* �ռ临�Ӷȣ� O(K)
* �ȶ��ԣ� �ȶ�
*/
void RadixSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	// Ѱ�����ֵ
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	// ���λ��
	int iDigit = 0;
	while (max > 0) {
		max /= 10;
		iDigit++;
	}
	// ����,����vector���ݽṹ
	int radix = 1;
	for (int i = 0; i < iDigit; i++) {
		vector<vector<int>> temp_vec;
		for (int j = 0; j < 10; j++) {
			temp_vec.push_back(vector<int>());
		}
		for (int j = 0; j < len; j++) {
			temp_vec[arr[j] / radix % 10].push_back(arr[j]);
		}
		int index = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < temp_vec[j].size(); k++) {
				arr[index++] = temp_vec[j][k];
			}
		}
		radix *= 10;
	}
}
// ���
void output(int arr[], int len) {
	if (NULL == arr) {
		return;
	}

	for (int i = 0; i < len; i++) {
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;
	return;
}

int main(int argc, char** argv) {
	int arr[10] = { 0 };
	
	int retry = 3;
	int rangeL = 0;
	int rangeR = 100;
	srand(time(NULL));
	for (int i = 0; i < retry; i++) {
		// �����������
		for (int j = 0; j < 10; j++) {
			arr[j] = rand() % (rangeR - rangeL) + rangeL;
		}

		// �������ǰ���
		std::cout << "random_array: ";
		output(arr, sizeof(arr)/sizeof(arr[0]));
		// ����
		// BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
		// SelectionSort(arr, sizeof(arr) / sizeof(arr[0]));
		// InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));
		// InsertionSortV2(arr, sizeof(arr) / sizeof(arr[0]));
		// ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
		// MergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) -1);
		// QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
		// HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
		// CountingSort(arr, sizeof(arr) / sizeof(arr[0]));
		// BucketSort(arr, sizeof(arr) / sizeof(arr[0]), 5);
		RadixSort(arr, sizeof(arr) / sizeof(arr[0]));
		// ����������
		std::cout << "sorted array: ";
		output(arr, sizeof(arr) / sizeof(arr[0]));
	}
	system("pause");
	return 0;
}