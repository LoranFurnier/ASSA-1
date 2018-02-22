#include <iostream>
using namespace std;
//a – ìàññèâ;
//lo – ïåðâûé ýëåìåíò (äëÿ íà÷àëà - 0);
//hi – ïîñëåäíèé ýëåìåíò (äëÿ íà÷àëà = a.length — 1).
void SortUnsorted(int a[], int lo, int hi) {
    if (hi <= lo){
        return;
	}
    int mid = lo + (hi - lo) / 2;
    SortUnsorted(a, lo, mid);
    SortUnsorted(a, mid + 1, hi);

    int buf[10];
	for(int j = 0; j<sizeof(a)/sizeof(a[0]); j++){
		buf[j] = a[j];
	}

    for (int k = lo; k <= hi; k++){
        buf[k] = a[k];
	}
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {

        if (i > mid) {
            a[k] = buf[j];
            j++;
        } else if (j > hi) {
            a[k] = buf[i];
            i++;
        } else if (buf[j] < buf[i]) {
            a[k] = buf[j];
            j++;
        } else {
            a[k] = buf[i];
            i++;
        }
    }
}
main(){
	int mas[10];
	cout << "Here comes the massive:\n";
	for(int i = 0; i<10; i++){
		cout << "Element #" << i << ": ";
		cin >> mas[i];
	}
	SortUnsorted(mas, 0, 9);
	for(int i = 0; i<10; i++){
		cout << "Element #" << i << ": ";
		cout << mas[i];
	}
}
